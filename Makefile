GPP = g++ -L$(PWD)

all: ex1 pet

ex1: ex1.cpp pet.h pet.cpp
	$(GPP) -lpet -o ex1 ex1.cpp

pet: pet.h pet.cpp
	$(GPP) -shared -o libpet.so pet.cpp 

stl: stl.cpp
	$(GPP) -o stl stl.cpp

udp: udp.cpp
	$(GPP) -o udpclient udpclient.cpp
	$(GPP) -o udpserver udpserver.cpp

hello: hello.asm
	nasm -f macho hello.asm
	ld -o hello -e mystart hello.o
