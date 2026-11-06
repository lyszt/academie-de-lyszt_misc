#include <bits/stdc++.h>

using namespace std;

void dfsRec(vector<vector<int>> &adj,
            vector<bool> &visited, int s, int parent, vector<int> &res, int &cycles, int start_point)
{

    visited[s] = true;

    res.push_back(s);

    // Recursively visit all adjacent vertices
    // that are not visited yet

    for (int i : adj[s])
        if (visited[i] == false)
        {
            dfsRec(adj, visited, i, s, res, cycles, start_point);
        }
        else if (i != parent)
        {
            cycles++;
            return;
        }
}
int dfs(vector<vector<int>> &adj)
{
    // modified so it returns the amount of cycles
    int cycles = 0;
    vector<bool> visited(adj.size(), false);
    vector<int> res;
    dfsRec(adj, visited, 0, -1, res, cycles, -1);
    return cycles;
}

int main()
{

    int edges, vertices;
    cin >> vertices >> edges;
    vector<vector<int>> graph(vertices + 1);
    for (int i = 0; i < edges; i++)
    {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cout << dfs(graph);
    return 0;
}