class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();
        int sumEven=0;
        for(int &m:nums){
            if(m%2==0){
                sumEven=sumEven+m;
            }
        }
        vector<int>result;
        for(int i=0;i<q;i++){
            int val=queries[i][0];
            int idx=queries[i][1];
            if(nums[idx]%2==0){
                sumEven=sumEven-nums[idx];
            }
            nums[idx]=nums[idx]+val;
            if(nums[idx]%2==0){
                sumEven=sumEven+nums[idx];
            }
            result.push_back(sumEven);
        }
        return result;
    }
};