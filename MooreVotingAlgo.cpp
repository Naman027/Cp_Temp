#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int cnt = 0, el = 0;
    for(int i = 0; i < n; i++){
        if(cnt==0) el = a[i];
        if(el==a[i]) cnt++;
        else cnt--;
    }

    

}
