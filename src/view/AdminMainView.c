#include "view/AdminMainView.h"

/// @brief 管理员主界面，显示管理员的操作选项
/// @note 管理员可以查看顾客信息、订单信息、库存信息、经营情况，
/// @note 并可以对顾客信息、订单信息、库存信息进行增删改查
/// @bug 优化项目逻辑：
/// @bug 顾客购买与退货的逻辑需要明确

#include <stdio.h>
#include <string.h>

#include "sys/Account.h"
#include "sys/Order.h"
#include "sys/Inventory.h"

void showCustomerMainView();
void showOrderMainView();
void showInventoryMainView();
void showBussinessMainView();

void showAdminMainView(char *loginID)
{
    while (1)
    {
        printf("你好，管理员: %s！\n", loginID);
        printf("1. 顾客信息\n");
        printf("2. 订单信息\n");
        printf("3. 库存信息\n");
        printf("4. 经营情况\n");
        printf("0. 退出系统\n");
        printf("请输入选项: ");

        char choice = '\0';
        while (1)
        {
            scanf("%c", &choice);
            getchar(); // 读取一个换行符
            if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '0')
            {
                break;
            }
            printf("输入选项有误，请重新选择：");
        }

        if (choice == '1')
        {
            // 顾客信息
            showCustomerMainView();
        }
        else if (choice == '2')
        {
            // 订单信息
            showOrderMainView();
        }
        else if (choice == '3')
        {
            // 库存信息
            showInventoryMainView();
        }
        else if (choice == '4')
        {
            // 经营情况
            showBussinessMainView();
        }
        else if (choice == '0')
        {
            printf("欢迎下次使用！\n");
            return;
        }
    }
}

/// @brief 顾客信息主界面
void showCustomerMainView()
{
    while (1)
    {
        getchar(); // 清空输入缓存
        printf("---顾客界面---\n");
        printf("1. 查看顾客信息\n");
        printf("2. 添加顾客信息\n");
        printf("3. 修改顾客信息\n");
        printf("4. 删除顾客信息\n");
        printf("0. 返回上一级\n");
        printf("请输入选项: ");

        char choice = '\0';
        while (1)
        {
            scanf("%c", &choice);
            getchar(); // 读取一个换行符
            if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '0')
            {
                break;
            }
            printf("输入选项有误，请重新选择：");
        }

        if (choice == '1')
        {
            // 查看顾客信息
            printAccount(CUSTOMER);
        }
        else if (choice == '2')
        {
            // 添加顾客信息
            printf("请输入顾客信息：(输入 # 退出)\n");

            printf("Id:");
            char id[10];
            scanf("%s", id);
            getchar();

            if (strcmp(id, "#") == 0)
            {
                continue;
            }

            printf("密码：");
            char password[10];
            scanf("%s", password);
            getchar();
            if (strcmp(id, "#") == 0)
            {
                continue;
            }

            printf("地址：");
            char address[50];
            scanf("%s", address);
            getchar();
            if (strcmp(id, "#") == 0)
            {
                continue;
            }

            printf("电话：");
            char phone[20];
            scanf("%s", phone);
            getchar();
            if (strcmp(id, "#") == 0)
            {
                continue;
            }

            char confirm = '\0';
            while (1)
            {
                printf("添加的顾客信息如下：\n");
                printf("Id: %s\n", id);
                printf("密码: %s\n", password);
                printf("地址: %s\n", address);
                printf("电话: %s\n", phone);
                printf("是否确认添加？(Y/n): ");

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
                addAccount(id, password, address, phone, CUSTOMER);
                printf("添加顾客信息成功！，返回上一级\n");
            }
            else if (confirm == 'n')
            {
                printf("取消添加顾客信息，返回上一级\n");
                continue;
            }
        }
        else if (choice == '3')
        {
            // 修改顾客信息
            printf("请输入顾客Id：(输入 # 退出)");
            char id[10];
            scanf("%s", id);
            getchar();
            if (strcmp(id, "#") == 0)
            {
                continue;
            }
            char confirm = '\0';
            while (1)
            {
                printf("该顾客的信息如下：\n");
                printAccountById(id, CUSTOMER);

                printf("是否继续修改？(Y/n): ");

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
                printf("请输入新的信息：\n");

                printf("密码：");
                char password[10];
                scanf("%s", password);
                getchar();

                printf("地址：");
                char address[50];
                scanf("%s", address);
                getchar();

                printf("电话：");
                char phone[20];
                scanf("%s", phone);
                getchar();

                char confirm = '\0';
                while (1)
                {
                    printf("修改后的顾客信息如下：\n");
                    printf("Id: %s\n", id);
                    printf("密码: %s\n", password);
                    printf("地址: %s\n", address);
                    printf("电话: %s\n", phone);
                    printf("是否确认修改？(Y/n): ");

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
                    modifyAccount(id, password, address, phone, CUSTOMER);
                    printf("修改顾客信息成功！，返回上一级\n");
                }
                else if (confirm == 'n')
                {
                    printf("取消修改顾客信息，返回上一级\n");
                }
            }
            else if (confirm == 'n')
            {
                printf("取消修改顾客信息，返回上一级\n");
            }
        }
        else if (choice == '4')
        {
            // 删除顾客信息
            printf("请输入顾客Id：(输入 # 退出)");
            char id[10];
            scanf("%s", id);
            getchar();

            if (strcmp(id, "#") == 0)
            {
                continue;
            }

            char confirm = '\0';
            while (1)
            {
                printf("该顾客的信息如下：\n");
                printAccountById(id, CUSTOMER);

                printf("是否继续删除？(Y/n): ");

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
                deleteAccount(id, CUSTOMER);
                printf("删除顾客信息成功！，返回上一级\n");
            }
            else if (confirm == 'n')
            {
                printf("取消删除顾客信息，返回上一级\n");
            }
        }
        else if (choice == '0')
        {
            printf("返回上一级\n");
            return;
        }
    }
}

