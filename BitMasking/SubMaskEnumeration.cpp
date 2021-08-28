#include<bits/stdc++.h>
using namespace std;
#define ll long long

// To iterate through all of it's submasks 

int main(){
    int m;
    // let s be all of its submasks
    cin >> m;
    int s = m;
    while(s){
        cout << s << endl;
        s = ((s-1)&m);
    }
}

// Time complexity: O(3^n) 
