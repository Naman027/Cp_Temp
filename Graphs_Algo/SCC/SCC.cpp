#include<bits/stdc++.h>
using namespace std;
#define SpeedForce               \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                    \
    cout.tie(0);

const int N = 2e5;
vector<int> adj[N];
vector<int> transpose[N];

// Kosaraju's Algorithm for SCC
/*
1. Sort -- Idea of topological Sort ( may be cycle present)
2. Transpose the graph
3. do DFS according to toposort order
*/

void dfs(int node,stack<int>& st,vector<int>& vis){
    vis[node] = 1;
    for(auto it:adj[node]){
        if(!vis[it]) dfs(it,st,vis);
    }
    st.push(node);
}

void revDfs(int node,vector<int>& vis){
    cout << node << " ";
    vis[node] = 1;
    for(auto it:transpose[node]){
        if(!vis[it]){
            revDfs(it,vis);
        }
    }
}

void solve(){ 
    int n,m;
    for(int i=0;i<m;i++){
        int u,v;
        adj[u].push_back(v);
    }
    
    stack<int> st;
    vector<int> vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]) dfs(i,st,vis);
    }

    for(int i=0;i<n;i++){
        vis[i] = 0;
        for(auto it:adj[i]){
            transpose[it].push_back(i);
        } 
    }

    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            revDfs(node,vis);
            cout << endl;
        }
    }
}
 
int32_t main(){
    SpeedForce
    int t;
    t=1;
    cin >> t;
    while (t--){
        solve();
    }
}



























