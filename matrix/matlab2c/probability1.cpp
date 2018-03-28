#include "Matlab2c.h"
using namespace Matlab2c;




//����ֲ����ܶȺ���ֵ
//���룺�¼�����K��(��������ʽ)��n�������ܴ�����pÿ�������¼������ĸ��ʣ�
//������¼�����K�εĸ����ܶ�
//��ʾ���������ı����ԭ������
Matrix Matlab2c::binopdf (Matrix& k, int n,double p)
{
	Matlab2c::CheckLicense();
	Matrix c(k.row,k.column);
	for (int i=0;i<c.row;i++)
		for (int j=0;j<c.column;j++)
			c(i,j) = (double)Matlab2c::nchoosek(n,k(i,j))*(double)(pow(p,k(i,j))*pow((1-p),(n-k(i,j))));
	return c;
}


//���ɶ���ֲ��������
//����Ϊ����ֲ��Ĳ���n��p���Լ����������������
//���Ϊ����ֲ��������
Matrix Matlab2c::binornd(int n,double p,int row,int column)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix c(row,column);
	int x=-1;
	double dScope;
	double *g = new double[n+1];
	double max=0;
	srand((unsigned)time(0));
	for (i=0;i<n+1;i++)
	{
		g[i]=(double)Matlab2c::nchoosek(n,i)*(double)(pow(p,i)*pow((1-p),(n-i)));//��ȡ�����ܸ����ܶ�
		if (max<g[i])
			max=g[i];
	}
	for (i=0;i<c.row;i++)
		for (j=0;j<c.column;j++)
		{
			x=-1;
			while (x<0 || x>n)
				x = (int)((double)std::rand()/RAND_MAX*n);
			do
			{
				dScope = ((double)std::rand()/RAND_MAX)*max;
			}while( dScope > g[x]);   //����Ĵ����ͷ�Ӧ�˸����ܶ�
			c(i,j)=x;
		}	
		return c;
}

//����ֲ�����������
//���룺n�������ܴ�����pÿ�������¼������ĸ���
//���������ֲ��������뷽��
Matrix* Matlab2c::binostat (Matrix& n,Matrix& p) 
{
	Matlab2c::CheckLicense();
	Matrix averMatrix(n.row,n.column),varMatrix(p.row,p.column);
	Matrix *back=new Matrix[2];
	for (int i=0;i<n.row;i++)
		for (int j=0;j<n.column;j++)
		{
			averMatrix(i,j) =n(i,j)*(p(i,j));
			varMatrix(i,j) = n(i,j)*(p(i,j))*(1-p(i,j));
		}
	back[0]=averMatrix;
	back[1]=varMatrix;
	return back;
}

//����ָ���ֲ����������
//����Ϊ����������ָ���ֲ��Ĳ���mu
//����������
Matrix Matlab2c::exprnd(double mu,int row ,int column)
{
	Matlab2c::CheckLicense();
	Matrix p(row,column);
	//default_random_engine generator;//��������Ĭ�ϵ����棬ÿ�����ɵ������������ͬ�ġ�
	random_device rd;
	mt19937 gen(rd());
	for (int i=0;i<p.row;i++)
	{
		for (int j=0;j<p.column;j++)
		{
			exponential_distribution<double> exponential(mu);
			p(i,j)=exponential(gen);
		}
	}

	return p;
}


//ָ���ֲ�������ֵ
//���룺����pdf�ĵ�������ָ���ֲ��Ĳ���lambda
//�������Ӧ��pdfֵ
Matrix Matlab2c::exppdf(Matrix& a,double mu)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			if(a(i,j)>=0)
				p(i,j) = (double)(mu*std::exp(-mu*a(i,j)));
			else
				p(i,j) =0;
	return p;
}

