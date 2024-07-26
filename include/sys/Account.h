#ifndef ACCOUNT_H
#define ACCOUNT_H

/// @brief 顾客信息

enum Role
{
    ADMIN,
    CUSTOMER,
};

/// @brief 验证账号密码是否正确
/// @param id 账号
/// @param password 密码
/// @param role 角色 ADMIN 管理员 CUSTOMER 顾客
/// @return 1 成功，0 失败
int verifyAccount(char *id, char *password, enum Role role);

/// @brief 打印全部账号信息
/// @param role 角色 ADMIN 管理员 CUSTOMER 顾客
void printAccount(enum Role role);

/// @brief 打印指定账号信息
/// @param id 账号
/// @param role 角色 ADMIN 管理员 CUSTOMER 顾客
/// @return 1 成功，0 失败
int printAccountById(char *id, enum Role role);

/// @brief 添加客户账号信息
/// @param id 账号
/// @param password 密码
/// @param address 地址 
/// @param phone 手机号
/// @param role 角色 ADMIN 管理员 CUSTOMER 顾客
/// @return 1 成功，0 失败
/// @note char 只能存储 ASCII字符，存储中文字符用 wchar_t
/// @note 如需存储中文，请使用 <wchar.h> 并修改char 为 wchar_t
/// @bug char 存储中文会乱码
int addAccount(char *id, char *password, char *address, char *phone, enum Role role);

/// @brief 删除账号信息
/// @param id 要删除的账号
/// @param role 角色 ADMIN 管理员 CUSTOMER 顾客
/// @return 1 成功，0 失败
int deleteAccount(char *id, enum Role role);

/// @brief 修改账号信息
/// @param id 账号
/// @param password 密码
/// @param address 地址
/// @param phone 手机号
/// @param role 角色 ADMIN 管理员 CUSTOMER 顾客
/// @return 1 成功，0 失败
/// @note char 只能存储 ASCII 字符，存储中文字符用 wchar_t
/// @note 如需存储中文，请使用 <wchar.h> 并修改char 为 wchar_t
/// @bug char 存储中文会乱码
int modifyAccount(char *id, char *password, char *address, char *phone, enum Role role);


#endif // ACCOUNT_H