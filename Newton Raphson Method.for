		!NEWTON RAPHSON CODE
1	PRINT*,"ENTER THE INITIAL POINT"
	READ*,A
	IF(DF(A).EQ.0.OR.ABS(F(A)*D2F(A)).GE.DF(A)**2) THEN
	print*,"choosen point is wrong:"
	GOTO 1
	ELSE
	GOTO 2
	ENDIF
	ITER = 0

2			B = A - (F(A)/DF(A))


		ITER = ITER +1
		PRINT*,"THE ROOT AFTER " , ITER , "ITERATION IS" ,B
		IF(ABS(B-A) .LT.10E-4) THEN 
		PRINT*,"THE ROOT AFTER", ITER , "ITERATION IS : " ,A
		
		ELSE 
		
		  A = B
		GOTO 2
		
		ENDIF
		
	
		


		
		STOP 
		END

	  
	   FUNCTION F(X)
	     F = X**2 - X -2
		 RETURN
		END
		FUNCTION DF(X)
		DF =2*X - 1
		RETURN 
		END
		FUNCTION D2F(X)
		D2F = 2
		RETURN 
		END
