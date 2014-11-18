function append_graph(names_file,source_file)
%clear all

global t_start t_end ng1;


% [ng_names,name]=read_names(names_file);
[ng_names,name]=read_name(names_file);
% source_file(1).name='for042';
%source_file(1).legend='kkk';


n_file=size(source_file,2);
for i=1:n_file
    [ng,ntime,m]=read_for042(source_file(i).name);
    
    time1=m(:,ntime);
    jj=size(time1)

i1=1;
i2=jj(1);

for k=1:jj(1)
    if(time1(k) <= t_start)
        i1=k;
    end
    if(time1(k) <= t_end)
        i2=k;
    end
    
end
i1
i2

    
    
    A(i).x=m(i1:i2,ntime);
    A(i).y=m(i1:i2,1:ng);
    A(i).leg=source_file(i).legend;
end

% [ng,ntime,m]=read_for042(source_file(1).name);
% A(1).x=m(:,ntime);
% A(1).y=m(:,1:ng);
% A(1).leg=source_file(1).legend;
% 
% [ng,ntime,m]=read_for042(source_file(2).name);
% A(2).x=m(:,ntime);
% A(2).y=m(:,1:ng);
% A(2).leg=source_file(2).legend;


i_graphic=0;

for i=1:ng1
    i_graph = mod(i,4); % to define subplot(2,2,# 1-3)
    if i_graph == 1 
        i_graphic=i_graphic+1;
        figure(i_graphic);  % to define figure(#)
    end 
    if i_graph == 0 
        i_graph=4; % to define subplot(2,2,# 4)
    end 
subplot(2,2,i_graph)
if n_file==1
    plot(A(1).x,A(1).y(:,i))%,'b',A(2).x,A(2).y(:,i),'r-.')%,A(3).x,A(3).y(:,i),'-g');%,'LineWidth',2)
 if i_graph == 4 
    legend('Location','Best',A(1).leg);
 end
end
if n_file==2
    plot(A(1).x,A(1).y(:,i),'b',A(2).x,A(2).y(:,i),'r')%,'LineWidth',2)
 if i_graph == 4 
    legend('Location','Best',A(1).leg,A(2).leg);
 end
 end
if n_file==3
    plot(A(1).x,A(1).y(:,i),'b',A(2).x,A(2).y(:,i),'r',A(3).x,A(3).y(:,i),'k');%,'LineWidth',2)
 if i_graph == 4 
    legend('Location','Best',A(1).leg,A(2).leg,A(3).leg);
 end
 end
if n_file==4
    plot(A(1).x,A(1).y(:,i),'b',A(2).x,A(2).y(:,i),'r',A(3).x,A(3).y(:,i),'k',A(4).x,A(4).y(:,i),'g');%,'LineWidth',2)
 if i_graph == 4 
    legend('Location','Best',A(1).leg,A(2).leg,A(3).leg,A(4).leg);
 end
 end

if n_file==5
    plot(A(1).x,A(1).y(:,i),'b',A(2).x,A(2).y(:,i),'r',A(3).x,A(3).y(:,i),'k',A(4).x,A(4).y(:,i),'g',A(5).x,A(5).y(:,i),'m');%,'LineWidth',2)
     if i_graph == 4 
legend('Location','Best',A(1).leg,A(2).leg,A(3).leg,A(4).leg,A(5).leg);
     end
     end


xlabel('time, s')
ylabel(name(i).text)

if i_graph==4
    fig_name=['app_' num2str(i_graphic)];
    print('-dtiff',fig_name);

    saveas(gcf, fig_name, 'fig')



end
end

% return
