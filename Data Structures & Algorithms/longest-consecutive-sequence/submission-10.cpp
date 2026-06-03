class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        std::unordered_set<int> s(nums.begin(), nums.end());

        int longest_streak = 1;

        for(int num: s)
        {
            if(s.find(num-1)==s.end())
            {
                int current_num = num;
                int curr_len = 1;

                while(s.find(current_num + 1) != s.end())
                {
                    curr_len++;
                    current_num++;
                }

                longest_streak = max(curr_len, longest_streak);
            }
        }

        return longest_streak;

    }
};
