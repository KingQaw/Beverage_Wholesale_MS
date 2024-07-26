#ifndef DATA_H
#define DATA_H

/// @brief 所有数据结构体的头文件

/// @brief 管理员账户结构体
/// @param id 管理员ID
/// @param password 管理员密码
/// @param next 链表指针
/// @note 管理员账户信息存储在 AdminAccount.txt 文件中
/// @note 管理员账户信息以 id password 的形式存储
struct AdminAccount
{
    char id[10];
    char password[10];
    struct AdminAccount *next;
};

/// @brief 顾客账户结构体
/// @param id 顾客ID
/// @param password 顾客密码
/// @param address 顾客地址
/// @param phone 顾客电话
/// @param next 链表指针
/// @note 顾客账户信息存储在 CustomerAccount.txt 文件中
/// @note 顾客账户信息以 id password address phone 的形式存储
struct CustomerAccount
{
    char id[10];
    char password[10];
    char address[50];
    char phone[20];
    struct CustomerAccount *next;
};

/// @brief 订单结构体
/// @param orderId 订单编号
/// @param customerId 顾客ID
/// @param productId 商品编号
/// @param quantity 购买数量
/// @param totalPrice 总价
/// @param orderDate 订单日期
/// @param next 链表指针
/// @note 订单信息存储在 Order.txt 文件中
/// @note 订单信息以 orderId customerId productId quantity totalPrice orderDate 的形式存储
struct Order
{
    char orderId[20];
    char customerId[10];
    char productId[10];
    int quantity;
    float totalPrice;
    char orderDate[20];
    struct Order *next;
};

/// @brief 库存结构体
/// @param productId 商品名
/// @param type 商品类型
/// @param price 商品价格
/// @param quantity 商品数量
/// @param next 链表指针
/// @note 库存信息存储在 Inventory.txt 文件中
/// @note 库存信息以 productId type price quantity 的形式存储
struct Inventory
{
    char productId[10];
    char type[10];
    float price;
    int quantity;
    struct Inventory *next;
};

struct AdminAccount *adminAccountHead;
struct CustomerAccount *customerAccountHead;
struct Order *orderHead;
struct Inventory *inventoryHead;

/// @brief 初始化数据
/// @return 1 成功，0 失败
int initData();

/// @brief 释放所有链表
/// @note 在程序退出时执行，free
void destroyData();

/// @brief 从 AdminAccount.txt 中读取管理员账户信息
/// @return 1 成功，0 失败
int readAdminAccount();

/// @brief 向 AdminAccount.txt 中写入管理员账户信息
/// @return 1 成功，0 失败
int writeAdminAccount();

/// @brief 从 CustomerAccount.txt 中读取顾客账户信息
/// @return 1 成功，0 失败
int readCustomerAccount();

/// @brief 向 CustomerAccount.txt 中写入顾客账户信息
/// @return 1 成功，0 失败
int writeCustomerAccount();

/// @brief 从 Order.txt 中读取订单信息
/// @return 1 成功，0 失败
int readOrder();

/// @brief 向 Order.txt 中写入订单信息
/// @return 1 成功，0 失败
int writeOrder();

/// @brief 从 Inventory.txt 中读取库存信息
/// @return 1 成功，0 失败
int readInventory();

/// @brief 向 Inventory.txt 中写入库存信息
/// @return 1 成功，0 失败
int writeInventory();

#endif // DATA_H