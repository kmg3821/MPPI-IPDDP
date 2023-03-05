nz = 3; % [cx,cy,r]

T = 50;
N = 500;
rho = 0.001;
noise = diag([0.08 0.08 0.05]);
rmax = 0.8;

%% data
data1.hz = @hz;
data1.getcost = @getcost;
data1.rmax = rmax;

data1.T = T;
data1.N = N;
data1.nz = nz;
data1.rho = rho;
data1.noise = noise;

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
    y = l(z,p); 

    function y = l(z,p)
        x = z(1:2,:,:) - reshape(p,2,1,[]);
        y = -35*z(3,:,:) + 20*vecnorm(x,2) + 1e8*collisioncheck(z);
    end
    function y = collisioncheck(z)

        y = 0;
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%
        yx = z(1,:,:) > -12.5 - z(3,:,:) & z(1,:,:) < 0.8 + z(3,:,:);
        yy = z(2,:,:) > 2 - z(3,:,:) & z(2,:,:) < 5 + z(3,:,:);
        y = y | (yx & yy);
        yx = (z(1,:,:) + 1).^2 + (z(2,:,:) - 3).^2 < (1.5 + z(3,:,:)).^2;
        y = y | yx;
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%
        yx = z(1,:,:) > 1 - z(3,:,:) & z(1,:,:) < 13 + z(3,:,:);
        yy = z(2,:,:) > 2 - z(3,:,:) & z(2,:,:) < 5 + z(3,:,:);
        y = y | (yx & yy);
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%
        yx = (z(1,:,:) - 0.5).^2 + (z(2,:,:) - 1).^2 < (0.3 + z(3,:,:)).^2;
        y = y | yx;
    end
end

function getplot(x,u,data)
    set(data.plotdisp,'XData',x(1,:),'Ydata',x(2,:),...
        'Marker','o','LineStyle','none');
    drawnow;
end

