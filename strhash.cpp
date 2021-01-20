#include "mylib.h"
#define ll long long
const int M = 1e4;
const ll base = 311, mod = 1e9 + 9;
void test_generate(int &len, char s[])
{
    len = 10;
    cout << "len = " << len << endl;
    loop(i,len)
    {
        s[i] = 'a' + r(0, 25);
    }
    s[len] = 0;
    cout << "Generated string" << endl;
    cout << s << endl;
}
void hashstr(char s[], ll p[], ll hv[])
{
    int dem = 0;
    p[dem] = 1;
    hv[dem] = s[dem] - 'a' + 1;
    while(s[ ++dem])
    {
        p[dem] = (p[dem - 1] * base) % mod;
        hv[dem] = hv[dem - 1] * base + (s[dem] - 'a' + 1);
        hv[dem] %= mod;
    }
}

ll getHash(ll p[], ll hv[], int i, int j)
{
    return (hv[j] - hv[i - 1] * p[j - i + 1] + mod * mod) % mod; 
}

ll test_getAns(char str[], int s, int e)
{
    ll ans = 0;
    ll p = 1;
    loope(i, s, e)
    {
        ans = ans * base + (str[i] - 'a' + 1);
        ans %= mod;
        p *= base;
    }
    return ans;
}

void test(char s[], ll p[], ll hv[], int len)
{
    hashstr(s, p, hv);
    int tc = r(1, 100);
    while(tc --)
    {
        cout << "TC = " << tc << endl;
        int start = r(0, len - 1);
        int end = r(start, len - 1);
        cout << "start = " << start << " end = " << end << endl;
        cout << "string need to calculate " << endl;
        loope(i, start, end)
        cout << s[i];
        cout << endl;
        ll ans = test_getAns(s, start, end);
        ll ourans = getHash(p, hv, start, end);
        cout << "Ans = " << ans << " our ans = " << ourans << endl;
        cout << "Status "; 
        if(ans == ourans)
        cout << "Correct"; 
        else
        cout <<"InCorrect";
        cout << endl;
    }
}

int main()
{
    init();
    freopen("output.txt", "w", stdout);
    int len;
    char s[M + 5];
    ll p[M + 5], hv[M + 5];
    test_generate(len, s);
    test(s, p, hv, len);
}