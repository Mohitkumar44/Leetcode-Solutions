class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0;
        string ans = "";
        for(char ch : s) {
            if(ch == '(') {
                open++;
                if(open > 1) {
                    ans += ch;
                }
            }
            else {
                open--;
                if(open >= 1) {
                    ans += ch;
                }
            }
        }
        return ans;
    }
};