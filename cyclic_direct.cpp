#include <iostream>
#include <vector>
using namespace std;


 // } Driver Code Ends


/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
int isAdj(vector<int> adj[], int s, int e)
{
    for(int i = 0; i < adj[s].size(); i ++)
    {
        if(adj[s][i] == e)
        return 1;
    }
    return 0;
}

int isAdjacent(vector<int> adj[], int s, int e)
{
    for(int i = 0; i < adj[s].size(); i ++)
    if(adj[s][i] == e)
    return 1;
    return 0;
}
int res = 0;

void dfs(int finished[], vector<int> adj[], int v, int nv)
{
    if(res == 1)
    return;
    finished[v] = 1;
    for(int i = 0; i < nv; i ++)
    {
        if(finished[i] != 2 && isAdjacent(adj, v, i))
        {
            if(finished[i] == 1)
            {
                res = 1;
                return;
            }else{
                dfs(finished, adj, i, nv);
            }
        }
    }
    finished[v] = 2;
}
bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    res = 0;
    int finished[1000] = {0};
    for(int i = 0; i < V; i ++)
    {
        if(res == 1)
        break;
        
        if(finished[i] == 0)
        dfs(finished, adj, i, V);
    }
    if(res == 0)
    return false;
    return true;
}

// { Driver Code Starts.

int main() {
    freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	
	while(t--){
	    
        res = 0;
	    int v, e;
	    cin >> v >> e;
        cout << v << " " << e << endl;
	    vector<int> adj[1000];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends