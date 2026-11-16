class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int f(string& word1, string& word2, int i, int j) {
        if(i >= m && j >= n) return 0;

        if(dp[i][j] != -1) return dp[i][j];
 
        // remaining strings.
        if(j >= n) return dp[i][j] = 1 + f(word1, word2, i+1, j);
        if(i >= m) return dp[i][j] = 1 + f(word1, word2, i, j+1);
        
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
        dp.resize(1 + max(m, n), vector<int> (1 + max(m, n), -1));
        return f(word1, word2, 0, 0);
    }
};