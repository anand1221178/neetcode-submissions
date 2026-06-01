class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total_product_nonzero = 1;
        int num_zeros = 0;
        
        for (int num : nums) {
            if (num == 0) {
                num_zeros++;
            } else {
                total_product_nonzero *= num;
            }
        }
        
        vector<int> res;
        for (int num : nums) {
            if (num_zeros >= 2) {
                res.push_back(0);
            } else if (num_zeros == 1) {
                if (num == 0) {
                    // The only zero → product of all non‑zero numbers
                    res.push_back(total_product_nonzero);
                } else {
                    // Other indices → 0 because the product includes the zero
                    res.push_back(0);
                }
            } else { // num_zeros == 0
                res.push_back(total_product_nonzero / num);
            }
        }
        return res;
    }
};