#include "mylib.h"
const int M = 1e4;
int K;
struct query{
    int l;
    int r;

    bool operator< (const query& q)
    {
        if(l/K == q.l / K)
        return r < q.r;
        return l < q.l;
    }
};

void solve_by_mo(int arr[], int tn, int tq, query queries[])
{
    K = sqrt(tn);
    sort(queries, queries + tq);
    query previous;
    previous.l = 0;
    previous.r = 0;
    loop(i, tq)
    {
        cout << "query :" << i << " start = " << queries[i].l << " end = " << queries[i].r << endl; 
        
    }
}

void test_generate()
{
    int arr[M], tn, tq;
    query queries[M];

    tn = r(1, M); 
    tq = r(1, M);
    cout << tn << " " << tq << endl;
    loop(i, tq)
    {
        cout << "generate query " << i << " ";
        queries[i].l = r(0, tn - 1);
        queries[i].r = r(queries[i].l, tn - 1);
        cout << "start = " << queries[i].l << " end = " << queries[i].r << endl;
    }

    solve_by_mo(arr, tn, tq, queries);
}
int main()
{
    freopen("mo_output.txt", "w", stdout);
    init();
    test_generate();
}