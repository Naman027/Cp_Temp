#include<bits/stdc++.h>
using namespace std;
// Minimum Spanning Tree can be found out using Prims and Kruskal's Algorithms

// Prim's Algorithm -- basically a greedy approach -- picking up the min length one

void Prim(vector<pair<int,int>> adj[],int N){
    vector<int> key;
    vector<int> mst(N,-1);
    
}

// Kruskal's Algorithm
// use dsu
/*
1. Sort according to weights
2. Greedly pickup the shortest edge checking the components because if they belong to same component
    then it will form a cycle 
*/

struct Node{
    int u;
    int v;
    int w;
};

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

void kruskal(int N){
    vector<Node> edges;

    auto comp = [&](Node a,Node b){
        return a.w < b.w;
    };

    sort(edges.begin(),edges.end(),comp);
    makePar(N);
    int cost = 0;
    vector<pair<int,int>> MST;
    
    for(auto it:edges){
        if(findPar(it.u)!=findPar(it.v)){
            cost+=it.w;
            MST.push_back({it.u,it.v});
            uni(it.u,it.v);
        }
    }

    cout << cost << endl;
    for(auto it:MST) cout << it.first << " " << it.second << endl;

}

































