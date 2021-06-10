class NumArray {
public:
    vector<int> a;
    vector<int> bit;
    
    NumArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = nums.size();
        
        a = nums;
        bit = vector<int> (n+1, 0);
        
        for(int i=0;i<n;i++){
            update_bit(i, a[i]);
        }
    }
    
    void update(int i, int val) {
        update_bit(i, val - a[i]);
        a[i] = val;
    }
    
    int sumRange(int i, int j) {
        return getsum(j) - getsum(i-1);
    }
    
    void update_bit(int idx, int val){
        idx++;
        
        int n = a.size();
        
        while(idx <= n){
            bit[idx] += val;
            
            idx += (idx & -idx);
        }
    }
    
    int getsum(int idx){
        idx++;
        
        int res = 0;
        while(idx > 0){
            res += bit[idx];
            
            idx -= (idx & -idx);
        }
        return res;
    }
};
