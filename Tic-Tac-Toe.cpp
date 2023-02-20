#include<bits/stdc++.h>
using namespace std;
int k=0;
char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
void print_board() {
    system("cls"); // Clear console
    printf("          TIC-TAC-TOE ");
    printf("\n\n");
    printf(" 	   |         |                         |         |         \n");
    printf("      %c    |    %c    |    %c            	 1     |   2     |    3     \n", board[0], board[1], board[2]);
    printf("    ______|_________|_______        _________|_________|_________\n");
    printf("	   |         |                         |         |          \n");
    printf("      %c    |    %c    |    %c          	 4     |   5     |    6    \n", board[3], board[4], board[5]);
    printf("    ______|_________|_______        _________|_________|_________\n");
    printf(" 	   |         |          	       |         |         \n");
    printf("      %c    |    %c    |    %c    	         7     |   8     |    9     \n", board[6], board[7], board[8]);
    printf("    	   |         |          	       |         |          \n");
    printf("\n");
}
void print_boardagain() {
    //system("cls"); // Clear console
    printf("\n\n");
    if(k==1)
    	cout<<"\nTIE\n";
    else if(k==3)
    	cout<<"YOU LOST BETER LUCK FOR NEXT TIME\n";
    printf("	  |          |                        \n");
    printf("     %c    |    %c     |    %c             \n", board[0], board[1], board[2]);
    printf("    _____|__________|_____        \n");
    printf("	  |          |                    \n");
    printf("     %c    |    %c     |    %c        \n", board[3], board[4], board[5]);
    printf("    _____|__________|_____        \n");
    printf("	  |          |          	              \n");
    printf("     %c    |    %c     |    %c    	      \n", board[6], board[7], board[8]);
    printf("	  |          |          	           \n");
    printf("\n");
}
int get_user_move() 
{
    int move;
    printf("Enter your move (1-9): ");
    scanf("%d", &move);
    while (move < 1 || move > 9 || board[move - 1] != ' ') 
    {
        printf("Invalid move. Enter your move (1-9): ");
        scanf("%d", &move);
    }
    return move - 1;
}

vector<int> mark;

void assign() 
{
    for(int i=0; i<10; i++)
        mark.push_back(i);
}

void rem(int number)
{
	vector<int>::iterator it;
    it=find(mark.begin(),mark.end(),number);
    
    if(it!=mark.end())
        mark.erase(it);
}

int found(int n)
{
    for (int i=1;i<=9;i++)
    {
        if(mark[i]==n)
            return 1;
    }
    return 0;
}


int iswin()
{
    
    if(board[0]=='O' && board[2]=='O')        //1 st row
        if(board[1]==' ')
            return 2;
    
    if(board[0]=='O' && board[1]=='O')
        if(board[2]==' ')
            return 3;
    
    if(board[1]=='O' && board[2]=='O')   
        if(board[0]==' ')
            return 1;
        
    if(board[0]=='O' && board[3]=='O')       //1 st col
        if(board[6]==' ')
            return 7;
        
    if(board[0]=='O' && board[6]=='O')
        if(board[3]==' ')
            return 4;
    
    if(board[3]=='O' && board[6]=='O')
        if(board[0]==' ')
            return 1;
        
    if(board[3]=='O' && board[4]=='O')       //2 nd row
        if(board[5]==' ')
            return 6;
    
    if(board[3]=='O' && board[5]=='O')
        if(board[4]==' ')
            return 5;
       
    if(board[5]=='O' && board[4]=='O')
        if(board[3]==' ')
            return 4;
        
    if(board[6]=='O' && board[7]=='O')       //3 rd row
        if(board[8]==' ')
            return 9;
        
    if(board[6]=='O' && board[8]=='O')
        if(board[7]==' ')
            return 8;
        
    if(board[8]=='O' && board[7]=='O')
        if(board[6]==' ')
            return 7; 
        
    if(board[1]=='O' && board[4]=='O')       //2 rd col
        if(board[7]==' ')
            return 8;
        
    if(board[1]=='O' && board[7]=='O')
        if(board[4]==' ')
            return 5;
        
    if(board[4]=='O' && board[7]=='O')
        if(board[1]==' ')
            return 2;
        
    if(board[5]=='O' && board[2]=='O')       //3 rd col
         if(board[8]==' ')
            return 9;
        
    if(board[2]=='O' && board[8]=='O')
         if(board[5]==' ')
            return 6;
        
    if(board[8]=='O' && board[5]=='O')
        if(board[2]==' ')
            return 3;
        
    if(board[0]=='O' && board[4]=='O')       //primary diagonal
        if(board[8]==' ')
            return 9;
        
    if(board[0]=='O' && board[8]=='O')
        if(board[4]==' ')
            return 5;
        
    if(board[4]=='O' && board[8]=='O')
        if(board[0]==' ')
            return 1;
        
    if(board[2]=='O' && board[4]=='O')       //secondry diagonal
         if(board[6]==' ')
            return 7;
        
    if(board[2]=='O' && board[6]=='O')
         if(board[4]==' ')
            return 5;
        
    if(board[6]=='O' && board[4]=='O')
         if(board[2]==' ')
             return 3; 
    
    return 0;
}

