#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Listeye rastgele uretilmis 100 sayi eklensin, girilen tum sayilari buyukten kucuge siralayan ve 
ekrana basan c kodunu yaziniz.
*/
struct Node {
    int data;
    struct Node* next;
};

void sorter(struct Node **head, int value) {
    
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || value >= (*head)->data) {
        newNode->next = *head; //eðer düðüm boþsa ya da deðer head den büyükse baþa ekliyoruz
        *head = newNode;
    } else {
        struct Node *current = *head;
        while (current->next != NULL && current->next->data > value) {
            current = current->next; //eðer deðer nextten küçükse diðer nexte bakýyoruz
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}

int main() {
    int rastgele_sayilar[100];
    int i;
    struct Node *head = NULL;

    // Rastgele sayý üretmek için zamaný kullanarak srand fonksiyonunu ayarlayýn.
    srand(time(NULL));

    // 1 ile 1000 arasý 100 sayi olustur
    for (i = 0; i < 100; i++) {
        rastgele_sayilar[i] = rand() % 1000 + 5;
    }

    for (i = 0; i < 100; i++) {
        sorter(&head, rastgele_sayilar[i]);
    }

    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    return 0;
}
