
class Solution {
public:

    //Memoization  ----> Time Limit Exceeded --> TC = O(n*K*n)
    // int M = 1e9+7;
    // int dp[1001][1001];
    // int solve(int n,int k,int i){
    //     if(k==0){
    //         return 1;
    //     }
    //     if(i>=n){
    //         return 0;
    //     }
    //     if(dp[k][i] != -1){
    //         return dp[k][i];
    //     }
    //     long long take = 0;
    //     long long skip = (solve(n,k,i+1)) % M;
    //     for(int j=i+1;j<=n-1;j++){
    //         take = (take + solve(n,k-1,j)) % M;
    //     }
    //     return dp[k][i] = take+skip;
    // }
    // int numberOfSets(int n, int k) {
    //     memset(dp,-1,sizeof(dp));
    //     return solve(n,k,0) % M;
    // }


    //Bottom up ----> O(k*n*n) -----> TLE

    int M = 1e9+7;
    int dp[1001][1001];
    int numberOfSets(int n,int K){
        //Base case 
        //k==0 --> 1 (i<n)
        for(int i=0; i < n;i++){
            dp[0][i] = 1;
        }
        for(int k = 1; k <= K; k++){
            vector<int> prevRowSum(n+1,0);
            for(int x = n-1; x >= 0; x--){
                prevRowSum[x] = (prevRowSum[x+1] + dp[k-1][x]) % M;
            }
            for(int i = n-1; i >= 0;i--){
                int skip = (dp[k][i+1]) % M;
                int take = prevRowSum[i+1];
                dp[k][i] = (take+skip) % M;
            }
        }
        return dp[K][0];
    }
};