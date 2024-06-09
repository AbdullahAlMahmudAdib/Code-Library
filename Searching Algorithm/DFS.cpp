#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 1e5 + 10;
vector<int> adjList[MAX_NODES];
bool visited[MAX_NODES];

void dfs(int node) {
    cout << node << '\n';
    visited[node] = true;

    for (int neighbor : adjList[node]) {
        cout << "Parent: " << node << " Children: " << neighbor << '\n';
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    dfs(1);  // Assuming DFS starts from node 1

    return 0;
}
