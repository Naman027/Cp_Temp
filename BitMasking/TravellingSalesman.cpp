#include <bits/stdc++.h>
using namespace std;

int dp[21][(1 << 21)];
int solve(int i, int mask, vector<vector<int>> tsp){
    if (mask == 0)
        return tsp[i][0];
    if (dp[i][mask] != -1)
        return dp[i][mask];
    
    int ans = INT_MAX;
    for (int j = 1; j < tsp.size(); j++)
        if (mask & (1 << j))
            ans = min(ans, tsp[i][j] + solve(j, mask ^ (1 << j), tsp));

    return dp[i][mask] = ans;
}

int main(){
    memset(dp, -1, sizeof(dp));
    vector<vector<int>> tsp = {{-1, 10, 15, 20},
                               {10, -1, 35, 25},
                               {15, 35, -1, 30},
                               {20, 25, 30, -1}};

    int n = tsp.size();
    cout << solve(0, ((1 << n) - 1) ^ 1, tsp);
}