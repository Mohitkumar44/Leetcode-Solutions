class Solution {
public:
    long long power(long long x, int n){
        int mod = 1000000007;
        if(n==0) return 1;
        if(n==1) return x;
        if(n%2){
            return ((x%mod)*(power(x, n-1))%mod)%mod;
        }
        else{
            return (power((x*x)%mod, n/2))%mod;
        }
    }
    int sumDecoded(vector<long long>& nums) {
        int sum = 0;
        int mod = 1000000007;
        for(int i = 0; i < nums.size(); i++){
            long long val = 0;
            int widthi = nums[i] % 10;
            long long di = floor(nums[i] / 10);
            long long t = di;
            int d = 0;
            while(t) {
                t/=10;
                d++;
            }
            int x = di / (int)(pow(10, d - widthi));
            int y = di % (int)(pow(10, d - widthi));
            val = power(x, y);
            sum = sum%mod;
            sum += val;
            sum = sum%mod;
        }
        return sum%mod;
    }
};