

// Shortest Path in an Undirected Graph

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

void shortest_distance(vector<int> adj[],int N,int src){
    int dist[N];
    for(int i=0;i<N;i++) dist[i] = INT_MAX;

    queue<int> q;
    dist[src] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it:adj[node]){
            if(dist[node]+1<dist[it]){
                dist[it] = 1 +dist[node];
                q.push(it);
            }            
        }
    }

    for(int i=0;i<N;i++) cout << dist[i] << " ";

}


















