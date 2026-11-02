class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        auto mid = nums.begin() + n/2;
        nth_element(nums.begin(),mid,nums.end());
        int median = *mid;
        int moves = 0;
        for(int i = 0; i<n; i++){
            moves+=abs(nums[i]-median);
        }
        return moves;
    }
};