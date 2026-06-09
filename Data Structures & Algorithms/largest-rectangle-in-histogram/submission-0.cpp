class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();

        stack<int>monotoneStack;

        vector<int> leftBoundary(n, -1);
        vector<int> rightBoundary(n, n);

        // Single pass to find both left and right boundaries:
        for(int i = 0; i < n; i++)
        {
            while(!monotoneStack.empty() && heights[monotoneStack.top()]>=heights[i])
            {
                rightBoundary[monotoneStack.top()] = i;
                monotoneStack.pop();
            }

            if (!monotoneStack.empty()) {
                leftBoundary[i] = monotoneStack.top();
            }

            monotoneStack.push(i);
        }

        for (int i = 0; i < n; ++i) {
            // Width extends from (leftBoundary + 1) to (rightBoundary - 1)
            int width = rightBoundary[i] - leftBoundary[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }
      
        return maxArea;
    }
};
