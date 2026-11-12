class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int t = nums[0];
        int inc = 1;
        int dec = 1;
        int minc = 1;
        int mdec = 1;
        bool flag = true;
        for(int i = 1; i < n; i++){
            if(nums[i] == t) {
                minc = max(minc, inc);
                mdec = max(mdec, dec);
                inc = 1;
                dec = 1;
                continue;
            }
            if(flag) {
                if(nums[i] > t) {
                    inc++;
                }
                else {
                    minc = max(minc, inc);
                    inc = 1;
                    dec++;
                    flag = false;
                }
            }
            else {
                if(nums[i] < t) {
                    dec++;
                }
                else {
                    mdec = max(mdec, dec);
                    dec = 1;
                    inc++;
                    flag = true;
                }
            }
            t = nums[i];
        }
        if(flag) {
            minc = max(minc, inc);
        }
        else {
            mdec = max(mdec, dec);
        }
        cout<<minc<<" "<<mdec;
        return max(minc, mdec);
    }
};