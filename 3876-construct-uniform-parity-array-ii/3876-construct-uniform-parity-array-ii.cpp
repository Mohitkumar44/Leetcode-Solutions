class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();

        int miniodd = INT_MAX;
        int minieven = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(nums[i]%2 == 1) miniodd = min(miniodd, nums[i]);
            else minieven = min(minieven, nums[i]);
        }

        if(miniodd == INT_MAX || minieven == INT_MAX) return true;
        if(minieven > miniodd) return true;

        return false;
    }
};