#include<iostream>

using namespace std;

double ** matrix_product(double ** A, double ** B,int n_A, int n_B, int m_A, int m_B);
double ** get_Matrix(int N, int M);
int main()
{
	//Dimensiones de cada matriz, donde n representa las filas y m las columnas
	int n_A;
	int m_A;
	int n_B;
	int m_B;
	//Mensajes para pedir las dimensiones de cada una de las matrices a multiplicar
	cout<<"Este programa calcula el producto matricial de dos matrices."<<endl;
	cout<<"Ingrese las filas de la primera matriz a multiplicar:";
	cin >> n_A;
	cout<<"Ingrese las columnas de la primera matriz a multiplicar:";
	cin >> m_A;
	cout<<"Ingrese las filas de la segunda matriz a multiplicar:";
	cin >> n_B;
	cout<<"Ingrese las columnas de la segunda matriz a multiplicar:";
	cin >> m_B;
	//Verificar que el producto matricial exista
	if(m_A!=n_B)
	{
		cout<<"Las matrices no se pueden multiplicar, debido a las dimensiones dadas."<<endl;
		return 0;
	}
	//Requerir los valores de la primera matriz
	cout<<"En primer lugar debe ingresar los valores de la primera matriz a multiplicar."<<endl;
	double ** A = get_Matrix(n_A,m_A);
	//Requerir los valores de la segunda matriz
	cout<<"Ahora debe ingresar los valores de la segunda matriz a multiplicar."<<endl;
	double ** B = get_Matrix(n_B,m_B);
	//realizar el producto matricial
	double ** C = matrix_product(A,B,n_A,m_A,n_B,m_B);
	//Imprimir el producto matricial
	cout<<"El producto matricial es igual a:"<<endl;
	//Iteracion para recorrer las filas de la matriz
	for(int i=0;i<n_A;i++)
	{
		//Iteracion para recorrer las columnas de la matriz 
		for(int j=0;j<m_B;j++)
		{
		//Impresion del  i-esimo renglon de la matriz
		cout<<C[i][j]<<" ";
		}
		cout<<endl;
	}	
	return 0;
}
double ** matrix_product(double ** A, double ** B,int n_A, int m_A, int n_B, int m_B)
{
	//Matriz resultado del producto junto con su inicializacion
	double ** prod=new double*[n_A];
	for(int i=0;i<n_A;i++)
	{
		prod[i]=new double[m_B];
	}
	//Iteracion para recorrer las filas de la matriz resultado
	for(int i=0;i<n_A;i++)
	{
		//Iteracion para recorrer las columnas de la matriz resultado
		for(int j=0;j<m_B;j++)
		{
			//variable para guardar el producto punto entre la fila i y la columa j
			double p=0.0;
			//Iteraccion que recorre la fila i, con la vairable k y la columna j, con la variable l
			for (int k=0, l=0 ; k < m_A && l < n_B ; k++, l++)
				{
					//Producto punto
					p=p+(A[i][k]*B[l][j]);
				}
			//Asignar el producto punto a la vairble en la posicion i,j
			prod[i][j]=p;
		} 
	}
	return prod;
}
double ** get_Matrix(int N, int M)
{
	//Matriz resultado del producto junto con su inicializacion
	double ** m=new double*[N];
	for(int i=0;i<N;i++)
	{
		m[i]=new double[M];
	}
	//Iteracion para recorrer las filas de la matriz dada por el usuario
	for(int i=0;i<N;i++)
	{
		//Iteracion para recorrer las columnas de la matriz dada por el usuario
		for(int j=0;j<M;j++)
		{
			//Mensaje para que el usuario identifique el valor que debe ingresar
			cout<<"Ingrese el valor "<<i<<", "<<j<<":";
			//Variable para guardar el valor que el usuario ingresa
			double v;
			cin >> v;
			//Se asigna el valor que el usuario ingresa a la posicion i,j
			m[i][j]=v;
		}
	}
	cout<<"La matriz ingresada fue:"<<endl;
	//Iteracion para recorrer las filas de la matriz dada por el usuario
	for(int i=0;i<N;i++)
	{
		//Iteracion para recorrer las columnas de la matriz dada por el usuario
		for(int j=0;j<M;j++)
		{
		//Impresion del  i-esimo renglon de la matriz
		cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
	return m;
}

