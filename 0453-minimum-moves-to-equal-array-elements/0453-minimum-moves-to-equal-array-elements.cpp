class Solution {
public:
    int sum(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for(int i = 0; i < n; i++) {
            s += nums[i];
        }
        return s;
    }
    int minimum(vector<int>& nums) {
        int n = nums.size();
        int m = nums[0];
        for(int i = 1; i < n; i++) {
            m = min(m, nums[i]);
        }
        return m;
    }
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int s = sum(nums);
        int m = minimum(nums);
        // int cnt = 0;
        // while(m * n != s) {
        //     cnt++;
        //     m++;
        //     s += n-1;
        // }
        // return cnt;
        return s - n*m;
    }
};