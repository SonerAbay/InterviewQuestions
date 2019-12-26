#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;


struct node {
	int data;
	struct node* next;
};

typedef struct node* NODEPTR;

// düğüm oluşturur
NODEPTR getNode() {
	return (NODEPTR)malloc(sizeof(node));
}

// düğümü temizler
void freeNode(NODEPTR p) {
	free(p);
}

// bagli listeye eleman ekleyen fonksiyon
void push(NODEPTR* head, int x) {
	NODEPTR p = getNode();
	p->data = x;
	p->next = *head;
	*head = p;
}

void insertAfter(NODEPTR head, int x) {
	if (head == NULL)
		printf("Bos liste! \n");
	else {
		NODEPTR p = getNode();
		p->next = head->next;
		p->data = x;
		head->next = p;
	}
}

int pop(NODEPTR *head) {
	if (*head == NULL) {
		printf("Gonderilen liste bos!");
		return -1;
	}
	else {
		NODEPTR p = *head;
		int x = p->data;
		*head = (*head)->next;
		freeNode(p);
		return x;
	}
}


void printList(NODEPTR head) {

	while (head != NULL) {

		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("NULL\n");

}

/*
2->1->3->5->6->4->7
*/
// Sorunun Linked List ile cozumu
NODEPTR oddEvenList(NODEPTR head) {

    // baslangicta cift ve cHead dugumlerini head'in nextine atariz.
	NODEPTR tek = head, cift = head->next, cHead = cift;

    // listenin sonuna gelmedigimiz surece tek ve cift dugumleri next'in nextine bagliyor
	while (cift != NULL && cift->next != NULL) {
		tek->next = cift->next;
		tek = tek->next;
		cift->next = tek->next;
		cift = cift->next;
	}
    // gruplandirma bittikten sonra tekler grubunun sonuna cift grubu baglaniyor
	tek->next = cHead;
	return head;

}

// sorunun array ile cozumu
int *oddEvenArr(int arr[], int len) {

	int *arr1;
	int *arr2;

	// eğer size çiftse tek ve çift arrayi tam 2'ye bölünebilir
	if (len % 2 == 0) {
		arr1 = new int[len / 2];
		arr2 = new int[len / 2];
	}
	// tekse tekincil indisler arrayinin size'ı 1 fazla olmalı
	else {
		arr1 = new int[len / 2 + 1];
		arr2 = new int[len / 2];
	}


	for (int i = 0; i < len; i++) {
		// i'yi sıfırdan başladığımız ve ilk elemanı 1. saydığımız için çift indisi tekincil indis olarak sayarız
		if (i % 2 == 0) {
			arr1[i / 2] = arr[i];
		}
		else
			arr2[i / 2] = arr[i];
	}

	// tek ve çift arrayi birleştirir
	int * result = new int[len];
	std::copy(arr1, arr1 + len / 2 + 1, result);
	std::copy(arr2, arr2 + len / 2, result + len / 2 + 1);

	return result;

}

int main() {
	// tek bagli liste
	NODEPTR n = NULL;

	// arrayi declare ederiz
	int arr[100000];
	
    // random number declare
    int rn;

	// hem arraye hem listeye 100.000 adet random int atarız
	for (int i = 0; i < 100000; i++) {
		rn = rand() % 100;
		arr[i] = rn;
		push(&n, rn);
	}

    // linked list ile cozum hiz testi
	auto start = high_resolution_clock::now();
	NODEPTR l = oddEvenList(n);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	
	// array ile cozum hiz testi
	auto start2 = high_resolution_clock::now();
	int*newArr = oddEvenArr(arr, 100000);
	auto stop2 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(stop2 - start2);

	cout << "Tek bagli liste ile cozum: "
		<< duration.count() << " mikrosaniye" << endl;

	cout << "Array ile cozum: "
		<< duration1.count() << " mikrosaniye" << endl;


	getchar();
}