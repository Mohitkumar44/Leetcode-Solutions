class Solution {
public:
    long long countCommas(long long n) {
        if( n < (long long)1000) return 0;
        else if( n < (long long)100000) return n-(long long)999;
        else if( n < (long long)10000000) return n-(long long)99999;
        else if( n < (long long)1000000000) return n-(long long)9999999;
        else if( n < (long long)100000000000) return n-(long long)999999999;
        else if( n < (long long)10000000000000) return n-(long long)99999999999;
        else if( n < (long long)1000000000000000) return n-(long long)9999999999999;
        return -1;
    }
};