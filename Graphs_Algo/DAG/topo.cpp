// Khan's Algo for toposort
// There can be more than one topological sorting for a graph.
// The first vertex in topological sorting is always a vertex with in-degree as 0 (a vertex with no in-coming edges).
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
vector<int> adj[N];

// O(V+E)
void toposort(){
    vector<int> in_degree(N, 0);
    for (int u = 0; u < N; u++) {
        for(auto child:adj[u])
            in_degree[child]++;
    }

    queue<int> q;
    for (int i = 0; i < N; i++)
        if (in_degree[i] == 0)
            q.push(i);

    int cnt = 0; // cnt of vis vertices
    vector<int> ans;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(auto child:adj[u])
            if (--in_degree[child] == 0) q.push(child); 
        cnt++;
    }
    
    if (cnt != N){ // Check if there was a cycle
        cout << "There exists a cycle in the graph\n";
        return;
    }
  
    // else ans contains one of the topo sort
}






