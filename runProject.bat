g++ -c -std=c++11 prims.cpp -o prims.o
g++ -c -std=c++11 main.cpp -o main.o
g++ -c -std=c++11 kruskal.cpp -o kruskal.o
g++ -c -std=c++11 kruskalADTs.cpp -o kruskalADTs.o
g++ -c -std=c++11 graph.cpp -o graph.o

g++ -o main.exe main.o graph.o prims.o kruskalADTs.o kruskal.o -s

echo "------Compiled successfully------"
rm -r *.o
main.exe
