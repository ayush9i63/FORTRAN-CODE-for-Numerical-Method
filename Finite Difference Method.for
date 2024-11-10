		 PROGRAM finite_difference
	      DIMENSION X(100) , Y(100 , 100)
	        PRINT*,"enter no. of data points:"
	         READ*,N
	          DO I =   1 ,N
	           PRINT*,"X(",I,")="
	READ*,X(I)
	PRINT*,"Y(",I,")="
	 READ*,Y(I,1)
	ENDDO

	
	DO I = 2, N
	 DO J = 1 , N-I+1
	Y(J,I) = Y(J+1 , I-1) - Y(J,I-1)
	PRINT*,'THE',I-1,'TH ORDER DIFF AT',J,'TH LEVEL IS',Y(J,I)
	ENDDO
	ENDDO
	
	

	STOP
 	END
