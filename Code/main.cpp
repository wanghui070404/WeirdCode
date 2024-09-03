#include <iostream>
using namespace std;

int main()
{
    int n, fibonacci = 0;
    cout << "Nhap n: ";
    cin >> n;
    if (n < 1 || n > 30)
    {
        cout << "Khong thoa dieu kien!" << endl;
        return 0;
    }
    else if (n == 1 || n == 2)
        fibonacci = 1;
    else
    {
        int a = 1, b = 1;
        for (int i = 3; i <= n; i++)
        {
            fibonacci = a + b;
            a = b;
            b = fibonacci;
        }
    }
    cout << fibonacci;
    return 0;
}