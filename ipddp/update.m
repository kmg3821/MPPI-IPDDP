function [val,bp,fp] = update(val,bp,fp)

mu = val.mu;
opterr = norm([val.Qu; val.rp; val.rd],'inf');
if opterr < 100*mu

    s = val.s;
    J = val.J;

    mu = max(1e-8, min(0.2*mu, mu^1.2));
    logbarrier = sum(log(reshape(s,[],1)));
    logcost = J - mu*logbarrier;
    fp.filter(1) = logcost;

    bp.regidx = 1;
    bp.fail = false;
    fp.fail = false;
    val.mu = mu;
end
