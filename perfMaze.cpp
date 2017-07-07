/*
Perfect maze generator using Deep-First Search
Developers: Wesley Ferreira and Natiele Lucca
Computer Science Students - Unipampa - Campus Alegrete
Data Structures II - Graph

NOTE: Mazes of size 400 x 400 or greater cause stack overflow because a recursive call of function generate(), please attention!
TIP: define stack to unlimited to resolve this bug
*/

#include "vertex.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

void generate(vertex vertice, int **maze){
	int n = 0;
	vector<vertex*> adjacentes;
	vertice.visit();
	vertex *prox;
	adjacentes = vertice.getadj();
	while(adjacentes.size() > 0){
		n = rand()%adjacentes.size();
		if( !adjacentes[n]->isvisit() ){

			maze[vertice.getx()*2+1][vertice.gety()*2+1] = 0;
			maze[((adjacentes[n]->getx()*2+1) + (vertice.getx()*2+1))/2][((adjacentes[n]->gety()*2+1) + (vertice.gety()*2+1))/2] = 0;
			maze[adjacentes[n]->getx()*2+1][adjacentes[n]->gety()*2+1] = 0;

			adjacentes[n]->visit();
			generate(*adjacentes[n], maze);
		}
		swap(adjacentes[n], adjacentes.back());
		adjacentes.pop_back();
	}

}

int main(int argc, char **argv){


	if(argc < 4){
		cout << "How to use: " << argv[0] << " <width> <height> <imageName.pbm>" << endl;
		exit(1);
	}

	cout << "CONSOLE DEBUG:" << endl << endl;

    vector<vertex> vertices;
    int largura, altura;
    largura = atoi(argv[1]);
    altura = atoi(argv[2]);
    int **maze;
    vertex ***matriz;
    srand(time(NULL));

    maze = new int* [largura*2+1];
    if(maze == NULL){
    	cout << "Error: Not enough memory";
    	exit(1);
    }
    for(int i = 0;i<largura*2+1;i++){
    	maze[i] = new int[altura*2+1];
    	if(maze[i] == NULL){
    		cout << "Error: Not enough memory" << endl;
    		exit(1);
    	}
    }

    for(int i = 0; i<largura*2+1;i++){
   		for(int j = 0; j< altura*2+1;j++){
   			maze[i][j]= 1;
   		}
   	}
    matriz = new vertex** [largura];
    if(matriz == NULL){
    	cout << "Error: Not enough memory" << endl;
    	exit(1);
    }
   	for(int i =0;i< largura;i++){
   		matriz[i] = new vertex*[altura];
   		if(matriz[i] == NULL){
    		cout << "Error: Not enough memory" << endl;
    		exit(1);
    	}
   	}

   	for(int i = 0; i<largura;i++){
   		for(int j = 0; j< altura;j++){
   			matriz[i][j] = new vertex();
   			if(matriz[i][j] == NULL){
    			cout << "Error: Not enough memory" << endl;
    			exit(1);
    		}
   			matriz[i][j]->setcord(i,j);
   		}
   	}
   	cout << "Successful memory allocation" << endl;

   	for(int i = 0; i<largura;i++){
   		for(int j = 0; j< altura;j++){
   			if(i>0)			matriz[i][j]->addadj(matriz[i-1][j]);
   			if(j>0)			matriz[i][j]->addadj(matriz[i][j-1]);
   			if(j<altura-1)	matriz[i][j]->addadj(matriz[i][j+1]);
   			if(i<largura-1)	matriz[i][j]->addadj(matriz[i+1][j]);
   		}
   	}
   	cout << "Successful edges creation"  << endl;

	matriz[0][0]->visit();
   	generate(*matriz[0][0], maze);
   	cout << "Successful maze generation"  << endl;

   	ofstream output(argv[3], ofstream::out);
   	if (!output.is_open()){
   		cout << "Error: Problem on image opening" << endl;
   		exit(1);
	}
   	output << "P1"<< endl;
   	output << "#" << endl;
   	output << altura*2+1 << " " << largura*2+1 << endl;
   	for(int i = 0; i<largura*2+1;i++){
   		for(int j = 0; j< altura*2+1;j++){
   			output << maze[i][j] << " ";
   		}
   		output << endl;
   	}
   	output.close();
   	cout << "Successful image recording"  << endl;

	for(int i =0;i< largura*2+1;i++) delete maze[i];
   	delete maze;

   	for(int i=0;i< largura;i++)
   		for(int j = 0;j < altura;j++)
   			delete matriz[i][j];
   	for(int i =0;i< largura;i++) delete matriz[i];
   	delete matriz;
   	cout << "Successful memory cleanup" << endl;
   	cout << "Program END" << endl << endl;

}
