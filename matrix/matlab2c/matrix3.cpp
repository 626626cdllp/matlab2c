#include "Matlab2c.h"
using namespace Matlab2c;


//����Խ���Ԫ�صĳ�ȡ�͸��ݶԽ�Ԫ�����ɾ���
//X = diag(v,k)��v��һ������n��Ԫ�ص�����ʱ������һ��n+abs(k)�׷���X������v�ھ���X�еĵ�k���Խ����ϣ�k=0��ʾ���Խ��ߣ�k>0��ʾ�����Խ����Ϸ���k<0��ʾ�����Խ����·���
//v = diag(X,k)����������v��v�ɾ���X�ĵ�k���Խ����ϵ�Ԫ���γ�
Matrix Matlab2c::diag(Matrix& a,int n)
{ 
	Matlab2c::CheckLicense();
	Matrix p;
	int p_row;
	int index=0;
	//�����������ɾ���
	if (a.isVector())
	{
		p_row =a.row*a.column+std::abs(n);
		p=Matrix(p_row,p_row);
		for (int i=0;i<p.row;i++)
			for (int j=0;j<p.column;j++)
				if (j-i==n)
					p(i,j)=a(index++);
				else
					p(i,j)=0;
		return p;
	}
	//���ݾ�����ȡ�Խ�Ԫ��
	else
	{
		p.column =1;
		if (n>0)
			p.row=std::min(a.column-n,a.row);
		else
			p.row=std::min(a.column,a.row+n);
		p.data=new double[p.row*p.column];
		for (int i=0;i<a.row;i++)
			for (int j=0;j<a.column;j++)
				if (j-i==n)
					p(index++) = a(i,j);	
		return p;
	}
}
Matrix Matlab2c::diag(Matrix& a)
{ 
	Matlab2c::CheckLicense();
	return diag(a,0);
}
CMatrix Matlab2c::diag(CMatrix& a,int n)
{ 
	Matlab2c::CheckLicense();
	CMatrix p;
	int p_row;
	int index=0;
	//�����������ɾ���
	if (a.isVector())
	{
		p_row =a.row*a.column+std::abs(n);
		p=CMatrix(p_row,p_row);
		for (int i=0;i<p.row;i++)
			for (int j=0;j<p.column;j++)
				if (j-i==n)
					p(i,j)=a(index++);
				else
					p(i,j)=0;
		return p;
	}
	//���ݾ�����ȡ�Խ�Ԫ��
	else
	{
		p.column =1;
		if (n>0)
			p.row=std::min(a.column-n,a.row);
		else
			p.row=std::min(a.column,a.row+n);
		p.data=new Complex[p.row*p.column];
		for (int i=0;i<a.row;i++)
			for (int j=0;j<a.column;j++)
				if (j-i==n)
					p(index++) = a(i,j);	
		return p;
	}
}
CMatrix Matlab2c::diag(CMatrix& a)
{ 
	Matlab2c::CheckLicense();
	return diag(a,0);
}
//�������ҷ�ת
//�������ҷ�ת������Ϊһ���������Ϊ�þ������ҷ�ת��ľ���
//���A��һ����������fliplr(A)��A��Ԫ�ص�˳����з�ת�� ���A��һ����������fliplr(A)������A��
Matrix Matlab2c::fliplr(Matrix& a)
{
	Matlab2c::CheckLicense();
	Matrix p(a.row,a.column);
	double temp;
	for (int i=0;i<p.row;i++)
		for (int j=0;j<(p.column-1)/2+1;j++)
		{
			temp = a(i,j);
			p(i,j) = a(i,a.column-j-1);
			p(i,p.column-j-1) = temp;
		}
	return p;
}
CMatrix Matlab2c::fliplr(CMatrix& a)
{
	Matlab2c::CheckLicense();
	CMatrix p(a.row,a.column);
	Complex temp;
	for (int i=0;i<p.row;i++)
		for (int j=0;j<(p.column-1)/2+1;j++)
		{
			temp = a(i,j);
			p(i,j) = a(i,a.column-j-1);
			p(i,p.column-j-1) = temp;
		}
		return p;
}

//�������·�ת
//�������·�ת������Ϊһ���������Ϊ�þ������·�ת��ľ�����AΪ����������BΪ����A����AΪ����������B����A
Matrix Matlab2c::flipud(Matrix& a)
{
	Matlab2c::CheckLicense();
	Matrix p(a.row,a.column);
	double temp;
	for (int i=0;i<(p.row-1)/2+1;i++)
	{
		for (int j=0;j<p.column;j++)
		{
			temp = a(i,j);
			p(i,j) = a(a.row-1-i,j);
			p(p.row-1-i,j) = temp;
		}
	}
	return p;
}
CMatrix Matlab2c::flipud(CMatrix& a)
{
	Matlab2c::CheckLicense();
	CMatrix p(a.row,a.column);
	Complex temp;
	for (int i=0;i<(p.row-1)/2+1;i++)
	{
		for (int j=0;j<p.column;j++)
		{
			temp = a(i,j);
			p(i,j) = a(a.row-1-i,j);
			p(p.row-1-i,j) = temp;
		}
	}
	return p;
}






