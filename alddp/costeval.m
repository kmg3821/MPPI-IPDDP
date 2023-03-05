function val = costeval(data,val,bp)

reg = bp.reg(bp.regidx);

muiq = val.muiq;
nuiq = val.nuiq;

x = val.x;
u = val.u;
w = val.w;

ubar = val.ubar;
wbar = val.wbar;

l = val.l;
h = val.h;

hbar = max(0,muiq*wbar + h) - muiq*w;

val.J = sum(l) + sum(hbar.^2,"all")*nuiq/(2*muiq) + ...
        sum((hbar + muiq*w).^2,"all")/(2*muiq) + ...
        sum((u - ubar).^2,"all")*reg/2 + ...
        data.lf(x(:,end));

val.hbar = hbar;


