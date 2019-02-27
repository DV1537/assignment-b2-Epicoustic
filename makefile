TestRule: main.cpp
	g++ -g main.cpp vector2.cpp shape.cpp figure.cpp point.cpp line.cpp triangle.cpp polygon.cpp -o main.exe -static-libgcc -static-libstdc++