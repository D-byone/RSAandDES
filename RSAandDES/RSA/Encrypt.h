

#ifndef _ENCRYPT_H
#define _ENCRYPT_H

#include"BigNum.h"
#include"RSA.h"


class Encrypt :public RSA
{
public:
	//构造函数 生成密文
	Encrypt();
	//将明文字符转换为数字
	int DealPw(char c);
	//加密过程
	void Set_c();
	//解密过程
	void Set_m();
	//打印明文
	void print_m();
	//打印密文
	void print_c();
	//翻译明文
	void Deal_c();
private:
	BigNum m;
	BigNum strm[10];
	BigNum strc[10];
	int m_length;
	int grouplen;
	int flag;
};
#endif