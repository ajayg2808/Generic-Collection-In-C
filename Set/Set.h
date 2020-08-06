/**
 * @author Ajay G.
 * @copyright Ajay G. - Code Stack 2020
 * @desc This code can not be used for commercial purpose. 
 *       Can be used for educational, academic projects, learning and any personal usage.
 */
/*  title: Set.h
    + _Author_      : *AJAY G.*
    + _Copyright_   : *AJAY G. - Code Stack 2020*
    
    
    About:
        *_1. Poiners_* 
        
            In *<Set>* all pointers are used which should have memory allocated by *malloc()/calloc()/realloc()* functions.
        
            It is useful for _dynamic memory management_.
    
        *_2. compare()_* 

            Used to compare data pointed by data pointer in *Set <BinaryTreeNode>*.

            *Prototype*
            --- Code ---
            int compare(const void * var1, const void * var2);
        
            if var1.value > var1.value
                return value should be > 0
        
            if var1.value < var1.value 
                return value should be < 0
        
            if var1.value == var1.value 
                return value should be 0
            ---

        *_3. print()_* 

            Used to print data pointed by data pointer in <Set.root>.

            *Prototype*
            --- Code ---
            void print(const void * dataPtr);
            ---	
*/
#include <SetUtils.h>

#ifndef AVL_TREE_H
#define AVL_TREE_H "../Tree/AVL_Tree.h"
#include AVL_TREE_H
#endif

#ifndef STDIO_H
#define STDIO_H <stdio.h>
#include STDIO_H
#endif

#ifndef STDLIB_H
#define STDLIB_H <stdlib.h>
#include STDLIB_H
#endif

Set *add(Set *set, void *dataPtr, int (*compare)(const void *, const void *));

/*  Function: intCompare()
    Default compare function for integer data.
    
    Parameters:
        const void *num1    - Pointer to 1st integer number.
        const void *num2    - Pointer to 2nd integer number.
	 
    Returns:
        int                 - Result of integer comparison.
                              Return > 0 if num1 > num2,
                              Return < 0 if num1 < num2,
                              Return 0 if num1 = num2. 
    
    See Also:
        <intPrint()>

*/
int intCompare(const void *num1, const void *num2)
{
    int *intNum1 = (int *)num1;
    int *intNum2 = (int *)num2;
    return (*intNum1) - (*intNum2);
}

/*  Function: intPrint()
    Default print function for integer data.
    
    Parameters:
        const void *ptr    - Pointer to integer number.
    
    See Also:
        <intCompare()>
	 
*/
void intPrint(const void *ptr)
{
	int *intPtr = (int *)ptr;
	printf("%d ", *intPtr);
}

/*  Function: createEmptySet()
    Create empty set.
    
    Returns:
        Set *          - Return pointer to *Empty Set*.

    See Also:
        <createSet()>

*/
Set *createEmptySet()
{
    Set *set = (Set *)malloc(sizeof(Set));
    set->root = NULL;
    return set;
}

/*  Function: createSet()
    Create set with provided data pointer array.
    
    Parameters:
        void *array[]                               - Array of pointer to data. All data pointer will be added in newly created *<Set>*. 
        const u_int size                             - Size of input array.
        int (*compare)(const void *, const void *)  - Compare function to compare data hold by dataPtr.
                                                      If not provided/ *NULL* is provided then default <intCompare()> function is used.
		--- Code ---
		int compare(const void *, const void *);
		--- 
	 
    Returns:
        Set *                                       - Return pointer to *<Set>*.

    See Also:
        <add()>

*/
Set *createSet(void *array[], const u_int size, int (*compare)(const void *, const void *))
{
    int i;
    Set *set = createEmptySet();
    if (compare == NULL)
    {
        compare = &intCompare;
        printf(SET_DEFAULT_COMPARE_FUN_WARN_MSG);
    }
    for (i = 0; i < size; i++)
    {
        set = add(set, array[i], compare);
    }

    return set;
}

/*  Function: add()
    Add given element in *<Set>*.
    
    Parameters:
        Set *set                                    - Pointer to *<Set>*. 
        void *dataPtr                               - Pointer to data to be be added in *<Set>*.
        int (*compare)(const void *, const void *)  - Compare function to compare data hold by dataPtr.
                                                      If not provided/ *NULL* is provided then default <intCompare()> function is used.
		--- Code ---
		int compare(const void *, const void *);
		--- 
	 
    Returns:
        Set *                                       - Return pointer to *<Set>*.

    See Also:
        <addAll()>

*/
Set *add(Set *set, void *dataPtr, int (*compare)(const void *, const void *))
{
    if (set == NULL)
    {
        printf(CREATE_SET_ERROR_MSG);
        return NULL;
    }
    if (compare == NULL)
    {
        compare = &intCompare;
        printf(SET_DEFAULT_COMPARE_FUN_WARN_MSG);
    }
    if (!searchNodeBST(set->root, dataPtr, compare))
    {
        set->root = insertNode(set->root, dataPtr, compare);
    }

    return set;
}

