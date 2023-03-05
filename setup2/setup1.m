nz = 4; % [cx,cy,cz,r]

T = 30;
N = 5000;
rho = 0.001;
noise = diag([0.3 0.3 0.3 0.08]);
rmax = 0.5;

%% data
data1.hz = @hz;
data1.getcost = @getcost;
data1.rmax = rmax;

data1.T = T;
data1.N = N;
data1.nz = nz;
data1.rho = rho;
data1.noise = noise;

data1.plotdisp = surf([],[],[]);
data1.getplot = @getplot;

%% functions
function y = hz(z,p,rmax) 

    % z: (nz x N) x T
    % p: 2 x T

    r = max(min(z(4,:,:),rmax),0);
    y(4,:,:) = r;
    x = z(1:3,:,:) - reshape(p,3,1,[]);

    xmag = vecnorm(x);
    idx = find(xmag > r);
    x(:,idx) = x(:,idx)./xmag(:,idx).*r(:,idx);
    y(1:3,:,:) = x + reshape(p,3,1,[]);
end
function y = getcost(z,p,data)

    % z: (nz x N) x T
    % p: 3 x T
    
    hz = data.hz;
    rmax = data.rmax;

    z = hz(z,p,rmax);
    y = l(z,p); 

    function y = l(z,p)
        x = z(1:3,:,:) - reshape(p,3,1,[]);
        y = -35*z(4,:,:) + 20*vecnorm(x) + 1e8*collisioncheck(z);
    end
    function y = collisioncheck(z)

        %
        ox = z(1,:,:) + z(4,:,:) > -2 & z(1,:,:) - z(4,:,:) < 2;
        oy = z(2,:,:) + z(4,:,:) > 1 & z(2,:,:) - z(4,:,:) < 3;
        oz = z(3,:,:) + z(4,:,:) > -10 & z(3,:,:) - z(4,:,:) < 1;
        y = ox & oy & oz;

        %
        ox = z(1,:,:) + z(4,:,:) > -2 & z(1,:,:) - z(4,:,:) < 0;
        oy = z(2,:,:) + z(4,:,:) > 2 & z(2,:,:) - z(4,:,:) < 3;
        oz = z(3,:,:) + z(4,:,:) > 1 & z(3,:,:) - z(4,:,:) < 2;
        y = y | (ox & oy & oz);

        %
        ox = z(1,:,:) + z(4,:,:) > 1 & z(1,:,:) - z(4,:,:) < 2;
        oy = z(2,:,:) + z(4,:,:) > 2 & z(2,:,:) - z(4,:,:)  < 3;
        oz = z(3,:,:) + z(4,:,:) > 1 & z(3,:,:) - z(4,:,:)  < 2;
        y = y | (ox & oy & oz);

        %
        ox = z(1,:,:) + z(4,:,:) > -2 & z(1,:,:) - z(4,:,:) < 2;
        oy = z(2,:,:) + z(4,:,:) > 2 & z(2,:,:) - z(4,:,:) < 3;
        oz = z(3,:,:) + z(4,:,:) > 2 & z(3,:,:) - z(4,:,:) < 3;
        y = y | (ox & oy & oz);

        %
        oo = sum((z(1:3,:,:)-[0;2;1]).^2) < (1 + z(4,:,:)).^2;
        y = y | oo;
    end
end

function getplot(c,r,data)
    
    [x,y,z] = sphere;
    x = x';
    y = y';
    z = z';
    
    x = repmat(x,1,1,data.T).*reshape(r,1,1,[]) + reshape(c(1,:),1,1,[]);
    x = reshape(x,21,[]);
    
    y = repmat(y,1,1,data.T).*reshape(r,1,1,[]) + reshape(c(2,:),1,1,[]);
    y = reshape(y,21,[]);
    
    z = repmat(z,1,1,data.T).*reshape(r,1,1,[]) + reshape(c(3,:),1,1,[]);
    z = reshape(z,21,[]);
    
    set(data.plotdisp,'XData',x,'YData',y,'ZData',z,'FaceAlpha',0.1,'FaceColor','r','EdgeColor','none');
end

