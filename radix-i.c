#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR  "Victor Adu"
#define YEAR 2022

void Dec2RadixI(int decValue , int radValue);

int main (void)
{
    printf("*****************************\n");
    printf("%s\nWritten by: %s\n", TITLE, AUTHOR);
    printf("Date: %d\n", YEAR);
    printf("*****************************\n");
    
    int  num;
    u_int32_t radix;

    do
    {
        printf("Enter a decimal number: ");
        scanf("%d",&num);
        
        if (num < 0)
        {
            printf("EXIT\n");
            break;
        }
        
        printf("The decimal number you have entered is %d\n",num);
        
        // Anticipate numbers not between 2 and 16
        do
        {
            printf("Enter a radix for the converter between 2 and 16: ");
            scanf("%d",&radix);
        } while ((radix < 2) || (radix > 16));
        
        printf("The radix you have entered is %d\n",radix);
        
        Dec2RadixI(num, radix);
        printf("\n");

    } while (num > 0);
   
    return 0;
}






void Dec2RadixI(int decValue, int radValue)
{
        // find the log 
        int q;
        float msbIndex;
        int rem;
        int result;
        msbIndex = ceil(log10(decValue+1)/log10(radValue))-1; // most significant bit
        printf("The log%d of the number is %.2f\n",radValue,msbIndex);
        
        result = decValue / radValue;
        rem = decValue % radValue;

        printf("The integer result of the number divided by %d is %d\n",radValue,result);
        printf("The remainder is %d\n",rem);

        // Convert to base radix using sum of weights

        printf("The radix-%d value is ",radValue);
        for (int i = msbIndex; i >= 0 ; i--)
        {
            q = decValue / pow(radValue,i); // Get the quotient
            if (q > 9) // check for letter representation
            {
                printf("%c",q+55); // Cheating with ASCII
            } else
            {
                printf("%d",q);
            }

            decValue %= (int)pow(radValue,i); // continue with remainder
        }
        printf("\n");

}