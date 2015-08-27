
fid=fopen('tt_kavin.dat','w');                     
fprintf(fid,'%s\n','t_tran2D   tt_dw');
fprintf(fid,' %g  ',t_tran2D*1.e3);
fprintf(fid,' %g  \n',tt_dw);
fid=fclose(fid); 

