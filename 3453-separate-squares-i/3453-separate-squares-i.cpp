class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        map<long double, long double> events;
        long double totalArea = 0;

        for (auto &s : squares) {
            long double y = s[1], l = s[2];
            events[y] += l;
            events[y + l] -= l;
            totalArea += l * l;
        }

        long double target = totalArea / 2.0;
        long double currArea = 0, slope = 0;
        long double prevY = 0;
        bool first = true;

        for (auto &[y, delta] : events) {
            if (!first) {
                long double height = y - prevY;
                long double segmentArea = slope * height;

                if (currArea + segmentArea >= target) {
                    long double need = target - currArea;
                    return (double)(prevY + need / slope);
                }
                currArea += segmentArea;
            }
            slope += delta;
            prevY = y;
            first = false;
        }

        return (double)prevY;
    }
};
