#ifndef MYGRAPH_H
#define MYGRAPH_H
#include <vector>

using namespace std;

class MyGraph
{
    private:
        vector<vector<int>>matriz;
        //void DFS(int nodo, vector<bool>& visited);
        //void BFS(int nodo, vector<bool>& visited);
    public:
        MyGraph(vector<vector<int>>& matriz);
        void loadGraph(vector<vector<int>>& matriz);
        void DFS();
        void BFS();
};
#endif