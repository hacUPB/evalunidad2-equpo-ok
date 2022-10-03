#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


EventList *CreateEventList(void)
{
    
EventList *ListaEvento=malloc(sizeof(EventList));
ListaEvento->head=NULL;
ListaEvento->last=NULL;
ListaEvento->isEmpty=1;
return ListaEvento;

}

void DestroyEventList(EventList *this)
{
    Event *aux;

    while (this->head != NULL)
    {
        aux= this->head;
        this->head = this->head->next;
        free(aux);
    }
    free(this);
}

Event *SearchEvent(EventList *this, char *name)
{
    
    if (this->isEmpty!=1)
    {Event *aux,*ult;
    
    aux=this->head;
    ult=NULL;
        while (1)
        {
            if(aux==NULL){
            break;
        }
        int i = strcmp(aux->eventName,name);
            if (!i){
       
                ult=aux;
                break;
         }
         aux=aux->next;
        }
        
        return ult;
            
       }        
      
    
    
    else{
        return NULL;
    }

    

}

void AddEvent(EventList *this, Event *event)
{   
    int prueba = 0;
    if (this->isEmpty != 1)
    {
        Event *aux;
        aux= this->head;

         while (1)
        {
            if (aux == NULL)
            {
                break;
            }

            int i = strcmp(aux->eventName,event->eventName);
            if (!i)
            
            {
                prueba = 1;
                break;
            }

            aux =aux->next;
        
        }
    }
    
    
    if (prueba!=1)
    {
         if (this->isEmpty == 1)
        {
        this->head = event;
        this->isEmpty = 2;
        } else if(this->isEmpty == 2)
        {
            this->head->next = event;
            this->last = event;
            this->isEmpty = 3;
        }else
        {
            this->last->next = event;
            this->last = event;
        }
    }    

}

void RemoveEvent(EventList *this, char *name)
{
     Event *aux,*eli,*ant;
    
    aux=this->head;
    eli=NULL;
    ant=NULL;

        while (1)
        {
            if(aux==NULL){
            break;
        }
        int i = strcmp(aux->eventName,name);

        if (!i){
       
                eli=aux;
                break;
         }
         ant=aux;
         aux=aux->next;
         
        }
        
    
    if(eli!=NULL){
        if(eli==this->head){
            if(this->head->next== NULL){
                this->isEmpty=1;
                this->head=NULL;
                DestroyEvent(eli);
            }
            else{
                this->head=this->head->next;
                DestroyEvent(eli);
            }
        }
        else{
            ant->next=aux->next;
            DestroyEvent(eli);
        }

    }
 }       

void ListEvents(EventList *this)
{
    Event *aux;
    aux=this->head;
    if(this->isEmpty == 1){
        printf("empty\n");
    }
    else{
        while(1){
            if(aux==NULL){
                break;
            }
            printf("%s\n",aux->eventName);
            aux=aux->next;
        }
        
    }
}
