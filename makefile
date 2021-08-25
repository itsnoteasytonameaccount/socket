
.PHONY: clean all

all: server.exe client.exe

server.exe: libcommu.dll server.cpp
	g++ -O3 server.cpp -L. -lcommu -o $@

client.exe: libcommu.dll client.cpp
	g++ -O3 client.cpp -L. -lcommu -o $@

libcommu.dll: communication/communication.cpp
	g++ -fPIC -shared -O3 communication/communication.cpp -LD:/environment/mingw64/x86_64-w64-mingw32/lib -lws2_32 -o $@

clean:
	call del libcommu.dll server.exe client.exe