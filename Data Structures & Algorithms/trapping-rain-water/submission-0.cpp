class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int left = 0;
        int right = height.size() - 1;
        
        int left_max = height[left];
        int right_max = height[right];
        
        int total_water = 0;

        // The Heartbeat
        while (left < right) {
            
            // STEP 1: The Bottleneck Check
            if (left_max < right_max) {
                // STEP 2: The Step (Left side is bottleneck)
                left++;
                // STEP 3: The History Update
                left_max = max(left_max, height[left]);
                // STEP 4: The Pour
                total_water += left_max - height[left];
            } 
            else {
                // STEP 2: The Step (Right side is bottleneck or tie)
                right--;
                // STEP 3: The History Update
                right_max = max(right_max, height[right]);
                // STEP 4: The Pour
                total_water += right_max - height[right];
            }
        }

        return total_water;
    }
};
