#include <iostream>

using namespace std;

class Node

{

private:
    Node *left, *right; // data members

    int data;

    int rbit, lbit;

public:
    Node(int d)

    {

        left = NULL;

        right = NULL;

        data = d;

        rbit = lbit = 0;
    }

    friend class TBT;
};

class TBT

{

private:
    Node *root, *header; // data members

public:
    TBT()

    { // constructor

        root = NULL;

        header = new Node(999);

        header->right = header;
        header->left = header;
        header->rbit = 1;
        header->lbit = 0;
    }
    void create(int d);

    Node *insert(Node *, int d);

    void linsert(Node *, Node *);

    void rinsert(Node *, Node *);

    void inorder();

    void preorder();

    void deleteNode(int);

    Node *inSucc(Node *);

    Node *inPred(Node *);
};

void TBT::create(int data)
{
    Node *p, *q;
    int dat;
    if (header == NULL)
    {
        p = new Node(0);
        header = p;
        p->left = p;
        p->right = p;
        p->lbit = 0;
        p->rbit = 1;
        // cout << "\nEnter data: ";
        // cin >> dat;
        q = new Node(data);
        linsert(header, q);
    }
    else
    {
        cout << 'Tree head is created' << endl;
        cout << "\nEnter data: ";
        cin >> dat;
        header->left = insert(header->left, dat);
    }
}

Node *TBT::insert(Node *t1, int d)

{
    Node *t;
    if (d < t1->data)
    {
        if (t1->lbit == 0)
        {
            t = new Node(d);
            linsert(t1, t);
        }
        else
            t = insert(t1->left, d);
    }
    else if (d > t1->data)
    {
        if (t1->rbit == 0)
        {
            t = new Node(d);
            rinsert(t1, t);
        }
        else
            t = insert(t1->right, d);
    }
}
void TBT::linsert(Node *s, Node *t)
{
    t->left = s->left;
    t->right = s;
    t->lbit = s->lbit;
    t->rbit = 0;
    s->left = t;
    s->lbit = 1;
}

void TBT::rinsert(Node *s, Node *t)
{
    t->right = s->right;
    t->left = s;
    t->rbit = s->rbit;
    t->lbit = 0;
    s->right = t;
    s->rbit = 1;
}

void TBT::inorder()
{
    Node *T;
    T = header;
    cout << T->data;
    while (T != NULL)
    {
        T = inSucc(T);
        if (T == header)
            return;
        cout << T->data << " ";
    }
}
Node *TBT::inSucc(Node *ptr)

{
    Node *s;
    s = ptr->right;
    cout << s->data;
    if (ptr->rbit == 1)
    {
        while (s->lbit == 1)
            s = s->left;
    }

    return s;
}
void TBT::preorder()
{
    Node *T;
    T = header->left;
    while (1)
    {
        if (T == header)
            return;
        cout << T->data << " ";
        if (T->lbit == 1)
            T = T->left;
        else
        {
            if (T->rbit == 1)
                T = T->right;
            else
            {
                while (T->rbit != 1)
                    T = T->right;
                T = T->right;
            }
        }
    }
}

int main()

{

    TBT t1;

    int ch;

    while (true)

    {

        cout << "\n<<-----MENU----->>" << endl;

        cout << "1. Insert" << endl;

        cout << "2. Inorder Traversal " << endl;

        cout << "3. Preorder Traversal" << endl;

        cout << "4. Delete Node" << endl;

        cout << "5. Exit" << endl;

        cout << "Enter choice : ";

        cin >> ch;

        switch (ch)

        {

        case 1:

        {

            int n;

            cout << "\nEnter number of Nodes:";

            cin >> n;

            for (int i = 0; i < n; i++)

            {

                int data;

                cout << "\nEnter data: ";

                cin >> data;

                t1.create(data);
            }

            break;
        }

        case 2:

        {
            cout << "Inorder Traversal : " << endl;

            t1.inorder();

            break;
        }

        case 3:

        {
            cout << "Preorder Traversal : " << endl;

            t1.preorder();

            break;
        }

        case 4:

        {
            break;
        }

        case 5:

            exit(1);

            break;

        default:

            cout << "Please ,enter valid choice!!" << endl;
        }
    }

    return 0;
}