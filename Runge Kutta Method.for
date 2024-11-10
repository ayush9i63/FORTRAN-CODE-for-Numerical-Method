	!RUNGA KUTTA METHOD
	DIMENSION X(100),Y(100)
	REAL K1,K2,K3,K4,L1,L2,L3,L4
	PRINT*,'ENTER THE INITIAL CONDITION'
	READ*,X0,Y0
	PRINT*,'ENTER THE STEP SIZE'
	READ*,H
	PRINT*,'ENTER THE POINT WHERE YOU WANT VALUE'
	READ*,A

	N=(A-X0)/H
	ITER=0
	K1=H*F(X0,Y0)
	K2=H*F(X0+H/2,Y0+K1/2)
	K3=H*F(X0+H/2,Y0+K2/2)
	K4=H*F(X0+H,Y0+K3)

	Y(1)=Y0+(K1+2*K2+2*K3+K4)/6
	X(1)=X0+H
	PRINT*,"SOLUTION IS:",Y(1)
	
	DO I=1,N
	L1=H*F(X(I),Y(I))
	L2=H*F(X(I)+H/2,Y(I)+L1/2)
	L3=H*F(X(I)+H/2,Y(I)+L2/2)
	L4=H*F(X(I)+H,Y(I)+L3)

	Y(I+1)=Y(I)+(L1+2*L2+2*L3+L4)/6
	X(I+1)=X(I)+H
	ITER=ITER+1
	PRINT*,'ITER NUMBER',ITER,'THE VALUE AT X(',A,")=",Y(I)
	END DO
	STOP
	END

	FUNCTION F(X,Y)
	F=Y - X**2+1
	RETURN
	END