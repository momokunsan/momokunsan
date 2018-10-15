//Bubble
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double BubbleMaximum(double *, int);

int main(int argc, char *argv[]) {    /*�R�}���h���C���������󂯎��*/
	int n;
	n = atoi(argv[1]);   /*char�^��int�^�ɕϊ�����*/
	double *array, max;
	clock_t start, end;

	array = (double *)malloc(n * sizeof(double));  /*�z��̃������m��*/

												   /*�������������R�[�h������*/
	srand((unsigned)time(NULL)); //���������Ƃɗ����𐶐�

	for (int i = 0; i < n; i++) { //�����_���܂ޗ����ɂ���
								  //	printf("%f ",(double)rand()/100);
		array[i] = (double)rand() / 100; //�z��ɑ��
	}

	start = clock();               /*���s���Ԍv���J�n*/
	max = BubbleMaximum(array, n);        /*�ő�l�����߂�֐��Ăяo��*/
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
double BubbleMaximum(double *array, int n) {
		for (int i = n; i >= 2; i--) { //n����2�܂�1�����炷
			for (int j = 0; j <= i - 2; j++) { //0����i-2�܂łP�����₷
				if (array[j] > array[j + 1]) { //�O�̒l�Ɠ���ւ���
					double z = array[j];
					array[j] = array[j + 1];
					array[j + 1] = z;
				}
			}
		}
	return array[n-1]; //�ő�l��Ԃ�
}