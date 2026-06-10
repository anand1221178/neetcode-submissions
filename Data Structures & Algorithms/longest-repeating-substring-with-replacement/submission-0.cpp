class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>cnt;
        int maxFreq = 0; 
        int left = 0; 

        for(int right =0 ; right < s.length(); right++)
        {
            cnt[s[right]]++;
            maxFreq = max(maxFreq,cnt[s[right]]);
            // check if valid
            if(!((right-left+1-maxFreq) <= k))
            {
                cnt[s[left]]--;
                left++;
            }
        }

        return s.length()-left;
    }
};
