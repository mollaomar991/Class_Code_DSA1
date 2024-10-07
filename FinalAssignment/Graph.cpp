#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph1 {
    int AdjcencyMatrix[100][100];  
    int NVertices;
    bool Directed;

public:
    
    Graph1(int n, bool dir) {
        NVertices = n;
        Directed = dir;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                AdjcencyMatrix[i][j] = 0;
            }
        }
    }

    
    void addEdge(int m, int n) {
        AdjcencyMatrix[m - 1][n - 1] = 1; 
        if (!Directed) {
            AdjcencyMatrix[n - 1][m - 1] = 1;  
        }
    }

   
    void print() {
        printf("Adjacency Matrix: \n");
        for (int i = 0; i < NVertices; i++) {
            for (int j = 0; j < NVertices; j++) {
                printf("%d ", AdjcencyMatrix[i][j]);
            }
            printf("\n");
        }
    }
     void finMutual(int u,int v)
    {
       int  found = 0;
        printf("Mutual vertices between %d and %d: ", u, v);
        for (int i = 0; i <= NVertices; i++)
        {
            if(AdjcencyMatrix[u-1][i-1]==1 && AdjcencyMatrix[v-1][i-1]==1)
            {
                printf("%d ", i);
               found = 1;
            }
        }
        if(!found){
        printf("not foud");
            }
         printf("\n");
        }
      
    

 void findDegree(int vertex) {
        int deg = 0;
        for (int j = 0; j < NVertices; j++) {
            if (AdjcencyMatrix[vertex - 1][j] != 0) {
                deg++;
            }
        }
        printf("Degree of vertex %d is %d\n", vertex, deg);
    }

};


class Graph2 {
    int Vertices;
    vector<vector<int>> adjList;  

public:
   
    Graph2(int n) {
        Vertices = n;
        adjList.resize(Vertices);
    }

    
    void addEdge(int src, int dest) {
        adjList[src - 1].push_back(dest); 
        adjList[dest - 1].push_back(src);  
    }


    void print() {
        printf("Adjacency List: \n");
        for (int i = 0; i < Vertices; i++) {
            printf("%d", i + 1);  
            for (int vertex : adjList[i]) {
                printf(" -----> %d", vertex);
            }
            printf("\n");
        }
    }

    void BFS(int startvertex) {
        vector<bool> visited(Vertices, false);  
        queue<int> q;

        startvertex -= 1; 
        visited[startvertex] = true;
        q.push(startvertex);

        printf("BFS traversal starting from vertex %d: ", startvertex + 1);
        while (!q.empty()) { 
            int current_vertex = q.front();
            q.pop();
            printf("%d ", current_vertex + 1);

    
            for (int neighbor : adjList[current_vertex]) {
                neighbor -= 1;  
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        printf("\n");
    }
};

int main() {
  
    Graph1 g1(5, false);  
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(1, 4);
    g1.addEdge(1, 5);
    g1.addEdge(2, 3);
    g1.addEdge(2, 4);
    g1.addEdge(2, 5);
    g1.addEdge(3, 4);
    g1.addEdge(3, 5);
    g1.addEdge(4, 5);

    g1.print();  
    g1.finMutual(1,7);
    g1.findDegree(1);

    
    Graph2 g2(5);  
    g2.addEdge(1, 2);
    g2.addEdge(1, 3);
    g2.addEdge(1, 4);
    g2.addEdge(1, 5);
    g2.addEdge(2, 3);
    g2.addEdge(2, 4);
    g2.addEdge(2, 5);
    g2.addEdge(3, 4);
    g2.addEdge(3, 5);
    g2.addEdge(4, 5);

    g2.print();  

    
    g2.BFS(5);

    return 0;
}
