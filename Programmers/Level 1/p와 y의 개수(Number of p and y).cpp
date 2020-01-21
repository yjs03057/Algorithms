#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool solution(string s)
{
	bool answer = true;
	int pNum = 0; int yNum = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'p' || s[i] == 'P') pNum++;
		else if (s[i] == 'y' || s[i] == 'Y') yNum++;
	}

	if (pNum == yNum) answer = true;
	else answer = false;

	return answer;
}

int main() {
	string s = "pPoooyY";
	printf(solution(s) ? "true" : "false");
	printf("\n");
	s = "Pyy";
	printf(solution(s) ? "true" : "false");
}