//BubbleSort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000
#define PRINT 1 // Nが大きな値の時は0にする
#define CHECK 1

int sort[N];

void BubbleSort(int *array, int n) {
	// ソートの処理を追加する
	for (int i = n; i >= 2; i--) { //nから2まで1ずつ減らす
		for (int j = 0; j <= i - 2; j++) { //0からi-2まで１ずつ増やす
			if (array[j] > array[j + 1]) { //前の値と入れ替える
				int z = array[j];
				array[j] = array[j + 1];
				array[j + 1] = z;
			}
		}
	}
}

int main(void) {
	int i, j, t;
	srand((unsigned int)time(NULL));
	// Fisher-Yatesアルゴリズムで1~Nのランダムな数列を構築する
	for (i = 0; i<N; i++) {
		sort[i] = i + 1;
	}
	for (i = N - 1; i>0; i--) {
		j = rand() % (i + 1);
		t = sort[i];
		sort[i] = sort[j];
		sort[j] = t;
	}
	if (PRINT) {
		for (i = 0; i<N; i++) {
			printf("%d ", sort[i]);
		}
		printf("\n");
	}

	clock_t start, end;
	start = clock();
	printf("Sort start...");
	// ソートを行う関数の呼び出し
	BubbleSort(sort, N);
	printf("Sort end.\n");
	end = clock();

	if (PRINT) {
		for (i = 0; i<N; i++) {
			printf("%d ", sort[i]);
		}
		printf("\n");
	}
	printf("Elapsed time: %.2f milisec.\n",
		(end - start) * 1000 / (double)CLOCKS_PER_SEC);

	if (CHECK) {
		for (i = 0; i<N - 1; i++) {
			if (sort[i] > sort[i + 1]) {
				printf("*** Not sorted ***\n"); break;
			}
		}
	}
	int a;
	scanf_s("%d", &a);
	return EXIT_SUCCESS;
}

