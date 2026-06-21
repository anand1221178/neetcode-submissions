class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>seen;

        while(seen.find(n) == seen.end())
        {
            seen.insert(n);
            n = sumsquares(n);
            if(n==1)
            {
                return true;
            }
        }

        return false;
    }


private:
    int sumsquares(int n)
    {
        int output = 0;

        while(n>0)
        {
            int digit = n%10;
            digit = digit*digit;
            output += digit;

            n/=10;
        }

        return output;
    }
};
