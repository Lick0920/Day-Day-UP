//F

#include <iostream>
using namespace std;


int tan(int*hi,int num,int high)   //�������ظõ�����ϵͳ�У�����߶���С��  ��ϵͳ������ʱ������-1 
{
	int k,m=-1;
	for(k=0;k<num;k++) 
	{
		if(hi[k]<high)
			continue;
		else
		{
			if(m<0) m=k;
			else if(hi[k]<hi[m]) 
				m=k;          //�����������С�߶ȱ�� 
		}
	}
	return m;
}

int ans(int num)
{
	int h[1000],min=1,hiest[1000]; //��ÿ��ϵͳ�����صĸ߶� 
	int i,j=0,low;
	
	for(i=0;i<num;i++)
	{	cin>>h[i];
	} 
	hiest[0]=h[0];
		
	for(i=0;i<num;i++)
	{ 
		if(tan(hiest,min,h[i])<0)
		{	
			hiest[min]=h[i];
			min++;		 //��ϵͳ�����أ�����Ҫһ���µ�ϵͳ 
		}
		else
		{
			low=tan(hiest,min,h[i]);
			hiest[low]=h[i];      //���±��Ϊlow��ϵͳ �����صĸ߶� 
		} 		
	}
	return min;
}

int main()
{
	int num; 
	while(scanf("%d",&num)!= EOF)
	{
		if(num<=0) return 0;
		cout<<ans(num)<<endl;
	}
	system("pause");
	return 0;
}

