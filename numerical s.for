      DIMENSION Y(100)
		PRINT*,"ENTER INITIAL POINT i.e., (Xo ,Yo)"
		READ*,U,V
		PRINT*,"Enter Step Size (h)"
		READ*,H
		PRINT*,"ENTER THE REQUIRED POINT :"
		READ*,G
		L = G/H
		  		  DO I = 1, L
				Y(I) = V + H*F(U,V)
		
			 R = Y(I)
	PRINT*,R
	ITER = 0
2	P = V+(H/2)*(F(U,V) + F(U+H,R) )
		ITER = ITER+1
		PRINT*,"THE VALUE OF FUNCTION AFTER",ITER,"ITERATION IS:",P
		IF(ABS(P-R) .LE.10E-4) THEN
		PRINT*,"THE VALUE OF Y(",I*H,")", P
		GOTO 3
		ELSE
		R = P
	 U = U+H
	V= P0
		GOTO 2
		ENDIF
		
		  ENDDO
3		STOP
		END
		FUNCTION F(X,Y)
		F = (X-Y)/2
		RETURN
		END
