#ifndef Queue
#define Queue

typedef enum{
  False=0,
  True=1
}enumCheck;
/*Enum type to check the errors through functions retrun*/
typedef enum{
  full=0,
  empty=1,
  done=2
}enumOperationStatus;
/*Enum type to check the status of each process on the queue whether enqueue or dequeue*/
void Q_Init(void);
/*
  Func name:Q_init , it has to ba called at the begining of the programme to initiate all the queues
  Parameters:None.
  Return:None.
*/
enumCheck Q_IsEmpty(u16 queue_num);
/*
  Func name:Q_IsEmpty , to check if the queue is empty or not , by giving it the queue number.
  Parameters: it takes unsigned 16-bit number , which refer to queue arrangement.
  retrun: it return enumCheck , there is 2 possible cases:
                                1) return false which means it's not empty.
                                2) return true which means it's empty.
*/
enumCheck Q_IsFull(u16 queue_num);
/*
  Func name:Q_IsFull , to check if the queue is full or not , by giving it the queue number.
  Parameters: it takes unsigned 16-bit number , which refer to queue arrangement.
  retrun: it return enumCheck , there is 2 possible cases:
                                1) return false which means it's not full.
                                2) return true which means it's full.
*/
enumOperationStatus enQueue(u16 queue_num,u16 value);
/*
  Func name:enQueue , to add a certain value in the end of certain queue
            , by giving it the queue number and the value.
  Parameters: it takes:
              1) queue_num: unsigned 16-bit number , which refer to queue arrangement.
              2) value: unsigned 16-bit number , which refer to the value wanted to be added.

  retrun: it return enumOperationStatus , there is 2 possible cases:
                                          1) return done which means the value is enqueued successfully.
                                          2) return full which means it's full, the value can't be enqueued.
*/
enumOperationStatus deQueue(u16 queue_num,u16 * getter);
/*
  Func name:deQueue , to get the first value from the certain queue .
                  , by giving it the queue number and getter to put the value on it.
  Parameters: it takes:
              1) queue_num: unsigned 16-bit number , which refer to queue arrangement.
              2) getter: pointer to unsigned 16-bit number , to get the value in it.
  retrun: it return enumOperationStatus , there is 2 possible cases:
                                          1) return done which means the value is dequeued successfully.
                                          2) return enpty which means it's empty,There is no values to be dequeued.
*/
void Q_printing(u16 queue_num);
/*
  Func name:Q_printing , it prints all the values which are in the certain queue.
  Parameters: it takes: queue_num: unsigned 16-bit number , which refer to queue arrangement.
  retrun:None.
*/
#endif
