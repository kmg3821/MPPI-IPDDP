nx = 3;
nu = 2;

T = 50;
N = 1800;
rho = 3;
noise = diag([0.3 0.7]);

%% start value
x0 = [0;0;pi/2];
u = randn(nu,T)*0;

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

% plot
data.getplot = @getplot;
data.showresult = @showresult;

figure(1); hold on; axis equal;
rectangle('Position',[-2.5 2 3.3 3],'FaceColor',[0.7 0.7 0.7],'EdgeColor','none');
rectangle('Position',[1 2 2 3],'FaceColor',[0.7 0.7 0.7],'EdgeColor','none');
rectangle('Position',[0.2 0.7 0.6 0.6],'Curvature',1,'FaceColor',[0.7 0.7 0.7],'EdgeColor','none');
axis equal; xlim([-4,4]); ylim([-1,7]); hold on;
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

    y = [max(min(u(1,:),1.0),0);
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
        cost = cost + l(x,u); 
    end
    y = cost + lf(x);

    function y = l(x,u)
        y = 1*sum(u.^2) + 1e-1*vecnorm(x(1:2,:) - [0;6],'inf') + 1e8*collisioncheck(x(1:2,:));
    end
    function y = lf(x)
        y = vecnorm(x - [0;6;pi/2],'inf')*800;
    end
    function y = collisioncheck(x)

        y = 0;

        yx = x(1,:) > -12.5 & x(1,:) < 0.8;
        yy = x(2,:) > 2 & x(2,:) < 5;
        y = y| (yx & yy);
        yx = (x(1,:) + 1).^2 + (x(2,:) - 3).^2 < 1.5^2;
        y = y | yx;

        yx = x(1,:) > 1 & x(1,:) < 13;
        yy = x(2,:) > 2 & x(2,:) < 5;
        y = y | (yx & yy);

        yx = (x(1,:) - 0.5).^2 + (x(2,:) - 1).^2 < 0.3^2;
        y = y | yx;
    end
end

% function getplot(x,u,data)
%     set(data.plotdisp,'XData',x(1,:),'Ydata',x(2,:),...
%         'Marker','.','LineStyle','none','Color','k','MarkerSize',10);
%     drawnow;
% end

function getplot(i,x,u,data)
    
    if i == 0
    set(data.plotdisp,'XData',x(1,:),'Ydata',x(2,:),...
        'Marker','.','LineStyle','none','Color','k','MarkerSize',5);
    else
    set(data.plotdisp1,'XData',x(1,:),'Ydata',x(2,:),...
    'Marker','.','LineStyle','none','Color','c','MarkerSize',15);
    end
    drawnow;
end

