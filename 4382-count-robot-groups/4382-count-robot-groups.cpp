class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int cnt = 1;
        // if(speed.size()==1) return 1;
        for(int i = 1; i < speed.size(); i++) {
            if(speed[i-1] <= speed[i]) cnt++;
        }
        return cnt;
    }
};