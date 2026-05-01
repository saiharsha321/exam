}
7. Write C programs to simulate the following memory management techniques a) Paging b) Segmentation
C Program for Paging
#include <stdio.h>

int main() {
    int pages, frames, i;
    
    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    int pageTable[pages];

    printf("Enter frame number for each page:\n");
    for(i = 0; i < pages; i++) {
        printf("Page %d: ", i);
        scanf("%d", &pageTable[i]);
    }

    int page, offset;
    printf("\nEnter page number: ");
    scanf("%d", &page);

    printf("Enter offset: ");
    scanf("%d", &offset);

    if(page >= pages) {
        printf("Invalid page number\n");
    } else {
        int physicalAddress = pageTable[page] * 1000 + offset;
        printf("Physical Address = %d\n", physicalAddress);
    }

    return 0;
}
C Program for Segmentation
#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of segments: ");
    scanf("%d", &n);

    int base[n], limit[n];

    printf("Enter base and limit for each segment:\n");
    for(i = 0; i < n; i++) {
        printf("Segment %d Base: ", i);
        scanf("%d", &base[i]);

        printf("Segment %d Limit: ", i);
        scanf("%d", &limit[i]);
    }

    int seg, offset;
    printf("\nEnter segment number: ");
    scanf("%d", &seg);

    printf("Enter offset: ");
    scanf("%d", &offset);

    if(seg >= n) {
        printf("Invalid segment number\n");
    } else if(offset >= limit[seg]) {
        printf("Offset exceeds limit (Segmentation Fault)\n");
    } else {
        int physicalAddress = base[seg] + offset;
        printf("Physical Address = %d\n", physicalAddress);
    }

    return 0;
}