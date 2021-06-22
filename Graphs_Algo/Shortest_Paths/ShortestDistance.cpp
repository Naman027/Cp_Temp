

// Shortest Path in an Undirected Graph with unit edge

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

void shortest_distance(vector<int> adj[],int N,int src){
    int dist[N];
    for(int i=0;i<N;i++) dist[i] = INT_MAX;

    queue<int> q;
    q.push(src);
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

// Shortest Path in a weighted DAG
/*
1. find toposort first
2. then just iterate over each element and find the shortest path
*/

// Djikstra's Algorithm

 // a pair is been put to priority queue when a lower distance is been observed
// set<pair<int,int>> can also be used so that similar values are not inserted in the queue basically


void djikstra(vector<pair<int,int>> adj[],int N,int src){
    vector<int> dis(N,1e9);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dis[src] = 0;
    pq.push({0,src});
    while(!pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto ch:adj[node]){
            int nnode = ch.second;
            int distreq = ch.first;
            if(dis[nnode]>dist+distreq){
                dis[nnode] = dist+distreq;
                pq.push({dis[nnode],nnode});
            } 
        }
    }

}










