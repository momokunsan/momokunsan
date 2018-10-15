//HeapSort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define PRINT 1 // N���傫�Ȓl�̎���0�ɂ���
#define CHECK 1

int sort[N];

void swap(int* x, int* y) { //�v�f�̓���ւ�
	int z = *x;
	*x = *y;
	*y = z;
}
// Heap�\�������֐�
void HeapSortBase(int *array, int n, int i) {
	int maximum = i; //�ő�l�̏�����
	int l = 2 * i + 1; //���̎q�m�[�h
	int r = 2 * i + 2; //�E�̎q�m�[�h
	//���̎q�m�[�h�����m�[�h���傫����
	if (l < n && array[l] > array[maximum]) {
		maximum = l;
	}
	//�E�̎q�m�[�h���e�m�[�h���傫����
	if (r < n && array[r] > array[maximum]) {
		maximum = r;
	}
	//�ő�l�����m�[�h�łȂ���
	if (maximum != i) {
		swap(&array[i], &array[maximum]);
		HeapSortBase(array, n, maximum);
	}
}
//�@�\�[�g���������̊֐��ōs��
void HeapSort(int *array, int n) {
	// Heap�\���̐���
	for (int i = (n / 2) - 1; i >= 0; i--) {
		HeapSortBase(array, n, i);
	}
	// �\�[�g�̏���
	for (int i = n - 1; i >= 0; i--) {
		swap(&array[0], &array[i]);

		HeapSortBase(array, i, 0);
	}
}

int main(void) {
	int i, j, t;
	srand((unsigned int)time(NULL));
	// Fisher-Yates�A���S���Y����1~N�̃����_���Ȑ�����\�z����
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
	// �\�[�g���s���֐��̌Ăяo��
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

//�Q�l����
//URL�Fhttps://www.geeksforgeeks.org/heap-sort/
//�{�����F2018/10/15