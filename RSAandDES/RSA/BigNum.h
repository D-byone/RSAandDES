
#ifndef _BIGNUM_H
#define _BIGNUM_H
#include<string>
#include<iostream>


using namespace std;

#define MAX_LENGTH 2000


class BigNum
{
public:
	//构造函数 用于人为初始化大数
	BigNum();
	BigNum(string s);
	//拷贝构造函数
	BigNum(const BigNum & T);
	//析构函数
	~BigNum();

	//重载加法运算符，两个大数之间的相加运算 
	BigNum operator+(const BigNum &) const;
	//重载减法运算符，两个大数之间的相减运算 
	BigNum operator-(const BigNum &) const;
	//重载乘法运算符，两个大数之间的相乘运算 
	BigNum operator*(const BigNum &n) const;
	//重载除法运算符，大数对一个大数进行相除运算  
	BigNum operator/(const BigNum &n) const;

	//重载赋值运算符，大数之间进行赋值运算 
	BigNum& operator=(const BigNum & n);

	//大数的幂运算  求模
	BigNum mod(const BigNum  &a, const BigNum  &b) const;
	//大数对一个大数进行取模运算
	BigNum    operator%(const BigNum & T) const;
	//大数和另一个大数的大小比较  
	bool   operator>=(const BigNum & T)const;
	//将int类型的数组转换为字符串型
	BigNum Change(const int data[], int len)const;
	//输出大数  
	void print();
	//补零
	BigNum AddZero(BigNum a, BigNum b) const;
	//每次调用 对补零以后的除数减少一个零
	bool SubZero(BigNum& a, BigNum b) const;
	//重载==运算符
	bool   operator==(const BigNum & T)const;
	//改变num的值
	void changNum(string s);
	//求两个大数的最大公因子
	BigNum gcd(const BigNum  a, const BigNum  b);
	//获取字符串
	string GetNum();
	//去掉大数前面添加的零
	BigNum ClearZero();
	//补齐前面的零 用于转译
	BigNum AdZero(int length);
private:
	//将大数用字符串的形式储存
	string num;
	//大数的长度
	int len;
};
#endif