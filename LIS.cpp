#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
 
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_map tree<pair<int, int>, null_type, less<pair<int, int>>,rb_tree_tag, tree_order_statistics_node_update>
*/
 
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
#define all(v) v.begin(),v.end()
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll,vector<ll>,greater<ll>>
const ll INF=1e18;
const double PI=4*atan(1);
const double eps=1e-8;
 
#define SpeedForce               \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                    \
    cout.tie(0);
 
using namespace std;
 
int dx[]={-1,0,1,0,-1,1,1,-1};
int dy[]={0,1,0,-1,1,1,-1,-1};
 
// Longest Increasing Sequence
int LIS(vector<int>& a){
    int n = a.size();
    vector<int> lis;
    for(int i=0;i<n;i++){
        int ind = lower_bound(lis.begin(),lis.end(),a[i])-lis.begin();
        if(ind==lis.size()){
            lis.push_back(a[i]);
        }
        else lis[ind] = a[i];
    }
    return lis.size();
}

// Longest non decreasing sequence
int LNDS(vector<int>& a){
    int n = a.size();
    vector<int> lnds;
    for(int i=0;i<n;i++){
        int ind = upper_bound(lnds.begin(),lnds.end(),a[i])-lnds.begin();
        if(ind==lnds.size()){
            lnds.push_back(a[i]);
        }
        else lnds[ind] = a[i];
    }
    return lnds.size();
}

