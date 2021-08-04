#include<bits/stdc++.h>
using namespace std;
#define N 100005
 
vector<int> spf(N);
void least_prime_factor(){
    for (int i = 2; i < N; i++)
        if (!spf[i])
            for (int j = i; j < N; j += i)
                if (!spf[j])
                    spf[j] = i;
}
 
void Mobius(int n){
    int mobius[N]; 
    for (int i = 1; i < N; i++) {
        if (i == 1)
            mobius[i] = 1;
        else {
             if (spf[i / spf[i]] == spf[i])
                mobius[i] = 0;
            else
                mobius[i] = -1 * mobius[i / spf[i]];
        }
    }
    for (int i = 1; i <= n; i++) cout << mobius[i] << " ";
}

