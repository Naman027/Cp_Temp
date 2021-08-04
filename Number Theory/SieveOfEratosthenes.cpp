#include<bits/stdc++.h>
using namespace std;

vector<bool> SieveOfEratosthenes(int n){
    vector<bool> prime(n+1,true);

    for(int p=2;p*p<=n;p++){
        if(prime[p]){
            for(int i=p*p;i<=n;i+=p){
                prime[i] = false;
            }
        }
    }

    return prime;
}

void segmentedSieve(int n){
    // divide into segments of size sqrt(n)
    int limit = floor(sqrt(n))+1;
    vector<bool> prime;
    prime.reserve(limit);
    prime = SieveOfEratosthenes(limit);
 
    int low = limit;
    int high = 2*limit;
 
    while (low < n){
        if (high >= n)
           high = n;
         
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
 
        for (int i = 0; i < prime.size(); i++){
            int loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
            for (int j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }
 
        for (int i = low; i<high; i++)
            if (mark[i - low] == true)
                cout << i << " ";

        low = low + limit;
        high = high + limit;
    }
}


