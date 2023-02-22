#include <bits/stdc++.h>
using namespace std;
/*
- LRU是最近最少使用页面置换算法(Least Recently Used),也就是首先淘汰最长时间未被使用的页面!
- LFU是最近最不常用页面置换算法(Least Frequently Used),也就是淘汰一定时期内被访问次数最少的页!
- 比如,第二种方法的时期T为10分钟,如果每分钟进行一次调页,主存块为3,若所需页面走向为2 1 2 1 2 3 4
- 注意,当调页面4时会发生缺页中断
- 若按LRU算法,应换页面1(1页面最久未被使用) 但按LFU算法应换页面3(十分钟内,页面3只使用了一次)
*/
class LFUCache {
public:
    typedef struct Node {
        int cnt, time, key, value; // cnt访问次数，time为上一次访问时间
        bool operator < (const Node& rhs) const { // 两个const不能去
            return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt; // 如果访问次数相同，那么按照lru规则淘汰最久没使用的
        }
    } Node;
    int cap, time;
    unordered_map<int, Node> m;
    set<Node> s;
    LFUCache(int capacity) {
        cap = capacity;
        time = 0;
    }
    
    int get(int key) {
        if (m.count(key) == 0) return -1;
        if (cap == 0) return -1;
        Node cache = m[key];
        s.erase(cache);
        cache.cnt++;
        cache.time = ++time;
        s.insert(cache);
        m[key] = cache;
        return cache.value;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;
        if (m.count(key) == 0) {
            if (m.size() == cap) {
                m.erase(s.begin()->key);
                s.erase(s.begin());
            }
            Node cache = Node{1, ++time, key, value};
            m[key] = cache;
            s.insert(cache);
        } else {
            Node cache = m[key];
            s.erase(cache);
            cache.cnt += 1;
            cache.time = ++time;
            cache.value = value;
            s.insert(cache);
            m[key] = cache;
        }
    }
};

int main() {
    LFUCache lfu(3);
    lfu.put(2, 2);
    lfu.put(1, 1);
    lfu.put(2, 3);
    lfu.put(1, 2);
    lfu.put(2, 4);
    lfu.put(3, 3);
    lfu.put(4, 4);

    cout << lfu.get(3) << endl; // 应该为-1， 3被淘汰了

    return 0;
}