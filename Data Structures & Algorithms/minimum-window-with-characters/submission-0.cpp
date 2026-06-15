class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>target;
        unordered_map<char,int>window;

        int min_len = INT_MAX;
        int min_start = 0;

        // Build the target hashmap
        for(char c : t)
        {
            target[c]++;
        }

        int left = 0;
        int need = target.size();
        int have = 0;

        for(int right = 0; right < s.length(); right++)
        {
            char c = s[right];
            window[c]++;

            // Check if we need this char:
            if(target.contains(c))
            {
                if(window[c] == target[c])
                {
                    have++;
                }
            }

            while(have == need)
            {
                int len = right-left+1;
                if(len < min_len)
                {
                    min_len = len;
                    min_start = left;
                }

                char left_char = s[left];
                window[left_char]--;

                if(target.contains(left_char))
                {
                    if(window[left_char] < target[left_char])
                    {
                        have--;
                    }
                }

                left++;
            }
        }

        if(min_len == INT_MAX)
        {
            return "";
        }
        else
        {
            return s.substr(min_start, min_len);
        }

    }
};
