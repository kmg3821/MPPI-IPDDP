function [xx,uu,JJ,rprp] = ipddp(x,u,uprev,c,r,data,val,bp,fp)

data.xref = c;
data.cref = c;
data.rref = r;

val.x = x;
val.u = u;
val.uprev = uprev;
val.s = data.s_init;
val.y = data.y_init;
val.mu = data.mu_init;

val = evaluation(data,val);
[val,fp] = costeval(data,val,fp);

for iter=1:500
    val.iter = iter;

    [data,val,bp,fp] = backwardpass(data,val,bp,fp);
    if bp.error
        break;
    end
    if ~bp.fail
        [data,val,bp,fp] = forwardpass(data,val,bp,fp);
        if ~fp.fail
            opterr = norm([val.Qu; val.rp; val.rd],'inf');
            if opterr < 1e-6
                break; 
            end
            [val,bp,fp] = update(val,bp,fp);
        end
    end
    data.dispinfo(val,bp,fp);
    
end

xx = val.x;
uu = val.u;
JJ = val.J;
rprp = val.rp;