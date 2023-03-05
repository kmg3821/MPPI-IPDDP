function dxdt = RobotStateFcn(x,u)


dxdt = [u(1)*cos(x(3)); u(1)*sin(x(3)); u(2)];


