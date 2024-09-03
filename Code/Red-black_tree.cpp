#include <iostream>
#include <cmath>

using namespace std;
#define COUNT 10

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *parent;
    bool color;
    // 1 -> Red   | 0 -> Black
};

Node *maxValueNode(Node *root)
{
    Node *current = root;

    // Tìm kiếm Node có giá trị lớn nhất
    while (current->right != NULL)
        current = current->right;

    return current;
}

Node *sibling(Node *current)
{
    if (current->parent == NULL)
        return NULL;
    if (current->parent->left == current)
        return current->parent->right;
    return current->parent->left;
}

void swapColors(Node *x1, Node *x2)
{
    bool temp;
    temp = x1->color;
    x1->color = x2->color;
    x2->color = temp;
}

void swapValues(Node *u, Node *v)
{
    int temp;
    temp = u->data;
    u->data = v->data;
    v->data = temp;
}

bool hasRedChild(Node *x)
{
    if (x->right != NULL)
        if (x->right->color == 1)
            return true;
    if (x->left != NULL)
        if (x->left->color == 1)
            return true;
    return false;
}

string getColor(Node *root)
{
    if (root->color == 1)
        return "RED";
    return "BLACK";
}

// In - Print 2D ra console
void print2DUtil(Node *root, int space)
{
    if (root == NULL)
        return;
    space += COUNT;

    print2DUtil(root->right, space);
    cout << endl;

    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << " (" << getColor(root) << ") "
         << "\n";
    print2DUtil(root->left, space);
}

void print2D(Node *root)
{
    print2DUtil(root, 0);
}

struct RedBlackTree
{
    Node *Root;
    bool ll = false;
    bool rr = false;
    bool lr = false;
    bool rl = false;
    RedBlackTree()
    {
        Root = NULL;
    }
    Node *rotateRight(Node *root)
    {
        Node *x = root->left;
        // Gán x->right vào left root
        root->left = x->right;
        if (x->right != NULL)
            x->right->parent = root;

        x->parent = root->parent;
        if (root->parent == NULL)
            Root = x;
        else if (root->parent->left == root)
            root->parent->left = x;
        else
            root->parent->right = x;
        // Gán root vào x.right
        x->right = root;
        root->parent = x;

        // Trả về x
        return x;
    }

    Node *rotateLeft(Node *root)
    {
        Node *y = root->right;
        // Gán y->left vào right root
        root->right = y->left;
        if (y->left != NULL)
            y->left->parent = root;

        y->parent = root->parent;
        if (root->parent == NULL)
            Root = y;
        else if (root->parent->left == root)
            root->parent->left = y;
        else
            root->parent->right = y;

        // Gán root vào y.left
        y->left = root;
        root->parent = y;

        // Trả về y;
        return y;
    }
    Node *insertHelp(Node *root, int key)
    {
        // f đúng khi có xung đột đỏ
        bool f = false;

        if (root == NULL)
        {
            return new Node{key, NULL, NULL, NULL, 1}; // RED Node
        }
        else if (key < root->data)
        {
            root->left = insertHelp(root->left, key);
            root->left->parent = root;
            // root->left = Node X
            // root       = X->parent
            if (Root != root)
            {
                if (root->color == root->left->color == 1)
                    f = true;
            }
        }
        else
        {
            root->right = insertHelp(root->right, key);
            root->right->parent = root;
            // root->right = Node X
            // root        = X->parent
            if (Root != root)
            {
                if (root->color == root->right->color == 1)
                    f = true;
            }
        }

        // Xử lý 4 TH lệch
        // Khi này (ll, lr, rr, rl = false) nên chưa xử lí liền
        // Sau khi thoát 1 vòng đệ quy thì: root = X->parent->parent
        // Tức là Node ông, lúc này ta quay Node ông

        // Case 1 : Left left - Trái trái
        if (ll)
        {
            root = rotateRight(root);
            root->color = 0;
            root->right->color = 1;
            ll = false;
        }
        // Case 2 : Right right - Phải phải
        else if (rr)
        {
            root = rotateLeft(root);
            root->color = 0;
            root->left->color = 1;
            rr = false;
        }
        // Case 3 : Left right - Trái phải
        else if (lr)
        {
            root->left = rotateLeft(root->left);
            root->left->parent = root;

            root = rotateRight(root);
            root->color = 0;
            root->right->color = 1;
            lr = false;
        }
        // Case 4 : Right left - Phải trái
        else if (rl)
        {
            root->right = rotateRight(root->right);
            root->right->parent = root;

            root = rotateLeft(root);
            root->color = 0;
            root->left->color = 1;
            rl = false;
        }

        // Xử lí xung đột đỏ
        if (f)
        {
            if (root->parent->right == root)
            {
                if (root->parent->left == NULL || root->parent->left->color == 0)
                {
                    // Cha đỏ - chú đen (rr or rl)
                    if (root->left != NULL && root->left->color == 1)
                        rl = true;
                    if (root->right != NULL && root->right->color == 1)
                        rr = true;
                }
                else
                {
                    // Cha đỏ - chú đỏ
                    root->color = root->parent->left->color = 0;
                    if (root != Root)
                        root->parent->color = 1;
                }
            }
            else
            {
                if (root->parent->right == NULL || root->parent->right->color == 0)
                {
                    // Cha đỏ - chú đen (ll or lr)
                    if (root->left != NULL && root->left->color == 1)
                        ll = true;
                    if (root->right != NULL && root->right->color == 1)
                        lr = true;
                }
                else
                {
                    // Cha đỏ - chú đỏ
                    root->color = root->parent->right->color = 0;
                    if (root != Root)
                        root->parent->color = 1;
                }
            }
            f = false;
        }
        return root;
    }

