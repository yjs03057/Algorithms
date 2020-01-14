#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int solution(string s) {
	int answer = s.length();
	int cut = s.length() / 2;

	for (int i = 1; i <= cut; i++) {
		string sub = s.substr(0, i);
		string res = "";
		int count = 1;

		for (int j = i; j <= s.length(); j += i) {
			if (sub == s.substr(j, i)) count++;
			else {
				if (count == 1) {
					res += sub;
				}
				if (count != 1) {
					res += (to_string(count) + sub);
				}
				sub = s.substr(j, i);
				count = 1;
			}
		}
		if (s.length() / i != 0) res += s.substr((s.length() / i) * i);
		if (answer > res.length())
			answer = res.length();
	}

	return answer;
}

int main() {
	printf("%d", solution("aabbaccc"));
	printf("%d", solution("ababcdcdababcdcd"));
	printf("%d", solution("abcabcdede"));
	printf("%d", solution("abcabcabcabcdededededede"));
	printf("%d", solution("xababcdcdababcdcd"));
}