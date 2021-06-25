#include<bits/stdc++.h>
using namespace std;

// to tell us if a particular node and an another node belongs to a same component or not
/*
1. findParent 
2. Union operation
*/

const int N = 2e5;
int ranki[N];
int par[N];

void makePar(int n){
    for(int i=0;i<n;++i){
        par[i] = i;
        ranki[i] = 0;
    }
}

int findPar(int node){
    if(node==par[node]) return node;
    return par[node] =  findPar(par[node]);  //Path Compression
}

void uni(int a,int b){
    a = findPar(a);
    b = findPar(b);
    // Union By Rank
    if(ranki[a]<ranki[b]) par[a] = b;
    else if(ranki[a]>ranki[b]) par[b] = a;
    else{
        par[b] = a;
        ranki[a]++;
    }
}

  
// lesser rank is attached to higher rank inorder to improve complexity
// Path Compression minimizes no of moves to get the parent of a node
// Constant O(1) time operations O(N) space

