/*  Function: addAll()
    Add all given element to *<Set>*.
    
    Parameters:
        Set *set                                    - Pointer to *<Set>*. 
        void *array[]                               - Array of pointer to data. All data pointers would be added in newly created *<Set>*. 
        const u_int size                           - Size of input array.
        int (*compare)(const void *, const void *)  - Compare function to compare data hold by dataPtr.
                                                      If not provided/ *NULL* is provided then default <intCompare()> function is used.
		--- Code ---
		int compare(const void *, const void *);
		--- 
	 
    Returns:
        Set *                                       - Return pointer to *<Set>*.

    See Also:
        <clear()>

*/
Set *addAll(Set *set, void *array[], const u_int size, int (*compare)(const void *, const void *))
{
    int i;
    if (set == NULL)
    {
        printf(CREATE_SET_ERROR_MSG);
        return NULL;
    }
    if (compare == NULL)
    {
        compare = &intCompare;
        printf(SET_DEFAULT_COMPARE_FUN_WARN_MSG);
    }
    for (i = 0; i < size; i++)
    {
        set = add(set, array[i], compare);
    }

    return set;
}

/*  Function: clear()
    Clear the *<Set>* (Make Set Empty).
    Deletes only elements from set.
    
    Parameters:
        Set *set                                    - Pointer to *<Set>*. 
        
    See Also:
        <deleteSet()>

*/
void clear(Set *set)
{
    if (set == NULL)
    {
        printf(CREATE_SET_ERROR_MSG);
        return;
    }
    deleteTree(set->root);
    set->root = NULL;
    printf(SET_CLEARED_INFO_MSG);
}

/*  Function: deleteSet()
    Delete *<Set>* along with elements in it.
    
    Parameters:
        Set *set                                    - Pointer to *<Set>*. 
	 
    Returns:
        Set *                                       - Return pointer to *<Set>*. Return *NULL* pointer.

    See Also:
        <contains()>

*/
Set *deleteSet(Set *set)
{
    if (set == NULL)
    {
        printf(CREATE_SET_ERROR_MSG);
        return NULL;
    }
    clear(set);
    free(set);
    set = NULL;
    printf(SET_DELETED_INFO_MSG);
    return set;
}

/*  Function: contains()
    Check *<Set>* contains given element OR not.
    
    Parameters:
        Set *set                                    - Pointer to *<Set>*. 
        void *dataPtr                               - Pointer to data to be be searched in *<Set>*.
        int (*compare)(const void *, const void *)  - Compare function to compare data hold by dataPtr.
                                                      If not provided/ *NULL* is provided then default <intCompare()> function is used.
		--- Code ---
		int compare(const void *, const void *);
		--- 
	 
    Returns:
        int                                         - *TRUE[1]* if given element present in *<Set>*.
                                                      *FALSE[0]* if element is not present in *<Set>*.
    
    See Also:
        <containsAll()>

*/
int contains(Set *set, void *dataPtr, int (*compare)(const void *, const void *))
{
    if (set == NULL)
    {
        printf(CREATE_SET_ERROR_MSG);
        return FALSE;
    }
    if (compare == NULL)
    {
        compare = &intCompare;
        printf(SET_DEFAULT_COMPARE_FUN_WARN_MSG);
    }
    return searchNodeBST(set->root, dataPtr, compare);
}

/*  Function: containsAll()
    Check *<Set>* contains all given elements OR not.
    
    Parameters:
        Set *set                                    - Pointer to *<Set>*. 
        void *array[]                               - Array of pointer to data. All data pointers would be searched in given *<Set>*. 
        const u_int size                           - Size of input array.
        int (*compare)(const void *, const void *)  - Compare function to compare data hold by dataPtr.
                                                      If not provided/ *NULL* is provided then default <intCompare()> function is used.
		--- Code ---
		int compare(const void *, const void *);
		--- 
	 
    Returns:
        int                                         - *TRUE[1]* if all given elements are present in *<Set>*.
                                                      *FALSE[0]* if any given element not present in *<Set>*.

    See Also:
        <isEmpty()>

*/
int containsAll(Set *set, void *array[], const u_int size, int (*compare)(const void *, const void *))
{
    int i;
    if (set == NULL)
    {
        printf(CREATE_SET_ERROR_MSG);
        return FALSE;
    }
    if (compare == NULL)
    {
        compare = &intCompare;
        printf(SET_DEFAULT_COMPARE_FUN_WARN_MSG);
    }
    for (i = 0; i < size; i++)
    {
        if (!searchNodeBST(set->root, array[i], compare))
            return FALSE;
    }

    return TRUE;
}

