#ifndef KVCACHE_WITH_SAMPLE_H
#define KVCACHE_WITH_SAMPLE_H
#include <unordered_map>
using namespace std;
// KVcache,支持get set del sample，sample返回随机一个val，要求时间复杂度较低，其中key不重复(快手三面题)
template <class T>
class KvCacheWithSample {
private:
    struct Entry {
        int key;
        T val;
        bool used;
    };
    unordered_map<int, Entry> dataMap;
    unordered_map<int, int> reverseMap;
    int count;
    int delTimer;

    void clean() {
        unordered_map<int, Entry> newDataMap;
        count = delTimer = 0;
        reverseMap.clear();
        for (auto& [k, v] : dataMap) {
            if (v.used == false) continue;
            newDataMap[count++] = v;
            reverseMap[v.key] = count - 1;
        }
        dataMap = std::move(newDataMap);
    }
public:
    KvCacheWithSample() : count(0), delTimer(0) {
    }

    void set(int key, T val) {
        if (reverseMap.count(key) != 0) {
            int idx = reverseMap[key];
            dataMap[idx].val = val;
            return;
        }
        Entry e{key, val, true};
        dataMap[count++] = e; 
        reverseMap[key] = count - 1;
    }

    T get(int key) {
        if (reverseMap.count(key) == 0) {
            return T();
        }
        int idx = reverseMap[key];
        if (dataMap[idx].used == false) {
            return T();
        }
        return dataMap[idx].val;
    }

    void del(int key) {
        if (reverseMap.count(key) == 0) {
            return;
        }
        int idx = reverseMap[key];
        reverseMap.erase(key);
        dataMap[idx].used = false;
        delTimer++;
        if (delTimer % 10 == 0) {
            clean();
        }
    }

    T sample() {
        int randIdx = rand() % count;
        if (dataMap[randIdx].used == true) {
            return dataMap[randIdx].val;
        }
        int ptr = randIdx + 1;
        while (ptr != randIdx) {
            ptr = ptr % count;
            if (dataMap[ptr].used == false) {
                ptr++;
                continue;
            } else {
                return dataMap[ptr].val;
            }
        }
        return T();
    }

};

#endif