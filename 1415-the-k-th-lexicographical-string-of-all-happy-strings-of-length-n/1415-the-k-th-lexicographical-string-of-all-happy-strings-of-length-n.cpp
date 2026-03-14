class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 3 * (1 << (n - 1));
        if(k > total) return "";

        string res="";
        vector<char> chars={'a','b','c'};

        int block = 1 << (n-1);

        for(int i=0;i<3;i++){
            if(k>block) k-=block;
            else{
                res.push_back(chars[i]);
                break;
            }
        }

        for(int i=1;i<n;i++){
            block >>=1;

            for(char ch='a';ch<='c';ch++){
                if(ch==res.back()) continue;

                if(k>block) k-=block;
                else{
                    res.push_back(ch);
                    break;
                }
            }
        }

        return res;
    }
};