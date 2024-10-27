/**
 * Author: omteja04
 * Created on: 13-10-2024 10:49:20
 * Description: BFS
 **/

#include <bits/stdc++.h>
using namespace std;
// BFS uses Queue

class Graph {
private:
    int nodes;
    int edges;
    vector<int> *graph;

public:
    Graph(int nodes, int edges) : nodes(nodes), edges(edges) {
        graph = new vector<int>[nodes + 1];
    }

    void initializeGraph() {
        for (int i = 0; i < edges; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }

    void printAdjacencyList() {
        for (int i = 1; i <= nodes; i++) {
            cout << "Node " << i << "\t->\t";
            for (int j = 0; j < graph[i].size(); j++) {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
    }
    // ! TC-> O(n*2E)
    vector<int> bfsOfGraph(int v, vector<int> graph[]) { // vertices
        vector<int> bfs;
        vector<bool> visited(v + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for (auto &neighbour : graph[node]) {
                if (visited[node] == false) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        return bfs;
    }
    vector<int> *getList() {
        return graph;
    }
};

int main() {
    int n, m;

    cin >> n >> m;

    Graph graph(n, m);

    graph.initializeGraph();
    graph.printAdjacencyList();
    vector<int> bfs = graph.bfsOfGraph(n, graph.getList());
    for (int node : bfs) {
        cout << node << " ";
    }

    return 0;
}