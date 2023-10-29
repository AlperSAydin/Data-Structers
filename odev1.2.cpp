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
        newNode->next = *head; //e�er d���m bo�sa ya da de�er head den b�y�kse ba�a ekliyoruz
        *head = newNode;
    } else {
        struct Node *current = *head;
        while (current->next != NULL && current->next->data > value) {
            current = current->next; //e�er de�er nextten k���kse di�er nexte bak�yoruz
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}

int main() {
    int rastgele_sayilar[100];
    int i;
    struct Node *head = NULL;

    // Rastgele say� �retmek i�in zaman� kullanarak srand fonksiyonunu ayarlay�n.
    srand(time(NULL));

    // 1 ile 1000 aras� 100 sayi olustur
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
