class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size() < 4) return {};
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j < nums.size(); j++) {
                for(int k = j+1; k < nums.size(); k++) {
                    for(int l = k+1; l < nums.size(); l++) {
                        ans.push_back({i, j, k, l});
                    }
                }
            }
        }
        return ans;
    }
};