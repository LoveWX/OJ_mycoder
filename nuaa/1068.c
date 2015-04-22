#include<stdio.h>

char board[10];
int tx,to,nx,no;

void checkline(int s,int step)
{
	if(board[s]==board[s+step]&&board[s+step]==board[s+step+step])
	{
		if(board[s]=='X')
			tx++;
		else if(board[s]=='O')
			to++;
	}
}

int main()
{
	int i;
	while(1)
	{
		gets(board);
		if(board[0]=='e')
			break;
		tx=0;
		to=0;
		nx=0;
		no=0;
		for(i=0;i<9;i++)
		{
			if(board[i]=='X')
				nx++;
			else if(board[i]=='O')
				no++;
		}
		if(!(nx-no==1||nx==no))
		{
			printf("invalid\n");
			continue;
		}
		for(i=0;i<3;i++)
		{
			checkline(i,3);
			checkline(i+i+i,1);
		}
		checkline(0,4);
		checkline(2,2);
		if((to>1)||(tx>0&&to>0))
		{
			printf("invalid\n");
			continue;
		}
		if(nx!=no&&to>0)
		{
			printf("invalid\n");
			continue;
		}
		if(nx==no&&tx>0)
		{
			printf("invalid\n");
			continue;
		}
		if(nx+no<9&&tx==0&&to==0)
		{
			printf("invalid\n");
			continue;
		}
		printf("valid\n");
	}
	return 0;
}
/*
XXXOO.XXX
XOXOXOXOX
OXOXOXOXO
XXOOOXXOX
XO.OX...X
.XXX.XOOO
X.OO..X..
OOXXXOOXO
XXXXXXOOO
XOXOOOXOX
OXOXXXOXO
.........
XXXOOO...
X.X...O.O
XXXO.O.O.
end
invalid
valid
invalid
valid
valid
invalid
invalid
invalid
invalid
invalid
valid
invalid
invalid
invalid
invalid
*/