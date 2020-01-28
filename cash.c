#import <cs50.h>
#import <math.h>
#import <stdio.h>

int main(void) 
{
    
    int coins = 0;
    float changeinput;
    
    do
    {
        changeinput = get_float("Change:\n") * 100;
    } 
    while (changeinput <= 0);
     
    int change = round(changeinput);
    
    while (change > 0)
    {
        if (change - 25 >= 0)
        {
            change -= 25;
            coins++;
        }
        else if (change - 10 >= 0)
        {
            change -= 10;
            coins++;
        }
        else if (change - 5 >= 0)
        {
            change -= 5;
            coins++;
        } 
        else if (change - 1 >= 0)
        {
            change -= 1;
            coins++;
        }
    }
    printf("%i\n", coins);
}