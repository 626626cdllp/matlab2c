#include "Matlab2c.h"
using namespace Matlab2c;

//����������Ԫ��Ϊ�Խ�Ԫ�صľ���
//����Ϊ�������������������Ϊ�Ը�����Ϊ�Խ��ߵľ���
Matrix Matlab2c::blkdiag(Matrix& a)
{
	Matlab2c::CheckLicense();
	Matrix p(a.row*a.column,a.row*a.column);
	for (int i=0;i<p.row;i++)
		for (int j=0;j<p.column;j++)
		{
			if (i==j)
				p(i,j)=a(j);
			else
				p(i,j)=0;
		}
	return p;
}

//����ʽϵ��������Ѿ���
//����Ϊ����ʽ��ϵ�����������Ϊ�ö���ʽ���Ѿ���
Matrix Matlab2c::compan(Matrix& a)
{
	Matlab2c::CheckLicense();
	if(a.row!=1)
		throw_logic_error("����ʽϵ������������Ϊ1");
	Matrix p(a.column-1,a.column-1);
	if(Matlab2c::FloatNotEqual(a(0),0))
		for (int i=0;i<p.row;i++)
			for (int j=0;j<p.column;j++)
			{
				if(i==0)
					p(j)=(a(j+1)/a(0));
				else if (i-j==1)
					p(i,j) =1;
				else
					p(i,j) =0;
			}
	else
		throw_logic_error("������һ��Ԫ��Ϊ0������");
	return p;
}

//���ɵ�λ����
//���뵥λ�����ά���������Ӧ��С�ĵ�λ����
Matrix Matlab2c::eye(int n)
{
	Matlab2c::CheckLicense();
	int i=0,j=0;
	Matrix a(n,n);
	for (i=0;i<a.row;i++)
		for (j=0;j<a.column;j++)
			if (i==j)
				a(i,j)=1;
			else
				a(i,j)=0;
	return a;
}
Matrix Matlab2c::eye(int row,int column)
{
	Matlab2c::CheckLicense();
	int i=0,j=0;
	Matrix a(row,column);
	for (i=0;i<a.row;i++)
		for (j=0;j<a.column;j++)
			if (i==j)
				a(i,j)=1;
			else
				a(i,j)=0;
	return a;
}

//����Hankel����
//����Ϊ���������������Ϊ��Hankel����
Matrix Matlab2c::hankel(Matrix& a,Matrix& b)
{
	Matlab2c::CheckLicense();
	Matrix p(a.column,b.column);
	int i,j;
	if (a(a.column-1)!=b(0))
	{
		throw_logic_error("��һ���������һ��Ԫ�غ͵ڶ���������һ��Ԫ�ز����");
	}
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			if ((i+j)<(a.column))
				p(i,j)=a(i+j);
			else
				p(i,j)=b(i+j+1-a.column);
	return p;
}
Matrix Matlab2c::hankel(Matrix& a)
{
	Matrix p(a.column,a.column);
	int i,j;
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			if ((i+j)<(a.column))
				p(i,j)=a(i+j);
			else
				p(i,j)=0;
	return p;
}

//����Hilbert(ϣ������)����
//����Ϊ�����ά���������Ӧ��С��Hilbert����
Matrix Matlab2c::hilb(int n)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(n,n);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j)=1.0/(i+j+1);
	return p;
}


//����ȫ1����
//����:���������������
//���:��Ӧ��С��ȫ1����
Matrix Matlab2c::ones(int n)
{
	Matlab2c::CheckLicense();
	int i=0,j=0;
	Matrix a(n,n);
	for (i=0;i<a.row*a.column;i++)
		a.data[i]=1;
	return a;
}
Matrix Matlab2c::ones(int row,int column)
{
	Matlab2c::CheckLicense();
	int i=0,j=0;
	Matrix a(row,column);
	for (i=0;i<a.row*a.column;i++)
			a.data[i]=1;
	return a;
}

//����Pascal����
//����Ϊ�����ά���������Ӧ��С��Pascal����
Matrix Matlab2c::pascal(int n)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(n,n);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			if(i==0)
				p(i,j) =1;
			else if (j==0)
				p(i,j) =1;
			else
				p(i,j) =p(i-1,j)+p(i,j-1);
	return p;
}


