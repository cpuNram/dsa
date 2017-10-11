#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
    private:
        vector<int> *adjList;
        vector<int> visited;
        int N; // num of nodes in graphs.
    public:
        Graph(int nodes) : N(nodes)
        {
            adjList = new vector<int> [nodes];
            visited.resize(nodes, 0);
        }
        ~Graph(void)
        {
            delete[] adjList; visited.clear();
        }
        void addNode(const int &u, const int &v)
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            
        }
        void dfs(const int &u)
        {
            if (visited[u]) return;
            visited[u] = 1;
            for (auto &v : adjList[u]) dfs(v);
        }
        int connComp(void)
        {
            int cc = 0;
            for (int i = 0; i < N; i++) {
                for (auto &u : adjList[i]) {
                    if (visited[u]) continue;
                    dfs(u); ++cc;
                }
            }
            // count each unvisited node.
            for (int i = 0; i < N; i++) {
                if (!visited[i]) ++cc;
            }
            return cc;
        }
};

int main(void)
{
    int n, m;
    cin >> n >> m; // n is num of nodes and m is num of edges.
    Graph g(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g.addNode(u, v);
    }
    cout << g.connComp() << "\n";
}
