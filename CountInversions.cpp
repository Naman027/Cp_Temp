#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>& a,vector<int>& temp,int left,int mid,int right){
    int i,j,k;
    int inversions = 0;
    i = left;
    j = mid;
    k = left;
    
    while((i<=mid-1) && j<=right){
        if(a[i]<=2*a[j]) temp[k++] = a[i++];
        else{
            temp[k++] = a[j++];
            inversions+=(mid-i);
        }
    }

    while(i<=mid-1) temp[k++] = a[i++];
    while(j<=right) temp[k++] = a[j++];

    for(int i=left; i<=right; i++) a[i] = temp[i];
    return inversions;
}

int mergeSort(vector<int>& a,vector<int>& temp,int left,int right){
    int mid, inversions = 0;
    if(right>left){
        mid = (left+right)/2;
        inversions+=mergeSort(a,temp,left,mid);
        inversions+=mergeSort(a,temp,mid+1,right);
        inversions+=merge(a,temp,left,mid+1,right);
    }
    return inversions;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int inversions = 0;

    // Using Merge Sort
    vector<int> temp = a;
    cout << mergeSort(a,temp,0,n-1) << endl;

}

