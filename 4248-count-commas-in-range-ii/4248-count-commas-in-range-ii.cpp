class Solution {
public:
    long long countCommas(long long n) {
        long long cnt = 0;
        if(n >= 1000000000000000) {
            cnt += 5*(n-999999999999999);
            n = 999999999999999;
        }
        if(n >= 1000000000000) {
            cnt += 4*(n-999999999999);
            n = 999999999999;
        }
        if(n >= 1000000000) {
            cnt += 3*(n-999999999);
            n = 999999999;
        }
        if(n >= 1000000) {
            cnt += 2*(n-999999);
            n = 999999;
        }
        if(n >= 1000) {
            cnt += 2*(n-999);
        }
        return cnt;
    }
};