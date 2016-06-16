// ----------------------------------------------------------------------------
//
// ----------------------------- Tic-Tac-Toe-------------------------------------
//
// ----------------------------------------------------------------------------
//
//  Purpose  : Implement methods declared in "tic.h" header file required to play tic-tac-toe game
//
//  Author   : Chetan Kumar Parakh
//  Date     : 4/29/2016
//
// ----------------------------------------------------------------------------




#include"tic.h";
using namespace std;

//A board with all blank spaces.
tBoard::tBoard()
{
	for (int i = 0; i < 9; i++)
	{
		pos[i] = " ";
	}

	moves_rem = 9;
}

//Makes a valid move on the board
bool tBoard::move(symbol m, int x, int y)
{
	if (x>2 || y > 2)
	{
		return(false);
	}
	string sign;
	bool mtemp = false;
	switch (m)
	{
	case X: sign = "X";
		break;
	case O: sign = "O";
		break;
	case BLANK: sign = " ";
		break;
	default:
		break;
	}

	if (x == 0 && pos[y]==" ")
	{
		pos[y] = sign;
		mtemp = true;
	}
	if (x == 1 && pos[y+3]==" ")
	{
		pos[y+3] = sign;
		mtemp = true;
	}
	if (x == 2 && pos[y+6]==" ")
	{
		pos[y+6] = sign;
		mtemp = true;
	}
	if (mtemp == true && sign!=" ")
	{
		moves_rem--;
	}
	return(mtemp);
}

//Return symbol stored in pos[i]; where 0<=0<9
string tBoard::getpos(int a) const
{
	return(pos[a]);
}

//To check if the game is over or not
bool tBoard::game_over()
{
	if (moves_rem > 7)
	{
		return(false);
	}
	for (int x = 0; x < 3; x++)
	{
		if (pos[0 + (3 * x)] != " ")
		{
			if (pos[0 + (3 * x)] == pos[1 + (3 * x)] && pos[1 + (3 * x)] == pos[2 + (3 * x)])
			{
				win = getpos(0 + (3 * x));
				return(true);
			}
		}
	}

	for (int y = 0; y < 3; y++)
	{
		if (pos[y] != " ")
		{
			if (pos[y] == pos[y + 3] && pos[y + 3] == pos[y + 6])
			{
				win = getpos(y);
				return(true);
			}
		}
	}

	if (pos[0] == pos[4] && pos[4] == pos[8])
	{
		if (pos[0] != " ")
		{
			win = getpos(0);
			return(true);
		}
	}

	if (pos[2] == pos[4] && pos[4] == pos[6])
	{
		if (pos[2] != " ")
		{
			win = getpos(2);
			return(true);
		}
	}

	if (moves_rem == 0)
	{ 
		win = "BLANK";
		return(true);
	}

	return(false);
}

//To decide the winner
symbol tBoard::winner()
{
	symbol temp;
	if (win == "X")
	{
		temp = X;
	}
	else if (win == "O")
	{
		temp = O;
	}
	else if (win == "BLANK")
	{
		temp = BLANK;
	}
	else
		temp = BLANK;

	return(temp);
}

//To print object of class tBoard
ostream & operator<<(ostream& os, const tBoard& myTable)
{
	os << " | 0 | 1 | 2 |" << endl;
	os << "+------------+" << endl;
	os << "0| " << myTable.getpos(0) << " | " << myTable.getpos(1) << " | " << myTable.getpos(2) << " |" << endl;
	os << "+------------+" << endl;
	os << "1| " << myTable.getpos(3) << " | " << myTable.getpos(4) << " | " << myTable.getpos(5) << " |" << endl;
	os << "+------------+" << endl;
	os << "2| " << myTable.getpos(6) << " | " << myTable.getpos(7) << " | " << myTable.getpos(8) << " |" << endl;
	os << "+------------+" << endl;
	return(os);
}
