class Solution {
public:
    bool isAnagram(string s, string t) {
    unordered_map<char, int> count1;
    unordered_map<char, int> count2;
        for(char &x : s)
        {
            count1[x]++;
        }

        for(char &x : t)
        {
            count2[x]++;
        }

        if (count1 == count2)
        {
            return true;
        }
        
        return false;
    }
};
