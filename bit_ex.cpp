#include "lib.h"
int bit[110];
void update(int idx, int val, int n)
{
    for(int p = idx; p <= n; p += (p & -p))
    {
        bit[p] += val;
    }
}
int query(int p)
{
    int ans = 0;
    for(int i = p; i; i -= (i & -i))
    ans += bit[i];
    return ans;
}
void test_update(int arr[], int idx, int val)
{
    arr[idx] += val;
}
int test_query(int arr[], int p)
{
    int ans = 0;
    for(int i = 1; i <= p; i ++)
    ans += arr[i];
    return ans;
}
int main()
{
    numberGenerator gen;
    const int numElement = 100;
    int arr[numElement] = {0};
    int bit[numElement] = {0};
    int queryNum = 1000;
    while(queryNum --)
    {
        int q = gen.generateANumberInRange(0, 100);
        if(q <= 70)
        q = 0;
        else
        q = 1;
        if(q == 0)
        {
            int idx = gen.generateANumberInRange(1, numElement - 1);
            int val = gen.generateANumberInRange(0, 1000); 
            update()
        }
    }
}