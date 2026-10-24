class Solution {
public:
    bool check(string& a, string& b) {
        int m1 = (a[0]-'0')*10 + (a[1]-'0');
        int m2 = (b[0]-'0')*10 + (b[1]-'0');
        int d1 = (a[3]-'0')*10 + (a[4]-'0');
        int d2 = (b[3]-'0')*10 + (b[4]-'0');

        if((m1 < m2) || (m1 == m2 && d1 <= d2)) return true;
        else return false;
    }

    int count(string& a, string& b, vector<int>& m) {
        if(!check(a, b)) return 0;
        int m1 = (a[0]-'0')*10 + (a[1]-'0');
        int m2 = (b[0]-'0')*10 + (b[1]-'0');
        int d1 = (a[3]-'0')*10 + (a[4]-'0');
        int d2 = (b[3]-'0')*10 + (b[4]-'0');

        int cnt = 0;
        if(m1 == m2) return d2 - d1 + 1;
        else {
            while(m1 != m2) {
                cnt += m[m1-1] - d1 + 1;
                d1 = 1;
                m1++;
            }
            cnt += d2 - d1 + 1;
        }
        return cnt;
    }
    string minimum(string& a, string& b) {
        if(check(a, b)) return a;
        else return b;
    }
    string maximum(string& a, string& b) {
        if(check(a, b)) return b;
        else return a;
    }
    int countDaysTogether(string aa, string la, string ab, string lb) {
        vector<int> m = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string arrive = maximum(aa, ab);
        string leave = minimum(la, lb);
        return count(arrive, leave, m);
    }
};