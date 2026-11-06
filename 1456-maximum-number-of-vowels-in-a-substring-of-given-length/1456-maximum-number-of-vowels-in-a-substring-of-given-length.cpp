class Solution {
public:
    bool check(char s) {
        if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i < k; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                cnt++;
            }
        }
        int m = cnt;
        for(int i = k; i < n; i++) {
            if(check(s[i])) cnt++;
            if(check(s[i-k])) cnt--;
            m = max(m, cnt);
        }
        return m;
    }
};