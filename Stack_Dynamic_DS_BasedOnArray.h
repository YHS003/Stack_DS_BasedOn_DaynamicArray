#ifndef _STACK_DYNAMIC_DS_BASEDONARRAY_H

#include "Std_Types_Stack_Dynamic_DS.h"

typedef struct
{
    void **StackArray;    /* Points to the array that allocated in the heap */
    sint32 ElementCount;  /* Has the actual number of elements in the stack */
    uint32 StackMaxSize;  /* Has the maximum number of elements in the stack */
    sint32 StackTop;      /* Has the index of the top element in the stack */
} Stack;

/**
  * @brief  This algorithm creates an empty stack by allocating the head
            structure and the array from dynamic memory.
  * @param  (maxSize) Stack maximum number of elements
  * @param  (ret_status) Status returned while performing this operation
  * @retval Pointer to the allocated stack in the heap
  */
Stack *CreateStack(uint32 maxSize, StackStatus *ret_status);

/**
  * @brief  This function releases all memory to the heap.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (ret_status) Status returned while performing this operation
  * @retval NULL
  */
Stack *DestroyStack(Stack *stack_obj, StackStatus *ret_status);

/**
  * @brief This function pushes an item onto the stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (itemPtr) pointer to be inserted
  * @retval Status returned while performing this operation
  */
StackStatus PushStack(Stack *stack_obj, void *itemPtr);

/**
  * @brief This function pops the item on the top of the stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (ret_status) Status returned while performing this operation
  * @retval Pointer to user data if successful, NULL if underflow
  */
void *PopStack(Stack *stack_obj, StackStatus *ret_status);

/**
  * @brief  This function retrieves the data from the top of the
            stack without changing the stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (ret_status) Status returned while performing this operation
  * @retval Pointer to user data if successful, NULL if underflow
  */
void *StackTop(Stack *stack_obj, StackStatus *ret_status);

/**
  * @brief  Returns number of elements in stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (stack_count) number of elements in stack.
  * @retval Status returned while performing this operation
  */
StackStatus StackCount(Stack *stack_obj, uint32 *stack_count);

#endif // _STACK_DYNAMIC_DS_BASEDONARRAY_H