int issafe()
{
    
    if(board[0]=='X' && board[2]=='X')        //1 st row
        if(board[1]==' ')
            return 2;
    
    if(board[0]=='X' && board[1]=='X')
        if(board[2]==' ')       
             return 3;
    
    if(board[1]=='X' && board[2]=='X')   
        if(board[0]==' ')
            return 1;
        
    if(board[0]=='X' && board[3]=='X')       //1 st col
        if(board[6]==' ')
            return 7;
        
    if(board[0]=='X' && board[6]=='X')
        if(board[3]==' ')
            return 4;
        
    if(board[3]=='X' && board[6]=='X')
        if(board[0]==' ')
            return 1;
        
    if(board[3]=='X' && board[4]=='X')       //2 nd row
        if(board[5]==' ')
            return 6;
        
    if(board[3]=='X' && board[5]=='X')
        if(board[4]==' ')
            return 5;
        
    if(board[5]=='X' && board[4]=='X')
        if(board[3]==' ')
            return 4;
        
    if(board[6]=='X' && board[7]=='X')       //3 rd row
        if(board[8]==' ')
            return 9;
        
    if(board[6]=='X' && board[8]=='X')
        if(board[7]==' ')
            return 8;
        
    if(board[8]=='X' && board[7]=='X')
        if(board[6]==' ')
            return 7; 
        
    if(board[1]=='X' && board[4]=='X')       //2 rd col
        if(board[7]==' ')
            return 8;
        
    if(board[1]=='X' && board[7]=='X')
        if(board[4]==' ')
            return 5;
        
    if(board[4]=='X' && board[7]=='X')
        if(board[1]==' ')
            return 2;
            
    if(board[5]=='X' && board[2]=='X')       //3 rd col
         if(board[8]==' ')
            return 9;
        
    if(board[2]=='X' && board[8]=='X')
         if(board[5]==' ')
            return 6;
        
    if(board[8]=='X' && board[5]=='X')
        if(board[2]==' ')
            return 3;        
        
    if(board[0]=='X' && board[4]=='X')       //primery diagonal
         if(board[8]==' ')
            return 9;
        
    if(board[0]=='X' && board[8]=='X')
         if(board[4]==' ')
            return 5;
        
    if(board[4]=='X' && board[8]=='X')
         if(board[0]==' ')
            return 1;
        
    if(board[2]=='X' && board[4]=='X')       //secondry diagonal
         if(board[6]==' ')
            return 7;
        
    if(board[2]=='X' && board[6]=='X')
         if(board[4]==' ')
            return 5;
        
    if(board[6]=='X' && board[4]=='X')
         if(board[2]==' ')
             return 3;
    return 0;        
}
int main() {
    int i=0;
    char winner = '\0';
    assign();
    int flag=0;
    while (winner == '\0') 
    { 
        print_board();
        int move,s,w;
        move = get_user_move();
        board[move] = 'X';
        rem(move+1);
        
        if(i==4)
        {
        	k=1;
            //cout<<"\nTIE\n";
            break;
        }
        
        if(i==0)
        {
            if(board[4]==' ')
            {
                board[4]='O';
                rem(5);
            }
            else
            {
                flag=1;
                board[0]='O';
                rem(1);
            }
            
        }
        else 
        {
            if(i==1)
            {
                s=issafe();
                if(s)
                {
                    board[s-1]='O';
                    rem(s);
                }
                else
                {
                        if((board[0]=='X' || board[2]=='X' || board[6]=='X' || board[8]=='X') && flag==0)
                        {
                            board[7]='O';
                            rem(8);
                        }
                        else if(flag==1)
                        {
                        
                            board[6]='O';
                            rem(7);
                        }
                        else
                        {
                            if(board[5]=='X' or board[7]=='X')
                            {
                                if(board[8]==' ')
                                {
                                    board[8]='O';
                                    rem(9);
                                }
                            }
                            else if(board[1]=='X' or board[3]=='X')
                            {
                                if(board[0]==' ')
                                {
                                    board[0]='O';
                                    rem(1);
                                }
                            }
                            else if(board[1]=='X' or board[5]=='X')
                            {
                                if(board[2]==' ')
                                {
                                    board[2]='O';
                                    rem(3);
                                }
                            }
                            else if (board[3]=='X' or board[7]=='X')
                            {
                                if(board[6]==' ')
                                {
                                    board[6]='O';
				                            rem(7);
        
                                }
                            }
                            else
                            {
                                board[mark[1]-1]='O';
                                rem(mark[1]);
                            }
                        }    
                }
            }
            else
            {
                s=issafe();
                w=iswin();
                if(w)
                {
                    board[w-1]='O';
                    k=3;
                    rem(w);
                    winner='Y';
                  //  cout<<"YOU LOST BETER LUCK FOR NEXT TIME\n";
                    break;
                }
                else
                {
                    if(s)
                    {
                        
                        board[s-1]='O';
                        
                        rem(s);
                    }
                    else
                    {
                        board[mark[1]-1]='O';
                            
                        rem(mark[1]);
                    }
                }
            }
        }
       
        i++;
            
    }
    print_boardagain();
}
