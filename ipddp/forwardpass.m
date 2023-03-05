function [data,val,bp,fp] = forwardpass(data,val,bp,fp)

Kfb.u = bp.Kfb.u;
Kff.u = bp.Kff.u;
Kfb.s = bp.Kfb.s;
Kff.s = bp.Kff.s;
Kfb.y = bp.Kfb.y;
Kff.y = bp.Kff.y;

ll = zeros(1,data.N-1);
cc = zeros(data.niq,data.N-1);
yy = zeros(data.niq,data.N-1);
ss = zeros(data.niq,data.N-1);
uu = zeros(data.m,data.N-1);
xx = zeros(data.n,data.N);
xx(:,1) = val.x(:,1);

mu = val.mu;
tau = max(fp.taumin, 1-mu);

fp.fail = true;
for step = fp.steps

    flag = false;
    for i=1:data.N-1 % trial step
        
        x = val.x(:,i);
        u = val.u(:,i);
        s = val.s(:,i);
        y = val.y(:,i);

        dx = xx(:,i) - x;
        
        ds = Kfb.s(:,:,i)*dx + step*Kff.s(:,i);
        dy = Kfb.y(:,:,i)*dx + step*Kff.y(:,i);
        ss(:,i) = s + ds;
        yy(:,i) = y + dy;

        if any( [ss(:,i); yy(:,i)] < (1-tau)*[s; y] )
            flag = true;
            break;
        end

        du = Kfb.u(:,:,i)*dx + step*Kff.u(:,i);
        uu(:,i) = u + du;
        
        cc(:,i) = data.c(xx(:,i),uu(:,i),data.cref(:,i),data.rref(:,i));
        xx(:,i+1) = data.f(xx(:,i),uu(:,i));
        if i == 1
            ll(i) = data.l(xx(:,i),uu(:,i),data.xref(:,i)) + data.l1(uu(:,i),val.uprev);
        else
            ll(i) = data.l(xx(:,i),uu(:,i),data.xref(:,i));
        end
    end
    JJ = sum(ll) + data.lf(xx(:,data.N));
    
    if ~flag
        logbarrier = sum(log(reshape(ss,[],1)));
        logcost = JJ - mu*logbarrier;
        rperr = norm(reshape(cc + ss,[],1),1);
        candidate = [logcost; rperr];
        
        if any(candidate < fp.filter)
            fp.filter = min(fp.filter, candidate);
            fp.fail = false;
            break;
        end
    end
end

fp.step = step;

if ~fp.fail

    val.x = xx;
    val.u = uu;
    val.s = ss;
    val.y = yy;

    val.J = JJ;
    val.c = cc;
    val.l = ll;

    val = evaluation(data,val);

end