//���ƺ�ƽ�̾���
//���ƺ�ƽ�̾�������Ϊһ������a���Լ���������m��n�������aΪԪ�ص�m*n����Ͼ���
Matrix Matlab2c::repmat(Matrix& a,int m,int n)
{
	Matlab2c::CheckLicense();
	Matrix p(a.row*m,a.column*n);
	int i,j;
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j)=a(i%a.row,j%a.column);
	return p;
}
CMatrix Matlab2c::repmat(CMatrix& a,int m,int n)
{
	Matlab2c::CheckLicense();
	CMatrix p(a.row*m,a.column*n);
	int i,j;
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j)=a(i%a.row,j%a.column);
	return p;
}


//������ʱ����ת
//������ʱ����ת������Ϊһ��������ת�Ƕȣ�0����ת��1��ʱ����ת90�ȣ�2��ʱ����ת180�ȣ�3��ʱ����ת270�ȣ���
Matrix Matlab2c::rot90(Matrix& a,int n)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p;
	if (n%4==0)
	{
		p=a;
		return p;
	}
	else if (n%4==1)
	{
		p=Matrix(a.column,a.row);
		for (i=0;i<a.row;i++)
			for (j=0;j<a.column;j++)
				p(p.row-1-j,i) = a(i,j);
	}
	else if (n%4==2)
	{
		p=Matrix(a.row,a.column);
		for (i=0;i<a.row;i++)
			for (j=0;j<a.column;j++)
				p(p.row-1-i,p.column-1-j) = a(i,j);
	}
	else if (n%4==3)
	{
		p=Matrix(a.column,a.row);
		for (i=0;i<a.row;i++)
			for (j=0;j<a.column;j++)
				p(j,p.column-1-i) = a(i,j);
	}
	return p;
}
Matrix Matlab2c::rot90(Matrix& a)
{
	Matlab2c::CheckLicense();
	return rot90(a,1);
}
CMatrix Matlab2c::rot90(CMatrix& a,int n)
{
	Matlab2c::CheckLicense();
	int i,j;
	CMatrix p;
	if (n%4==0)
	{
		p=a;
		return p;
	}
	else if (n%4==1)
	{
		p=CMatrix(a.column,a.row);
		for (i=0;i<a.row;i++)
			for (j=0;j<a.column;j++)
				p(p.row-1-j,i) = a(i,j);
	}
	else if (n%4==2)
	{
		p=CMatrix(a.row,a.column);
		for (i=0;i<a.row;i++)
			for (j=0;j<a.column;j++)
				p(p.row-1-i,p.column-1-j) = a(i,j);
	}
	else if (n%4==3)
	{
		p=CMatrix(a.column,a.row);
		for (i=0;i<a.row;i++)
			for (j=0;j<a.column;j++)
				p(j,p.column-1-i) = a(i,j);
	}
	return p;
}
CMatrix Matlab2c::rot90(CMatrix& a)
{
	Matlab2c::CheckLicense();
	return rot90(a,1);
}

//��ȡ����������
//����Ϊһ���������Ϊ�þ���������Ǿ��󣬰����Խ�Ԫ�أ����Բ��Ƿ���
Matrix Matlab2c::tril(Matrix& a)
{
	Matlab2c::CheckLicense();
	Matrix p(a.row,a.column);
	for (int i=0;i<a.row;i++)
		for (int j=0;j<a.column;j++)
			if (i>=j)
				p(i,j) = a(i,j);
			else
				p(i,j) =0;
	return p;
}
CMatrix Matlab2c::tril(CMatrix& a)
{
	Matlab2c::CheckLicense();
	CMatrix p(a.row,a.column);
	for (int i=0;i<a.row;i++)
		for (int j=0;j<a.column;j++)
			if (i>=j)
				p(i,j) = a(i,j);
			else
				p(i,j) =0;
	return p;
}


//��ȡ����������
//����Ϊһ���������Ϊ�þ���������Ǿ��󣬰����Խ�Ԫ�أ����Բ��Ƿ���
Matrix Matlab2c::triu(Matrix& a)
{
	Matlab2c::CheckLicense();
	Matrix p(a.row,a.column);
	for (int i=0;i<a.row;i++)
		for (int j=0;j<a.column;j++)
			if (i<=j)
				p(i,j) = a(i,j);
			else
				p(i,j) =0;
	return p;
}
CMatrix Matlab2c::triu(CMatrix& a)
{
	Matlab2c::CheckLicense();
	CMatrix p(a.row,a.column);
	for (int i=0;i<a.row;i++)
		for (int j=0;j<a.column;j++)
			if (i<=j)
				p(i,j) = a(i,j);
			else
				p(i,j) =0;
	return p;
}

//����ϲ�
//Ŀǰ֧����ά�ϲ���dim=1���������ϲ��ȼ���[a,b]��dim=2��������ϲ��ȼ���[a;b]
Matrix Matlab2c::cat(int dim,Matrix& a,Matrix& b)
{
	Matlab2c::CheckLicense();
	Matrix p(a);
	switch (dim)
	{
	case 1:
		p.append_bottom(b);
		return p;
	case 2:
		p.append_right(b);
		return p;
	default:
		p.append_bottom(b);
		return p;
	}
}
CMatrix Matlab2c::cat(int dim,CMatrix& a,CMatrix& b)
{
	Matlab2c::CheckLicense();
	CMatrix p(a);
	switch (dim)
	{
	case 1:
		p.append_bottom(b);
		return p;
	case 2:
		p.append_right(b);
		return p;
	default:
		p.append_bottom(b);
		return p;
	}
}