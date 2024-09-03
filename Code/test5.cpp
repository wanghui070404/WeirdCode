#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
// Khoi tao node
Node *makeNode(int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}
// Them mot phan tu vao Queue
void Push(Node **head, int x)
{
    Node *newNode = makeNode(x);
    if ((*head) == nullptr)
        (*head) = newNode;
    else
    {
        Node *tmp = (*head);
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}
// Xoa phan tu vao dau tien trong queue
void Pop(Node **head)
{
    if ((*head) == nullptr)
        return;
    else
        (*head) = (*head)->next;
}
int Top(Node *head)
{
    return head->data;
}
int Back(Node *head)
{
    Node *tmp = head;
    while (tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    return tmp->data;
}
bool Empty(Node *head)
{
    return head == nullptr;
}
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
void print(Node *head)
{
	cout << "--------------------------\n";
	while (head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
	cout << "--------------------------\n";
	cout << "\n";
}

int main()
{
    Node *head = nullptr;
    while (1)
    {
        cout << "------------------------MENU----------------------------\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Back\n";
        cout << "5. Empty\n";
        cout << "6. Size\n";
        cout << "7. In\n";
        int lc;
        cout << "Nhap lua chon: ";
        cin >> lc;
        if (lc == 1)
        {
            cout << "Nhap gia tri: ";
            int x;
            cin >> x;
            Push(&head, x);
        }
        if (lc == 2)
        {
            Pop(&head);
        }
        if (lc == 3)
        {
            cout << "Phan tu dau tien trong queue: " << Top(head) << endl;
        }
        if (lc == 4)
        {
            cout << "Phan tu cuoi cung trong queue: " << Back(head) << endl;
        }
        if (lc == 5)
        {
            if (Empty(head) == true)
                cout << "Queue is empty\n";
            else
                cout << "Queue is not empty\n";
        }
        if (lc == 6)
        {
            cout << "Kich thuoc cua queue: " << Size(head) << endl;
        }
        if (lc == 7)
        {
            print(head);
        }
    }
    return 0;
}