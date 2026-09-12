class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        // Brute force ----->   TC = O(n3) + O(slogs) 
        // int n = digits.size();
        // unordered_set<int> st;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         for(int k=0;k<n;k++){
        //             if(i==j||i==k||j==k){
        //                 continue;
        //             }
        //             int num = digits[i]*100 + digits[j]*10 + digits[k]*1;
        //             if(num>=100 && num%2==0){
        //                 st.insert(num);
        //             }
        //         }
        //     }
        // }
        // vector<int>result(begin(st),end(st));
        // sort(result.begin(),result.end());
        // return result;


        //Optimal approach ------> TC = O(1)  and SC = O(1)
        map<int,int> mp;
        for(auto n:digits){
            mp[n]++;
        }
        vector<int>result;
        for(int i=1;i<=9;i++){
            if(mp[i] == 0){
                continue;
            }
            mp[i]--;
            for(int j=0;j<=9;j++){
                if(mp[j] == 0){
                    continue;
                }
                mp[j]--;
                for(int k=0;k<=8;k+=2){
                    if(mp[k] == 0){
                        continue;
                    }
                    mp[k]--;
                    int num = (i*100) + (j*10) + k;
                    result.push_back(num);
                    mp[k]++;
                }
                mp[j]++;
            }
            mp[i]++;
        }
        return result;
    }
};