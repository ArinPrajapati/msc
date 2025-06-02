#include <iostream>
#include <vector>
#include <list>


using namespace std;


class MyHashMap {
private:
    static const int INITIAL_CAPACITY = 8;
    static constexpr double LOAD_FACTOR_THRESHOLD = 0.75;

    struct Entry {
        string key;
        int value;
        Entry(string k,int v): key(k),value(v){};
    };


    vector<list<Entry>> table;

    int size;
    int capacity; 

    int hash(const string& key) const{
        int hashValue = 0;
        for( char c:key){
            hashValue = (hashValue * 31 + c) %  capacity;
        }
        return hashValue;
    }

    void resize(){
        int oldCapacity  = capacity;
        capacity *= 2;
        vector<list<Entry>> newTable(capacity);

        for(auto& bucket :table){
            for(auto& entry:bucket){
                int newIndex = hash(entry.key);
                newTable[newIndex].emplace_back(entry.key,entry.value);
            }
        }
        table = move(newTable);
    }

public:

    MyHashMap():size(0),capacity(INITIAL_CAPACITY) ,table(INITIAL_CAPACITY){}

    void put(const string& key,int value){
        if((double)(size + 1)/ capacity > LOAD_FACTOR_THRESHOLD){
            resize();
        }

        int index = hash(key);
        for(auto& entry:table[index]){
            if(entry.key == key){
                entry.value = value;
                return;
            }
        }

        table[index].emplace_back(key,value);
        size++;
    }
    
    
    int get(int key) {
        
    }
    
    void remove(int key) {
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
