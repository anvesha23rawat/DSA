class Solution {
public:
//solution
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int diff = INT_MAX;
        int closest_sum=0;
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(diff > abs(target-sum)){
                    diff=abs(target-sum);
                    closest_sum=sum;
                }
                if(sum < target){
                    j++;
                }
                else if(sum > target){
                    k--;
                }
                else{
                    return target;
                }
            }
        }
        return closest_sum;
    }
};