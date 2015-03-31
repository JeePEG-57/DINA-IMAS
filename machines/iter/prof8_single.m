%*================================================================*
%* Function prof8() is used to plot profiles of plasma parameters *
%* from psi_data1 files. There are eight plasma parameters here.  *
%* Input - k_step  - throught what number of time moment to plot  *
%*       - j_start - number of initial time moment                *   
%* Output is absent                                               *
%* It is created by TRINITI team at 17.05.02                      *    
%*================================================================* 

k_beg=7;
%k_beg=7;
%k_step=1;
file_name='p_data1';

while(1)
       fid=fopen(file_name,'r');
	break;
	end;
%	end;

j=0;
while 1
    
    
   eofstat=feof(fid);
	if(eofstat)
      break;
   end
   [iprof,count]=fscanf(fid,'%d',1);
   if(count==0)
      break;
   end
   j=j+1;
   
   [t(j),count]=fscanf(fid,'%g',1);
   
   
   for i=1:iprof
      tm(j,i)=t(j);
      [x(j,i),count]=fscanf(fid, '%g',1);
   end
   count;
%=========================================   

   for i=1:iprof
      [z1(j,i),count]=fscanf(fid, '%g',1);
   end
   
   count;
   xx=t(j);
   xx;
   
%=========================================   
   for i=1:iprof
      [z2(j,i),count]=fscanf(fid, '%g',1);
	end
%=========================================
   for i=1:iprof
      [z3(j,i),count]=fscanf(fid, '%g',1);
   end
%=========================================   
   for i=1:iprof
      [z4(j,i),count]=fscanf(fid, '%g',1);
   %	C(j,i)=j;   
   end
%	j=j+1;
%=========================================   
   for i=1:iprof
      [z5(j,i),count]=fscanf(fid, '%g',1);
   %	C(j,i)=j;   
   end
%	j=j+1;
%=========================================   
   for i=1:iprof
      [z6(j,i),count]=fscanf(fid, '%g',1);
   %	C(j,i)=j;   
   end
%	j=j+1;
%=========================================   
   for i=1:iprof
      [z7(j,i),count]=fscanf(fid, '%g',1);
   %	C(j,i)=j;   
   end
%	j=j+1;
%=========================================   
   for i=1:iprof
      [z8(j,i),count]=fscanf(fid, '%g',1);
   	C(j,i)=j;   
   end
%	j=j+1;


j;

end
   
fid=fclose(fid);
%pause


%---------------------------------------------------------!
% psi_data1 have already been read                        !
%                                                         !
% ========================================================!
%                                                         !
% start plotting (8 pictures) by means of "while loop"    !
%                                                         !    
% ========================================================!
 
jt=1; % for control in "while loop" 
kkk=0; % number of figure 
j;

if(j==1)
    x(2,:)=x(1,:);
    z1(2,:)=z1(1,:);
    z2(2,:)=z2(1,:);
    z3(2,:)=z3(1,:);
    z4(2,:)=z4(1,:);
    z5(2,:)=z5(1,:);
    z6(2,:)=z6(1,:);
    z7(2,:)=z7(1,:);
    z8(2,:)=z8(1,:);
end    
if(j==2)
    x(3,:)=x(1,:);
    z1(3,:)=z1(1,:);
    z2(3,:)=z2(1,:);
    z3(3,:)=z3(1,:);
    z4(3,:)=z4(1,:);
    z5(3,:)=z5(1,:);
    z6(3,:)=z6(1,:);
    z7(3,:)=z7(1,:);
    z8(3,:)=z8(1,:);
end    

jt =k_beg;

while(jt<=j)
jt;
j1=jt; 
j2=jt+k_step; 
j3=jt+2*k_step;
if j2>j j2=j; end;
if j3>j j3=j; end;
jt=jt+3*k_step;

kkk=kkk+1;
figure(1);
clf

