class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res;
        string str = "";
        for(int i = 0; i < n; i++) {
            str += '.';
        }
        res.push_back(str);
        str = "";
        for(int i = 0; i < n-1; i++) {
            str += '#';
        }
        str += '.';
        for(int i = 0; i < m-1; i++) {
            res.push_back(str);
        }
        return res;
    }
};