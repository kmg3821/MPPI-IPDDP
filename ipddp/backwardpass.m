function [data,val,bp,fp] = backwardpass(data,val,bp,fp)

if bp.regidx == length(bp.reg)
    bp.error = true;
end

if bp.fail || fp.fail
    bp.regidx = min(bp.regidx + 1, length(bp.reg));
else
    bp.regidx = max(bp.regidx - 1, 1);
end
reg = bp.reg(bp.regidx);

x = val.x(:,end);
Vx = data.lfx(x)';
Vxx = data.lfxx(x);

mu = val.mu;

Kfb.u = zeros(size(bp.Kfb.u));
Kff.u = zeros(size(bp.Kff.u));
Kfb.s = zeros(size(bp.Kfb.s));
Kff.s = zeros(size(bp.Kff.s));
Kfb.y = zeros(size(bp.Kfb.y));
Kff.y = zeros(size(bp.Kff.y));

Qu_record = zeros(data.m,data.N-1);
rp_record = zeros(data.niq,data.N-1);
rd_record = zeros(data.niq,data.N-1);

bp.fail = false;
for i=data.N-1:-1:1 

    lx = val.lx(:,i);
    lu = val.lu(:,i);
    lxx = val.lxx(:,:,i);
    luu = val.luu(:,:,i);
    lux = val.lux(:,:,i);
    fx = val.fx(:,:,i);
    fu = val.fu(:,:,i);

    s = val.s(:,i);
    y = val.y(:,i);
    c = val.c(:,i);
    cx = val.cx(:,:,i);
    cu = val.cu(:,:,i);

    Lyx = cx;
    Lyu = cu;

    rp = c + s;
    rd = y.*s - mu;
    r = y.*rp - rd;
    YSinv = diag(y./s);
    
    % lagrangian ( L = l + y(c+s) + V )
    Lx = lx + fx'*Vx + cx'*y;
    Lu = lu + fu'*Vx + cu'*y;
    Lxx = lxx + fx'*Vxx*fx;
    Luu = luu + fu'*Vxx*fu + reg*eye(size(luu));
    Lux = lux + fu'*Vxx*fx;
    
    % barrier effect
    Qx = Lx + Lyx'*(r./s);
    Qu = Lu + Lyu'*(r./s);
    Qxx = Lxx + Lyx'*YSinv*Lyx;
    Quu = Luu + Lyu'*YSinv*Lyu;
    Qux = Lux + Lyu'*YSinv*Lyx;
    
    [R, fail] = chol(Quu);
    if fail 
        bp.fail = true;
        return;
    end
    
    Ku = -R\(R'\Qux);
    du = -R\(R'\Qu);
    Ks = -(Lyx + Lyu*Ku);
    ds = -(rp + Lyu*du);
    Ky = YSinv*(Lyx + Lyu*Ku);
    dy = (r./s) + YSinv*Lyu*du;
    
    Vx = Qx + Ku'*Qu + Qux'*du + Ku'*Quu*du;
    Vxx = Qxx + Ku'*Qux + Qux'*Ku + Ku'*Quu*Ku;
    
    Kfb.u(:,:,i) = Ku;
    Kff.u(:,i) = du;
    Kfb.s(:,:,i) = Ks;
    Kff.s(:,i) = ds;
    Kfb.y(:,:,i) = Ky;
    Kff.y(:,i) = dy;

    Qu_record(:,i) = Qu;
    rp_record(:,i) = rd;
    rd_record(:,i) = rp;

end

val.Qu = Qu_record;
val.rp = rp_record;
val.rd = rd_record;

bp.Kfb.u = Kfb.u;
bp.Kff.u = Kff.u;
bp.Kfb.s = Kfb.s;
bp.Kff.s = Kff.s;
bp.Kfb.y = Kfb.y;
bp.Kff.y = Kff.y;
















