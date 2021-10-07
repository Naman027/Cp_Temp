#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9+7;

ll POW(ll base,ll exp){
    ll result = 1;
    while (exp > 0){
        if (exp & 1)
            result = ((ll)result * base);
        base = ((ll)base * base);
        exp >>= 1;
    }
    return result;
}
//-------------------------------------------------------------------------------------------------

ll mod = 1e9+7; 
ll mpow(ll base, ll exp){
    base %= mod;
    ll result = 1;
    while (exp > 0){
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}
//-------------------------------------------------------------------------------------------------

// GP sum upto n in O(logn)

ll sum_nthGP(ll a,ll r,ll n){
    ll ans = 0;
    while(n){
        if(n&1) ans+=a*pow(r,n);
        a = a+a*r;
        r = r*r;
        n >>= 1;
    }
    return ans;
}

