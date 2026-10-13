class Solution {
public:
    bool check(int n) { // check for prime number.
        for(int i = 2; i*i <= n; i++) {
            if(n%i == 0) return false;
        }
        return true;
    }
    vector<int> maxPrimes(int n, int s) {
        vector<int> sieve(n+1, 0);
        vector<int> ans;
        int sum = 0;
        for(int i = 2; i <= n; i++) {
            if(sieve[i] == 1) continue;   // skip precalculated nums
            else if(check(i)) {    // check once
                sum += i;    // add to sum
                if(sum > s) break;
                ans.push_back(i);    // add to final ans
                int temp = 2;
                while(i*temp <= n) {    // fill sieve for a particular num
                    sieve[i*temp] = 1;
                    temp++;
                }
            }
        }
        return ans;
    }
};