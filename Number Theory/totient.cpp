# phi will return the numbers of k such that 1<=k<=n and gcd(k,n) = 1.

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
-----------------------------------------------------------
