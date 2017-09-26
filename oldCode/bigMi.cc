#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string fun(string src, string num) {
	string tmp = src;
	for (int i =num.length() -1; i >= 0 ; --i) {

		string mid(tmp.length(),'0');
		int cnt =0;
		for (int j =  tmp.length()-1; j >= 0; --j) {

			int tm = cnt + (tmp[j] -'0')* (num[i] - '0');
			mid[j] = tm% 10 +'0';
			cnt = tm  /10;
		}

		for (int q = num.length()-1; q> i; --q)
			mid.push_back('0');
		if (cnt != 0)
			mid.insert(0, string(1, (char)cnt +'0'));

		// ¼Ó·¨ÔËËã
		if (i == num.length()-1)
			src = mid;
		else {

			cnt =0;
			string s(mid.length() - src.length(), '0');
			src = s + src;
			for (int j = mid.length()-1; j>=0; --j) {

				int tm = (mid[j] - '0') +(src[j] - '0') + cnt;
				src[j] = tm %10 + '0';
				cnt = tm /10;
			}

			if (cnt !=0)
				src.insert(0, string(1, (char)cnt +'0'));
		}
	}
	return src;
}

int main() {

	string str;
	while (getline(cin, str)) {
		int i =0;
		int ind = 0;
		int count = 0;
		string num;
		while ( i< str.length()) {
			if ( str[i] != ' ') {
				if (str[i] == '.')
					ind = i;
				else
					num.push_back(str[i]);
				++i;
				continue;
			}
			while ( !isdigit(str[i]))
				++i;
			if (i + 1 == str.length())
				count = str[i] - '0';
			else
				count = (str[i] - '0') * 10 + str[i+1] - '0';
			break;
		}

		ind = num.length() - ind;

		string ans = num;
		for (int i =0; i< count-1; ++i) {

			ans = fun( ans, num);
		}
		ind = ind * count;

		ans.insert(ans.length() - ind, string("."));

		while (ans.length() >1 && ans[0] == '0')
			ans.erase(0, 1);

		for (int i =ans.length()-1; i>=0; --i) {

			if (ans[i] == '0' )
				ans.erase(i, i+1);
			else
				break;
		}
		if(ans[0] == '.')cout << '0';
		cout << ans << endl;
	}
	return 0;
}
