#include<bits/stdc++.h>
using namespace std;

// Removing a particular edge the graph is broken into 2 or more components
/*
creating 2 arrays : time of insertion[] and lowest time of insertion[]
dfs problem
*/

const int N = 2e5;
vector<int> adj[N];

void bridge(int node,int parent,vector<int>& tim, vector<int>& low,vector<int>& vis,int& timer){
    vis[node] = 1;
    tim[node] = low[node] = timer++;
    for(auto it:adj[node]){
        if(it==parent) continue;
        if(!vis[it]){
            bridge(it,node,tim,low,vis,timer);
            if(low[it]>tim[node]){
                cout << node << " " << it << endl;
            }
            low[node] = min(low[node],low[it]);  
        }
        else{
            low[node] = max(low[node],tim[it]); // directly to ancestor 
            low[node] = min(low[node],low[it]); // ancestor of ancestor
        }
    }
}

void solve(){ 
    int n; 
    vector<int> tim(n,-1);
    vector<int> low(n,-1);
    vector<int> vis(n,0);
    int timer = 0;
    bridge(0,-1,tim,low,vis,timer); 
}
 
int32_t main(){
    int t;
    t=1;
    cin >> t;
    while (t--){
        solve();
    }
}



























