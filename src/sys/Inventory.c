#include "sys/Inventory.h"

#include "sys/Data.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addInventory(char *productId, char *type, float price, int quantity)
{
    struct Inventory *p = inventoryHead;
    while (p->next != NULL)
    {
        p = p->next;
        if (strcmp(p->productId, productId) == 0 && strcmp(p->type, type) == 0)
        {
            p->quantity += quantity;
            
            writeInventory();
            return 1;
        }
    }

    p->next = (struct Inventory*) malloc(sizeof(struct Inventory));

    if (p->next == NULL)
    {
        perror("malloc failed");
        return 0;
    }

    p = p->next;
    strcpy(p->productId, productId);
    strcpy(p->type, type);
    p->price = price;
    p->quantity = quantity;
    p->next = NULL;

    writeInventory();
    return 1;
}

void printInventory()
{
    struct Inventory *p = inventoryHead;
    while (p->next != NULL)
    {
        p = p->next;
        printf("商品名：%s\n  种类：%s\n  售价：%.2f\n  库存量：%d\n", p->productId, p->type, p->price, p->quantity);
    }
}

int findInventoryByIdType(char *productId, char *type)
{
    struct Inventory *p = inventoryHead;
    while (p->next != NULL)
    {
        p = p->next;
        if (strcmp(p->productId, productId) == 0 && strcmp(p->type, type) == 0)
        {
            printf("商品名：%s\n  种类：%s\n  售价：%.2f\n  存量：%d\n", p->productId, p->type, p->price, p->quantity);
            return 1;
        }
    }
    return 0;
}

double calculateTotalPrice(char *productId, char *type, int quantity)
{
    struct Inventory *p = inventoryHead;
    while (p->next != NULL)
    {
        p = p->next;
        if (strcmp(p->productId, productId) == 0 && strcmp(p->type, type) == 0)
        {
            return p->quantity >= quantity ? p->price * quantity : -1.0;
        }
    }
    return -1.0;
}

int decreaseInventory(char *productId, char *type, int quantity)
{
    struct Inventory *p = inventoryHead;
    while (p->next != NULL)
    {
        p = p->next;
        if (strcmp(p->productId, productId) == 0 && strcmp(p->type, type) == 0)
        {
            if (p->quantity >= quantity)
            {
                p->quantity -= quantity;
                writeInventory();
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    return 0;
}