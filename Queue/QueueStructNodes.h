/**
 * @author Ajay G.
 * @copyright Ajay G. - Code Stack 2020
 * @desc This code can not be used for commercial purpose. 
 *       Can be used for educational, academic projects, learning and any personal usage.
 */

/*  title: QueueStructNodes.h
    - _Author_      : *AJAY G.*
    - _Copyright_   : *AJAY G. - Code Stack 2020* 
    .
	 
*/

/* Struct: QueueNode
    
    Struct Type used to achieve implementation of Queue.

    --- Code ---
    typedef struct QueueNode
    {
        void *dataPtr;
        struct QueueNode *next;

    } QueueNode;
    ---
 */

typedef struct QueueNode
{
    // var: void* dataPtr
    // Holds pointer to data.
    void *dataPtr;
    // var: struct QueueNode *next
    // Holds pointer to next QueueNode.
    struct QueueNode *next;
} QueueNode;

 /* Struct: Queue
    Handle Queue Structure using the *'front'* and *'rear'* pointers
    *'front'* and *'rear'* holds pointers to queue implementation.

    --- Code ---
    typedef struct Queue
    {
        QueueNode *front;
        QueueNode *rear;
        
    } Queue;
    ---
 */
typedef struct Queue
{
    // Var: QueueNode *front
    // Hold *front* pointer to Queue
    QueueNode *front;
    // Var: QueueNode *rear
    // Hold *rear* pointer to Queue
    QueueNode *rear;
} Queue;
