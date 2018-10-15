//Bubble
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double BubbleMaximum(double *, int);

int main(int argc, char *argv[]) {    /*コマンドライン引数を受け取る*/
	int n;
	n = atoi(argv[1]);   /*char型をint型に変換する*/
	double *array, max;
	clock_t start, end;

	array = (double *)malloc(n * sizeof(double));  /*配列のメモリ確保*/

												   /*実数乱数を作るコードを書く*/
	srand((unsigned)time(NULL)); //時刻をもとに乱数を生成

	for (int i = 0; i < n; i++) { //小数点を含む乱数にする
								  //	printf("%f ",(double)rand()/100);
		array[i] = (double)rand() / 100; //配列に代入
	}

	start = clock();               /*実行時間計測開始*/
	max = BubbleMaximum(array, n);        /*最大値を求める関数呼び出し*/
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
double BubbleMaximum(double *array, int n) {
		for (int i = n; i >= 2; i--) { //nから2まで1ずつ減らす
			for (int j = 0; j <= i - 2; j++) { //0からi-2まで１ずつ増やす
				if (array[j] > array[j + 1]) { //前の値と入れ替える
					double z = array[j];
					array[j] = array[j + 1];
					array[j + 1] = z;
				}
			}
		}
	return array[n-1]; //最大値を返す
}