#include<bits/stdc++.h>
using namespace std;


class NumArray {
public:
    vector<int> bit;
    vector<int> a;
    int n;
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        a = nums;
        bit = vector<int>(n+1,0);
        
        for(int i=0;i<n;i++){
            update_bit(i,a[i]);
        }
    }
    
    void update_bit(int ind,int val){
        ind++;
        while(ind<=n){
            bit[ind]+=val;
            ind+=(ind&(-ind));
        }
    }
    
    void update(int index, int val) {
        update_bit(index,val-a[index]);
        a[index] = val;
    }
    
    int query(int ind){
        ind++;
        int ans = 0;
        while(ind>0){
            ans+=bit[ind];
            ind-=(ind&(-ind));
        }
        return ans;
    }
    
    int sumRange(int left, int right) {
        return query(right)-query(left-1);
    }
};


// Rightmost set bit of x  = (x&(-x))
// i is index i BIT
// let j = remove last bit (i)

Then BIT[i] stores value for range of index (j+1) -> i
that is j = i-(i&(-i));

class BIT{
public:
    vector<ll> bit;
    int n;

    BIT(int n){
        bit = vector<ll>(n+1,0);
        this->n = n+1;
    }

    void update(ll idx,ll val){
        while(idx<=n){
            bit[idx]+=val;
            idx+=(idx&(-idx));
        }
    }

    ll query(ll ind){
        ll ans = 0;
        while(ind>0){
            ans+=bit[ind];
            ind-=(ind&(-ind));
        }
        return ans;
    }

    ll sumRange(int l,int r){
        return query(r) - query(l-1);
    }

};
