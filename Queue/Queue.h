/**
 * @author Ajay G.
 * @copyright Ajay G. - Code Stack 2020
 * @desc This code can not be used for commercial purpose. 
 *       Can be used for educational, learning and any personal usage.
 */
/*  title: Queue.h
    + _Author_      : *AJAY G.*
    + _Copyright_   : *AJAY G. - Code Stack 2020*
    
    
    About:
        *_1. Poiners_* 
        
            In *Queue* all pointers are used which should have memory allocated by *malloc()/calloc()/realloc() functions.
        
            It is useful for _dynamic memory management_.
    
        *_2. print()_* 

            Used to print data pointed by data pointer in <QueueNode>.

            *Prototype*
            --- Code ---
            void print(const void * dataPtr);
            ---
*/
#include "QueueUtils.h"

#ifndef QUEUE_STRUCT_NODES
#define QUEUE_STRUCT_NODES "QueueStructNodes.h"
#include QUEUE_STRUCT_NODES
#endif

#ifndef STDIO_H
#define STDIO_H <stdio.h>
#include STDIO_H
#endif

#ifndef STDLIB_H
#define STDLIB_H <stdlib.h>
#include STDLIB_H
#endif

int isQueue(Queue *queue);
int isEmpty(Queue *queue);
/*  Function: createEmptyQueue()
    Create empty Queue. i.e. *'rear'* and *'front'* is *NULL*.
    Memory is only alocated for Queue [Holds *rear* and *front* pointers].
    
    Returns:
        Queue *     - Pointer to allocated memory for *Queue*.

    See Also:
        <enQueue>

*/
Queue *createEmptyQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

/*  Function: createQueueNode()
    Allocates memory for new QueueNode and stores data pointer in it.
    
    Parameters:
        void *dataPtr   - Pointer to data [Pointer to memory allocated by *malloc()/calloc()/realloc()*]

    Returns:
        QueueNode *     - Pointer to allocated memory for *QueueNode* and assign *dataPtr* to it.

    See Also:
        <createEmptyQueue>

*/
QueueNode *createQueueNode(void *dataPtr)
{
    QueueNode *queueNode = (QueueNode *)malloc(sizeof(QueueNode));
    queueNode->dataPtr = dataPtr;
    queueNode->next = NULL;
    return queueNode;
}

/*  Function: enQueue()
    Insert new *QueueNode* with _data pointer_ in a *Queue*.
    Insertion is done at *rear* of *Queue*.
    
    Parameters:
        Queue *queue    - Pointer to Queue.
        void *dataPtr   - Pointer to Data.

    See Also:
        <deQueue>

*/
void enQueue(Queue *queue, void *dataPtr)
{
    if (!isQueue(queue))
    {
        printf(QUEUE_NOT_AVAILABLE_ERROR);
        return;
    }
    if (queue->rear == NULL || queue->front == NULL)
    {
        queue->front = queue->rear = createQueueNode(dataPtr);
    }
    else
    {
        queue->rear->next = createQueueNode(dataPtr);
        queue->rear = queue->rear->next;
    }
}

/*  Function: deQueue()
    Delete *QueueNode* from *Queue*.
    Deletion is done at *front* of *Queue*.
    
    Parameters:
        Queue *queue    - Pointer to Queue.
        
    Returns:
        void *dataPtr   - Pointer to Data.

    See Also:
        <peek>

*/
void *deQueue(Queue *queue)
{
    if (!isQueue(queue))
    {
        printf(QUEUE_NOT_AVAILABLE_ERROR);
        return NULL;
    }
    if (queue->rear == NULL || queue->front == NULL)
    {
        printf(QUEUE_EMPTY_ERROR);
        queue->rear = queue->front = NULL;
        return NULL;
    }
    else
    {
        QueueNode *temp = queue->front;
        if (queue->rear == queue->front)
        {
            queue->rear = queue->front = NULL;
        }
        else
        {
            queue->front = temp->next;
        }
        void *dataPtr = temp->dataPtr;
        free(temp);
        return dataPtr;
    }
}

