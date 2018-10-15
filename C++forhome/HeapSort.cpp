//HeapSort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define PRINT 1 // Nが大きな値の時は0にする
#define CHECK 1

int sort[N];

void swap(int* x, int* y) { //要素の入れ替え
	int z = *x;
	*x = *y;
	*y = z;
}
// Heap構造を作る関数
void HeapSortBase(int *array, int n, int i) {
	int maximum = i; //最大値の初期化
	int l = 2 * i + 1; //左の子ノード
	int r = 2 * i + 2; //右の子ノード
	//左の子ノードが根ノードより大きい時
	if (l < n && array[l] > array[maximum]) {
		maximum = l;
	}
	//右の子ノードが親ノードより大きい時
	if (r < n && array[r] > array[maximum]) {
		maximum = r;
	}
	//最大値が根ノードでない時
	if (maximum != i) {
		swap(&array[i], &array[maximum]);
		HeapSortBase(array, n, maximum);
	}
}
//　ソートをこっちの関数で行う
void HeapSort(int *array, int n) {
	// Heap構造の生成
	for (int i = (n / 2) - 1; i >= 0; i--) {
		HeapSortBase(array, n, i);
	}
	// ソートの処理
	for (int i = n - 1; i >= 0; i--) {
		swap(&array[0], &array[i]);

		HeapSortBase(array, i, 0);
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
	HeapSort(sort, N);
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

//参考文献
//URL：https://www.geeksforgeeks.org/heap-sort/
//閲覧日：2018/10/15