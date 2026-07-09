class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int ans=0;

        while(i<j){
            int h=min(height[i],height[j]);
            int w=j-i;
            int area=h*w;
            ans=max(ans,area);
            
            if(height[i]>height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;

    }
};