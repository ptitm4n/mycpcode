#include "mylib.h"
const int M = 1e6;
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(){
    }
    Node(int data)
    {
        this -> data = data;
        left = right = 0;
    }
};

Node* insertNode(Node* root, int key)
{
    if(!root)
    {
        return new Node(key);
    }

    if(root -> data < key)
    root -> right = insertNode(root -> right, key);
    else if(root -> data > key)
    root -> left = insertNode(root -> left, key);

    return root;
}

bool checkBst(Node* root)
{
    if(!root)
    return true;
    int tempt = root -> data;
    if(root -> left && root -> left -> data > tempt)
    return false;

    if(root -> right && root -> right -> data < tempt)
    return false;

    if(checkBst(root -> left) && checkBst(root -> right))
    return true;
    return false;
}

Node* searchNode(Node* root, int key)
{
    if(!root || root -> data == key )
    return root;

    if(root -> data < key)
    return searchNode(root -> right, key);
    else if(root -> data > key)
    return searchNode(root -> left, key);

}

void testInsert(Node*& root, vector<int>& inserted)
{
    int tc =  1000;
    while(tc --)
    {
        int iv = r(1, M);
        inserted.push_back(iv);
        root = insertNode(root, iv);
    }

    if(checkBst(root))
    cout << "Pass test insert" << endl;
    else
    cout << "Not pass test insert" << endl;

    cout << "Root Info " << root << endl; 
}

bool isInVector(vector<int> inserted, int searchV)
{
    vector<int>::iterator res = lower_bound(inserted.begin(), inserted.end(), searchV);
    if(res != inserted.end() && *res == searchV)
    return true;
    return false;
}

void testSearchNode(Node* root, vector<int> inserted)
{
    int tc = 1e4, tempt;
    while(tc --)
    {
        int toss = r(0, 1);
        cout << "Toss = " << toss << endl; 
        if(!toss)
        {
            tempt = r(1, M);
            while(isInVector(inserted, tempt))
            {
                tempt = r(1, M);
            }
            cout << "Find Value = " << tempt << endl;
            Node* sNode = searchNode(root, tempt);
            cout << "Result = " << sNode << endl;
            if(sNode)
            {
                cout <<"Not pass test search Node" << endl;
                return;
            }
        }else{
            tempt = r(0, inserted.size() - 1);
            cout << "Find value = " << inserted[tempt] << endl;
            Node* sNode = searchNode(root, inserted[tempt]);
            cout << "Result = " << sNode << endl;
            if(!sNode || sNode -> data != inserted[tempt])
            {
                cout << "Not pass test search Node" << endl;
                return;
            }
        }
    }
    cout << "Pass test search Node" << endl;
}

void treeTraversal(Node* root)
{
    if(!root)
    return;
    treeTraversal(root -> left);
    cout << "Value Node " << root -> data << endl;
    treeTraversal(root -> right);
}

int main()
{
    srand(time(0));
    freopen("output.txt", "w", stdout);
    Node* root = 0;
    vector<int> inserted;
    testInsert(root, inserted);
    cout << "Root info " << root << endl;
    //cout << "Try to traversal binary search tree" << endl;
    treeTraversal(root);
    sort(inserted.begin(), inserted.end());
    testSearchNode(root, inserted);
}