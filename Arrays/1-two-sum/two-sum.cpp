class Solution {
public:
    //Time complexity = O(n2)
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     for(int i=0;i<nums.size()-1;i++){
    //         for(int j=i+1;j<nums.size();j++){
    //             if(nums[i]+nums[j]==target){
    
    //                 return {i,j};
    //             }
    //         }
    //     }
    //     return {-1,-1};
    // }
    //Time complexity for this is O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int curr = nums[i];
            int rem = target-curr;
            if(mp.find(rem)!=mp.end()){
                return {mp[rem],i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};