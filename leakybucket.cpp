#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#define bucketsize 512
using namespace std;
void bktinput(int a,int b);
int main()
{
	int op,pktsize;
	cout<<"enter output rate";
	cin>>op;
	for(int i=1;i<=5;i++)
	{
		usleep(rand()%1000);
		pktsize=rand()%1000;
		cout<<"\n Packet no"<<i<<"\tPacket size="<<pktsize;
		bktinput(pktsize,op);
	}
	return 0;
}
void bktinput(int a,int b)
{
	if(a>bucketsize)
		cout<<"\n\t\tBucket overflow";
	else
	{
		usleep(500);
		while(a>b)
		{
			cout<<"\n\t\t"<<b<<"bytes outputed";
			a-=b;
			usleep(500);
		}
		if(a>0)
			cout<<"\n\t\tLast"<<a<<"bytes sent\t\n";
	}
}


bmsce@bmsce-Precision-T1700:~/Desktop$ g++ leak.cpp
bmsce@bmsce-Precision-T1700:~/Desktop$ ./a.out
enter output rate300

 Packet no1	Packet size=886
		Bucket overflow
 Packet no2	Packet size=915
		Bucket overflow
 Packet no3	Packet size=335
		300bytes outputed
		Last35bytes sent	

 Packet no4	Packet size=492
		300bytes outputed
		Last192bytes sent	

 Packet no5	Packet size=421
		300bytes outputed
		Last121bytes sent
