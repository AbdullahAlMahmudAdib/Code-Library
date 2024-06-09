#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 1e5 + 10;
vector<int> adjList[MAX_NODES];
bool visited[MAX_NODES];
int level[MAX_NODES];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                level[neighbor] = level[node] + 1;
            }
        }
    }
}

void readGraphAndPerformBFS() {
    int numEdges;
    cin >> numEdges;

    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bfs(1);  // Assuming BFS starts from node 1
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    readGraphAndPerformBFS();

    return 0;
}
