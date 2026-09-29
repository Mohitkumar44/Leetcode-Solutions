class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i = 0; i < n && target - numbers[i] >= numbers[i]; i++) {
            int temp = target - numbers[i];
            int lo = i+1;
            int hi = numbers.size()-1;
            while(lo <= hi) {
                int mid = lo + (hi-lo)/2;
                if(temp == numbers[mid]) return {i+1, mid+1};
                else if(temp < numbers[mid]) hi = mid - 1;
                else lo = mid + 1;
            }
        }
        return {-1,-1};
    }
};