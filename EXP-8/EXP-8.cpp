#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
int minDistance(vector<int> &dist, vector<bool> &sptSet, int V)
{
    int minVal = INF, minIndex = -1;
    for (int v = 0; v < V; v++)
    {
        if (!sptSet[v] && dist[v] <= minVal)
        {
            minVal = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}
void printSolution(vector<int> &dist, int V)
{
    cout << "\nVertex\tDistance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << dist[i] << "\n";
}
void dijkstra(vector<vector<int>> &graph, int src, int V)
{
    vector<int> dist(V, INF);
    vector<bool> sptSet(V, false);
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist, V);
}

int main()
{
    cout << "DIJKSTRA'S ALGORITHM - SHORTEST PATH FINDER\n\n";
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V, 0));
    cout << "\nEnter the adjacency matrix (0 for no edge):\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];
    }

    int src;
    cout << "\nEnter source vertex (0 to " << V - 1 << "): ";
    cin >> src;
    dijkstra(graph, src, V);
    return 0;
}