#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+5;

vector<ll> p(N);

void precompute(){
    p[0] = 0; p[1] = 1;
    for(ll i = 2; i < N; i++) {
        if(p[i] == 0) {
            p[i] = i+1;
            for(ll j = 2*i; j < N; j += i) {
                if(p[j] == 0) p[j] = 1;
                ll tmp = j;
                ll pow_div = 1; 
                ll summation_div = 1;  // 1+p+p2+p3---
                while(tmp % i == 0) {
                    pow_div *= i;
                    summation_div+=pow_div;
                    tmp /= i;
                }
                p[j] *= summation_div;
            }
        }
    }
}

ll sum_divisors(ll n){
    return p[n];
}

int main(){
    precompute();
    for(int i=1;i<=20;i++) cout << p[i] << " ";
    cout << endl;
}

