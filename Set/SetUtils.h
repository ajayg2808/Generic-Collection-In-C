/**
 * @author Ajay G.
 * @copyright Ajay G. - Code Stack 2020
 * @desc This code can not be used for commercial purpose. 
 *       Can be used for educational, academic projects, learning and any personal usage.
 */

/*  title: SetUtils.h
    + _Author_      : *AJAY G.*
    + _Copyright_   : *AJAY G. - Code Stack 2020*
	.
		
*/
#ifndef AVL_TREE_H
#define AVL_TREE_H "../Tree/AVL_Tree.h"
#include AVL_TREE_H
#endif

/*  Defines: Boolean Values

    TRUE   - Used for true. 
    FALSE  - Used for false.
*/
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

/*  Defines: Message Strings
    
    CREATE_SET_ERROR_MSG                - Error message if *<Set>* not created/ *<Set>* pointer is not correct.
    SET_CLEARED_INFO_MSG                - Info message for *<Set>* clear succeed.
    SET_DELETED_INFO_MSG                - Info message for *<Set>* deletion succeed.
    SET_DEFAULT_COMPARE_FUN_WARN_MSG    - Warn message for default <intCompare()> function use.
    SET_DEFAULT_PRINT_FUN_WARN_MSG      - Warn message for default <intPrint()> function use.
*/
#define CREATE_SET_ERROR_MSG "\n [ERROR] : Create Set before using it.\n"
#define SET_CLEARED_INFO_MSG "\n [INFO] : Set cleared successfully.\n"
#define SET_DELETED_INFO_MSG "\n [INFO] : Set deleted successfully.\n"
#define SET_DEFAULT_COMPARE_FUN_WARN_MSG "\n [WARN] : Using default intCompare() function.\n"
#define SET_DEFAULT_PRINT_FUN_WARN_MSG "\n [WARN] : Using default intPrint() function.\n"

/*  typedef: int

    u_int    - unsigned int
    
*/
typedef unsigned int u_int;

/*  Struct: Set
    *<Set>* structure to hold link to set elements. *AVL Tree* used for efficiency.

    --- Code ---
    typedef struct Set
	{
        BinaryTreeNode *root;

	} Set;
    ---
*/
typedef struct Set
{
    // Var: BinaryTreeNode *root
    // Hold *root* pointer to *Binary Tree-(AVL Tree)*
    BinaryTreeNode *root;

} Set;
