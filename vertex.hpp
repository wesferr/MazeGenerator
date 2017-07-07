/* 
Perfect maze generator using Deep-First Search
Developers: Wesley Ferreira and Natiele Lucca
Computer Science Students - Unipampa - Campus Alegrete
Data Structures II - Graph
*/

#ifndef VERTEX_H
#define VERTEX_H
#include <vector>

using namespace std;

class vertex{
    private:
        int value;
        int x;
        int y;
        bool visited;
        vector<vertex*> adj;

    public:
        vertex();
        void setval(int v);
        void setcord(int x, int y);
        int getx();
        int gety();
        void visit();
        void unvisit();
        void addadj(vertex* adjacente);
        int isvisit();
        int getval();
        vector<vertex*> getadj();
    
};

#endif
