class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>result(n,0);
        stack<int>st;

        for(int i = 0; i<n; i++)
        {
            while(!st.empty() &&temperatures[i]>temperatures[st.top()])
            {
                int prev_day_idx = st.top();
                st.pop();

                result[prev_day_idx] = i - prev_day_idx;
            }

            st.push(i);
        }

        return result;
    }
};
