#include "sys/Account.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "sys/Data.h"

int verifyAccount(char *id, char *password, enum Role role)
{
    if (role == ADMIN)
    {
        struct AdminAccount *p = adminAccountHead;
        while (p->next != NULL)
        {
            p = p->next;
            if (strcmp(p->id, id) == 0 && strcmp(p->password, password) == 0)
            {

                return 1;
            }
        }
    }
    else if (role == CUSTOMER)
    {
        struct CustomerAccount *p = customerAccountHead;
        while (p->next != NULL)
        {
            p = p->next;
            if (strcmp(p->id, id) == 0 && strcmp(p->password, password) == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}

void printAccount(enum Role role)
{
    if (role == ADMIN)
    {
    }
    else if (role == CUSTOMER)
    {
        struct CustomerAccount *p = customerAccountHead;
        while (p->next != NULL)
        {
            p = p->next;
            printf("ID：%s\n  密码：%s\n  地址：%s\n  电话：%s\n", p->id, p->password, p->address, p->phone);
        }
    }
}

int printAccountById(char *id, enum Role role)
{
    if (role == ADMIN)
    {
    }
    else if (role == CUSTOMER)
    {
        struct CustomerAccount *p = customerAccountHead;
        while (p->next != NULL)
        {
            p = p->next;
            if (strcmp(p->id, id) == 0)
            {
                printf("id：%s\n密码：%s\n地址：%s\n电话：%s\n", p->id, p->password, p->address, p->phone);
                return 1;
            }
        }
    }
    return 0;
}

int addAccount(char *id, char *password, char *address, char *phone, enum Role role)
{
    if (role == ADMIN)
    {
    }
    else if (role == CUSTOMER)
    {
        struct CustomerAccount *p = customerAccountHead;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = (struct CustomerAccount *)malloc(sizeof(struct CustomerAccount));

        if (p->next == NULL)
        {
            perror("malloc failed");
            return 0;
        }

        p = p->next;
        strcpy(p->id, id);
        strcpy(p->password, password);
        strcpy(p->address, address);
        strcpy(p->phone, phone);
        p->next = NULL;

        writeCustomerAccount();
        return 1;
    }
}

int deleteAccount(char *id, enum Role role)
{
    if (role == ADMIN)
    {
    }
    else if (role == CUSTOMER)
    {
        struct CustomerAccount *p = customerAccountHead;
        while (p->next != NULL)
        {
            if (strcmp(p->next->id, id) == 0)
            {
                struct CustomerAccount *temp = p->next;
                p->next = temp->next;
                free(temp);
                temp = NULL;

                writeCustomerAccount();

                return 1;
            }
            p = p->next;
        }
    }
    return 0;
}

int modifyAccount(char *id, char *password, char *address, char *phone, enum Role role)
{
    if (role == ADMIN)
    {
    }
    else if (role == CUSTOMER)
    {
        struct CustomerAccount *p = customerAccountHead;
        while (p->next != NULL)
        {
            p = p->next;
            if (strcmp(p->id, id) == 0)
            {
                strcpy(p->password, password);
                strcpy(p->address, address);
                strcpy(p->phone, phone);

                writeCustomerAccount();

                return 1;
            }
        }
    }
    return 0;
}
