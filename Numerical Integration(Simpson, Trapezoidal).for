			PROGRAM NUMERICAL_INTEGRATION
	DIMENSION X(100)  , Y(100)
	PRINT*,"ENTER LOWER LIMIT OF INTEGRAL:"
	READ*,A
	PRINT*,"ENTER UPPER LIMIT OF INTEGRAL:"
	READ*,B
	PRINT*,"ENTER NUMBER OF SUB - INTERVALS"
2	READ*,N
      
	
	!Calculate Step Size
	H = (B-A)/N
	
	
	DO I = 1 , N
	X(I) = A + H*I
	Y(I) = F(X(I)) 
	ENDDO
	Y(0) = F(A)
	PRINT*,"Enter 1 For Trapezoidal Rule  2 for SIMPSON 1/3rd Rule 
     m	 3 for SIMPSON 3/8th Rule "
	READ*,M
	IF(M.EQ.1) THEN
	GOTO 1
	ELSEIF(M.EQ.2) THEN 
	GOTO 3
	ELSE IF (M.EQ.3) THEN 
	GOTO 100
	!Calculation of Integral
1	Z = 0.5*(Y(0) + Y(N))
	DO I = 1 ,N-1
	Z = Z +Y(I)
	ENDDO
	Z = Z*H
	PRINT*,"INTEGRAL USING TRAPEZOIDAL RULE IS:",Z
	GOTO 4
	
	
3	IF(MODULO(N ,2) .NE.0) THEN 
	PRINT*,"SIMPSON RULE NOT APPLICABLE"
	GOTO 2
	ELSE 
	W = (Y(0) + Y(N))
	DO I = 1 , N-1 ,2
	W = W+(4*Y(I))
	ENDDO
	DO I = 2 , N-2 ,2

	 W = W + (2*Y(I))
	ENDDO
	W = W*H/3.0
	ENDIF
	PRINT*,"INTEGRAL USING SIMPSON 1/3 RULE:" ,W
	GOTO 4

100	IF(MODULO(N ,3) . NE.0) THEN 
	PRINT*,"SIMPSON 3/8th RULE NOT APPLICABLE"
	GOTO 2
	ELSE
	W = (Y(0) + Y(N))
	
	DO I = 1 , N-2 ,3
	W = W + 3*(Y(I))
	ENDDO
	DO I = 2 , N-1 ,3
	 W = W + 3*(Y(I))
	ENDDO
	DO I = 3 , N-3 , 3
	  W = W + 2*(Y(I))
	ENDDO
       W = (3*H*W)/8
	ENDIF
	PRINT*,"INTEGRAL USING SIMPSON 3/8th Rule is:" ,W

	ENDIF
4	STOP
	END
	FUNCTION F(X)
	F = LOG(X)
	RETURN 
	END