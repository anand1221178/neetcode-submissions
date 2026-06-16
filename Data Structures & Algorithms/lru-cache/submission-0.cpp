class LRUCache {
private:
    int cap;

    //DLL with {key,value}
    list<pair<int,int>>timeline;

    unordered_map<int, list<pair<int,int>>::iterator>cache;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end())
        {
            return -1;
        }

        int val = cache[key]->second;

        timeline.erase(cache[key]);

        timeline.push_front({key,val});

        cache[key] = timeline.begin();

        return val;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end())
        {
            timeline.erase(cache[key]);
        }
        else if (cache.size() == cap)
        {
            int lru = timeline.back().first;
            cache.erase(lru);
            timeline.pop_back();
        }

        timeline.push_front({key,value});

        cache[key] = timeline.begin();
    }
};
