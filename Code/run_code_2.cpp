
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;

vector<int> get_ans(const vector<int> &A, int K)
{
    map<int, int> Hash;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        Hash[A[i]]++;
    }
    if (Hash.size() >= K)
    {
        int count = 0;

        for (auto x : Hash)
        {
            v.push_back(x.first);
            count++;
            if (count == K)
                break;
        }
        return v;
    }
    else
    {
        int d = K - Hash.size();
        for (auto x : Hash)
        {
            v.push_back(x.first);
            if (d > 0)
            {
                for (int i = 1; i < x.second; i++)
                {
                    v.push_back(x.first);
                    d--;
                    if (d == 0)
                        break;
                }
            }
        }
        return v;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> ans = get_ans(a, k);

    for (const int &x : ans)
        cout << x << ' ';
    return 0;
}
