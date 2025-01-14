//
// Created by Marina on 30/11/19.
//
#include <stdio.h>
#include <stdlib.h>
#include "flight.h"
struct flight {
    int f_Num;
    FlightType  f_type;
    char dest[4]; // TODO: Add define
    BOOL emergency;
};
pFlight createFlight(int f_Num , FlightType f_type, char dest[4], BOOL emergency ){
    pFlight f;
    if (f_Num<1 || f_Num>MAX_ID)     //TODO: add additional parameters check
        return NULL;
    f=(pFlight)malloc(sizeof(struct flight));
    if(f == NULL)
        return NULL;
    f->f_Num = f_Num;
    f->f_type = f_type;
    strcpy((char *) f->dest, dest);
    f->emergency = emergency;
    return f;
}

void destroyFlight(pFlight f){
    if(f == NULL)
        return;
    //free(f->dest);
    free(f);
}

void printFlight(pFlight f){
    if(f == NULL)
        return;
    printf("Flight %d %c %s %c\n", f->f_Num, (f->f_type == DOMESTIC ? 'D' : 'I'), f->dest, (f->emergency ? 'E' : 'R'));
}
int getFlightID(pFlight f){
    return f->f_Num;
}
FlightType getFlightType(pFlight f){
    return f->f_type;
}
BOOL isEmergency(pFlight f){
    return f->emergency;
}
char* getDestination(pFlight f){
    return f->dest;//TODO: use strcpy
}//TODO: Check if all the fields are correctly defined
Result setDestination(pFlight f, char new_dest[4]){
    if(!f){
        return FAILURE;
    }
    for (int i; i<3; i++){
        if ( new_dest[i]<65 || new_dest[i]>90){
            return FAILURE;
        }
    }
    strcpy(f->dest,new_dest);
    return SUCCESS;
}
