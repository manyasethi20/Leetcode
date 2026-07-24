class Solution {
public:
    int maxArea(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        int width, height, area, maxArea = 0;
        while(left < right) {
            width = right - left;
            height = min(arr[left], arr[right]);
            area = width * height;
            maxArea = max(maxArea, area);

            if(arr[left] <= arr[right]) left++;
            else right--;
        }
        return maxArea;
    }
};