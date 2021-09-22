#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

#define endl '\n'
#define loop(i,m,n) for(int i=m;i<n;i++)
#define loope(i,m,n) for(int i=m;i<=n;i++)
#define mod 1000000007
#define mod2 998244353                                                                       
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define vt vector
#define sz(x) (int)x.size()
const int maxN = 20;

void dfs1(ll node,vt<ll>& parent,vt<vt<ll>>& g,vt<ll>& vis,vt<vt<ll>>& LCA,vt<ll>& level){
    vis[node] = 1;
    for(auto ch:g[node]){
        if(!vis[ch]){
            level[ch] = level[node]+1;
            parent[ch] = node;
            LCA[ch][0] = node;
            dfs1(ch,parent,g,vis,LCA,level);
        }
    }
}

void init(vt<vt<ll>>& LCA,ll n){
    for(int j=1;j<=maxN;j++){
        for(int i=1;i<=n;i++){
            if(LCA[i][j-1]!=-1){
                ll par = LCA[i][j-1];
                LCA[i][j] = LCA[par][j-1];
            }
        }
    }
}

ll findLCA(ll u,ll v,vt<vt<ll>>& g,vt<vt<ll>>& LCA,vt<ll>& level){
    if(level[v]<level[u]) swap(u,v);
    ll d = level[v]-level[u];

    for(int i=0;i<maxN;i++){
        if((d&(1<<i))) v = LCA[v][i];
    }

    if(u==v) return u;
    for(int i=maxN-1;i>=0;i--){
        if(LCA[u][i]!=LCA[v][i]){
            u = LCA[u][i];
            v = LCA[v][i];
        }
    }
    return LCA[u][0];
}


