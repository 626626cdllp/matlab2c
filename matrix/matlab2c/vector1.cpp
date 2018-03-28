#include "Matlab2c.h"
using namespace Matlab2c;

//��������
//���룺Ҫ���������ָ�룬���ݵĸ���num
//	�������С��С����������ָ�롣
//	��ʾ�������ı�ԭ����
void Matlab2c::Q_sort(Matrix& a)  //�ı�ԭ������
{
	Matlab2c::CheckLicense();
	Q_sort(a.data,a.row*a.column);
}
void Matlab2c::Q_sort(double *a,int num)  //�ı�ԭ������
{
	Matlab2c::CheckLicense();
	int i=0;
	int j=num-1;
	double key=*a;
	if (num>1)
	{
		while(i!=j)
		{
			for (;i<j;j--)
				if (*(a+j)<key)
				{
					*(a+i)=*(a+j);
					break;
				}
				for (;i<j;i++)
					if (*(a+i)>key)
					{
						*(a+j)=*(a+i);
						break;
					}
					*(a+i)=key;
		}
		Q_sort(a,i);
		Q_sort(a+i+1,num-i-1);
	}
}


//ѡ������
//���룺����
//	���������������������
//	��ʾ�������ı�ԭ����
void Matlab2c::C_sort(Matrix& a)   //�ı�ԭ������
{
	Matlab2c::CheckLicense();
	int i,j,k;
	double temp; 
	int n=a.row*a.column;
	for(i=0;i<n-1;i++) 
	{ 
		k=i;                                       //���ǺŸ�ֵ
		for(j=i+1;j<n;j++) 
			if(a.data[k]>a.data[j]) 
				k=j;                               //��k����ָ����СԪ��
		if(i!=k) 
		{                                          //��k!=i�ǲŽ���������a[i]��Ϊ��С
			temp=a.data[i]; 
			a.data[i]=a.data[k]; 
			a.data[k]=temp; 
		} 
	} 
}
//������
//��ÿһ�а���������
Matrix Matlab2c::sort(Matrix& a)   
{
	Matlab2c::CheckLicense();
	Matrix p(a.row,a.column);
	for (int j=0;j<a.column;j++)
	{
		vector<double> lie(a.row);
		for (int i=0;i<a.row;i++)
			lie[i]=a(i,j);
		std::sort(begin(lie),end(lie));	  //��vector����ϵͳ�����������
		for (int i=0;i<p.row;i++)
			p(i,j)=lie[i];	
	}
	return p;
}
//��ÿһ�л�ÿһ�а��������򣬲��ı�Դ����
Matrix Matlab2c::sort(Matrix& a,int dim)
{
	Matlab2c::CheckLicense();
	Matrix p(a.row,a.column);
	if (dim==1)
	{
		for (int j=0;j<a.column;j++)
		{
				vector<double> lie(a.row);
				for (int i=0;i<a.row;i++)
					lie[i]=a(i,j);

				std::sort(begin(lie),end(lie));	  //��vector����ϵͳ�����������
				for (int i=0;i<p.row;i++)
					p(i,j)=lie[i];	
		}
	}
	else if(dim==2){
		for (int i=0;i<a.row;i++)
		{
			vector<double> lie(a.column);
			for (int j=0;j<a.column;j++)
				lie[j]=a(i,j);

			std::sort(begin(lie),end(lie));	  //��vector����ϵͳ�����������
			for (int j=0;j<p.column;j++)
				p(i,j)=lie[j];	
		}
	}
	return p;
}
//��ÿһ�а���������򰴽�������
Matrix Matlab2c::sort(Matrix& a,string mode)
{
	Matlab2c::CheckLicense();
	string mode1;
	transform(mode.begin(),mode.end(),back_inserter(mode1),::tolower);
	Matrix p(a.row,a.column);
	for (int j=0;j<a.column;j++)
	{
		vector<double> lie(a.row);
		for (int i=0;i<a.row;i++)
			lie[i]=a(i,j);

		std::sort(begin(lie),end(lie));	  //��vector����ϵͳ�����������
		if(mode1=="ascend")
			for (int i=0;i<p.row;i++)
				p(i,j)=lie[i];	
		else if(mode1=="descend")
			for (int i=0;i<p.row;i++)
				p(i,j)=lie[p.row-i-1];	
	}
	return p;
}
//��ÿһ�л�ÿһ�а���������򰴽�������
Matrix Matlab2c::sort(Matrix& a,int dim,string mode)
{
	Matlab2c::CheckLicense();
	string mode1;
	transform(mode.begin(),mode.end(),back_inserter(mode1),::tolower);
	Matrix p(a.row,a.column);
	if (dim==1)
	{
		for (int j=0;j<a.column;j++)
		{
			vector<double> lie(a.row);
			for (int i=0;i<a.row;i++)
				lie[i]=a(i,j);

			std::sort(begin(lie),end(lie));	  //��vector����ϵͳ�����������
			if(mode1=="ascend")
				for (int i=0;i<p.row;i++)
					p(i,j)=lie[i];	
			else if(mode1=="descend")
				for (int i=0;i<p.row;i++)
					p(i,j)=lie[p.row-i-1];	
		}
	}
	else if(dim==2){
		for (int i=0;i<a.row;i++)
		{
			vector<double> lie(a.column);
			for (int j=0;j<a.column;j++)
				lie[j]=a(i,j);

			std::sort(begin(lie),end(lie));	  //��vector����ϵͳ�����������
			if(mode1=="ascend")
				for (int j=0;j<p.column;j++)
					p(i,j)=lie[j];	
			else if(mode1=="descend")
				for (int j=0;j<p.column;j++)
					p(i,j)=lie[p.column-j-1];	
		}
	}
	return p;
}

