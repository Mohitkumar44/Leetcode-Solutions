class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int mn = INT_MAX;
        for(int len = l; len <= r; len++) {
            int sum = 0;
            int i = 0;
            int j = 0;
            while(j < len) {
                sum += nums[j];
                j++;
            }
            if(sum > 0) mn = min(mn, sum);
            while(j < n) {
                sum += nums[j];
                sum -= nums[i];
                i++;
                j++;
                if(sum > 0) mn = min(mn, sum);
            }
        }
        if(mn == INT_MAX) return -1;
        return mn;
    }
};