%function read_psi_from_dina_imas
close all
%!del psi_data_cop 


n_start = 1;
n_fig = 1;
i_halo = 0;


k_fig=0;
k_fig1=0;

nr = 65;
nz = 129;

% fid=fopen('parf2','r');
%  
% for k=1:100
%    [c,count]=fscanf(fid,'%c',1);
%    if(c=='=')
%       [nr,count]=fscanf(fid,'%d',1);
%       break;
%    end
% end
% for k=1:100
%    [c,count]=fscanf(fid,'%c',1);
%    if(c=='=')
%       [nz,count]=fscanf(fid,'%d',1);
%       break;
%    end
% end
%------------------------------------------------!
%checking and copying psi_data file

fid=fclose(fid);

ntay=0;

i_fil=0
if(i_fil==1)
fid=fopen('fil_out.dat');
[n_fil,count]=fscanf(fid,'%d',1);
[r_fil,count]=fscanf(fid,'%g',[n_fil]);
[z_fil,count]=fscanf(fid,'%g',[n_fil]);
fid=fclose(fid);
end

%-------------------------------------------------!
%reading psi_data_cop file 

while 1
   if(ntay==0)
%      fid=fopen('psi_data_cop');
       fid=fopen('psi_data_imas');
     
      if(i_halo==1)
      fid1=fopen('test_points.dat','r');   
      end
      
         
   end
  
 % disp(fid)
  
   [ke,count]=fscanf(fid,'%d',1);
   
      if(count==0)
      break;
   end

   [ncam,count]=fscanf(fid,'%d',1);
   [npf,count]=fscanf(fid,'%d',1);
   [jbound,count]=fscanf(fid,'%d',1);
   [iprof,count]=fscanf(fid,'%d',1);
   
ncam;
iprof;


        [rc,count]=fscanf(fid,'%g',[ncam]);
        
        ncam;
        
        [zc,count]=fscanf(fid,'%g',[ncam]);
  
        [xu,count]=fscanf(fid,'%g',[ke]);
	[yu,count]=fscanf(fid,'%g',[ke]);

	[dx,count]=fscanf(fid,'%g',1);
	[dy,count]=fscanf(fid,'%g',1);
	[pmag,count]=fscanf(fid,'%g',1);
	[pbound,count]=fscanf(fid,'%g',1);
	[p_s,count]=fscanf(fid,'%g',1);
	[um,count]=fscanf(fid,'%g',1);
	[vm,count]=fscanf(fid,'%g',1);
	[ttt,count]=fscanf(fid,'%g',1);
%
	for j=1:nz
   	for i=1:nr
   	   [psi(j,i),count]=fscanf(fid,'%g',1);
		end
	end
%
	[x,count]=fscanf(fid,'%g',[nr]);
	[y,count]=fscanf(fid,'%g',[nz]);
   
    [xbound,count]=fscanf(fid,'%g',[jbound]);
	[ybound,count]=fscanf(fid,'%g',[jbound]);

	[xcur,count]=fscanf(fid,'%g',[iprof]);
	[torcur,count]=fscanf(fid,'%g',[iprof]);


       
    if(i_halo==1)
    [nhalo,count]=fscanf(fid1,'%d',1);
    clear xx
    clear yy
    for j=1:nhalo
    [cc,count]=fscanf(fid1,'%g',2);
    if(count > 0)
    xx(j)=cc(1);
    yy(j)=cc(2);
    end
    end

    nhalo
    
   end

   eofstat=feof(fid);
   
   if(eofstat)
      break;
   end


   ntay=ntay+1;
    
   psi_f(:,:,ntay) = psi;
   
