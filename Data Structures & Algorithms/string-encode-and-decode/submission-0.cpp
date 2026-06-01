class Solution {
public:

    string encode(vector<string>& strs) {
        //Loop throigh the string:
        string encoded_string="";
        for (string s: strs)
        {
            encoded_string+=to_string(s.length());
            encoded_string+='#'; //delimiter
            encoded_string+=s;
        }

        return encoded_string;
        
    }

    vector<string> decode(string s) {
    vector<string> result;          // this will hold the decoded strings
    int i = 0;                      // current position in the encoded string

    while (i < s.length()) {
        // Find the next '#'
        int j = i;
        while (j < s.length() && s[j] != '#') {
            j++;
        }
        // Now s[j] is '#', and s[i..j-1] is the length (as digits)

        // Get the length substring and convert to int
        string lenStr = s.substr(i, j - i);
        int len = stoi(lenStr);

        // The actual string starts right after '#'
        int wordStart = j + 1;
        string word = s.substr(wordStart, len);
        result.push_back(word);

        // Move i to the position after this word
        i = wordStart + len;
    }

    return result;
    }
};
