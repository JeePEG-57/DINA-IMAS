
fid=fopen('tt_kavin.dat','w');                     
fprintf(fid,'%s\n','t_tran2D   tt_dw');
fprintf(fid,' %g  ',t_tran2D*1.e3);
fprintf(fid,' %g  \n',tt_dw);
fid=fclose(fid); 

dtpl_term_h=0.e-3;

Ics1_eob1=Ics1_eob/ntur(3)*1.e3;
%Ics1_eob1=Ics1_eob;

fid=fopen('tt_kavin2.dat','w');                     
fprintf(fid,'%s\n','tt_rampup');
fprintf(fid,' %g  \n ',t_eob2*1.e3);
fprintf(fid,'%s\n','dtpl_term_h     dtpl_term_l   cIp_end');
fprintf(fid,' %g  ',dtpl_term_h);
fprintf(fid,' %g  ',dtpl_term_l);
fprintf(fid,' %g \n ',cIp_end);
fprintf(fid,'%s\n','Ics1_eob        dt_contr_hl');
fprintf(fid,' %g  ',Ics1_eob1);
fprintf(fid,' %g \n ',dt_contr_hl);


fid=fclose(fid); 


%tt_rampup
%25.e3
%dtpl_term_h     dtpl_term_l   cIp_end
% 0.             28.           1.5
%Ics1_eob        dt_contr_hl 
%  -30.          25.         

