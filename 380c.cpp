#include<iostream>

#define endl "\n"
using namespace std;
const int M = 1e6 + 10;
struct Node{
    int left;
    int right;
    int optimal;
    Node(){
        left = 0;
        right = 0;
        optimal = 0;
    }
    Node(int left, int right, int opt)
    {
        this -> left = left; 
        this -> right = right;  
        this -> optimal = opt;    
    }
};
char a[M]; 
Node node[M * 4];
int getLength()
{
    int i = 0;
    while(a[i] != 0)
    i ++;
    return i;
}

Node cong(Node left, Node right)
{
    Node node;

    int minLR = left.left < right.right ? left.left : right.right;  
    node.optimal = left.optimal + right.optimal + minLR;
    node.left = left.left + right.left - minLR;
    node.right = left.right + right.right - minLR;

    return node;
}

void buildTree(int id, int l, int r)
{
    if(l == r)
    {
        if(a[l] == '(')
        node[id].left = 1; 
        else
        node[id].right = 1;
        return;
    }
    int left = (id << 1) + 1; 
    int right = left + 1;
    int canphai = (l + r) >> 1;
    buildTree(left, l, canphai);
    buildTree(right, canphai + 1, r);

    node[id] = cong(node[left], node[right]);
//    cout << id << " " << l << " " << r << " " << node[id].left << " " << node[id].right << " " << node[id].optimal << endl; 
//    cout << left << " " << right << " " << canphai << endl;
}

Node query(int id, int l, int r, int s, int e)
{
//    cout << id <<" " << l << " " << r << " " << s << " " << e << endl;
    if(e < l || s > r)
    return Node(0, 0, 0);

    if(s <= l && r <= e)
    return node[id];

    int left = (id << 1) + 1;
    int right = left + 1;
    int middle = (l + r) >> 1;

    Node nodeLeft = query(left, l, middle, s, e);
    Node nodeRight = query(right, middle + 1, r, s, e);

    return cong(nodeLeft, nodeRight);
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a;
    int length = getLength();
    buildTree(0, 0, length - 1);
 //   cout << endl;
    int n, s, e;
//    cout <<node[7].optimal << endl;
//    cout << query(0, 0, length - 1, 0, 1).optimal << endl;
    cin >> n;
    while(n -- )
    {
        cin >> s >> e;
        cout << query(0, 0, length - 1, s - 1, e - 1).optimal * 2 << endl;
    }
}