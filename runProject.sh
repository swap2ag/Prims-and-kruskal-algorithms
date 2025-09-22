g++ -c prims.cpp -o prims.o
g++ -c main.cpp -o main.o
g++ -c kruskal.cpp -o kruskal.o
g++ -c kruskalADTs.cpp -o kruskalADTs.o
g++ -c graph.cpp -o graph.o
g++ -o main.out main.o graph.o prims.o kruskalADTs.o kruskal.o -s
echo "------Compiled successfully------"
./main.out