//��ָ���ֲ��ľ�ֵ�ͷ���
//����ָ���ֲ��Ĳ���mu����1/LambdaΪ�������
//���ָ���ֲ��������ͷ���
Matrix* Matlab2c::expstat(Matrix& mu)
{
	Matlab2c::CheckLicense();
	Matrix averMatrix(mu),varMatrix(mu.row,mu.column);
	Matrix *p = new Matrix[2];
	for (int i=0;i<mu.row*mu.column;i++)
		varMatrix(i)=mu(i)*mu(i);
	p[0]=averMatrix;
	p[1]=varMatrix;
	return p;
}



//��һ�����鲻ͬά�ȵ����ֵ
//����Ϊһ������ʱ�����Ϊһ��1x1�ľ���
//����Ϊһ���������Ϊÿ�����ֵ������
//dim=1��Ĭ�ϣ����������ֵ��dim=2���������ֵ
Matrix Matlab2c::max(Matrix& a,int dim)
{
	Matlab2c::CheckLicense();
	if(a.isVector())
	{
		Matrix p(1,1);
		double maxitem=DBL_MIN;
		for (int i=0;i<a.row*a.column;i++)
			if(maxitem<a(i))
				maxitem=a(i);
		p.data[0]=maxitem;
		return p;
	}
	else
	{
		if (dim==1)
		{
			Matrix p(1,a.column);
			double maxitem=DBL_MIN;
			for (int j=0;j<a.column;j++)
			{
				maxitem=DBL_MIN;
				for (int i=0;i<a.row;i++)
					if(maxitem<a(i,j))
						maxitem=a(i,j);
				p.data[j]=maxitem;
			}
			return p;
		}else{
			Matrix p(a.row,1);
			double maxitem=DBL_MIN;
			for (int i=0;i<a.row;i++)
			{
				maxitem=DBL_MIN;
				for (int j=0;j<a.column;j++)
					if(maxitem<a(i,j))
						maxitem=a(i,j);
				p.data[i]=maxitem;
			}
			return p;
		}
		
	}
}
//��һ�����鲻ͬά�ȵ���Сֵ
//����Ϊһ������ʱ�����Ϊһ��1x1�ľ���
//����Ϊһ���������Ϊÿ����Сֵ������
//dim=1��Ĭ�ϣ���������Сֵ��dim=2��������Сֵ
Matrix Matlab2c::min(Matrix& a,int dim)
{
	Matlab2c::CheckLicense();
	if(a.isVector())
	{
		Matrix p(1,1);
		double minitem=DBL_MAX;
		for (int i=0;i<a.row*a.column;i++)
			if(minitem>a(i))
				minitem=a(i);
		p.data[0]=minitem;
		return p;
	}
	else
	{
		if(dim==1)
		{
			Matrix p(1,a.column);
			int i,j;
			double minitem=DBL_MAX;
			for (j=0;j<a.column;j++)
			{
				minitem=DBL_MAX;
				for (i=0;i<a.row;i++)
					if(minitem>a(i,j))
						minitem=a(i,j);
				p.data[j]=minitem;
			}
			return p;
		}
		else
		{
			Matrix p(a.row,1);
			double minitem=DBL_MAX;
			for (int i=0;i<a.row;i++)
			{
				minitem=DBL_MAX;
				for (int j=0;j<a.column;j++)
					if(minitem>a(i,j))
						minitem=a(i,j);
				p.data[i]=minitem;
			}
			return p;
		}
		
	}
}
//��ֵ���������������ֵ���������
//����Ϊһ���������Ϊÿ�еľ�ֵ������
//����Ϊһ�����������Ϊ1x1�ľ�ֵ
//dim=1��Ĭ�ϣ��������ֵ��dim=2�������ֵ
Matrix Matlab2c::mean(Matrix& a,int dim)
{
	Matlab2c::CheckLicense();
	if(a.isVector())
	{
		Matrix p(1,1);
		double sum=0;
		for (int i=0;i<a.row*a.column;i++)
				sum +=a(i);
		p.data[0]=sum/(a.row*a.column);
		return p;
	}
	else
	{
		if (dim==1)
		{
			Matrix p(1,a.column);
			int i,j;
			double sum=0;
			for (j=0;j<a.column;j++)
			{
				sum=0;
				for (i=0;i<a.row;i++)
					sum +=a(i,j);
				p.data[j]=sum/a.row;
			}
			return p;
		}else
		{
			Matrix p(a.row,1);
			double sum=0;
			for (int i=0;i<a.row;i++)
			{
				sum=0;
				for (int j=0;j<a.column;j++)
					sum +=a(i,j);
				p.data[i]=sum/a.column;
			}
			return p;
		}
		
	}
}


