#include <iostream>
using namespace std;

int adj[20][20], vis[20], q[20], n;

void BFS(int start) {
    int front = 0, rear = 0;
    for (int i = 0; i < n; i++) vis[i] = 0;

    q[rear++] = start;
    vis[start] = 1;

    while (front < rear) {
        int v = q[front++];
        cout << v << " ";

        for (int i = 0; i < n; i++) {
            if (adj[v][i] && !vis[i]) {
                q[rear++] = i;
                vis[i] = 1;
            }
        }
    }
}

void DFS(int v) {
    vis[v] = 1;
    cout << v << " ";

    for (int i = 0; i < n; i++)
        if (adj[v][i] && !vis[i])
            DFS(i);
}

int main() {
    int e, u, v, start;
    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }

    cin >> start;
    cout << "BFS: ";
    BFS(start);

    for (int i = 0; i < n; i++) vis[i] = 0;

    cout << "\nDFS: ";
    DFS(start);

    return 0;
}