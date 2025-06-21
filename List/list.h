#ifndef LISTAWP_LIST_H
#define LISTAWP_LIST_H


#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1


int insertFront(int element);

int insertBack(int element);

int insertAfterNode(int index, int element);

int deleteFront();

int deleteBack();

int deleteNode(int index);

int readFromTop();
int readFromBeginning();

int searchList(int key);

void printList(void);

int getNodesCount();

void freeList(void);


#endif //LISTAWP_LIST_H