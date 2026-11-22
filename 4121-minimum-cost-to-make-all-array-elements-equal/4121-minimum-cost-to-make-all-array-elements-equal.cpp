class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        long long cost = LLONG_MAX;    // INT_MAX --> LLONG_MAX
        vector<int> pre(n, 1);
        vector<int> suff(n, 1);
        vector<int> suffIdx(n, n-1);
        
        for(int i = 1; i < n-1; i++) {
            if(nums[i] != nums[i-1] || pre[i-1] != 1) pre[i] = 0;
        }
        if(pre[n-2] == 1 && nums[n-1] == nums[n-2]) {
            if(nums[n-1] == nums[n-2]) pre[n-1] = 1;
        }
        else pre[n-1] = 0;
        
        if(nums[n-1] == nums[n-2]) {
            suffIdx[n-2] = n-1;
        }
        else suffIdx[n-2] = n-2;
        
        for(int i = n-2; i >= 1; i--) {
            if(nums[i] != nums[i+1] || suff[i+1] != 1) suff[i] = 0;
            if(nums[i] == nums[i+1]) {
                suffIdx[i] = suffIdx[i+1];
            }
            else {
                suffIdx[i] = i;
            }
        }
        if(suff[1] == 1 && nums[0] == nums[1]) {
            if(nums[0] == nums[1]) suff[0] = 1;
        }
        else suff[0] = 0;
        
        long long c;
        for(int i = 1; i < n-1; i++) {
            c = 0;
            if(pre[i] == 0) c += (long long)i * (long long)nums[i];
            if(suff[i] == 0) c += (long long)(n - suffIdx[i] - 1) * (long long)nums[suffIdx[i]];
            cost = min(cost, c);
        }
        return cost;
    }
};