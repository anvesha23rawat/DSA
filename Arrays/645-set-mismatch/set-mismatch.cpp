class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dup = 0;
        int missing = 0;
        for(int i=1;i<=n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(nums[j] == i){
                    count++;
                }
            }
            if(count == 0){
                missing = i;
            }
            else if(count == 2){
                dup = i;
            }
        }
        return {dup,missing};
    }
};