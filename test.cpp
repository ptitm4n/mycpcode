#include "mylib.h"

using namespace std;
int count_unique_substrings(string const& s)
{
    int n = s.size();

    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n); 
    p_pow[0] = 1;

    for(int i = 1; i < n; i ++)
    p_pow[i] = (p_pow[i - 1] * p) % m;

    vector<long long> h(n + 1, 0);
    
}
int main()
{

}