make:
	g++ -Wall -Wpedantic -std=c++20 -o main main.cpp heatflow.cpp

test:
	g++ -Wall -Wpedantic -std=c++20 -o main main.cpp heatflow.cpp && ./main
