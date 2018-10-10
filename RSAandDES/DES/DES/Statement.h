#include<iostream>
#include<string>
using namespace std;



//���� ���Ĵ���

class Password
{
public:
	Password(string IntiData);
	//ת��Ϊ64λ������
	void ChangeBinary(char DealData[64], string IntiData);
	//��ʼ�û�
	void IntiChange(char DealData[64]);
	//�ֳ�����������
	void Divi(char DealData[64]);
	//��ӡ���� 64�����û��Ժ�
	void Show();
	//�������
	void CLearData();
	//���� Encrypt��Ϊ��Ԫ��
	friend class Encrypt;
private:
	//���32λ
	char Left[32];
	//�ұ�32λ
	char Right[32];
};

// ��Կ���� 

class Key
{
public:
	Key(string IntiData);
	//ת��Ϊ56λ������
	void ChangeBinary(char DealData[64], string IntiData);
	//��ʼ�û� PC-1
	void IntiChange(char DealData[64]);
	//�ֳ�����������
	void Divi(char DealData[64]);
	//��ӡ����
	void Show();
	//�������
	void CLearData();
	//���� Encrypt��Ϊ��Ԫ��
	friend class Encrypt;
private:
	char C[28];
	char D[28];
};

//���� ����

class  Encrypt
{
public:
	Encrypt();
	//���ɸ��ֱ��� L R C D
	void MoveData(Password p1,Key k1);
	//��չR
	void ExRight();
	//��ӡÿһ�ε���Կ
	void Show1();
	//��ӡÿһ�ε����� �Լ���չ�������
	void Show2();
	//��ӡ��λ�Ժ������Կ �Լ���չ����ֻ�
	void Show3();
	//����Կ ��ѭ����λ
	void LeftCircMov(int round);
	//�û�ѡ��2 PC-2 ����������ԿK
	void Exchange();
	//RightEx ������ԿK �ֻ�
	void RightExKF();
	//ͨ��S�в���32���ص����
	void SOutPut();
	//��SOutPut ������
	int SOut32(char Move[6], int i);
	//��SOut32���� ��ȡ����
	int GetRow(int a,int b);
	//��SOut32���� ��ȡ����
	int GetColumn(char Mid[6]);
	//S�в�����32���ص���� �����û�
	void ExchangeF();
	//L(i-1)��F���ֻ�
	void LandF();
	//������һ�ε�����LR
	void SaveLandR();
	//���ҽ��� ���ʼ ��������
	void FinaChan();

protected:
	char ELeft[32];
	char ERight[32];
	char EC[28];
	char ED[28];
	char K[48];
	char LER[32];
	char RightEx[48];
	char RightExK[48];
private:
	char LEF[32];
	char F[32];
};

//������ �ɼ�����̳ж���

class BreakPW:public Encrypt
{
public:
	BreakPW(string s1,string s2);
	void Exchange16();
	//��������Կ
	void SaveKey(int j, char K[48]);
	//����
	void BreakData();
	//�����ǰ��L
	void MakeL();
	//������Կ�ֻ�
	void BRightExKF(int round);
	//���ܵĵ�һ����ʼ�û�
	void Change();
	//������ת�����ַ�
	void CreatChar();
	//�������� ת��Ϊʮ������
	int MakeInt(int num,char ch);
private:
	char strK[16][48];
};

