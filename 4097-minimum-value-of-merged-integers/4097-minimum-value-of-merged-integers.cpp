class Solution {
public:
    int len(int n) {
        int cnt = 0;
        while(n) {
            cnt++;
            n/=10;
        }
        return cnt;
    }
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        int mn = INT_MAX;
        for(int i = 0; i < n; i+=2) {
            int a = nums[i];
            int b = nums[i+1];
            int l = len(b);
            while(l) {
                a *= 10;
                l--;
            }
            mn = min(mn, a + b);
        }
        return mn;
    }
};