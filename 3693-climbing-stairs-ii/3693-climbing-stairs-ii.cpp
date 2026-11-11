class Solution {
public:
    vector<int> dp;
    int f(vector<int>& costs, int i) {
        int n = costs.size();

        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        
        int ans = INT_MAX;
        for(int j = 1; j <= 3; j++) {
            if(i + j <= n) {
                ans = min(ans, costs[i+j-1] + j*j + f(costs, i+j));
            }
        }

        return dp[i] = ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        dp.resize(n+1, -1);
        return f(costs, 0);
    }
};