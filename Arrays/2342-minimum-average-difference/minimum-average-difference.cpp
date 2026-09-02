class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {

        //brute force = O(n2) ---> gives TLE only 60 test cases pass
        // int n = nums.size();
        // long long min_diff = LLONG_MAX;
        // int idx = 0;
        // long long left_avg,right_avg;
        // if(n == 1){
        //     return 0;
        // }
        // for(int i = 0; i < n; i++) {
        //     long long left_sum = 0;
        //     long long right_sum = 0;
        //     //left sum
        //     for(int j = 0; j <= i ; j++) {
        //         left_sum += nums[j];
        //     }
        //     //right sum
        //     for(int j = i+1; j < n ; j++){
        //         right_sum += nums[j];
        //     }
            
        //     left_avg = left_sum/(i+1);
        //     if(i == n-1) {
        //         right_avg = 0;
        //     }
        //     else{
        //         right_avg = right_sum/(n-i-1);
        //     }
        //     long long diff = abs(left_avg-right_avg);
        //     if(diff < min_diff) {
        //         min_diff = diff;
        //         idx = i;
        //     }
        // }
        // return idx;

        int n = nums.size();
        long long Total_sum = 0;
        //calculate total sum
        for(int i =0;i < n;i++){
            Total_sum += nums[i];
        }
        long long left_sum = 0;
        long long right_sum = 0;
        long long min_diff = LLONG_MAX;
        int idx = 0;
        for(int i = 0;i < n;i++) {
            left_sum += nums[i];
            right_sum = Total_sum - left_sum;
            long long left_avg = left_sum/(i+1);
            long long right_avg = 0;
            if(i != n-1){
                right_avg = right_sum/(n-i-1);
            }
            long long diff = llabs(left_avg-right_avg);
            if(min_diff > diff){
                min_diff = diff;
                idx = i;
            }
        }
        return idx;
    }
};