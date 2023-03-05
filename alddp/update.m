function [data,val,bp,fp] = update(data,val,bp,fp)

res = [val.Qu; val.hbar];
fea = max(0,val.h);

if max(vecnorm(res,'inf')) < fp.tol_res

    if max(vecnorm(fea,'inf')) < fp.tol_fea
%         val.wbar = max(0, 2*(val.wbar + val.h/val.muiq) - val.w);
        val.wbar = max(0, val.wbar + val.h/val.muiq);
        fp.tol_fea = fp.tol_fea*val.muiq;
        fp.tol_res = fp.tol_res*val.muiq^fp.beta;
    else
        val.muiq = max(fp.muiq_min, fp.gam*val.muiq);
        fp.tol_fea = fp.tol_fea_init*val.muiq;
        fp.tol_res = fp.tol_res_init*val.muiq^fp.alpha;
    end
    val.ubar = val.u;
    
    val = costeval(data,val,bp);
end





