//Quick
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double QuickMaximum(double *, int, int, int);
void swap(double *, double *);


int main(int argc, char *argv[]) {    /*コマンドライン引数を受け取る*/
	int n;
	n = atoi(argv[1]);   /*char型をint型に変換する*/
	double *array, max;
	clock_t start, end;

	array = (double *)malloc(n * sizeof(double));  /*配列のメモリ確保*/

												   /*実数乱数を作るコードを書く*/
	srand((unsigned)time(NULL)); //時刻をもとに乱数を生成

	for (int i = 0; i < n; i++) {
		//	printf("%f ",(double)rand()/100);
		array[i] = (double)rand() / 100; //小数点を含む乱数にする
	}

	start = clock();               /*実行時間計測開始*/
	max = QuickMaximum(array, n, 0, n);        /*最大値を求める関数呼び出し*/
	end = clock();                 /*実行時間計測終了*/

	printf("\n");
	printf("Maximum number is %lf\n", max);
	printf("Elapsed time: %f milisec.\n",
		(double)(end - start) * 1000 / CLOCKS_PER_SEC);
	int a;
	scanf_s("%d", &a);
	return EXIT_SUCCESS;
}

/*最大値を求めるコードを書く*/
double QuickMaximum(double *array, int n, int L, int R) {
	int l = L;
	int r = R;
	double pivot = array[(L + R) / 2];


	while (1) {
		if (l > r) break; //step2
		while (array[l] < pivot) l++; //step3
		while (array[r] > pivot) r--; //step4
		if (l > r) break; //step5
		if (l < r) swap(&array[l], &array[r]); //step6
		l++; r--; //step7
	}

	if (L < r) QuickMaximum(array, n, L, r); //step8
	if (l < R) QuickMaximum(array, n, l, R); //step9

	return array[n];
}

void swap(double* x, double* y) { //要素の入れ替え
	double z = *x;
	*x = *y;
	*y = z;
}
