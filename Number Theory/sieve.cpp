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
