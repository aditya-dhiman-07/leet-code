class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int max_stored = 0;
        while(l<r){
            int area = (r-l)*min(height[l], height[r]);
            max_stored = max(max_stored, area);
            if(height[l]<=height[r]) l++;
            else r--;
        }
        return max_stored;
    }
};