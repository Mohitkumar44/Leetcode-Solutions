class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for(char ch : magazine) {
            mp[ch]++;
        }
        for(int i = 0; i < ransomNote.size(); i++) {
            if(mp[ransomNote[i]] <= 0) return false;
            else mp[ransomNote[i]]--;
        }
        return true;
    }
};