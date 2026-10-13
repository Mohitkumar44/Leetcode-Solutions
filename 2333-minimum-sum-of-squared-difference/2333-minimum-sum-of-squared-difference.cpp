class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> v(100001, 0);
        int n = nums1.size();
        for(int i = 0; i < n; i++) {
            v[abs(nums1[i]-nums2[i])]++;
        }

        int t = k1+k2;
        for(int i = 100000; i > 0 && t > 0; i--) {
            if(v[i] > 0) {
                int cnt = min(t, v[i]);
                v[i] -= cnt;
                v[i-1] += cnt;
                t -= cnt;
            }
        }

        long long ans = 0;
        for(int i = 100000; i >= 0; i--) {
            if(v[i] > 0) {
                ans += (long long)((long long)i*(long long)i)*(long long)v[i];
            }
        }
        return ans;
    }
};