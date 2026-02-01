// Last updated: 2/1/2026, 12:52:42 PM
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1,area = 0,maxArea = INT_MIN;
        while(i <= j){
            area = (min(height[i],height[j])) * (j - i);
            maxArea = max(area,maxArea);
            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxArea;
    }
};