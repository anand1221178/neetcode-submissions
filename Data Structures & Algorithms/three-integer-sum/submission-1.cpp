class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for(int i =0; i<nums.size()-2;i++)
        {
            if(nums[i] > 0)
            {
                break;
            }

            // Dup check -> skip identical starting elements:
            if(i>0&&nums[i] == nums[i-1])
            {
                continue;
            }

            // 2ptr setup:
            int left = i+1;
            int right = nums.size()-1;

            while(left<right)
            {
                int sum = nums[i] + nums[left]+nums[right];

                if(sum == 0)
                {
                    res.push_back({nums[i], nums[left], nums[right]});

                    // DUp check 2 -> skip identical elements for the lfet ptr:
                    while(left < right && nums[left] == nums[left+1])
                    {
                        left++;
                    }

                    while(left<right && nums[right] == nums[right-1])
                    {
                        right--;
                    }

                    // Move both inwards:
                    left++;
                    right--;
                }
                else if(sum < 0)
                {
                    left++;
                }
                else{
                    right--;
                }
            }
        }

        return res;
    }
};
