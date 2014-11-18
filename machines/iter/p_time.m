

t_start=-60.e3;
t_end=137.8e8;


clear m

fid=fopen('na_ramp');
j=0;
sz=zeros(80,1);
while 1
   line=fgetl(fid);
   n=size(line);
   %   disp(line);
   
   if ~isstr(line), break, end
   
   if j==0 
      ng=line;
   else
      sz(j,1)=n(2);
      name(j,n(1):n(2))=line(n(1):n(2));
   end
   j=j+1;
end
fclose(fid);

ng;

!cp for042 for042.dat

fid=fopen('for042.dat','r');
%fid=fopen('for042','r');
j=1;

m(1:99995,1:177)=0.;

while(1)
  	[ntemp,count]=fscanf(fid,'%d',1);
   eofstat=feof(fid);
   if(eofstat)
      break;
   end
   
  	nt=ntemp;
	[ntemp1,count]=fscanf(fid,'%d',1);
	ng=ntemp1;
   for i=1:ng+1
      [m(j,i),count]=fscanf(fid, '%g',1);
   end
   if(j==1)
      kmax=ng/4;
      ntime=ng+1;
  end
   j=j+1;   
  end
fid=fclose(fid);

save f42 m

%
time1=m(1:j-1,ntime);
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
ntime

time=m(i1:i2,ntime);
yy=m(i1:i2,ntime-1);

kmax=6

%keyboard;


for k=1:kmax
	figure(1);
   clf;
   k1=4*(k-1)+1;
   k2=k1+1;
   k3=k1+2;
   k4=k1+3;
   
   y1=m(i1:i2,k1);
	y2=m(i1:i2,k2);
	y3=m(i1:i2,k3);
   y4=m(i1:i2,k4);
%
XMIN=min(time);
XMAX=max(time);

YMIN=min(yy);
YMAX=max(yy);

%AXIS([XMIN XMAX YMIN YMAX]);
subplot(2,2,1);
	plot(time,y1,'r-');
	xlabel('time [ms]');
 	ylabel(name(k1,1:sz(k1,1)));
%
	hold on;
	subplot(2,2,2);
	h=plot(time,y2,'m');
	set(h,'MarkerSize',3);
	xlabel('time [ms]');
 	ylabel(name(k2,1:sz(k2,1)));
%
	hold on;
	subplot(2,2,3);
	plot(time,y3,'m');
	xlabel('time [ms]');
 	ylabel(name(k3,1:sz(k3,1)));
%
	hold on;
	subplot(2,2,4);
	plot(time,y4,'m');
	xlabel('time [ms]');
  	ylabel(name(k4,1:sz(k4,1)));
    
     k_fig=k;
  str2=[ 'time' num2str(k_fig) ]
  
 % keyboard;
  
  saveas(gcf, str2, 'fig')

 saveas(gcf, str2, 'tif')
    
end


t_eee=time(end);
t_eee

