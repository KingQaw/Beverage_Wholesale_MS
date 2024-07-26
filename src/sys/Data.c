#include "sys/Data.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int initData()
{
    if (readAdminAccount() == 0)
        return 0;

    if (readCustomerAccount() == 0)
        return 0;

    if (readOrder() == 0)
        return 0;

    if (readInventory() == 0)
    {
        return 0;
    }
    

    return 1;
}

void destroyData()
{
    struct AdminAccount *aap = adminAccountHead;
    while (aap != NULL)
    {
        struct AdminAccount *temp = aap;
        aap = aap->next;
        free(temp);
        temp = NULL;
    }
    aap = NULL;

    struct CustomerAccount *cap = customerAccountHead;
    while (cap != NULL)
    {
        struct CustomerAccount *temp = cap;
        cap = cap->next;
        free(temp);
        temp = NULL;
    }
    cap = NULL;

    struct Order *op = orderHead;
    while (op != NULL)
    {
        struct Order *temp = op;
        op = op->next;
        free(temp);
        temp = NULL;
    }
    op = NULL;

    struct Inventory *ip = inventoryHead;
    while (ip != NULL)
    {
        struct Inventory *temp = ip;
        ip = ip->next;
        free(temp);
        temp = NULL;
    }
    ip = NULL;
}

int readAdminAccount()
{
    fopen("AdminAccount.txt", "a");
    FILE *fp = fopen("AdminAccount.txt", "r");

    if (fp == NULL)
    {
        perror("Error: Failed to open AdminAccount.txt file\n");
        return 0;
    }

    adminAccountHead = (struct AdminAccount *)malloc(sizeof(struct AdminAccount));

    strcpy(adminAccountHead->id, "\0");
    strcpy(adminAccountHead->password, "\0");
    adminAccountHead->next = NULL;

    struct AdminAccount *p = adminAccountHead;
    struct AdminAccount *temp = (struct AdminAccount *)malloc(sizeof(struct AdminAccount));

    while (fscanf(fp, "%s %s", temp->id, temp->password) == 2)
    {
        temp->next = NULL;
        p->next = temp;
        p = p->next;
        temp = (struct AdminAccount *)malloc(sizeof(struct AdminAccount));
    }

    free(temp);
    temp = NULL;

    fclose(fp);

    return 1;
}

int readCustomerAccount()
{
    fopen("CustomerAccount.txt", "a");
    FILE *fp = fopen("CustomerAccount.txt", "r");

    if (fp == NULL)
    {
        perror("Error: Failed to open CustomerAccount.txt file\n");
        return 0;
    }

    customerAccountHead = (struct CustomerAccount *)malloc(sizeof(struct CustomerAccount));

    strcpy(customerAccountHead->id, "\0");
    strcpy(customerAccountHead->password, "\0");
    customerAccountHead->next = NULL;

    struct CustomerAccount *p = customerAccountHead;
    struct CustomerAccount *temp = (struct CustomerAccount *)malloc(sizeof(struct CustomerAccount));

    while (fscanf(fp, "%s %s %s %s", temp->id, temp->password, temp->address, temp->phone) == 4)
    {
        temp->next = NULL;
        p->next = temp;
        p = p->next;
        temp = (struct CustomerAccount *)malloc(sizeof(struct CustomerAccount));
    }

    free(temp);
    temp = NULL;

    fclose(fp);

    return 1;
}

int writeAdminAccount()
{
    FILE *fp = fopen("AdminAccount.txt", "w");

    if (fp == NULL)
    {
        perror("Error: Failed to open AdminAccount.txt file\n");
        return 0;
    }

    struct AdminAccount *p = adminAccountHead;

    while (p->next != NULL)
    {
        p = p->next;
        fprintf(fp, "%s %s\n", p->id, p->password); 
    }

    fclose(fp);

    return 1;
}

int writeCustomerAccount()
{
    FILE *fp = fopen("CustomerAccount.txt", "w");

    if (fp == NULL)
    {
        perror("Error: Failed to open CustomerAccount.txt file\n");
        return 0;
    }

    struct CustomerAccount *p = customerAccountHead;

    while (p->next != NULL)
    {
        p = p->next;
        fprintf(fp, "%s %s %s %s\n", p->id, p->password, p->address, p->phone); 
    }

    fclose(fp);

    return 1;
}

int readOrder()
{
    fopen("Order.txt", "a");
    FILE *fp = fopen("Order.txt", "r");

    if (fp == NULL)
    {
        perror("Error: Failed to open Order.txt file\n");
        return 0;
    }

    orderHead = (struct Order *)malloc(sizeof(struct Order));

    strcpy(orderHead->orderId, "\0");
    strcpy(orderHead->productId, "\0");
    strcpy(orderHead->customerId, "\0");
    orderHead->quantity = 0;
    orderHead->totalPrice = 0.0;
    strcpy(orderHead->orderDate, "\0");
    orderHead->next = NULL;

    struct Order *p = orderHead;
    struct Order *temp = (struct Order *)malloc(sizeof(struct Order));

    while (fscanf(fp, "%s %s %s %d %f %s", temp->orderId, temp->productId, temp->customerId, &temp->quantity, &temp->totalPrice, temp->orderDate) == 6)
    {
        temp->next = NULL;
        p->next = temp;
        p = p->next;
        temp = (struct Order *)malloc(sizeof(struct Order));
    }

    free(temp);
    temp = NULL;

    fclose(fp);

    return 1;
}

int writeOrder()
{
    FILE *fp = fopen("Order.txt", "w");

    if (fp == NULL)
    {
        perror("Error: Failed to open Order.txt file\n");
        return 0;
    }

    struct Order *p = orderHead;

    while (p->next != NULL)
    {
        p = p->next;
        fprintf(fp, "%s %s %s %d %.2f %s\n", p->orderId, p->productId, p->customerId, p->quantity, p->totalPrice, p->orderDate); 
    }

    fclose(fp);

    return 1;
}

int readInventory()
{
    fopen("Inventory.txt", "a");
    FILE *fp = fopen("Inventory.txt", "r");

    if (fp == NULL)
    {
        perror("Error: Failed to open Inventory.txt file\n");
        return 0;
    }

    inventoryHead = (struct Inventory *)malloc(sizeof(struct Inventory));

    strcpy(inventoryHead->productId, "\0");
    strcpy(inventoryHead->type, "\0");
    inventoryHead->quantity = 0;
    inventoryHead->price = 0.0;
    inventoryHead->next = NULL;

    struct Inventory *p = inventoryHead;
    struct Inventory *temp = (struct Inventory *)malloc(sizeof(struct Inventory));

    while (fscanf(fp, "%s %s %f %d", temp->productId, temp->type, &temp->price, &temp->quantity) == 4)
    {
        temp->next = NULL;
        p->next = temp;
        p = p->next;
        temp = (struct Inventory *)malloc(sizeof(struct Inventory));
    }

    free(temp);
    temp = NULL;

    fclose(fp);

    return 1;
}

int writeInventory()
{
    FILE *fp = fopen("Inventory.txt", "w");

    if (fp == NULL)
    {
        perror("Error: Failed to open Inventory.txt file\n");
        return 0;
    }

    struct Inventory *p = inventoryHead;

    while (p->next != NULL)
    {
        p = p->next;
        fprintf(fp, "%s %s %.2f %d\n", p->productId, p->type, p->price, p->quantity); 
    }

    fclose(fp);

    return 1;
}