class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char>letters_seen;

        int left =0;
        int longest_ss = 0;

        for(int right = 0; right<s.length(); ++right)
        {
            while(letters_seen.contains(s[right]))
            {
                letters_seen.erase(s[left]);
                left++;
            }

            letters_seen.insert(s[right]);

            int current_window_size = right - left + 1;
            if (current_window_size > longest_ss) {
                longest_ss = current_window_size;
            }
        }

        return longest_ss;
    }
};
