#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int cvtNum(string src)
{
	unordered_map<string, int> multi;
	multi["亿"] = 1e8;
	multi["万"] = 1e4;
	multi["千"] = 1e3;
	multi["百"] = 1e2;
	multi["十"] = 1e1;

	unordered_map<string, int> base;
	base["零"] = 0;
	base["一"] = 1;
	base["二"] = 2;
	base["三"] = 3;
	base["四"] = 4;
	base["五"] = 5;
	base["六"] = 6;
	base["七"] = 7;
	base["八"] = 8;
	base["九"] = 9;

	cout << "current src: " << src << endl;

	int len = src.length();
	int dst = 0, yi_dst = 0, wan_dst = 0;
	int currval = 0;
	for (int i = 0; i < len; i += 3)
	{
		string curr = src.substr(i, 3); // 这里是选一个汉字出来 3个字节
		if (multi.count(curr))
		{
			if (curr == "亿")
			{
				yi_dst = (dst + currval) * multi[curr];
				dst = 0;
			}
			else if (curr == "万")
			{
				wan_dst = (dst + currval) * multi[curr];
				dst = 0;
			}
			else
			{
				dst += currval * multi[curr];
			}
			currval = 0;
		}
		else
		{
			currval = base[curr];
		}
	}

	dst += yi_dst + wan_dst + currval;
	return dst;
}

int main()
{
	// string a = "五十六万七千九百零一";
	// string src = "五千四百二十八万九千三百二十一";
	// string src = "五千四百二十八万零二十一";
	// string src = "五亿零一十万零八十";
	// string src = "九千万零一十二";
	// string src = "九千万";
	// string src = "九千零五";
	string src = "五亿零一十万零八十";

	int res = cvtNum(src);
	cout << "curr result: " << res << endl;

	string s1 = "三";
	cout << s1.substr(0, 3) << endl;
	return 0;
}
