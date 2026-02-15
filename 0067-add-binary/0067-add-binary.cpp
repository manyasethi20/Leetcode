class Solution {
public:
    string addBinary(string a, string b) {
        string res="";
        int i=a.size()-1,j=b.size()-1,carry=0;

        while(i>=0 || j>=0 || carry){
            int x = (i>=0)?a[i--]-'0':0;
            int y = (j>=0)?b[j--]-'0':0;

            res.push_back((x^y^carry)+'0');
            carry = (x&y) | (y&carry) | (x&carry);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
