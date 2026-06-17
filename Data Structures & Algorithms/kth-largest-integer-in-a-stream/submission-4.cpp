class KthLargest {
private: 
    priority_queue<int , vector<int>, greater<int>> min_heap;
    int cap;
public:
    KthLargest(int k, vector<int>& nums) {
        cap = k;
        for(int i =0 ; i<nums.size(); i++)
        {
            add(nums[i]);
        }
    }
    
    int add(int val) {
        if(min_heap.size() < cap)
        {
            min_heap.push(val);
        }
        else if(val > min_heap.top())
        {
            min_heap.pop();
            min_heap.push(val);
        }
        return min_heap.top();
    }
};
