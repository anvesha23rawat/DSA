class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        //Brute Force -> O(n*m) + O(nlogn)
        /*
        int n = nums.size();
        int m = queries.size();
        vector<int> result;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < m; i++){
            int sum = 0;
            int len = 0;
            for(int j = 0; j < n; j++){
                sum = sum + nums[j];
                if(sum > queries[i]){
                    break;
                }
                len++;
            }
            result.push_back(len);
        }
        return result;
        */

        //Optimized method -> sort-> cumulative sum -> binary sum

        int n = nums.size();
        int m = queries.size();
        vector<int> result;
        //sort
        sort(nums.begin(),nums.end());
        //cumulative sum
        for(int i = 1; i < n; i++){
            nums[i] = nums[i-1]+nums[i];
        }
        // binary search
        for(int i=0;i<m;i++){
            int l = 0;
            int r = n-1;
            int ans= -1;
            while(l<=r){
                int mid = (l+r)/2;
                if(nums[mid] <= queries[i]){
                    ans = mid;
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
            result.push_back(ans+1);
        }
        return result;
    }
};