//���з�ʽ����
//AΪ���󣬷��ؾ���Y��Y��A�ĵ�1����С�������з�ʽ��������ɵľ���
//��ָ����col��С�����������,colĬ��Ϊ0
Matrix Matlab2c::sortrows(Matrix& a,int col)
{
	Matlab2c::CheckLicense();
	Matrix sorttemp=a(0,a.row-1,col,col);
	sorttemp = Matlab2c::sort(sorttemp);
	Matrix flag(a.row,1,0.0);  //��¼��ǰ���Ƿ��ѱ�ռ��
	Matrix p(a.row,a.column);
	for (int i=0;i<a.row;i++)   //����������ǰ�ı���
		for(int ii=0;ii<sorttemp.row;ii++)   //�����������ı���
			if (a(i,col)==sorttemp(ii) && flag(ii)==0)
			{
				flag(ii)=1;
				for (int t = 0; t < a.column; t++)
					p(ii,t)=a(i,t);   //����i�в��õ���ii��
				break;
			}
	return p;
}


//��������ɢ�����������㣬����ʽ�˷�
//���룺�������������߶���ʽ��������������ݺ��������ķ���
//�����������ɢ���������������㣬���߶���ʽ�˷��Ľ��
Matrix Matlab2c::conv(Matrix& a,Matrix& b)
{
	Matlab2c::CheckLicense();
	if(!(a.isVector() && b.isVector()))
		throw_logic_error("�����������Ϊ����");
	int i,k;
	double m;
	Matrix p;
	if (b.row==1)
	{
		p.row=1;
		p.column = a.row*a.column+b.row*b.column-1;
	}else{
		p.column=1;
		p.row = a.row*a.column+b.row*b.column-1;
	}

	p.data = new double[p.row*p.column];
	for (k=0;k<p.row*p.column;k++)
	{
		m=0;
		for (i=0;i<a.row*a.column;i++)
			if ((k-i)>-1 && (k-i)<b.row*b.column)
				m+=(a.data[i])*(b.data[k-i]);
		p.data[k]=m;
	}
	return p;
}
CMatrix Matlab2c::conv(CMatrix& a,CMatrix& b)
{
	Matlab2c::CheckLicense();
	if(!(a.isVector() && b.isVector()))
		throw_logic_error("�����������Ϊ����");
	int i,k;
	Complex m;
	CMatrix p;
	if (b.row==1)
	{
		p.row=1;
		p.column = a.row*a.column+b.row*b.column-1;
	}else{
		p.column=1;
		p.row = a.row*a.column+b.row*b.column-1;
	}

	p.data = new Complex[p.row*p.column];
	for (k=0;k<p.row*p.column;k++)
	{
		m=0;
		for (i=0;i<a.row*a.column;i++)
			if ((k-i)>-1 && (k-i)<b.row*b.column)
				m+=(a.data[i])*(b.data[k-i]);
		p.data[k]=m;
	}
	return p;
}


