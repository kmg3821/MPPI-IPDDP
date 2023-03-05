close all; clc; clear;
addpath('tmp\');

Ts = 0.1;
p = 50;
nx = 3;
nu = 2;

x0 = [0;0;pi/2];
u0 = [0;0];

planner = nlmpcMultistage(p,nx,nu);
planner.Ts = Ts;
planner.Model.StateFcn = 'RobotStateFcn';

planner.MV(1).Min = 0;
planner.MV(1).Max = 1.5;
planner.MV(2).Min = -1.5;
planner.MV(2).Max = 1.5;

for t=1:p+1
    planner.Stages(t).CostFcn = 'RobotCostFcn';
    planner.Stages(t).IneqConFcn = 'RobotIneqConFcn';
    planner.Stages(t).ParameterLength = 3;
end
planner.Stages(p+1).CostFcn = 'RobotCostFcn';
planner.Stages(p+1).ParameterLength = 3;
planner.Model.TerminalState = [0;6;pi/2];

planner.Optimization.SolverOptions.MaxIterations = 100;
simdata.StageParameter = rand(nx*(p+1),1);
validateFcns(planner,rand(nx,1),rand(nu,1),simdata);

options = nlmpcMultistageToForcesOptions;
options.Server = 'https://forces.embotech.com/';
options.x0 = x0;
options.mv0 = u0;
options.NumInequalityConstraints = [ones(p,1); 0];
options.UseOnlineTerminalState = true;

[coredata, onlinedata, model] = nlmpcMultistageToForces(planner, options);

%%
load("c_tmp.mat");
load("r_tmp.mat");
load("xref_tmp.mat");
load("uref_tmp.mat");
xref = x;
uref = u;
cref = [c(:,1:25) repmat(c(:,26),1,25)];
rref = r;
myparam = [c; r];
onlinedata.TerminalState = [0;6;pi/2];
onlinedata.StageParameter = [reshape(myparam,[],1); 0;6;pi/2];
% myinit = reshape([xref(:,1:end-1); uref],[],1);
% onlinedata.InitialGuess = [myinit; xref(:,end)];
tic;
[~, onlinedata, infoFORCES] = nlmpcmove_myForcesNLPSolver(x0,u0,onlinedata);
toc;

xx = infoFORCES.Xopt';
uu = infoFORCES.MVopt';

figure; axis equal; xlim([-4,4]); ylim([-1,7]); hold on;
plot(xx(1,:),xx(2,:));

tmp = viscircles([0 0], 0);
tmp = viscircles(cref',rref','LineWidth',0.3);

% figure; axis equal; hold on;
% for t=1:10000
%     [~, onlinedata, infoFORCES] = nlmpcmove_myForcesNLPSolver(x0,u0,onlinedata);
%     x0 = infoFORCES.Xopt(2,:)';
%     u0 = infoFORCES.MVopt(2,:)';
%     plot(x0(1),x0(2),'.'); drawnow;
%     pause(0.1);
% end















