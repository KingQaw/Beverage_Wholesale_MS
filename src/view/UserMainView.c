#include "view/UserMainView.h"

#include <stdio.h>
#include <string.h>
#include <time.h>

#include "sys/Data.h"
#include "sys/Inventory.h"
#include "sys/Order.h"

void showInventoryNumMainView();
void showBatchMainView();
void showBatchRecordMainView();

char loginId[10];

void showUserMainView(char *loginID)
{
    strcpy(loginId, loginID);
    while (1)
    {
        getchar();
        printf("你好，顾客: %s！\n", loginID);
        printf("1. 查看库存\n");
        printf("2. 批发\n");
        printf("3. 批发记录\n");
        printf("0. 退出系统\n");

        char choice = '\0';
        while (1)
        {
            scanf("%c", &choice);
            getchar(); // 读取一个换行符
            if (choice == '1' || choice == '2' || choice == '3' || choice == '0')
            {
                break;
            }
            printf("输入选项有误，请重新选择：");
        }

        if (choice == '1')
        {
            // 查看库存
            showInventoryNumMainView();
        }
        else if (choice == '2')
        {
            // 批发
            showBatchMainView();
        }
        else if (choice == '3')
        {
            // 批发记录
            showBatchRecordMainView();
        }
        else if (choice == '0')
        {
            // 退出系统
            printf("欢迎下次使用！\n");
            return;
        }
    }
}

/// @brief 显示库存主界面
void showInventoryNumMainView()
{
    printInventory();
}

/// @brief 批发
void showBatchMainView()
{
    while (1)
    {
        printf("当前酒水信息如下：\n");
        printInventory();
        printf("请输入您要批发的酒水（输入 # 退出）\n");

        printf("商品名：");
        char productId[10];
        scanf("%s", productId);
        getchar();

        if (strcmp(productId, "#") == 0)
        {
            return;
        }

        printf("种类：");
        char type[10];
        scanf("%s", type);
        getchar();

        if (strcmp(type, "#") == 0)
        {
            return;
        }

        printf("该酒水信息如下：\n");
        if (findInventoryByIdType(productId, type) == 0)
        {
            printf("不存在该商品名和种类的酒水，请检查输入是否正确\n");
            continue;
        }

        double totalPrice = -1.0;
        int num = 0;
        while (1)
        {
            printf("请输入批发数量：");

            // TODO: 批发数量的输入改为字符串，避免错误输入
            scanf("%d", &num);
            getchar();

            if (num == 0)
            {
                printf("退出进货\n");
                return;
            }

            totalPrice = calculateTotalPrice(productId, type, num);

            if (totalPrice == -1.0)
            {
                printf("库存不足，请重新输入：(输入 0 退出)");
                continue;
            }

            break;
        }

        // TODO: 实现一次购买多种酒水
        char confirm = '\0';
        while (1)
        {
            printf("当前订单信息如下：\n");
            printf("商品名：%s\n  种类：%s\n  数量：%d\n  总价：%.2f\n", productId, type, num, totalPrice);
            printf("是否确认：（Y/n)");

            scanf("%c", &confirm);
            getchar();

            if (confirm == 'Y' || confirm == 'n')
            {
                break;
            }
            printf("输入有误，请重新输入：");
        }

        if (confirm == 'Y')
        {
            // decreaseInventory(productId, type, num);
            time_t now = time(NULL);
            struct tm *ltm = localtime(&now);
            char orderId[20];
            strftime(orderId, sizeof(orderId), "%Y%m%d%H%M%S", ltm);
            char orderDate[20];
            strftime(orderDate, sizeof(orderDate), "%Y-%m-%d.%H:%M:%S", ltm);
            addOrder(orderId, loginId, productId, num, totalPrice, orderDate);
            printf("订单提交成功，订单号：%s\n", orderId);
            continue;
        }
        else if (confirm == 'n')
        {
            printf("已取消订单，返回上一级\n");
            return;
        }
    }
}

/// @brief 批发记录
void showBatchRecordMainView()
{
    printf("顾客 %s 的批发记录如下：\n", loginId);
    if (findOrderByCustomerId(loginId) == 0)
    {
        printf("暂无记录\n");
    }
}
