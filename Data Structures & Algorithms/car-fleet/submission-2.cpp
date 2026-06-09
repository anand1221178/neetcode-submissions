class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        int fleets= 0;
        double blocking_time = 0.0;

        vector<int>idx(n);
        iota(idx.begin(), idx.end(), 0); //Fill from 0 to n in idx
        // Sort by closest to the target so descending order:
        std::sort(idx.begin(), idx.end(), [&position](int a, int b){
            return position[a] > position[b];
        });

        for(int id:idx)
        {
            // calculate fleets;
            // Timing:
            double curr_speed = (double)(target-position[id])/speed[id];
            if (curr_speed > blocking_time){
                fleets++;
                blocking_time = curr_speed;
            }
        }

        return fleets;

    }
};
