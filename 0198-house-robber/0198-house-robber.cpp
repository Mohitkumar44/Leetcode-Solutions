class Solution {
public:
    int rob(vector<int>& nums) {
        // T.C. = O(n) S.C. = O(1)
        int n = nums.size();
        if(n == 1) return nums[0];
        int a = nums[0];
        int b = max(a, nums[1]);
        for(int i = 2; i < n; i++) {
            if(b < a + nums[i]) {
                int t = a + nums[i];
                a = b;
                b = t;
            }
            else {
                a = b;
            }
            cout<<b<<" ";
        }
        return b;
    }
};