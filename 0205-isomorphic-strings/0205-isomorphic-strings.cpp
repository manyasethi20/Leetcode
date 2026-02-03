class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mapST[256] = {0}; 
        int mapTS[256] = {0}; 

        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            if (mapST[c1] == 0 && mapTS[c2] == 0) {
                mapST[c1] = c2;
                mapTS[c2] = c1;
            } 
            else {
                if (mapST[c1] != c2 || mapTS[c2] != c1)
                    return false;
            }
        }
        return true;
    }
};
