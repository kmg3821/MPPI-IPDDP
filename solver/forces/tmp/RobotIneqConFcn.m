function C = RobotIneqConFcn(stage,x,u,p)

C = sum((x(1:2) - p(1:2)).^2) - p(3)^2;
