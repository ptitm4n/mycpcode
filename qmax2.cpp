#include<iostream>
#include<cstdlib>
#include<ctime>

#define MAX_ELEMENT 50000
#define MAX_QUERY 100000
using namespace std;

int n, m, tree[4 * MAX_ELEMENT] = {0}, lazy[4 * MAX_ELEMENT] = {0};
int testarr[MAX_ELEMENT] = {0};
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
void update(int id, int l, int r, int u, int v, int val)
{
    if(v < l || r < u )
    return;

    if(u <= l && r <= v)
    {
//        cout << " cap nhat lazy doan " << l << " " << r << " " << val << endl;
        lazy[id] += val;
        return;
    }

    int left = (id << 1) + 1;
    int right = left + 1;
    int middle = (l + r) >> 1;
    lazy[left] += lazy[id];
    lazy[right] += lazy[id];
    lazy[id] = 0;
    update(left, l, middle, u, v, val);
    update(right, middle + 1, r, u, v, val);

}

int get(int id, int l, int r, int u, int v)
{
    if(l > v || r < u) 
    return 0;

    if(l == r)
    {
        tree[id] += lazy[id];
        lazy[id] = 0;
        return tree[id];
    }

    int left = (id << 1) + 1;
    int right = left + 1;
    int middle = (l  + r) >> 1;
    lazy[left] += lazy[id];
    lazy[right] += lazy[id];
    int leftval = get(left, l, middle, u, v);
    int rightval = get(right, middle + 1, r, u ,v);
    tree[id] = leftval > rightval ? leftval : rightval;
    return tree[id];
}
int tc = 50;
int ntest = 100; 
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
            int a = taosongaunhien(0, ntest - 1);
            int b = taosongaunhien(a, ntest - 1);
            int c = taosongaunhien(0, 5000);
            cout << query << " " << a << " " << b << " " << c << endl;
            update(0, 0, ntest - 1, a, b, c);
            test_query1(a, b, c);
        }else{
            int a = taosongaunhien(0, ntest - 1);
            int b = taosongaunhien(a, ntest - 1);
            cout << query << " " << a << " " << b << endl;
            int res = test_query2(a, b);
            int res1 = get(0, 0, ntest - 1, a, b);
            if(res == res1)
            cout << "correct "; 
            else
            cout << "incorrect ";
            cout<< res << " " << res1 << endl;
        }
    }
}
int example_main()
{
    return 0;
    for(int i = 0; i < 10; i ++)
    cout << taosongaunhien(2, 8) << endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    int type, a, b, c, d;
    for(int i = 0; i < m; i ++)
    {
        cin >> type;
        if(type == 0)
        {
//            cout << "query 1" << endl;
            cin >> a >> b >> c;
            a --;
            b --;
            update(0, 0, n - 1, a, b, c);
        }
        else
        {
//            cout << "query 2" << endl;
            cin >> a >> b;
            a --;
            b --;
            cout << get(0, 0, n - 1, a, b);
        }
    }
}