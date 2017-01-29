#define DEBUG 1

class RandomizedSet {
    
    unordered_map<int, int> randomized_map;
    vector<int> randomized_list;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (randomized_map.find(val) == randomized_map.end()) {
            randomized_list.push_back(val);
            randomized_map[val] = randomized_list.size() - 1;
            return true;
        } else {
            return false;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (randomized_map.find(val) != randomized_map.end()) {
            int back = randomized_list.back();
            int removal_index = randomized_map[val];
            
            //SWAP the last element with the element to be deleted using the index stored in randomized_map
            randomized_list[removal_index] = back;
            randomized_map[back] = removal_index;
            
            randomized_list.pop_back();
            randomized_map.erase(val);
            return true;
        } else {
            return false;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return randomized_list[rand() % randomized_list.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */