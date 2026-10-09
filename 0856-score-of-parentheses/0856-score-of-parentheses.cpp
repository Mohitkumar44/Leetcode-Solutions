class Solution {
public:
    int f(string& s, int st, int ed) {
        if(st+1 == ed) return 1;
        int d = -1;
        int c = 0;
        for(int i = st; i <= ed; i++) {
            if(s[i] == '(') {
                if(i != st && c == 0) {
                    d = i;
                    break;
                }
                c++;
            }
            else {
                c--;
            }
        }
        if(d == -1) {
            return 2 * f(s, st+1, ed-1);
        }
        else return f(s, st, d-1) + f(s, d, ed);
    }
    int scoreOfParentheses(string s) {
        return f(s, 0, s.size()-1);
    }
};