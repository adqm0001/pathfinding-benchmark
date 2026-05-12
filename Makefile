all:
	g++ -std=c++17 -Wall -o pathfinder main.cpp grid.cpp astar.cpp

clean:
	rm -f pathfinder
