#include "view/LoginView.h"

#include <stdio.h>
#include <string.h>

#include "sys/Account.h"
#include "view/AdminMainView.h"
#include "view/UserMainView.h"

void showLoginView(void)
{
    while (1)
    {
        printf("欢迎使用巴适酒水批发管理系统\n");
        printf("1. 管理员登录  2. 顾客登录  0. 退出登录\n");
        printf("请选择您的身份：");
        char choice = '\0';
        while (1)
        {
            scanf("%c", &choice);
            getchar();
            if (choice == '1' || choice == '2' || choice == '0')
            {
                break;
            }
            printf("输入有误，请重新选择身份：");
        }
        if (choice == '1')
        {
            // 管理员登录
            printf("请输入管理员账号：");
            char adminId[10];
            scanf("%s", adminId);
            getchar();
            printf("请输入管理员密码：");
            char adminPwd[10];
            scanf("%s", adminPwd);
            getchar();

            if (verifyAccount(adminId, adminPwd, ADMIN) == 0)
            {
                printf("管理员账号密码错误，请重新登录！\n");
            }
            else
            {
                printf("管理员登录成功！\n");
                showAdminMainView(adminId);
            }
        }
        else if (choice == '2')
        {
            // 普通顾客登录
            printf("请输入顾客账号：");
            char userId[10];
            scanf("%s", userId);
            getchar();
            printf("请输入顾客密码：");
            char userPwd[10];
            scanf("%s", userPwd);
            getchar();

            if (verifyAccount(userId, userPwd, CUSTOMER) == 0)
            {
                printf("顾客账号密码错误，请重新登录！\n");
            }
            else
            {
                printf("顾客登录成功！\n");
                showUserMainView(userId);
            }
        }
        else if (choice == '0')
        {
            printf("欢迎下次使用！");
            return;
        }
    }
}