#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];
bool visited[100] = {false};

void input(int vertise, int edge)
{
    for (int i = 1; i <= edge; i++)
    {
        int m, n;
        cin >> m >> n;
        adj[m].push_back(n);
        adj[n].push_back(m);
    }
}

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int v = q.front();
        cout << v << " ";
        q.pop();
        for (int it : adj[v])
        {
            if (!visited[it])
            {
                q.push(it);
                visited[it] = true;
            }
        }
    }
}
int main()
{
    int vertise, edge, u;
    cin >> vertise >> edge;
    input(vertise, edge);
    cin >> u;
    BFS(u);
    return 0;
}