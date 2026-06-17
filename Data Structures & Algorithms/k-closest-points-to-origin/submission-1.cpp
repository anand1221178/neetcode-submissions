class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> q;

        for(int i =0 ;i <points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];

            int dist = (x*x) + (y*y);

            if(q.size() < k)
            {
                q.push({dist,i});
            }
            else if(dist < q.top().first)
            {
                q.pop();
                q.push({dist,i});
            }
        }

        vector<vector<int>>res;
        while(!q.empty())
        {
            int idx = q.top().second;
            res.push_back(points[idx]);
            q.pop();
        }

        return res;
    }
};
