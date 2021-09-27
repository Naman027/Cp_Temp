#include<bits/stdc++.h>
using namespace std;
#define SpeedForce               \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                    \
    cout.tie(0);

const int N = 2e5;
/*
1. Low Link Value relation
2. Maintaining an onStack array so that correct SCC component could be found out
3. Same low link value will give that SCC component 
*/

void dfs(int node,vector<vector<int>>& g,vector<int>& vis,vector<int>& onStack,vector<int>& in,vector<int>& low,int& timer,stack<int>& s,int & SCC){
    vis[node] = 1;
    in[node] = low[node] = timer++;
    onStack[node] = 1;
    s.push(node);

    for(auto ch:g[node]){
        if(vis[ch] && onStack[ch]){
            low[node] = min(low[node],in[ch]);
        }
        else if(!vis[ch]){
            dfs(ch,g,vis,onStack,in,low,timer,s,SCC);
            if(onStack[ch])
                low[node] = min(low[node],low[ch]); 
        }
    }

    if(in[node]==low[node]){
        SCC++;
        cout << "SCC #" << SCC << endl; 
        while(1){
            int cur = s.top();
            s.pop();
            onStack[cur] = 0;
            cout << cur << " ";
            if(cur==node) break;
        }
        cout << endl;
    }
}

int32_t main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    for(int i = 0; i < m; i++){
        
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    vector<int> vis(n+1,0),onStack(n+1,0);
    vector<int> in(n+1,0),low(n+1,0);
    int timer = 1;
    int SCC = 0;
    stack<int> s;
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i,g,vis,onStack,in,low,timer,s,SCC);
    }

}
