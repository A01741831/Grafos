#include "MyGraph.h"
#include <vector>

MyGraph::MyGraph(vector<vector<int>>& matriz){
    loadGraph(matriz);
}

void MyGraph::loadGraph(vector<vector<int>>& matriz){
    this->matriz=matriz;
}

void MyGraph::DFS(){
    //Imprime el recorrido separado por comas y sin espacios
}

void MyGraph::BFS(){
    //Imprime el recorrido separado por comas y sin espacios
}