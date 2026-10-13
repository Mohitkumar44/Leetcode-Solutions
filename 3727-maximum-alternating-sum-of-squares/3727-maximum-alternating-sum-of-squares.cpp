class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> pq;
        for(int i = 0; i < n; i++) {
            pq.push(abs(nums[i]));
        }
        int size = 0;
        if(n%2) size = n/2 + 1;
        else size = n/2;
        long long ans = 0;
        while(size) {
            int ele = pq.top();
            size--;
            pq.pop();
            ans += ele*ele;
        }
        while(pq.size()) {
            int ele = pq.top();
            size--;
            pq.pop();
            ans -= ele*ele;
        }
        return ans;
    }
};