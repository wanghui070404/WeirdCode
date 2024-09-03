#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int value;
    Node *left;
    Node *right;
};
// Tao node
Node *makeNode(int x)
{
    Node *newNode = new Node();
    newNode->value = x;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
// Chen mot node vao binary search tree
void Insert_node(Node **root, int x)
{
    Node *newNode = makeNode(x);
    if ((*root) == nullptr)
        (*root) = newNode;
    else
    {
        Node *temp = *root;
        while (1)
        {
            if (x < temp->value)
            {
                if (temp->left != nullptr)
                    temp = temp->left;
                else if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    break;
                }
            }
            if (x > temp->value)
            {
                if (temp->right != nullptr)
                    temp = temp->right;
                else if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    break;
                }
            }
        }
    }
}
// DUYET CAY NHI PHAN THEO CHIEU SAU
// Insert node by using Recursion
Node *Insert_node_recursion(Node *root, int value)
{
    if (root == nullptr)
        return makeNode(value);
    if (value < root->value)
    {
        if (root->left == nullptr)
            root->left = makeNode(value);
        else
            Insert_node_recursion(root->left, value);
    }
    else if (value > root->value)
    {
        if (root->right == nullptr)
            root->right = makeNode(value);
        else
            Insert_node_recursion(root->right, value);
    }
    return root;
}
// Pre-order: duyet tu dau
void Preorder(Node *root)
{
    if (root == nullptr)
        return;

    cout << root->value << " ";
    Preorder(root->left);
    Preorder(root->right);
}
// In-order: duyet tu giua
void Inorder(Node *root)
{
    if (root == nullptr)
        return;

    Inorder(root->left);
    cout << root->value << " ";
    Inorder(root->right);
}
// Post-order: duyet tu cuoi
void Postorder(Node *root)
{
    if (root == nullptr)
        return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->value << " ";
}
// DUYET CAY NHI PHAN THEO CHIEU RONG
vector<int> breadthFirstValues(Node *root)
{
    if (root == nullptr)
        return {};
    vector<int> values;
    queue<Node *> queue;
    queue.push(root);

    while (!queue.empty())
    {
        values.push_back(queue.front()->value);
        if (queue.front()->left != nullptr)
            queue.push(queue.front()->left);
        if (queue.front()->right != nullptr)
            queue.push(queue.front()->right);
        queue.pop();
    }
    return values;
}
// Tim node trai cung
Node *Find_left_mode_node(Node *root)
{
    Node *tmp = root;
    if (root == nullptr)
        return nullptr;
    while (tmp->left != nullptr)
    {
        tmp = tmp->left;
    }
    return tmp;
}
// Xoa node
Node *Delete_node(Node *root, int key)
{
    if (root == nullptr)
        return nullptr;
    if (key < root->value)
    {
        root->left = Delete_node(root->left, key);
    }
    else if (key > root->value)
    {
        root->right = Delete_node(root->right, key);
    }
    else
    {
        if (root->left == nullptr && root->right == nullptr)
            return nullptr;
        if (root->left != nullptr && root->right == nullptr)
            return root->left;
        if (root->left == nullptr && root->right != nullptr)
            return root->right;
        Node *left_mode_node = Find_left_mode_node(root->right);
        root->value = left_mode_node->value;
        root->right = Delete_node(root->right, left_mode_node->value);
        return root;
    }
}
Node *Find_value(Node *root, int key)
{
    if (root == nullptr)
        return nullptr;
    if (key < root->value)
    {
        return Find_value(root->left, key);
    }
    else if (key > root->value)
    {
        return Find_value(root->right, key);
    }
    else
    {
        return root;
    }
}
int main()
{
    Node *root = nullptr;
    root = Insert_node_recursion(root, 5);
    root = Insert_node_recursion(root, 1);
    root = Insert_node_recursion(root, 4);
    root = Insert_node_recursion(root, 0);
    root = Insert_node_recursion(root, 2);
    root = Insert_node_recursion(root, 3);
    for (auto it = breadthFirstValues(root).begin(); it != breadthFirstValues(root).end(); ++it)
        cout << *it << " ";
    Delete_node(root, 1);
    return 0;
}
