map<int, int> myMap;
vector<int> vec;
int maxi = 0;
int current = 0;

LRUCache::LRUCache(int capacity) {
    myMap.erase(myMap.begin(), myMap.end());
    vec.erase(vec.begin(), vec.end());
    maxi = capacity;
    current = 0;
}

int LRUCache::get(int key) {
    if(current > 0){
        auto it = myMap.find(key);
        if(it != myMap.end()){
            int temp = it->second;
            int value = it->first;
            
            vector<int>::iterator it;
            it = find (vec.begin(), vec.end(), value); 
            if (it != vec.end()) 
            { 
                vec.erase(it);
            }
            vec.push_back(value);
            return temp;
        }
    }
    return -1;
}

void LRUCache::set(int key, int value) {
    if(myMap.find(key) == myMap.end()){
        myMap.insert({key, value});
        if(current != maxi){
            current++;
            vec.push_back(key);
        }
        else{
            int t = vec[0];
            // int t = lru->val;
            auto it = myMap.find(t);
            myMap.erase(it);
            vec.erase(vec.begin());
            vec.push_back(key);
        }
    }
    else{
        myMap[key] = value;
        
        vector<int>::iterator it;
        it = find (vec.begin(), vec.end(), key); 
        if (it != vec.end()) 
        { 
            vec.erase(it);
        }
        vec.push_back(key);
    }
}
