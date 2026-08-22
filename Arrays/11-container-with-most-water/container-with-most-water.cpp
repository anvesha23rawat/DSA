class Solution {
public:
//solution
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int h=0;
        int max_area=0;
        while(i<j){
            int w=j-i;
            if(height[i]<height[j]){
                h=height[i];
                i++;
            }
            else {
                h=height[j];
                j--;
            }
            int area=h*w;
            max_area=max(area,max_area);
        }
        return max_area;
    }
};