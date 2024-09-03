#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
};
typedef struct Node *node;
// Tao mot nut moi
node makeNode(int x)
{
	node newNode = new Node();
	newNode->data = x;
	newNode->next = nullptr;
	return newNode;
}
// Kiem tra rong
bool empty(node a)
{
	return a == nullptr;
}
// Dem so node trong danh sach lien ket
int size(node a)
{
	int count = 0;
	while (a != nullptr)
	{
		count++;
		a = a->next;
	}
	return count;
}
// Them mot node vao dau
void Insert_head(node &a, int x)
{
	node temp = makeNode(x);
	if (a == nullptr)
	{
		a = temp;
	}
	else
	{
		temp->next = a;
		a = temp;
	}
}
// Them mot node vao cuoi
void Insert_tail(node &a, int x)
{
	node temp = makeNode(x);
	if (a == nullptr)
	{
		a = temp;
	}
	else
	{
		node p = a;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->next = temp;
	}
}
// Them mot node vao giua
void Insert_middle(node &a, int x, int pos)
{
	node temp = makeNode(x);
	int n = size(a);
	if (pos <= 0 || pos > n + 1)
	{
		cout << "Vi tri chen khong hop le\n";
		return;
	}
	else
	{
		if (pos == 1)
		{
			Insert_head(a, x);
			return;
		}
		else if (pos == n + 1)
		{
			Insert_tail(a, x);
			return;
		}
		node p = a;
		for (int i = 1; i < pos - 1; i++)
		{
			p = p->next;
		}
		temp->next = p->next;
		p->next = temp;
	}
}
// Xoa mot node o dau
void Delete_head(node &a)
{
	if (a == nullptr)
		return;
	else
	{
		a = a->next;
	}
}
// Xoa mot node o cuoi
void Delete_tail(node &a)
{
	if (a == nullptr)
		return;
	else
	{
		node truoc = nullptr, sau = a;
		while (sau->next != nullptr)
		{
			truoc = sau;
			sau = sau->next;
		}
		if (truoc == nullptr)
			a = nullptr;
		else
		{
			truoc->next = nullptr;
		}
	}
}
// Xoa mot node o giua
void Delete_middle(node &a, int pos)
{
	if (pos <= 0 || pos > size(a))
		return;
	else
	{
		if (pos == 1)
		{
			Delete_head(a);
			return;
		}
		if (pos == size(a))
		{
			Delete_tail(a);
			return;
		}
		if (pos > 1 && pos < size(a))
		{
			node truoc = nullptr, sau = a;
			for (int i = 1; i < pos; i++)
			{
				truoc = sau;
				sau = sau->next;
			}
			truoc->next = sau->next;
		}
	}
}
// Tim gia tri
node find_value_node(node a, int x)
{
	while (a != nullptr)
	{
		if (a->data == x)
			return a;
		a = a->next;
	}
	return nullptr;
}
// Tim node co gia tri lon nhat
node find_node_max(node a)
{
	int max = a->data;
	node p = a;
	while (a != nullptr)
	{
		if (a->data > max)
		{
			max = a->data;
			p = a;
		}
		a = a->next;
	}
	return p;
}
/*node find_node_max(node a)
{
	if (a == nullptr) {
		return nullptr;
	}

	int max = a->data;
	node p = a;
	while (a->next != nullptr)
	{
		a = a->next;
		if (a->data > max)
		{
			max = a->data;
			p = a;
		}
	}
	return p;
}
*/
// In cac node trong danh sach lien ket
void print(node a)
{
	cout << "--------------------------\n";
	while (a != nullptr)
	{
		cout << a->data << " ";
		a = a->next;
	}
	cout << "\n";
	cout << "--------------------------\n";
	cout << "\n";
}
// Sap xep cac node trong danh sach lien ket
void swap(int &a, int &b)
{
	int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}
void arrange(node a)
{
	for (node p = a; p->next != nullptr; p = p->next)
	{
		node min_node = p;
		for (node q = p->next; q != nullptr; q = q->next)
		{
			if (q->data < min_node->data)
			{
				min_node = q;
			}
		}
		swap(min_node->data, p->data);
	}
}

int main()
{
	node head = nullptr;
	while (1)
	{
		cout << "-------------------------------MENU--------------------------------\n";
		cout << "1. Chen mot node vao dau\n";
		cout << "2. Chen mot node vao cuoi\n";
		cout << "3. Chen mot node vao giua\n";
		cout << "4. Xoa mot node o dau\n";
		cout << "5. Xoa mot node o cuoi\n";
		cout << "6. Xoa mot node o giua\n";
		cout << "7. Sap xep cac node trong danh sach lien ket\n";
		cout << "8. In danh sach lien ket don\n";
		cout << "9. Thoat\n";
		cout << "10. Dem so luong node trong danh sach lien ket don\n";
		cout << "11. Tim node co data la mot gia tri cho truoc\n";
		cout << "12. Tim node co chua data max\n";
		cout << "-------------------------------------------------------------------\n";
		int lc;
		cout << "Nhap lua chon: ";
		cin >> lc;
		if (lc == 1)
		{
			cout << "Nhap gia tri can chen vao dau: ";
			int value;
			cin >> value;
			Insert_head(head, value);
		}
		if (lc == 2)
		{
			cout << "Nhap gia tri can chen vao cuoi: ";
			int value;
			cin >> value;
			Insert_tail(head, value);
		}
		if (lc == 3)
		{
			cout << "Nhap gia tri can chen: ";
			int value;
			cin >> value;
			cout << "Nhap vi tri can chen: ";
			int pos;
			cin >> pos;
			Insert_middle(head, value, pos);
		}
		if (lc == 4)
		{
			Delete_head(head);
		}
		if (lc == 5)
		{
			Delete_tail(head);
		}
		if (lc == 6)
		{
			cout << "Nhap vi tri can xoa: ";
			int pos;
			cin >> pos;
			Delete_middle(head, pos);
		}
		if (lc == 7)
		{
			arrange(head);
		}
		if (lc == 8)
		{
			print(head);
		}
		if (lc == 9)
		{
			break;
		}
		if (lc == 10)
		{
			cout << "So luong node trong danh sach lien ket don: " << size(head) << "\n";
		}
		if (lc == 11)
		{
			cout << "Nhap gia tri can tim: ";
			int x;
			cin >> x;
			cout << "Node co data bang gia tri cho truoc la " << find_value_node(head, x) << "\n";
		}
		if (lc == 12)
		{
			cout << "Node co data max la " << find_node_max(head) << "\n";
		}
	}
	return 0;
}
