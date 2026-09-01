class Solution {
public:
    int number(int n, int& k, int target, vector<vector<int>>& dp) {
        if(target < 0) return 0;
        if(n == 0) {
            if(target == 0) return 1;
            else return 0;
        } 
        int mod = 1000000007;
        if(dp[n][target]!=-1) return dp[n][target];
        int cnt = 0;
        for(int i = 1; i <= k; i++) {
            if(target - i < 0) continue;
            cnt = (cnt%mod + (number(n-1, k, target - i, dp))%mod)%mod;
        }
        return dp[n][target] = cnt;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(31, vector<int> (1001, -1));
        return number(n, k, target, dp);
    }
};