/* TC= O(n2)
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
*/


// TC = O(nlogn)
/*
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        //frequency count
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int dup = 0;
        int miss = 0;
        // 1 to n check krenge
        for(int i = 1; i <= n ; i++){
            if(mp[i] == 2){
                dup=i;
            }
            if(mp[i] == 0){
                miss = i;
            }
        }
        return {dup,miss};
    }
};

*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dup = -1;
        int missing = -1;

        for(int i=0;i<n;i++){
            if(nums[abs(nums[i]) - 1] < 0){
                dup = abs(nums[i]);
            }
            else{
                nums[abs(nums[i]) - 1] *= (-1); 
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i] > 0){
                missing = i+1;
            }
        }
        return {dup,missing};
    }
};