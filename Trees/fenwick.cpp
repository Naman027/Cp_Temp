struct BIT{
    vector<ll> bit;
    BIT(){
        bit.assign(maxN, 0LL);
    }
    void update(int ind, ll val){
        for(; ind < maxN; ind += (ind & (-ind))){
            bit[ind] += val;
        }
    }
    ll query(int ind){
        ll ret = 0LL;
        for(; ind; ind -= (ind & (-ind))){
            ret += bit[ind];
        }
        return ret;
    }
};