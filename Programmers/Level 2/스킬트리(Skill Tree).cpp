#include <string>
#include <vector>
#include <cstdio>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	for (int i = 0; i < skill_trees.size(); i++) {
		string tree = skill_trees[i];
		int skill_pos = 0;
		bool possibility = true;
		for (int j = 0; j < tree.length(); j++) {
			int index = skill.find(tree[j]);
			if (index == -1) continue;
			else if (index == skill_pos) skill_pos++;
			else {
				possibility = false;
				break;
			}
		}
		if (possibility == true) answer++;
	}
	return answer;
}

int main() {
	printf("%d", solution("CBD", { "BACDE", "CBADF", "AECB", "BDA" }));
}