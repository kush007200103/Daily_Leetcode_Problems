class Solution {
    public:
        int power=0;
        int solve(int n){
            power=0;
            int nums=1;
            while(nums<=n){
                if(3*nums>n){
                    break;
                }
                power++;
                nums=3*nums;
               
            }
            return nums;
        }
        bool checkPowersOfThree(int n) {
            vector<int>v(16,0);
            while(n>=3){
                int k=solve(n);
                if(v[power]==0){
                    v[power]++;
                     n-=k;
                }else{
                    cout<<power<<endl;
                    return false;
                }
            }
            if(n==2){
                return false;
            }
            return true;
        }
    };