nx = 3;
nu = 2;

T = 50;
N = 2200;
rho = 0.01;
noise = diag([0.7 0.7]);

%% start value
x0 = [0;0;pi/2];
u = randn(nu,T)*0;
% u = [ones(1,T); ones(1,T)*0];

%% data
data.f = @f;
data.h = @h;
data.getcost = @getcost;

data.T = T;
data.N = N;
data.nx = nx;
data.nu = nu;
data.rho = rho;
data.noise = noise;

data.iter = 0;
load('statobs.mat');
load('dynaobs.mat');
data.statobs = statobs;
data.dynaobs = dynaobs;

% plot
data.getplot = @getplot;
data.showresult = @showresult;

figure(1); hold on; axis equal;
b1 = [-2.5,3.5,2,2.5];
b2 = [-2.5,0,2,2.5];
b3 = [0.5,0,2,6];
clr = [0.7 0.7 0.7];
% rectangle('Position',b1,'FaceColor',clr,'EdgeColor','none');
% rectangle('Position',b2,'FaceColor',clr,'EdgeColor','none');
% rectangle('Position',b3,'FaceColor',clr,'EdgeColor','none');
data.plotrect = rectangle('Position',[0,0,0,0],'FaceColor',[0.7 0.7 0.7],'EdgeColor','none','Curvature',1);
xlim([-6,6]); ylim([-1,7]); hold on;
ax=gca; ax.FontSize = 18;

data.plotdisp = line(0,0);
data.plotdisp1 = line(0,0);

%% functions
function y = f(x,u)

    dt = 0.1;
    y = [x(1,:) + dt*u(1,:).*cos(x(3,:)); 
         x(2,:) + dt*u(1,:).*sin(x(3,:));
         x(3,:) + dt*u(2,:)];
end
function y = h(u)

    y = [max(min(u(1,:),1.5),0);
         max(min(u(2,:),1.5),-1.5)];
end
function y = getcost(x0,U,data)
    
    N = data.N;
    T = data.T;
    f = data.f;
    h = data.h;

    x = repmat(x0,N);
    cost = zeros(1,N);
    for t=1:T
        u = U(:,:,t);
        x = f(x,h(u));
        so = data.statobs;
        do = data.dynaobs(t);
        cost = cost + l(x,u,so,do); 
    end
    y = cost + lf(x);

    function y = l(x,u,so,do)
        y = 1e-2*sum(u.^2) + 1e8*collisioncheck(x(1:2,:),so,do);
    end
    function y = lf(x)
        y = vecnorm(x - [0;6;pi/2],'inf')*8000;
    end
    function y = collisioncheck(x,so,do)
        
        tmp = 0;
%         % static
%         for i=1:length(so)
%             ix = x(1,:) > so(i).x(1) & x(1,:) < so(i).x(2);
%             iy = x(2,:) > so(i).y(1) & x(2,:) < so(i).y(2);
%             tmp = tmp | (ix & iy);
%         end

        % dynamic
%         ix = x(1,:) > do.x(1) & x(1,:) < do.x(2);
%         iy = x(2,:) > do.y(1) & x(2,:) < do.y(2);
        ixy = (x(1,:) - do.x(1)).^2 + (x(2,:) - do.y(1)).^2 < 1;
        y = tmp | ixy;
    end
end

function getplot(i,x,u,data)

    xi = data.dynaobs(1).x(1);
    yi = data.dynaobs(1).y(1);
    set(data.plotrect,'Position',[xi-1,yi-1,2,2]);
    
    if i == 0
    set(data.plotdisp,'XData',x(1,:),'Ydata',x(2,:),...
    'Marker','.','LineStyle','none','Color','k','MarkerSize',5);
    else
    set(data.plotdisp1,'XData',x(1,:),'Ydata',x(2,:),...
    'Marker','.','LineStyle','none','Color','c','MarkerSize',15);
    end
    drawnow;
end

% function getplot(x,u,data)
%     xi = data.dynaobs(1).x(1);
%     yi = data.dynaobs(1).y(1);
%     set(data.plotrect,'Position',[xi-1,yi-1,2,2]);
% 
%     set(data.plotdisp,'XData',x(1,:),'Ydata',x(2,:),...
%         'Marker','.','LineStyle','none','Color','k','MarkerSize',10);
%     drawnow;
% end