/// @brief 订单信息主界面
void showOrderMainView()
{
    while (1)
    {
        getchar();
        printf("---订单界面---\n");
        printf("1. 查看订单信息\n");
        printf("2. 修改订单信息\n");
        printf("3. 删除订单信息\n");
        printf("0. 返回上一级\n");
        printf("请输入选项: ");

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
            // 查看订单信息
            printOrder();
        }
        else if (choice == '2')
        {
            // 修改订单信息
            printf("修改订单功能暂不开放\n");
            // TODO: 实现修改订单功能
        }
        else if (choice == '3')
        {
            // 删除订单信息
            printf("删除订单功能暂不开放\n");
            // TODO: 实现删除订单功能
        }
        else if (choice == '0')
        {
            printf("返回上一级\n");
            return;
        }
    }
}

/// @brief 库存信息主界面
void showInventoryMainView()
{
    while (1)
    {
        getchar();
        printf("---库存界面---\n");
        printf("1. 查看库存信息\n");
        printf("2. 进货\n");
        printf("0. 返回上一级\n");
        printf("请输入选项: ");

        char choice = '\0';
        while (1)
        {
            scanf("%c", &choice);
            getchar(); // 读取一个换行符
            if (choice == '1' || choice == '2' || choice == '0')
            {
                break;
            }
            printf("输入选项有误，请重新选择：");
        }

        if (choice == '1')
        {
            // 查看库存信息
            printInventory();
        }
        else if (choice == '2')
        {
            // 进货
            printf("请输入进货信息：(输入 # 退出)\n");
            printf("商品名：");
            char productId[10];
            scanf("%s", productId);
            getchar();

            if (strcmp(productId, "#") == 0)
            {
                continue;
            }

            printf("种类：");
            char type[10];
            scanf("%s", type);
            getchar();

            if (strcmp(type, "#") == 0)
            {
                continue;
            }

            printf("售价：");
            float price;
            scanf("%f", &price);
            getchar();

            printf("库存量：");
            int quantity;
            scanf("%d", &quantity);
            getchar();

            char confirm = '\0';
            while (1)
            {
                printf("进货的商品信息如下：\n");
                printf("商品名: %s\n", productId);
                printf("种类: %s\n", type);
                printf("售价: %.2f\n", price);
                printf("库存量: %d\n", quantity);
                printf("是否确认添加？(Y/n): ");

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
                addInventory(productId, type, price, quantity);
                printf("添加商品进货成功！，返回上一级\n");
            }
            else if (confirm == 'n')
            {
                printf("取消添加商品进货，返回上一级\n");
            }
        }
        else if (choice == '0')
        {
            printf("返回上一级\n");
            return;
        }
    }
}

/// @brief 经营情况主界面
void showBussinessMainView()
{
}