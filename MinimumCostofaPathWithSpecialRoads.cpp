class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        int sx=start[0],sy=start[1],tx=target[0],ty=target[1],n=specialRoads.size();
        vector<int> roads(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(int i=0;i<n;i++){
            int x1=specialRoads[i][0];
            int y1=specialRoads[i][1];
            int x2=specialRoads[i][2];
            int y2=specialRoads[i][3];
            int cost=specialRoads[i][4];
            int distance=abs(x1-sx)+abs(y1-sy);
            roads[i]=distance+cost;
            q.push({roads[i],i});
        }
        int ans=abs(sx-tx)+abs(ty-sy);
        while(!q.empty()){
            int road=q.top().second;
            int cost=q.top().first;
            q.pop();
            ans=min(ans,abs(specialRoads[road][2]-tx)+abs(specialRoads[road][3]-ty)+cost);
            if(cost!=roads[road]) continue;
            for(int i=0;i<n;i++){
                if(i==road) continue;
                int x1=specialRoads[i][0];
                int y1=specialRoads[i][1];
                int x2=specialRoads[i][2];
                int y2=specialRoads[i][3];
                int costa=specialRoads[i][4];
                int cx1=specialRoads[road][0];
                int cy1=specialRoads[road][1];
                int cx2=specialRoads[road][2];
                int cy2=specialRoads[road][3];
        
                int total=abs(cx2-x1)+abs(cy2-y1)+costa+cost;
                if(total<roads[i]){
                    roads[i]=total;
                    q.push({roads[i],i});
                }
            }
        }
        return ans;
    }
};
