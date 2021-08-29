#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    int n;
    cin >> n;

    // 1. __builtin_popcount(x) -- no of set bits (one's) 
    int a = __builtin_popcount(n);
    cout << a << endl;

    ll b = __builtin_popcountll(n);
    cout << b << endl;

    // 2. __builtin_parity(x) -- 1 if x is odd and 0 if x is even
    a  =  __builtin_parity(n);
    cout << a << endl;

    // 3. __builtin_clz(x) -- no of leading zeroes
    a  = __builtin_clzll(n);
    cout << a << endl;
    
    // 4. __builtin_ctz(x) -- no of trailing zeroes
    a = __builtin_ctzll(n);
    cout << a << endl;

}

