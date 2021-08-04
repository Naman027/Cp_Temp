#include<bits/stdc++.h>
using namespace std;


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

