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

void init()
{
    srand(time(0));
    freopen("input.txt", "r", stdin);
}

int r(int s, int e)
{
    return s + rand() % (e - s + 1);
}