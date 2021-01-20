#include<iostream>
using namespace std;
const int M = 60000;
int force_solution(int arr[], int n)
{
    int ans = 0;
    for(int i = 0; i < n - 1; i ++)
    {
        for(int j = i + 1; j < n; j ++)
        if(arr[i] > arr[j])
        ans ++;
    }
    return ans;
}
int main()
{
//    freopen("inp.txt", "r", stdin);
    int n, arr[M];
    cin >> n;
    for(int i = 0; i < n; i ++)
    cin >> arr[i];
    cout << force_solution(arr, n);
}