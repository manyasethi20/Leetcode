class Solution {
public:
    bool checkOnesSegment(string s) {
        int blocks = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1' && (i == 0 || s[i-1] == '0'))
                blocks++;
        }

        return blocks <= 1;
    }
};