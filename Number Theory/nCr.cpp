#include<bits/stdc++.h>
using namespace std;
#define ll long long

//Code for nCr using the fermat's theorem

ll mod = 1e9+7;

ll mpow(ll base,ll exp){
    base%=mod;
    ll res = 1;
    while(exp){
        if(exp&1) res*=base;
        res%=mod;
        base = (base*base)%mod;
        exp>>=1;
    }
    return res;
}

ll modInverse(ll n) { 
    return mpow(n, mod-2); 
}

// precomputation of fact is possible.. 
ll nCr(ll n, ll r){ 
   if (r==0) 
      return 1; 
    ll fac[n+1]; 
    fac[0] = 1; 
    for (int i=1 ; i<=n; i++) 
        fac[i] = (fac[i-1]*i)%mod; 
    return ((fac[n]* modInverse(fac[r]) % mod * 
            modInverse(fac[n-r]) % mod)%mod)%mod; 
}

//----------------------------------------------------------------------------------------
