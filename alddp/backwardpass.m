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

n = data.n;
m = data.m;
niq = data.niq;

muiq = val.muiq;

x = val.x(:,end);
Vx = data.lfx(x)';
Vxx = data.lfxx(x);

Kfb = zeros(size(bp.Kfb));
Kff = zeros(size(bp.Kff));
Qu_tmp = zeros(data.m,data.N-1);

dV = [0;0];
bp.fail = false;
for i=data.N-1:-1:1 
    
    %% data
    u = val.u(:,i);
    w = val.w(:,i);
    wbar = val.wbar(:,i);
    ubar = val.ubar(:,i);

    %% cost
    lx = val.lx(:,i);
    lu = val.lu(:,i);
    lxx = val.lxx(:,:,i);
    luu = val.luu(:,:,i);
    lux = val.lux(:,:,i);

    %% dynamics
    fx = val.fx(:,:,i);
    fu = val.fu(:,:,i);

    %% inequality
    h = val.h(:,i);
    D = double(muiq*wbar + h > 0);
    hx = D.*val.hx(:,:,i);
    hu = D.*val.hu(:,:,i);
    
    %% direction
    Quu = luu + fu'*Vxx*fu + reg*eye(size(luu));
    Qux = lux + fu'*Vxx*fx;

    Qu = lu + fu'*Vx + hu'*w + reg*(u-ubar);

    hbar = val.hbar(:,i);

    A = [Quu hu';
         hu -muiq*eye(niq)];
    b = -[Qux Qu;
          hx hbar];
    Kd = A\b;
    
    %% value function
    Mxx = lxx + fx'*Vxx*fx + (hx'*hx)/muiq;
    Muu = luu + fu'*Vxx*fu + (hu'*hu)/muiq + reg*eye(size(luu));
    Mux = lux + fu'*Vxx*fx + (hu'*hx)/muiq;

    Mx = lx + fx'*Vx + hx'*(w + hbar/muiq);
    Mu = lu + fu'*Vx + hu'*(w + hbar/muiq) + reg*(u-ubar);

    K = Kd(1:m,1:n);
    d = Kd(1:m,end);
    
    dV = dV + [Mu'*d; 0.5*d'*Muu*d];
    Vx = Mx + K'*Mu + Mux'*d + K'*Muu*d;
    Vxx = Mxx + K'*Mux + Mux'*K + K'*Muu*K;
    
    Kfb(:,:,i) = Kd(:,1:n);
    Kff(:,i) = Kd(:,end);
    Qu_tmp(:,i) = Qu;
end

bp.dV = dV;
bp.Kfb = Kfb;
bp.Kff = Kff;
val.Qu = Qu_tmp;
















