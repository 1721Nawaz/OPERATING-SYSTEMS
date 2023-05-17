
#include <stdio.h>

int contiguousAllocation(int fileLength, int blockSize) {
    int numBlocks = fileLength / blockSize;
    int numIOOperations = 2;  
    int i;

    for (i = 0; i < numBlocks; i++) {

        numIOOperations++;
    }

    return numIOOperations;
}


int linkedAllocation(int fileLength, int blockSize) {
    int numBlocks = fileLength / blockSize;
    int numIOOperations = 2; 

    numIOOperations += numBlocks;

    return numIOOperations;
}

int indexedAllocation(int fileLength, int blockSize, int indexBlockSize) {
    int numBlocks = fileLength / blockSize;
    int numIOOperations = 2;  

    int numIndexBlocks = (numBlocks + indexBlockSize - 1) / indexBlockSize;

    numIOOperations += numIndexBlocks;

    numIOOperations += numBlocks;

    return numIOOperations;
}

int main() {
    int fileLength = 100;
    int blockSize = 1;
    int indexBlockSize = 10;

    int contiguousIO = contiguousAllocation(fileLength, blockSize);
    int linkedIO = linkedAllocation(fileLength, blockSize);
    int indexedIO = indexedAllocation(fileLength, blockSize, indexBlockSize);

    printf("Contiguous allocation: %d disk I/O operations\n", contiguousIO);
    printf("Linked allocation: %d disk I/O operations\n", linkedIO);
    printf("Indexed allocation: %d disk I/O operations\n", indexedIO);

    return 0;
}

