  
    pow=0.5;
    a_0=0.35;
    n=10;
    
    for i=1:n
     x(i)=(i-1.)/(n-1.);
     a(i)=1.-abs(x(i)-a_0)^pow;
    end

    plot(x,a)

    
    