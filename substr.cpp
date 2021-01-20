#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
#include<stack>
#include<vector>
#define loop(i, e) for(int i = 0; i < e; i ++)
#define loope(i, s, e) for(int i = s; i <= e; i ++)
#define ll long long
using namespace std;
const ll base = 311, mod = 1e9 + 9;
const int M = 1e6 + 2;
ll hv[M], p[M], thash;
ll calHash(string s1, ll hv[], ll p[])
{
    hv[0] = 0;
    p[0] = 1;
    loop(i, s1.size())
    {
        hv[i + 1] = (hv[i] * base + s1[i]) % mod;
        p[i + 1] = (p[i] * base) % mod;
    }
    return hv[s1.size()];
}

ll getHash(ll hv[], ll p[], int s, int e)
{
    return (hv[e] - hv[s - 1] * p[e - s + 1] + mod * mod) % mod; 
}

int main()
{
//    freopen("input.txt", "r", stdin);
    string s1, s2;
    cin >> s1 >> s2;
    thash = calHash(s2, hv, p);
    calHash(s1, hv, p);
    loop(i, s1.size() - s2.size() + 1)
    {
        ll hasv = getHash(hv, p, i + 1, i + s2.size());
        if(hasv == thash)
        cout << i + 1 << " ";
    }
}