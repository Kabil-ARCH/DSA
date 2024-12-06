#include <stdio.h>
#include <stdlib.h>

struct phoneBook {
  char *name;
  long phoneNumber;
  struct phoneBook *next;
};

struct phoneBook *createNode(char *name, long phoneNumber) {
  struct phoneBook *newNode =
      (struct phoneBook *)(malloc(sizeof(struct phoneBook)));
  newNode->phoneNumber = phoneNumber;
  newNode->name = name;
  newNode->next = NULL;
  return newNode;
}

void displayContact(struct phoneBook *head) {
  struct phoneBook *temp = head;
  printf("Contact Innformation:\n");
  int number = 1;
  while (temp != NULL) {
    printf("%d: contact Name: %s \tnumber:%ld\n", number, temp->name,
           temp->phoneNumber);
    number++;
    temp = temp->next;
  }
}
void AddContact(struct phoneBook **head, char *name, long phoneNumber) {
  struct phoneBook *newNode = createNode(name, phoneNumber);
  if (*head == NULL) {
    *head = newNode;
  } else {
    struct phoneBook *temp = *head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}
int main() {
  struct phoneBook *head = NULL;
  AddContact(&head, "nithesh", 8248854743);
  AddContact(&head, "nandha", 9620293488);
  AddContact(&head, "Kabil", 9344878410);
  displayContact(head);
  return 0;
}
