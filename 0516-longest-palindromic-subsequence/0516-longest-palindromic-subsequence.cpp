class Solution {
public:
    vector<vector<int>> dp;
    int f(string& str1, string& str2, int i, int j) {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(str1[i] == str2[j]) {
            return dp[i][j] = 1 + f(str1, str2, i-1, j-1);
        }
        else {
            return dp[i][j] = max(f(str1, str2, i-1, j), f(str1, str2, i, j-1));
        }
    }
    int longestPalindromeSubseq(string str1) {
        int n = str1.size();
        string str2 = str1;
        dp.resize(n, vector<int> (n, -1));
        reverse(str2.begin(), str2.end());
        return f(str1, str2, n-1, n-1);
    }
};