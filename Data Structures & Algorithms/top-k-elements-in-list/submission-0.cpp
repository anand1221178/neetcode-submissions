class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freqs;

        for(int i =0 ; i < nums.size(); i++)
        {
            freqs[nums[i]]++;
        }

        std::priority_queue<std::pair<int, int>> pq;

        for(auto& pair : freqs)
        {
            pq.push({pair.second, pair.first});
        }

        vector<int>result;

        for(int i = 0; i < k; i++)
        {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
