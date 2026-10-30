class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt++;
            int a = i-1;
            int b = i+1;
            while(a >= 0 && b <= n-1) {
                if(s[a] == s[b]) {
                    cnt++;
                    a--;
                    b++;
                }
                else break;
            }
        }
        for(int i = 0; i < n-1; i++) {
            int a = i;
            int b = i+1;
            while(a >= 0 && b <= n-1) {
                if(s[a] == s[b]) {
                    cnt++;
                    a--;
                    b++;
                }
                else break;
            }
        }
        return cnt;
    }
};