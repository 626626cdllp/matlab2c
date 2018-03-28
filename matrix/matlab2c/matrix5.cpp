#include "Matlab2c.h"
using namespace Matlab2c;


//���ذ���������������������Ϊ�������������л���1x1����
//����Ϊһ���������Ϊÿ�еĳ˻�����������һ��������
Matrix Matlab2c::prod(Matrix& a)
{
	Matlab2c::CheckLicense();
	double prod=1;
	if(a.row==1)  //�����ݾ���Ϊ������
	{
		Matrix p = Matrix(1,1);
		for (int j=0;j<a.column;j++)
			prod=prod*a.data[j];
		p.data[0] = prod;
		return p;
	}
	Matrix p = Matrix(1,a.column);
	for (int j=0;j<a.column;j++)
	{
		prod=1;
		for (int i=0;i<a.row;i++)
		{
			prod =prod*(a(i,j));
		}
		p.data[j]=prod;
	}
	return p;
}
CMatrix Matlab2c::prod(CMatrix& a)
{
	Matlab2c::CheckLicense();
	Complex prod=1;
	if(a.row==1)  //�����ݾ���Ϊ������
	{
		CMatrix p = CMatrix(1,1);
		for (int j=0;j<a.column;j++)
			prod=prod*a.data[j];
		p.data[0] = prod;
		return p;
	}
	CMatrix p = CMatrix(1,a.column);
	for (int j=0;j<a.column;j++)
	{
		prod=1;
		for (int i=0;i<a.row;i++)
		{
			prod =prod*(a(i,j));
		}
		p.data[j]=prod;
	}
	return p;
}

//�����ά���ۻ�����
//���ظ�ά���۳˻�������Ϊ���󣬷��ذ����ۻ����ˣ�����Ϊ���������ذ������ۻ����˽��
Matrix Matlab2c::cumprod(Matrix& a)  
{
	Matlab2c::CheckLicense();
	Matrix p(a.row,a.column);
	double prod=1;
	if(a.row==1)  //�����ݾ���Ϊ�������������ۻ�
	{
		for (int j=0;j<a.column;j++)
		{
			prod=prod*a.data[j];
			p.data[j]=prod;
		}
		return p;
	}
	for(int j=0;j<a.column;j++)
	{	
		prod=1;
		for (int i=0;i<a.row;i++)
		{
			prod =prod*a(i,j);
			p(i,j)=prod;
		}
	}
	return p;
}

CMatrix Matlab2c::cumprod(CMatrix& a)  
{
	Matlab2c::CheckLicense();
	CMatrix p(a.row,a.column);
	Complex prod=1;
	if(a.row==1)  //�����ݾ���Ϊ�������������ۻ�
	{
		for (int j=0;j<a.column;j++)
		{
			prod=prod*a.data[j];
			p.data[j]=prod;
		}
		return p;
	}
	for(int j=0;j<a.column;j++)
	{	
		prod=1;
		for (int i=0;i<a.row;i++)
		{
			prod =prod*a(i,j);
			p(i,j)=prod;
		}
	}
	return p;
}

//���������еļ���ƽ����������Ϊ������ʱ�����������ļ���ƽ����
//���룺����a
//���������a���еļ���ƽ����
//��ʾ�����ڼ���ƽ����Ҫ���������㣬���Ը�����˺��ֵ��ʱҪ��Ϊ����
Matrix Matlab2c::geomean(Matrix& a)
{
	Matlab2c::CheckLicense();
	double m=1;
	if(a.row==1)  //�����ݾ���Ϊ������
	{
		Matrix p=Matrix(1,1);
		for (int j=0;j<a.column;j++)
			m = m*a.data[j];
		p.data[0]=std::pow(m,1.0/a.column);
		return p;
	}
	Matrix p=Matrix(1,a.column);
	for (int j=0;j<a.column;j++)
	{
		m=1;
		for (int i=0;i<a.row;i++)
			m = m*(a(i,j));
		p.data[j]=std::pow(m,1.0/a.row);
	}
	return p;
}

CMatrix Matlab2c::geomean(CMatrix& a)
{
	Matlab2c::CheckLicense();
	Complex m=1;
	if(a.row==1)  //�����ݾ���Ϊ������
	{
		CMatrix p=CMatrix(1,1);
		for (int j=0;j<a.column;j++)
			m = m*a.data[j];
		p.data[0]=std::pow(m,1.0/a.column);
		return p;
	}
	CMatrix p=CMatrix(1,a.column);
	for (int j=0;j<a.column;j++)
	{
		m=1;
		for (int i=0;i<a.row;i++)
			m = m*(a(i,j));
		p.data[j]=std::pow(m,1.0/a.row);
	}
	return p;
}

