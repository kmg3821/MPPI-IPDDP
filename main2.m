clear; clc; close all;
addpath('ipddp\');
addpath('setup2\');
addpath('data\');
addpath('vi\');
setup2_2;
setup1;
setup;
% load('quad_final.mat');

flag = true;
ttmp = pagemtimes(data.noise,randn(data.nu,data.N,data.T));
ttmp2 = pagemtimes(data1.noise,randn(data1.nz,data1.N,data1.T));

acc = quiver(0,0,0,0);

J_record = [];
rp_record = [];

for i=1:30000

    %%%%%%%%%%%%%%%%%%% MPPI %%%%%%%%%%%%%%%%%%%%%
    [x,u] = mppi(x0,u,data,ttmp);
    figure(3); plot(u','LineWidth',2); 
    ax=gca; ax.FontSize = 18;
    ylim([-21, 21]);
    yline(20,'LineStyle','--','LineWidth',1.5);
    yline(-20,'LineStyle','--','LineWidth',1.5);
    drawnow;
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    %%%%%%%%%%%%%%%% corridor %%%%%%%%%%%%%%%%%%%%
    [c,r] = corridor3d(x,data1,ttmp2);
    data1.getplot(c,r,data1);
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    %%%%%%%%%%%%%%%%%% DDP %%%%%%%%%%%%%%%%%%%%%%%
    if flag
        [x,u,J,rp] = ipddp(x,u,c,r,data2,val,bp,fp);
    end
    figure(2); plot(u','LineWidth',2); 
    ax=gca; ax.FontSize = 18;
    ylim([-21, 21]);
    yline(20,'LineStyle','--','LineWidth',1.5);
    yline(-20,'LineStyle','--','LineWidth',1.5);
    drawnow;

    figure(1);
    set(acc,'XData',x(1,1:end-1),'YData',x(2,1:end-1),'ZData', x(3,1:end-1), ...
        'UData',u(1,:),'VData',u(2,:),'WData',u(3,:),'Color','g','LineWidth',1.5)

    if mod(i,1) == 0; figure(1); data.getplot(x,u,data); end
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

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
% data.showresult(x,squeeze(u)',data)

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


