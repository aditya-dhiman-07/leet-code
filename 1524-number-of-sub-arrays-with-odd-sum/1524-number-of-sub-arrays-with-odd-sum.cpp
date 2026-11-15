class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long e=1, o=0, sol=0, sum=0;
        const int MOD =1e9+7;

        for(int x: arr){
            sum+=x;
            if(sum%2==0){
                sol+=o;
                e++;
            }

            else{
                sol+=e;
                o++;
            }
            sol%=MOD;
        }

        return sol%MOD;
        
    }
};