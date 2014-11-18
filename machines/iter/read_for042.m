function [ng,ntime,m]=read_for042(file_name)

fid=fopen(file_name,'r');
j=1;

while(1) 
  	[ntemp,count]=fscanf(fid,'%d',1);
    
    if(count==0)
        break;
    end
    
    [ng,count]=fscanf(fid,'%d',1);
   
    for i=1:ng+1
        [m(j,i),count]=fscanf(fid, '%g',1);
    end
    
    if(j==1)
        ntime=ng+1;
    end
      j=j+1;   
   end

fid=fclose(fid);
