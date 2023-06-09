
#include <stdio.h>
#define MAX_FRAMES 3

int main()
{
    int frames[MAX_FRAMES], page_faults = 0, pointer = 0, hit = 0;
    int pages[] = {1,2,3,2,1,5,2,1,6,2,5,6,3,1,3,6,1,2,4,3};
    int num_pages = sizeof(pages)/sizeof(pages[0]);
    int i, j;

    for(i = 0; i < MAX_FRAMES; ++i)
        frames[i] = -1;

    printf("Page Reference String: ");
    for(i = 0; i < num_pages; ++i){
        printf("%d ", pages[i]);

        hit = 0;
        for(j = 0; j < MAX_FRAMES; ++j){
            if(frames[j] == pages[i]){
                hit = 1;
                break;
            }
        }

        if(hit == 0){
            frames[pointer] = pages[i];
            pointer = (pointer + 1) % MAX_FRAMES;
            ++page_faults;
        }

        printf("Current Page Frames: ");
        for(j = 0; j < MAX_FRAMES; ++j){
            if(frames[j] == -1)
                printf("| | ");
            else
                printf("|%d| ", frames[j]);
        }
        printf("\n");
    }

    printf("Number of Page Faults = %d\n", page_faults);

}
