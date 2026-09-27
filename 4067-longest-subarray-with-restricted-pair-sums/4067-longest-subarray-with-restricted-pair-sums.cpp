class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int low = 0, high = n;

        auto check = [&](int mid){
            multiset<int> s;
            // map<int,int> mp;
            vector<int> mp(1003);
            for(int i = 0; i < mid; i++){
                for(auto &ele : s){
                    mp[ele + nums[i]]++;
                }
                // mp[nums[i]]++;
                s.insert(nums[i]);
            }
            int l = 0, h = n-1;
            for(int j = mid; j < n; j++){
                bool ok = 0;
                for(auto &ele : s){
                    if(mp[ele] > 0){
                        ok = 1;
                        break;
                    }
                }
                if(!ok) return true;
                // mp[nums[l]]--;
                // if(mp[nums[l]] == 0) mp.erase(nums[l]);
                s.erase(s.find(nums[l]));
                for(auto &ele : s){
                    mp[ele + nums[l]]--;
                    // if(mp[ele+nums[l]] == 0) mp.erase(ele+nums[l]);
                }
                for(auto &ele : s){
                    mp[ele + nums[j]]++;
                }
                // mp[nums[j]]++;
                s.insert(nums[j]);
                l++;
            }
            bool ok = 0;
            for(auto &ele : s){
                if(mp[ele] > 0){
                    ok = 1;
                    break;
                }
            }
            if(!ok) return true;
            return false;
        };
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(mid)){
                res = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return res;
    }
};