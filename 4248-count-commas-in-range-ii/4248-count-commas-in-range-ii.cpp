class Solution {
public:
    long long countCommas(long long n) {
        if( n < (long long)1000) return 0;
        int cnt = 0;
        while(n > (long long)1000) {
            long long temp = n;
            n/=100;
            cnt += temp-n-1;
        }
        return cnt;
    }
};