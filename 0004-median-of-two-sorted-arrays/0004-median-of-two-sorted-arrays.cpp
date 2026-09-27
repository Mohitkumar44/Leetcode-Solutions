class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> nums;
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                nums.push_back(nums1[i]);
                i++;
            } 
            else {
                nums.push_back(nums2[j]);
                j++;
            }
        }
        while(i < m) {
            nums.push_back(nums1[i]);
            i++;
        }
        while(j < n) {
            nums.push_back(nums2[j]);
            j++;
        }
        int k = nums.size();
        cout<<k;
        if(k%2 == 1) {
            return nums[k/2];
        }
        return (nums[k/2] + nums[(k/2)-1])/2.0;
    }
};