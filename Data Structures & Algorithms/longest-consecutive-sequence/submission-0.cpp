class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        // Step 1: Insert into set (removes duplicates and sorts)
        set<int> s(nums.begin(), nums.end());

        int longest_streak = 1;
        int current_streak = 1;

        // Step 2: Iterate through the sorted set
        // We start from the second element
        auto it = s.begin();
        int prev = *it;
        it++;

        while (it != s.end()) {
            if (*it == prev + 1) {
                current_streak++;
            } else {
                // Sequence broke, update global max and reset current
                longest_streak = max(longest_streak, current_streak);
                current_streak = 1;
            }
            prev = *it;
            it++;
        }

        // One last check for the final sequence
        return max(longest_streak, current_streak);
    }
};
