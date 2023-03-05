function [val,fp] = costeval(data,val,fp)

for i=1:data.N-1
    if i == 1
        val.l(:,i) = data.l(val.x(:,i),val.u(:,i),data.xref(:,i)) + ...
            data.l1(val.u(:,i),val.uprev);
    else
        val.l(:,i) = data.l(val.x(:,i),val.u(:,i),data.xref(:,i));
    end
    val.c(:,i) = data.c(val.x(:,i),val.u(:,i),data.cref(:,i),data.rref(:,i));
end
J = sum(val.l) + data.lf(val.x(:,data.N));

logbarrier = sum(log(reshape(val.s,[],1)));
logcost = J - val.mu*logbarrier;
rperr = norm(reshape(val.c + val.s,[],1),1);
fp.filter = [logcost; rperr];
val.J = J;


