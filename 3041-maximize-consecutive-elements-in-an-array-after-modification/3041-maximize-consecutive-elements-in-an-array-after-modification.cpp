class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int findMethod(vector<int>& nums, int start, int target) {
        int j = lower_bound(begin(nums) + start, end(nums), target) - begin(nums);
        
        if(j < n && nums[j] == target) return j;

        return -1;
    }

    int solve(vector<int>& nums, int i, int inc) {
        int curr = nums[i] + inc;
        int len = 1;

        if(dp[i][inc] != -1) return dp[i][inc];

        int j = findMethod(nums, i + 1, curr + 1);
        if(j != -1) {
            len = max(len, 1 + solve(nums, j, 0));
        }

        j = findMethod(nums, i + 1, curr);
        if(j != -1) {
            len = max(len, 1 + solve(nums, j, 1));
        }

        return dp[i][inc] = len;
    }
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        dp.resize(n+1, vector<int> (2, -1));
        int result = 1;
        for(int i = 0; i < n; i++) {
            result = max({result, solve(nums, i, 0), solve(nums, i, 1)});
        }
        return result;
    }
};