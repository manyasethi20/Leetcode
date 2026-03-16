class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        set<int, greater<int>> st;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                st.insert(grid[i][j]);

                int maxRadius = min({i, j, m-1-i, n-1-j});

                for(int r=1;r<=maxRadius;r++){

                    int sum = 0;

                    int x=i-r, y=j;

                    for(int k=0;k<r;k++)
                        sum += grid[x+k][y+k];

                    for(int k=0;k<r;k++)
                        sum += grid[i+k][j+r-k];

                    for(int k=0;k<r;k++)
                        sum += grid[i+r-k][j-k];

                    for(int k=0;k<r;k++)
                        sum += grid[i-k][j-r+k];

                    st.insert(sum);
                }
            }
        }

        vector<int> ans;

        for(auto x : st){
            ans.push_back(x);
            if(ans.size()==3) break;
        }

        return ans;
    }
};