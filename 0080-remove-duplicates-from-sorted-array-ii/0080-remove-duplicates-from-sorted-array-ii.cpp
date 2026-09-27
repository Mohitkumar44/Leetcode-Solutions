class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int ele : nums) {
            mp[ele]++;
        }
        int i = 0;
        for(auto ele : mp) {
            if(ele.second > 1) {
                nums[i] = ele.first;
                i++;
                nums[i] = ele.first;
                i++;
            }
            else {
                nums[i] = ele.first;
                i++;
            }
        }
        sort(nums.begin(), nums.begin() + i);
        return i;
    }
};