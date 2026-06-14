class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char>rows[9];
        unordered_set<char>cols[9];
        unordered_set<char>sub_box[9];

        for(int i =0 ; i < 9; i++)
        {
            for(int j = 0; j<9; j++)
            {
                char val = board[i][j];

                if(val == '.')
                {
                    continue;
                }

                int box_idx = (i/3)*3+(j/3);

                if(rows[i].count(val) || cols[j].count(val) || sub_box[box_idx].count(val))
                {
                    return false;
                }

                rows[i].insert(val);
                cols[j].insert(val);
                sub_box[box_idx].insert(val);
            }
        }

        return true;
    }
};
