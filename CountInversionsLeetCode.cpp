/*
Given an integer array nums, return the number of reverse pairs in the array.
  A reverse pair is a pair (i, j) where:
  0 <= i < j < nums.length and
  nums[i] > 2 * nums[j].
*/ 

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long long double
#define ar array
#define mod 1000000007
#define mod2 998244353
#define endl '\n'
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define loop(i, m, n) for (int i = m; i < n; i++)
#define EACH(a, A) for (auto &a : A)
#define fi first
#define se second
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll, vector<ll>, greater<ll>>
const int dx[8] = {-1, 0, 0, 1, 1, 1, -1, -1}, dy[8] = {0, 1, -1, 0, 1, -1, -1, 1};

class Solution {
public:
	int ans = 0, n;
	vector<int> nums;

	void Merge(int l,int mid,int r){
		int i = l, j = mid;
		vector<int> temp;

		while(i<=mid-1 && j<=r){
			if((ll)nums[i]<=2LL*(ll)nums[j]) i++;
			else{
				ans+=(mid-i);
				j++;
			}
		}

		i = l, j = mid;
		while(i<=mid-1 && j<=r){
			if(nums[i]<=nums[j]) temp.push_back(nums[i]),i++;
			else temp.push_back(nums[j]),j++;
		}

		while(i<=mid-1) temp.push_back(nums[i]),i++;
		while(j<=r) temp.push_back(nums[j]),j++;
        
		for(int i=l;i<=r;i++) nums[i] = temp[i-l];
	}

	void MergeSort(int l,int r){
		if(l<r){
			int mid = (l+r)/2;
			MergeSort(l,mid);
			MergeSort(mid+1,r);
			Merge(l,mid+1,r);
		}
	}

    int reversePairs(vector<int>& _nums) {
    	n = (_nums).size();
        nums = _nums;
    	MergeSort(0,n-1);
    	return ans;
    }
};
