#include<bits/stdc++.h>
using namespace std;

//O(NlogN + Q)

vector<vector<int>> sparse;
vector<int> logr;

int query(int l,int r){
    int len = r-l+1;
    int k = logr[len];
    // on can use count leading zero formula 
    int bit = 31-__builtin_clz(len);
    // this bit is same as k
    return min(sparse[l][k],sparse[r-(1<<k)+1][k]);
}

int main(){
    int n;
    cin >> n;
    logr = vector<int>(n+1,0);
    logr[1] = 0;
    for(int i=2;i<=n;i++){
        logr[i] = logr[i/2]+1;
    }
    sparse = vector<vector<int>>(n,vector<int>(30,0));
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        sparse[i][0] = a[i];
    }   

    for(int k=1;k<30;k++){
        for(int i=0;i+(1<<k)-1<n;i++){
            sparse[i][k] = min(sparse[i][k-1],sparse[i+(1<<(k-1))][k-1]);
        }
    }

    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        cout << query(l,r) << endl;
    }

}


