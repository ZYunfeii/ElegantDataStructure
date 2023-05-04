#include <bits/stdc++.h>
using namespace std;
// 本题通过了牛客的所有测试用例
vector<string> chnNumChar = {"零","一","二","三","四","五","六","七","八","九"};
vector<string> chnUnitSection = {"", "万","亿","万亿"};
vector<string> chnUnitChar = {"", "十","百","千"};

void SectionToChinese(unsigned int section, string& chnStr) {
    string strIns;
    int unitPos = 0;
    bool zero = true;
    while(section > 0) {
        int v = section % 10;
        if (v != 0) {
            strIns = chnNumChar[v];
            strIns += chnUnitChar[unitPos];
            zero = false;
        } else {
            if (!zero) {
                strIns = chnNumChar[v];
                zero = true;
            }
        }
        chnStr.insert(0, strIns);
        if ((section / 10 == 0 && strIns.substr(0, 3) == "一") && chnUnitChar[unitPos] == "十") { // 针对103000 不是一十万三千 是 十万三千
            chnStr.erase(chnStr.begin(), chnStr.begin() + 3);
        }
        unitPos++;
        section /= 10;
        
    }
}

string numToChiness(int num) {
    if (num == 0) return "零";
    bool flag = false;
    if (num < 0) {
        num = -num;
        flag = true;
    }

    string chnStr;
    int unitPos = 0;
    
    bool needZero = false;
    while (num > 0) {
        uint32_t section = num % 10000;
        string strIns;
        SectionToChinese(section, strIns);
        strIns += (section != 0) ? chnUnitSection[unitPos] : chnUnitSection[0];
        chnStr.insert(0, strIns);
        num = num / 10000;
        unitPos++;
        if (num > 0 && section < 1000 && section > 0) { // 针对60500这种，五百前面需要加0
            chnStr.insert(0, "零");
        }  
    }
    if (flag) {
        chnStr.insert(0, "负");
    }
    return chnStr;
}

int main() {
    cout << numToChiness(-188921075);
    return 0;
}