int nowcan;
Matrix nowzhen;
//����ȫ�����Ӻ���
void perm(double* data, int n, int curr)
{
	Matlab2c::CheckLicense();
	int i;
	double t;
	if (curr==n-1)
	{
		for (i= 0; i < n; ++i)
			*(nowzhen.data+nowzhen.column*nowcan+i) = data[i];	
		nowcan++;
	}
	else
	{
		for (i = curr; i < n; ++i)
		{
			t = data[curr], data[curr] = data[i], data[i] = t;
			perm(data, n, curr+1);
			t = data[curr], data[curr] = data[i], data[i] = t;
		}
	}
}
//��������Ԫ�ص�ȫ��������������������ͬԪ�أ�ֻ��¼λ��
//���룺��Ҫ���������������������
//	���������Ԫ�ص�ȫ����
//	��ʾ��������������ͬԪ�ء��������ı�ԭ�������ݡ� N!�С� N��
Matrix Matlab2c::perms(Matrix& a)
{
	Matlab2c::CheckLicense();
	nowcan =0;
	nowzhen.row =Matlab2c::factorial(a.row*a.column);
	nowzhen.column = a.column*a.row;
	nowzhen.data = new double[nowzhen.row*nowzhen.column];
	perm(a.data, a.column*a.row, 0);
	return nowzhen;
}







//����ѭ����λ
//���룺����a��Ҫ���ƶ���ά��
//�������λ��ľ���
//downshift>0�����ƣ�downshift<0���ƣ�rightshift>0���� rightshift<0����
Matrix Matlab2c::circshift(Matrix& a,int downshift)  //nΪ��˳ʱ�룬nΪ��ʱ��
{
	Matlab2c::CheckLicense();
	downshift = ((downshift%a.row)+a.row)%a.row;   //����%һ���ܻ�����������
	Matrix p(a.row,a.column);
	for (int i=0;i<a.row;i++)
	{
		int newrow=(i+downshift)%a.row;
		for (int j=0;j<a.column;j++)
			p(newrow,j) = a(i,j);
	}
	return p;
}
Matrix Matlab2c::circshift(Matrix& a,int downshift,int rightshift) 
{
	Matlab2c::CheckLicense();
	downshift = ((downshift%a.row)+a.row)%a.row;   //����%һ���ܻ�����������
	rightshift = ((rightshift%a.column)+a.column)%a.column;   //����%һ���ܻ�����������
	Matrix p(a.row,a.column);
	for (int i=0;i<a.row;i++)//���б�
	{
		int newrow=(i+downshift)%a.row;
		for (int j=0;j<a.column;j++)
		{
			int newcolumn=(j+rightshift)%a.column;
			p(newrow,newcolumn) = a(i,j);
		}
	}
	return p;
}
CMatrix Matlab2c::circshift(CMatrix& a,int downshift)  //nΪ��˳ʱ�룬nΪ��ʱ��
{
	Matlab2c::CheckLicense();
	downshift = ((downshift%a.row)+a.row)%a.row;   //����%һ���ܻ�����������
	CMatrix p(a.row,a.column);
	for (int i=0;i<a.row;i++)
	{
		int newrow=(i+downshift)%a.row;
		for (int j=0;j<a.column;j++)
			p(newrow,j) = a(i,j);
	}
	return p;
}
CMatrix Matlab2c::circshift(CMatrix& a,int downshift,int rightshift) 
{
	Matlab2c::CheckLicense();
	downshift = ((downshift%a.row)+a.row)%a.row;   //����%һ���ܻ�����������
	rightshift = ((rightshift%a.column)+a.column)%a.column;   //����%һ���ܻ�����������
	CMatrix p(a.row,a.column);
	for (int i=0;i<a.row;i++)//���б�
	{
		int newrow=(i+downshift)%a.row;
		for (int j=0;j<a.column;j++)
		{
			int newcolumn=(j+rightshift)%a.column;
			p(newrow,newcolumn) = a(i,j);
		}
	}
	return p;
}
//����Ԫ��λ��
//���룺����Ϊ��������󣬲�������m
//�����m������������е�λ��
//��ʾ��������Ϊ����ʱ�����Ϊ��������λ���±��0��ʼ��
//������Ϊ����ʱ�����Ϊ���󣬵�1��ΪԪ�������У��ڶ���ΪԪ�������У�������ΪԪ��ֵ��
Matrix Matlab2c::find(Matrix& a,double m)  
{
	Matlab2c::CheckLicense();
	//���������
	if (a.isVector())
	{
		vector<int> location;
		for (int i=0;i<a.row*a.column;i++)
			if(a(i)!=m)
				location.push_back(i);
		Matrix p(location.size(),1);
		for (int i=0;i<p.row;i++)
			p(i)=location[i];
		return p;
	}
	//����Ǿ���
	else
	{
		vector<int> x,y;
		vector<double> value;
		for (int i=0;i<a.row;i++)
			for (int j=0;j<a.column;j++)
				if(a(i)!=m)
				{
					x.push_back(i);
					y.push_back(j);
					value.push_back(a(i,j));
				}
		Matrix p(x.size(),3);
		for (int i=0;i<p.row;i++)
		{ 
			p(i,0)=x[i];
			p(i,1)=y[i];
			p(i,2)=value[i];
		}
		return p;
	}
}
Matrix Matlab2c::find(Matrix& a) 
{
	Matlab2c::CheckLicense();
	return find(a,0);
}


