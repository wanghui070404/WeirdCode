#include <bits/stdc++.h>
using namespace std;
// Ma trận kề sang danh sách kề
int main()
{
    vector<int> adj[100];
    int A[100][100];
    int vertise;
    cin >> vertise;
    for (int i = 1; i <= vertise; i++)
        for (int j = 1; j <= vertise; j++)
        {
            cin >> A[i][j];
            if (A[i][j] == 1)
                adj[i].push_back(j);
        }
    for (int i = 1; i <= vertise; i++)
    {
        if (!adj[i].empty())
        {
            cout << i << "->";
            for (int x : adj[i])
                cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}