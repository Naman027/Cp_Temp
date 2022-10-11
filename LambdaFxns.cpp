// Writing recursive Function 
function<void(int,int,int)> build = [&](int l,int r,int ind) -> void {
    if(l==r){
        Node node;
        seg[ind] = node;
        return;
    }
    int mid = (l+r)/2;
    build(l,mid,2*ind+1);
    build(mid+1,r,2*ind+2);
    return;
};

int ans = 0;
for_each(begin(a),end(a),[&](int x){ans+=x;});
