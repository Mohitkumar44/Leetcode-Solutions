class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int count = 0;
        int ans = 0;
        int i = 0;
        while(i < n) {
            if(s[i] == '(') {
                count++;
                i++;
            }
            else { // s[i] == ')'
                if(count > 0) {
                    count--;
                }
                else {
                    ans++;   // if count is negative.
                }

                if(i + 1 < n && s[i + 1] == ')') {  //checking i+1.
                    i += 2;
                }
                else {
                    i += 1;
                    ans++;     //next bracket is open or does not exist.
                }
            }
        }
        return ans + count*2;   //result
    }
};