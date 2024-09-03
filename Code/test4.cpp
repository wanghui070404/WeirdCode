#include <bits/stdc++.h>
using namespace std;

int n = 0, st[10001];
// Them phan tu vao stack
void push(int x)
{
    st[n] = x;
    ++n;
}
void pop()
{
    if (n >= 0)
        --n;
}
int top()
{
    if (n > 0)
        return st[n - 1];
}
int size()
{
    return n;
}
bool empty()
{
    return n == 0;
}
int main()
{
    while (1)
    {
        cout << "-------------------MENU--------------------\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Size\n";
        cout << "5. Empty\n";
        cout << "0. Thoat\n";
        cout << "-------------------------------------------\n";
        int lc;
        cout << "Nhap lua chon: ";
        cin >> lc;
        if (lc == 1)
        {
            int x;
            cout << "Nhap gia tri: ";
            cin >> x;
            push(x);
        }
        if (lc == 2)
        {
            pop();
        }
        if (lc == 3)
        {
            cout << "Phan tu dau cua stack: " << top() << endl;
        }
        if (lc == 4)
        {
            cout << "Kich thuoc cua stack: " << size() << endl;
        }
        if (lc == 5)
        {
            if (empty() == true)
                cout << "Stack is empty\n";
            else
                cout << "Stack is not empty\n";
        }
        if (lc == 0) break;
    }
    return 0;
}
