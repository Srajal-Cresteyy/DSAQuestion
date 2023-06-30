class Solution {
    public:
    class compare{
        public:
        bool operator()(vector<int> &a,vector<int> &b){
            return b[0]+b[1]<a[0]+a[1];
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int> ,vector<vector<int>>,compare> q;

        vector<vector<int>> ans;

        for(int i=0;i<nums2.size() and i<k;i++)
            q.push({nums1[0],nums2[i],0});

        while(k-- and !q.empty()){
            vector<int> temp=q.top();
            q.pop();
            ans.push_back({temp[0],temp[1]});
            int index=temp[2];

            if(index==nums1.size()-1) continue;

            q.push({nums1[index+1],temp[1],index+1});
        }

        return ans;
    }
};
/*
Sample TestCase : 
  input : 
        nums1=[1,7,11]
        nums2=[2,4,6]  k=3

  sorted ------------>
  |  (1,2)0  (1,4)0  (1,6)0
  |  (7,2)1  (7,4)1  (7,6)1
  | (11,2)2 (11,4)2 (11,6)2
  ↓

  priority_queue : (inititally contains after preproccing)
  (1,2)0  
  (1,4)0  
  (1,6)0

  similar to merge k sorted lists 
*/
