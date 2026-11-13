class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> a;
        map<int,int> m;
        for(int i = nums2.size()-1; i >= 0; i--){
            int x = nums2[i];
            m[x] = -1;
            while(!a.empty()){
                if( a.top() > x ){
                    m[x] = a.top();
                    break;
                } else a.pop();
            }
            a.push(x);
        }
        for(int &i : nums1) i = m[i];
        return nums1;
    }
};
