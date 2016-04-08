#include <iostream>

using namespace std;

struct Node{
	char word[40];
	int count;
	Node* next;
};
typedef Node* PNode;
PNode Head = NULL;

PNode CreateNode(char NewWord[]){	//возвращает адрес созданного узла
	//PNode NewNode = *(new PNode);
	PNode NewNode = (PNode)malloc(sizeof(Node));
	strcpy_s(NewNode->word, strlen(NewWord), NewWord);
	NewNode->count = 1;
	NewNode->next = NULL;
	return NewNode;
}
void AddFirst(PNode *Head, PNode NewNode){
	NewNode->next = *Head;
	Head = &NewNode;
}
void AddAfter(PNode p, PNode NewNode){
	NewNode->next = p->next;
	p->next = NewNode;
}
void show(){
	PNode temp = Head;
	while (temp != NULL){
		cout << temp->word << endl;
		temp = temp->next;
	}
}
void AddLast(PNode* Head, PNode NewNode){
	PNode q = *Head;
	if (Head == NULL){
		AddFirst(Head, NewNode);
		return;
	}
	while (q->next)q = q->next;
	AddAfter(q, NewNode);
}
PNode Find(PNode Head, char NewWord[]){
	PNode q = Head;
	while (q&&strcmp(q->word, NewWord))
		q = q->next;
	return q;
}
void DeleteNode(PNode* Head,PNode p){
	PNode q = *Head;
	if (*Head == p){
		Head = &(p->next);
	}
	else {
		while (q&&q->next != p){
			q = q->next;
		}
		if (q == NULL) return;
		q->next = p->next;
	}
	free(p);
}

int main(){
	PNode el=CreateNode("hello");



	
	system("pause>void");
	return 0;
}