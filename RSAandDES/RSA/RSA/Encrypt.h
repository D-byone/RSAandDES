

#ifndef _ENCRYPT_H
#define _ENCRYPT_H

#include"BigNum.h"
#include"RSA.h"


class Encrypt :public RSA
{
public:
	//���캯�� ��������
	Encrypt();
	//�������ַ�ת��Ϊ����
	int DealPw(char c);
	//���ܹ���
	void Set_c();
	//���ܹ���
	void Set_m();
	//��ӡ����
	void print_m();
	//��ӡ����
	void print_c();
	//��������
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