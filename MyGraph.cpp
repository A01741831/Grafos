#include "MyGraph.h"
#include <vector>
#include <iostream>
#include <queue>


using namespace std;

MyGraph::MyGraph(vector<vector<int>>& matriz){ //O(v^2)
    loadGraph(matriz);
}

void MyGraph::loadGraph(vector<vector<int>>& matriz){ //O(v^2)
    this->matriz=matriz;
}

void MyGraph::DFS(){ //O(v+e)
    //Imprime el recorrido separado por comas y sin espacios
    vector<bool> visited(matriz.size(), false);
    auto dfsaux=[&](int nodo,auto& dfsref)->void{
        visited[nodo]=true;
        cout<<nodo<<",";
        for(int i=0; i<matriz.size(); i++){
            if(matriz[nodo][i]==1 && !visited[i]){
                dfsref(i,dfsref);
            }
        }
    };
    for(int i=0; i<matriz.size(); i++){
        if(!visited[i]){
            dfsaux(i,dfsaux);
        }
    }   
}

void MyGraph::BFS(){ //O(v+e)
    //Imprime el recorrido separado por comas y sin espacios
    vector<bool>visited(matriz.size(),false);
    for(int i=0;i<matriz.size();i++){
        if(!visited[i]){
            queue<int>q;
            visited[i]=true;
            q.push(i);
            while(!q.empty()){
                int nodo=q.front();
                q.pop();
                cout<<nodo<<",";
                for(int j=0;j<matriz.size();j++){
                    if(matriz[nodo][j]==1 && !visited[j]){
                        q.push(j);
                        visited[j]=true;
                    }
                }
            }
        }
    }
}

/*int main() {
    vector<vector<int>> matriz = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}
    };
    MyGraph grafo(matriz);
    cout<<"Recorrido DFS:"<<endl; 
    grafo.DFS();
    cout<<endl<<"Recorrido BFS:"<<endl;
    grafo.BFS();
    cout<<endl;
    return 0;
}*/