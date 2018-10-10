
#ifndef _RSA_H
#define _RSA_H
#include"BigNum.h"


class RSA
{
public:
	RSA();
	//��������
	BigNum CreatePQ(int len);
	//��������
	bool CheckNum(BigNum num);
	//��ŷ������ֵ �Լ�n
	void Euler_n();
	//�������e
	void Create_e();
	//����d ��˷���Ԫ
	BigNum Create_d();
	//�������ڲ��Ե�����
	void Setdata();
	//��ӡ����
	void print();
	//�õ�e
	BigNum Get_e();
	//�õ�n
	BigNum Get_n();
	//�õ�d
	BigNum Get_d();
	//MR���ʼ��
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