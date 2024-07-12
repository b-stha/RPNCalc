
polish: Stack.o Nodes.o AST.o test.o
	g++ Stack.o Nodes.o AST.o test.o -o polish

test.o:
	g++ -c test.cpp

Stack.o: Stack.cpp Stack.h
	g++ -c Stack.cpp

Nodes.o: Nodes.cpp Nodes.h
	g++ -c Nodes.cpp

AST.o: AST.cpp AST.h
	g++ -c AST.cpp

clean:
	rm -f *.o polish