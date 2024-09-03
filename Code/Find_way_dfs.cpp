#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

multimap<char, char> G;
map<char, bool> visited;
map<char, char> parent;

void input(int edges)
{
    for (int i = 1; i <= edges; i++)
    {
        char x, y;
        cin >> x >> y;
        G.insert({x, y});
    }
}

void DFS(char u)
{
    visited[u] = true;
    for (auto it = G.equal_range(u); it.first != it.second; ++it.first)
    {
        if (!visited[it.first->second])
        {
            parent[it.first->second] = u;
            DFS(it.first->second);
        }
    }
}

void Path(char s, char t)
{
    for (auto pair : visited)
    {
        pair.second = false;
    }
    DFS(s);
    if (!visited[t])
    {
        cout << "no_path\n";
    }
    else
    {
        vector<char> path;
        while (t != s)
        {
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for (auto x : path)
        {
            cout << x << " ";
        }
    }
}

int main()
{
    int vertise, edge;
    cin >> vertise >> edge;
    for (int i = 1; i <= vertise; i++)
    {
        char x;
        cin >> x;
    }
    input(edge);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        char x, y;
        cin >> x >> y;
        Path(x, y);
    }
}