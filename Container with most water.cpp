class Solution {
public:
    int maxArea(vector<int>& height) {
        // int l= sizeof(height)/sizeof(height[0]);
        // int area=0;
        // for(int i=0;i<l;i++)
        // {
        //     if(height[i]>=height[l])
        //     {
        //         int a=l-i-1;
        //         area=height[l]*a;
        //         break;
        //     }
        // }
        // return area;
int s=0,e=height.size()-1;
int m=0;
while(s<e){
m=max(m,min(height[s],height[e])*(e-s));
if(height[s]<height[e])
    s++;
else 
    e--;
}
return m;
    }
};
