#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *makeNode(int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}
// Kich thuoc cua danh sach lien ket doi
int size(Node *head)
{
    int cnt = 0;
    while (head != nullptr)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}
// Them mot node vao dau
void Insert_head(Node **head, int x)
{
    Node *newNode = makeNode(x);
    newNode->next = (*head);
    if ((*head) != nullptr)
        (*head)->prev = newNode;
    (*head) = newNode;
}
// Them mot node vao cuoi
void Insert_tail(Node **head, int x)
{
    Node *newNode = makeNode(x);
    if (*(head) == nullptr)
    {
        *(head) = newNode;
        return;
    }
    else
    {
        Node *tmp = *(head);
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
        newNode->prev = tmp;
    }
}
// Them mot node vao giua
void Insert_middle(Node **head, int x, int pos)
{
    if (pos < 1 || pos > size(*head) + 1)
    {
        cout << "Vi tri chen khong hop le\n";
        return;
    }
    else if (pos == 1)
    {
        Insert_head(head, x);
        return;
    }
    else if (pos == size(*head) + 1)
    {
        Insert_tail(head, x);
        return;
    }
    else if (pos > 1 && pos < size(*head) + 1)
    {
        Node *tmp = *head;
        for (int i = 1; i < pos; i++)
        {
            tmp = tmp->next;
        }
        Node *newNode = makeNode(x);
        newNode->next = tmp;
        newNode->prev = tmp->prev;
        tmp->prev->next = newNode;
        tmp->prev = newNode;
    }
}
// Xoa mot node o dau danh sach lien ket doi
void Delete_head(Node **head)
{
    if (*head == nullptr)
        return;
    else
    {
        *head = (*head)->next;
        (*head)->prev = nullptr;
    }
}
// Xoa mot node o cuoi danh sach lien ket doi
void Delete_tail(Node **head)
{
    if (*head == nullptr)
        return;
    else
    {
        Node *truoc = nullptr, *sau = (*head);
        while (sau->next != nullptr)
        {
            truoc = sau;
            sau = sau->next;
        }
        if (truoc == nullptr)
        {
            (*head) = nullptr;
        }
        truoc->next = nullptr;
        sau->prev = nullptr;
    }
}
// Xoa mot node o vi tri giua danh sach lien ket doi
void Delete_middle(Node **head, int pos)
{
    if (pos < 1 || pos > size(*head))
    {
        cout << "Vi tri xoa khong hop le\n";
        return;
    }
    else if (pos == 1)
    {
        Delete_head(head);
        return;
    }
    else if (pos == size(*head))
    {
        Delete_tail(head);
        return;
    }
    else if (pos > 1 && pos < size(*head))
    {
        Node *truoc = nullptr, *sau = (*head);
        for (int i = 1; i < pos; i++)
        {
            truoc = sau;
            sau = sau->next;
        }
        truoc->next = sau->next;
        sau->next->prev = truoc;
    }
}
// In danh sach lien ket doi
void print(Node *head)
{
    cout << "||------------||--------------||\n";
    while (head != nullptr)
    {
        cout << " " << head->data << " ";
        head = head->next;
    }
    cout << "\n";
    cout << "||------------||--------------||\n";
}
int main()
{
    Node *head = nullptr;
    while (1)
    {
        cout << "--------------------------------MENU-------------------------------\n";
        cout << "1. Them mot node vao dau danh sach lien ket doi\n";
        cout << "2. Them mot node vao cuoi danh sach lien ket doi\n";
        cout << "3. Them mot node vao giua danh sach lien ket doi\n";
        cout << "4. In danh sach lien ket doi\n";
        cout << "5. Thoat\n";
        cout << "6. Xoa mot node o dau danh sach lien ket doi\n";
        cout << "7. Xoa mot node o cuoi danh sach lien ket doi\n";
        cout << "8. Xoa mot node o vi tri bat ki trong danh sach lien ket doi\n";
        cout << "-------------------------------------------------------------------\n";
        cout << "Nhap lua chon: ";
        int lc;
        cin >> lc;
        if (lc == 1)
        {
            cout << "Nhap gia tri can chen vao dau: ";
            int value;
            cin >> value;
            Insert_head(&head, value);
        }
        if (lc == 2)
        {
            cout << "Nhap gia tri can chen vao cuoi: ";
            int value;
            cin >> value;
            Insert_tail(&head, value);
        }
        if (lc == 3)
        {
            cout << "Nhap vi tri can chen: ";
            int pos, value;
            cin >> pos;
            cout << "\n";
            cout << "Nhap gia tri can chen: ";
            cin >> value;
            cout << "\n";
            Insert_middle(&head, value, pos);
        }
        if (lc == 4)
        {
            print(head);
        }
        if (lc == 5)
            break;
        if (lc == 6)
        {
            Delete_head(&head);
        }
        if (lc == 7)
        {
            Delete_tail(&head);
        }
        if (lc == 8)
        {
            cout << "Nhap vi tri can xoa: ";
            int pos;
            cin >> pos;
            Delete_middle(&head, pos);
        }
    }
    return 0;
}