class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long double totalArea = 0;
        long double low = 1e18, high = -1e18;

        for (auto &s : squares) {
            long double y = s[1], l = s[2];
            totalArea += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        long double target = totalArea / 2.0;

        auto areaBelow = [&](long double h) {
            long double area = 0;
            for (auto &s : squares) {
                long double y = s[1], l = s[2];
                if (h <= y) continue;
                else if (h >= y + l) area += l * l;
                else area += (h - y) * l;
            }
            return area;
        };

        for (int i = 0; i < 80; i++) { 
            long double mid = (low + high) / 2;
            if (areaBelow(mid) < target)
                low = mid;
            else
                high = mid;
        }

        return (double)low;
    }
};
