class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int k = -1;
        if(n%2) {
            k = nums[n/2];
        }
        else {
            k = nums[n/2 - 1] + nums[n/2];
            k/=2;
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            res += abs(nums[i] - k);
        }
        return res;
    }
};