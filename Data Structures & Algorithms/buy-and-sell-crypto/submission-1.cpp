class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int left = 0; //IDX


        for(int right = 1; right < prices.size(); ++right)
        {
            int curr_profit = prices[right] - prices[left];
            if(curr_profit > max_profit)
            {
                max_profit = curr_profit;
            }

            if(prices[right]< prices[left])
            {
                left = right;
            }

        }

        return max_profit;
    }
};