//����λ�ã�����Ԫ��������
//���룺��������a��λ������weizhi
//	���������������Ӧλ���ϵ�Ԫ��ֵ
//	��ʾ��λ���±��1��ʼ��
//Matrix Matlab2c::getdata(Matrix& a,Matrix& weizhi)
//{
//	int i;
//	Matrix p(weizhi.row*weizhi.column,1);
//	for (i=0;i<p.row;i++)
//		p.data[i]=a.data[(int)(*(weizhi.data+i))-1];
//	return p;
//}


//���ظ��������Ŀ����,����������
//���룺��������a���߽�����edg
//�������������a�е�Ԫ����edg���и������ϵĸ����Ķ���
//��ʾ������Ϊ����ҿ�,����������
Matrix Matlab2c::histc(Matrix& a,Matrix& edg)    //��������
{
	Matlab2c::CheckLicense();
	int i=0,j=0;
	Matrix p(edg.row*edg.column,1);
	for (i=0;i<p.row;i++)
		p.data[i]=0;
	for (i=0;i<a.row*a.column;i++)
		for (j=edg.row*edg.column-1;j>-1;j--)
			if((a.data[i])>=(edg.data[j]))
			{
				(p.data[j])++;  //���ڵ���С�����±߽磬С��С�����ϱ߽�����ݵĸ���.���һ���洢�������һ��ֵ�ĸ���
				break;
			}
			return p;
}


//���������л�Ϊ1,0��-1,
//����Ϊ����a���������a�ĸ���Ԫ�صķ���ֵ��
//����Ԫ�ش���0���򷵻�1������0������0��С��0������-1
Matrix Matlab2c::sign(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			if (a(i,j)>0)
				p(i,j)=1;
			else if(a(i,j)<0)
				p(i,j)=-1;
			else
				p(i,j)=0;
	return p;
}


//����������λ�������x
//���룺����a,Ҫ��ӵ�����x
//	�����������a����ǰ���������x�������
//	��ʾ����������Ϊ���������������������������������
//Matrix Matlab2c::x_vector(double x,Matrix& a)
//{
//	int i;
//	Matrix p;
//	if(a.row!=1)
//	{
//		p.row=a.row+1;
//		p.column = a.column;
//	}
//	else
//	{
//		p.column=a.column+1;
//		p.row = a.row;
//	}
//	p.data = new double[p.row*p.column];
//	*p.data =x;//�������ײ��������
//	for (i=0;i<a.row*a.column;i++)
//		p(i+1)=a.data[i];
//	return p;
//}


