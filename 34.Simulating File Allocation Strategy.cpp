#include <stdio.h>
#define MAX_BLOCKS 100

struct File {
    int startBlock;
    int length;
};

void allocateContiguous(struct File file) {
    printf("Allocating blocks for file starting at block %d:\n", file.startBlock);
    for (int i = file.startBlock; i < file.startBlock + file.length; ++i) {
        printf("Block %d\n", i);
    }
}

int main() {
    struct File myFile = {19, 6}; 
    allocateContiguous(myFile);
    return 0;
}
