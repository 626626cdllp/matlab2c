#include "Matlab2c.h"
using namespace Matlab2c;




//�жϾ���Գ�����	
int Matlab2c::isSymmetryRegular(Matrix& a, int sym)
{		
	Matlab2c::CheckLicense();
	long double ldDet;
	size_t i, j, k;

	size_t sC = a.column;	//��������
	size_t sR = a.row;	//��������

	size_t stRank = sR;				// �������
	if(stRank != a.row)
		return int(-1);				// ���Ƿ���

	if(sym > 0)
		if(isSymmetry(a)==false)
			return int(-2);			//rhs���ǶԳ���

	cout << " K = 1 \t Determinant = " << a.data[0] <<endl;

	for(k = 0; k < stRank; k ++)	//��Ҫ�б�����������������Ҫ�޸�
	{
		if(FloatEqual(a(k,k), 0)||a(k,k) < 0)
			return int(-3);	//�Խ�Ԫ������0��������������
	}

	for(k = 2; k <= sR; k++)
	{
		Matrix m(k,k);	//����һmatrix����

		for(i=0; i<k; i++)
			for(j=0; j<k; j++)
				m(i, j) = (long double)a(i,j);	//��ʼ��

		ldDet = det(m);				// ˳������ʽ��ֵ

		cout << " K = " << k << "\t Determinant = " << ldDet << endl; 

		if(FloatEqual(ldDet,0) || ldDet < 0.0)
			return (0);					//����������
	}
	if(sym == 1) return int(2);			//����Ϊ�����Գ���
	else		 return int(1);			//����Ϊ������
}

//�жϾ���Գ�
bool Matlab2c::isSymmetry(Matrix& a)
{
	Matlab2c::CheckLicense();
	bool bSy = true;
	size_t stRow = a.row;	//ȡ��������

	if(a.column == stRow)	// �����Ƿ���
	{
		for(size_t i = 1; i < stRow; i ++)			//�ж��Ƿ�Գ�
			for(size_t j = 0; j < i; j ++)
				if(FloatNotEqual((long double)a(i,j), (long double)a(i,j)))
				{
					bSy =  false;
					goto RET;
				}
	}
	else
		bSy = false;
RET: return bSy;	//����Գ�
}


//���淽���LU�ֽ�
//������淽�����ΪL�����Ǿ����U�����Ǿ���ľ���ָ��
Matrix* Matlab2c::lu(Matrix& a)
{
	Matlab2c::CheckLicense();
	if (a.row!=a.column)
	{
		throw_logic_error("LU�ֽ�������Ϊ����");
		return nullptr;
	}
	Matrix *p = new Matrix[2];
	int n=a.row;
	int i,j,k,w,v,tt;
	for (k=0; k<=n-2; k++)
	{ 
		tt=k*n+k;
		if (std::fabs(a.data[tt])+1.0==1.0)
		{ 
			printf("fail\n"); 
			return(nullptr);
		}
		for (i=k+1; i<=n-1; i++)
		{ 
			w=i*n+k; a.data[w]=a.data[w]/a.data[tt];
		}
		for(i=k+1; i<=n-1; i++)
		{ 
			w=i*n+k;
			for (j=k+1; j<=n-1; j++)
			{ 
				v=i*n+j;
				a(v)=a(v)-a(w)*a(k*n+j);
			}
		}
	}
	for (i=0; i<=n-1; i++)
	{ 
		for (j=0; j<i; j++)
		{ 
			w=i*n+j; p[0].data[w]=a.data[w]; p[1].data[w]=0.0;
		}
		w=i*n+i;
		p[0].data[w]=1.0; p[1].data[w]=a.data[w];
		for (j=i+1; j<=n-1; j++)
		{ 
			w=i*n+j; p[0].data[w]=0.0; p[1].data[w]=a.data[w];
		}
	}
	return(p);
}

