#include<iostream>
#include<vector>
using namespace std;

#define LL long long
struct FenwickTree{
    int n;
    vector<LL> vec;
    FenwickTree(int n): n(n) , vec(n + 1, 0) {}

    int get(int x)
    {
        int result = 0;
        for(; x <= n; x += x & -x)
        result += vec[x];
        return result;
    }

    void set(int x)
    {
        for(; x >= 1; x -= x & -x)
        vec[x] ++;
    }
};

int main(){
//    freopen("inp.txt", "r", stdin);
    int n;
    cin >> n;
    FenwickTree f(60000);
    LL result = 0;
    while(n --)
    {
        LL x;
        cin >> x;
        result += f.get(x + 1);
        f.set(x);
    }
    cout << result;
    return 0;
}