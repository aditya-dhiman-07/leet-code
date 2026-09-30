class Solution {
private:
    bool minLargestSplit(vector<int>& nums, int k, int max_sum){
        int req = 1;
        int currSum=0;
        for(int num:nums){
            if(currSum+num>max_sum){
                req++;
                currSum = num;
            }
            else currSum+=num;
        }
        return (req<=k);
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        
        for(int x : nums){
            i = max(i,x);
            j+=x;
        }
        while(i<j){
            int mid = (i+j)/2;
            bool flag = minLargestSplit(nums, k, mid);
            if(flag) j = mid;
            else i = mid+1;
        }
        return i;
    }
};