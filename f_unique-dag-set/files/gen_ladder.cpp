#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main(int argc,char*argv[])
{
  registerGen(argc,argv,1);
  int n=atoi(argv[1]);
  cout<<"1\n"<<n<<" "<<(n/2-1)*4<<"\n";
  for(int i=1;i*2+2<=n;i++)
  {
    cout<<i*2-1<<" "<<i*2+1<<"\n";
    cout<<i*2-1<<" "<<i*2+2<<"\n";
    cout<<i*2<<" "<<i*2+1<<"\n";
    cout<<i*2<<" "<<i*2+2<<"\n";
  }
}
