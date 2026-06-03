class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int longest = 1;
        int curr_len = 1;
        
        for(int i =0; i < nums.size()-1; i++)
        {
            if(nums[i+1]- nums[i] == 1)
            {
                curr_len++;
                longest = max(curr_len,longest);
            }
            else if(nums[i+1] - nums[i] == 0)
            {
                continue;
            }
            else
            {
                curr_len=1;
            }
        }

        return longest;
    }
};
