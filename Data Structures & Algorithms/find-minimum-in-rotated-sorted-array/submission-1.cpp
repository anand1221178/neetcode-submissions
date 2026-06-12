class Solution {
public:
    int findMin(vector<int> &nums) {
        // Check if its rotated:
        if(nums[0] - nums[nums.size()-1] < 0)
        {
            return nums[0];
        }

        int l = 0;
        int r = nums.size()-1;

        while(l<r)
        {
            int mpt = l+(r-l)/2;
            
            if(nums[mpt] > nums[r])
            {
                // min is on the right of mpt
                l = mpt+1;
            }
            else
            {
                // min is on the left of mpt:
                r = mpt;
            }
        }

        return nums[l];
    }
};
