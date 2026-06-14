class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi=0;

        for (int i =0; i<piles.size(); i++)
        {
            if(piles[i] > hi)
            {
                hi = piles[i];
            }
        }

        while(lo<hi)
        {
            int mpt = lo +(hi-lo)/2;
            int time_taken = 0;
            for(int i =0; i< piles.size(); i++)
            {
                time_taken += ceil((double)piles[i]/mpt);
            }

            if(time_taken > h)
            {
                lo = mpt+1;
            }
            else if(time_taken <= h)
            {
                hi = mpt;
            }
        }

        return lo;
    }
};
