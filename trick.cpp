#include<iostream>

#define endl "\n"
#define debug(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int kiemtrale(int i)
{
    return i&1;
}

void swap(int* a, int* b)
{
    (*a) ^= (*b);
    (*b) ^= (*a);
    (*a) ^= (*b);
}

int nhan2n(int i, int n)
{
    return i << n;
}

int chia2n(int i, int n)
{
    return i >> n;
}

void sinhnhiphan(int n)
{
    for(int i = 0; i < (1 << n); i ++)
    {
        for(int j = 0; j < n; j ++)
        cout << ((i >> j) & 1) << " ";
        cout << endl;
    }
}
int main()
{
    sinhnhiphan(3);
}