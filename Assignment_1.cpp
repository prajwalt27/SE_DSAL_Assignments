#include <iostream>
#include <stack>
#define max 1000
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

class bTree
{
public:

   //Operations
    Node *create();

    //Recursive traversals
    void inorder_r(Node *root);
    void preorder_r(Node *root);
    void postorder_r(Node *root);

   //iterative traversals
    void I_inorder(Node *root);
    void I_preorder(Node *root);
    void I_postorder(Node *root);

    void mirror(Node *root);

    int height(Node *root);

    int getLeafCount(Node *root);

    int countInternalNodes(Node *root);

    void deleteTree(Node *root);
};


Node *bTree::create()
{
    int key;
    Node *root;
    bool flag = false;
    root = new Node();
    cout << "\n1.NULL \n2.Input \n";
    cin >> key;
    if (key == 1)
    {
        return 0;
    }
    else if ( key == 2)
    {

        cout << "Enter element \n";
        cin >> root->data;
        cout << "Enter element to left of " << root->data;
        root->left = create();
        cout << "Enter element to right of " << root->data;
       root->right = create();
        flag=true;
        return root;
    }
    else
    {
        cout << "Enter valid choice..!"<< "\n";
        flag=false;
        return 0;
    }
}


//Recursive Traversals 

void bTree::inorder_r(Node *root)
{
    if (root == NULL)
        return;

    inorder_r(root->left);
    cout << root->data << " ";
    inorder_r(root->right);
}

void bTree::preorder_r(Node *root)
{

    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder_r(root->left);
    preorder_r(root->right);
}

void bTree::postorder_r(Node *root)
{
    if (root == NULL)
        return;

    postorder_r(root->left);
    postorder_r(root->right);
    cout << root->data << " ";
}


//Inorder Traversals
void bTree::I_inorder(Node *root)
{
    Node *d;
    int finish, top;
    top = 0;
    d = root;
    finish = 0;
    Node *stack[max];
    do
    {
        while (d != NULL)
        {
            top++;
            stack[top] = d;
            d = d->left;
        }
        if (top != 0)
        {
            d = stack[top];
            top--;
            cout << d->data << " ";
            d = d->right;
        }
        else
            finish = 1;
    } while (finish == 0);
}

void bTree::I_preorder(Node *root)
{
    Node *d;
    int finish, top;
    top = 0;
    d = root;
    finish = 0;
    Node *stack[max];
    do
    {
        while (d != NULL)
        {
            top++;
            stack[top] = d;
            cout << d->data << " ";
            d = d->left;
        }

        if (top != 0)
        {
            d = stack[top];
            top--;
            d = d->right;
        }
        else
            finish = 1;

    } while (finish == 0);
}

void bTree::I_postorder(Node *root)
{
    int top = -1;
    Node *p = root;
    Node *stack[max];
    do
    {
        while (p != NULL)
        {
            if (p->right != NULL)
            {
                top++;
                stack[top] = p->right;
            }
            top++;
            stack[top] = p;
            p = p->left;
        }

        p = stack[top];
        top--;
        if (p->right && (stack[top] == p->right))
        {
            stack[top] = p;
            p = p->right;
        }
        else
        {
            cout << p->data << " ";
            p = NULL;
        }
    } while (top != -1);
}

int bTree::height(Node *root)
{
    Node *p = root;
    if (p == NULL)
        return 0;
    else
    {
        int left;
        int right;
        left = height(p->left);
        right = height(p->right);
        if (left> right)
        {
            return left + 1;
        }
        else
            {
                return right + 1;
            }
    }
}

void bTree::mirror(Node *root)
{
    Node *p = root;
    if (p == NULL)
        return;
    else
    {
        Node *swap;

        mirror(p->left);
        mirror(p->right);
        swap = p->left;
        p->left = p->right;
        p->right = swap;
    }
}

int bTree::getLeafCount(Node *root)
{
    if (root == NULL)
    {
        cout << "\nTree is empty" << endl;
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
        return 1;
    else
        return getLeafCount(root->left) + getLeafCount(root->right);
}

int bTree::countInternalNodes(Node *root)
{

    if (root != NULL)
    {
        
        int result = countInternalNodes(root->left) + countInternalNodes(root->right);
        if (root->left != NULL || root->right != NULL)
        {

            return result + 1;
        }
        else
        {

            return result;
        }
    }
    else
    {

        cout << "\nTree is empty" << endl;
        return 0;
    }
}

void bTree::deleteTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    deleteTree(root->left);

    deleteTree(root->right);

    delete root;
    root = NULL;
}

int main()
{
    char input = 'y';
    while (input != 'n')
    {
        int choice;
        Node *n;
        bTree *op;
        cout << "*-------Main Menu--------*"<< "\n";
        cout << "\n1.Create tree\n2.Recursive Traversal\n3.Iterative Traversal\n4.Height of tree\n5.Mirroing of tree\n6.Leaf count\n7.Internal node count\n8.Delete the tree";
        cout << "\n\nEnter your choice :";
        cin >> choice;
        switch (choice)
        {
        case 1:
            n = op->create();
            
            cout << "Created successfully !" << endl;
            break;
        case 2:
            if (n != NULL)
            {
                cout << "\n<---------Recursive Traversal---------->";
                cout << "\n Inorder traversal  :";
                op->inorder_r(n);
                cout << "\n Preorder traversal  :";
                op->preorder_r(n);
                cout << "\n Postorder traversal  :";
                op->postorder_r(n);
                break;
            }
            else
            {
                cout << "\nBinary tree is empty !";
                break;
            }

        case 3:
            if (n != NULL)
            {
                cout << "\n\n\n<----------Iterative Traversal------------>";
                cout << "\n Inorder traversal  :";
                op->I_inorder(n);
                cout << "\n Preorder traversal  :";
                op->I_preorder(n);
                cout << "\n Postorder traversal  :";
                op->I_postorder(n);
                break;
            }
            else
            {
                cout << "\nBinary tree is empty";
                break;
            }

        case 4:

            cout << "\n\n Height of Binary tree : " << op->height(n) << endl;
            break;

        case 5:
            cout << "original tree is :";
            op->inorder_r(n);
            cout << "\n\nmirror of original tree: ";
            op->mirror(n);
            op->inorder_r(n);

            break;

        case 6:
            cout << "\n\nThe count of leaf node is:" << op->getLeafCount(n);
            break;

        case 7:
            cout << "\n\nThe count of Internal node is:" << op->countInternalNodes(n);
            break;
        case 8:
            op->deleteTree(n);
            cout << "\n\nTree deleted successfully." << endl;
            n = NULL;
            break;

        default:
            cout << "Enter valid choice";
            break;
        }
        cout << "\n\nDo you want to perform again (y/n) :";
        cin >> input;
    }

    return 0;
}
