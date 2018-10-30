//Fibonacci01
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int n = 100;



float Fibonacci02(int n) {
	if (n == 0 || n == 1) {
		return 1.0;
	}
	else {
		float x = 1.0, y = 1.0;
		float z = 1.0;
		for (int i = 1; i < n; i++) {
			z = x + y;
			x = y;
			y = z;
		}
		return z;
	}
}

int main(void) {
	clock_t start, end;
	printf("Start computing...\n");
	start = clock();

	// フィボナッチ数列を計算する関数の呼び出し
	for (int i = 0; i < n; i++) {
		printf("%.1f ,", Fibonacci02(i));
	}
	end = clock();
	printf("\n");
	printf("End computing.\n");
	printf("Elapsed time: %.2f milisec.\n",
		(end - start) * 1000 / (double)CLOCKS_PER_SEC);

	printf("Exit for press any button");
	int a;
	scanf_s("%d", &a);
	return EXIT_SUCCESS;
}
