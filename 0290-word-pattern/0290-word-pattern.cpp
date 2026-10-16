class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = s.size();
        vector<string> words;
        int t = 0;
        string temp = "";
        for(int i = 0; i < n; i++) {
            if(i != t && s[i] == ' ') {
                words.push_back(temp);
                temp = "";
                t = i+1;
            }
            else {
                temp += s[i];
            }
        }
        words.push_back(temp);

        if(pattern.size() != words.size()) return false;
        unordered_map<char, string> mp;
        for(int i = 0; i < pattern.size(); i++) {
            if(mp.find(pattern[i]) != mp.end() && mp[pattern[i]] != words[i]) {
                return false;
            }
            else if(mp.find(pattern[i]) == mp.end()) {
                mp[pattern[i]] = words[i];
            }
        }
        unordered_map<string, char> rev;
        for(int i = 0; i < pattern.size(); i++) {
            if(rev.find(words[i]) != rev.end() && rev[words[i]] != pattern[i]) {
                return false;
            }
            else if(rev.find(words[i]) == rev.end()) {
                rev[words[i]] = pattern[i];
            }
        }
        return true;
    }
};