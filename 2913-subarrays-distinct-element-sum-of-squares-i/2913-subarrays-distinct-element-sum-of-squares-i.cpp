class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        // T.C. = O(n^2).
        // S.C. = O(n).
        unordered_set<int> st;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                st.insert(nums[j]);
                ans += st.size()*st.size();
            }
            st.clear();
        }

        return ans;
    }
};