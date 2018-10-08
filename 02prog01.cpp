#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


// ２重線形リストのノード（セル）の構造体
typedef struct tagNode {
	struct tagNode *prev; // 前のノードへのポインタ
	struct tagNode *next; // 次のノードへのポインタ
	int data; // ノードのデータ（今回は整数型）
} Node;

// メイン関数
int main(void) {
	int buf;
	Node *firstNode, *lastNode, *newNode;
	firstNode = lastNode = NULL;
	do {
		printf("整数値を入力してください（0を入力すると終了）:");
		scanf("%d", &buf); //入力された整数値の読み込み
		if (buf) {
			// 新しいノード（セル）の作成．メモリ確保．
			newNode = (Node*)malloc(sizeof(Node));
			newNode->data = buf;
			newNode->next = NULL;

			// 既にノードが存在する場合
			if (lastNode != NULL) {
				lastNode->next = newNode;
				newNode->prev = lastNode;
				lastNode = newNode;
			}
			//ノードが存在していない場合
			else {
				firstNode = lastNode = newNode;
				newNode->prev = NULL;
			}
		}
	} while (buf != 0);

	//ノードの削除
	do {
		printf("削除する値を入力してください（0を入力すると終了）:");
		scanf("%d", &buf); //入力された整数値の読み込み
		if (buf) {
			int x = FALSE;
			Node *deleteNode;
			for (deleteNode = firstNode; deleteNode != NULL; deleteNode = deleteNode->next) {
				// データが存在する場合
				if (deleteNode->data == buf) {
					printf("入力された値の中に%dが見つかりました。ノードを削除します。\n", buf);
					/*ここにノード削除の処理を書く*/
					//削除するノードが最初のノードの場合
					if (firstNode->data == deleteNode->data) {
						firstNode = deleteNode->next;
					}
					//最初以外のノードの場合
					if (deleteNode->next != NULL) {
						deleteNode->next->prev = deleteNode->prev;
					}
					if (deleteNode->prev != NULL) {
						deleteNode->prev->next = deleteNode->next;
					}
					x = TRUE; //真を記録
				}	
			}
			// データが存在しない場合
			if (x == FALSE) {
				printf("%dは存在しません\n", buf);
			}
		}
	} while (buf != 0);


	// 入力された数の出力
	printf("--入力されたのは以下の数です--\n");
	Node* thisNode;
	for (thisNode = firstNode; thisNode != NULL; thisNode = thisNode->next) {
		printf("%d ", thisNode->data);
	}

	printf("\n");

	// リストの全ノード（セル）を削除
	// Cの場合これを行わないとメモリリークとなる．
	for (thisNode = firstNode; thisNode != NULL; ) {
		Node* removeNode = thisNode;
		thisNode = thisNode->next;
		free(removeNode);
	}
	return 0;
}
