function [data,val,bp,fp] = forwardpass(data,val,bp,fp)

xx = [val.x(:,1) zeros(data.n,data.N-1)];
uu = zeros(data.m,data.N-1);
ww = zeros(data.niq,data.N-1);

m = data.m;
niq = data.niq;

muiq = val.muiq;
nuiq = val.nuiq;

reg = bp.reg(bp.regidx);

ubar = val.ubar;
wbar = val.wbar;

l = zeros(size(val.l));
h = zeros(size(val.h));

fp.fail = true;
% step = 1;
for step = fp.steps

    for i=1:data.N-1

        x = val.x(:,i);
        u = val.u(:,i);
        w = val.w(:,i);
%         ref = data.ref(:,i);

        Kfb = bp.Kfb(:,:,i);
        Kff = bp.Kff(:,i);
        
        dx = xx(:,i) - x;
        d = Kfb*dx + step*Kff;

        uu(:,i) = u + d(1:m);
        ww(:,i) = w + d(m+1:m+niq);
        xx(:,i+1) = data.f(xx(:,i),uu(:,i));

%         l(i) = data.l(xx(:,i),uu(:,i),ref);
        l(i) = data.l(xx(:,i),uu(:,i),data.xref(:,i));
        h(:,i) = data.h(xx(:,i),uu(:,i),data.cref(:,i),data.rref(:,i));
    end
    hbar = max(0,muiq*wbar + h) - muiq*ww;

    % same as costeval
    JJ = sum(l) + sum(hbar.^2,"all")*nuiq/(2*muiq) + ...
         sum((hbar + muiq*ww).^2,"all")/(2*muiq) + ...
         sum((uu - ubar).^2,"all")*reg/2 + ...
         data.lf(xx(:,end));

    AR = JJ - val.J;
    dV = step*(bp.dV(1) + step*bp.dV(2));
    r = AR/dV;
    
%     if AR < 0 || max(vecnorm(max(h,0),'inf')) < max(vecnorm(max(val.h,0),'inf'))
%     if fp.lb < r || max(vecnorm(max(h,0),'inf')) < max(vecnorm(max(val.h,0),'inf'))
    if fp.lb < r
        fp.fail = false;
        break;
    end
end

fp.step = step;
fp.r = r;

if ~fp.fail

    fp.AR = AR;
    fp.dV = dV;

    val.x = xx;
    val.u = uu;
    val.w = ww;
    val.J = JJ;
    
    val.l = l;
    val.h = h;
    val.hbar = hbar;

    val = evaluation(data,val);
end









