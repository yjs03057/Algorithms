#include <cstdio>
using namespace std;

//calculate gcd
int gcd(int w, int h) {
	while (h != 0) {
		int r = w % h;
		w = h;
		h = r;
	}

	return w;
}

long long solution(int w, int h)
{
	long long answer = 1;
	answer = (long long)w * (long long)h - (w + h - gcd(w, h));
	return answer;
}

int main() {
	printf("%d", solution(8, 12));
}