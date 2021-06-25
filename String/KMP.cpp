#include<bits/stdc++.h>
using namespace std;

/*----------------------------------------------------------------
1. using prefix function
*/

vector<int> prefix_fun(string s){
    int n = s.size();
    vector<int> pi(n,0);
    for(int i=1; i < n; i++){
        int j = pi[i-1];
        while(j>0 && s[i]!=s[j]) j = pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

void kmp(){
    string s;
    cin >> s;
    int n = s.size();

    // Prefix function
    // Pi(i) == length of longest proper prefix of substring (0,i) which is also a suffix

    vector<int> pi = prefix_fun(s);
    // Substring search
    // make a search string as pattern + "#" + text
 
}

int32_t main(){
    kmp();
}



