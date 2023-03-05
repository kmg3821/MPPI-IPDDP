%% variables
x = sym('x',[6,1]);
u = sym('u',[3,1]);
n = size(x,1);
m = size(u,1);

X = [x;u];
dt = 0.05;

xref = sym('xref',[6,1]);
cref = sym('cref',[3,1]);
rref = sym('rref',[1,1]);

%% dynamics
f = x + dt*[x(4:6,:); u - 9.81*[0;0;1]];
fX = jacobian(f,X);

%% cost

l = 1e-2*sum(u.^2) + sum((x - xref).^2)*1e-3;
lx = jacobian(l,x);
lu = jacobian(l,u);
lxx = jacobian(lx,x);
luu = jacobian(lu,u);
lux = jacobian(lu,x);

lf = sum((x - [0;4;2;0;0;0]).^2)*500;
lfx = jacobian(lf,x);
lfxx = jacobian(lfx,x);

%% inequality constraint
rmax = 20;
theta_max = deg2rad(60);

c = [sum(u.*u) - rmax^2;
     u(1)^2 + u(2)^2 - tan(theta_max)^2*u(3)^2;
     sum((x(1:3) - cref).^2) - rref^2]*1e-3;
cX = jacobian(c,X);
data.niq = size(c,1);

%% data
data.f = matlabFunction(f,'Vars',{x,u});
data.fX = matlabFunction(fX,'Vars',{x,u});

data.c = matlabFunction(c,'Vars',{x,u,cref,rref});
data.cX = matlabFunction(cX,'Vars',{x,u,cref,rref});

data.l = matlabFunction(l,'Vars',{x,u,xref});
data.lx = matlabFunction(lx,'Vars',{x,u,xref});
data.lu = matlabFunction(lu,'Vars',{x,u,xref});
data.lxx = matlabFunction(lxx,'Vars',{x,u,xref});
data.luu = matlabFunction(luu,'Vars',{x,u,xref});
data.lux = matlabFunction(lux,'Vars',{x,u,xref});

data.lf = matlabFunction(lf,'Vars',{x});
data.lfx = matlabFunction(lfx,'Vars',{x});
data.lfxx = matlabFunction(lfxx,'Vars',{x});

data.xidx = 1:n;
data.uidx = n+1:n+m;

data.N = 31;
data.n = n;
data.m = m;

data.s_init = 0.01*ones(data.niq,data.N-1);
data.y_init = 0.01*ones(data.niq,data.N-1);
data.mu_init = 0.01;

%% bp
bp.fail = true;
bp.reg = 5.^(-10:1:2);
bp.regidx = 1;
bp.dV = [0;0;0];
bp.eps = 1e-7;
bp.error = false;

bp.Kfb.u = zeros(data.m,data.n,data.N-1);
bp.Kff.u = zeros(data.m,data.N-1);
bp.Kfb.s = zeros(data.niq,data.n,data.N-1);
bp.Kff.s = zeros(data.niq,data.N-1);
bp.Kfb.y = zeros(data.niq,data.n,data.N-1);
bp.Kff.y = zeros(data.niq,data.N-1);

%% fp
fp.fail = true;
fp.steps = 0.5.^(0:18);
fp.step = fp.steps(1);
fp.eps = 1e-7;

fp.taumin = 0.99;
fp.cost = 0;
fp.filter = zeros(2,1);

%% value

val.s = data.s_init;
val.y = data.y_init;
val.mu = data.mu_init;

val.iter = 0;

val.l = zeros(1,data.N-1);
val.lx = zeros(data.n,data.N-1);
val.lu = zeros(data.m,data.N-1);
val.lxx = zeros(data.n,data.n,data.N-1);
val.lux = zeros(data.m,data.n,data.N-1);
val.luu = zeros(data.m,data.m,data.N-1);

% val.f = zeros(data.n,data.N-1);
val.fx = zeros(data.n,data.n,data.N-1);
val.fu = zeros(data.n,data.m,data.N-1);

val.c = zeros(data.niq,data.N-1);
val.cx = zeros(data.niq,data.n,data.N-1);
val.cu = zeros(data.niq,data.m,data.N-1);

%% function
data.dispinfo = @dispinfo;
data.plotresult = @plotresult;

data2 = data;

function dispinfo(val,bp,fp)

    txt = sprintf(['iter: %d | reg: %f | J: %.4f | ' ...
                   'step: %f | Qu: %f | rp: %f | rd: %f | mu: %f \n'],...
    val.iter, bp.reg(bp.regidx), val.J, fp.step, ...
    max(vecnorm(val.Qu,'inf')), max(vecnorm(val.rp,'inf')),...
    max(vecnorm(max(val.rd,0),'inf')),val.mu);
    disp(txt);

end

function plotresult(data,val)

    figure; plot(val.x(1,:),val.x(2,:)); axis equal

end
