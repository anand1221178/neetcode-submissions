class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count1;
        unordered_map<char, int> count2;
        if(s.size() != t.size()) return false;

        for(int i = 0; i < t.size(); i++)
        {
            count1[s[i]]++;
            count2[t[i]]++;
        }

        if (count1 == count2)
        {
            return true;
        }
        
        return false;
    }
};
