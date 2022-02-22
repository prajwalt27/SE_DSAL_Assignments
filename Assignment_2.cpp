#include <iostream>
using namespace std;

class TreeNode
{
private:
    string keyword;
    string meaning;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode()
    {
        keyword = "";
        meaning = "";
        left = NULL;
        right = NULL;
    }
    friend class BinarySearchTree;
};

class BinarySearchTree
{
private:
    TreeNode *root;

public:
    BinarySearchTree()
    {
        root = NULL;
    }
    void inserNode(string addkeyword, string addmeaning)
    {
        TreeNode *newn = new TreeNode();
        newn->keyword = addkeyword;
        newn->meaning = addmeaning;
        if (root == NULL)
        {
            root = newn;
        }
        else
        {
            TreeNode *temp = root;
            while (true)
            {
                if (temp->keyword == newn->keyword)
                {
                    cout << "Value already exist, insert another value" << endl;
                    return;
                }

                else if ((newn->keyword < temp->keyword))
                {
                    if (temp->left == NULL)
                    {
                        temp->left = newn;
                        cout << "Keykeyword inserted" << endl;
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }

                else if ((newn->keyword > temp->keyword))
                {
                    if (temp->right == NULL)
                    {
                        temp->right = newn;
                        cout << "Keykeyword inserted" << endl;
                        break;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
        }
    }

    TreeNode *findMeaning(TreeNode *r, string EnteredKey, int cnt)
    {
        if (r == NULL || r->keyword == EnteredKey)
        {
            cout << "Search Comparisons is : " << cnt << endl;
            return r;
        }
        if (r->keyword > EnteredKey)
        {
            cnt++;
            return findMeaning(r->left, EnteredKey, cnt);
        }
        else
        {
            cnt++;
            return findMeaning(r->right, EnteredKey, cnt);
        }
    }

    string findMeaning(string EnteredKey)
    {
        TreeNode *temp = root;
        TreeNode *result = NULL;
        int searchcount = 0;
        result = findMeaning(temp, EnteredKey, searchcount);

        if (result != NULL)
        {
            return result->meaning;
        }
        else
        {
            return "No-KeyWord-Found\n";
        }
    }

    void inorder_rec(TreeNode *r)
    {
        if (r == NULL)
        {
            return;
        }
        else
        {
            inorder_rec(r->left);
            cout << r->keyword << " : " << r->meaning << endl;
            inorder_rec(r->right);
        }
    }

    void inorder_rec()
    {
        if (root == NULL)
        {
            cout << "Tree is empty";
            return;
        }
        inorder_rec(root);
    }

    TreeNode *updateMeaning(TreeNode *r, string EnteredKey)
    {
        if (r == NULL || r->keyword == EnteredKey)
        {
            return r;
        }
        if (r->keyword > EnteredKey)
        {
            return updateMeaning(r->left, EnteredKey);
        }
        else
        {
            return updateMeaning(r->right, EnteredKey);
        }
    }

    void updateMeaning(string EnteredKey, string meaningtoUpdate)
    {
        TreeNode *temp = root;
        TreeNode *result = NULL;
        result = updateMeaning(temp, EnteredKey);

        if (result == NULL)
        {
            cout << "No keyword found\n";
        }
        else
        {
            result->meaning = meaningtoUpdate;
        }
    }

    void descendingOrder(TreeNode *r)
    {
        if (r == NULL)
        {
            return;
        }
        else
        {
            descendingOrder(r->right);
            cout << r->keyword << " : " << r->meaning << endl;
            descendingOrder(r->left);
        }
    }

    void descendingOrder()
    {
        if (root == NULL)
        {
            cout << "No Words in dictionary";
            return;
        }
        descendingOrder(root);
    }

    void deleteLeaf(TreeNode *current, TreeNode *parent)
    {
        cout << "Inside else deleteLeaf\n";
        if (current == root)
        {
            root = NULL;
        }
        else
        {
            cout << "Inside else deleteLeaf\n";
            if (parent->left != NULL)
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }
        }
        delete current;
    }

    void deleteNodeWithSingleChild(TreeNode *current, TreeNode *parent)
    {
        if (current == root)
        {
            if (current->left != NULL)
            {
                root = current->left;
            }
            else
            {
                root = current->right;
            }
        }
        else
        {
            cout << "single else\n";
            if (parent->left == current)
            {
                if (current->left != NULL)
                {
                    parent->left = current->left;
                }
                else
                {
                    parent->left = current->right;
                }
            }
            else
            {
                if (current->left != NULL)
                {
                    parent->right = current->right;
                }
                else
                {
                    parent->right = current->left;
                }
                parent->right = current->right;
                cout << "parent else\n";
            }
        }

        delete current;
    }

    void deleteNodeWithTwoChild(TreeNode *current, TreeNode *parent)
    {
        string tempKey, tempMean;
        TreeNode *temp = NULL;

        cout << "else deleteNodeWithTwoChild\n";
        temp = current->left;
        while (temp->right != NULL)
        {
            parent = temp;
            temp = temp->right;
        }
        tempKey = temp->keyword;
        temp->keyword = current->keyword;
        current->keyword = tempKey;

        tempMean = temp->meaning;
        temp->meaning = current->meaning;
        current->meaning = tempMean;

        if (temp->right == NULL && temp->left == NULL)
        {
            deleteLeaf(temp, parent);
        }
        else if (temp->right == NULL || temp->left == NULL)
        {
            deleteNodeWithSingleChild(temp, parent);
        }
    }

    void deleteNode(TreeNode *r, string keywordtodelete)
    {
        TreeNode *current = r;
        TreeNode *parent = NULL;
        while (current != NULL)
        {
            if (current->keyword == keywordtodelete)
            {
                cout << "Keyword compared...\n";
                if ((current->left == NULL) && (current->right == NULL)) // leaf node
                {
                    cout << "Leaf...\n";
                    deleteLeaf(current, parent);
                    break;
                }
                else if (current->right != NULL && current->left != NULL)
                {
                    deleteNodeWithTwoChild(current, parent);
                    break;
                }
                else if (current->right == NULL || current->left == NULL) // current has single child
                {
                    cout << "Onechild...\n";
                    deleteNodeWithSingleChild(current, parent);
                    break;
                }
            }
            else if (current->keyword > keywordtodelete)
            {
                cout << "Inside left\n";
                parent = current;
                current = current->left;
            }
            else if (current->keyword < keywordtodelete)
            {
                cout << "Inside right\n";
                parent = current;
                current = current->right;
            }
        }
    }

    void deleteNode(string keywordtodelete)
    {
        cout << "Inside deletenode\n";
        TreeNode *temp = root;
        deleteNode(temp, keywordtodelete);
    }
};

int main()
{
    BinarySearchTree bobj;
    char choice;
    string key, meaning, getmeaning, word, updateMean;
    do
    {
        cout << "\nMENU" << endl;
        cout << "1) Insert node" << endl;
        cout << "2) Find meaning" << endl;
        cout << "3) Display in ascending order" << endl;
        cout << "4) Display in descending order" << endl;
        cout << "5) Update Meaning" << endl;
        cout << "6) Delete" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            cout << "Enter the keyword to add in bst: " << endl;
            cin.ignore();
            getline(cin, key);
            cout << "Enter the meaning of " << key << endl;
            getline(cin, meaning);
            bobj.inserNode(key, meaning);
            break;

        case '2':
            cout << "Enter the keyword to find in bst dictionary: " << endl;
            cin.ignore();
            getline(cin, key);
            getmeaning = bobj.findMeaning(key);
            cout << key << " : " << getmeaning;
            break;

        case '3':
            cout << "\nPrinting words in ascending order: " << endl;
            bobj.inorder_rec();
            break;

        case '4':
            cout << "\nPrinting words in descending order: " << endl;
            bobj.descendingOrder();
            break;

        case '5':
            cout << "Enter keyword to change its meaning : " << endl;
            cin.ignore();
            getline(cin, key);
            cout << "Enter the meaning to change: " << endl;
            getline(cin, updateMean);
            bobj.updateMeaning(key, updateMean);
            break;

        case '6':
            cout << "Enter keyword to delete : " << endl;
            cin.ignore();
            getline(cin, key);
            bobj.deleteNode(key);
            break;

        default:
            cout << "Invalid choice. Select[0-6]";
            cout << endl;
            break;
        }
    } while (choice != '0');

    return 0;
}
