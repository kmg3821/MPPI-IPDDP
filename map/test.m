close all; clc; clear;

mperc = 0.02;
xplen = 200;
yplen = 200;
mymap = char(zeros(xplen,yplen)); % 단위: 번째

mymap(30:45,30:45) = 1;
mymap(130:145,30:45) = 1;
mymap(130:145,130:145) = 1;
mymap(30:50,130:155) = 1;
mymap(40:60,120:140) = 0;
mymap(80:120,90:110) = 1;
mymap(90:110,80:120) = 1;
mymap(40:50,80:100) = 1;

p = find(mymap == 1)';
xp = mod(p,xplen);
yp = (p - xp)/xplen + 1;
p = ([xp; yp] - 1)*mperc;


figure; axis equal; hold on;
xlim([0,(xplen-1)*mperc]); ylim([0,(yplen-1)*mperc]);
plot(p(1,:),p(2,:),'.','Markersize',15);

% q = randn(2,50);
% q(1,:) = q(1,:)*3 + 20;
% q(2,:) = q(2,:)*3 + 20;
% r = min(vecnorm(q - reshape(p,2,1,[]),2,1),[],3);
% r = r .* (r > mperc);
% 
% 
% tmp = viscircles(q',r','LineWidth',0.3);
% plot(q(1,:),q(2,:),'.','Color','k','Markersize',15);
% drawnow;


%%
global pref; pref = p;
options = optimoptions('fmincon','Algorithm','sqp');
x0 = ([3.5;3.5;0] - [0;0;pi/2])*linspace(0,1,50);
u0 = zeros(2,50);
xu0 = [reshape(x0,[],1);reshape(u0,[],1)];
xu = fmincon(@f,xu0,[],[],[],[],[],[],@mycon,options);
x = reshape(xu(1:150),3,[]);
u = reshape(xu(151:250),2,[]);


% figure; axis equal; xlim([-4,4]); ylim([-1,7]); hold on;
plot(x(1,:),x(2,:));


function y = f(xu)

    x0 = [0;0;pi/2];
    x = reshape(xu(1:150),3,[]);
    u = reshape(xu(151:250),2,[]);

    l = 1e-2*sum(u(1,:).^2,'all') + 1e-2*sum(u(2,:).^2,'all');
    lf = sum((x(:,end) - [3.4;3.4;0]).^2,'all')*300;
    y = l + lf;
end

function [c,cq] = mycon(xu)
    c = cineq(xu);
    cq = ceq(xu);
end

function y = cineq(xu)

    global pref;
    x0 = [0;0;pi/2];
    x = reshape(xu(1:150),3,[]);
    u = reshape(xu(151:250),2,[]);

    y = constr([x0,x(:,1:end-1)],u);
    
    function y = constr(x,u)
        vmax = 1.5;
        wmax = 1.5;

        y1 = [u(1,:) - vmax; 
              -u(1,:) - vmax*0;
              u(2,:) - wmax; 
              -u(2,:) - wmax];
        y1 = reshape(y1,[],1);
        y2 = -min(squeeze(sum((x(1:2,:) - reshape(pref,2,1,[])).^2,1)),[],2) + 0.08^2;
        y = [y1; y2];

    end
end

function y = ceq(xu)

    x0 = [0;0;pi/2];
    x = reshape(xu(1:150),3,[]);
    u = reshape(xu(151:250),2,[]);
    
    y = x - dyna([x0,x(:,1:end-1)],u);
    y = reshape(y,[],1);
    
    function y = dyna(x,u)
        y = [x(1,:) + 0.08*u(1,:).*cos(x(3,:)); 
             x(2,:) + 0.08*u(1,:).*sin(x(3,:));
             x(3,:) + 0.08*u(2,:)];
    end
end


















