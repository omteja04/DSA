/**
 * Author: omteja04
 * Created on: 13-10-2024 10:15:12
 * Description: GraphRepresentation
 **/

#include <bits/stdc++.h>
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << (#x) << " = " << (x) << '\n'
using namespace std;

// Storing
// Matirx -> Adjacency Matrix
// List -> Adjacency List

int main() {
    int n, m;
    cin >> n >> m;
    // n -> nodes
    // m edges
    int graph1[n + 1][m + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph1[u][v] = 1;
        graph1[v][u] = 1;
    }
    // TC ->  O(n)
    // SC -> O(n^2)

    //  second way
    vector<int> graph2[n + 1];
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph2[u].push_back(v);
        graph2[v].push_back(u);
    }
    // TC ->  O(n)
    // SC -> O(2n)
    /* ============================================= */
    // Directed Graph

    vector<int> graph3[n + 1];
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        // u -> v
        graph3[u].push_back(v);
    }
    /* ============================================= */
    // Weighted Graph

    int graph4[n + 1][m + 1];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph1[u][v] = w;
        graph1[v][u] = w;
    }

    vector<pair<int, int>> graph5[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph5[u].push_back(make_pair(v, w));
        graph5[v].push_back(make_pair(u, w));
    }
    return 0;
}