class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res;
        int smaller = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] < target) smaller++;
            else if(nums[i] == target) cnt++;
        }
        for(int i = smaller; i < smaller + cnt; i++) {
            res.push_back(i);
        }
        return res;
    }
};