//���Ⱦ����QR�ֽ�
Matrix* Matlab2c::qr(Matrix& a)   //���ؾ����һ��ΪQ���ڶ���ΪR
{
	Matlab2c::CheckLicense();
	Matrix *back = new Matrix[2];
	Matrix& rhs=a;
	int stRow = a.row;	// ��������
	int stCol = a.column;	// ��������
	Matrix rhq(stRow,stCol);
	if(stRow < stCol)
	{
		throw_logic_error("QR�ֽ�����в���С����");
		return nullptr;
	}
	for(int i=0; i<stRow; i++)
		for(int j=0; j<stRow; j++)
		{ 
			rhq(i,j)=0.0;
			if(i==j) rhq(i,j)=1.0;
		}

		int nn=stCol;

		if(stRow == stCol) nn=stRow-1;

		for(int k=0; k<nn; k++)
		{
			double u=0.0;

			for(int i = k; i < stRow; i++)
			{ 
				double w = std::fabs(rhs(i,k));
				if(w > u) u = w;
			}
			double alpha=0.0;
			for(int i = k; i < stRow; i++)
			{
				double t=rhs(i,k)/u;
				alpha=alpha+t*t;
			}

			if(rhs(k,k)>0.0) u=-u;

			alpha=u*std::sqrt(alpha);

			if(FloatEqual(alpha,0.0)) return(0);

			u=std::sqrt(2.0*alpha*(alpha-rhs(k,k)));

			if(FloatNotEqual(u,0.0))
			{ 
				rhs(k,k)=(rhs(k,k)-alpha)/u;

				for(int i=k+1; i<stRow; i++)
					rhs(i,k) /= u;

				for(int j=0; j<stRow; j++)
				{
					double t=0.0;

					for(size_t jj=k; jj<stRow; jj++)
						t=t+rhs(jj,k)*rhq(jj,j);

					for(int i=k; i<stRow; i++)
						rhq(i,j)=rhq(i,j)-2.0*t*rhs(i,k);
				}

				for(int j=k+1; j<stCol; j++)
				{ 
					double t=0.0;

					for(int jj=k; jj<stRow; jj++)
						t=t+rhs(jj,k)*rhs(jj,j);

					for(int i=k; i<stRow; i++)
						rhs(i,j)=rhs(i,j)-2.0*t*rhs(i,k);
				}

				rhs(k,k)=alpha;

				for(int i=k+1; i<stRow; i++)
					rhs(i,k)=0.0;
			}
		}

		for(int i=0; i<stRow-1; i++)
			for(int j=i+1; j<stRow;j++)
				swap(rhq(i,j), rhq(j,i));
		back[0]=rhq;  //��ֵΪ�ֵ
		return back;
}



//����ֽ�-�Գ����������Cholesky�ֽ�
Matrix Matlab2c::chol(Matrix& a)
{
	Matlab2c::CheckLicense();
	int iReValue= isSymmetryRegular(a, 1);	//�б�Գ�����
	if(iReValue < 2)
	{
		throw_logic_error("Cholesky����ֽ�Ҫ���������");
		return NULL;
	}

	int stRank = a.column;	// �������

	Matrix p(a);				//����һmatrix������rhs��ʼ��

	p.data[0] = std::sqrt(p.data[0]); 
	for(int i=1; i<stRank; i++)
		p.data[i*p.column] /= p.data[0];
	for(int j=1; j<stRank; j++)
	{
		for(size_t k=0; k<j; k++)
			p(j,j) -= p(j,k) * p(j,k);
		p(j,j)= std::sqrt(p(j,j));
		for(int i=j+1; i<stRank; i++)
		{
			for(int k=0; k<j; k++)
				p(i,j) -= p(i,k) * p(j,k);
			p(i,j) /= p(j,j);
		}
	}
	for(int i=0; i<stRank-1; i++)
		for(int j=i+1; j<stRank; j++)
			p(i,j)=0;

	return p;		//��������ʽֵ
}
