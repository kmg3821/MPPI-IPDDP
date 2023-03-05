function [xx,uu] = mppi(x0,u,data,ttmp)

N = data.N;
T = data.T;
nx = data.nx;
nu = data.nu;
rho = data.rho;
noise = data.noise;
getcost = data.getcost;
f = data.f;
h = data.h;

% uu = reshape(u,nu,1,T) + ttmp(:,randperm(size(ttmp,2)),:);

uu = reshape(u,nu,1,T) + pagemtimes(noise,[zeros(nu,1,T), randn(nu,N-1,T)]);
J = getcost(x0,uu,data);
minJ = min(J)
J = J - minJ;
w = exp(-J/rho);
w = w/sum(w);

%%%%%% monte carlo rollout plot
xx = zeros(nx,N,T+1); xx(:,:,1) = repmat(x0,1,N);
for t=1:T
    xx(:,:,t+1) = f(xx(:,:,t),uu(:,:,t));
end
data.getplot(0,xx,uu,data)
%%%%%%

%%%%%%%%%%%%%%%%%%
% if minJ > 1e8
%     uu = uu/10;
% end
%%%%%%%%%%%%%%%%%%

uu = squeeze(pagemtimes(uu,w'));
uu = h(uu);

xx = zeros(nx,T+1); xx(:,1) = x0;
for t=1:T
    xx(:,t+1) = f(xx(:,t),uu(:,t));
end













