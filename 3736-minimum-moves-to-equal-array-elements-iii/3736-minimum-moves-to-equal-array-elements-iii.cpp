class Solution {
public:
    int maximum(vector<int>& nums) {
        int m = nums[0];
        for(int ele : nums) {
            m = max(m, ele);
        }
        return m;
    }
    int minMoves(vector<int>& nums) {
        int m = maximum(nums);
        int cnt = 0;
        for(int ele : nums) {
            cnt += m - ele;
        }
        return cnt;
    }
};