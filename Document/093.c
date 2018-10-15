#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void PrintData(int n, double data[n], int L, int R) {
  return;
  for (int i = 0; i < n; i++) {
    if (L <= i && i <= R) printf("%2.0f ", data[i]); //L～R番目は要素の値を表示
    else printf(" | "); //それ以外は縦線を表示
  }
  printf("\n");
}

void swap(double* x, double* y){ //要素の入れ替え
  double z = *x;
  *x = *y;
  *y = z;
}

void QuickSortBase(int n, double data[n], int L, int R){// 小さい順に並べ替え
  int l = L, r = R;
  double p = data[(L+R)/2];
  while(1){
    if(l > r) break; //step2
    while(data[l] < p) l++; //step3
    while(data[r] > p) r--; //step4
    if(l > r) break; //step5
    if(l < r) swap(&data[l], &data[r]); //step6
    l++; r--; //step7
  }
  PrintData(n, data, L, R);
  if(L < r) QuickSortBase(n, data, L, r); //step8
  if(l < R) QuickSortBase(n, data, l, R); //step9
  
}

void QuickSort(int n, double data[n]){
  if(n <= 1) return;
  QuickSortBase(n, data, 0, n-1);
}

void BubbleSort(int n, double data[n]){
  for(int i = n; i >= 2;i--){ //nから2まで1ずつ減らす
    for(int j = 0; j <= i-2; j++){ //0からi-2まで１ずつ増やす
      if(data[j] > data[j+1]) swap(&data[j], &data[j+1]); //条件を満たすなら入れ替え
    }
    PrintData(n, data, 0, i-1);
  }
}

double Measure(void (*sort)(int, double[])) { //sort関数の時間を計測
  srand(1127);
  int n = 30000;
  double data[n];
  for (int i = 0; i < n; i++) {
    data[i] = rand() % 100; //0～99の整数乱数
  }
  clock_t c0 = clock(); //計測開始
  sort(n, data); //ソート関数呼び出し
  clock_t c1 = clock(); //計測終了
  return (c1 - c0) / (double)CLOCKS_PER_SEC; //経過時間を計算
}

int main(void) {
  printf("bubble sort: %.2f秒\n", Measure(BubbleSort));
  printf("quick sort: %.2f秒\n", Measure(QuickSort));
  return 0;
}
