#include<stdio.h>

int main()
{
	int left,right,top,bottom;
	int x,y;
	while(1)
	{
		scanf("%d%d",&x,&y);
		if(x==0&&y==0)
			break;
		left=x;
		right=x;
		top=y;
		bottom=y;
		while(1)
		{
			scanf("%d%d",&x,&y);
			if(x==0&&y==0)
				break;
			if(x<left)
				left=x;
			if(x>right)
				right=x;
			if(y<bottom)
				bottom=y;
			if(y>top)
				top=y;
		}
		printf("%d %d %d %d\n",left,bottom,right,top);
	}
	return 0;
}
