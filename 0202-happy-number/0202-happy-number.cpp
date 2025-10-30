#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> viewed;

        while(n != 1 && viewed.find(n) == viewed.end()) {
            viewed.insert(n);
            n = getSumOfSquares(n);
        }
        return n == 1;
    }
    private:
    int getSumOfSquares(int num) {
        int sum = 0;
        while(num > 0) {
            int digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }
        return sum;
    }
};