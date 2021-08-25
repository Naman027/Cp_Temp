#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e7;

vector<int> prime;
const int maxN = N;

vector<ll> sieveprime(int N){
    vector<ll> prime(N,1);
    for(int p=2;p*p<maxN;p++){
        if(prime[p]){
            for(int i=2*p;i<maxN;i+=p){
                prime[i]=0;
            }
        }
    }
    return prime;
}

void segmentedSieve(int n){
    // divide into segments of size sqrt(n)
    int limit = floor(sqrt(n))+1;
    vector<ll> prime;
    prime.reserve(limit);
    prime = sieveprime(limit);
 
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

//-------------------------------------------------------------------------------------------------

//  spf stores the the least prime divisor of a number i
void sieve(){ 
    spf[1] = 1; 
    for (ll i=2; i<maxN; i++) 
        spf[i] = i; 
    for (ll i=4; i<maxN; i+=2) 
        spf[i] = 2; 
    for (ll i=3; i*i<maxN; i++){  
        if (spf[i] == i){ 
            for (ll j=i*i; j<maxN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
}
//-------------------------------------------------------------------------------------------------

int spf[N + 1];
void linear_sieve(){
	for (int i = 2; i <= N; ++i){
		if (spf[i] == 0){
			spf[i] = i;
			prime.push_back(i);
		}
		for (int j = 0; j < int(prime.size()) && prime[j] <= spf[i] && i * prime[j] <= N; j++)
			spf[i * prime[j]] = prime[j];
	}
}
