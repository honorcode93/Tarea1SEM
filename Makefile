DIR=/usr/local
LIBS= \
   -lgecodeflatzinc  -lgecodedriver \
   -lgecodegist      -lgecodesearch \
   -lgecodeminimodel -lgecodeset    \
   -lgecodefloat     -lgecodeint    \
   -lgecodekernel    -lgecodesupport \

nqueens: queens.cpp
	g++ -Wall -I$(DIR)/include -c queens.cpp
	g++ -Wall -L$(DIR)/lib -o queens queens.o $(LIBS)

smm: send-more-money.cpp
	g++ -Wall -I$(DIR)/include -c send-more-money.cpp
	g++ -Wall -L$(DIR)/lib -o send-more-money send-more-money.o $(LIBS)

