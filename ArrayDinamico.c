#include <stdio.h>
#include <stdlib.h>

int addAtTail(int **array, int data, int *sizeArray);
int addAtFront(int **array, int data, int *sizeArray);
int sizeArrayValue(int *array);
void removeAll(int **array);
int getAt(int *array, int index, int sizeArray);


int main()
{
    int *array;
    int sizeArray = 0, iterator, data, result;
    char answer;

    do{
        printf("enter data: ");
        scanf("%d", &data);
        result = addAtFront(&array, data, &sizeArray);
       if(result)
        {
            printf("another one? (y = yes / n = no): ");
            fflush(stdin);
            scanf("%s", &answer);
        }else
            printf("\nerror: data not entered");
    }while (answer == 'y' && result);    

    for(iterator = 0; iterator < sizeArray; iterator++)
        printf("%d ",*(array + iterator));

    printf("\nwhat index? ");
    scanf("%d", &data);
    result = getAt(array,data,sizeArray);
    printf("\n%d ",result);

    result = sizeArrayValue(array);
    printf("\n size: %d", result);

    removeAll(&array);
    return (0);
}

//function to add at tail
int addAtTail(int **array, int data, int *sizeArray)
{
    int result, iterator;
    int *arrayAuxiliary;

    if(sizeArray > 0)
    {
        arrayAuxiliary = (int *) malloc(*sizeArray * sizeof(int));
        if(arrayAuxiliary)
        {
            for(iterator = 0; iterator < *sizeArray; iterator++)
                *(arrayAuxiliary + iterator) = *(*array + iterator);

            free(*array);

            *array = (int *) malloc(*sizeArray + 1 * sizeof(int));
            if(*array)
            {
                for(iterator = 0; iterator < *sizeArray; iterator++)
                *(*array + iterator) = *(arrayAuxiliary + iterator);

                *(*array + iterator) = data;

                (*sizeArray)++;
                result = 1;
            }else
                result = 0;
        }else
            result = 0;
    }else
    {
        *array = (int *) malloc(sizeof(int));
        if(*array)
        {
            *(*array) = data;
            (*sizeArray)++;
            result = 1;
        }else
            result = 0;
    }
    return (result);
}
//function to add at front 
int addAtFront(int **array, int data, int *sizeArray)
{
    int result, iterator;
    int *arrayAuxiliary;

     if(sizeArray > 0)
    {
        arrayAuxiliary = (int *) malloc(*sizeArray * sizeof(int));
        if(arrayAuxiliary)
        {
            for(iterator = 0; iterator < *sizeArray; iterator++)
                *(arrayAuxiliary + iterator) = *(*array + iterator);

            free(*array);

            *array = (int *) malloc(*sizeArray + 1 * sizeof(int));
            if(*array)
            {
                for(iterator = 1; iterator < *sizeArray + 1; iterator++)
                *(*array + iterator) = *(arrayAuxiliary + iterator - 1);

                *(*array) = data;

                (*sizeArray)++;
                result = 1;
            }else
                result = 0;
        }else
            result = 0;
    }else
    {
        *array = (int *) malloc(sizeof(int));
        if(*array)
        {
            *(*array) = data;
            (*sizeArray)++;
            result = 1;
        }else
            result = 0;
    }
    return (result);
}
//function to remove all
void removeAll(int **array)
{
    free(*array);
    *array = NULL;
}
//function to get at
int getAt(int *array, int index, int sizeArray)
{
    int data, iterator;

    for(iterator = 0; iterator < sizeArray && iterator != index; iterator++);

    if (iterator == index)
        data = *(array + iterator - 1);
    else
        data = -1;
    return(data);
}
int sizeArrayValue(int *array){
    int value =sizeof(array);

    return(value/2);
}