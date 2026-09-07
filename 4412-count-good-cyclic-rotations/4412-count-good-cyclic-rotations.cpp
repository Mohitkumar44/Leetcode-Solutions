class Solution {
public:
    vector<int> rotate(vector<int> s) {
        vector<int> temp;
        for(int i = 0; i < s.size(); i++) {
            temp.push_back(s[i]);
        }
        temp[s.size()-1] = s[s.size()-1];
        return temp;
    }
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            vector<int> t = rotate(nums);
            int score = 0;
            nums = t;
            for(int i = 0; i < n - 1; i++){
                if(t[i] == t[i + 1]) score++;
            }
            // if(score == k) cnt++;
        }
        return cnt;
    }
};