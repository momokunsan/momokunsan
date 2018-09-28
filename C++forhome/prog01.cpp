
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double maximum(double *, int);
double QuickMaximum(double *, int, int, int);

int main(int argc, char *argv[]) {    /*コマンドライン引数を受け取る*/
	int n;
	n = atoi(argv[1]);   /*char型をint型に変換する*/
	double *array, max, max02;
	clock_t start, end;

	array = (double *)malloc(n * sizeof(double));  /*配列のメモリ確保*/

												   /*実数乱数を作るコードを書く*/
	srand((unsigned)time(NULL)); //時刻をもとに乱数を生成

	for (int i = 0; i < n; i++) { //小数点を含む乱数にする
								  //	printf("%f ",(double)rand()/100);
		array[i] = (double)rand() / 100; //配列に代入
	}

	Measure(maximum(array, n), array, n);
	int a;
	scanf_s("%d", &a);
	return EXIT_SUCCESS;
}

/*最大値を求めるコードを書く*/
double maximum(double *array, int n) {
	double y = array[0]; //最大値の初期化

	for (int i = 1; i < n; i++) {
		if (y < array[i]) { //一個前の配列の値と比べて大きければ代入
			y = array[i];
		}
	}
	return y; //最大値を返す
}


void swap(double* x, double* y) { //要素の入れ替え
	double z = *x;
	*x = *y;
	*y = z;
}

double QuickMaximum(double *array, int n, int L, int R) {
	int l = L;
	int r = R;
	double pivot = array[(L + R) / 2];

	double QuickMax = array[n];

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

	return QuickMax;
}

void Measure(void(*sort)(double *, int), double *array, int n) {
	clock_t start, end;
	double max;
	start = clock();               /*実行時間計測開始*/
	max = sort(array, n);        /*最大値を求める関数の呼び出し*/
	end = clock();                 /*時間計測終了*/

	printf("\n");
	printf("Maximum number is %lf\n", max);
	printf("Elapsed time: %f milisec.\n",
		(double)(end - start) * 1000 / (double)CLOCKS_PER_SEC);
}