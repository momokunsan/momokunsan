
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double maximum(double *, int);
double QuickMaximum(double *, int, int, int);

int main(int argc, char *argv[]) {    /*�R�}���h���C���������󂯎��*/
	int n;
	n = atoi(argv[1]);   /*char�^��int�^�ɕϊ�����*/
	double *array, max, max02;
	clock_t start, end;

	array = (double *)malloc(n * sizeof(double));  /*�z��̃������m��*/

												   /*�������������R�[�h������*/
	srand((unsigned)time(NULL)); //���������Ƃɗ����𐶐�

	for (int i = 0; i < n; i++) { //�����_���܂ޗ����ɂ���
								  //	printf("%f ",(double)rand()/100);
		array[i] = (double)rand() / 100; //�z��ɑ��
	}

	Measure(maximum(array, n), array, n);
	int a;
	scanf_s("%d", &a);
	return EXIT_SUCCESS;
}

/*�ő�l�����߂�R�[�h������*/
double maximum(double *array, int n) {
	double y = array[0]; //�ő�l�̏�����

	for (int i = 1; i < n; i++) {
		if (y < array[i]) { //��O�̔z��̒l�Ɣ�ׂđ傫����Α��
			y = array[i];
		}
	}
	return y; //�ő�l��Ԃ�
}


void swap(double* x, double* y) { //�v�f�̓���ւ�
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
	start = clock();               /*���s���Ԍv���J�n*/
	max = sort(array, n);        /*�ő�l�����߂�֐��̌Ăяo��*/
	end = clock();                 /*���Ԍv���I��*/

	printf("\n");
	printf("Maximum number is %lf\n", max);
	printf("Elapsed time: %f milisec.\n",
		(double)(end - start) * 1000 / (double)CLOCKS_PER_SEC);
}