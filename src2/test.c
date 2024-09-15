/*
 * Written by @asofcs
 * Copyright 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXSIZE 100
#define ERRORINT -1
#define ERRORPTR NULL


typedef struct{
    char *itemName;
    int quantity;
    float price;
    float amount; // price* quantity
}item;


void readItem(item *elem); //read values for all elements in an item
void printItem(item* elem);//print all elements in an item
void resetValues(item* elem);// reset all elements in an item


int main(void)
{
    item initValues = {ERRORPTR, ERRORINT, ERRORINT, ERRORINT};
    item *ptr = &initValues;
    
    readItem(ptr);
    printItem(ptr);
    resetValues(ptr);
    
    return 0;
}

/*
 * Read values for all elements in an item
 */
void readItem(item *elem)
{
    if(elem->itemName == ERRORPTR)
    {
        elem->itemName = (char*)calloc(MAXSIZE, sizeof(char));
        
        if(elem->itemName == ERRORPTR)
        {
            printf("\n\tMEMORY NOT ALLOCATED!\n");
            exit(1);
        }
        else
        {
            printf(" \nPlease enter the name of the item (MAXSIZE: %d):\n", MAXSIZE-1);
            fgets(elem->itemName, MAXSIZE, stdin);
            elem->itemName[strcspn(elem->itemName, "\n")] = 0;
        }
    }
    
    if (elem->quantity == ERRORINT)
    {
        printf(" \nPlease enter the quantity of the item:\n");
        scanf("%d", &elem->quantity);
    }
    
    if (elem->price == ERRORINT)
    {
        printf(" \nPlease enter the price of the item:\n");
        scanf("%f", &elem->price);
    }
    
    if ((elem->price >= 0) && (elem->quantity >= 0))
    {
        elem->amount = elem->price*elem->quantity;
    }
}

/*
 * Print all elements in an item
 */
void printItem(item* elem)
{
    
    if ((elem->itemName != NULL) && (strlen(elem->itemName) > 0))
    {
        printf(" \n Name: %s \n",elem->itemName); 
    }
    else
    {
        printf(" \n INVALID NAME \n"); 
    }
    
    if (elem->quantity >= 0)
    {
        printf(" \n Quantity: %d \n",elem->quantity); 
    }
    else
    {
        printf(" \n INVALID QUANTITY \n"); 
    }
    
    if (elem->price >= 0)
    {
        printf(" \n Price: %.3f \n",elem->price); 
    }
    else
    {
        printf(" \n INVALID PRICE \n"); 
    }
    
    if (elem->amount >= 0)
    {
        printf(" \n Amount: %.3f \n",elem->amount); 
    }
    else
    {
        printf(" \n INVALID AMOUNT \n"); 
    }
}

/*
 * Reset all elements in an item
 */
void resetValues(item* elem)
{
    if (elem->itemName != ERRORPTR)
    {
        free(elem->itemName);
        elem->itemName = ERRORPTR;
        printf("\n\tNAME'S MEMORY FREED WITH SUCCESS!\n");
    }
    
    elem->quantity = (elem->quantity >= 0) ? ERRORINT : elem->quantity;
    
    elem->price = (elem->price >= 0) ? ERRORINT : elem->price;
    
    elem->amount = (elem->amount >= 0) ? ERRORINT : elem->amount;
}
