class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;
    int f(vector<vector<int>>& grid, int i, int j, int x, int y) {
        if(i >= n || j >= n || x >= n || y >= n || grid[i][j] == -1 || grid[x][y] == -1) return INT_MIN;
        if(x == n-1 && y == n-1) return grid[x][y] == 1;
        if(dp[i][j][x] != -1) return dp[i][j][x];
        int result = -1e9;
        result = max(result, f(grid, i+1, j, x+1, y));
        result = max(result, f(grid, i+1, j, x, y+1));
        result = max(result, f(grid, i, j+1, x+1, y));
        result = max(result, f(grid, i, j+1, x, y+1));
        if(grid[i][j] == 1) result++;
        if(grid[x][y] == 1) result++;
        if(i == x && j == y && grid[i][j] == 1) result--;
        return dp[i][j][x] = result;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        dp.resize(n+1, vector<vector<int>> (n+1, vector<int> (n+1, -1)));
        int res = f(grid, 0, 0, 0, 0);
        return res < 0 ? 0 : res;
    }
};