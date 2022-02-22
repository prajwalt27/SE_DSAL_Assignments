#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

template <class T>
class Stack;
class BinaryTree;

template <class T>
class SNode
{
    T data;
    SNode<T> *next;

public:
    SNode<T>()
    {
        data = 0;
        next = NULL;
    }

    SNode<T>(T val)
    {
        data = val;
        next = NULL;
    }

    friend class Stack<T>;
};

template <class T>
class Stack
{
    SNode<T> *top;

public:
    friend class BinaryTree;
    Stack<T>()
    {
        top = NULL;
    }

    void push(T val)
    {
        SNode<T> *temp = new SNode<T>(val);
        if (top == NULL)
        {
            top = temp;
            return;
        }
        temp->next = top;
        top = temp;
    }

    void pop()
    {
        if (!isEmpty())
        {
            SNode<T> *todelete = top;
            top = top->next;
            delete todelete;
        }
        else
        {
            cout << "Stack underflow" << endl;
        }
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    T Top()
    {
        return top->data;
    }
};



template <class T>
class Queue;

template <class T>
class QNode
{
    T data;
    QNode<T>* next;
    public:
        QNode<T>()
        {
            data=0;
            next=NULL;
        }

        QNode<T>(T val){
            data=val;
            next=NULL;
        }

    friend class Queue<T>;
};

template <class T>
class Queue
{
    QNode<T>*front,*rear;

    public:
    friend class BinaryTree;
        Queue<T>()
        {
            front=rear=NULL;
        }

        QNode<T>* getfront(){
            return front;
        }

        void push(T val){
            QNode<T> *temp = new QNode<T>(val);

            if(front==NULL){
                front=rear=temp;
                return;
            }
            rear->next = temp;
            rear = temp;
        }

        void pop(){
            if(!empty()){
                QNode<T>* todelete = front;
                front = front->next;
                delete todelete;
            }
            else{
                cout<<"Queue underflow"<<endl;
            }
        }

        bool empty(){
            return front==NULL;
        }
};

class Node
{
    int data;
    Node *left, *right;

public:
    Node() {}
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
    friend class BinaryTree;
};

class BinaryTree
{
    Node *root;

public:
    BinaryTree()
    {
        root = NULL;
    }

    Node *get_root()
    {
        return root;
    }

    Node *create()
    {
        int val;
        cout << "enter data(-1 if no child)=";
        cin >> val;
        if (val == -1)
            return 0;
        Node *newnode = new Node(val);
        if (root == NULL)
            root = newnode;
        cout << "left child of " << val << endl;
        newnode->left = create();
        cout << "right child of " << val << endl;
        newnode->right = create();

        return newnode;
    }

    void create2(Node *newnode)
    {
        if (root == NULL)
        {
            root = newnode;
            cout << "\nRoot Created Successfully" << endl;
        }
        else
        {
            Node *temp = root; // Traversing Node
            while (true)
            {
                int option;
                cout << "\nYou are at node: " << temp->data << endl;
                cout << "\n1.Go to left\t 2.Go to right\t 5.Exit" << endl;
                cin >> option;
                if (option == 1)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = newnode;
                        cout << newnode->data << " is left child of node " << temp->data << endl;
                        break;
                    }
                    else
                        temp = temp->left;
                }
                else if (option == 2)
                {
                    if (temp->right == NULL)
                    {
                        temp->right = newnode;
                        cout << newnode->data << " is right child of " << temp->data << endl;
                        break;
                    }
                    else
                        temp = temp->right;
                }
            }
        }
    }

    void inorder(Node *temp)
    {
        if (temp == NULL)
            return;
        inorder(temp->left);
        cout << temp->data << "  ";
        inorder(temp->right);
    }

    void preorder(Node *temp)
    {
        if (temp == NULL)
        {
            return;
        }

        cout << temp->data << "   ";
        preorder(temp->left);
        preorder(temp->right);
    }

    void postorder(Node *temp)
    {
        if (temp == NULL)
            return;
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << "   ";
    }

    void inor()
    {
        Stack<Node *> st;
        Node *temp = root;
        while (1)
        {
            if (temp != NULL)
            {
                st.push(temp);
                temp = temp->left;
            }

            else
            {
                if (st.isEmpty())
                    break;
                cout << st.Top()->data << "  ";
                temp = st.Top()->right;
                st.pop();
                

                // temp = temp->right;
            }
        }
    }

    void preo()
    {
        Node *temp = root;
        Stack<Node *> st;
        while (1)
        {
            if (temp != NULL)
            {
                cout << temp->data << "  ";
                st.push(temp);
                temp = temp->left;
            }
            else
            {
                if (st.isEmpty())
                    break;
                temp = st.Top()->right;
                st.pop();
            }
        }
    }

//Recursive 
    int height(Node *current)
    {
        if (current == NULL)
            return 0;
        int lh = height(current->left);
        int rh = height(current->right);
        return 1 + max(lh, rh);
    }
//Non-recursive
    int height2(Node *current)
    {
        if (current == NULL)
            return 0;
        else if (current->right == NULL && current->left == NULL)
            return 1;
        else if (current->right == NULL)
        {
            return 1 + height2(current->left);
        }
        else if (current->left == NULL)
        {
            return 1 + height2(current->right);
        }
        else
        {
            int l = 1 + height2(current->left);
            int r = 1 + height2(current->right);

            return max(l, r);
        }
    }
 
    void mirror()
    {
        // Queue<Node*> q;
        queue<Node*>q;
        q.push(root);
        while (!q.empty())
        {
            Node*front =q.front();
            q.pop();

            if (front->left != NULL && front->right != NULL)
            {
                q.push(front->right);
                q.push(front->left);
            }
            else if (front->right != NULL)
            {
                q.push(front->right);
            }
            else if (front->left != NULL)
            {
                q.push(front->left);
            }

           //or swap only data
            Node*temp=front->right;
            front->right=front->left;
            front->left=temp;
        }
    }

};

int main(int argc, char const *argv[])

{
    BinaryTree b;
    int choice;
    while(1)
  {  cout<<"\nMenu\n1:create\n2:traversal\n3:height  "<<"\n";
    cout<<"Enter your choice: ";
    cin>>choice;

    switch (choice)
    {
    case 1:
        cout<<"\n1:recursive way\n2:non recursive way=";
        cin>>choice;
        if(choice==1)  Node*root=b.create();
        else
        {
            while (1)
            {
                 cout<<"\nenter data=(-1 for no node)=";int val;cin>>val;
                 if(val==-1)  break;
        Node *newnode = new Node(val);
        b.create2(newnode);
            }  
        }
        break;

    case 2:
        cout<<"1:preorder recursive\t2:preorder non recursive\n";
        cout<<"3:inorder recursive\t4:inorder non recursive\n";
        cout<<"5:postorder recursive\t6:postorder non recursive\n";

        cin>>choice;
        if(choice==1) b.preorder(b.get_root());
        else  if(choice==2) b.preo();
        else if(choice==3) b.inorder(b.get_root());
        else if(choice==4)  b.inor();
        else if(choice==5)  b.postorder(b.get_root());
        break;
        
    case 3:
    cout<<"\nheight of tree is= "<<b.height(b.get_root())<<endl;
    break;

    
    default:
        break;
    }}
    return 0;
}