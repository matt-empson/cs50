#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    
    do 
    {
        height = get_int("Height:\n");
    }
    while (height < 1 || height > 8);
      
    for (int row = 1; row <= height; row++) 
    {
        for (int fs = 0; fs < height - row; fs++)
        {
            printf(" ");
        }
        for (int fh = 0; fh < row; fh++) 
        {
            printf("#");
        }
        printf("  ");
        for (int sh = 0; sh < row; sh++) 
        {
            printf("#");
        }
        printf("\n");
    }
}
