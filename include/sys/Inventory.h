#ifndef INVENTORY_H
#define INVENTORY_H

/// @brief 进货
/// @param productId 商品名
/// @param type 种类
/// @param price 价格
/// @param quantity 进货数量
/// @return 1 成功，0 失败
/// @bug char 存储中文会乱码
int addInventory(char *productId, char *type, float price, int quantity);

/// @brief 向控制台打印全部库存信息
void printInventory();

/// @brief 向控制台打印指定库存的信息
/// @param productId 商品名
/// @param type 种类
/// @return 1 成功，0 失败
int findInventoryByIdType(char *productId, char *type);

/// @brief 计算购买总价
/// @param productId 商品名
/// @param type 种类
/// @param quantity 数量
/// @return 总价，数量超出库存时返回-1.0
double calculateTotalPrice(char *productId, char *type, int quantity);

/// @brief 减少库存
/// @param productId 商品名 
/// @param type 种类
/// @param quantity 减少的数量
/// @return 1 成功，0 失败
int decreaseInventory(char *productId, char *type, int quantity);

#endif // INVENTORY_H