#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


int findBinary(int num,int *arr, int size)					// finding Binary of a number
{
    int temp[8];
    int i = 0;
    while(num)
    {
        temp[i] = num % 2;
        num /= 2;
        i++;
    }   

    while( i < 8)
    {
        temp[i] = 0;
        i++;
    }


    for(i = i - 1; i >= 0 ; i--)
    {
        arr[size] = temp[i];
        size++;
    }
    return size;
}

int findDecimal(int *binaryCode)						// finding Decimal of a number
{
    int decimal = 0;
    int j = 5;
    for(int i = 0 ; i < 6 ; i++)
    {
        decimal += binaryCode[j--] * (int) pow(2,i);
    }
    return decimal;
}

char* encode(char *input)							// encoding function
{
    int size = strlen(input);
    int asciCodes[size];
    for(int i = 0 ; i < size ; i++)
    {
        asciCodes[i] = (int) input[i];						// fetching ascii values of all the characters
    }



    char s[64]= "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/0123456789";			// encoding table string

    int binaryData[8*size];
    int count = 0;
    for(int i = 0 ; i < size ; i++)
    {
        count = findBinary(asciCodes[i],binaryData,count);					// getting binary codes
    }


    int count1 = 0;
    int finalSize = 0;
    char *res = (char *)malloc(finalSize * sizeof(char));
    int index = 0;
    int temp[6];


    int remaining = count % 6;
    for(int i = 0 ; i <= count - remaining ; i++)
    {
        if(count1 % 6 == 0 && count1 != 0)							// inserting encoded character to the result string
        {
            int y = findDecimal(temp);
            finalSize++;
            res = (char *)realloc(res,finalSize * sizeof(char));
            res[index++] = s[y];
            count1 = 0;
        }
        temp[count1] = binaryData[i];
        count1++;
    }
    count1 = 0;

    for(int i = count - remaining; i < count ; i++)						// incase binaryStore size % 6 != 0;
    {
        temp[count1] = binaryData[i];
        count1++;    
    }
    for(int i = 0; i <= (6 - remaining) ; i++ )
    {
        if(count1 % 6 == 0)
        {
            int y = findDecimal(temp);
            finalSize++;
            res = (char *)realloc(res,finalSize * sizeof(char));
            res[index++] = s[y];
            count1 = 0;
        }
        temp[count1] = 0;
        count1++;
    }




    if(strlen(input) % 3 == 2)									// inserting '=' if strlen(input) % 3 == 0
    {
        finalSize++;
        res = (char *)realloc(res, finalSize * sizeof(char));
        res[index++] = '=';
    }

    if(strlen(input) % 3 == 1)
    {
        finalSize += 2;
        res = (char *)realloc(res, finalSize * sizeof(char));
        res[index++] = '=';
        res[index] = '=';
    }

    return res;
}


int main()
{
    char *input = (char *)malloc(51200 * sizeof(char));
    scanf("%s",input);
    char *res;
    res = encode(input);
    printf("%s",res);
    
    return 0;
}
