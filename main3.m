clear; clc; close all;
addpath('ipddp\');
addpath('setup3\');
addpath('data\');
addpath('vi\');
addpath('map\');
setup2_2;
setup1;
setup;

tmp = viscircles([0 0], 0);

flag = true;
ttmp = pagemtimes(data.noise,randn(data.nu,data.N,data.T));
ttmp2 = pagemtimes(data1.noise,randn(data1.nz,data1.N,data1.T));

uprev = zeros(data.m,2);

J_record = [];
rp_record = [];
u_record = [];
x_record = [];

for i=1:30000

    %%%%%%%%%%%%%%%%%%% MPPI %%%%%%%%%%%%%%%%%%%%%
    [x,u] = mppi(x0,u,data,ttmp);
    figure(3); plot(u','LineWidth',2); 
    ax=gca; ax.FontSize = 18;
    ylim([-1.6, 1.6]);
    yline(1.5,'LineStyle','--','LineWidth',1.5);
    yline(-1.5,'LineStyle','--','LineWidth',1.5);
    drawnow;
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    %%%%%%%%%%%%%%%% corridor %%%%%%%%%%%%%%%%%%%%
    [c,r] = corridor(x,data1,ttmp2);
    delete(tmp);
    figure(1); tmp = viscircles(c',r','LineWidth',0.3);
    drawnow;
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    %%%%%%%%%%%%%%%%%% DDP %%%%%%%%%%%%%%%%%%%%%%%
    if flag
        [x,u,J,rp] = ipddp(x,u,uprev,c,r,data2,val,bp,fp);
        uprev = [u(:,1), uprev(:,1)];
    end
    figure(2); plot(u','LineWidth',2); 
    ax=gca; ax.FontSize = 18;
    ylim([-1.6, 1.6]);
    yline(1.5,'LineStyle','--','LineWidth',1.5);
    yline(-1.5,'LineStyle','--','LineWidth',1.5);
    drawnow;

    if mod(i,1) == 0; figure(1); data.getplot(1,x,u,data); end
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    data.iter = data.iter + 1;
    data1.iter = data1.iter + 1;
    for j = 1:50
        data.dynaobs(j).x(1) = data.dynaobs(j+1).x(1);
        data.dynaobs(j).y(1) = data.dynaobs(j+1).y(1);
        data1.dynaobs(j).x(1) = data.dynaobs(j+1).x(1);
        data1.dynaobs(j).y(1) = data.dynaobs(j+1).y(1);
    end

    x0 = x(:,2);
    u = [u(:,2:end) u(:,end)];
    u_record = [u_record, u(:,1)];
    x_record = [x_record, x0];

%     J_record = [J_record J];
%     rp_record = [rp_record norm(rp,'inf')];
% 
%     str = '1_' + string(i) + '.png';
%     saveas(figure(1),str);
%     str = '2_' + string(i) + '.png';
%     saveas(figure(2),str);
%     str = '3_' + string(i) + '.png';
%     saveas(figure(3),str);
end

%%

figure(4); plot(J_record,'LineWidth',2,'Color','k'); 
ax=gca; ax.FontSize = 18;
xlim([1,length(J_record)]);
drawnow;

figure(5); plot(rp_record,'LineWidth',2,'Color','k'); 
ax=gca; ax.FontSize = 18;
xlim([1,length(rp_record)]);
drawnow;

str = '4_' + string(i) + '.png';
saveas(figure(4),str);
str = '5_' + string(i) + '.png';
saveas(figure(5),str);


