#include <bits/stdc++.h>
using namespace std;

vector<int> get_ans(const vector<int> &A, int K)
{
    map<int, int> Hash;
    for (int i = 0; i < A.size(); i++)
    {
     Hash[A[i]]++;
    }

    vector<pair<int, int>> countPairs;
    for (const auto &entry : Hash)
    {
        countPairs.push_back({entry.second, entry.first});
    }

    sort(countPairs.rbegin(), countPairs.rend());

    vector<int> result;
    for (int i = 0; i < K; i++)
    {
        result.push_back(countPairs[i].second);
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> ans = get_ans(a, k);

    for (const int &x : ans)
        cout << x << ' ';
    return 0;
}
