###############################################
Title		: SFCT Assignment 2
Made by		: Sah Swapnil Agrawal
Submitted to: Dr Sumeet Agarwal
###############################################

1.	Introduction
	------------
	* The code consists of 5 .cpp files and 4 header files. They are-
		1. main.cpp - Consists of code for entering the graph and applying algorithms to generate MST
		2. graph.cpp - consists of code for defining graph and its various functions.
		3. prims.cpp - implements prims algorithm.
		4. kruskalADTs.cpp - defines priority queue ADT and MFSET ADT and their respective functions.
		5. kruskal.cpp - implements kruskal algorithm.
		
	* The header files contain all class declarations.
	* There is one change that needs to make in code for graph having more than 2000 nodes. 
		In the file kruskalADTs.h, in the class mfset, change the size of arrays "setHeaders" and "elements" to number of nodes in graph.
2. Procedure to compile the code and run it
   ----------------------------------------
   * enter the following commands to compile using g++ -
   
		g++ -c graph.cpp -o graph.o
		g++ -c kruskal.cpp -o kruskal.o
		g++ -c kruskalADTs.cpp -o kruskalADTs.o
		g++ -c main.cpp -o main.o
		g++ -c prims.cpp -o prims.o
		
		g++ -o main.exe graph.o kruskal.o kruskalADTs.o main.o prims.o -s
		
		main.exe
				
3. Steps to take after running the code
   ------------------------------------
	* The program asks for number of nodes in the graph as input. 
	* Then it asks for the filename to read the graph from. (eg. input_graph.txt)
	* Then it prints the MST using Prim's algorithm and Kruskal's algorithm along with respective run times and costs.
	
	
	