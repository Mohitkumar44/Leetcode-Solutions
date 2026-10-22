class Solution {
public:
    int minoper(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        if(temp == nums) return 0;
        int dec = 0, inc = 0;
        int decIdx = -1, incIdx = -1;
        int last = nums[n-1];
        for(int i = 0; i < n; i++) {
            if(last < nums[i]) {
                inc++;
                incIdx = i;
            } 
            else if(last > nums[i]) {
                dec++;
                decIdx = i;
            }
            last = nums[i];
        }
        if(inc >= 2 && dec >= 2) return -1;
        // cout<<inc<<" "<<dec;
        if(inc >= 2) {
            return decIdx;
        }
        else {
            return incIdx + 1;
        }
    }
    int minOperations(vector<int>& nums) {
        int a = minoper(nums);
        reverse(nums.begin(), nums.end()); 
        int b = 1 + minoper(nums);
        cout<<a<<" "<<b;
        return min(a, b);
    }
};