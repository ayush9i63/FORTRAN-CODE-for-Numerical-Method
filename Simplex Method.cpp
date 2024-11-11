#include<iostream>
#include<iomanip>
#include<climits>
using namespace std;

int main() {
	int var,cons,problem,less,eq,great;
	cout.precision(2);

l1:
	cout<<"\nEnter total numbers of variables: ";
	cin>>var;
	cout<<"\nEnter total numbers of constraints: ";
	cin>>cons;
	cout<<"\nEnter total numbers of <= constraints: ";
	cin>>less;
	cout<<"\nEnter total numbers of = constraints: ";
	cin>>eq;
	cout<<"\nEnter total numbers of >= constraints: ";
	cin>>great;

	if((less+eq+great)!=cons) {
		cout<<"\nWrong inputs..."<<"\nRe-enter :";
		goto l1;
	}

	double C[var+cons+great];
	double A[cons][var+cons+great];
	double B[cons];

	cout<<"\nEnter '1' for maximisation problem and '0' for minimisation problem: ";
	cin>>problem;

	cout<<"\nEnter the coefficient of objective function: ";
	for(int i=0; i<var; i++) {
		cin>>C[i];
		if(problem==0) C[i]=-C[i];
	}
	for(int i=0; i<less; i++)
		C[var+i]=0;
	for(int i=less; i<cons; i++)
		C[var+i]=INT_MIN;
	for(int i=0; i<great; i++)
		C[var+cons+i]=0;

	cout<<"\nEnter the coefficient of contraints: ";
	for(int i=0; i<cons; i++) {
		for(int j=0; j<var; j++)
			cin>>A[i][j];
		for(int j=0; j<cons; j++) {
			if (i==j) A[i][var+j]=1;
			else A[i][var+j]=0;
		}
	}
	for(int i=0; i<great; i++) {
		for(int j=0; j<cons; j++) {
			if(A[j][i+var+less+eq]==0) A[j][i+cons+var]=0;
			else A[j][i+cons+var]=-1;
		}
	}
	cout<<"\nEnter the solution column: ";
	for(int i=0; i<cons; i++) cin>>B[i];

	cout<<"\n--------------------------------------------------------------------SIMPLEX METHOD--------------------------------------------------------------------";

	cout<<"\n\nThus the given LPP is: ";
	if(problem==1) cout<<"\n\n\tmax: ";
	else cout<<"\n\n\tmin: ";
	for(int i=0; i<var; i++) {
		if(problem==0) cout<<-C[i]<<"x"<<i+1;
		else cout<<C[i]<<"x"<<i+1;
		if(i<var-1) cout<<" + ";
	}

	cout<<"\n\nsubject tO:\n\n";
	for(int i=0; i<cons; i++) {
		for(int j=0; j<var; j++) {
			cout<<"\t"<<A[i][j]<<"x"<<j+1;
			if(j<var-1) cout<<" + ";
		}
		if(i<less) cout<<" <= ";
		else if(i>=less && i<less+eq) cout<<" =  ";
		else cout<<" >= ";
		cout<<B[i];
		cout<<endl;
	}
	cout<<"\n\t\tall xj >= 0\n\n";

	cout<<"\nSIMPLEX TABLE:\n\n";

	// Simplex

	double z_c[var+cons+great];
	double cb[cons];
	double variable[cons];
	double sol[cons];
	double min_ratio[cons];
	double min,min2;
	double alternate[var+great];
	int enter,exit,flag,count=cons;
	double pivot,ratio,res;

	for(int i=0; i<cons; i++) {
		cb[i]=C[var+i];
		sol[i]=B[i];
		variable[i]=var+i;
	}

	while (true) {

		min=INT_MAX;
		for(int j=0; j<var+cons+great; j++)
		{
			z_c[j]=0;
			for(int i=0; i<cons; i++) z_c[j] += A[i][j]*cb[i];
			z_c[j] -= C[j];
			if(min>z_c[j]) {
				min=z_c[j];
				enter=j;
			}
		}
l3:
		min2=INT_MAX;
		for(int i=0; i<cons; i++) {
			if(A[i][enter]>0) {
				min_ratio[i]=sol[i]/A[i][enter];
				if(min2>min_ratio[i]) {
					min2=min_ratio[i];
					exit=i;
				}
			}
			else min_ratio[i]=-1;
		}

		//printint simplex table-----------------------------------------------------------------------------------
		cout<<setw(10)<<"  "<<setw(10)<<"  "<<setw(3)<<"|"<<setw(10)<<"Cj"<<setw(3)<<"|";
		for(int j=0; j<cons+var+great; j++) {
			cout<<setw(10)<<C[j];
		}
		cout<<setw(3)<<"|"<<setw(10)<<"  "<<endl;

		cout<<setw(10)<<"CB"<<setw(10)<<"XB"<<setw(3)<<"|"<<setw(10)<<"Sol"<<setw(3)<<"|";
		for(int i=0; i<cons+var+great; i++) cout<<setw(9)<<"x"<<i+1;
		cout<<setw(3)<<"|"<<setw(13)<<"Min Ratio"<<endl;

		for(int i=0; i<(10*(var+cons+great)+55); i++) cout<<"-";
		cout<<endl;

		for(int i=0; i<cons; i++) {
			cout<<setw(10)<<cb[i]<<setw(9)<<"x"<<variable[i]+1<<setw(3)<<"|"<<setw(10)<<sol[i]<<setw(3)<<"|";
			for(int j=0; j<cons+var+great; j++) {
				cout<<setw(10)<<A[i][j];
			}
			if(min_ratio[i]>0) {
				cout<<setw(3)<<"|"<<setw(10)<<min_ratio[i];
				if(exit==i) cout<<" ->";
				cout<<endl;
			}
			else cout<<setw(3)<<"|"<<setw(10)<<"--"<<endl;
		}

		for(int i=0; i<(10*(var+cons+great)+55); i++) cout<<"-";
		cout<<endl;

		cout<<setw(10)<<"  "<<setw(10)<<"  "<<setw(3)<<"|"<<setw(10)<<"z_c"<<setw(3)<<"|";
		for(int j=0; j<cons+var+great; j++) {
			if(enter==j) cout<<setw(9)<<z_c[j]<<"b";
			else cout<<setw(10)<<z_c[j];
		}
		cout<<setw(3)<<"|"<<setw(10)<<"  "<<endl;
		cout<<endl<<endl;
		//printing complete-----------------------------------------------------------------------------------------

		//checking degeneracy

		for(int i=0; i<cons; i++) {
			if(sol[i]==0) {
				cout<<"\nThe solution is degenerate.\n";
				if(min<0) goto l5;
				else goto l6;
			}
		}

		//checking for unbounded solution
		if(min2==INT_MAX) {
			cout<<"\nSolution is Unbounded, thus we have no optimal solution.";
			goto l5;
		}


		if(min<0) {

			cb[exit]=C[enter];
			variable[exit]=enter;

			pivot=A[exit][enter];

			//using ert

			for(int i=0; i<cons+var+great; i++) A[exit][i]/=pivot;
			sol[exit]/=pivot;

			for(int i=0; i<cons; i++) {
				if(i!=exit) {
					ratio=A[i][enter];
					for(int j=0; j<var+cons+great; j++) {
						A[i][j] -= ratio*A[exit][j];
					}
					sol[i] -= ratio*sol[exit];
				}
			}
		}
		else break;
	}

	for(int i=0; i<cons; i++) {
		if(cb[i]==INT_MIN) {
			cout<<"Solution is Infeasible."<<endl;
			goto l5;
		}
	}

l6:
	cout<<"\nThe required optimal solution is given at: \n";
	cout.precision(10);
	res=0;
	for(int i=0; i<cons; i++) {
		cout<<"x"<<variable[i]+1<<" = "<<sol[i]<<endl;
		if(problem==0) res+=(-cb[i])*sol[i];
		else res+=(cb[i])*sol[i];
	}
	cout<<"all remaining xi = 0"<<endl;
	cout<<"The optimal value is: "<<res;

	if(count==cons) {
		for(int i=0; i<cons+great+var; i++) {
			if(i<cons) alternate[i]=variable[i];
			else for(int i=cons; i<cons+great+var; i++) alternate[i]=-1;
		}
	}

	for(int i=0; i<cons+var+great; i++) {
		flag=0;
		for(int j=0; j<cons+var+great; j++) {
			if(i==alternate[j]) {
				flag++;
				break;
			}
		}
		if(flag==0 && z_c[i]==0) {
			cout.precision(2);
			cout << "\n\nWe have an Altenate Optima.\n\n";
			enter=i;
			alternate[count++]=i;
			min=-1;
			goto l3;
		}
	}

l5:
	cout<<"\n\n--------------------------------------------------------------------SIMPLEX ENDS--------------------------------------------------------------------";

}