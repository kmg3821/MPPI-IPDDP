function J = RobotFinalCostFcn(stage,x,u,p)

J = sum((x - p).^2)*300;
