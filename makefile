app : app.cpp liblistener.a
	gcc -o app app.cpp liblistener.a -lstdc++

liblistener.a : liblistener.o
	ar cr liblistener.a liblistener.o

liblistener.o : liblistener.cpp
	gcc -c liblistener.cpp	-lstdc++
