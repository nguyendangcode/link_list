#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int value;
    struct node* next;
} node;

node* create_node(int value) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Không thể cấp phát bộ nhớ!\n");
        exit(1);
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void insert_tail(node** head_ref, int value) {
    node* new_node = create_node(value);

    if (*head_ref == NULL) {
        *head_ref = new_node;
    }
    else {
        node* temp = *head_ref;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
}

int GetValueIndex(node* head, int index) {
    if (head == NULL || index < 0)
        return -1;

    node* current = head;
    int i = 0;
    while (current != NULL && i < index) {
        current = current->next;
        i++;
    }

    if (current == NULL)
        return -1;

    return current->value;
}
int main() {
    node* head = NULL;

    insert_tail(&head, 10);
    insert_tail(&head, 20);
    insert_tail(&head, 30);

    int value = GetValueIndex(head, 2);
    printf(" gia tri index: %d\n", value);  // Kết quả: 20

    node* current = head;
    while (current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
