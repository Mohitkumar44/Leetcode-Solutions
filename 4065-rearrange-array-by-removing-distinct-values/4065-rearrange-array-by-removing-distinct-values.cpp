class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(101, 0);
        int mx = 0;
        for(int ele : nums) {
            v[ele]++;
            mx = max(mx, v[ele]);
        }
        vector<int> ans;
        for(int i = 0; i < mx; i++){
            for(int j = 0; j < 101; j++) {
                if(v[j] > 0) {
                    ans.push_back(j);
                    v[j]--;
                }
            }
        }
        return ans;
    }
};