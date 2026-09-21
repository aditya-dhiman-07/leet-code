class Solution {
private: 
    int checkThreshold(vector<int>& nums, int divisor){
        int ans = 0;
        for(int i = 0; i < nums.size() ; i++){
            ans+=(nums[i] + divisor - 1) / divisor;
        }
        return ans;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while(low<=high){
            int mid = (low+high)/2;
            if(checkThreshold(nums,mid)<=threshold) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};