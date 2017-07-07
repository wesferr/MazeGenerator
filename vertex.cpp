/* 
Perfect maze generator using Deep-First Search
Developers: Wesley Ferreira and Natiele Lucca
Computer Science Students - Unipampa - Campus Alegrete
Data Structures II - Graph
*/

#include "vertex.hpp"
#include <vector>

using namespace std;

vertex::vertex(){
    visited = false;
}
void vertex::setval(int v){
    value = v;
}

void vertex::setcord(int a, int b){
    x = a;
    y = b;
}
int vertex::getx(){
    return x;
}
int vertex::gety(){
    return y;
}
void vertex::visit(){
    visited = true;
}
void vertex::unvisit(){
    visited = false;
}
void vertex::addadj(vertex* adjacente){
    adj.push_back(adjacente);
}
vector<vertex*> vertex::getadj(){
    return adj;
}
int vertex::getval(){
    return value;
}
int vertex::isvisit(){
    if(visited == 1) return 1;
    return 0;
}
