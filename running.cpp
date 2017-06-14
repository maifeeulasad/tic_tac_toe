#include<bits/stdc++.h>
int best(char board[3][3],char hsep,char boss);
void spe_col(void);
using namespace std;
struct ttt
{
	char board[3][3];
	char hsep;
	char boss;
};
void init_bor(char board[3][3])
{
	for(int i=0;i<3;i++)
    {
		for(int j=0;j<3;j++)
			board[i][j]='.';
	}
}
void coi_colr(void)
{
    int que;
    while(1)
    {
        cout << "Want to change color to  ? (1 or 0) " << endl;
        cin >> que;
        if(que==1)
        {
            spe_col();
            break;
        }
        else if(que==0)
            break;
        else
            system("cls");
    }
}
void spe_col(void)
{
    bool que;
    cout << "Please enter only 1 or 0 " << endl;
    cout << "White in blue ? ";
    cin >> que;
    if(que==1)
    {
        system("Color 1F");
        return;
    }
    cout << "White in green ? ";
    cin >> que;
    if(que==1)
    {
        system("Color 2F");
        return;
    }
    cout << "White in light blue ? ";
    cin >> que;
    if(que==1)
    {
        system("Color 3F");
        return;
    }
    cout << "White in magenta ? ";
    cin >> que;
    if(que==1)
    {
        system("Color 4F");
        return;
    }
    cout << "White in violate ? ";
    cin >> que;
    if(que==1)
        system("Color 5F");
    else
    {
        cout << "Sorry no more color " << endl << "Want to select again ?(1 to do so ,else 0) " << endl;
        cin >> que;
        if(que==1)
            spe_col();
    }
}
void print(char board[3][3])
{
    system("cls");
    cout << "----------------" <<endl;
	for(int i=0;i<3;i++)
    {
		for(int j=0;j<3;j++)
		{
		    cout << "|";
			cout << "  ";
			cout << board[i][j] << " ";
		}
		cout << "|";
		if(i==0 || i==1)
            cout << endl;
	}
	cout << endl << "----------------" <<endl;
	cout << endl << endl;
}
char check_win(char board[3][3])
{
	if (board[0][0]!='.' && (board[0][0]==board[0][1] && board[0][0]==board[0][2] || board[0][0]==board[1][0] && board[0][0]==board[2][0] || board[0][0]==board[1][1] && board[0][0]==board[2][2]))
		return board[0][0];
	if (board[1][1]!='.' && (board[1][1]==board[1][0] && board[1][1]==board[1][2] || board[1][1]==board[0][1] && board[1][1]==board[2][1] || board[1][1]==board[2][0] && board[1][1]==board[0][2]))
		return board[1][1];
	if (board[2][2]!='.' && (board[2][2]==board[0][2] && board[2][2]==board[1][2] || board[2][2]==board[2][0] && board[2][2]==board[2][1]))
		return board[2][2];
	return 0;
}
void loca_sel(char board[3][3],char hmsep)
{
	while(1)
    {
		int row=0,col=0;
		while(1)
        {
			cout << "Row = ? ";
			cin >> row;
			if(row>=1 && row<=3)
				break;
			cout << "Please enter between 1 and 3" << endl;
		}
		while(1)
        {
			cout << "Column = ? ";
			cin >> col;
			if(col>=1 && col<=3)
				break;
			cout << "Please enter between 1 and 3 " << endl;
		}
		if(board[row-1][col-1]=='.')
        {
			board[row-1][col-1]=hmsep;
			break;
		}
		else
			cout << "Place somewhere else ,location taken" << endl;
	}
}
char boss_choice(char hsep)
{
	char boss_char;
	if(hsep=='x' || hsep=='X')
		boss_char='o';
	else
		boss_char='x';
	return boss_char;
}
char choice(void)
{
    system("cls");
    cout << "Choose 'o' or 'O' or 'x' or 'X'  ";
    char a;
    cin >> a;
    return a;
}
void game_on(char board[3][3],char hsep,char boss)
{
	int moves=0;
	int done=0;
	while(moves++<9)
    {
		loca_sel(board,hsep);
		print(board);
		if(check_win(board))
		{
			cout << "Congratulations !!!" << endl << endl << "You just beat an AI" << endl << endl;
            break;
		}
		if(moves==9)
			break;
		int place=best(board,boss,hsep);
		int row=place/10;
		int col=place%10;
		board[row][col]=boss;
		moves++;
		print(board);
		if(check_win(board))
		{
			cout << boss << "(computer) won!" <<endl;
			cout << "Better luck next time !" << endl;
			done=1;
			break;
		}
	}
	if(done==0)
        cout<< "It's a tie" << endl;
}
int res(char board[3][3],char hsep,char boss)
{
	int max_sco=-9999;
	int curr_sco=0;
	if(check_win(board)==hsep)
		return 1000;
	else if(check_win(board)==boss)
		return -1000;
	for(int r=0;r<3;r++)
    {
		for(int c=0;c<3;c++)
		{
			if(board[r][c]=='.')
			{
				board[r][c]=hsep;
				curr_sco=-(res(board,boss,hsep));
				board[r][c]='.';
				if(curr_sco>=max_sco)
					max_sco=curr_sco;
			}
		}
	}
	if(max_sco==-9999 || max_sco==0)
		return 0;
	else if(max_sco<0)
		return max_sco+1;
	else if(max_sco>0)
		return max_sco-1;
}
int best(char board[3][3],char hsep,char boss)
{
	int max_sco=-9999;
	int good_row=0;
	int good_col=0;
	int curr_sco=0;
	for(int r=0;r<3;r++)
    {
		for(int c=0;c<3;c++)
		{
			if(board[r][c]=='.')
            {
				board[r][c]=hsep;
				curr_sco=-(res(board,boss,hsep));
				board[r][c]='.';
				if(curr_sco>=max_sco)
				{
					max_sco=curr_sco;
					good_row=r;
					good_col=c;
				}
			}
		}
	}
	return (10*good_row+good_col);
}
int main()
{
    coi_colr();
	ttt game;
	init_bor(game.board);
    game.hsep=choice();
    game.boss=boss_choice(game.hsep);
    print(game.board);
    game_on(game.board,game.hsep,game.boss);
    cin.ignore();
    char exi[10000];
    cout << "Press anything to exit : " ;
    gets(exi);
    return 0;
}
