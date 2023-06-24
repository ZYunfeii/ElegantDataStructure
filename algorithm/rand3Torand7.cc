#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rand3() { return 0;}
    int rand7() {
        int t;
        while (1) {
            int a = (rand3() - 1) * 3;
            int b = rand3();
            t = a + b; // [1,9]均匀随机数，每一个产生的概率都是1/9
            if (t <= 7) {
                break;
            }
        }
        return t;
    }
};

int main(int argc, char** argv) {
    
}