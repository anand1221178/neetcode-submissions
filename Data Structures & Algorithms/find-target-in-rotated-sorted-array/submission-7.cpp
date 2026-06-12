    class Solution {
    public:
        int search(vector<int>& nums, int target) {
            // Initial check for if rotated:
            if(nums[0] == target)
            {
                return 0;
            }

            int l =0;
            int r = nums.size()-1;

            while(l<=r)
            {
                int mpt = l + (r-l)/2;

                if(nums[mpt] == target)
                {
                    return mpt;
                }

                // left half is sorted
                if (nums[l] <= nums[mpt]) {
                    if (target >= nums[l] && target < nums[mpt]) {
                        r = mpt-1;
                    } else {
                        l = mpt+1;
                        
                    }
                }

                // right half is sorted
                else {
                    if (target > nums[mpt] && target <= nums[r]) {
                        l = mpt+1;
                    } else {
                        // go left
                        r = mpt-1; 
                    }
                }

            }
            
            return -1;
        }
    };