//���ظ�����λ����ɵ���������
//����Ϊ�������������������λ��
//����Ϊһ���������Ϊÿ�е���λ��������
//dim=1��Ĭ�ϣ���������λ����dim=2��������λ��
Matrix Matlab2c::median(Matrix& a,int dim)
{
	Matlab2c::CheckLicense();
	int lp=0;
	Matrix c = Matlab2c::sort(a,dim);   //��ûһ�л�ÿһ�а���������
	Matrix p;
	
	if(a.isVector())  //�����ݾ���Ϊ����
	{
		p=Matrix(1,1);
		if ((a.row*a.column)%2==1)
			p.data[0]=c.data[(a.row*a.column/2)];
		else
			p.data[0]=0.5*(c.data[(a.row*a.column/2)])+0.5*(c.data[(a.row*a.column/2-1)]);
		return p;
	}
	if (dim==1)
	{
		p=Matrix(1,a.column);
		if (a.row%2==1)
			for (int j=0;j<p.column;j++)
				p.data[j]=c(a.row/2,j);
		else
			for (int j=0;j<p.column;j++)
				p.data[j]=0.5*c(a.row/2,j)+0.5*c(a.row/2-1,j);
		return p;
	}else
	{
		p=Matrix(a.row,1);
		if (a.column%2==1)
			for (int i=0;i<p.row;i++)
				p.data[i]=c(i,a.column/2);
		else
			for (int i=0;i<p.row;i++)
				p.data[i]=0.5*c(i,a.column/2)+0.5*c(i,a.column/2-1);
		return p;
	}
}



//��̬�ֲ��ĸ���ֵ��
//���룺Ҫ������ܶȵĵ����aver����ֵ��sigma����׼��
//���������ϵĸ����ܶ�ֵ
Matrix Matlab2c::normpdf(Matrix& a,double aver,double sigma)
{
	Matlab2c::CheckLicense();
	Matrix p(a.row,a.column);
	for (int i=0;i<p.row;i++)
		for (int j=0;j<p.column;j++)
			p(i,j) = (double)(1.0/(std::sqrt(2*3.141592)*sigma)*std::exp(-(a(i,j)-aver)*(a(i,j)-aver)/(2*sigma*sigma)));
	return p;
}
//����̬�ֲ��ľ�ֵ�ͷ���
//������̬�ֲ��ľ�ֵ�ͱ�׼��
//�����̬�ֲ��ľ�ֵ�ͷ���
Matrix* Matlab2c::normstat(Matrix& aver,Matrix& sigma)
{
	Matlab2c::CheckLicense();
	Matrix averMatrix(aver),varMatrix(aver.row,aver.column);
	Matrix *p = new Matrix[2];
	for (int i=0;i<sigma.row*sigma.column;i++)
		varMatrix(i)=sigma(i)*sigma(i);
	p[0]=averMatrix;
	p[1]=varMatrix;
	return p;
}





