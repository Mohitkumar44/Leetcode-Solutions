class Solution {
public:
    void find(int& n, vector<string>& ans, string temp, int open, int close) {
        if(open < close) return;
        if(open == n && close == n) {
            ans.push_back(temp);
            return;
        }
        if(temp.size()>n*2) return;
        find(n, ans, temp+'(', open+1, close);
        find(n, ans, temp+')', open, close+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        find(n, ans, "", 0, 0);
        return ans;
    }
};