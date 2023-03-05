clear; clc; close all;
addpath('ipddp\');
addpath('setup1\');
addpath('data\');
addpath('vi\');
addpath('solver\forces\');
setup2_2;
setup1;
setup;

tmp = viscircles([0 0], 0);

flag = true;
ttmp = pagemtimes(data.noise,randn(data.nu,data.N,data.T));
ttmp2 = pagemtimes(data1.noise,randn(data1.nz,data1.N,data1.T));

J_record = [];
rp_record = [];
u_record = [];
x_record = [];
xtmp = zeros(3,51);
utmp = zeros(2,50);

uprev = zeros(data.m,2);

for i=1:30000

    %%%%%%%%%%%%%%%%%%% MPPI %%%%%%%%%%%%%%%%%%%%%
    [x,u] = mppi(x0,u,data,ttmp);
    figure(3); plot(u','LineWidth',2); 
    ax=gca; ax.FontSize = 18;
    ylim([-1.3, 1.3]);
    yline(0.5,'LineStyle','--','LineWidth',1.5);
    yline(-0.5,'LineStyle','--','LineWidth',1.5);
    yline(1.2,'LineStyle','--','LineWidth',1.5);
    yline(-1.2,'LineStyle','--','LineWidth',1.5);
    drawnow;
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    %%%%%%%%%%%%%%%% corridor %%%%%%%%%%%%%%%%%%%%
    [c,r] = corridor(x,data1,ttmp2);
    delete(tmp);
    figure(1); tmp = viscircles(c',r','LineWidth',0.3);
    drawnow;
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    %%%%%%%%%%%%%%%%%% DDP %%%%%%%%%%%%%%%%%%%%%%%
%     x = repmat(x(:,1),1,51);
%     u = zeros(size(u));
    if flag
        [x,u,J,rp] = ipddp(x,u,uprev,c,r,data2,val,bp,fp);
        uprev = [u(:,1), uprev(:,1)];
    end
%     xtmp = x;
%     utmp = u;
    figure(2); plot(u','LineWidth',2); 
    ax=gca; ax.FontSize = 18;
    ylim([-1.3, 1.3]);
    yline(0.5,'LineStyle','--','LineWidth',1.5);
    yline(-0.5,'LineStyle','--','LineWidth',1.5);
    yline(1.2,'LineStyle','--','LineWidth',1.5);
    yline(-1.2,'LineStyle','--','LineWidth',1.5);
    drawnow;

    if mod(i,1) == 0; figure(1); data.getplot(1,x,u,data); end
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    %%%%%%%%%%%%%%%%%% FORCES %%%%%%%%%%%%%%%%%%%%%%%
%     if flag
%         myinit = reshape([x(:,1:end-1); u],[],1);
%         onlinedata.InitialGuess = [myinit; x(:,end)];
%         myparam = [c; r];
%         onlinedata.StageParameter = [reshape(myparam,[],1); 0;6;pi/2];
%         onlinedata.TerminalState = [0;6;pi/2];
%         [~, onlinedata, infoFORCES] = ...
%             nlmpcmove_myForcesNLPSolver(x(:,1),u(:,1),onlinedata);
%         x = infoFORCES.Xopt';
%         u = infoFORCES.MVopt(1:end-1,:)';
%     end
%     figure(2); plot(u','LineWidth',2); 
%     ax=gca; ax.FontSize = 18;
%     ylim([-1.3, 1.3]);
%     yline(0.5,'LineStyle','--','LineWidth',1.5);
%     yline(-0.5,'LineStyle','--','LineWidth',1.5);
%     drawnow;
% 
%     if mod(i,1) == 0; figure(1); data.getplot(x,u,data); end
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

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


