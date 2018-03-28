#include "Matlab2c.h"
using namespace std;
using namespace Matlab2c;


//��������ȡʵ��
//���룺��������a
//�������������a��ʵ��
Matrix Matlab2c::real(CMatrix& a)
{
	Matlab2c::CheckLicense();
	return a.real();
}

//��������ȡ�鲿
//���룺��������a
//�������������a���鲿
Matrix Matlab2c::imag(CMatrix& a)
{
	Matlab2c::CheckLicense();
	return a.imag();
}


//��������ȡ�Ƕ�
//���룺��������a
//���������a������Ԫ�صĽǶ�ֵ�����ȵ�λ��
Matrix Matlab2c::angle(CMatrix& a)
{
	Matlab2c::CheckLicense();
	return a.angle();
}


//��������ȡģ
//���룺��������a
//���������a������Ԫ�ص�ģ��ֵ
Matrix Matlab2c::abs(CMatrix& a)
{
	Matlab2c::CheckLicense();
	return a.abs();
}



//��������ȡ����
//���룺��������a
//�������������a�Ĺ���
CMatrix Matlab2c::conj(CMatrix& a)
{
	Matlab2c::CheckLicense();
	return a.conj();
}










