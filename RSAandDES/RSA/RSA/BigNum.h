
#ifndef _BIGNUM_H
#define _BIGNUM_H
#include<string>
#include<iostream>


using namespace std;

#define MAX_LENGTH 2000


class BigNum
{
public:
	//���캯�� ������Ϊ��ʼ������
	BigNum();
	BigNum(string s);
	//�������캯��
	BigNum(const BigNum & T);
	//��������
	~BigNum();

	//���ؼӷ����������������֮���������� 
	BigNum operator+(const BigNum &) const;
	//���ؼ������������������֮���������� 
	BigNum operator-(const BigNum &) const;
	//���س˷����������������֮���������� 
	BigNum operator*(const BigNum &n) const;
	//���س����������������һ�����������������  
	BigNum operator/(const BigNum &n) const;

	//���ظ�ֵ�����������֮����и�ֵ���� 
	BigNum& operator=(const BigNum & n);

	//������������  ��ģ
	BigNum mod(const BigNum  &a, const BigNum  &b) const;
	//������һ����������ȡģ����
	BigNum    operator%(const BigNum & T) const;
	//��������һ�������Ĵ�С�Ƚ�  
	bool   operator>=(const BigNum & T)const;
	//��int���͵�����ת��Ϊ�ַ�����
	BigNum Change(const int data[], int len)const;
	//�������  
	void print();
	//����
	BigNum AddZero(BigNum a, BigNum b) const;
	//ÿ�ε��� �Բ����Ժ�ĳ�������һ����
	bool SubZero(BigNum& a, BigNum b) const;
	//����==�����
	bool   operator==(const BigNum & T)const;
	//�ı�num��ֵ
	void changNum(string s);
	//�������������������
	BigNum gcd(const BigNum  a, const BigNum  b);
	//��ȡ�ַ���
	string GetNum();
	//ȥ������ǰ����ӵ���
	BigNum ClearZero();
	//����ǰ����� ����ת��
	BigNum AdZero(int length);
private:
	//���������ַ�������ʽ����
	string num;
	//�����ĳ���
	int len;
};
#endif