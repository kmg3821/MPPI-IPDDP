function J = RobotCostFcn(stage,x,u,p)

J = sum(u.^2)*1e-2 + sum((x(1:2) - [0;6]).^2)*1e-1 + sum((x(1:2) - p(1:2)).^2)*1e-3;
