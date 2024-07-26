/// @note 所有代码文件使用 UTF-8 编码，中文乱码请注意修改 VSCode 的编码设置。

#include "view/LoginView.h"
#include "sys/Data.h"

#include <stdio.h>
#include <windows.h>

int main()
{
    // 设置控制台输出编码为 UTF-8
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    // 初始化数据
    if (initData() == 0)
    {
        printf("导入数据错误，请联系管理员！\n");
        return 1;
    }

    // 显示登录界面
    showLoginView();

    // 销毁数据
    destroyData();
    return 0;
}