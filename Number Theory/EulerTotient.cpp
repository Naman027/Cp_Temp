#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<long long> computeTotient(int n){
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
    return phi;
}

// phi will return the numbers of k such that 1<=k<=n and gcd(k,n) = 1.

ll phi(ll n){
	int res = n;
	for (int i = 2; i * i <= n; i++){
		if (n % i == 0){
			while (n % i == 0)
				n /= i;
			res -= res / i;
		}
	}
	if (n > 1)
		res -= res / n;
	return res;
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

int main(){
    int n  = 10;
    vector<long long> v = computeTotient(n);
    for(long long a:v) cout << a << endl;
}

