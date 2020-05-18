//F

#include <iostream>
using namespace std;


int tan(int*hi,int num,int high)   //找能拦截该导弹的系统中，允许高度最小的  无系统能拦截时，返回-1 
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
				m=k;          //更新允许的最小高度编号 
		}
	}
	return m;
}

int ans(int num)
{
	int h[1000],min=1,hiest[1000]; //存每个系统能拦截的高度 
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
			min++;		 //无系统可拦截，则需要一个新的系统 
		}
		else
		{
			low=tan(hiest,min,h[i]);
			hiest[low]=h[i];      //更新编号为low的系统 能拦截的高度 
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

