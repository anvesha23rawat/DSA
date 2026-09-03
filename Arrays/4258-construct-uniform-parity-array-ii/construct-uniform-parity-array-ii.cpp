class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minEl = *min_element(nums1.begin(),nums1.end());
        if(minEl % 2 == 1){// odd - we can convert all even to odd
            return true;//all nums2 will be odd
        }
        for(int &num : nums1){ // check if we can make all even in nums2
            if(num % 2 == 1){
                return false;
            }
        }
        return true;//all nums2 will be even
    }
};