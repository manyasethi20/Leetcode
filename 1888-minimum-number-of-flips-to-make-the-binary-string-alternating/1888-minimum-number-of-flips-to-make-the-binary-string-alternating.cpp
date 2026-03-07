class Solution {
public:
    int minFlips(string s) {
        
        int n = s.size();
        s += s;

        int diff1=0, diff2=0;
        int ans = INT_MAX;
        int l=0;

        for(int r=0;r<s.size();r++){
            
            char alt1 = (r%2 ? '1':'0');
            char alt2 = (r%2 ? '0':'1');

            if(s[r]!=alt1) diff1++;
            if(s[r]!=alt2) diff2++;

            if(r-l+1 > n){
                
                char leftAlt1 = (l%2 ? '1':'0');
                char leftAlt2 = (l%2 ? '0':'1');

                if(s[l]!=leftAlt1) diff1--;
                if(s[l]!=leftAlt2) diff2--;

                l++;
            }

            if(r-l+1 == n)
                ans = min(ans, min(diff1,diff2));
        }

        return ans;
    }
};