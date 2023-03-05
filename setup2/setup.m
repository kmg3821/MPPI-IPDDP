nx = 6;
nu = 3;

T = 30;
N = 8000;
rho = 0.01;
noise = diag([1 1 1])*1.5;

%% start value
x0 = [0;0;0;0;0;0];
% load("quad_u.mat");
u = [zeros(2,T); ones(1,T)*9.81];

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

figure(1); axis equal;  hold on;

mycolor = [.8 .8 .8];
plotcube([4 2 2],[-2 1 -1],1,mycolor);
plotcube([2 1 1],[-2 2 1],1,mycolor);
plotcube([1 1 1],[1 2 1],1,mycolor);
plotcube([4 1 1],[-2 2 2],1,mycolor);

[x,y,z] = sphere;
c = [0 2 1];
r = 1;
x = x * r + c(1);
y = y * r + c(2);
z = z * r + c(3);
surf(x,y,z,'FaceColor',mycolor,'EdgeColor',mycolor/2);
xlim([-2 2]); ylim([-1 5]); zlim([-1 4]);
ax=gca; ax.FontSize = 18;

data.plotdisp = line(0,0);

%% functions
function y = f(x,u)

    dt = 0.05;
    y = x + dt*[x(4:6,:); u - 9.81*[0;0;1]];
end
function y = h(u)

    %%%%%%%%%%%%%%%%%%%%%%% sphere
    rmax = 20;
    
    [az,el,r] = cart2sph(u(1,:),u(2,:),u(3,:));
    r = min(r,rmax);
    [u(1,:),u(2,:),u(3,:)] = sph2cart(az,el,r);
    %%%%%%%%%%%%%%%%%%%%%%%
    
    %%%%%%%%%%%%%%%%%%%%%%% soc
    T = diag([1 1 tan(deg2rad(60))]); % must be 45 degree above
    u = T*u;
    idx = find(vecnorm(u(1:2,:)) < -u(3,:));
    u(:,idx) = 0;
    idx = find(vecnorm(u(1:2,:)) > abs(u(3,:)));
    u(:,idx) = (1 + u(3,idx)./vecnorm(u(1:2,idx))).*[u(1:2,idx); vecnorm(u(1:2,idx))]/2;
    y = T\u;
    %%%%%%%%%%%%%%%%%%%%%%%
end
function y = getcost(x0,U,data)
    
    N = data.N;
    T = data.T;
    f = data.f;
    h = data.h;

    x = repmat(x0,1,N);
    cost = zeros(1,N);
    for t=1:T
        u = U(:,:,t);
        x = f(x,h(u));
        cost = cost + l(x,u); 
    end
    y = cost + lf(x);

    function y = l(x,u)
        y = 1e-2*sum(u.^2) + 1e8*collisioncheck(x(1:3,:));
    end
    function y = lf(x)
        xf = [0;4;2;0;0;0];
        y = vecnorm(x - xf,'inf')*500;
    end
    function y = collisioncheck(x)

        %
        ox = x(1,:) > -2 & x(1,:) < 2;
        oy = x(2,:) > 1 & x(2,:) < 3;
        oz = x(3,:) > -10 & x(3,:) < 1;
        y = ox & oy & oz;

        %
        ox = x(1,:) > -2 & x(1,:) < 0;
        oy = x(2,:) > 2 & x(2,:) < 3;
        oz = x(3,:) > 1 & x(3,:) < 2;
        y = y | (ox & oy & oz);

        %
        ox = x(1,:) > 1 & x(1,:) < 2;
        oy = x(2,:) > 2 & x(2,:) < 3;
        oz = x(3,:) > 1 & x(3,:) < 2;
        y = y | (ox & oy & oz);

        %
        ox = x(1,:) > -2 & x(1,:) < 2;
        oy = x(2,:) > 2 & x(2,:) < 3;
        oz = x(3,:) > 2 & x(3,:) < 3;
        y = y | (ox & oy & oz);

        %
        oo = sum((x-[0;2;1]).^2) < 1;
        y = y | oo;
    end
end

function getplot(x,u,data)
    set(data.plotdisp,'XData',x(1,:),'Ydata',x(2,:),'Zdata',x(3,:),...
        'Marker','.','LineStyle','none','MarkerSize',12,'MarkerEdgeColor','k');
    drawnow;
end