//������̬�ֲ����������
//����Ϊ������������̬�ֲ��ľ�ֵ�ͱ�׼��
//�����̬�ֲ�����
Matrix Matlab2c::normrnd(double aver,double sigma,int row,int column)
{
	Matlab2c::CheckLicense();
	Matrix p(row,column);
	//default_random_engine generator;//��������Ĭ�ϵ����棬ÿ�����ɵ������������ͬ�ġ�
	random_device rd;
	mt19937 gen(rd());
	for (int i=0;i<p.row;i++)
	{
		for (int j=0;j<p.column;j++)
		{
			normal_distribution<double> normal(aver,sigma);
			p(i,j)=normal(gen);
		}
	}

	return p;
}


//���ɷֲ��ĸ���ֵ��
//����:����pdf�ĵ���������poisson����lambda
//���:pdfֵ
Matrix Matlab2c::poisspdf(Matrix& a,double Lambda)
{
	Matlab2c::CheckLicense();
	double e =2.718282;
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			p(i,j) = (double)(pow(e,-Lambda)*pow(Lambda,a(i,j))/Matlab2c::factorial((int)(a(i,j))));
	return p;
}


//���������е���ֵ��Χ������Ϊ������ʱ�������е�ȡֵ��Χ
//���룺����a
//���������a���е����ֵ����Сֵ�Ĳ�
Matrix Matlab2c::range(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	double maxdata=0;
	double mindata=0;
	Matrix p;
	if(a.row==1)  //�����ݾ���Ϊ������
	{
		p=Matrix(1,1);
		maxdata = a.data[0];
		mindata = a.data[0];
		for (j=0;j<a.column;j++)
		{
			if (maxdata<a.data[j])
				maxdata = a.data[j];
			if (mindata>a.data[j])
				mindata = a.data[j];
		}
		p.data[0]=maxdata-mindata;
		return p;
	}
	p=Matrix(1,a.column);
	for (j=0;j<a.column;j++)
	{
		maxdata = a(0,j);
		mindata = a(0,j);
		for (i=0;i<a.row;i++)
		{
			if (maxdata<a(i,j))
				maxdata = a(i,j);
			if (mindata>a(i,j))
				mindata = a(i,j);
		}
		p.data[j]=maxdata-mindata;
	}
	return p;
}


//�������ֲ�����ֵ
//���룺����pdf�ĵ������������ֲ��Ĳ���sigma
Matrix Matlab2c::raylpdf(Matrix& a,double sigma)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			if(a(i,j)>=0)
				p(i,j) = (double)(a(i,j)/(sigma*sigma)*std::exp(-(a(i,j))*(a(i,j))/(2*sigma*sigma)));
			else
				p(i,j) =0;
	return p;
}


//���ذ��б�׼������������Ϊ������ʱ�������������ı�׼��
//����Ϊһ���������Ϊÿ�еı�׼��������
//ʵ�ֵ���matlab�� std(X,1) ����
Matrix Matlab2c::std(Matrix& a)
{
	Matlab2c::CheckLicense();
	Matrix m=mean(a);
	double sum=0;
	if(a.row==1)  //�����ݾ���Ϊ������
	{
		Matrix p=Matrix(1,1);
		for (int j=0;j<a.column;j++)
			sum +=(a(j)-m(0))*(a(j)-m(0));
		p(0)=std::sqrt(sum/a.column);
		return p;
	}
	Matrix p(1,a.column);
	for (int j=0;j<a.column;j++)
	{
		sum=0;
		for (int i=0;i<a.row;i++)
		{
			sum +=(a(i,j)-m(j))*(a(i,j)-m(j));
		}
		p.data[j]=std::sqrt(sum/a.row);
	}
	return p;
}



//���ȷֲ����������������ͷ���
//���룺���ȷֲ����Ͻ���½�
//��������ȷֲ��ľ�ֵ�ͷ���
Matrix* Matlab2c::unifstat(Matrix& a,Matrix& b)
{
	Matlab2c::CheckLicense();
	if(a.row!=b.row || a.column!=b.column)
	{
		throw_logic_error("���ȷֲ������޾���ƥ��");
		return NULL;
	}
	Matrix averMatrix(a.row,a.column),varMatrix(a.row,a.column);
	Matrix *p = new Matrix[2];

	for (int i=0;i<a.row;i++)
		for (int j=0;j<a.column;j++)
		{
			averMatrix(i,j)=0.5*(a(i,j))+0.5*(b(i,j));
			varMatrix(i,j)=pow((a(i,j))-(b(i,j)),2)/12;
		}
	p[0]=averMatrix;
	p[1]=varMatrix;
	return p;
}




