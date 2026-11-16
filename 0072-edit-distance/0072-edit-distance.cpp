class Solution {
public:
    int m, n;
    vector<vector<int>> dp;  // Memoization.

    int f(string& word1, string& word2, int i, int j) {
        // remaining strings.
        if(i >= m) return dp[i][j] = word2.size() - j;
        if(j >= n) return dp[i][j]  = word1.size() - i;

        if(dp[i][j] != -1) return dp[i][j];
        
        // same character.
        if(word1[i] == word2[j]) return dp[i][j] = f(word1, word2, i+1, j+1);

        int res = 1e9;
        res = min(res, 1 + f(word1, word2, i+1, j+1));   //replace
        res = min(res, 1 + f(word1, word2, i, j+1));   //insert
        res = min(res, 1 + f(word1, word2, i+1, j));   //delete

        return dp[i][j] = res;
    }
    int minDistance(string word1, string word2) {
        m = word1.size();
        n = word2.size();
        dp.resize(501, vector<int> (501, -1));
        return f(word1, word2, 0, 0);
    }
};