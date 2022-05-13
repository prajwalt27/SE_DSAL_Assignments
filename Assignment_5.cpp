#include <iostream>
using namespace std;
class Node
{
    int data;
    Node *next;

public:
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int x)
    {
        data = x;
        next = NULL;
    }
    friend class LL;
};
class LL
{

    Node *head = NULL;
    friend class Hash;

public:
    int search(int key)
    {
        Node *temp = head;
        int flag = 0;
        int comparisons = 1;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                flag = 1;
                break;
            }
            temp = temp->next;
            comparisons++;
        }
        if (flag == 1)
        {
            cout << "Number of comparisons required to search " << key << " are " << comparisons << endl;
        }

        return flag;
    }
    void insertAtHead(int data)
    {
        Node *n = new Node(data);
        n->next = head;
        head = n;
    }
    void insertAtEnd(int data)
    {
        if (!head)
        {
            insertAtHead(data);
            return;
        }
        else
        {
            Node *n = new Node(data);
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }
    }
    void printLL()
    {
        Node *temp = head;

        if (temp == NULL)
        {
            cout << "XXXXXX\n";
            return;
        }
        while (temp != NULL)
        {
            cout << temp->data << " --> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    void deleteAtHead()
    {
        if (!head)
        {
            cout << "\nList is empty already\n";
            return;
        }
        Node *temp = head;
        head = temp->next;
        delete temp;
    }
    void deleteAtEnd()
    {
        if (!head)
        {
            cout << "\nList is empty already\n";
            return;
        }
        Node *temp = head;
        Node *temp2;
        while (temp->next != NULL)
        {
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NULL;
        delete temp;
    }
    void deleteByValue(int value)
    {
        if (value == head->data)
        {
            deleteAtHead();
            return;
        }

        Node *temp = head;
        Node *p;
        while (temp->data != value)
        {
            p = temp;
            temp = temp->next;
        }
        p->next = temp->next;
        delete temp;
    }
};
class Hash
{

    LL obj[10];

public:
    int hashFunc(int x)
    {
        return x % 10;
    }
    void display()
    {
        cout << "\n\n";
        for (int i = 0; i < 10; i++)
        {
            cout << i << "   ";
            obj[i].printLL();
        }
    }
    void insert(int key)
    {

        int x = hashFunc(key);
        obj[x].insertAtEnd(key);
    }
    int search(int value)
    {
        int x = hashFunc(value);
        if (obj[x].search(value) == 1)
        {
            return 1;
        }
        else
            return 0;
    }
    void deleteEntry(int value)
    {
        int x = hashFunc(value);
        if (obj[x].search(value) == 1)
        {
            cout << value << " deleted\n";
            obj[x].deleteByValue(value);
        }
        else
        {
            cout << "No such data present\n";
        }
    }
};
int main()
{
    Hash h;
    char t;
    int value;
    while (true)
    {   cout<<"\n\n---Menu---\n";
        cout << "1.Insert entry in Hash Table\n";
        cout << "2.Search entry in Hash Table\n";
        cout << "3.Delete entry in Hash Table\n";
        cout << "4.Display Hash Table\n";
        cout << "0.Exit\n";
        cout << "Enter your choice:";
        cin >> t;
        switch (t)
        {
        case '0':
            exit(0);
            break;
        case '1':
            cout<<"Enter 10 values\n";
            for (int i = 0; i < 10; i++)
            {
                cout << "Enter input " << i + 1 << ":";
                cin >> value;
                h.insert(value);
            }
            h.display();
            break;
        case '2':
            cout << "Enter the key to be searched:";
            cin >> value;
            if (h.search(value) == 0)
            {
                cout << value << " not present\n";
            }

            break;
        case '3':
            cout << "Enter the value to be deleted:";
            cin >> value;
            h.deleteEntry(value);
            h.display();
            break;

        case '4':
            h.display();
            break;

        default:
            cout << "Invalid input\n";
            break;
        }
    }

    return 0;
}