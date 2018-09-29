#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PrintData(int n, double *data, int L, int R) {
	return;
	for (int i = 0; i < n; i++) {
		if (L <= i && i <= R) printf("%2.0f ", data[i]); //L�`R�Ԗڂ͗v�f�̒l��\��
		else printf(" | "); //����ȊO�͏c����\��
	}
	printf("\n");
}

void swap(double* x, double* y) { //�v�f�̓���ւ�
	double z = *x;
	*x = *y;
	*y = z;
}

void QuickSortBase(int n, double *data, int L, int R) {// ���������ɕ��בւ�
	int l = L, r = R;
	double p = data[(L + R) / 2];
	while (1) {
		if (l > r) break; //step2
		while (data[l] < p) l++; //step3
		while (data[r] > p) r--; //step4
		if (l > r) break; //step5
		if (l < r) swap(&data[l], &data[r]); //step6
		l++; r--; //step7
	}
	PrintData(n, data, L, R);
	if (L < r) QuickSortBase(n, data, L, r); //step8
	if (l < R) QuickSortBase(n, data, l, R); //step9

}

void QuickSort(int n, double *data) {
	if (n <= 1) return;
	QuickSortBase(n, data, 0, n - 1);
}

void BubbleSort(int n, double *data) {
	for (int i = n; i >= 2; i--) { //n����2�܂�1�����炷
		for (int j = 0; j <= i - 2; j++) { //0����i-2�܂łP�����₷
			if (data[j] > data[j + 1]) swap(&data[j], &data[j + 1]); //�����𖞂����Ȃ����ւ�
		}
		PrintData(n, data, 0, i - 1);
	}
}

double Measure(void(*sort)(int, double *)) { //sort�֐��̎��Ԃ��v��
	srand(1127);
	int n = 100000;
	double *data;
	data = (double *)malloc(n * sizeof(double));  /*�z��̃������m��*/
	for (int i = 0; i < n; i++) {
		data[i] = rand() % 100; //0�`99�̐�������
	}
	clock_t c0 = clock(); //�v���J�n
	sort(n, data); //�\�[�g�֐��Ăяo��
	clock_t c1 = clock(); //�v���I��
	return (c1 - c0) / (double)CLOCKS_PER_SEC; //�o�ߎ��Ԃ��v�Z
}

int main(void) {
	printf("bubble sort: %.2f�b\n", Measure(BubbleSort));
	printf("quick sort: %.2f�b\n", Measure(QuickSort));

	int a;
	scanf_s("%d", &a);
	return 0;
}