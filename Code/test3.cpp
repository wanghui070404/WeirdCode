// TAO STACK BANG CACH SU DUNG DANH SACH LIEN KET DON
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
// Khoi tao mot node
Node *makeNode(int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}
// Chen mot node vao dau
void push(Node **head, int x)
{
    Node *tmp = makeNode(x);
    if ((*head) == nullptr)
        (*head) = tmp;
    else
    {
        tmp->next = (*head);
        (*head) = tmp;
    }
}
// Xoa mot node o dau
void pop(Node **head)
{
    if ((*head) == nullptr)
        return;
    else
    {
        (*head) = (*head)->next;
    }
}
// Lay phan tu o dau stack
void top(Node *head)
{
    cout << head->data << endl;
}
// Kiem tra so luong phan tu trong stack
int Size(Node *head)
{
    int cnt = 0;
    while (head != nullptr)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}
// Kiem tra rong
bool empty(Node *head)
{
    return head == nullptr;
}

int main()
{
    Node *head = nullptr;
    while (1)
    {
        cout << "--------------------------MENU---------------------------\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Size\n";
        cout << "5. Empty\n";
        cout << "0. Thoat\n";
        cout << "---------------------------------------------------------\n";
        int lc;
        cout << "Nhap lua chon: ";
        cin >> lc;
        if (lc == 1)
        {
            cout << "Nhap gia tri can push: ";
            int x;
            cin >> x;
            push(&head, x);
        }
        if (lc == 2)
        {
            pop(&head);
        }
        if (lc == 3)
        {
            top(head);
        }
        if (lc == 4)
        {
            cout << "Kich thuoc cua stack: " << Size(head) << endl;
        }
        if (lc == 5)
        {
            if (empty(head) == true)
                cout << "Stack is empty\n";
            else
                cout << "Stack is not empty\n";
        }
        if (lc == 0)
            break;
    }
    return 0;
}
