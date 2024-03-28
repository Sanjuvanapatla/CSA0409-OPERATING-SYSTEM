#include <stdio.h>
#define MAX_BLOCKS 100
struct IndexBlock {
    int blockPointers[MAX_BLOCKS];
};
void allocateIndexed(struct IndexBlock index, int fileIndex) {
    printf("Allocating blocks for file %d:\n", fileIndex);
    for (int i = 0; i < MAX_BLOCKS; ++i) {
        if (index.blockPointers[i] != -1) {
            printf("Block %d\n", index.blockPointers[i]);
        }
    }
}

int main() {
    struct IndexBlock myIndex = {{19, 20, 21, 22, 23, 24, -1}};
    int fileNumber = 1; 
    allocateIndexed(myIndex, fileNumber);
    return 0;
}
