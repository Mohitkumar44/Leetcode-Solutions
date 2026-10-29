class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        // T.C. = O(m*n*k) where k is max of grid[i][j];
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (1025, 0)));
        dp[0][0][grid[0][0]] = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) continue;
                if(i == 0) {
                    vector<int> temp(1025);
                    for(int t = 0; t < 1025; t++) {
                        if(dp[i][j-1][t] == 1) {
                            temp[t ^ grid[i][j]] = 1;
                        }
                    }
                    dp[i][j] = temp;
                }
                else if(j == 0) {
                    vector<int> temp(1025);
                    for(int t = 0; t < 1025; t++) {
                        if(dp[i-1][j][t] == 1) {
                            temp[t ^ grid[i][j]] = 1;
                        }
                    }
                    dp[i][j] = temp;
                }
                else {
                    vector<int> temp(1025);
                    for(int t = 0; t < 1025; t++) {
                        if((dp[i-1][j][t] | dp[i][j-1][t]) == 1) {
                            temp[t ^ grid[i][j]] = 1;
                        }
                    }
                    dp[i][j] = temp;
                }
            }
        }
        for(int i = 0; i < dp[m-1][n-1].size(); i++) {
            if(dp[m-1][n-1][i] == 1) return i;
        }
        return -1;
    }
};