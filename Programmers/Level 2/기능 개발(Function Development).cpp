#include <string>
#include <vector>
#include <cstdio>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int max;
	int ans = 0;

	for (int i = 0; i < progresses.size(); i++) {
		int day = (100 - progresses[i]) / speeds[i];

		if ((100 - progresses[i]) % speeds[i] != 0) day++;

		if (i == 0) {
			max = day;
			ans++;
		}

		else if (day <= max) ans++;

		else {
			answer.push_back(ans);
			ans = 1;
			max = day;
		}
	}
	answer.push_back(ans);
	return answer;
}

int main() {

	vector<int> answer = solution({ 93, 30, 55 }, { 1, 30, 5 });

	for (int i = 0; i < answer.size(); i++) {
		printf("%d ", answer[i]);
	}
}