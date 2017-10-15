#include <iostream>
#include <list>
#include <vector>
#include <stack>

using namespace std;

const int VISITED = 1;
const int VISITING = 2;
const int NOTVISITED = 3;

class DGraph {
    private:
        vector<int> *adjList;
        vector<int> visited;
        int N;
        list<int> tlist;
        bool dfs(int n);
    public:
        DGraph(int nodes) : N(nodes)
        {
            adjList = new vector<int> [nodes];
            visited.resize(nodes, NOTVISITED);
        }
        ~DGraph(void) { delete[] adjList; }
        void addNode(const int &u, const int &v) { adjList[u].push_back(v);}
        bool tsort(void);
};

bool DGraph::dfs(int n)
{
    if (visited[n] == VISITED) return 1;
    if (visited[n] == VISITING) return 0;
    visited[n] = VISITING;
    for (auto &m : adjList[n]) {
        if (dfs(m) == 0) return 0;
    }
    visited[n] = VISITED;
    tlist.push_back(n);
    return 1;
}

bool DGraph::tsort(void)
{
    for (int i = 0; i < N; i++) {
        for (auto &n : adjList[i])
            if (visited[n] == NOTVISITED)
                if (dfs(n) == 0) return 0;
     }
     return 1;
}

int main(void)
{
    int N, M;
    cin >> N >> M;
    DGraph dg(N);
    
    while (M--) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        dg.addNode(u, v);
    }
    cout << "tsort = " << dg.tsort() << "\n";
}
