class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;


        while(l<=r)
        {
            int mpt = l+(r-l)/2;
            // First check if we are opn the elemtn:
            if (nums[mpt] == target)
            {
                return mpt;
            }
            else if(nums[mpt] < target)
            {
                l = mpt + 1;
            }
            else
            {
                r = mpt-1;
            }

        }

        return -1;
    }
};
