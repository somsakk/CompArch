// array_pointer_hw.c
#include<stdio.h>

int main(void)
{
    int scores[5] = {-1, 16, -16, 258, -258};
    
    printf("scores[1] = %d = %#x\n", scores[1], scores[1]);
    printf("*scores = %d = %#x\n", *scores, *scores);
    printf("*(scores+1) = %d = %#x\n", *(scores+1), *(scores+1));
    printf("scores[5] = %d = %#x\n", scores[5], scores[5]);
    printf("*(scores+4) = %d = %#x\n", *(scores+4), *(scores+4));
    printf("scores = %p\n", scores); 
    printf("scores+1 = %p\n", scores+1);
    printf("scores+4 = %p\n", scores+4); 
    printf("Address of scores[0] = %p\n", &scores[0]);
    printf("Address of scores[1] = %p\n", &scores[1]); 
    printf("Address of scores[4] = %p\n", &scores[4]); 

	*(scores+2) = 3;
	for (int i = 1; i<3; i++) {
		printf("%d\n", scores[i]);
	}
}
