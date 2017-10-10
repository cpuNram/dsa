#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    vector<int> *adjList;
    vector<bool> visited;
    int numOfNodes;

public:
    Graph(int nodes) : numOfNodes(nodes)
    {
        adjList = new vector<int> [nodes];
        visited.resize(nodes, 0);
    }
    ~Graph(void) { delete[] adjList; }
    void dfs(int start);
    int connectedComp(void);
    void addNode(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
};

void Graph::dfs(int start)
{
    stack<int> stk;
    stk.push(start);
    visited[v] = 1;
    while (!stk.empty()) {
        int u = stk.top();
        stk.pop();
        for (auto &v : adjList[u]) {
            if (visited[v]) continue;
            visited[v] = 1;
            stk.push(v);
        }
    }
}

int Graph::connectedComp(void)
{
    int cc = 0;
    for (int i = 0; i < numOfNodes; i++) {
        for (auto &u :  adjList[i]) {
            if (!visited[u]) {
                dfs(u);
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
    g.addNode(1, 3);
    g.addNode(1, 4);
    g.addNode(2, 5);
    g.addNode(7, 8);
    g.addNode(9, 6);
    cout << "cc = " << g.connectedComp() << "\n";
    return 0;
}
