class Solution {
public:
    int minOperations(string s) {
        string str = s;
        sort(str.begin(), str.end());
        if(str == s) return 0;
        if(str.size() == 2) {
            if(str == s) return 0;
            else return -1;
        }
        char mn = str[0];
        char mx = str[str.size()-1];
        cout<<mn<<" "<<mx;
        if(s[0] == mn || s[s.size()-1] == mx) return 1;
        bool flag1 = true, flag2 = true;
        for(int i = 0; i < s.size()-1; i++) {
            if(s[i] == mn) {
                flag1 = false;
                break;
            }
        }
        for(int i = s.size()-1; i > 0; i--) {
            if(s[i] == mx) {
                flag2 = false;
                break;
            }
        }
        if(flag1 && flag2) return 3;
        else return 2;
    }
};