//��������β���������x
//���룺����a,Ҫ��ӵ�����x
//	�����������a��������������x�������
//	��ʾ����������Ϊ���������������������������������
//Matrix Matlab2c::vector_x(Matrix& a,double x)
//{
//	int i;
//	Matrix p;
//	if(a.row!=1)
//	{
//		p.row=a.row+1;
//		p.column = a.column;
//	}
//	else
//	{
//		p.column=a.column+1;
//		p.row = a.row;
//	}
//	p.data = new double[p.row*p.column];
//	for (i=0;i<a.row*a.column;i++)
//		p.data[i]=a.data[i];
//	p.data[p.row*p.column-1]=x;//������β���������
//	return p;
//}



//���Եȷ�����������
//����Ϊ��������յ�a��b�Լ����ݵ���n�����Ϊ����a��b֮��ȷֵ�n����,Ĭ��Ϊ100
Matrix Matlab2c::linspace(double begin,double finish,int number)
{
	Matlab2c::CheckLicense();
	int j;
	double interval = (finish-begin)/(number-1);
	Matrix p(1,number);
	for (j=0;j<p.column;j++)
		p.data[j]=begin+j*interval;
	return p;
}

//�����ȷ֣��ȵȷ֣�����10��x�η�,����number��Ĭ��ֵ100
Matrix Matlab2c::logspace(double begin,double finish,int number)
{
	Matlab2c::CheckLicense();
	int j;
	double interval = (finish-begin)/(number-1);
	Matrix p(1,number);
	for (j=0;j<p.column;j++)
		p.data[j]=std::pow(10,begin+j*interval);
	return p;
}

//�����������
//���룺����a������b
//	���������a��b�ĵ��
double Matlab2c::dot(Matrix& a,Matrix& b)
{
	Matlab2c::CheckLicense();
	int i,j;
	double sum=0;
	for (i=0;i<a.row;i++)
		for (j=0;j<a.column;j++)
			sum +=a(i,j)*b(i,j);
	return sum;
}


//����ʽ����,a����b
//���룺��������ʽ�ľ���a��b
//�����a����b���̾���
Matrix Matlab2c::deconv(Matrix& a1,Matrix& b1)
{
	Matlab2c::CheckLicense();
	Matrix p;
	int i,j;
	int lengtha,lengthb;
	double *ma;
	double *mb;
	double *a;  //���a1ǰ���0
	double *b;  //���b1ǰ�����
	for (i=0;i<a1.column;i++)
		if ((a1.data[i])!=0)
			break;
	lengtha =a1.column-i;
	a =new double[lengtha];
	for (i=(a1.column-lengtha);i<a1.column;i++)
		a[i-a1.column+lengtha] = a1.data[i];

	for (i=0;i<b1.column;i++)
		if ((b1.data[i])!=0)
			break;
	//b��Ϊb1����ǰ��0��Ķ���ʽ
	lengthb=b1.column-i;
	b=new double[lengthb];
	for (i=(b1.column-lengthb);i<b1.column;i++)
		b[i-b1.column+lengthb] = b1.data[i];

	p=Matrix(1,lengtha+1-lengthb);
	ma = new double[lengtha];  //����ѭ��������
	mb = new double[lengtha];  //�洢ѭ����ȥ��ֵ
	for (i=0;i<lengtha;i++)
		ma[i] =a[i];

	for (i=0;i<p.column;i++)
	{
		p.data[i]=ma[i]/(b[0]);
		for (j=0;j<lengthb;j++)
			mb[j] =(p.data[i])*(b[j]);

		for (j=i;j<(i+lengthb);j++)
			ma[j]=ma[j]-mb[j-i];
	}
	delete[] a;
	delete[] b;
	delete[] ma;
	delete[] mb;
	return p;
}



