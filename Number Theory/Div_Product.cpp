#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+5;

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

vector<ll> p(N);

void precompute(){
    p[0] = 0; p[1] = 1;
    for(ll i = 2; i < N; i++) {
        if(p[i] == 0) {
            p[i] = 2;
            for(ll j = 2*i; j < N; j += i) {
                if(p[j] == 0) p[j] = 1;
                ll tmp = j;
                ll cnt = 0;
                while(tmp % i == 0) {
                    cnt += 1;
                    tmp /= i;
                }
                p[j] *= (cnt + 1);
            }
        }
    }

    for(int i = 2; i < N; i++) {
        p[i] = (mpow(i, p[i]/2)%mod * (p[i]&1 ? (ll)sqrt(i) : 1)%mod)%mod;
    }
}

ll product_divisors(ll n){
    return p[n];
}


