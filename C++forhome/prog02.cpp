//Quick
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double QuickMaximum(double *, int, int, int);
void swap(double *, double *);


int main(int argc, char *argv[]) {    /*�R�}���h���C���������󂯎��*/
	int n;
	n = atoi(argv[1]);   /*char�^��int�^�ɕϊ�����*/
	double *array, max;
	clock_t start, end;

	array = (double *)malloc(n * sizeof(double));  /*�z��̃������m��*/

												   /*�������������R�[�h������*/
	srand((unsigned)time(NULL)); //���������Ƃɗ����𐶐�

	for (int i = 0; i < n; i++) {
		//	printf("%f ",(double)rand()/100);
		array[i] = (double)rand() / 100; //�����_���܂ޗ����ɂ���
	}

	start = clock();               /*���s���Ԍv���J�n*/
	max = QuickMaximum(array, n, 0, n);        /*�ő�l�����߂�֐��Ăяo��*/
	end = clock();                 /*���s���Ԍv���I��*/

	printf("\n");
	printf("Maximum number is %lf\n", max);
	printf("Elapsed time: %f milisec.\n",
		(double)(end - start) * 1000 / CLOCKS_PER_SEC);
	int a;
	scanf_s("%d", &a);
	return EXIT_SUCCESS;
}

/*�ő�l�����߂�R�[�h������*/
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

void swap(double* x, double* y) { //�v�f�̓���ւ�
	double z = *x;
	*x = *y;
	*y = z;
}