//����ʽ��
//����:����ʽ��ϵ������a(���кϲ���һά����)
//���:�������ϵ������
Matrix Matlab2c::polyder(Matrix& a)
{
	Matlab2c::CheckLicense();
	Matrix p(1,a.row*a.column-1);
	Matrix temp(a);
	if(!a.isVector())
		temp = Matlab2c::reshape(a,1,a.row*a.column);
	for (int i=0;i<p.column;i++)
		p.data[i] =temp.data[i]*(p.column-i);
	return p;
}


//����ʽ�����
//����:����ʽ��ϵ������a(���кϲ���һά����)
//���:������ֵ�ϵ��������������Ϊ0
Matrix Matlab2c::polyint(Matrix& a)
{
	Matlab2c::CheckLicense();
	Matrix p(1,a.row*a.column+1);
	Matrix temp(a);
	if(!a.isVector())
		temp = Matlab2c::reshape(a,1,a.row*a.column);
	for (int i=0;i<p.column-1;i++)
		p.data[i] = temp.data[i]/(p.column-i-1);
	p.data[a.row*a.column]=0;
	return p;
}


//����ʽ�ӷ�
//����:��������ʽ��ϵ������a��b
//���:��������ʽ�͵�ϵ������
//Matrix Matlab2c::polynome_add(Matrix& a,Matrix& b)
//{
//	int i;
//	Matrix p;
//	if (a.column>b.column || a.column==b.column)
//	{
//		p=Matrix(1,a.column);
//		for (i=0;i<a.column;i++)
//		{
//			if (i<(a.column-b.column))
//			{
//				p.data[i] = a.data[i];
//			}
//			else
//				p.data[i] = a.data[i]+b.data[i-a.column+b.column];
//		}
//	}
//	if (a.column<b.column)
//	{
//		p=Matrix(1,b.column);
//		for (i=0;i<b.column;i++)
//		{
//			if (i<(b.column-a.column))
//			{
//				p.data[i] = b.data[i];
//			}
//			else
//				p.data[i] = b.data[i]+a.data[i-b.column+a.column];
//		}
//	}
//	return p;
//}



//�����ʽa����m�㴦��ֵ
//���룺����ʽ��ϵ������a����ֵ��m,(���кϲ���һά����)
//���������ʽ��m���ȡֵ
double Matlab2c::polyval(Matrix& a,double m)
{
	Matlab2c::CheckLicense();
	Matrix temp(a);
	if(!a.isVector())
		temp = Matlab2c::reshape(a,1,a.row*a.column);

	double s =0;
	for(int i=0;i<a.row*a.column;i++)
		s+=a.data[a.row*a.column-i-1]*pow(m,i);
	return s;
}



//ȡ���ϵĵ�ֵԪ��
//���룺����a
//���������ָ�룬��һ�����ϱ�ʾ����aȥ���ظ�Ԫ�غ�ļ������򣬵ڶ����������¼���Ԫ����ԭ����a�е�λ�ã�����������Ϊԭ����aԪ�����¼����е�λ�á�
//��ʾ��λ���±��0��ʼ
Matrix* Matlab2c::unique(Matrix& a)
{
	Matlab2c::CheckLicense();
	bool exist=false;
	vector<double> c;

	Matrix *p; 
	p = new Matrix[3];
	for (int j=0;j<a.row*a.column;j++)
	{
		exist=false;
		for (int n=0;n<c.size();n++)
			if (a.data[j]==c[n])
			{
				exist=true;
				break;
			}
			if (!exist)
				c.push_back( a.data[j]);  
	}

	Matrix ia(1,c.size());
	Matrix ib(1,a.row*a.column); 
	Matrix tmp(c,1,c.size());
	Matlab2c::Q_sort(tmp);  //��������
	for (int i=0;i<a.row*a.column;i++)
	{
		for (int j=0;j<tmp.row*tmp.column;j++)
		{
			if(a(i)==tmp(j))
			{
				ia(j)=i;
				ib(i)=j;
			}
		}
	}

	*p = tmp;
	*(p+1)=ia;
	*(p+2)=ib;
	return p;
}


