#import <cs50.h>
#import <math.h>
#import <stdio.h>

int get_card_length(long int card);
bool luhn_check(long int card, int card_length);
void card_type(long int card, int card_length, bool luhn);

int main(void)
{    
    long int card = get_long("Number: ");
    int card_length = get_card_length(card);
    
    if (card_length < 13 || card_length == 14 || card_length > 16)
    {
        printf("INVALID\n");
    }
    else
    {
        bool luhn = luhn_check(card, card_length);
        card_type(card, card_length, luhn);
    }
}

// Get number of digits in card
int get_card_length(long int card)
{
    int counter = 0;
    
    while (card > 0)
    {
        card = card / 10;
        counter++;
    }
    return counter;
}

//
bool luhn_check(long int card, int card_length)
{
    int counter = 0;
    int sum = 0;
    
    int digits[card_length];
    int sum_digits[card_length / 2];
    
    long int temp_card = card;
    
    // Create array from card number
    for (int i = 0; i < card_length; i++)
    {
        int digit = temp_card % 10;
        digits[i] = digit;
        temp_card /= 10;
    }
    
    // Create array of every other digit starting from the end of card number
    for (int i = 1; i < card_length; i += 2)
    {
        sum_digits[counter] = digits[i] * 2;
        counter++;
    }
    
    // Sum of remaining digits
    for (int i = 0; i < card_length; i += 2)
    {
        if (digits[i] < 10)
        {
            sum += digits[i];
        }
        else
        {
            sum += (digits[i] % 10) + (digits[i] / 10);
        }
    }
    
    // Sum of every other digit
    for (int i = 0; i < counter; i++)
    {
        if (sum_digits[i] < 10)
        {
            sum += sum_digits[i];
        }
        else
        {
            sum += (sum_digits[i] % 10) + (sum_digits[i] / 10);
        }
    }
    
    if (sum % 10 == 0)
    {
        // LUHN check passes
        return true;
    }
    else
    {
        // LUHN check fails
        return false;
    }
}

// Work out card type
void card_type(long int card, int card_length, bool luhn)
{
    if (luhn == false)
    {
        printf("INVALID\n");
    }
    else if (card / (long int) pow(10, card_length - 1) == 4)
    {
        printf("VISA\n");
    }
    else
    {
        switch (card / (long int) pow(10, card_length - 2))
        {
            case 34:
            // fallthrough
            case 37: 
                printf("AMEX\n");
                break;
            case 51 ... 55: 
                printf("MASTERCARD\n");
                break;
            default:
                printf("INVALID\n");
                break;                
        }
    }
}