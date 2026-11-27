class Solution {
public:
    int n;
    vector<vector<int>> dp;
    vector<int> copies;
    int cheap;

    int f(vector<vector<int>>& items, int budget, int i) {
        if(i < 0) return budget/cheap;

        if(dp[i][budget] != -1) return dp[i][budget];

        if(budget < items[i][1]) {
            return dp[i][budget] = f(items, budget, i-1);
        }
        else {
            return dp[i][budget] = max(f(items, budget, i-1), copies[i] + 1 + f(items, budget - items[i][1], i-1));
        } 
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n = items.size();
        
        copies.resize(n);
        dp.resize(n + 1, vector<int> (budget + 1, -1));

        cheap = 2000;
        for(int i = 0; i < n; i++) {
            int c = 0;
            cheap = min(cheap, items[i][1]);

            for(int j = 0; j < n; j++) {
                if(i != j && items[j][0] % items[i][0] == 0) c++; 
            }

            copies[i] = c;
        }

        return f(items, budget, n-1);
    }
};