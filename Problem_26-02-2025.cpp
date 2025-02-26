class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int ans=0,sum=0,minv=INT_MAX,maxv=INT_MIN;
            for(int i=0;i<nums.size();i++){
                sum+=nums[i];
                if(minv!=INT_MAX){
                    int val1 = abs(sum-minv);
                    int val2=abs(sum-maxv);
                    ans=max(ans,max(val2,val1));
                    ans=max(ans,abs(sum));
                }
                ans=max(ans,abs(sum));
                minv=min(minv,sum);
                maxv=max(maxv,sum);
            }
            return ans;
        }
    };