#include<iostream>
#include<math.h>

using namespace std;

int main()
{
  double T;
	double D=10.0;
	double dt=1E-6;
  double alpha=0.1;
  double dx=pow(D*dt/alpha,0.5);
	int N_x=2.0/ dx;
	double * in_u = new double[N_x];
	double * u = new double[N_x ];
	double * u_old =new double[N_x];
	double x =0.0;
  int m = 1.0/dx;
  bool centinela=false;
	for(int i=0;i<N_x;i++)
	{
		x=(dx*i);
		in_u[i]=exp(-0.5 * (x-1)*(x-1)/(0.1*0.1));
		u_old[i]=exp(-0.5 * (x-1)*(x-1)/(0.1*0.1));
  }
  while(!centinela)
  {
    T=T+dt;
		for(int i=1;i<N_x - 1 ;i++)
		{
			u[i]= in_u[i] + ( D * (dt/(dx*dx)) * ( -2.0*in_u[i] + in_u[i-1] + in_u[i+1] ) );
		}
		for(int i=1;i<N_x - 1 ;i++)
		{
		    in_u[i]=u[i];
        if(u[m]<=0.5)
        {
          centinela=true;
        }
    }
  }
  for(int i=0;i<N_x;i++)
	{
		x=(dx*i);
		cout<<x<<" "<<u[i]<<" "<<u_old[i]<<" "<<T<<endl;
	}
return 0;
}
