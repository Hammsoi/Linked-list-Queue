#include <stdio.h>
#include <malloc.h>

typedef struct Queue{
    int data;
    struct Queue *next;
}Queue;





int check( Queue *tale){
    if( tale == NULL)
        return 1;

    return 0;
}


void addQ( Queue **head, Queue **tale, int data)
{
    Queue *new_q = (Queue *)malloc(sizeof(Queue));

    

    new_q->data = data;
    new_q->next = NULL;

    if( *tale  == NULL)
    {
        *head = new_q;
        *tale = new_q;

        return;
    }

    
    (*head)->next = new_q;
    *head = new_q;
}


int delQ( Queue **tale)
{
    Queue *tmp = *tale;
    int data;

    if(check(*tale))
    {
        printf("Queue is empty.\n");

        return 0;
    }

    data = tmp->data;

    

    *tale = tmp->next;

    free( tmp);

    return data;
}

void print(Queue *prt){
  int num = 0;
  while(1){
    printf("%d번 -> %d\n",num, prt);   
    if(check(prt) == 1){
      break;
    }
    prt = prt->next;
    num++;
  }
  
}

int main( void)
{
    Queue *head; 
    Queue *tale; 

    
   head = NULL;
   tale= NULL;

   addQ(&head, &tale, 1);
   addQ(&head, &tale, 2);
   addQ(&head, &tale, 3);
   addQ(&head, &tale, 4);
   print(tale);
  printf("--------------\n");
   delQ(&tale);
   delQ(&tale);

   
}
