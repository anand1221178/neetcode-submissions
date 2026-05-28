class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        bool dup = false;
        for(int i =0; i < nums.size(); i ++)
        {
            int num = nums[i];
            for (int j = i+1; j < nums.size(); j++)
            {
                if (num == nums[j])
                {
                    dup = true;
                    break;
                }
            }
        }   

        return dup;
    }
};