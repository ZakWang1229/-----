#include <cstdio>
#include <cstdlib>

int main(int, char ** argv) {
	int n = atoi(argv[1]);
	int c = atoi(argv[2]) - 1;
	printf("%d\n", n);
	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", (int) (c * (long long) (2 * n - i) / (2 * n)) + 1, (int) (c * (long long) i / (2 * n)));
	}
	return 0;
}