% =============== 1-4 graphics ==========================!
subplot(2,2,1);

  plot(x(j1,:),z1(j1,:),x(j2,:),z1(j2,:),x(j3,:),z1(j3,:));
  %title(['time(1)= ' num2str(t(j1)) ' ms' ' time(2)= ' num2str(t(j2)) ' ms' ' t(3)= ' num2str(t(j3)) ' ms']);  

  grid on; 
  tit1=[num2str(j1) ' - ' num2str(t(j1)) ' ms'];
  tit2=[num2str(j2) ' - ' num2str(t(j2)) ' ms'];
  tit3=[num2str(j3) ' - ' num2str(t(j3)) ' ms'];
  tit=[tit1 ' ' tit2 ' ' tit3];
  %title(tit);


%  x0=min(x(j1,:))+0.2*(max(x(j1,:))-min(x(j1,:)));
%  y0=max(z1(j,:))-0.2*(max(z1(j1,:))-min(z1(j1,:)));
%  dy=0.15*(max(z1(j1,:))-min(z1(j1,:)));
%  text(x0,y0,tit1);
%  text(x0,y0-dy,tit2);
%  text(x0,y0-2*dy,tit3);

  q1=[num2str(t(j1)) ' ms'];
  q2=[num2str(t(j2)) ' ms'];
  q3=[num2str(t(j3)) ' ms'];
  %legend(num2str(j1),num2str(j2),num2str(j3));
  %legend(q1,q2,q3);  	
  %legend(num2str(j1),num2str(j2),num2str(j3),1);
  %legend('1','2','3');
  xlabel('r [cm]');
  ylabel('j_p, kA/cm^2');
  

subplot(2,2,2);

  plot(x(j1,:),z2(j1,:),x(j2,:),z2(j2,:),x(j3,:),z2(j3,:));
  %title(['time(1)= ' num2str(t(j1)) ' ms' ' time(2)= ' num2str(t(j2)) ' ms' ' t(3)= ' num2str(t(j3)) ' ms']);  
  grid on;

  %tit1=[num2str(j1) ' - ' num2str(t(j1)) ' ms'];
  %tit2=[num2str(j2) ' - ' num2str(t(j2)) ' ms'];
  %tit3=[num2str(j3) ' - ' num2str(t(j3)) ' ms'];
  tit1=['1- ' num2str(t(j1)) ' ms'];
  tit2=['2- ' num2str(t(j2)) ' ms'];
  tit3=['3- ' num2str(t(j3)) ' ms'];
  tit=[tit1 ' ' tit2 ' ' tit3];
  %title(tit);

  x0=min(x(j1,:))+0.2*(max(x(j1,:))-min(x(j1,:)));
  yyy=[z2(j1,:) z2(j2,:) z2(j3,:)];
  ymin=min(yyy);
  ymax=max(yyy);

  y0=ymax-0.2*(ymax-ymin);
  dy=0.15*(ymax-ymin);
  %text(x0,y0,tit1);
  %text(x0,y0-dy,tit2);
  %text(x0,y0-2*dy,tit3);

  q1=[num2str(t(j1)) ' ms'];
  q2=[num2str(t(j2)) ' ms'];
  q3=[num2str(t(j3)) ' ms'];
  %legend(q1,num2str(j2),num2str(j3));
  %legend(q1,q2,q3);  	
  %legend(num2str(j1),num2str(j2),num2str(j3),1);
  xlabel('r [cm]');
  %ylabel('pprime'); 
  ylabel('n d');


subplot(2,2,3);

  hold on
  plot(x(j1,:),z1(j1,:),'k');
  plot(x(j2,:),z1(j2,:),'k');
  plot(x(j3,:),z1(j3,:),'k');
  grid on;
  
  plot(x(j1,:),z3(j1,:),'b');
  plot(x(j2,:),z3(j2,:),'r');
  plot(x(j3,:),z3(j3,:),'m');
  
  %legend(num2str(j1),num2str(j2),num2str(j3));
  xlabel('r [cm]');
  ylabel('J bo');

subplot(2,2,4);

  plot(x(j1,:),z4(j1,:),x(j2,:),z4(j2,:),x(j3,:),z4(j3,:));
  grid on;
  
  legend('1','2','3');
  
  xlabel('r [cm]');
%  ylabel('pff');
  ylabel('P');
     

%======================================================================!

  k_fig=kkk;
  str2=[ 'prof' num2str(k_fig) ];
  
 % keyboard;
  
  saveas(gcf, str2, 'fig')

 saveas(gcf, str2, 'tif')


