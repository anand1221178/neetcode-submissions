class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>nums;

        // Iterator loop
        for(int i = 0; i< tokens.size(); i++)
        {
            if((tokens[i]!= "+")&&(tokens[i]!= "-")&&(tokens[i]!= "*")&&(tokens[i]!= "/"))
            {
                nums.push(stoi(tokens[i]));
            }
            else //operation
            {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                
                if(tokens[i] == "+")
                {
                    nums.push(a+b);
                }
                else if (tokens[i] == "-")
                {
                    nums.push(b-a);
                }
                else if (tokens[i] == "*")
                {
                    nums.push(a*b);
                }
                else
                {
                    nums.push(b/a);
                }
            }
        }
        return nums.top();
    }
};
