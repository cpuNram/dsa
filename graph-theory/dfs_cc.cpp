#include <iostream>
#include <vector>

using namespace std;

class Graph {
    private:
        vector<int> *adjList;
        vector<bool> visited;        
        int N; // num of nodes in graph.
    public:
        Graph(int nodes) : N(nodes)
        {
            adjList = new vector<int> [nodes];
            visited.resize(nodes, 0);
        }
        ~Graph(void)
        {
            delete[] adjList;
            visited.clear();
        }
        void addNode(int u, int v)
        {
            adjList[u].push_back(v);
            if (u != v) adjList[v].push_back(u);
        }
        void dfs(int startNode)
        {
            if (visited[startNode]) return;
            visited[startNode] = 1;
            for (auto &u : adjList[startNode]) dfs(u);
        }
        int connectedComp(void)
        {
            int cc = 0;
            for (int i = 0; i < N; i++) {
                for (auto &u : adjList[i]) {
                    if (!visited[u]) {
                        dfs(u);
                        ++cc;
                    }
                }
            }
            return cc;
        }
};

int main(void)
{
    Graph g(10);
    g.addNode(1, 2);
    g.addNode(1, 3);
    g.addNode(4, 5);
    g.addNode(6, 7);
    g.addNode(8, 9);
    cout << "cc = " << g.connectedComp() << "\n";
}
