//
//  LRUCache.h
//  LeetCode
//
//  Created by ipuser on 2015/03/03.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
 
 get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 */
#ifndef LeetCode_LRUCache_h
#define LeetCode_LRUCache_h
struct LRUCacheCell {
    int times;
    int value;
    LRUCacheCell(int a = 0, int b = 0){
        times = a;
        value = b;
    }
};
class LRUCache{
private:
    int length;
    int curlen;
    map<int, LRUCacheCell> cache;
public:
    LRUCache(int capacity) {
        length = capacity;
        curlen = 0;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            cache[key].times = 1;
            return cache[key].value;
        } else
            return -1;
    }
    
    void set(int key, int value) {
        map<int, LRUCacheCell>::iterator map_it, pos;
        int maxValue = 0;
        for (map_it = cache.begin(); map_it != cache.end(); map_it ++) {
            map_it->second.times ++;
            if(map_it->second.times > maxValue) {
                maxValue = map_it->second.times;
                pos = map_it;
            }
        }
        if (cache.find(key) == cache.end()) {
            LRUCacheCell a(1, value);
            if (curlen >= length) {
                cache.erase(pos);
                curlen --;
            }
            cache[key] = a;
            curlen ++;
        } else {
            cache[key].times = 1;
            cache[key].value = value;
        }
        return;
    }
};
class LRUCacheTest{
public:
    void test() {
        
    }
};
#endif
