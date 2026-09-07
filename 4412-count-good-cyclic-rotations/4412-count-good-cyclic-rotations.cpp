class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        for(int i = 0; i < n/2; i++) {
            l += nums[i];
        }
        for(int i = n/2; i < n; i++) {
            r += nums[i];
        }
        int i = 0, j = n/2;
        int cnt = 0;
        for(int k = 0; k < n; k++) {
            if(l == r) cnt++;
            l -= nums[i];
            r += nums[i];
            l += nums[j];
            r -= nums[j];
        }
        return cnt;
    }
};