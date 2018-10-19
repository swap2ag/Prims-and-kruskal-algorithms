g++  main.cpp -o main.o
g++ graph.cpp -o graph.o
g++ prims.cpp -o prims.o
g++ kruskalADTs.cpp -o kruskalADTs.o
g++ kruskal.cpp -o kruskal.o
g++ -o main.out main.cpp graph.cpp prims.cpp kruskalADTs.cpp kruskal.cpp -s