//�����������Ⱦ���
//a��Ϊ����ĵ�һ�У�b��Ϊ����ĵ�һ�У���Ԫ��Ҫ����ȣ�������Ӧ���������Ⱦ���
Matrix Matlab2c::toeplitz(Matrix& a,Matrix& b)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.column*a.row,b.column*b.row);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			if(j==0)
				p(i,j)=a(i);
			else if (i==0)
				p(i,j) =b(j);
			else
				p(i,j) =p(i-1,j-1);
	return p;
}


//����Wilkinson����ֵ������
//����Ϊ�����ά���������Ӧ��С��Wilkinson����
Matrix Matlab2c::wilkinson(int n)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(n,n);
	if (n==1)
		p.data[0]=0;
	else if (n>1)
	{
		if (n%2==0)
		{
			for (i=0;i<p.row;i++)
				for (j=0;j<p.column;j++)
					if (i-j==1 || j-i==1)
						p(i,j) = 1;
					else if(i==j)
						p(i,j) =std::fabs((n-1)/2-i+0.5);
					else
						p(i,j) =0;
		}
		else
		{
			for (i=0;i<p.row;i++)
				for (j=0;j<p.column;j++)
					if (i-j==1 || j-i==1)
						p(i,j) = 1;
					else if(i==j)
						p(i,j) =std::abs(n/2-i);
					else
						p(i,j) =0;
		}
	}
	return p;
}

//�����������
//������������Ԫ��(һ������aһ������b)���ܵĳ˻�
Matrix Matlab2c::kron(Matrix& a,Matrix& b)
{
	Matlab2c::CheckLicense();
	Matrix p(a.row*b.row,a.column*b.column);
	for (int i=0;i<a.row;i++)
		for (int j=0;j<a.column;j++)
			for (int ii=0;ii<b.row;ii++)
				for (int jj=0;jj<b.column;jj++)
				{
					//��i*b.row+ii����j*b.column+jj
					p(i*b.row+ii,j*b.column+jj)=a(i,j)*b(ii,jj);
				}
	return p;
}

//���������
//����Ϊ����������������������Ӧ��С�������
Matrix Matlab2c::zeros(int n)
{
	Matlab2c::CheckLicense();
	int i=0,j=0;
	Matrix p(n,n);
	for (i=0;i<p.row*p.column;i++)
		p(i)=0;
	return p;
}
 Matrix Matlab2c::zeros(int row,int column)
{
	Matlab2c::CheckLicense();
	int i=0,j=0;
	Matrix p(row,column);
	for (i=0;i<p.row*p.column;i++)
			p(i)=0;
	return p;
}



//��ȡ�������
//���룺ԭ����a����ȡ����ʼ��n1����ֹ��n2
//	������������a�ĵ�n1�е�n2��(������n2��)��ԭ���󲻸ı�
//	��ʾ��n1��n2��1��ʼ�����±�ͬmatlabʹ����ͬ
Matrix Matlab2c::get_2column(Matrix& a,int n1,int n2)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,n2-n1+1);
	for (i=0;i<p.row;i++)
		for(j=n1-1;j<n2+1;j++)
			p(i,j-n1+1)=a(i,j);
	return p;
}


//��ȡ������У��±�ͬmatlabʹ�ã���1��ʼ
//���룺ԭ����a����ȡ����ʼ��m1����ֹ��m2
//	������������a�ĵ�m1�е�m2��(������m2��)��ԭ���󲻸ı�
//	��ʾ��m1��m2��1��ʼ�����±�ͬmatlabʹ����ͬ
Matrix Matlab2c::get_2row(Matrix& a,int m1,int m2)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(m2-m1+1,a.column);
	for(i=m1-1;i<m2+1;i++)
		for(j=0;j<p.column;j++)
			p(i-m1+1,j)=a(i,j);
	return p;
}


//��ȡ����ָ����
//���룺Դ����a��Ҫ��ȡ������n
//	�����Դ����a�ĵ�n��
//	��ʾ��ֱ�Ӱ�matlab������±귽ʽ���á�n��1��ʼ
Matrix Matlab2c::get_column(Matrix& a,int n)
{
	Matlab2c::CheckLicense();
	int i;
	Matrix p(a.row,1);
	for (i=0;i<a.row;i++)
		p.data[i]=a(i,n-1); 
	return p;
}

