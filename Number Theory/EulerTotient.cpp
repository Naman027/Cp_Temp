#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> computeTotient(int n){
    vector<long long> phi(n+1);
    for(int i=1;i<=n;i++) phi[i] = i;

    for(int p=2;p<=n;p++){
        if(phi[p]==p){
            phi[p] = p-1;
            for(int i=2*p;i<=n;i+=p){
                phi[i] = phi[i]*(p-1)/p;
            }
        }
    }
}

ll Euler_totient_function(ll n){
    ll result = 1;
    for (ll i = 2; i * i <= n; i++) {
        ll c = 0;
        if (n % i == 0) {
            while (n % i == 0) {
                c++;
                n /= i;
            }
        }
        if (c > 0) {
            ll power = (ll)pow(i, c - 1);
            ll sm = power* (i - 1);
            result *= sm;
        }
    }
    if (n > 1) result *= (n - 1);
    return result;
}



