class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int open = 0, close = 0;
        int len = 0;
        for(int i = 0; i < n; i++) {
            if(s[i]=='(') {
                open++;
            }
            else {
                close++;
            }
            if(open == close) len = max(len, 2*open);
            if(close > open) {
                open = 0;
                close = 0;
            }
        }
        open = 0;
        close = 0;
        for(int i = n-1; i >= 0; i--) {
            if(s[i]==')') {
                open++;
            }
            else {
                close++;
            }
            if(open == close) len = max(len, 2*open);
            if(close > open) {
                open = 0;
                close = 0;
            }
        }
        return len;

        // TC = O(n**3).
        // int a = 0;
        // int n = s.size();
        // for(int len = n; len >= 0; len--) {
        //     if(len%2==1) continue;
        //     for(int i = 0; i <= n-len; i++) {
        //         int j = i+len-1;
        //         bool flag = true;
        //         int cnt = 0;
        //         for(int k = i; k <= j; k++) {
        //             if(s[k] == '(') {
        //                 cnt++;
        //             }
        //             else if(cnt > 0) {
        //                 cnt--;
        //             }
        //             else {
        //                 flag = false;
        //                 break;
        //             } 
        //         }
        //         if(flag && cnt == 0)  {
        //             a = max(a, j-i+1);
        //         }
        //     }
        // }
        // return a;
    }
};