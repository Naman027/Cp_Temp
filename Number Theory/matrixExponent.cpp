#include<bits/stdc++.h>
using namespace std;
#define ll long long

int m;
 
struct matr {
    ll m[2][2];
};

matr operator * (const matr& a, const matr& b) {
    matr res;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            res.m[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                res.m[i][j] = (res.m[i][j] + a.m[i][k] * b.m[k][j]) % m;
            }
        }
    return res;
}
 
matr power(matr m, ll p) {
    if (p == 1)
        return m;
    if (p % 2) 
        return m * power(m, p - 1); 
    return power(m * m, p / 2);
}
 
int fib(ll num) {
    if (num == 1)
        return 1;
    matr f;
    f.m[0][0] = 0;
    f.m[0][1] = f.m[1][0] = f.m[1][1] = 1;
    f = power(f, num);
    return f.m[0][1];
}









