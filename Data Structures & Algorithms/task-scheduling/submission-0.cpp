class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        
        // 1. Count the frequencies of all 26 letters
        vector<int> freq(26, 0);
        int max_freq = 0;
        
        for (char task : tasks) {
            freq[task - 'A']++;
            max_freq = max(max_freq, freq[task - 'A']); // Find the highest frequency
        }
        
        // 2. How many different tasks have this exact max_freq? (Ties)
        int max_count = 0;
        for (int f : freq) {
            if (f == max_freq) {
                max_count++;
            }
        }
        
        // 3. The Magic Formula!
        int formula_time = (max_freq - 1) * (n + 1) + max_count;
        
        // 4. If the formula gives us a number SMALLER than the total tasks, 
        // it means we never idled. So just return the number of tasks!
        return max((int)tasks.size(), formula_time);
    }
};
