#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long long int num_card, cur_card, div = 10;
    int sum1 = 0, sum2 = 0, sum3 = 0, cont = 0, lastdig = 0;
    do
    {
        printf("Please, insert here your Card number:");
        scanf("%lld", &num_card);
        //num_card = get_long("Please, insert here your Card number: ");
    }
    while (num_card <= 0);

    // Current Card number must be greater than 0.

    // First Step of Luhn's Algorithm

    cur_card = num_card;

    while (cur_card > 0)
    {
        lastdig = cur_card % 10;
        sum1 = sum1 + lastdig;
        cur_card = cur_card / 100;
    }

    // Second Step of Luhn's Algorithm

    cur_card = num_card / 10;
    while (cur_card > 0)
    {
        lastdig = cur_card % 10;
        int mult = lastdig * 2;
        sum2 = sum2 + (mult % 10) + (mult / 10);
        cur_card = cur_card / 100;
    }

    // Third Step of Luhn's Algorithm

    sum3 = sum1 + sum2;
    cur_card = num_card;
    while (cur_card != 0)
    {
        cur_card = cur_card / 10;
        cont++;
    }

    for (int i = 0; i < cont - 2; i++)

    {
        div = div * 10;
    }
    int firstdig = num_card / div;
    int twodig = num_card / (div / 10);

    // If the last digit is equal to 0 and the number of the credit card is valid.
    // Now we need to find out if the card is Visa, Master or Amex.

    if (sum3 % 10 == 0)
    {
        if ((firstdig == 4) && (cont == 13 || cont == 16))
        {
            printf("VISA\n");
        }
        else if ((twodig == 34 || twodig == 37) &&  cont == 15)
        {
            printf("AMEX\n");
        }
        else if ((twodig > 50 && twodig < 56) && cont == 16)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }

}