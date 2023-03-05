function val = evaluation(data,val)

uprev = val.uprev;

for i=1:data.N-1

    x = val.x(:,i);
    u = val.u(:,i);
    xref = data.xref(:,i);
    cref = data.cref(:,i);
    rref = data.rref(:,i);

    if i == 1
        val.lx(:,i) = data.lx(x,u,xref)';
        val.lu(:,i) = data.lu(x,u,xref)' + data.l1u(u,uprev)';
        val.lxx(:,:,i) = data.lxx(x,u,xref);
        val.lux(:,:,i) = data.lux(x,u,xref);
        val.luu(:,:,i) = data.luu(x,u,xref) + data.l1uu(u,uprev)';
    else
        val.lx(:,i) = data.lx(x,u,xref)';
        val.lu(:,i) = data.lu(x,u,xref)';
        val.lxx(:,:,i) = data.lxx(x,u,xref);
        val.lux(:,:,i) = data.lux(x,u,xref);
        val.luu(:,:,i) = data.luu(x,u,xref);
    end

    fX = data.fX(x,u);
    val.fx(:,:,i) = fX(:,data.xidx);
    val.fu(:,:,i) = fX(:,data.uidx);

    cX = data.cX(x,u,cref,rref);
    val.cx(:,:,i) = cX(:,data.xidx);
    val.cu(:,:,i) = cX(:,data.uidx);
end



