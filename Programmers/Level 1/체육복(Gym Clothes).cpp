#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	int* students = new int[n + 1];
	vector<int>::iterator it;
	fill(students, students + n + 1, 1);

	for (int i = 0; i < reserve.size(); i++) {
		students[reserve[i]] = 2;
	}

	for (int i = 0; i < lost.size(); i++) {
		students[lost[i]]--;
		if (students[lost[i]] == 0) {
			if (students[lost[i] - 1] == 2 && find(lost.begin(), lost.end(), lost[i] - 1) == lost.end()) {
				students[lost[i] - 1]--;
				students[lost[i]] = 1;
			}
			else if (students[lost[i] + 1] == 2 && find(lost.begin(), lost.end(), lost[i] + 1) == lost.end()) {
				students[lost[i] + 1]--;
				students[lost[i]] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (students[i] > 0) answer++;
	}

	return answer;
}

int main() {
	printf("%d\n", solution(5, { 2, 4 }, { 1, 3, 5 }));
	printf("%d\n", solution(5, { 2, 4 }, { 3 }));
	printf("%d\n", solution(3, { 3 }, { 1 }));
	printf("%d\n", solution(5, { 1,2 }, { 2,3 }));
}