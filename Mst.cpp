#include <iostream>
using namespace std;

#define INF 99999

int main() {
    int n;
    int cost[10][10];
    int visited[10] = {0};
    int minCost = 0;

    cout << "Enter number of offices: ";
    cin >> n;

    cout << "Enter cost matrix (0 if no direct connection):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];

            if (i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;
    int edges = 0;

    cout << "Selected phone lines:\n";

    while (edges < n - 1) {
        int min = INF;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u == -1) {
            cout << "Cannot connect all offices.\n";
            return 0;
        }

        cout << u << " - " << v << " : " << min << "\n";
        minCost += min;
        visited[v] = 1;
        edges++;
    }

    cout << "Minimum total cost = " << minCost << "\n";

    return 0;
}
