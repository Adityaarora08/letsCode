class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,h=height.size()-1,maxi=INT_MIN;
        while(l<h){
            maxi=max(maxi,min(height[l],height[h])*(h-l));
            if(height[l]>height[h])h--;
            else l++;
        }
        return maxi;
    }
};
