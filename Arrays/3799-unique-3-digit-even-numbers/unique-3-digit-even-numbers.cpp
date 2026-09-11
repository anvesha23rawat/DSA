class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};
        for(auto num : digits){
            freq[num]++;
        }
        // i = hundreds digit
        // j = tens digit
        // k = units digit
        int result = 0;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                for(int k=0;k<10;k++){
                    //first digit not equal to 0
                    if( i != 0 ){
                        //last digit must be even
                        if( k % 2 == 0){
                            //check frequency table
                            if(freq[i] > 0){
                                freq[i]--;
                                if(freq[j] > 0){
                                    freq[j]--;
                                    if(freq[k] > 0){
                                        freq[k]--;
                                        result++;
                                        freq[k]++;
                                    }
                                    freq[j]++;
                                }
                                freq[i]++;
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
};