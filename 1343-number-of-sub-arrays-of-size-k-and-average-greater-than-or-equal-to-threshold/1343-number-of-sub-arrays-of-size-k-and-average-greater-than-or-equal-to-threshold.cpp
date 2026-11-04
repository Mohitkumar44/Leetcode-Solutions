class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int s = 0;
        for(int i = 0; i < k; i++) {
            s += arr[i];
        }
        int cnt = 0;
        if(s/k >= threshold) cnt++;
        for(int i = k; i < n; i++) {
            s += arr[i];
            s -= arr[i-k];
            if(s/k >= threshold) cnt++;
        }
        return cnt;
    }
};