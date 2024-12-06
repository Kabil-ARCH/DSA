#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct webStack {
    char *history;
};

int counter = 0;

void addHistory(struct webStack historyStore[], const char *website) {
    historyStore[counter].history = malloc(strlen(website) + 1); // Allocate memory
    if (historyStore[counter].history == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(historyStore[counter].history, website); // Copy website to history
    counter++;
}

void displayHistory(struct webStack historyStore[]) {
    printf("Browser History:\n");
    for (int i = 0; i < counter; i++) {
        printf("%d: %s\n", i + 1, historyStore[i].history);
    }
}

void freeHistory(struct webStack historyStore[]) {
    for (int i = 0; i < counter; i++) {
        free(historyStore[i].history); // Free each allocated memory
    }
}

int main() {
    struct webStack historyStore[100]; // Array to hold up to 100 websites

    addHistory(historyStore, "https://github.com");
    addHistory(historyStore, "https://stackoverflow.com");
    addHistory(historyStore, "https://openai.com");

    displayHistory(historyStore);

    freeHistory(historyStore);

    return 0;
}

