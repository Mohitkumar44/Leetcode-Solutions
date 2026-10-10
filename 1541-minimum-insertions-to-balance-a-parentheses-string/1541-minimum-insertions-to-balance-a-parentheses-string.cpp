class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int i = 0;
        int open = 0;
        int ans = 0;
        while(i < n) {
            if(s[i] == '(') {
                open++;
                i++;
            }
            else {    // s[i] == ')'
                if(i + 1 < n) {
                    if(s[i + 1] == ')') {
                        if(open > 0) {
                            open--;
                        }
                        else {   //s[i] == '('
                            ans++;
                        }
                        i += 2;
                    }
                    else {   
                        if(open > 0) {
                            open--;
                            ans++;
                        }
                        else {   //s[i] == '('
                            ans += 2;
                        }
                        i++;
                    }
                }
                else { // index is out of bound
                    if(open > 0) {
                        open--;
                        ans++;
                    }
                    else {
                        ans += 2;
                    }
                    break;
                }
            }
        }
        if(open > 0) ans += open*2;
        return ans;
    }
};