% if ntay == n_start+n_fig*k_fig
%    
%    % plotting graphics
% 	figure(k_fig1+1);
% 	%-------plotting parameters -------%
% 	lw=1; %LineWidth
% 	fs=9; %FontSize
% 
% 	s_time=num2str(ttt);
% 	clf;
%   
% 	hold on;
% 	plot(rc,zc,'r.'); %vessel & passive
%    
%   plot(xu,yu,'k'); % limiter
%   
%   
% %  keyboard;
%   
%   
%   if(i_fil==1)
% plot(r_fil,z_fil,'.y'); % filaments
% end
% if ttt<4 
%     plot(xbound,ybound,'.r'); % filaments
% % legend('pl bound');
% end
% 
% %*********************
% %  for ki=1:10
% %		Halo(ki)=p_s+(pbound-p_s)/10*(ki-1);
% %	end;
% %  [C,h]=contour(x,y,psi,Halo,'-b'); % flux
%   
% 
% psep=pbound;
% pbound=psep+5.e-3*(pmag-psep);
% 
% p_s=psep-1.e-2*(pmag-psep);
% 
% %p_s
% p_s
% pbound
% pmag
% 
% 		sep(1)=p_s;
% 		sep(2)=psep;
% 		sep(3)=pbound;
%   [C,h]=contour(x,y,psi,sep,'-b'); % flux
%   
% n_con=10;
%   if(i_halo==1)
%   plot(xx,yy,'g.');
%   end
% 
% 	for kii=1:n_con
% %		PL(kii)=pbound+(pmag-pbound)/n_con*(kii-1);
% 		PL(kii)=pmag-(kii-1.)*(pmag-p_s)/(n_con-1);
% 	end;
%   [C,h]=contour(x,y,psi,PL,'-r');  %flux
%   
%   clear PL;
%     n_con1=15
% 	for kii=1:n_con1
% %		PL(kii)=pbound+(pmag-pbound)/n_con*(kii-1);
% 		PL(kii)=p_s-kii*(pmag-p_s)/n_con1;
% 	end;
%    [C,h]=contour(x,y,psi,PL,'-b');  %flux
% 
%   clear PL;
%   
%     n_con2=30
%   	for kii=1:n_con2
% %		PL(kii)=pbound+(pmag-pbound)/n_con*(kii-1);
% 		PL(kii)=pmag+0.1*kii*(pmag-p_s)/n_con;
% 	end;
% %   [C,h]=contour(x,y,psi,PL,'-k');  %flux
% 
%   
% %   if(i_halo==1)
% %   plot(xx,yy,'y.');
% %   end
% 
%  hold on;
% % pf_coor_read('koor_jt',11)
% %[r_ps,z_ps]=for040_read;
% %for040_read;
% %pf_coor_read
% %keyboard
% % plot(r_ps,z_ps,'*')
% % if ntay == 1
% %     load environ_t15md_angle
% % end
% % coils_rus_plot(device)
% % plot(100*device.vessel.rc,100*device.vessel.zc,'.b');
% %   %plot(xbound,ybound,'r');
%   
% 
% %filament_drawing_new()
% 
% %***************************************
% 	title('ITER equilibrium','FontSize',12);
% 	xlabel('r [cm]','FontSize',fs);
%   ylabel('z [cm]','FontSize',fs);
%   rmx=max(rc);
%   rmn=min(rc);
%   rtext=rmn+0.10*(rmx-rmn);
%   zmn=min(zc);
%   ztext=1.25*zmn;
% 
%   rtext=200;
%   ztext=-270;
%   text('Position',[rtext ztext],'String',['time=',s_time,'ms'],'FontSize',fs);
% 
% 	set(gca,'XGrid','on','YGrid','on','LineWidth',lw,'FontSize',fs);%,'PlotBoxAspectRatio',[1 1.7 1]);
%   daspect([1 1 1]);
%   xlim([100 1350]);
%   ylim([-600 600]);
%   
%   % to store as tif - file
%   k_fig=k_fig+1;
%   k_fig1=k_fig1+1;
%   
%   
%   ss=['equil_',num2str(k_fig)];
%   print(k_fig1, '-dtiff', ss)
%   
%    saveas(gcf, ss, 'fig')
% 
%   if(k_fig1 > 6)
%       k_fig1=0;
%   end
%   
%   
% end
end
fid=fclose(fid);

 if(i_halo==1)
fid1=fclose(fid1);
 end
    
  
 assignin('base','psi_dina_imas_k',psi_f);
 
%hold on;
%pf_coor_read
%for040_read
%ntay
