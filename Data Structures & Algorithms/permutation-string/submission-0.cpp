class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length() < s1.length())
        {
            return false;
        }

        unordered_map<char,int>s1_map;
        for(int i =0; i < s1.length(); i++)
        {
            s1_map[s1[i]]++;
        }

        unordered_map<char,int>window;

        int left = 0;
        for(int right = 0; right < s2.length(); ++right)
        {
            window[s2[right]]++;
            if(right-left+1 > s1.length())
            {
                window[s2[left]]--;
                if(window[s2[left]] == 0)
                {
                    window.erase(s2[left]);
                }
                left++;
            }


            if(right-left+1 == s1.length())
            {
                if(window == s1_map)
                {
                    return true;
                }
            }

        }

        return false;
    }
};
