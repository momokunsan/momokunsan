#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


// �Q�d���`���X�g�̃m�[�h�i�Z���j�̍\����
typedef struct tagNode {
	struct tagNode *prev; // �O�̃m�[�h�ւ̃|�C���^
	struct tagNode *next; // ���̃m�[�h�ւ̃|�C���^
	int data; // �m�[�h�̃f�[�^�i����͐����^�j
} Node;

// ���C���֐�
int main(void) {
	int buf;
	Node *firstNode, *lastNode, *newNode;
	firstNode = lastNode = NULL;
	do {
		printf("�����l����͂��Ă��������i0����͂���ƏI���j:");
		scanf("%d", &buf); //���͂��ꂽ�����l�̓ǂݍ���
		if (buf) {
			// �V�����m�[�h�i�Z���j�̍쐬�D�������m�ہD
			newNode = (Node*)malloc(sizeof(Node));
			newNode->data = buf;
			newNode->next = NULL;

			// ���Ƀm�[�h�����݂���ꍇ
			if (lastNode != NULL) {
				lastNode->next = newNode;
				newNode->prev = lastNode;
				lastNode = newNode;
			}
			//�m�[�h�����݂��Ă��Ȃ��ꍇ
			else {
				firstNode = lastNode = newNode;
				newNode->prev = NULL;
			}
		}
	} while (buf != 0);

	//�m�[�h�̍폜
	do {
		printf("�폜����l����͂��Ă��������i0����͂���ƏI���j:");
		scanf("%d", &buf); //���͂��ꂽ�����l�̓ǂݍ���
		if (buf) {
			int x = FALSE;
			Node *deleteNode;
			for (deleteNode = firstNode; deleteNode != NULL; deleteNode = deleteNode->next) {
				// �f�[�^�����݂���ꍇ
				if (deleteNode->data == buf) {
					printf("���͂��ꂽ�l�̒���%d��������܂����B�m�[�h���폜���܂��B\n", buf);
					/*�����Ƀm�[�h�폜�̏���������*/
					//�폜����m�[�h���ŏ��̃m�[�h�̏ꍇ
					if (firstNode->data == deleteNode->data) {
						firstNode = deleteNode->next;
					}
					//�ŏ��ȊO�̃m�[�h�̏ꍇ
					if (deleteNode->next != NULL) {
						deleteNode->next->prev = deleteNode->prev;
					}
					if (deleteNode->prev != NULL) {
						deleteNode->prev->next = deleteNode->next;
					}
					x = TRUE; //�^���L�^
				}	
			}
			// �f�[�^�����݂��Ȃ��ꍇ
			if (x == FALSE) {
				printf("%d�͑��݂��܂���\n", buf);
			}
		}
	} while (buf != 0);


	// ���͂��ꂽ���̏o��
	printf("--���͂��ꂽ�͈̂ȉ��̐��ł�--\n");
	Node* thisNode;
	for (thisNode = firstNode; thisNode != NULL; thisNode = thisNode->next) {
		printf("%d ", thisNode->data);
	}

	printf("\n");

	// ���X�g�̑S�m�[�h�i�Z���j���폜
	// C�̏ꍇ������s��Ȃ��ƃ��������[�N�ƂȂ�D
	for (thisNode = firstNode; thisNode != NULL; ) {
		Node* removeNode = thisNode;
		thisNode = thisNode->next;
		free(removeNode);
	}
	return 0;
}
