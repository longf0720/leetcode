class Solution {
public:
    int calc(std::vector<int> &v, vector<int>::iterator target) {
        int res = 0;
        int left = 0, right = 0;
        //cout<<"target="<<*target<<endl;
        for(std::vector<int>::iterator iter = v.begin(); iter != target; iter++) {
            //cout<<"iter="<<*iter<<endl;
            if(*iter > left) left = *iter;
        }
        for(vector<int>::iterator iter = target + 1; iter < v.end(); iter++) {
            if(*iter > right) right = *iter;
        }
        //cout<<"left="<<left<<",right="<<right<<endl;
        res = min(left, right) - *target;
        return (res>=0)?res:0;
    }

    int trap(vector<int>& height) {
        int ans = 0;
        for(std::vector<int>::iterator v = height.begin(); v != height.end(); v++) {
            //cout<<"v="<<*v<<endl;
            int ret = calc(height, v);
            
            //cout<<"ret="<<ret<<endl;
            ans += ret;
        }
        return ans;
    }
};