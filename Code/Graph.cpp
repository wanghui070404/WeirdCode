#include <bits/stdc++.h>
using namespace std;
// Danh sách cạnh sang ma trận kề
int main()
{
    int vertise, edge, m, n;
    cin >> vertise >> edge;
    int A[100][100] = {0};
    int count = 0;
    while (count < edge)
    {
        cin >> m >> n;
        A[m][n] = A[n][m] = 1;
        count++;
    }
    for (int i = 1; i <= vertise; i++)
    {
        for (int j = 1; j <= vertise; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    return 0;
}
