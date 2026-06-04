class Solution {
public:
    bool isPalindrome(string s) {
        int j = s.length()-1;
        bool flag = true;
        for(int i =0; i<s.length(); i++)
        {
            if(i>=j)
            {
                break;
            }
            if(!isalnum(s[i]))
            {
                continue;
            }
            while(j > i && !isalnum(s[j]))
            {
                j--;
            }

            if(tolower(s[i]) == tolower(s[j]))
            {
                j--;
            }
            else
            {
                flag = false;
                break;
            }
        }

        return flag;
    }
};
