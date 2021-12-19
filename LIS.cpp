
// Longest Increasing Sequence
int LIS(vector<int>& a){
    int n = a.size();
    vector<int> lis;
    for(int i=0;i<n;i++){
        int ind = lower_bound(lis.begin(),lis.end(),a[i])-lis.begin();
        if(ind==lis.size()){
            lis.push_back(a[i]);
        }
        else lis[ind] = a[i];
    }
    return lis.size();
}

// Longest non decreasing sequence
int LNDS(vector<int>& a){
    int n = a.size();
    vector<int> lnds;
    for(int i=0;i<n;i++){
        int ind = upper_bound(lnds.begin(),lnds.end(),a[i])-lnds.begin();
        if(ind==lnds.size()){
            lnds.push_back(a[i]);
        }
        else lnds[ind] = a[i];
    }
    return lnds.size();
}

