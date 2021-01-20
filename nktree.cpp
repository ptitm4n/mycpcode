#include<iostream>

#define FORE(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define FOR(i, b) for(int i = 0; i < b; i++)
#define ll long long 

using namespace std;

const ll MA = (ll) 1 << 32;
ll sosanh[2] = {-MA, MA};
int chengiatri(ll data, ll pre)
{
//    cout << "Insert " << data << endl;
    if(data <= sosanh[0] || data >= sosanh[1])
    return 0;

//    cout << " original min and max value " << sosanh[0] << " " << sosanh[1] << endl;
    if(data > pre)
    sosanh[0] = sosanh[0] < pre ? pre : sosanh[0];
    else
    sosanh[1] = sosanh[1] > pre ? pre : sosanh[1];

//    cout << " update min and max value " << sosanh[0] << " " << sosanh[1] << endl;
    return 1;
}

int main()
{
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll pre;
    ll tempt;
    cin >> pre;

    while(cin >> tempt)
    {
        int res = chengiatri(tempt, pre);
        if(res == 0)
        {
            cout << "NO"; 
            return 0;
        }
        pre = tempt;
    }
    cout << "YES";
}