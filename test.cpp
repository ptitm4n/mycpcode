#include "mylib.h"

struct Node{
    int data;
    Node* left;
    Node* right;
    Node()
    {
    }
    Node(int data)
    {
        this -> data = data;
        left = right = 0;
    }
};
void change1(Node* node)
{
    cout << "Node Info " << (&node) << endl;
    node = new Node(1);
}

void change(Node*& node) 
{
    cout << "Node Info " << (&node) << endl;
    change1(node);
}

void printNode(Node* node)
{
    cout << "Node " << node << " Address " << (&node) << " Left " << (node -> left)  << " Right " << (node -> right) << endl;
}

void printRealNode(Node*& node)
{
    cout << "Node " << node << " Address " << (&node) << " Left " << (node -> left)  << " Right " << (node -> right) << endl;
}

int main()
{
    Node* node = new Node(1);
    node -> left = new Node(2);
    node -> right = new Node(3);
    printNode(node);
    printRealNode(node);

}