//��ȡ����ָ���У��±�ͬmatlab����1��ʼ
//���룺Դ����a��Ҫ��ȡ������m
//	�����Դ����a�ĵ�m��
//	��ʾ��ֱ�Ӱ�matlab������±귽ʽ���á�m��1��ʼ
Matrix Matlab2c::get_row(Matrix& a,int m)
{
	Matlab2c::CheckLicense();
	int j;
	Matrix p(1,a.column);
	for (j=0;j<a.column;j++)
		p.data[j]=a(m-1,j);
	return p;
}


//������и�ֵ
//���룺Դ����yuan��Ҫ��ֵ�ľ���fu��Ҫ��ֵ������n1��n2
//��ʾ��ֱ�Ӱ�matlab������±귽ʽ���á�n��1��ʼ
void Matlab2c::set_2column(Matrix& yuan,Matrix& fu, int n1,int n2)
{
	Matlab2c::CheckLicense();
	int i,j;
	for (i=0;i<yuan.row;i++)
		for(j=n1;j<n2+1;j++)
			yuan(i,j)=fu(i,j-n1);
}

//ָ�����и�ֵ
//���룺Դ����yuan��Ҫ��ֵ�ľ���fu��Ҫ��ֵ����m1 ����m2
//��ʾ��ֱ�Ӱ�matlab������±귽ʽ���á�m��1��ʼ
void Matlab2c::set_2row(Matrix& yuan,Matrix& fu, int m1,int m2)
{
	Matlab2c::CheckLicense();
	int i,j;
	for(i=m1;i<m2+1;i++)
		for (j=0;j<yuan.column;j++)
			yuan(i,j)=fu(i-m1,j);
}


//ָ���и�ֵ
//���룺Դ����yuan��Ҫ��ֵ�ľ���fu��Ҫ��ֵ������n
//	��ʾ��ֱ�Ӱ�matlab������±귽ʽ���á�n��1��ʼ
void Matlab2c::set_column(Matrix& yuan,Matrix& fu, int n)
{
	Matlab2c::CheckLicense();
	int i;
	for (i=0;i<yuan.row;i++)
		yuan(i,n)=fu.data[i];
}


//ָ���и�ֵ
//���룺Դ����yuan��Ҫ��ֵ�ľ���fu��Ҫ��ֵ������m
//	��ʾ��ֱ�Ӱ�matlab������±귽ʽ���á�m��1��ʼ
void Matlab2c::set_row(Matrix& yuan,Matrix& fu, int m)
{
	Matlab2c::CheckLicense();
	int j;
	for (j=0;j<yuan.column;j++)
		yuan(m-1,j)=fu.data[j];
}

//ɾ���������
//���룺ԭ����a��Ҫɾ�����������n1��Ҫɾ�������յ�n2���±��1��ʼ
//	�����ԭ����aɾ����n1��n2��ľ��󡣰���ɾ��n2��
//	��ʾ���������ı�ԭ�����±�ͬmatlab��ɾ���а���n1��n2
Matrix Matlab2c::del_2column(Matrix& a,int n1,int n2)
{
	Matlab2c::CheckLicense();
	int i,j,d=0;
	Matrix p(a.row,a.column-n2+n1-1);
	for (j=0;j<a.column;j++)
		if (j<n1-1 || j>=n2)
		{
			for (i=0;i<a.row;i++)
				p(i,d)=a(i,j);
			d++;
		}
		return p;
}


//ɾ���������
//���룺ԭ����a��Ҫɾ�����������m1��Ҫɾ�������յ�m2���±��1��ʼ
//	�����ԭ����aɾ����m1��m2��ľ���ɾ��m2��
//	��ʾ���������ı�ԭ�����±�ͬmatlab��ɾ���а���m1��m2
Matrix Matlab2c::del_2row(Matrix& a,int m1,int m2)
{
	Matlab2c::CheckLicense();
	int i,j,d=0;
	Matrix p(a.row-m2+m1-1,a.column);
	for (i=0;i<a.row;i++)
		if (i<m1-1 || i>=m2)
		{
			for (j=0;j<a.column;j++)
				p(d,j)=a(i,j);
			d++;
		}
		return p;
}


//ɾ������ָ����
//���룺ԭ����a��Ҫɾ��������n��nȡֵͬmatlab����1��ʼ
//	���������aɾ����n�к��µľ���
//	��ʾ���������ı����ԭ������
Matrix Matlab2c::del_column(Matrix& a,int n)
{
	Matlab2c::CheckLicense();
	int i,j,d=0;
	Matrix p(a.row,a.column-1);
	for (j=0;j<a.column;j++)
		if (j!=n-1)
		{
			for (i=0;i<a.row;i++)
				p(i,d)=a(i,j);
			d++;
		}
		return p;
}



