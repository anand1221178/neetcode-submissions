class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        int right;
        vector<int>window;
        vector<int>max_ele;

        for(int right = left + k -1; right < nums.size(); ++right)
        {    // initial fill
            if(left == 0)
            {
                for(int i =0; i < k; i++)
                {
                    window.push_back(nums[i]);
                }
            }

            // Add the max element from the vector to the answer array
            max_ele.push_back(*std::max_element(nums.begin()+left,nums.begin() + left +k));

            // Reomve the last element:
            window.erase(window.begin());

            // move left forward by 1:
            left++;

            // add new alement into front;
            window.push_back(nums[right]);
        }

        return max_ele;
    }
};
