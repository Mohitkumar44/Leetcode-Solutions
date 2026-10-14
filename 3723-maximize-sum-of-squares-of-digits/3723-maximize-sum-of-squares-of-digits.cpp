class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(9*num < sum) return "";
        int cnt = num;
        string ans = "";
        while(cnt) {
            if(sum >= 9) {
                ans += '9';
                sum -= 9;
            }
            else {
                ans += to_string(sum);
                sum = 0;
            }
            cnt--;
        }
        return ans;
    }
};