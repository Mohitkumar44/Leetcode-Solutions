class Solution {
public:
    bool check(long long num) {
        if(num < 2) return false;
        for(long long i = 2; i*i <= num; i++) {
            if(num%i == 0) return false;
        }
        return true;
    }
    long long number(string& s, int i, int j) {
        int n = s.size();
        long long num = 0;
        for(int k = i; k <= j; k++) {
            num *= 10;
            num += s[k] - '0';
        }
        return num;
    }
    long long sumOfLargestPrimes(string s) {
        int n = s.size();
        priority_queue<long long> pq;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                long long no = number(s, i, j);
                if(check(no)) {
                    pq.push(no);
                }
            }
        }
        long long a = 0, b = 0, c = 0;
        if(pq.size() > 0) a = pq.top();
        while(pq.size() > 0 && pq.top() == a) pq.pop();
        if(pq.size() > 0 && pq.top()!=a) b = pq.top();
        while(pq.size() > 0 && pq.top() == b) pq.pop();
        if(pq.size() > 0 && pq.top()!=b) c = pq.top();
        cout<<a<<" "<<b<<" "<<c;
        return a + b + c;
    }
};