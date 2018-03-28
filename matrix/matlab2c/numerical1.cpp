#include "Matlab2c.h"
using namespace Matlab2c;

//ʵ���������ֵ
//����Ϊһ���������Ϊ�þ���Ԫ�صľ���ֵ����
Matrix Matlab2c::abs(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i;
	Matrix p(a.row,a.column);
	for (i=0;i<(p.row*p.column);i++)
		p.data[i]=(double)std::fabs(a.data[i]);
	return p;
}
//����Ԫ�س����������ȡ��
//���룺ԭ����a
//���������aԪ������ȡ��
Matrix Matlab2c::ceil(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	p.data = new double[p.row*p.column];
	for(i=0;i<p.row;i++)
		for(j=0;j<p.column;j++)
			p(i,j) = std::ceil(a(i,j)); //ceil(x)���ص��Ǵ��ڵ���x����С����
	return p;
}


//����eΪ�׵�ָ������
//���룺����a
//���������a����eΪ�׵�ָ��ֵ
Matrix Matlab2c::exp(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::exp(a(i,j));
	return p;
}

//��Ԫ��ƽ��������
//���룺����a
//���������a��Ԫ��ƽ����
Matrix Matlab2c::sqrt(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::sqrt(a(i,j));
	return p;
}

//����Ԫ�س�0����ȡ��
//���룺ʵ����a
//���������Ԫ����0ȡ��
Matrix Matlab2c::fix(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for(i=0;i<p.row;i++)
		for(j=0;j<p.column;j++)
			p(i,j) = (int)(a(i,j)); //fix(x)���ص��ǿ���0������
	return p;
}


//����Ԫ�س��������ȡ��
//���룺ʵ����a
//���������Ԫ��������ȡ��
Matrix Matlab2c::floor(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for(i=0;i<p.row;i++)
		for(j=0;j<p.column;j++)
			p(i,j) = std::floor(a(i,j));
	return p;
}


//�����Ԫ����Ȼ������
//���룺����a������Ԫ�ش���0
//���������a����eΪ�׵Ķ���ֵ
Matrix Matlab2c::log(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::log(a(i,j));
	return p;
}

//�������������
//���룺����a������Ԫ�ش���0
//���������a����10Ϊ�׵Ķ���ֵ
Matrix Matlab2c::log10(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::log10(a(i,j));
	return p;
}


//�������
//���룺����ܸ���n��������ϵ���Ŀm
//����������Ŀ
int Matlab2c::nchoosek(int n,int m)
{
	Matlab2c::CheckLicense();
	int fenzi=1;
	int fenmu=1;
	int temp = n-m;
	for (;n>m;n--)
		fenzi = fenzi*n;
	for (;temp>0;temp--)
		fenmu = fenmu*temp;
	return fenzi/fenmu;
}



//�������к���
//���룺���ݾ���
//���������ֵ
Matrix Matlab2c::tan(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::tan(a(i,j));
	return p;
}
//�������к�����
//���룺����a
//���������a�ķ�����ֵ
Matrix Matlab2c::atan(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::atan(a(i,j));
	return p;
}

//����˫�����к�����
//���룺����a
//���������a��˫������ֵ
Matrix Matlab2c::tanh(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::tanh(a(i,j));
	return p;
}
//�������Һ���
//���룺����a
//���������a������ֵ
Matrix Matlab2c::sin(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::sin(a(i,j));
	return p;
}

//�������Һ�����
//���룺����a
//���������a�ķ�����ֵ
Matrix Matlab2c::asin(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::asin(a(i,j));
	return p;
}
//����˫�����Һ�����
//���룺����a
//���������a��˫������ֵ
Matrix Matlab2c::sinh(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::sinh(a(i,j));
	return p;
}


//�������Һ���
//���룺����a
//���������a������ֵ
Matrix Matlab2c::cos(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::cos(a(i,j));
	return p;
}

//�������Һ�����
//���룺����a
//���������a�ķ�����ֵ
Matrix Matlab2c::acos(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::acos(a(i,j));
	return p;
}


//����˫�����Һ���
//���룺���ݾ���
//�����˫������ֵ
Matrix Matlab2c::cosh(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = std::cosh(a(i,j));
	return p;
}








//�������׳�
//������Ϊ����ʱ����������Ľ׳�
int Matlab2c::factorial(int a)
{
	Matlab2c::CheckLicense();
	int d=1;
	for (;a>0;a--)
		d = d*a;
	return d;
}

//�����׳�
//������Ϊ����ʱ������һ��ͬ�ȴ�С�ľ���ÿ�������ϵ���Ϊ֮ǰ�����ĳ˻�
Matrix Matlab2c::factorial(Matrix& a)
{
	Matlab2c::CheckLicense();
	Matrix p(a.row,a.column);
	double d=1;
	for (int i=0;i<a.row*a.column;i++)
	{
		 d= d*a(i);
		 p(i)=d;
	}
	return p;
}