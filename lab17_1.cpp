#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void randData(double *dPtr,int N,int M){
	for(int i=0; i<N*M; i++){
		*(dPtr+i) = rand()%101/100.0;
	}
}

void showData(double *dPtr,int N,int M){
	cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << *(dPtr+i);
        if(i%M==M-1) cout << endl;
        else cout << " ";
    }
}

void findRowSum(const double *dPtr,double *sumRow,int N,int M){
	for(int i = 0; i < N; i++){
		sumRow[i] = 0;
		for(int j = 0; j < M; j++){
			sumRow[i] += *(dPtr+j+M*i);
		}
    }
}

void findColSum(const double *dPtr,double *sumCal,int N,int M){
	for(int j = 0; j < M; j++){
			sumCal[j] = 0;
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			sumCal[j] += *(dPtr+j+M*i);
		}
    }
}