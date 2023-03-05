close all; clc; clear;

b1 = [-2.5,3.5,2,2.5];
b2 = [-2.5,0,2,2.5];
b3 = [0.5,0,2,6];

figure; axis equal; hold on;
clr = [0.7 0.7 0.7];
rectangle('Position',b1,'FaceColor',clr,'EdgeColor','none');
rectangle('Position',b2,'FaceColor',clr,'EdgeColor','none');
rectangle('Position',b3,'FaceColor',clr,'EdgeColor','none');

statobs(1).x = [b1(1),b1(1)+b1(3)];
statobs(1).y = [b1(2),b1(2)+b1(4)];
statobs(2).x = [b2(1),b2(1)+b2(3)];
statobs(2).y = [b2(2),b2(2)+b2(4)];
statobs(3).x = [b3(1),b3(1)+b3(3)];
statobs(3).y = [b3(2),b3(2)+b3(4)];

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% %% no overlap
% 
% T = 51;
% seq = linspace(5,0,T);
% obs = rectangle('Position',[0,0,0,0],'FaceColor',[0,0.5,0],'EdgeColor','none');
% 
% load('x2.mat');
% dynaobs = struct();
% for i=1:T
%     dynaobs(i).x = [-0.5,0.5];
%     dynaobs(i).y = [seq(i),seq(i)+1];
%     set(obs,'Position',[dynaobs(i).x(1),dynaobs(i).y(1),1,1]);
% %     plot(mean(dynaobs(i).x),mean(dynaobs(i).y),'.','Color','k');
%     plot(x(1,i),x(2,i),'.','Color','k','MarkerSize',15);
%     pause(0.1)
% end
% 
% %% overlap
% 
% T = 51;
% seq = linspace(4.8,0,T);
% obs = rectangle('Position',[0,0,0,0],'FaceColor',[0,0.5,0],'EdgeColor','none');
% 
% load('x3.mat');
% dynaobs = struct();
% for i=1:T
%     dynaobs(i).x = [-0.6,0.6];
%     dynaobs(i).y = [seq(i),seq(i)+1.2];
%     set(obs,'Position',[dynaobs(i).x(1),dynaobs(i).y(1),1.2,1.2]);
% %     plot(mean(dynaobs(i).x),mean(dynaobs(i).y),'.','Color','k');
%     plot(x(1,i),x(2,i),'.','Color','k','MarkerSize',15);
%     pause(0.1)
% end
% 
% %% overlap large
% 
% T = 51;
% seq = linspace(4.5,0,T);
% obs = rectangle('Position',[0,0,0,0],'FaceColor',[0,0.5,0],'EdgeColor','none');
% 
% load('x3.mat');
% dynaobs = struct();
% for i=1:T
%     dynaobs(i).x = [-1,1];
%     dynaobs(i).y = [seq(i),seq(i)+1.5];
%     set(obs,'Position',[dynaobs(i).x(1),dynaobs(i).y(1),2,1.5]);
%     plot(mean(dynaobs(i).x),mean(dynaobs(i).y),'.','Color','k','MarkerSize',15);
% %     plot(x(1,i),x(2,i),'.','Color','k','MarkerSize',15);
%     pause(0.2);
% end

%% horizonal

T = 51;
seq = linspace(-2,2,T);
obs = rectangle('Position',[0,0,0,0],'FaceColor',[0,0.5,0],'EdgeColor','none','Curvature',1);

dynaobs = struct();
for i=1:T
    dynaobs(i).x = seq(i);
    dynaobs(i).y = 3;
    set(obs,'Position',[dynaobs(i).x(1)-1,dynaobs(i).y(1)-1,2,2]);
%     plot(mean(dynaobs(i).x),mean(dynaobs(i).y),'.','Color','k');
%     plot(x(1,i),x(2,i),'.','Color','k','MarkerSize',15);
    pause(0.1)
end

%%
save('statobs.mat','statobs');
save('dynaobs.mat','dynaobs');
