class Solution {
public:
    bool isValid(string s) {
        stack<char> openers;

        for(int i = 0; i < s.length(); i++)
        {
            // If opener add to stack
            if((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
            {
                openers.push(s[i]);
            }
            else
            {
                if(openers.empty())
                {
                    return false;
                    break;
                }
                if((openers.top() == '(') && (s[i] != ')'))
                {
                    return false;
                    break;
                }
                else if((openers.top() == '[') && (s[i] != ']'))
                {
                    return false;
                    break;
                }
                else if((openers.top() == '{') && (s[i] != '}'))
                {
                    return false;
                    break;
                }
                else
                {
                    openers.pop();
                }
            }

        }

        return openers.empty();
    }
};
