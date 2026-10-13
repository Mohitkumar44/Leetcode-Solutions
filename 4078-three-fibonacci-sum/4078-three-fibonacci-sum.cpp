class Solution {
public:
    bool threeFibonacciSum(int n) {
        int b = 0;
        int c = 1;
        int d = 1;
        if(n == 1 or n == 3) return false;
        if(n == 2) return true;
        int temp = d + b + c;
        while(temp <= n) {
            b = c;
            c = d;
            d = b + c;
            temp = d + b + c;
            if(temp == n) return true;
            cout<<d<<" "; 
        }
        if(temp == n) return true;
        return false;        
    }
};