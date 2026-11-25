class Solution {
public:
    #define ll long long
    int mod = 1e9 + 7;
    ll pow(int a, int p) {
        if(p == 0) return 1;

        ll half = pow(a, p/2);
        
        ll result = (half * half) % mod;

        if(p%2) {
            result = (result * a) % mod;
        }
        
        return result;
    }
    bool check(vector<int>& nums, int l, int base) {
        int n = nums.size();
        map<ll, int> mp;
        ll hash = 0;

        int i = 0;
        int j = 0;

        while(j < l) {
            hash = (hash*(ll)base)%mod + (ll)nums[j];
            hash = hash%mod;
            j++;
        }
        mp[hash]++;

        ll p = pow(base, l-1);

        while(j < n) {
            hash = (hash - (ll)nums[i] * p % mod + mod) % mod;
            hash = (hash*(ll)base)%mod + (ll)nums[j];
            hash = hash%mod;
            i++;
            j++;
            mp[hash]++;
        }

        bool check = true;
        for(auto ele : mp) {
            if(ele.second == 1) {
                return true;
            }
        }   

        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int base = *max_element(nums.begin(), nums.end()) + 1;

        // binary_search.
        int lo = 1, hi = n;
        while(lo <= hi) {
            int l = lo + (hi-lo)/2;
            if(check(nums, l, base)) hi = l - 1;
            else lo = l + 1;
        }

        return lo;
    }
};