figure(2)


 kkk=kkk+1;

% =============== 5-8 graphics ==========================!
subplot(2,2,1);

  plot(x(j1,:),z5(j1,:),x(j2,:),z5(j2,:),x(j3,:),z5(j3,:));
  %title(['time(1)= ' num2str(t(j1)) ' ms' ' time(2)= ' num2str(t(j2)) ' ms' ' t(3)= ' num2str(t(j3)) ' ms']);  

  grid on; 
  tit1=[num2str(j1) ' - ' num2str(t(j1)) ' ms'];
  tit2=[num2str(j2) ' - ' num2str(t(j2)) ' ms'];
  tit3=[num2str(j3) ' - ' num2str(t(j3)) ' ms'];
  tit=[tit1 ' ' tit2 ' ' tit3];
  %title(tit);


%  x0=min(x(j1,:))+0.2*(max(x(j1,:))-min(x(j1,:)));
%  y0=max(z1(j,:))-0.2*(max(z1(j1,:))-min(z1(j1,:)));
%  dy=0.15*(max(z1(j1,:))-min(z1(j1,:)));
%  text(x0,y0,tit1);
%  text(x0,y0-dy,tit2);
%  text(x0,y0-2*dy,tit3);

  q1=[num2str(t(j1)) ' ms'];
  q2=[num2str(t(j2)) ' ms'];
  q3=[num2str(t(j3)) ' ms'];
  %legend(q1,num2str(j2),num2str(j3));
  %legend(q1,q2,q3);  	
  %legend(num2str(j1),num2str(j2),num2str(j3),1);
  %legend('1','2','3');
  xlabel('r [cm]');
  ylabel('-q-');

  
subplot(2,2,2);

  plot(x(j1,:),z6(j1,:),x(j2,:),z6(j2,:),x(j3,:),z6(j3,:));
  %title(['time(1)= ' num2str(t(j1)) ' ms' ' time(2)= ' num2str(t(j2)) ' ms' ' t(3)= ' num2str(t(j3)) ' ms']);  
  grid on;

  tit1=['1 - ' num2str(t(j1)) ' ms'];
  tit2=['2 - ' num2str(t(j2)) ' ms'];
  tit3=['3 - ' num2str(t(j3)) ' ms'];
  tit=[tit1 ' ' tit2 ' ' tit3];
  %title(tit);

  x0=min(x(j1,:))+0.2*(max(x(j1,:))-min(x(j1,:)));
  yyy=[z6(j1,:) z6(j2,:) z6(j3,:)];
  ymin=min(yyy);
  ymax=max(yyy);

  y0=ymax-0.2*(ymax-ymin);
  dy=0.15*(ymax-ymin);
  text(x0,y0,tit1);
  text(x0,y0-dy,tit2);
  text(x0,y0-2*dy,tit3);

  q1=[num2str(t(j1)) ' ms'];
  q2=[num2str(t(j2)) ' ms'];
  q3=[num2str(t(j3)) ' ms'];
  %legend(q1,num2str(j2),num2str(j3));
  %legend(q1,q2,q3);  	
  %legend(num2str(j1),num2str(j2),num2str(j3),1);
  xlabel('r [cm]');
  %ylabel('f');
  ylabel('N e');


subplot(2,2,3);

  plot(x(j1,:),z7(j1,:),x(j2,:),z7(j2,:),x(j3,:),z7(j3,:));
  grid on;
  %legend('1','2','3');
  xlabel('r [cm]');
  ylabel('T i, eV');

subplot(2,2,4);

  plot(x(j1,:),z8(j1,:),x(j2,:),z8(j2,:),x(j3,:),z8(j3,:));
  grid on;
  xlabel('r [cm]');
  ylabel('T e, eV');




%disp('To continue - press Enter');

%pause

%  k_fig=k_fig+1
  k_fig=kkk;
  str2=[ 'prof' num2str(k_fig) ];
  
 % keyboard;
  
  saveas(gcf, str2, 'fig')

 saveas(gcf, str2, 'tif')

end % "while loop"
%st=fclose(fid);

%============ eof =================%
%print -depsc prof;

out=1

