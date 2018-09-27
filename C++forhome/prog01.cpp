
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double maximum(double *, int);

int main(int argc, char *argv[]) {    /*�R�}���h���C���������󂯎��*/
	int n;
	n = atoi(argv[1]);   /*char�^��int�^�ɕϊ�����*/
	double *array, max;
	clock_t start, end;

	array = (double *)malloc(n * sizeof(double));  /*�z��̃������m��*/

	/*�������������R�[�h������*/
	//start = clock();               /*���s���Ԍv���J�n*/
	srand((unsigned) time(NULL)); //���������Ƃɗ����𐶐�

	for (int i = 0; i < n; i++) { //�����_���܂ޗ����ɂ���
	//	printf("%f ",(double)rand()/100);
		array[i] = (double)rand()/100; //�z��ɑ��
	}

	start = clock();               /*���s���Ԍv���J�n*/
	max = maximum(array, n);        /*�ő�l�����߂�֐��Ăяo��*/
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
double maximum(double *array, int n) {
	double y = array[0]; //�ő�l�̏�����

	for (int i = 1; i < n; i++) {
		if (y < array[i]) {
			y = array[i];
		}
	}

	return y;
}
