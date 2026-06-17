class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Gather frequency's
        vector<int> counts(26,0);
        for(char task:tasks)
        {
            counts[task-'A']++;
        }


        // This will track the most frequent task still left
        priority_queue<int>max_heap;
        for(int count : counts)
        {
            if(count>0)
            {
                max_heap.push(count);
            }
        }

        int time = 0;

        queue<pair<int,int>>timeline;

        while(!timeline.empty() || !max_heap.empty())
        {
            time++;

            if(!timeline.empty() && timeline.front().second == time)
            {
                max_heap.push(timeline.front().first);
                timeline.pop();
            }

            if(!max_heap.empty())
            {
                int freq = max_heap.top()-1;
                max_heap.pop();

                if(freq>0)
                {
                    timeline.push({freq, time+n+1});
                }
            }
        }

        return time;


    }
};
