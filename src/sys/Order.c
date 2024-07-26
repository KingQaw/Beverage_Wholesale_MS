#include "sys/Order.h"

#include "sys/Data.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printOrder()
{
    struct Order *p = orderHead;
    
    while (p->next != NULL)
    {
        p = p->next;
        printf("订单ID: %s\n  顾客ID: %s\n  商品ID: %s\n  数量: %d\n  总价: %.2f\n  日期: %s\n", p->orderId, p->customerId, p->productId, p->quantity, p->totalPrice, p->orderDate);
    }
}

void addOrder(char *orderId, char *customerId, char *productId, int quantity, float totalPrice, char *orderDate)
{
    struct Order *p = orderHead;
    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = (struct Order*)malloc(sizeof(struct Order));
    p = p->next;

    strcpy(p->orderId, orderId);
    strcpy(p->customerId, customerId);
    strcpy(p->productId, productId);
    p->quantity = quantity;
    p->totalPrice = totalPrice;
    strcpy(p->orderDate, orderDate);
    p->next = NULL;

    writeOrder();
}

int findOrderByCustomerId(char *customerId)
{
    int flag = 0;
    struct Order *p = orderHead;
    while (p->next != NULL)
    {
        p = p->next;
        if (strcmp(p->customerId, customerId) == 0)
        {
            printf("订单ID: %s\n  顾客ID: %s\n  商品ID: %s\n  数量: %d\n  总价: %.2f\n  日期: %s\n", p->orderId, p->customerId, p->productId, p->quantity, p->totalPrice, p->orderDate);
            flag = 1;
        }
    }
    return flag;
}