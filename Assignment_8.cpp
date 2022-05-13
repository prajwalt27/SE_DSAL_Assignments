#include <iostream>
#include <queue>
#include<stack>
using namespace std;

class Node
{
    int d;
    Node *next;

public:
    Node()
    {
        d = -1 ;
        next = NULL;
    }
    Node(int data)
    {
        d = data;
        next = NULL;
    }
    friend class Graph;
};

class Graph
{
    Node **adjlist;
    bool *visited;
    int v, e;

public:
    Graph(int v, int e)
    {
        this->v = v;
        this->e = e;
        adjlist = new Node *[v];
        visited=new bool[v];
        for (int i = 0; i < v; i++)
        {
            adjlist[i]=NULL;
            visited[i] = 0;
        }
    }
    void create()
    {
        for (int i = 0; i < e; i++)
        {
            int source, destination;
            cout << "enter source and destination=";
            cin >> source >> destination;
           
            Node*newnode=new Node(destination);

            //********how*********
            // newnode->next=adjlist[source];
            // adjlist[source]=newnode;

            Node*temp=adjlist[source];
            if(temp==NULL)
            {
                adjlist[source]=newnode;
                continue;
            }
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }



    void calcuIndegrees(int inDegree[])
    {
        for(int i=0;i<v;i++)
        {
            int cnt=0;
            if(adjlist[i]==NULL)
            continue;
            
                Node*temp=adjlist[i];
                while(temp!=NULL)
                {
                    inDegree[temp->d]++;
                    temp=temp->next;
                }   
        }
    }

    void topo_queue(int inDegree[])
    {
        queue<int>q;
        // q.push(1);
        q.push(4);


        while(!q.empty())
        {
            int curr=q.front();
            cout<<curr<<"  ";
            q.pop();
            Node*temp=adjlist[curr];
            while(temp!=NULL)
            {
                inDegree[temp->d]--;
                if(inDegree[temp->d]==0)
                q.push(temp->d);
                temp=temp->next;
            }
        }
    }

    void topoWithoutDS(int inDegree[])
    {
        int visited[v]={0};
        for(int i=0;i<v;i++)  //we want v edges to print
        {
            for(int j=0;j<v;j++)  //access every vertex
            {
                if(inDegree[j]==0 && visited[j]==0)
                {   cout<<j<<"  ";
                     visited[j]=1;  //removed from concideration
                    Node*temp=adjlist[j];
                    if(temp==NULL) continue;
                    while(temp!=NULL)
                    {
                        inDegree[temp->d]--;
                        temp=temp->next;
                    }
                }
            
            }
        }
    }
    void topo()
    {
        int inDegree[v]={0};
        calcuIndegrees(inDegree);
        cout<<"1:using queue\n2:without Data structure=";
        int choice;cin>>choice;
        if(choice==1)
        topo_queue(inDegree);
        else
        topoWithoutDS(inDegree);
    }


    void display()
    {
        Node *temp = NULL;
        for (int i = 0; i < v; i++)
        {
            if (adjlist[i]==NULL)
            {
                cout<<"No connected node for:" << i <<" \n";
                continue;
            }
            cout << i << " -->";
            temp =adjlist[i];
            while (temp!= NULL)
            {
                cout << temp->d<<"  ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
    int v, e;
    cout << "enter number of vertices=";
    cin >> v;
    cout << "number of edges=";
    cin >> e;
    Graph g(v, e);
    g.create();
    g.display();
    g.topo();

    return 0;
}
