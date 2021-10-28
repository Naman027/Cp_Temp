#include <bits/stdc++.h>
using namespace std;

void build(int *tree, int *a, int index, int s, int e)
{
    if (s == e)
    {
        tree[index] = a[s];
    }
    else
    {
        int mid = (s + e) / 2;
        build(tree, a, 2 * index, s, mid);
        build(tree, a, 2 * index + 1, mid + 1, e);
        tree[index] = tree[2 * index] + tree[2 * index + 1];
    }
}

int sum(int *tree, int index, int s, int e, int qs, int qe)
{
    if (qs <= s && e <= qe)
    {
        return tree[index];
    }
    if (qs > e || qe < s)
        return 0;
    int mid = (s + e) / 2;
    return sum(tree, 2 * index, s, mid, qs, qe) + sum(tree, 2 * index + 1, mid + 1, e, qs, qe);
}

void update(int *tree, int index, int s, int e, int pos, int val)
{
    if (pos < s || pos > e)
        return;
    if (s == e)
    {
        tree[index] = val;
        return;
    }
    int mid = (s + e) / 2;
    update(tree, 2 * index, s, mid, pos, val);
    update(tree, 2 * index + 1, mid + 1, e, pos, val);
    tree[index] = tree[2 * index] + tree[2 * index + 1];
    return;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    int *tree = new int[4 * n + 1];
    int index = 1;

    int s = 0, e = n - 1;
    build(tree, arr, index, s, e);

    cout << sum(tree, index, s, e, 1, 3) << endl;
    update(tree, index, s, e, 1, 43);
    cout << sum(tree, index, s, e, 1, 3) << endl;
}

// For Range Update using Lazy Propogation
const int N = 1e5;
vector<int> segtree(4*N);
vector<int> lazy(4*N);

void rangeLazy(int ind,int left,int right,int l,int r,int val){

    if(lazy[ind]!=0){
        segtree[ind]+=(right-left+1)*lazy[ind];
        if(left!=right){
            lazy[2*ind+1]+=lazy[ind];
            lazy[2*ind+2]+=lazy[ind];
        }
        lazy[ind] = 0;
    }

    if(r<left || l>right || left>right) return;

    if(left>=l && right<=r){
        segtree[ind]+=(right-left+1)*val;
        if(left!=right){
            lazy[2*ind+1]+=val;
            lazy[2*ind+2]+=val;
        }
        return;
    }

    int mid = l +(r-l)/2;
    rangeLazy(2*ind+1,left,mid,l,r,val);
    rangeLazy(2*ind+2,mid+1,right,l,r,val);
    segtree[ind] = segtree[2*ind+1]+segtree[2*ind+2];
}

int query(int ind,int left,int right,int l,int r){
    if(lazy[ind]!=0){
        segtree[ind]+=(right-left+1)*lazy[ind];
        if(left!=right){
            lazy[2*ind+1]+=lazy[ind];
            lazy[2*ind+2]+=lazy[ind];
        }
        lazy[ind] = 0;
    }

    if(r<left || l>right || left>right) return 0;
    if(l<=left && right<=r){
        return segtree[ind];
    }

    int mid = l+(r-l)/2;
    return query(2*ind+1,left,mid,l,r)+query(2*ind+2,mid+1,right,l,r);
}














