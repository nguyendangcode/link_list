﻿#include <stdio.h>
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
//Insert: chèn node vào linked list ở vị trí index
//- input:
//*linked_list_t * địa của đối tượng linked lisst, mà ta sẽ insert đối tượng vào
//* int value : giá trị của node.
//* int index : vị trí node được insert vào.
//- Output : void
//- Gợi ý : giống như add chúng ta cũng cần cấp phát động, và chúng ta cần update lại previous_node của node trước nó
void insert_at_index(node** head_ref, int value, int index) {
    node* new_node = create_node(value);
    if (index == 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }
    node* current = *head_ref;
    for (int i = 0; i < index - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Vị trí không hợp lệ!\n");
        free(new_node);
        return;
    }
    new_node->next = current->next;
    current->next = new_node;
}
void remove_node(node** head_ref, int index) {
    if( *head_ref == NULL || index < 0) {
        printf("Vị trí không hợp lệ!\n");
        return;
	}
    else if(index == 0) {
        node* temp = *head_ref;
        *head_ref = (*head_ref)->next;
        free(temp);
        return;
	}
    node* current = *head_ref;
    for(int i = 0; current != NULL && i < index - 1; i++) {
        current = current->next;
    }
    node* next_node = current->next->next;
    free(current->next);
	current->next = next_node;
}
void sreach_value(node* head, int value) {
    node* current = head;
    int cnt = 0;
    while (current != NULL) {
        if( current->value == value) {
            printf("index %d được tìm thấy tại gia tri %d\n", value, cnt);
		}
        cnt++;
        current = current->next;
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

	insert_at_index(&head, 20, 0);
	insert_at_index(&head, 30, 1);
    insert_at_index(&head, 20, 2);
	sreach_value(head, 20);
    node* current = head;
    while (current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
