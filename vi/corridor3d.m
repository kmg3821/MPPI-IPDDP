function [c,r] = corridor(x,data,ttmp)

N = data.N;
T = data.T;
nz = data.nz;
rho = data.rho;
noise = data.noise;
getcost = data.getcost;
hz = data.hz;
rmax = data.rmax;

% p = x(1:2,1:end-1);
% z = [reshape(p(1:2,:),2,1,T); abs(zeros(1,1,T))];

p = x(1:3,1:end-1);
z = [reshape(p,3,1,T); abs(randn(1,1,T))*0.01];

for i=1:5

    z = reshape(z,nz,1,T) + ttmp(:,randperm(size(ttmp,2)),:);
    J = getcost(z,p,data);
    J = J - min(J);
    w = exp(-J/rho);
    w = w./sum(w);
    
    z = pagemtimes(z,pagetranspose(w));
    z = squeeze(hz(z,p,rmax));
end

% c = z(1:2,:);
% r = z(3,:);

c = z(1:3,:);
r = z(4,:);











