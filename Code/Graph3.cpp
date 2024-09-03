#include <bits/stdc++.h>
using namespace std;
// Ma trận kề sang danh sách cạnh
int main()
{
    int A[100][100];
    int vertise;
    cin >> vertise;
    for (int i = 1; i <= vertise; i++)
        for (int j = 1; j <= vertise; j++)
            cin >> A[i][j];
    for (int i = 1; i <= vertise; i++)
    {
        for (int j = 1; j <= vertise; j++)
        {
            if (A[i][j] == 1 && i < j)
            {
                cout << i << " " << j;
                cout << endl;
            }
        }
    }
    return 0;
}