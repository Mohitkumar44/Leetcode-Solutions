class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // T.C. = O(max(sum/9, num)).
        if(9*num < sum) return "";
        int cnt = num;
        string ans = "";
        while(cnt && sum) {
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
        while(cnt) {
            ans += '0';
            cnt--;
        }
        return ans;
    }
};