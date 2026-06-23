class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
        {
            return "0";
        }

        int m = num1.length();
        int n = num2.length();

        vector<int>res(n+m,0);

        for(int i = m-1; i>=0; i--)
        {
            for(int j = n-1; j>=0; j--)
            {
                int digit1 = num1[i] - '0';
                int digit2 = num2[j] - '0';

                int sum = (digit1 * digit2) + res[i+j+1];

                res[i+j+1] = sum %10;

                res[i+j] += sum/10;
            }
        }


        string result = "";
        for(int val :res)
        {
            if(val != 0 || !result.empty())
            {
                result += to_string(val);
            }
        }

        return result;
    }
};