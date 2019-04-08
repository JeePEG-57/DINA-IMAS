%% Select pulse and run to compare

pulse = [170 170];
run = [6 8];

%% Select coils to compare
coils = [1 5 11];

%%
col = cell(1,2);
col{1} = 'b';
col{2} = 'r';
lnt = cell(1,2);
lnt{1} = '-';
lnt{2} = '--';

addpath ../../tools
%%
pfa = cell(1,length(run));
for ip=1:length(pfa)
    pfa{ip} = LoadIDS(pulse(ip),run(ip),'pf_active');
end

%%
pfp = cell(1,length(run));
for ip=1:length(pfp)
    pfp{ip} = LoadIDS(pulse(ip),run(ip),'pf_passive');
end

%% Compare active currents

ncoil = length(pfa{1}.coil);
for ic=coils
    figure(ic);
    clf;
    
    npfa = length(pfa);
    for ip=1:npfa
    
        plot(pfa{ip}.time, pfa{ip}.coil{ic}.current.data, [lnt{ip} col{ip}]);
        hold on;
    end
end


%% Compare active voltages

ncoil = length(pfa{ip}.coil);
for ic=coils
    figure(ncoil+ic);
    clf;
    
    npfa = length(pfa);
    for ip=1:npfa
    
        plot(pfa{ip}.time, pfa{ip}.coil{ic}.voltage.data, [lnt{ip} col{ip}]);
        hold on;
    end
end

%% Compare passive currents

figure(3);
clf;

npfp = length(pfp);
for ip=1:npfp

    nloop = length(pfp{ip}.loop);
    for il=1:nloop   
        plot(pfp{ip}.time, pfp{ip}.loop{il}.current, [lnt{ip} col{ip}]);
        hold on;
    end

end
