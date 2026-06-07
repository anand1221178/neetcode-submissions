class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_water =0;
        int left = 0; 
        int right = heights.size()-1;

        while(left<right)
        {
            int curr_water = (right-left) * min(heights[left], heights[right]);

            if(curr_water > max_water)
            {
                max_water = curr_water;
            }

            if(heights[left] <= heights[right])
            {
                left++;
            }
            else if(heights[left] >= heights[right])
            {
                right--;
            }
        }

        return max_water;
    }
};
