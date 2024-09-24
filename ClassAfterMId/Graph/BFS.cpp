#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Graph {
    int Vertices;
    vector<vector<int>> adjList;

public:
    Graph(int n) {
        Vertices = n;
        adjList.resize(Vertices);
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void print() {
        for (int i = 0; i < Vertices; i++) {
            printf("%d", i);
            for (int vertex : adjList[i]) {
                printf(" -----> %d", vertex);
            }
            printf("\n");
        }
    }

    void BFS(int startvertex) {
        vector<bool> visited(Vertices, false);
        queue<int> q;
        visited[startvertex] = true;
        q.push(startvertex);

        while (!q.empty()) {  // Corrected condition
            int current_vertex = q.front();
            q.pop();
            printf("%d ", current_vertex);

            for (int vertex : adjList[current_vertex]) {
                if (!visited[vertex]) {
                    visited[vertex] = true;
                    q.push(vertex);
                }
            }
        }
    }
};

int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    g.print();
    g.BFS(0);

    return 0;
}
