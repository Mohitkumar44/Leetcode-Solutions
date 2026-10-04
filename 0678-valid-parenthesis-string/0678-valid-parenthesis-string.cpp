class Solution {
public:
    bool checkValidString(string s) {
        int st = 0;
        int count = 0;
        for(char ele : s) {
            if(ele == '(') {
                st++;
            }
            else if(ele == ')') {
                if(st > 0) {
                    st--;
                }
                else if(count>0) {
                    count--;
                }
                else return false;
            }
            else {
                count++;
            }
        }
        if(st > 0 && st > count) return false;
        st = 0;
        count = 0;
        for(int i = s.size()-1; i >= 0; i--) {
            if(s[i] == ')') {
                st++;
            }
            else if(s[i] == '(') {
                if(st > 0) {
                    st--;
                }
                else if(count>0) {
                    count--;
                }
                else return false;
            }
            else {
                count++;
            }
        }
        if(st > 0 && st > count) return false;
        return true;
    }
};