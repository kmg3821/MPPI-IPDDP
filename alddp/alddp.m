function [xx,uu] = alddp(x,u,c,r,data,val,bp,fp)

data.xref = x;

val.x = x;
val.u = u;
data.cref = c;
data.rref = r;

val.xbar = val.x;
val.ubar = val.u;
val.muiq = 10;

for i=1:data.N-1
    val.l(:,i) = data.l(val.x(:,i),val.u(:,i),data.xref(:,i));
    val.h(:,i) = data.h(val.x(:,i),val.u(:,i),c(:,i),r(:,i));
end
val.w = double(val.h > 0)*0;
val.wbar = val.w;

val = evaluation(data,val);
val = costeval(data,val,bp);
val.J = inf;

for iter=1:30

    [data,val,bp,fp] = backwardpass(data,val,bp,fp);
    if bp.error
        break;
    end
    if ~bp.fail
        [data,val,bp,fp] = forwardpass(data,val,bp,fp);
    end
    
    [data,val,bp,fp] = update(data,val,bp,fp);

    val.iter = iter;
    data.dispinfo(val,bp,fp);
    
    res = [val.Qu; max(0,val.h)];
    if max(vecnorm(res,'inf')) < 1e-6
        break;
    end
end

xx = val.x;
uu = val.u;

