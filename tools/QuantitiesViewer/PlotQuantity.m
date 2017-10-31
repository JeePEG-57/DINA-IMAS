function PlotQuantity(x,y,Namex,Unitsx,Namey,Unitsy,t1,t2)

if size(x) ~= size(y)
    disp('Size of x != size of y');
    return 
end

plot(x(t1:t2),y(t1:t2));
title(Namey);
if strcmp(Unitsx, '-') || isempty(Unitsx)
    xlabel(Namex);
else
    xlabel([Namex ', ' Unitsx]);
end
if strcmp(Unitsy, '-') || isempty(Unitsy)
    ylabel(Namey)
else
    ylabel([Namey ', ' Unitsy]);
end

end
