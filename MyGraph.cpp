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

bool MyGraph::isTree(){ //O(v+e)
    vector<bool>visited(matriz.size(),false);
    vector<int>parent(matriz.size(),-1);
    queue<int>q;
    q.push(0);
    visited[0]=true;
    while(!q.empty()){
        int nodo=q.front();
        q.pop();
        for(int i=0;i<matriz.size();i++){
            if(matriz[nodo][i]==1){
                if(!visited[i]){
                    visited[i]=true;
                    parent[i]=nodo;
                    q.push(i);
                } else if(parent[nodo]!=i){
                    return false;
                }
            }
        }
    }
    for(int i=0;i<matriz.size();i++){
        if(!visited[i]){
            return false;
        }
    }
    return true;
}

void MyGraph::topologicalSort(){ //O(v+e)
    vector<int>inDegree(matriz.size(),0);
    for(int i=0;i<matriz.size();i++){
        for(int j=0;j<matriz.size();j++){
            if(matriz[i][j]==1){
                inDegree[j]++;
            }
        }
    }
    queue<int>q;
    for(int i=0;i<matriz.size();i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int nodo=q.front();
        q.pop();
        cout<<nodo<<",";
        for(int i=0;i<matriz.size();i++){
            if(matriz[nodo][i]==1){
                inDegree[i]--;
                if(inDegree[i]==0){
                    q.push(i);
                }
            }
        }
    }
    cout<<endl;
}

bool MyGraph::bipartiteGraph(){ //O(v+e)
    vector<int>color(matriz.size(),-1);
    queue<int>q;
    q.push(0);
    color[0]=0;
    while(!q.empty()){
        int nodo=q.front();
        q.pop();
        for(int i=0;i<matriz.size();i++){
            if(matriz[nodo][i]==1){
                if(color[i]==-1){
                    color[i]=1-color[nodo];
                    q.push(i);
                } else if(color[i]==color[nodo]){
                    return false;
                }
            }
        }
    }
    return true;
}


/*void MyGraph::DFS(){ //O(v+e)
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
}*/

/*void MyGraph::BFS(){ //O(v+e)
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
}*/

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

/*int main() {
    vector<vector<int>> matriz = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    MyGraph grafo(matriz);
    cout<<"¿Es un árbol? "<<(grafo.isTree()?"Sí":"No")<<endl;
    cout<<"Orden topológico: ";
    grafo.topologicalSort();
    cout<<"¿Es bipartito? "<<(grafo.bipartiteGraph()?"Sí":"No")<<endl;
    return 0;
}*/