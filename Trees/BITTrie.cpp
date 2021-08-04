#include <bits/stdc++.h>
using namespace std;

/*----------------------------------------------------------------
1. Binary rep storage of array elements
*/

class node{
public:
    node* child[2];
    node(){
        child[0] = nullptr;
        child[1] = nullptr;
    }
};

void insert(node* root,int num){
    node* tempRoot = root;
    for(int i=31;i>=0;i--){
        int bit = ((num>>i)&1);
        if(tempRoot->child[bit]==nullptr){
            tempRoot->child[bit] = new node();            
        }
        tempRoot = tempRoot->child[bit];
    }
}

int maxXor(node* root,int y){
    int ret = 0;
    node* tempRoot = root;
    for(int i=31;i>=0;i--){
        int bit = ((y>>i)&1);
        if(tempRoot->child[bit^1] == nullptr){
            tempRoot = tempRoot->child[bit];
        }
        else{
            ret|=(1LL<<i);
            tempRoot = tempRoot->child[bit^1];
        }
    }   
    return ret;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    node* root = new node();
    int ans = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        insert(root,a[i]);
        int y = a[i];
        int temp = maxXor(root,y);
        ans = max(ans,temp);
    }
    cout << ans << endl;
}

int32_t main(){
    solve();
}
















