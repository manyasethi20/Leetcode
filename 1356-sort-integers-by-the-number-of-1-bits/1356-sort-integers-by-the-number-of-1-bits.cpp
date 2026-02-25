class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> temp;
        
        for (int num : arr) {
            temp.push_back({__builtin_popcount(num), num});
        }
        
        sort(temp.begin(), temp.end());
        
        vector<int> result;
        for (auto &p : temp)
            result.push_back(p.second);
        
        return result;
    }
};