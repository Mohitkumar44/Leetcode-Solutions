class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        // T.C. = O(n).
        int n = nums.size();
        int res = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] != i) {
                if(res != -1) {
                    res = res & nums[i];
                }
                else {
                    res = nums[i];
                }
            } 
        }
        if(res == -1) return 0;
        return res;
    }
};