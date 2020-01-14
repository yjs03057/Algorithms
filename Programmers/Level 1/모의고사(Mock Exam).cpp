#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int student1[5] = { 1, 2, 3, 4, 5 };
	int student2[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
	int student3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	int score1 = 0;
	int score2 = 0;
	int score3 = 0;

	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == student1[i % 5]) score1++;
		if (answers[i] == student2[i % 8]) score2++;
		if (answers[i] == student3[i % 10]) score3++;
	}

	if (score1 < score2) {
		if (score2 < score3) answer.push_back(3);
		else if (score2 == score3) {
			answer.push_back(2);
			answer.push_back(3);
		}
		else
			answer.push_back(2);
	}
	else if (score1 == score2) {
		if (score1 < score3) answer.push_back(3);
		else if (score1 == score3) {
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(3);
		}
		else {
			answer.push_back(1);
			answer.push_back(2);
		}
	}
	else {
		if (score1 < score3) answer.push_back(3);
		else if (score1 == score3) {
			answer.push_back(1);
			answer.push_back(3);
		}
		else {
			answer.push_back(1);
		}
	}

	sort(answer.begin(), answer.end());
	return answer;
}

int main() {
	vector<int> answer;
	answer = solution({ 1, 2, 3, 4, 5 });
	for (int i = 0; i < answer.size(); i++) {
		printf("%d ", answer[i]);
	}
	printf("\n");
	answer = solution({ 1, 3, 2, 4, 2 });
	for (int i = 0; i < answer.size(); i++) {
		printf("%d ", answer[i]);
	}
}