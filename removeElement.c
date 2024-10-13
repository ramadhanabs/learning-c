#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *array;
    size_t used;
    size_t size;
};

void initArray(struct Array *a, size_t initialSize)
{
    a->array = malloc(initialSize * sizeof(int));
    a->used = 0;
    a->size = initialSize;
};

void appendArray(struct Array *a, int value)
{
    if (a->used == a->size)
    {
        a->size *= 2;
        int *temp = realloc(a->array, a->size * sizeof(int));
        if (temp == NULL)
        {
            fprintf(stderr, "Memory reallocation failed\n");
            free(a->array);
            exit(1);
        }

        a->array = temp;
    }
    a->array[a->used++] = value;
}

void freeArray(struct Array *a)
{
    free(a->array);
    a->array = NULL;
    a->used = 0;
    a->size = 0;
}

int removeElements(int *nums, int numsSize, int val)
{
    int j = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
        {
            nums[j] = nums[i];
            j++;
        };
    }

    return j;
}

int main(void)
{
    struct Array nums;

    initArray(&nums, 2);
    appendArray(&nums, 3);
    appendArray(&nums, 2);
    appendArray(&nums, 2);
    appendArray(&nums, 3);

    int num = removeElements(nums.array, nums.size, 2);

    for (size_t i = 0; i < nums.size; i++)
    {
        printf("Value => %d \n", nums.array[i]);
    }
    
    printf("Num => %d", num);

    return 0;
}