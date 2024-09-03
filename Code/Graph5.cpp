#include <bits/stdc++.h>
using namespace std;
// Danh sách kề sang danh sách cạnh
int main()
{
    vector<int> adj[100];
    int vertise;
    cin >> vertise;
    cin.ignore();
    for (int i = 1; i <= vertise; i++)
    {
        string s, num;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> num)
        {
            if (stoi(num) > i)
                adj[i].push_back(stoi(num));
        }
    }
    for (int i = 1; i <= vertise; i++)
    {
        for (auto x : adj[i])
            cout << i << " " << x << '\n';
    }
    return 0;
}