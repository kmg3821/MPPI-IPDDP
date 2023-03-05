nz = 3; % [cx,cy,r]

T = 50;
N = 1000;
rho = 0.001;
noise = diag([0.3 0.3 0.08]);
rmax = 0.8;

%% data
data.hz = @hz;
data.getcost = @getcost;
data.rmax = rmax;

data.T = T;
data.N = N;
data.nz = nz;
data.rho = rho;
data.noise = noise;

data.iter = 0;
load('statobs.mat');
load('dynaobs.mat');
data.statobs = statobs;
data.dynaobs = dynaobs;

data1 = data;

%% functions
function y = hz(z,p,rmax) 

    % z: (nz x N) x T
    % p: 2 x T

    r = max(min(z(3,:,:),rmax),0);
    y(3,:,:) = r;
    x = z(1:2,:,:) - reshape(p,2,1,[]);

    xmag = vecnorm(x,2);
    idx = find(xmag > r);
    x(:,idx) = x(:,idx)./xmag(:,idx).*r(:,idx);
    y(1:2,:,:) = x + reshape(p,2,1,[]);
end
function y = getcost(z,p,data)

    % z: (nz x N) x T
    % p: 2 x T
    
    hz = data.hz;
    rmax = data.rmax;

    z = hz(z,p,rmax);
    so = data.statobs;
    do = data.dynaobs;
    y = l(z,p,so,do); 

    function y = l(z,p,so,do)
        x = z(1:2,:,:) - reshape(p,2,1,[]);
        y = -35*z(3,:,:) + 20*vecnorm(x,2) + 1e8*collisioncheck(z,so,do);
    end
    function y = collisioncheck(z,so,do)

        tmp = zeros(1,size(z,2),size(z,3));
%         % static
%         for i=1:length(so)
%             ix = z(1,:,:) > so(i).x(1) - z(3,:,:) & z(1,:,:) < so(i).x(2) + z(3,:,:);
%             iy = z(2,:,:) > so(i).y(1) - z(3,:,:) & z(2,:,:) < so(i).y(2) + z(3,:,:);
%             tmp = tmp | (ix & iy);
%         end
%         tmp = tmp*0;

        % dynamic
        for t=1:size(z,3)
%             ix = z(1,:,t) > do(t).x(1) - z(3,:,t) & z(1,:,t) < do(t).x(2) + z(3,:,t);
%             iy = z(2,:,t) > do(t).y(1) - z(3,:,t) & z(2,:,t) < do(t).y(2) + z(3,:,t);
            ixy = (z(1,:,t) - do(t).x(1)).^2 + (z(2,:,t) - do(t).y(1)).^2 < (1 + z(3,:,t)).^2;
            tmp(:,:,t) = ixy;
        end
        y = tmp;
    end
end

function getplot(x,u,data)
    set(data.plotdisp,'XData',x(1,:),'Ydata',x(2,:),...
        'Marker','o','LineStyle','none');
    drawnow;
end

