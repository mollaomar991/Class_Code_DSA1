#include <bits/stdc++.h>


class Graph
{
    int adjmat[100][100];
    int nVertics;
    bool directed;

public:
    Graph(int n, bool dir)
    {
        nVertics = n;
        directed = dir;


        for (int i = 0; i < nVertics; i++)
        {
            for (int j = 0; j < nVertics; j++)
            {
                adjmat[i][j] = 0;
            }
        }
    }

    void addEdge(int v, int u)
    {
        adjmat[v][u] = 1;
        if (!directed)
        {
            adjmat[u][v] = 1;
        }
    }

    void print()
    {
        for (int i = 0; i < nVertics; i++)
        {
            for (int j = 0; j < nVertics; j++)
            {
                printf("%d ", adjmat[i][j]);
            }
            printf("\n");
        }
    }

    void finMutual(int u)
    {
        printf("u %d: ",u);
        for (int i = 0; i < nVertics; i++)
        {


            if(adjmat[u][i]==1 )
            {
                printf(" %d ", i);

            }

        }

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
    g.finMutual(1);


    return 0;
}