//�������ϵĲ���
//���룺����a������b
//	�����a��b�Ĳ���
//	��ʾ��������һά�������ʽ��ʾ
Matrix Matlab2c::unionf(Matrix& a,Matrix& b)
{
	Matlab2c::CheckLicense();
	if (!((a.row==1 || a.column==1)&&(b.row==1 || b.column==1)))
		throw_logic_error("unionf����Ҫ������Ϊ����");
	int j,n,m=0;
	int geshu=0;
	Matrix c(1,a.column*a.row+b.column*b.row);
	for (j=0;j<a.row*a.column;j++)
	{
		m=0;
		for (n=0;n<geshu;n++)
			if ((a.data[j])==(c.data[n]))
			{
				m=1;
				break;
			}
			if (m==0)
			{
				c.data[geshu] = a.data[j];
				geshu++;
			}
	}
	for (j=0;j<b.row*b.column;j++)
	{
		m=0;
		for (n=0;n<geshu;n++)
			if (b.data[j]==c.data[n])
			{
				m=1;
				break;
			}
			if (m==0)
			{
				c.data[geshu] = b.data[j];
				geshu++;
			}
	}
	Matrix p(1,geshu);
	for (j=0;j<p.column;j++)
		p.data[j]=c.data[j];
	return p;
}

//��⼯���е�Ԫ���Ƿ�����һ��������
//���룺����a������b
//���������������ָ�룬��һ��������¼a�е�Ԫ���Ƿ����b�У��ڶ���������¼a�е�Ԫ����b�е�λ�ã���������Ϊ-1
//��ʾ��������һ������������һά�����±��0��ʼ��������Ϊ-1
Matrix* Matlab2c::ismember(Matrix& a,Matrix& b)
{
	Matlab2c::CheckLicense();
	bool exist=false;
	Matrix *p;
	Matrix p1(1,a.column);  //��¼a�е�Ԫ���Ƿ����b��,����Ϊ1��������Ϊ0
	Matrix p2(1,a.column);  //��¼a�е�Ԫ����b�е�λ�ã���������Ϊ-1
	p = new Matrix[2];
	for (int j=0;j<a.column;j++)
	{
		int n=0;
		exist=false;
		for (n=0;n<b.column;n++)
			if (a.data[j]==b.data[n])
			{
				exist=true;
				break;
			}
		if (exist)
		{
			p1.data[j] = 1;
			p2.data[j] = n;
		}
		else
		{
			p1.data[j] = 0;
			p2.data[j] = -1;
		}
	}
	*p = p1;
	*(p+1)=p2;
	return p;
}



//���������ϵĽ���
//���룺����a������b
//��������ؾ���ָ�룬��һ������Ϊa��b�Ľ������ڶ�������Ϊ�����ڼ���a�е�λ�ã�����������Ϊ������b�е�λ�á�
//��ʾ��������һά�������ʽ��ʾ������λ��ʱ���±��0��ʼ
Matrix* Matlab2c::intersect(Matrix& a,Matrix& b)
{
	Matlab2c::CheckLicense();
	vector<double> c;
	vector<int> ia;
	vector<int> ib;
	Matrix *p = new Matrix[3];
	for (int j=0;j<a.column;j++)
		for (int n=0;n<b.column;n++)
			if (a.data[j]==b.data[n])
			{
				ia.push_back(j);
				ib.push_back(n);
				c.push_back(a.data[j]);
				break;
			}
	
	*p = Matrix(c,1,c.size());
	*(p+1)=Matrix(ia,1,ia.size());
	*(p+2)=Matrix(ib,1,ib.size());
	return p;
}






//���ݸ������ʽϵ��  ���������������ʽ
//���룺����ʽ�ĸ�����a
//���������ʽ��ϵ������
Matrix Matlab2c::poly(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i;
	Matrix p(1,1),b(1,2);
	p.data[0]=1;
	b.data[0] =1;
	if (a.isVector())
	{
		for (i=0;i<a.row*a.column;i++)
		{
			b.data[1] = -(a.data[i]);
			p=conv(p,b);
		}
	}else if (a.row==a.column)   //�������������ʽ
	{
		//p=det(lambda*eye(a.row))-a;
	}else
	{
		throw_logic_error("poly����������Ϊ���������");
	}
	
	return p;
}

