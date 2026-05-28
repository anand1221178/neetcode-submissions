class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>> anagramMap;

        //Process each key:
        for(string s : strs)
        {
            // create the key of 26 0's
            string key(26,0); //len of 26 and fill with 0;s

            //now we process each char in the string s:
            for (char c : s)
            {
                key[c-'a']++;
            }

            // Add it to the anagram:
            anagramMap[key].push_back(s);
        }  

        // create the result array:
        vector<vector<string>>results;

        for(auto [key,group] : anagramMap)
        {
            results.push_back(std::move(group));
        }

        return results;
    }

};
