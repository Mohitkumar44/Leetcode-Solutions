class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int mx = ans;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                ans++;
                mx = max(ans, mx);
            } else if (s[i] == ')')
                ans--;
        }
        return mx;
    }
};