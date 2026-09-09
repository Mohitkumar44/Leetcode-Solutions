class Solution {
public:
    long long countCommas(long long n) {
        long long cnt = 0;
        if( (long long)n >= (long long)1000000000000000) {
            cnt += (long long)((long long)4*(long long)((long long)n-(long long)999999999999999));
            n = (long long)999999999999999;
        }
        if( (long long)n >= (long long)1000000000000) {
            cnt += (long long)((long long)4*(long long)((long long)n-(long long)999999999999));
            n = (long long)999999999999;
        }
        if( (long long)n >= (long long)1000000000) {
            cnt += (long long)((long long)3*(long long)((long long)n-(long long)999999999));
            n = (long long)999999999;
        }
        if( (long long)n >= (long long)1000000) {
            cnt += (long long)((long long)2*(long long)((long long)n-(long long)999999));
            n = (long long)999999;
        }
        if( (long long)n >= (long long)1000) {
            cnt += (long long)((long long)n-(long long)999);
        }
        return cnt;
    }
};