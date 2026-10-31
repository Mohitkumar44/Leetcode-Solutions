class Solution {
public:
    // flag == true means right
    vector<vector<vector<int>>> dp;
    int m, n;
    const int mod = 1e9 + 7;
    int f(vector<vector<int>>& grid, int i, int j, bool flag) {
        if(i >= m || j >= n) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j][flag] != -1) return dp[i][j][flag];
        if(grid[i][j] == 1) {
            if(flag == true) {
                return dp[i][j][flag] = f(grid, i+1, j, false)%mod;
            }
            else {
                return dp[i][j][flag] = f(grid, i, j+1, true)%mod;
            }
        }
        else return dp[i][j][flag] = (f(grid, i+1, j, false)%mod + f(grid, i, j+1, true)%mod)%mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.resize(m, vector<vector<int>> (n, vector<int> (2, -1)));
        return f(grid, 0, 0, false);
    }
};