//���ذ��з�������������Ϊ������ʱ�������������ķ���
//����Ϊһ���������Ϊÿ�еķ���������
//ʵ�ֵ�Ϊmatlab��D=var(X, 1) ����
Matrix Matlab2c::var(Matrix& a)
{
	Matlab2c::CheckLicense();
	Matrix m = Matlab2c::mean(a);
	double sum=0;
	if(a.row==1)  //�����ݾ���Ϊ������
	{
		Matrix p(1,1);
		for (int j=0;j<a.column;j++)
			sum +=(a(j)-m(0))*(a(j)-m(0));
		p(0) = sum/a.column;
		return p;
	}
	Matrix p(1,a.column);
	for (int j=0;j<a.column;j++)
	{
		sum=0;
		for (int i=0;i<a.row;i++)
		{
			sum +=(a(i,j)-m(j))*(a(i,j)-m(j));
		}
		p(j)=sum/a.row;
	}
	return p;
}


//Τ���ֲ�����ֵ
//����:Τ���ֲ��Ĳ���k��lambda
//���:����ֵ
Matrix Matlab2c::weibpdf(Matrix& a,double k,double lambda)
{
	Matlab2c::CheckLicense();
	double e =2.718282;
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
			if (a(i,j)>=0)
				p(i,j) = (double)(k/lambda*std::pow(a(i,j)/lambda,k-1)*std::exp(std::pow(-(a(i,j)/lambda),k)));
			else
				p(i,j)=0;
	return p;
}



//���ɾ��ȷֲ����������
//����Ϊ�����������Լ����ȷֲ����±߽磨Ĭ��Ϊ0�����ϱ߽磨Ĭ��Ϊ1��
//������ȷֲ�����
Matrix Matlab2c::rand(int row,int column,double min,double max)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(row,column);
	double temp;
	srand((unsigned)time(NULL));
	for (i=0;i<p.row;i++)
		for (j=0;j<p.column;j++)
		{
			temp = (double)std::rand()/RAND_MAX*(max-min)+min;
			p(i,j)=temp ;
		}	
		return p;
}




//���ɱ�׼��̬�ֲ�����
//����Ϊ��������
//���Ϊ��׼��̬�ֲ�����
Matrix Matlab2c::randn(int row ,int column)
{
	Matlab2c::CheckLicense();
	Matrix p(row,column);
	//default_random_engine generator;//��������Ĭ�ϵ����棬ÿ�����ɵ������������ͬ�ġ�
	random_device rd;
	mt19937 gen(rd());
	for (int i=0;i<p.row;i++)
	{
		for (int j=0;j<p.column;j++)
		{
			//normal(0,1)��0Ϊ��ֵ��1Ϊ����
			normal_distribution<double> normal(0,1);
			p(i,j)=normal(gen);
		}
	}
	return p;
}


//���ɾ��ȷֲ������������
//���룺����Ҫ�������������ֲ����䣬�±߽�Ĭ��Ϊ0���ϱ߽�Ĭ��Ϊ1
//�����������ξ���
Matrix Matlab2c::randind(int row,int column,int min,int max)
{
	Matlab2c::CheckLicense();
	Matrix p(row,column);
	double temp;
	srand((unsigned)time(NULL));
	for (int i=0;i<p.row;i++)
		for (int j=0;j<p.column;j++)
		{
			temp = (double)std::rand()/RAND_MAX*(max-min+1)+min-0.5;
			p(i,j)=(int)(temp+0.5);  //4��5��
		}	
		return p;
}


