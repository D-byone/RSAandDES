
#ifndef _RSA_H
#define _RSA_H
#include"BigNum.h"


class RSA
{
public:
	RSA();
	//素数生成
	BigNum CreatePQ(int len);
	//素数检验
	bool CheckNum(BigNum num);
	//求欧拉函数值 以及n
	void Euler_n();
	//随机生成e
	void Create_e();
	//计算d 求乘法逆元
	BigNum Create_d();
	//设置用于测试的数据
	void Setdata();
	//打印数据
	void print();
	//得到e
	BigNum Get_e();
	//得到n
	BigNum Get_n();
	//得到d
	BigNum Get_d();
	//MR概率检测
	bool witness(BigNum n);
private:
	BigNum p;
	BigNum q;
	BigNum n;
	BigNum euler_n;
	BigNum e;
	BigNum d;
};
#endif