/*  Function: isEmpty()
    Check *<Set>* is empty OR not.
    
    Parameters:
        Set *set                                    - Pointer to *<Set>*.
	 
    Returns:
        int                                         - *TRUE[1]* if *<Set>* is empty.
                                                      *FALSE[0]* if *<Set>* is not empty.

    See Also:
        <sRemove()>

*/
int isEmpty(Set *set)
{
    if (set == NULL)
    {
        printf(CREATE_SET_ERROR_MSG);
        return 0;
    }
    if (countTotalNodes(set->root) == 0)
        return TRUE;

    return FALSE;
}

/*  Function: sRemove()
    Remove given element from *<Set>*.
    
    Parameters:
        Set *set                                    - Pointer to *<Set>*. 
        void *dataPtr                               - Pointer to data to be removed from *<Set>*.
        int (*compare)(const void *, const void *)  - Compare function to compare data hold by dataPtr.
                                                      If not provided/ *NULL* is provided then default <intCompare()> function is used.
		--- Code ---
		int compare(const void *, const void *);
		--- 
	 
    Returns:
        Set *                                       - Return pointer to *<Set>*.

    See Also:
        <removeAll()>

*/
Set *sRemove(Set *set, void *dataPtr, int (*compare)(const void *, const void *))
{
    if (set == NULL)
    {
        printf(CREATE_SET_ERROR_MSG);
        return NULL;
    }

    if (compare == NULL)
    {
        compare = &intCompare;
        printf(SET_DEFAULT_COMPARE_FUN_WARN_MSG);
    }

    if (searchNodeBST(set->root, dataPtr, compare))
    {
        set->root = deleteNode(set->root, dataPtr, compare);
    }

    return set;
}

/*  Function: removeAll()
    Remove all given elements from *<Set>*.
    
    Parameters:
        Set *set                                    - Pointer to *<Set>*. 
        void *array[]                               - Array of pointer to data. All pointers to data to be deleted from *<Set>*. 
        const u_int size                           - Size of input array.
        int (*compare)(const void *, const void *)  - Compare function to compare data hold by dataPtr.
                                                      If not provided/ *NULL* is provided then default <intCompare()> function is used.
		--- Code ---
		int compare(const void *, const void *);
		--- 
	 
    Returns:
        Set *                                       - Return pointer to *<Set>*.

    See Also:
        <size()>

*/
Set *removeAll(Set *set, void *array[], const u_int size, int (*compare)(const void *, const void *))
{
    int i;
    if (set == NULL)
    {
        printf(CREATE_SET_ERROR_MSG);
        return NULL;
    }
    if (compare == NULL)
    {
        compare = &intCompare;
        printf(SET_DEFAULT_COMPARE_FUN_WARN_MSG);
    }
    for (i = 0; i < size; i++)
    {
        set->root = deleteNode(set->root, array[i], compare);
    }

    return set;
}

/*  Function: size()
    Return size of given *<Set>*.
    
    Parameters:
        Set *set            - Pointer to *<Set>*. 
        
    Returns:
        int                 - Return size of *<Set>*.
                              Return *-1* if given set not present.

    See Also:
        <setToArray()>

*/
int size(Set *set)
{
    if (set == NULL)
    {
        printf(CREATE_SET_ERROR_MSG);
        return -1;
    }
    return countTotalNodes(set->root);
}

/*  Function: setToArray()
	All Nodes from *<Set>* are copied to given Array.
    
    Parameters:
        Set *set                    - Pointer to *<Set>*. 
		int *array[]				- Array in which all data pointers are copied.
	 
    Returns:
        int                         - Total nodes copied in Array / Index to last element of array.

    See Also:
        <printSet()>

*/
int setToArray(Set *set, int *array[])
{
    if (set == NULL)
    {
        printf(CREATE_SET_ERROR_MSG);
        return -1;
    }
    return treeToArray(set->root, array, 0);
}

/*  Function: printSet()
    Print all *<Set>* elements.
    
    Parameters:
        Set *set                        - Pointer to *<Set>*. 
        void (*print)(const void *)     - Function to print data.
                                          If not provided/ provided *NULL* then default <intPrint()> function is used.
        
*/
void printSet(Set *set, void (*print)(const void *))
{
    if (set == NULL)
    {
        printf(CREATE_SET_ERROR_MSG);
        return;
    }
    if (print == NULL)
    {
        print = &intPrint;
        printf(SET_DEFAULT_PRINT_FUN_WARN_MSG);
    }
    printInOrder(set->root, print);
}