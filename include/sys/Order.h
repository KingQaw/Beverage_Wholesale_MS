#ifndef ORDER_H
#define ORDER_H

/// @brief 订单

/// @brief 向控制台打印订单信息
void printOrder();

/// @brief 添加订单
/// @param orderId 订单编号
/// @param customerId 顾客ID
/// @param productId 商品名
/// @param quantity 数量
/// @param totalPrice 总价
/// @param orderDate 日期
void addOrder(char *orderId, char *customerId, char *productId, int quantity, float totalPrice, char *orderDate);

/// @brief 根据顾客ID查找订单
/// @param customerId 顾客ID
/// @return 1表示找到，0表示未找到
/// @note 找到在控制台输出对应信息
int findOrderByCustomerId(char *customerId);

#endif // ORDER_H