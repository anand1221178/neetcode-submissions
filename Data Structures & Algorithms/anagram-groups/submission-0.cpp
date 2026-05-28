class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>anagramMap;

        for(const string& word : strs)
        {
            string key(26,0);

            for(char c : word)
            {
                key[c-'a']++;
            }

            anagramMap[key].push_back(word);
        }

        vector<vector<string>>result;
        result.reserve(anagramMap.size());

        for(auto& [key,group] : anagramMap)
        {
            result.push_back(std::move(group));
        }
        return result;
    }

};
