class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> mh;

        for(int i =0; i < nums.size(); i++)
        {
            if(mh.size() < k)
            {
                mh.push(nums[i]);
            }
            else if(nums[i] > mh.top())
            {
                mh.pop();
                mh.push(nums[i]);
            }
        }

        return mh.top();
    }
};
