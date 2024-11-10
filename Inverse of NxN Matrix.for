	
	!MATRIX INVERSE
	DIMENSION A(100,100) , B(100,100)
	PRINT*,"ENTER ORDER OF A MATRIX:"
	READ*,N
	PRINT*,"ENTER ENTRIES OF MATRIX ROW-WISE"
1	READ*,((A(I,J) , J = 1 , N) , I = 1 , N)
	DO I = 1 , N
	DO J = N+1 , 2*N
	IF(I.EQ.J-N) THEN
	A(I,J) = 1
	ELSE
	A(I,J) = 0
	ENDIF
	ENDDO
	ENDDO
	PRINT*,"THE AUGMENTED MATRIX  IS:"
	DO I = 1 ,N
	PRINT*,(A(I,J) , J = 1 , 2*N)
	ENDDO
	!CHECK FOR DETERMINANT
	DO I = 1 ,N
	IF(A(I,I).EQ.0) THEN
	A(I,:) = B(I,:)
	DO K = I+1, N
	IF(A(K,I).NE.0) THEN
	A(I,:) = A(K,:)
	A(K,:) = B(I,:)
	GOTO 10
	ENDIF
	ENDDO
	PRINT*,"ENTER VALID MATRIX"
	GOTO 1
	ENDIF

10	A(I,:) = A(I,:)/A(I,I)
	DO K = 1 ,N 
	IF(K.NE.I) THEN
	A(K,:) = A(K,:) - A(I,:)*A(K,I)
	ENDIF
	ENDDO
	ENDDO
	PRINT*,"THE INVERSE MATRIX IS"
	DO I = 1 ,N 
	PRINT*,(A(I,J) , J = N+1 ,2*N)
	ENDDO
	STOP
	END

