#include<bits/stdc++.h>
using namespace std;

class Solution1 { // Better Approach TC : O(N*M) SC : O(N*M)
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> mat;
        
        for(auto row:matrix)
            for(int val:row)
                mat.push_back(val);

        return binary_search(mat.begin(),mat.end(),target);
    }
};

// Approach
// Just search for the right row where the element could be expected to lie and then simply apply the approach on that particular row !

// Complexity
// Time complexity : O(LogN + LogM)
// Space complexity : O(1)
// Code

class Solution2 {// Optimal Approach TC : O(LogN + LogM) , SC : O(1)
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Searching for the right row 
        
        int l=0,h=matrix.size()-1;
        int row = -1;

        while(l<=h){

            int mid = (h-l)/2 + l;

            if(target<=matrix[mid].back() && target>=matrix[mid][0]){
                row = mid;
                return binary_search(matrix[row].begin(),matrix[row].end(),target);
            }
            else if(target<matrix[mid][0]){
                h=mid-1;
            }
            else l=mid+1;
        }

        return false;
    }
};

int main(){
  Solution2 solve = new Solution2();

  int target;
  cin>>target; // Target to search for
  
  int n,m;
  cin>>n>>m; // No of rows and columns in the input matrix

  vector<vector<int>> arr(n,vector<int>(m));
  for(vector<int> &row:arr){
    for(int &val:row) cin>>val;
  }

  cout<<solve.searchMatrix(arr,target)<<endl;
}
  
}
