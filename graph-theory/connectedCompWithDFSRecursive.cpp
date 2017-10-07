#include <iostream>
#include <vector>

using namespace std;

class Graph {
    private:
        int numOfNodes;
        vector<int> *adjList;
        vector<bool> visited;        
    public:
        Graph(int nodes) : numOfNodes(nodes)
        {
            adjList = new vector<int> [nodes];
            visited.resize(nodes, 0);
        }
        ~Graph(void) { delete[] adjList;}
        void addNode(int u, int v)
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        void dfsRecursive(int startNode);
        int connectedComp(void);
};

void Graph::dfsRecursive(int startNode)
{
    if (visited[startNode]) return;
    visited[startNode] = 1;
    for (auto &u : adjList[startNode]) dfsRecursive(u);
}

int Graph::connectedComp(void)
{
    int cc = 0;
    for (int i = 0; i < numOfNodes; i++) {
        for (auto &u : adjList[i]) {
            if (!visited[u]) {
                dfsRecursive(u);
                ++cc;
            }
        }
    }
    return cc;
}

int
main(void)
{
    Graph g(10);
    g.addNode(1, 2);
    g.addNode(1, 3);
    g.addNode(4, 5);
    g.addNode(6, 7);
    g.addNode(8, 9);
    cout << "cc = " << g.connectedComp() << "\n";
}
