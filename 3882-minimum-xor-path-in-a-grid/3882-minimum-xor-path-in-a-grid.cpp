class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;
    // int mincost(vector<vector<int>>& grid, int i, int j, vec) {

    //     // if(i < 0 || j < 0) return INT_MAX;
    //     if(i == m-1 && j == n-1) return val^ grid[i][j];
    //     if(dp[i][j] != -1) return dp[i][j];
    //     return grid[i][j] ^ min(mincost(grid, i-1, j, dp), mincost(grid, i, j-1, dp));
    // }
    int f(vector<vector<int>>&grid, int i, int j, int val){
        if(i == m-1 && j == n-1) return val^ grid[i][j];
        if(i >= m || j >= n) return 1e9;
        if(dp[i][j][val] != -1) return dp[i][j][val];
        int ans = 1e9;
        ans = min(ans, f(grid, i+1, j, val^ grid[i][j]));
        ans = min(ans, f(grid, i, j+1, val^ grid[i][j]));

        return dp[i][j][val] = ans;
    }
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int> (n, -1));
        dp.resize(m, vector<vector<int>> (n, vector<int> (1024, -1)));
        return f(grid, 0, 0, 0);
    }
};