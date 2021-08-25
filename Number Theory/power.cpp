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
