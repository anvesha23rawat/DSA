class Solution {
public:
    int countOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int rowOff,int colOff){
        int n= img1.size();
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int b_i = i+rowOff;
                int b_j = j+colOff;
                if( b_i < 0 || b_i >= n || b_j < 0 || b_j >= n ){
                    continue;
                } 
                if(img1[i][j] == 1 && img2[b_i][b_j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        //n*n matrix
        //row = n
        //col = n

        int maxOverlap = 0;
        for(int rowOff = -n+1;rowOff < n; rowOff++){
            for(int colOff = -n+1; colOff < n; colOff++){
                int count = countOverlap(img1,img2,rowOff,colOff);
                maxOverlap = max(maxOverlap,count);
            }
        }
        return maxOverlap;
    }
};