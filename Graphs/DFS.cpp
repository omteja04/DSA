/**
 * Author: omteja04
 * Created on: 13-10-2024 12:04:29
 * Description: DFS
 **/

#include <bits/stdc++.h>
using namespace std;

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
            std::cin >> u >> v;
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
    // ! TC-> O(V+2E)
    // ! SC-> O(3n)

    void rec(int node, vector<int> *graph, vector<bool> &visited, vector<int> &dfs) {
        visited[node] = true;
        dfs.push_back(node);
        for (auto &neightbour : graph[node]) {
            if (!visited[neightbour])
                rec(neightbour, graph, visited, dfs);
        }
    }
    vector<int> dfsOfGraph(int v, vector<int> graph[]) { // vectices
        vector<int> dfs;
        vector<bool> visited(v + 1, false);
        visited[1] = true;
        rec(1, graph, visited, dfs);
        return dfs;
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
    vector<int> dfs = graph.dfsOfGraph(n, graph.getList());
    for (int node : dfs) {
        cout << node << " ";
    }

    return 0;
}