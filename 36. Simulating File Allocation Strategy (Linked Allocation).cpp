#include <stdio.h>
struct FileBlock {
    int blockNumber;
    struct FileBlock* next;
};
void allocateLinked(struct FileBlock* firstBlock) {
    printf("Allocating blocks for file:\n");
    struct FileBlock* current = firstBlock;
    while (current != NULL) {
        printf("Block %d\n", current->blockNumber);
        current = current->next;
    }
}

int main() {
    struct FileBlock block1 = {19, NULL};
    struct FileBlock block2 = {20, NULL};
    struct FileBlock block3 = {21, NULL};
    block1.next = &block2;
    block2.next = &block3;
    allocateLinked(&block1);
    return 0;
}
