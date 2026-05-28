class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // value -> index
        for(int i =0 ; i < nums.size(); i++)
        {
            int comp = target - nums[i];
            if(seen.contains(comp))
            {
                return {seen[comp], i};
            }
                seen[nums[i]] = i;
        }

        return {};
    }
};