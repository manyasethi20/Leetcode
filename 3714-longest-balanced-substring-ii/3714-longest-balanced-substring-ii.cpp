class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size(), ans=1;

        int cur=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]) cur++;
            else cur=1;
            ans=max(ans,cur);
        }

        auto solve2 = [&](char x,char y,char block){
            int best=0;
            unordered_map<int,int> mp;
            int diff=0;
            mp[0]=-1;

            for(int i=0;i<n;i++){
                if(s[i]==block){
                    mp.clear();
                    mp[0]=i;
                    diff=0;
                    continue;
                }
                if(s[i]==x) diff++;
                if(s[i]==y) diff--;

                if(mp.count(diff))
                    best=max(best,i-mp[diff]);
                else
                    mp[diff]=i;
            }
            return best;
        };

        ans=max(ans,solve2('a','b','c'));
        ans=max(ans,solve2('a','c','b'));
        ans=max(ans,solve2('b','c','a'));

        {
            map<pair<int,int>,int> mp;
            mp[{0,0}]=-1;

            int a=0,b=0,c=0;
            for(int i=0;i<n;i++){
                if(s[i]=='a') a++;
                else if(s[i]=='b') b++;
                else c++;

                pair<int,int> key={a-b,a-c};

                if(mp.count(key))
                    ans=max(ans,i-mp[key]);
                else
                    mp[key]=i;
            }
        }

        return ans;
    }
};
