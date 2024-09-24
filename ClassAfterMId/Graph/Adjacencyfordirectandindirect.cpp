#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int Vertices;
    bool directed;
    vector<vector<int>> adjList;

public:
    Graph(int n, bool dir)
    {
        Vertices = n;
        directed = dir;
        adjList.resize(Vertices);
    }

    void addEdge(int src, int dest)
    {
        adjList[src].push_back(dest);
        if (!directed)
        {
            adjList[dest].push_back(src);
        }
    }

    void print()
    {
        for (int i = 0; i < Vertices; i++)
        {
            printf("%d", i);
            for (int vertex : adjList[i])
            {
                printf(" -----> %d", vertex);
            }
            printf("\n");
        }
    }

    void findMutual(int u, int v)
    {
        printf("Mutual vertices between %d and %d: ", u, v);
        unordered_set<int> mutual;
        for (int vertex : adjList[u])
        {
            mutual.insert(vertex);
        }
        for (int vertex : adjList[v])
        {
            if (mutual.find(vertex) != mutual.end())
            {
                printf("%d ", vertex);
            }
        }
        printf("\n");
    }
};

int main()
{
    Graph g(4, false);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    g.print();
    g.findMutual(0, 3);

    return 0;
}

