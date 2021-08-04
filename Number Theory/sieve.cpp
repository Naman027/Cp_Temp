void sieveprime(){
    memset(prime,true,sizeof(prime));
    for(int p=2;p*p<maxN;p++){
        if(prime[p]){
            for(int i=2*p;i<maxN;i+=p){
                prime[i]=false;
            }
        }
    }
}
-------------------------------------------------------------------------------------------------
# spf stores the the least prime divisor of a number i
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
-------------------------------------------------------------------------------------------------
const int N = 1e7;
int spf[N + 1];
vector<int> prime;

void linear_sieve(){
	for (int i = 2; i <= N; ++i){
		if (spf[i] == 0){
			spf[i] = i;
			prime.pb(i);
		}
		for (int j = 0; j < int(prime.size()) && prime[j] <= spf[i] && i * prime[j] <= N; j++)
			spf[i * prime[j]] = prime[j];
	}
}
