class Solution {
public:
    static int dsum(int n) {
        int s = 0;
        while(n) {
            s += n%10;
            n/=10;
        }
        return s;
    }
    static bool customSort(int a, int b) {
        int s1 = dsum(a), s2 = dsum(b);
        if(s1 < s2) return true;
        else if(s1 > s2) return false;
        return a < b;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> copy = nums;
        sort(copy.begin(), copy.end(), customSort);
        int cnt = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]] = i; 
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] != copy[i]) {
                int m = mp[copy[i]];
                int l = nums[i];
                swap(nums[i], nums[m]);
                mp[copy[i]] = i;
                mp[l] = m;
                cnt++;
            }
        }
        return cnt;
    }
};