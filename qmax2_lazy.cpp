#include<iostream>
#include<cstdlib>
#include<ctime>


using namespace std;
const int MAXN = 50000;
int testarr[MAXN] = {0};
void test_query1(int u, int v, int val)
{
    for(int i = u; i <= v; i ++)
    testarr[i] += val;
}

int test_query2(int u, int v)
{
    int curM = 0;
    for(int i = u; i <= v; i ++)
    if(testarr[i] > curM)
    curM = testarr[i];
    return curM;
}

int taosongaunhien(int start, int end)
{
    return start + rand() % (end - start + 1);
}
struct Node{
    int lazy;
    int val;
} nodes[MAXN * 4];
void down(int id)
{
    int t = nodes[id].lazy;
    int left = id << 1;
    int right = left + 1;
    nodes[left].lazy += t;
    nodes[left].val += t;
    nodes[right].lazy += t;
    nodes[right].val += t;
    nodes[id].lazy = 0;
}
int max(int a, int b)
{
    return a > b ? a : b;
}
void update(int id, int l, int r, int u, int v, int val)
{
    if(u > r || v < l)
    return ;
    if(u <= l && r <= v)
    {
        nodes[id].lazy += val;
        nodes[id].val += val;
        return ;
    }
    down(id);
    int middle = (l + r) >> 1;
    int left = id << 1;
    int right = left + 1;
//    cout<< "debug " << left << " " << right << " " << middle << endl;
    update(left, l, middle, u, v, val);
    update(right, middle + 1, r, u, v, val);
    nodes[id].val = max(nodes[left].val, nodes[right].val);
}
int get(int id, int l, int r, int u, int v)
{
    if(u > r || v < l)
    return -999999;
    if(u <= l && r <= v)
    return nodes[id].val;
    down(id);
    int middle = (l + r) >> 1;
    int left = id << 1;
    int right = left + 1;
//    cout << " u: " << u << " v: " << v << endl;
//    cout << "l: " << l << " r: " << r << endl;
//    cout<< "debug get function "<< id << " " << left << " " << right << " " << middle << endl;
    return max(get(left, l, middle, u, v),
    get(right, middle + 1, r, u, v));
}
int tc = 5000;
int ntest = 10000; 

int main()
{
    srand(time(NULL));
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < tc; i ++)
    {
        int tempt = taosongaunhien(0, 60);
        int query;
        if(tempt <= 40)
        query = 0;
        else
        query = 1;
        if(query == 0)
        {
            int a = taosongaunhien(1, ntest);
            int b = taosongaunhien(a, ntest);
            int c = taosongaunhien(0, 5000);
            cout << query << " " << a << " " << b << " " << c << endl;
            update(1, 1, ntest, a, b, c);
            test_query1(a, b, c);
        }else{
            int a = taosongaunhien(1, ntest - 0);
            int b = taosongaunhien(a, ntest - 0);
            cout << query << " " << a << " " << b << endl;
            int res = test_query2(a, b);
            int res1 = get(1, 1, ntest, a, b);
            if(res == res1)
            cout << "correct "; 
            else
            cout << "incorrect ";
            cout<< res << " " << res1 << endl;
        }
    }

}
int test_main()
{
    return 0;
    int n, t, a, b, c , d;
    freopen("input.txt", "r", stdin);
    cin >> n >> t;
//    cout << n << " " << t << endl;
    for(int i = 0; i < t; i ++)
    {
        cin  >> a;
//        cout << a << endl;
        if(a)
        {
            cin >> b >> c;
//            cout << b << " " << c << endl;
            cout << get(1, 1, n, b, c) << endl;
        }else{
            cin >> b >>  c >> d;
//            cout << b << " " << c << " " << d << endl;
            update(1, 1, n, b, c, d);
        }
    }
}