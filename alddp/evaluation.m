function val = evaluation(data,val)

for i=1:data.N-1

    x = val.x(:,i);
    u = val.u(:,i);
    xref = data.xref(:,i);
    cref = data.cref(:,i);
    rref = data.rref(:,i);

    val.lx(:,i) = data.lx(x,u,xref)';
    val.lu(:,i) = data.lu(x,u,xref)';
    val.lxx(:,:,i) = data.lxx(x,u,xref);
    val.lux(:,:,i) = data.lux(x,u,xref);
    val.luu(:,:,i) = data.luu(x,u,xref);

    fX = data.fX(x,u);
    val.fx(:,:,i) = fX(:,data.xidx);
    val.fu(:,:,i) = fX(:,data.uidx);

    hX = data.hX(x,u,cref,rref);
    val.hx(:,:,i) = hX(:,data.xidx);
    val.hu(:,:,i) = hX(:,data.uidx);
end



