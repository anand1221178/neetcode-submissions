class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m  = matrix.size(); // rows
        int n = matrix[0].size(); //cols

        // Check which row:
        for(int i =0 ; i<m; i++)
        {
            if((target >= matrix[i][0]) && (target<=matrix[i][n-1]))
            {
                // Do bst to find the element:
                int l=0;
                int r = n-1;

                while(l<=r)
                {
                    int mpt = l+(r-1)/2;

                    if(target == matrix[i][mpt])
                    {
                        return true;
                    }
                    else if(matrix[i][mpt] < target)
                    {
                        l = mpt+1;
                    }
                    else
                    {
                        r = mpt-1;
                    }
                }
            }
        }

        return false;
    }
};