//���������еĵ���ƽ����������Ϊ������ʱ�����������ĵ���ƽ����
//���룺����a
//���������a���еĵ���ƽ����
//��ʾ������������Ҫ�����Ԫ�ز���Ϊ0
Matrix Matlab2c::harmmean(Matrix& a)
{
	Matlab2c::CheckLicense();
	double m=0;
	if(a.row==1)  //�����ݾ���Ϊ������
	{
		Matrix p=Matrix(1,1);
		for (int j=0;j<a.column;j++)
			m +=1.0/(a.data[j]);
		p.data[0]=(double)a.column/m;
		return p;
	}
	Matrix p(1,a.column);
	for (int j=0;j<a.column;j++)
	{
		m=1;
		for (int i=0;i<a.row;i++)
			m +=1.0/(a(i,j));
		p.data[j]=(double)a.row/m;
	}
	return p;
}
CMatrix Matlab2c::harmmean(CMatrix& a)
{
	Matlab2c::CheckLicense();
	Complex m=0;
	if(a.row==1)  //�����ݾ���Ϊ������
	{
		CMatrix p=CMatrix(1,1);
		for (int j=0;j<a.column;j++)
			m +=1.0/(a.data[j]);
		p.data[0]=(Complex)a.column/m;
		return p;
	} 
	CMatrix p(1,a.column);
	for (int j=0;j<a.column;j++)
	{
		m=1;
		for (int i=0;i<a.row;i++)
			m +=1.0/(a(i,j));
		p.data[j]=(Complex)a.row/m;
	}
	return p;
}

//���ذ�����ͺ��������������Ϊ������ʱ�����к�
//����Ϊ����a�����Ϊ����a������ͺ󷵻�������p
Matrix Matlab2c::sum(Matrix& a)
{
	Matlab2c::CheckLicense();
	double sum=0;
	if(a.row==1)  //�����ݾ���Ϊ������
	{
		Matrix p=Matrix(1,1);
		for (int j=0;j<a.column;j++)
			sum+=a.data[j];
		p.data[0] = sum;
		return p;
	}

	Matrix p=Matrix(1,a.column);
	for (int j=0;j<a.column;j++)
	{
		sum=0;
		for (int i=0;i<a.row;i++)
			sum +=a(i,j);
		p.data[j]=sum;
	}
	return p;
}
CMatrix Matlab2c::sum(CMatrix& a)
{
	Matlab2c::CheckLicense();
	Complex sum=0;
	if(a.row==1)  //�����ݾ���Ϊ������
	{
		CMatrix p=CMatrix(1,1);
		for (int j=0;j<a.column;j++)
			sum+=a.data[j];
		p.data[0] = sum;
		return p;
	}

	CMatrix p=Matrix(1,a.column);
	for (int j=0;j<a.column;j++)
	{
		sum=0;
		for (int i=0;i<a.row;i++)
			sum +=a(i,j);
		p.data[j]=sum;
	}
	return p;
}


//�����ظ�ά��˳���ۼӺͣ�����Ϊ�������������ۼ����
//���룺����a
//���������a���и�ά�ȵ��ۼ�ֵ��
//��ʾ������ֵ��С����������С��ȡ�
Matrix Matlab2c::cumsum(Matrix& a) 
{
	Matlab2c::CheckLicense();
	Matrix p(a.row,a.column);
	double sum=0;
	if(a.row==1)  //�����ݾ���Ϊ������
	{
		for (int j=0;j<a.column;j++)
		{
			sum+=a.data[j];
			p.data[j]=sum;
		}
		return p;
	}
	for (int j=0;j<p.column;j++)
	{
		sum=0;
		for (int i=0;i<p.row;i++)
		{
			sum+=(a(i,j));
			p(i,j)=sum;
		}
	}
	return p;
}
CMatrix Matlab2c::cumsum(CMatrix& a) 
{
	Matlab2c::CheckLicense();
	CMatrix p(a.row,a.column);
	Complex sum=0;
	if(a.row==1)  //�����ݾ���Ϊ������
	{
		for (int j=0;j<a.column;j++)
		{
			sum+=a.data[j];
			p.data[j]=sum;
		}
		return p;
	}
	for (int j=0;j<p.column;j++)
	{
		sum=0;
		for (int i=0;i<p.row;i++)
		{
			sum+=(a(i,j));
			p(i,j)=sum;
		}
	}
	return p;
}