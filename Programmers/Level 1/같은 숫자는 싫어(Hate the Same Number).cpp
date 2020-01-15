#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer;
	int before = -1;
	for (int i = 0; i < arr.size(); i++) {
		if (before == arr[i]) continue;
		else {
			before = arr[i];
			answer.push_back(arr[i]);
		}
	}
	return answer;
}

int main() {
	vector<int> answer;
	answer = solution({ 1, 1, 3, 3, 0, 1, 1 });
	for (int i = 0; i < answer.size(); i++) {
		printf("%d ", answer[i]);
	}
	printf("\n");
	answer = solution({ 4,4,4, 3, 3 });
	for (int i = 0; i < answer.size(); i++) {
		printf("%d ", answer[i]);
	}
	printf("\n");
}