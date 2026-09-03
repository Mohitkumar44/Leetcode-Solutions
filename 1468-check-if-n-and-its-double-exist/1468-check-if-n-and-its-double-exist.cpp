class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;
        for(int ele : arr) {
            if(st.find(ele*2)!=st.end() || (ele%2==0 && st.find(ele/2)!=st.end())) return true;
        }
        return false;
    }
};