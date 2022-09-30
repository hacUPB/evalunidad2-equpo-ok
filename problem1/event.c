#include "event.h"
#include <string.h>
#include <stdlib.h>

Event *CreateEvent(char *name)
{   
    char i[15];
    Event *nombre= malloc(sizeof(Event));
    strncpy(nombre->eventName,name,sizeof(i));
    nombre->next=NULL;
    return nombre;
    


}

void DestroyEvent(Event *this)
{
    free(this);
}