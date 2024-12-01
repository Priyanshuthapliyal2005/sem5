#include <stdio.h>
#include <string.h>
#define MAX_FILES 100
#define MAX_BLOCKS 1000
typedef struct {
    char fname[20];
    int startBlk;
    int totalBlks;
    int blkList[MAX_BLOCKS];
    int idxBlk;
} FileRec;
FileRec fileDirectory[MAX_FILES];
int totalFileCount = 0;
void allocateContiguous(FileRec *rec) {
    for (int i = 0; i < rec->totalBlks; i++) {
        rec->blkList[i] = rec->startBlk + i;
    }
}
void allocateLinked(FileRec *rec) {
    int currBlk = rec->startBlk;
    for (int i = 0; i < rec->totalBlks; i++) {
        rec->blkList[i] = currBlk;
        currBlk++;
    }
}
void allocateIndexed(FileRec *rec) {
    rec->idxBlk = rec->startBlk;
    for (int i = 0; i < rec->totalBlks; i++) {
        rec->blkList[i] = rec->startBlk + i + 1;
    }
}
void addFileRecord(char *fname, int startBlk, int totalBlks, char allocType) {
    FileRec rec;
     strcpy(rec.fname, fname);
    rec.startBlk = startBlk;
    rec.totalBlks = totalBlks;
    switch (allocType) {
        case 'C':
            allocateContiguous(&rec);
            break;
        case 'L':
            allocateLinked(&rec);
            break;
        case 'I':
            allocateIndexed(&rec);
            break;
        default:
            printf("Invalid allocation type!\n");
            return;}
    fileDirectory[totalFileCount++] = rec;}
void searchFileRecord(char *fname) {
    for (int i = 0; i < totalFileCount; i++) {
        if (strcmp(fileDirectory[i].fname, fname) == 0) {
            printf("File Name: %s\n", fileDirectory[i].fname);
            printf("Start Block: %d\n", fileDirectory[i].startBlk);
            printf("Total Blocks: %d\n", fileDirectory[i].totalBlks);
            printf("Blocks Occupied: ");
            for (int j = 0; j < fileDirectory[i].totalBlks; j++) {
                printf("%d ", fileDirectory[i].blkList[j]);
            }
            printf("\n");
            if (fileDirectory[i].idxBlk > 0) {
                printf("Index Block: %d\n", fileDirectory[i].idxBlk);}
            return; }
    }
    printf("File not found.\n");
}
int main() {
    int fileCount;
    char fname[20], searchFname[20], allocType;
    int startBlk, blkCount;
    printf("Enter number of files: ");
    scanf("%d", &fileCount);
    for (int i = 0; i < fileCount; i++) {
        printf("Enter file %d name: ", i + 1);
        scanf("%s", fname);
        printf("Enter starting block of file %d: ", i + 1);
        scanf("%d", &startBlk);
        printf("Enter number of blocks in file %d: ", i + 1);
        scanf("%d", &blkCount);
        printf("Enter allocation strategy (C: Contiguous, L: Linked, I: Indexed): ");
        scanf(" %c", &allocType);
        addFileRecord(fname, startBlk, blkCount, allocType);
    }
    printf("\nEnter the file name to search: ");
    scanf("%s", searchFname);
    searchFileRecord(searchFname);
    return 0;}
