/**
 * @author Ajay G.
 * @copyright Ajay G. - Code Stack 2020
 * @desc This code can not be used for commercial purpose. 
 *       Can be used for educational, learning and any personal usage.
 */

/*  title: QueueUtils.h
    - _Author_      : *AJAY G.*
    - _Copyright_   : *AJAY G. - Code Stack 2020*        
	.
	 
*/

/*  Defines: Boolean Values

	TRUE   - Used for true. 
	FALSE  - Used for false.
*/
#define TRUE 1
#define FALSE 0

/*  Defines: Message Strings
   
	QUEUE_EMPTY_ERROR          - Message for empty queue error.
	QUEUE_NOT_AVAILABLE_ERROR  - Message for queue not created error.
	QUEUE_EMPTY_INFO           - Queue empty info message.
	QUEUE_ELEMENTS_MSG         - Queue elements message.
	QUEUE_CLEARED_INFO         - Queue deleted info message.
	QUEUE_DELETED_INFO         - Queue cleared info message.
*/
#define QUEUE_EMPTY_ERROR "\n [ERROR] : Queue is Empty.\n"
#define QUEUE_NOT_AVAILABLE_ERROR "\n [ERROR] : Given Queue is NOT Available\n\t   Create Queue Before Using it.\n"
#define QUEUE_EMPTY_INFO "\n [INFO] : Queue is Empty.\n"
#define QUEUE_ELEMENTS_MSG "\n [INFO] : Queue elements are : "
#define QUEUE_CLEARED_INFO "\n [INFO] : Queue cleared successfully.\n"
#define QUEUE_DELETED_INFO "\n [INFO] : Queue deleted successfully.\n"
