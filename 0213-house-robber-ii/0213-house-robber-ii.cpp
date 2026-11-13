class Solution {
public:
    int rob(vector<int>& nums) {
        // T.C. = O(n) S.C. = O(1)
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[1], nums[0]);
        if(n == 3) return max({nums[0], nums[1], nums[2]});
        int a = nums[0];
        int b = max(a, nums[1]);
        for(int i = 2; i < n-1; i++) {
            if(b < a + nums[i]) {
                int t = a + nums[i];
                a = b;
                b = t;
            }
            else {
                a = b;
            }
        }
        int x = b;
        a = nums[1];
        b = max(a, nums[2]);
        for(int i = 3; i < n; i++) {
            if(b < a + nums[i]) {
                int t = a + nums[i];
                a = b;
                b = t;
            }
            else {
                a = b;
            }
        }
        x = max(x, b);
        return x;
    }
};