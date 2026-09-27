class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        for(int len = 1; len <= n; len++) {
            for(int i = 0; i <= n-len; i++) {
                int j = i + len-1;
                if(len <= 2) dp[i][j] = s[i] == s[j];
                else dp[i][j] = s[i]==s[j] && dp[i+1][j-1] == 1;
            }
        }
        int a = -1, b = -1;
        int maxlen = -1;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                if(dp[i][j]==1) {
                    if(j-i > maxlen) {
                        maxlen = max(maxlen, j-i);
                        a = i;
                        b = j;
                    }
                }
            }
        }
        return s.substr(a, b-a+1);
    }
};