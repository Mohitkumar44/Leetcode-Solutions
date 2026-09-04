class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int n = digits.size();
        int plus = 1;
        for(int i = n-1; i >= 0; i--) {
            if(digits[i] == 9 && plus == 1) {
                digits[i] = 1;
            }
            else {
                digits[i] = digits[i] + 1;
                break;
            }
        }
        return digits;
    }
};