#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> adjList;
vector<bool> visited;

void
addEdge(int u, int v)
{
    adjList[u].push_back(v);
}

bool
isReachable(int u, int v)
{
    stack<int> stk;
    stk.push(u);
    while (!stk.empty()) {
        int node = stk.top();
        stk.pop();
        for (int w: adjList[node]) {
            if (v == w) return true;
            if (visited[w]) continue;
            visited[w] = 1;
            stk.push(w);
        }
    }
    return false;
}

int
main(void)
{
    int N = 4;
    visited.resize(4, 0);
    adjList.resize(4);
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);
    if (isReachable(1, 3)) {
        cout << "YES\n"; 
    } else cout << "NO\n";
    if (isReachable(3, 1)) {
        cout << "YES\n"; 
    } else cout << "NO\n";
}
