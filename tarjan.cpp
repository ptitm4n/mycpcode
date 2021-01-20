#include "mylib.h"
const int MN = 101;
int m, n, adjm[MN][MN] = {0}, order = 1, available[MN] = {0}, low[MN], number[MN] = {0}, stconnected = 1;
stack<int> st;
void readInput()
{
    int t1, t2;
    cin >> n >> m;
    loope(i, 1, m)
    {
        cin >> t1 >> t2;
        adjm[t1][t2] = 1;
    }
}


void dfs(int u)
{
    low[u] = order;
    number[u] = order ++;
    st.push(u);
    loope(i, 1, n)
    {
        if(adjm[u][i] && available[i] == 0)
        {
            if(number[i] != 0)
            low[u] = min(low[u], number[i]);
            else
            {
                dfs(i);
                low[u] = min(low[u], low[i]);
            }
        }
    }
    if(low[u] == number[u])
    {
        cout << "Strongly Connected number " << stconnected ++ << endl;
        int sttop = 0;
        do
        {
            sttop = st.top();
            cout << sttop << " ";
            available[sttop] = 1;
            st.pop();

        }while(sttop != u);
        cout << endl;
    }

}

void solve()
{
    loope(i, 1, n)
    {
        if(number[i] == 0)
        dfs(i);
    }
}

int main()
{
    init();
    readInput();
    solve();
}