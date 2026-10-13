class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // T.C. = O(nlong(n));
        // S.C. = O(log(n));
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int i = 0;
        while(i < n/2) {
            ans -= nums[i];
            i++;
        }
        while(i < n) {
            ans += nums[i];
            i++;
        }
        return ans;
    }
};