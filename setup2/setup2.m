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

lf = sum((x - [0;4;2;0;0;0]).^2)*100;
lfx = jacobian(lf,x);
lfxx = jacobian(lfx,x);

%% inequality constraint
rmax = 20;
theta_max = deg2rad(60);

h = [sum(u.*u) - rmax^2;
     u(1)^2 + u(2)^2 - tan(theta_max)^2*u(3)^2;
     sum((x(1:3) - cref).^2) - rref^2];
hX = jacobian(h,X);
data.niq = size(h,1);

%% data
data.f = matlabFunction(f,'Vars',{x,u});
data.fX = matlabFunction(fX,'Vars',{x,u});

data.h = matlabFunction(h,'Vars',{x,u,cref,rref});
data.hX = matlabFunction(hX,'Vars',{x,u,cref,rref});

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

%% bp
bp.fail = true;
bp.reg = 5.^(-10:1:2);
bp.regidx = 1;
bp.Kfb = zeros(data.m + data.niq, data.n, data.N-1);
bp.Kff = zeros(data.m + data.niq, data.N-1);
bp.dV = [0;0];
bp.eps = 1e-7;
bp.error = false;

%% fp
fp.fail = true;
fp.steps = 0.5.^(0:18);
fp.step = fp.steps(1);
fp.lb = 1e-4;
fp.ub = inf;
fp.r = 1;
fp.AR = 0;
fp.eps = 1e-7;

fp.alpha = 0.5;
fp.beta = 0.5;
fp.gam = 0.5;
fp.muiq_min = 1e-8;
fp.tol_fea_init = 1e-3;
fp.tol_res_init = 1e-3; 
fp.tol_fea = fp.tol_fea_init;
fp.tol_res = fp.tol_res_init;

%% value

val.iter = 0;
val.fea = 9999;
val.Qu = 9999*ones(data.m,data.N-1);

val.muiq = 10;
val.nuiq = 0;

val.l = zeros(1,data.N-1);
val.lx = zeros(data.n,data.N-1);
val.lu = zeros(data.m,data.N-1);
val.lxx = zeros(data.n,data.n,data.N-1);
val.lux = zeros(data.m,data.n,data.N-1);
val.luu = zeros(data.m,data.m,data.N-1);

% val.f = zeros(data.n,data.N-1);
val.fx = zeros(data.n,data.n,data.N-1);
val.fu = zeros(data.n,data.m,data.N-1);

val.h = zeros(data.niq,data.N-1);
val.hx = zeros(data.niq,data.n,data.N-1);
val.hu = zeros(data.niq,data.m,data.N-1);

val.hbar = zeros(data.niq,data.N-1);
% val.ubar = val.u;
% val.xbar = val.x;

% for i=1:data.N-1
%     val.l(:,i) = data.l(val.x(:,i),val.u(:,i));
% %     val.f(:,i) = data.f(val.x(:,i),val.u(:,i));
%     val.h(:,i) = data.h(val.x(:,i),val.u(:,i));
% end
% val.w = double(val.h > 0)*0;
% val.wbar = val.w;
% 
% val = evaluation(data,val);
% val = costeval(data,val,bp);
% val.J = inf;

%% function
data.dispinfo = @dispinfo;
data.plotresult = @plotresult;

data2 = data;

function dispinfo(val,bp,fp)

    txt = sprintf(['iter: %d | reg: %f | cost: %.4f | r: %.4f | ' ...
                   'step: %f | AR: %f | Qu: %f | hbar: %f | h: %f \n'],...
    val.iter, bp.reg(bp.regidx), val.J, fp.r, fp.step, ...
    abs(fp.AR), max(vecnorm(val.Qu,'inf')), max(vecnorm(val.hbar,'inf')),...
    max(vecnorm(max(val.h,0),'inf')));
    disp(txt);

end

function plotresult(data,val)

    figure; plot(val.x(1,:),val.x(2,:)); axis equal

end
