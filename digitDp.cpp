#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
 
#define endl '\n'
#define loop(i,m,n) for(int i=m;i<n;i++)
#define loope(i,m,n) for(int i=m;i<=n;i++)
#define epool(i,m,n) for(int i=m;i>=n;i--)
#define mod 1000000007
#define mod2 998244353                                                                       
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define vi vector<int>
#define vl vector<ll>
#define empf emplace_front
#define empb emplace_back
#define ret(x) return cout << x,0;
#define all(v) v.begin(),v.end() 
#define umap unordered_map<ll,ll>
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll,vector<ll>,greater<ll>>
#pragma pack(1)
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
 
ll dp[10][2][81];

bool isprime(ll n){
    if(n==1) return 0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}

ll G(string str, ll pos=0, ll sum = 0, ll tight = 1){
    if(pos==str.size()){
        if(isprime(sum)) return 1;
        return 0;
    }

    if(dp[pos][tight][sum]!=-1) return dp[pos][tight][sum];
    ll ans = 0;
    if(tight==1){
        for(ll i=0;i<=str[pos]-'0';i++){
            if(i==str[pos]-'0'){
                ans+=G(str,pos+1,sum+i,1);
            }
            else{
                ans+=G(str,pos+1,sum+i,0);
            }
        }
    }
    else{
        for(int i=0;i<=9;i++){
            ans+=G(str,pos+1,sum+i,0);
        }
    }

    return dp[pos][tight][sum] = ans; 
}

void solve(){  
    ll l,r;
    cin >> l >> r;
    l--;
    string a = to_string(l);
    string b = to_string(r);
    memset(dp,-1,sizeof(dp));
    ll rr = G(b);
    memset(dp,-1,sizeof(dp));
    ll lr = G(a);

    cout << rr-lr << endl;
    
}
 
int32_t main(){
    SpeedForce
    int t;
    t=1;
    cin >> t;
    //cerr << endl;
    int cnt=1;
    while (t--){
        //cout << "Case #" << cnt << ": ";
        //cout << fixed << setprecision(6);
        solve();
        cnt++;
    }
    //cerr << "Time : " << 1000*((double)clock())/ (double)CLOCKS_PER_SEC << "ms" << endl;
 
}