/*  Function: peek()
    Get *QueueNode* from *Queue* pointed by *front* pointer.
    
    Parameters:
        Queue *queue    - Pointer to Queue.
        
    Returns:
        void *dataPtr   - Pointer to Data.

    See Also:
        <deQueue>

*/
void *peek(Queue *queue)
{
    if (!isQueue(queue))
    {
        printf(QUEUE_NOT_AVAILABLE_ERROR);
        return NULL;
    }
    if (isEmpty(queue))
    {
        printf(QUEUE_EMPTY_ERROR);
        return NULL;
    }
    else
    {
        return queue->front->dataPtr;
    }
}

/*  Function: isQueue()
    Used to check queue is created or not.
    Checks whether given pointer of *Queue* has memory allocated for it or not.
    Checks for NULL pointer in case queue is not created.
    
    Parameters:
        Queue *queue    - Pointer to Queue.

    Returns:
        int             - Return *TRUE[1]* if memory is allocated for *Queue* and pointer to *Queue* is not *NULL*.
                          Otherwise Return *FALSE[0]*.
    
    See Also:
        <isEmpty>

*/
int isQueue(Queue *queue)
{
    if (queue == NULL)
        return FALSE;
    return TRUE;
}

/*  Function: isEmpty()
    Used to check queue is empty or not.
    
    Parameters:
        Queue *queue    - Pointer to Queue.

    Returns:
        int             - Return *TRUE[1]* if *Queue* is empty i.e. *front* and *raer* are *NULL*.
                          Otherwise Return *FALSE[0]*.
    
    See Also:
        <isQueue>

*/
int isEmpty(Queue *queue)
{
    if (!isQueue(queue))
    {
        printf(QUEUE_NOT_AVAILABLE_ERROR);
        return TRUE;
    }
    if (queue->front == NULL || queue->rear == NULL)
    {
        return TRUE;
    }
    return FALSE;
}

/*  Function: printQueue()
    Prints all data element values from *Queue* using provided *void print(const void *dataPtr)* function.
    
    Parameters:
        Queue *queue                        - Pointer to Queue.
        void (*print)(const void *dataPtr)  - Function to print data.
        
    See Also:
        <enQueue>
*/
void printQueue(Queue *queue, void (*print)(const void *dataPtr))
{
    if (!isQueue(queue))
    {
        printf(QUEUE_NOT_AVAILABLE_ERROR);
        return;
    }

    if (isEmpty(queue))
    {
        printf(QUEUE_EMPTY_INFO);
        return;
    }
    printf(QUEUE_ELEMENTS_MSG);
    QueueNode *temp = queue->front;
    while (temp != NULL)
    {
        (*print)(temp->dataPtr);
        temp = temp->next;
    }
    printf("\n");
}

/*  Function: clearQueue()
    Remove all the elements from *Queue*, but do not remove *Queue* pointer which holds *QueueNode* pointers. 
    
    Parameters:
        Queue *queue         - Pointer to Queue.
        
    See Also:
        <deleteQueue>
*/
void clearQueue(Queue *queue)
{
    if (!isQueue(queue))
    {
        printf(QUEUE_NOT_AVAILABLE_ERROR);
        return;
    }

    if (isEmpty(queue))
    {
        printf(QUEUE_EMPTY_INFO);
        queue->front = queue->rear = NULL;
    }
    else
    {
        QueueNode *temp = queue->front, *p;
        while (temp != NULL)
        {
            void *data = (void *)temp->dataPtr;
            p = temp;
            temp = temp->next;
            free(data);
            free(p);
        }

        queue->front = queue->rear = NULL;
        printf(QUEUE_CLEARED_INFO);
    }
}

/*  Function: deleteQueue()
    Remove all the elements from *Queue*, and also remove *Queue* pointer which holds *QueueNode* pointers. 
    
    Parameters:
        Queue *queue        - Pointer to Queue.
        
    Returns:
        Queue *queue        - NULL pointer as previous pointer is deleted.
    
    See Also:   
        <clearQueue>
*/
Queue *deleteQueue(Queue *queue)
{
    if (!isQueue(queue))
    {
        printf(QUEUE_NOT_AVAILABLE_ERROR);
        return;
    }

    clearQueue(queue);

    free(queue);
    queue = NULL;
    printf(QUEUE_DELETED_INFO);
    return queue;
}
