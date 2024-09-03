#include <bits/stdc++.h>
using namespace std;
// Danh sách cạnh sang danh sách kề
int main()
{
    vector<int> adj[100];
    int vertise, edge;
    cin >> vertise >> edge;
    for (int i = 1; i <= edge; i++)
    {
        int m, n;
        cin >> m >> n;
        adj[m].push_back(n);
        adj[n].push_back(m);
    }
    for (int i = 1; i <= vertise; i++)
    {
        cout << i << " : ";
        for (int x : adj[i])
            cout << x << " ";
        cout << endl;
    }
    return 0;
}