//ɾ������ָ����
//���룺ԭ����a��Ҫɾ��������m��mȡֵͬmatlab����1��ʼ
//	���������aɾ����m�к��µľ���
//	��ʾ���������ı����ԭ������
Matrix Matlab2c::del_row(Matrix& a,int m)
{
	Matlab2c::CheckLicense();
	int i,j,d=0;
	Matrix p(a.row-1,a.column);
	for (i=0;i<a.row;i++)
		if (i!=m-1)
		{
			for (j=0;j<a.column;j++)
				p(d,j)=a(i,j);
			d++;
		}
		return p;
}


//ͬʱɾ������ָ���к�ָ����
//���룺ԭ����a��Ҫͬʱɾ��������m������n
//	�����ԭ����aɾ����m�У���n�к�ľ���
//	��ʾ��m��n�±��1��ʼ���������ı�ԭ��������
Matrix Matlab2c::del_row_column(Matrix& a,int rowsnum,int columnsnum)
{
	Matlab2c::CheckLicense();
	int i=0,j;
	int rownow = rowsnum-1,columnnow = columnsnum-1;
	Matrix p(a.row-1,a.column-1);
	while(i<rownow)
	{ 
		j=0;
		while(j<columnnow)
		{
			p(i,j)=a(i,j);
			j++;
		}
		j++;
		while(j>columnnow&&j<a.column)
		{
			p(i,j)=a(i,j); 
			j++;
		}
		i++;
	}
	i++;
	while(i>rownow&&i<a.row)
	{
		j=0;
		while(j<columnnow)
		{
			p(i-1,j)=a(i,j);
			j++;
		}
		j++;
		while(j>columnnow&&j<a.column)
		{
			p(i-1,j-1)=a(i,j); 
			j++;
		}
		i++;
	}
	return p;

}


//���Һϲ�����
//���룺����a,b
//	���������a��b���Һϲ�֮��ľ���
//	��ʾ���������ı�ԭ��������
Matrix Matlab2c::left_right(Matrix& a,Matrix& b)
{
	Matlab2c::CheckLicense();
	Matrix c(a.row,a.row+a.column);
	int i,j;
	for (i=0;i<a.row;i++)
	{
		for (j=0;j<a.column;j++)
			c(i,j)=a(i,j);
		for (j=0;j<b.column;j++)
			c(i,j+a.column)=b(i,j);
	}
	return c;
}



//���ºϲ�����
//���룺����a,b
//	���������a��b���ºϲ�֮��ľ���
//	��ʾ���������ı�ԭ��������
Matrix Matlab2c::up_down(Matrix& a,Matrix& b)
{
	Matlab2c::CheckLicense();
	Matrix c(a.row+a.column,a.column);
	int i,j;
	for (i=0;i<a.row;i++)
		for (j=0;j<a.column;j++)
			c(i,j)=a(i,j);
	for (i=0;i<b.row;i++)
		for (j=0;j<b.column;j++)
			c(i,j+a.row*a.column)=b(i,j);
	return c;
}

//�����б�ά
//�����б�ά������Ϊ����a���Լ���Ҫ�任��ά��m��n�����Ϊ�������ŵ�m*n���󡣾����ά�����к���
Matrix  Matlab2c::reshape(Matrix& a,int row,int column)
{
	Matlab2c::CheckLicense();
	if (row*column<=a.row*a.column)
	{
		Matrix p(row,column);
		for (int j=0;j<p.column;j++)
			for (int i=0;i<p.row;i++)
				p(i,j)=a((j*p.row+i)%a.row,(j*p.row+i)/a.row);
		return p;
	}
	else
	{
		throw_logic_error("�����άʱ���ݲ���");
		return NULL;
	}
}
CMatrix  Matlab2c::reshape(CMatrix& a,int row,int column)
{
	Matlab2c::CheckLicense();
	if (row*column<=a.row*a.column)
	{
		CMatrix p(row,column);
		for (int j=0;j<p.column;j++)
			for (int i=0;i<p.row;i++)
				p(i,j)=a((j*p.row+i)%a.row,(j*p.row+i)/a.row);
		return p;
	}
	else
	{
		throw_logic_error("�����άʱ���ݲ���");
		return NULL;
	}
}
