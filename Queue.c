/*Author:Yomna Ragab*/
#include "std_types.h"
#include "Queue_config.h"
#include "Queue.h"
#include "Queue_priv.h"
#include <stdio.h>
u16 queues[QUEUES_NUM][Q_SIZE]={{0}}; /*Our queus*/
strtQ_Info Arr_Info[QUEUES_NUM]; /*queues info*/
void Q_Init (void)
{
  /*initialize all the heads and tales of queues with -1*/
  u8 i=0;
  for (i=0; i<QUEUES_NUM; i++)
  {
    Arr_Info[i].head=-1;
    Arr_Info[i].tale=-1;
  }
}
enumCheck Q_IsEmpty(u16 queue_num)
{
  /*it will be empty in the case that , the head and the tale on the top of the queue
    which means head=tale=-1
  */
  return((Arr_Info[queue_num].head==Arr_Info[queue_num].tale)&&(Arr_Info[queue_num].tale==-1));
}
enumCheck Q_IsFull(u16 queue_num)
{
  /*it will be full in 2 cases , 1) if the head=tale and not in the top of the queue !=-1
                                2) if the tale in the end of the queue , and the head still in the
                                top of the queue , there were only enqueued operations.
  */
  return((Arr_Info[queue_num].head==Arr_Info[queue_num].tale)&&(Arr_Info[queue_num].tale!=-1)
      ||((Arr_Info[queue_num].tale==Q_SIZE-1)&&(Arr_Info[queue_num].head==-1)));
}
enumOperationStatus enQueue(u16 queue_num,u16 value)
{
  enumOperationStatus status;
    if (!Q_IsFull(queue_num)) //if it's not full
    {
      /*to reset the tale from the start if it reaches to the end*/
      Arr_Info[queue_num].tale=(Arr_Info[queue_num].tale+1)%Q_SIZE;
      queues[queue_num][Arr_Info[queue_num].tale]=value;
      status=done;
    }
    else //Q is full
    {
      status=full;
    }
    return(status);
}
enumOperationStatus deQueue(u16 queue_num, u16 * getter)
{
    enumOperationStatus status;
    if(!Q_IsEmpty(queue_num)) //if it's not Q_IsEmpty
    {
      Arr_Info[queue_num].head = (Arr_Info[queue_num].head+1)%Q_SIZE;
      *getter=queues[queue_num][Arr_Info[queue_num].head];
      status=done;
      if(Arr_Info[queue_num].head==Arr_Info[queue_num].tale) // queue is empty now
      {
        /*then restart the head and the tale */
        Arr_Info[queue_num].head=-1;
        Arr_Info[queue_num].tale=-1;
      }
    }
    else /*Q is empty*/
    {
      status=empty;
      *getter='\0';
    }
    return(status);
}
void Q_printing(u16 queue_num)
{
  u16 i=0;
  for (i=0; i<Q_SIZE; i++)
  {
    printf("%d\n",queues[queue_num][i]);
  }
}
/***************************Test*******************/

void main(void)
{
  Q_Init();

  if (enQueue(0,5)==done){/*do nothing*/};
  enQueue(0,3);
  enQueue(0,7);
  enQueue(0,10);
  enQueue(0,1);
  //Q_printing(0);
  u16 x=0;
  deQueue(0, &x);
  enQueue(0,444);
  enQueue(0,333); // it won''t be added
  //printf("%d\n",x);
  Q_printing(0);

}