    void Insert(int key)
    {
        if (Root == NULL)
        {
            Root = new Node{key, NULL, NULL, NULL, 0};
        }
        else
        {
            Root = insertHelp(Root, key);
            if (Root->color == 1)
                Root->color = 0;
        }
    }
    void fixDoubleBlack(Node *root)
    {
        if (root == Root)
            return;
        Node *sib = sibling(root);
        Node *par = root->parent;

        if (sib == NULL)
            fixDoubleBlack(par);
        else
        {
            if (sib->color == 1)
            {
                par->color = 1;
                sib->color = 0;

                if (sib->parent->left == sib)
                    par = rotateRight(par);
                else
                    par = rotateLeft(par);

                fixDoubleBlack(root);
            }
            else
            {
                if (hasRedChild(sib))
                {
                    if (sib->parent->left == sib)
                    {
                        if (sib->left != NULL && sib->left->color)
                        {
                            sib->left->color = sib->color;
                            sib->color = par->color;
                            par->color = 0;

                            par = rotateRight(par);
                        }
                        else
                        {
                            sib->right->color = par->color;
                            par->color = 0;
                            sib = rotateLeft(sib);
                            par = rotateRight(par);
                        }
                    }
                    else
                    {
                        if (sib->right != NULL && sib->right->color)
                        {
                            sib->right->color = sib->color;
                            sib->color = par->color;
                            par->color = 0;

                            par = rotateLeft(par);
                        }
                        else
                        {
                            sib->left->color = par->color;
                            par->color = 0;
                            sib = rotateRight(sib);
                            par = rotateLeft(par);
                        }
                    }
                }
                else
                {
                    sib->color = 1;
                    if (par->color == 0)
                        fixDoubleBlack(par);
                    else
                        par->color = 0;
                }
            }
        }
    }
    void deleteNode(Node *vDelete)
    {
        Node *uReplace;

        if ((vDelete->left != NULL) && (vDelete->right != NULL))
            uReplace = maxValueNode(vDelete->left);
        else if (vDelete->left != NULL)
            uReplace = vDelete->left;
        else if (vDelete->right != NULL)
            uReplace = vDelete->right;
        else
            uReplace = NULL;

        bool uvBlack = ((uReplace == NULL) || (uReplace->color == 0)) && (vDelete->color == 0);
        Node *par = vDelete->parent;
        Node *sib = sibling(vDelete);
        if (uReplace == NULL)
        {
            if (vDelete == Root)
            {
                Root = NULL;
            }
            else
            {
                if (uvBlack)
                    fixDoubleBlack(vDelete);
                else if (sib != NULL)
                    sib->color = 1;

                if (vDelete->parent->left == vDelete)
                    par->left = NULL;
                else
                    par->right = NULL;
            }
            delete vDelete;
            return;
        }

        if (vDelete->left == NULL || vDelete->right == NULL)
        {
            if (vDelete == Root)
            {
                vDelete->data = uReplace->data;
                vDelete->left = vDelete->right = NULL;
                delete uReplace;
            }
            else
            {
                if (vDelete->parent->left == vDelete)
                    par->left = uReplace;
                else
                    par->right = uReplace;
                delete vDelete;

                uReplace->parent = par;
                if (uvBlack)
                    fixDoubleBlack(uReplace);
                else
                    uReplace->color = 0;
            }
            return;
        }
        swapValues(uReplace, vDelete);
        deleteNode(uReplace);
    }
    Node *search(int val)
    {
        Node *temp = Root;
        while (temp != NULL)
        {
            if (val < temp->data)
            {
                if (temp->left == NULL)
                    return NULL;
                else
                    temp = temp->left;
            }
            else if (val == temp->data)
            {
                break;
            }
            else
            {
                if (temp->right == NULL)
                    return NULL;
                else
                    temp = temp->right;
            }
        }
        return temp;
    }
    void Delete(int val)
    {
        Node *vDelete = search(val);
        if (vDelete == NULL)
        {
            cout << "\n ** Khong tim thay Node can xoa **\n";
            return;
        }
        else
        {
            deleteNode(vDelete);
        }
        return;
    }
};

int main()
{
    RedBlackTree RBTree;
    while (1)
    {
        cout << "1. Chen\n";
        cout << "2. Xoa\n";
        cout << "3. In\n";
        cout << "4. Thoat\n";
        cout << "Nhap lua chon: ";
        int lc;
        cin >> lc;
        if (lc == 1)
        {
            cout << "Nhap gia tri can chen: ";
            int val;
            cin >> val;
            RBTree.Insert(val);
        }
        if (lc == 2)
        {
            cout << "Nhap gia tri can xoa: ";
            int val;
            cin >> val;
            RBTree.Delete(val);
        }
        if (lc == 3)
        {
            print2D(RBTree.Root);
        }
        if (lc == 4)
        {
            break;
        }
    }
    return 0;
}