#include "Stack_Dynamic_DS_BasedOnArray.h"

static uint8 StackIsEmpty(Stack *stack_obj);
static uint8 StackIsFull(Stack *stack_obj);

/**
  * @brief  This algorithm creates an empty stack by allocating the head
            structure and the array from dynamic memory.
  * @param  (maxSize) Stack maximum number of elements
  * @param  (ret_status) Status returned while performing this operation
  * @retval Pointer to the allocated stack in the heap
  */
Stack *CreateStack(uint32 maxSize, StackStatus *ret_status)
{
    Stack *RetPtr = NULL;

    if(!ret_status)
    {
        RetPtr = NULL;
        *ret_status = STACK_NULL_POINTER;
    }
    else
    {
        RetPtr = (Stack *)malloc(sizeof(Stack));
        if(!RetPtr)
        {
            RetPtr = NULL;
            *ret_status = STACK_NOK;
        }
        else
        {
            RetPtr->StackTop = -1;
            RetPtr->ElementCount = 0;
            RetPtr->StackMaxSize = maxSize;
            RetPtr->StackArray = (void **)calloc(RetPtr->StackMaxSize, sizeof(void *));
            if(!(RetPtr->StackArray))
            {
                free(RetPtr);
                RetPtr = NULL;
                *ret_status = STACK_NOK;
            }
            else
            {
                *ret_status = STACK_OK;
            }
        }
    }

    return RetPtr;
}

/**
  * @brief  This function releases all memory to the heap.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (ret_status) Status returned while performing this operation
  * @retval NULL
  */
Stack *DestroyStack(Stack *stack_obj, StackStatus *ret_status)
{
    if((!stack_obj) || (!ret_status))
    {
        *ret_status = STACK_NULL_POINTER;
    }
    else
    {
        free(stack_obj->StackArray);
        free(stack_obj);
        *ret_status = STACK_OK;
    }

    return NULL;
}

/**
  * @brief This function pushes an item onto the stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (itemPtr) pointer to be inserted
  * @retval Status returned while performing this operation
  */
StackStatus PushStack(Stack *stack_obj, void *itemPtr)
{
    StackStatus Status = STACK_NOK;

    if((!stack_obj) || (!itemPtr))
    {
        Status = STACK_NULL_POINTER;
    }
    else
    {
        if(StackIsFull(stack_obj))
        {
            Status = STACK_FULL;
        }
        else
        {
            (stack_obj->ElementCount)++;
            (stack_obj->StackTop)++;
            stack_obj->StackArray[stack_obj->StackTop] = itemPtr;
            Status = STACK_OK;
        }
    }

    return Status;
}

/**
  * @brief This function pops the item on the top of the stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (ret_status) Status returned while performing this operation
  * @retval Pointer to user data if successful, NULL if underflow
  */
void *PopStack(Stack *stack_obj, StackStatus *ret_status)
{
    void *RetPtr = NULL;

    if((!stack_obj) || (!ret_status))
    {
        *ret_status = STACK_NULL_POINTER;
        RetPtr = NULL;
    }
    else
    {
        if(StackIsEmpty(stack_obj))
        {
            *ret_status = STACK_EMPTY;
            RetPtr = NULL;
        }
        else
        {
            *ret_status = STACK_OK;
            RetPtr = stack_obj->StackArray[stack_obj->StackTop];
            (stack_obj->ElementCount)--;
            (stack_obj->StackTop)--;
        }
    }

    return RetPtr;
}

/**
  * @brief  This function retrieves the data from the top of the
            stack without changing the stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (ret_status) Status returned while performing this operation
  * @retval Pointer to user data if successful, NULL if underflow
  */
void *StackTop(Stack *stack_obj, StackStatus *ret_status)
{
    void *RetPtr = NULL;

    if((!stack_obj) || (!ret_status))
    {
        *ret_status = STACK_NULL_POINTER;
        RetPtr = NULL;
    }
    else
    {
        if(StackIsEmpty(stack_obj))
        {
            *ret_status = STACK_EMPTY;
            RetPtr = NULL;
        }
        else
        {
            *ret_status = STACK_OK;
            RetPtr = stack_obj->StackArray[stack_obj->StackTop];
        }
    }

    return RetPtr;
}

/**
  * @brief  Returns number of elements in stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (stack_count) number of elements in stack.
  * @retval Status returned while performing this operation
  */
StackStatus StackCount(Stack *stack_obj, uint32 *stack_count)
{
    StackStatus Status = STACK_NOK;

    if((!stack_obj) || (!stack_count))
    {
        Status = STACK_NULL_POINTER;
    }
    else
    {
        *stack_count = stack_obj->ElementCount;
        Status = STACK_OK;
    }

    return Status;
}

/**
  * @brief  Function to check is the stack full or not
  * @param  (stack_obj) pointer to stack head structure
  * @retval Status returned while performing this operation
  */
static uint8 StackIsEmpty(Stack *stack_obj)
{
    return (stack_obj->ElementCount == 0);
}

/**
  * @brief  Function to check is the stack empty or not
  * @param  (stack_obj) pointer to stack head structure
  * @retval Status returned while performing this operation
  */
static uint8 StackIsFull(Stack *stack_obj)
{
    return (stack_obj->ElementCount == stack_obj->StackMaxSize);
}
