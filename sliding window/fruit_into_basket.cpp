class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int high =0;
        int low=0;
        int res=0;
        int n=fruits.size();
        unordered_map<int,int>f;
        for(int high=0;high<n;high++){
            f[fruits[high]]++;
            while(f.size()>2){
                f[fruits[low]]--;
                if(f[fruits[low]]==0){
                    f.erase(fruits[low]);
                }
                low++;
            }
            int len= high-low+1;
            res=max(len,res);
        }
        return res;
    }
};