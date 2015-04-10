#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void print(int board[4][4]);
int checkwin(int board[4][4]);
void AImove(int board[4][4]);
void setPlace(int a, int board[4][4]);
bool isTaken(int a, int board[4][4]);

int main()
{
	srand(time(0));
	int board[4][4] = {};
	print(board);
	int x = 1;
	while (checkwin(board) == 0)
	{
		system("cls");
		print(board);
		if (x%2 == 1)
		{
			int inputrow;
			int inputcolumn;
			cout << "\nPlayer 1, select row: ";
			cin >> inputrow;
			cout << "\nPlayer 1, select column: ";
			cin >> inputcolumn;
			
			while ((!(inputrow >=1 && inputrow <=3 && inputcolumn >=1 && inputcolumn <=3)) || ((inputrow >=1 && inputrow <=3 && inputcolumn >=1 && inputcolumn <=3) && board[inputrow][inputcolumn] !=0))
			{
			cout << "\nError!\n\nPlayer 1, select row: ";
			cin >> inputrow;
			cout << "\nPlayer 1, select column: ";
			cin >> inputcolumn;
			}


			board[inputrow][inputcolumn] = 1;
		}
		else
		{
			AImove(board);
		}
		x++;
	}
	system("cls");
		print(board);
	if (checkwin(board)!=-1)
		cout << "Player " << checkwin(board) << "won!";
	else 
		cout << "Cat's Game!";
			
			


	int rand;
	cin >> rand;

}


void print (int board[4][4])
{
	cout << "You can't beat me!!\n";
	for (int row = 1; row <=3; row++)
	{
		cout << "\n";
		for (int column = 1; column <= 3; column++)
		{
			cout << setw(4) << " ";
			if (column !=3)
			cout << "\t|";
		}
		cout << "\n";
		for (int column = 1; column <= 3; column++)
		{
			if (board[row][column] == 0)
				cout << setw(4) << " ";
			else if (board[row][column] == 1)
				cout << setw(4) << "X";
			else
				cout << setw(4) << "O";
			
			if (column != 3)
			cout << "\t|";
		}
		cout << "\n";
		for (int column = 1; column <= 3; column++)
		{
			if (row !=3)
			{
				cout << "_______";
			}
			if (column !=3)
			{
				if (column==2 && row!=3)
					cout << "|"; 
				else if (row ==3)
					cout << "\t|";
				else
					cout <<"\t|";
			}
		}
		cout << "\n";
	}
}


int checkwin(int board[4][4])
{

	for (int row = 1; row <=3; row++)
	{
		int counter = 0;
		int number = board[row][1];
		for (int column = 2; column <=3; column++)
		{
			if (board[row][column] == number && number != 0)
				counter++;
		}
		if (counter == 2)
		return number;
	}

	for (int column = 1; column <=3; column++)
	{
		int counter = 0;
		int number = board[1][column];
		for (int row= 2; row<=3; row++)
		{
			if (board[row][column] == number && number != 0)
				counter++;
		}
		if (counter == 2)
		return number;
	}

	if (board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[1][1] != 0)
	{
		return board[1][1];
	}

	if (board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[1][3] !=0)
	{
		return board[1][3];
	}
	int x = 0;
	for (int row = 1; row <=3; row ++)
	{
		for (int column = 1; column <=3; column++)
		{
			if(board[row][column] !=0)
				x++;
		}
	}
	if (x == 9)
		return -1;
	return 0;
}

//1			2			3
//4			5			6
//7			8			9
	
void setPlace(int a, int board[4][4])
{
	if (a == 1)
		board[1][1] = 2;
	else if (a == 2)
		board[1][2] = 2;
	else if (a ==3)
		board[1][3] = 2;
	else if (a == 4)
		board[2][1] =2;
	else if (a == 5)
		board[2][2] = 2;
	else if (a == 6)
		board[2][3] = 2;
	else if (a == 7)
		board[3][1] = 2;
	else if (a == 8)
		board[3][2] = 2;
	else
		board[3][3] = 2;

	return;
}

bool isTaken(int a, int board[4][4])
{
	if (a == 1)
	{
		if (board[1][1] != 0)
			return true;
		else
			return false;
	}
	else if (a == 2)
	{
		if (board[1][2] != 0)
			return true;
		else
			return false;
	}
	else if (a ==3)
	{
		if (board[1][3] != 0)
			return true;
		else
			return false;
	}
	else if (a == 4)
	{
		if (board[2][1] != 0)
			return true;
		else
			return false;
	}
	else if (a == 5)
	{
		if (board[2][2] != 0)
			return true;
		else
			return false;
	}
	else if (a == 6)
	{
		if (board[2][3] != 0)
			return true;
		else
			return false;
	}
	else if (a == 7)
	{
		if (board[3][1] != 0)
			return true;
		else
			return false;
	}
	else if (a == 8)
	{
		if (board[3][2] != 0)
			return true;
		else
			return false;
	}
	else
	{
		if (board[3][3] != 0)
			return true;
		else
			return false;
	}



}


void AImove(int board[4][4])
{
	int numberofO = 0;

	for (int row = 1; row <=3; row++)
	{
		for (int column = 1; column <=3; column++)
		{
			if (board[row][column] ==2)
				numberofO++;
		}
	}

	if (numberofO >= 2)
	{
		int coordinates[12] = {};
		int counter = 0;
		for (int row = 1; row <=3; row++)
		{
			for (int column = 1; column <=3; column++)
			{
				if (board[row][column] == 2)
				{
					coordinates[counter] = row;
					counter++;
					coordinates[counter] = column;
					counter++;

				}
			}
		}

		//comparisons of rows

		int scenario = 0;//0 is no match, 1 is row, 2 is column, 3 is diagonal
		int position1 = 0;
		int position2 = 0;

		for (int first = 1; first < numberofO*2; first=first+2)
		{
			for (int second = first + 2; second <= numberofO*2; second = second +2)
			{
				if (coordinates[first-1] == coordinates[second-1])
				{
					position1 = first-1;
					position2 = second - 1;

					int temprow = coordinates[position1];
					int tempcolumn = 1;
					while (tempcolumn == coordinates[position1+1] || tempcolumn == coordinates[position2+1])
					{
						tempcolumn = rand()%3 + 1;
					}

					if (board[temprow][tempcolumn] == 0)		 
					{
						scenario = 1;
						board[temprow][tempcolumn] = 2;
						return;
					}
				}
			}
			
		}

		//compare columns
		for (int first = 1; first < numberofO*2; first=first+2)
		{
			for (int second = first + 2; second <= numberofO*2; second = second +2)
			{
				if (coordinates[first] == coordinates[second])
				{
					 position1 = first-1;
					 position2 = second - 1;

					int tempcolumn = coordinates[position1+1];
					int temprow = 1;
					while (temprow == coordinates[position1] || temprow == coordinates[position2])
					{
						temprow= rand()%3 + 1;
					}

					if (board[temprow][tempcolumn] == 0)		 
					{
						
						board[temprow][tempcolumn] = 2;
						return;
					
					}
				}
			}
			
		}
		
	
		

		//compare diagonals
		for (int first = 1; first < numberofO*2; first=first+2)
		{
			for (int second = first + 2; second <= numberofO*2; second = second +2)
			{
				if (abs(coordinates[first-1] - coordinates[second-1]) == 1)
				{
					if (abs(coordinates[first] -coordinates[second]) == 1 )
					{	
						 position1 = first-1;
						 position2 = second - 1;

						 int temprow = 1;
						 while (temprow == coordinates[position1] || temprow == coordinates[position2])
						 {
							temprow= rand()%3 + 1;
						 }
						 
						 int tempcolumn = 1;
						 
						 while (tempcolumn == coordinates[position1+1] || tempcolumn == coordinates[position2+1])
						 {
							tempcolumn = rand()%3 + 1;
						 } 
						
						if (board[temprow][tempcolumn] == 0)		 
						{
							scenario = 3;
							board[temprow][tempcolumn] = 2;
							return;
							
						}


					}
				}
				else if (abs(coordinates[first-1] - coordinates[second-1]) == 2)
				{
					if (abs(coordinates[first] -coordinates[second]) == 2 )
					{	
						 position1 = first-1;
						 position2 = second - 1;
						 
						 int temprow = 1;
						 while (temprow == coordinates[position1] || temprow == coordinates[position2])
						 {
							temprow= rand()%3 + 1;
						 }
						 
						 int tempcolumn = 1;
						 
						 while (tempcolumn == coordinates[position1+1] || tempcolumn == coordinates[position2+1])
						 {
							tempcolumn = rand()%3 + 1;
						 } 
						
						if (board[temprow][tempcolumn] == 0)		 
						{
							scenario = 3;
							board[temprow][tempcolumn] = 2;
							return;
						}
					}
				}

			}

		}

	}

	
	int numberofX = 0;

	for (int row = 1; row <=3; row++)
	{
		for (int column = 1; column <=3; column++)
		{
			if (board[row][column] ==1)
				numberofX++;
		}
	}

	if (numberofX == 1)
	{
		if (board[2][2] == 0)
		{
			setPlace(5, board);
			return;
		}
		else
		{
			int place = rand()%4;
			if (place == 0)
				setPlace(1,board);
			else if (place == 1)
				setPlace(3, board);
			else if (place == 2)
				setPlace(7, board);
			else
				setPlace(9,board);
		}
	}
	else if (numberofX == 2)
	{
		if (isTaken(1, board) && isTaken(5, board) && isTaken(9, board))
		{
			if (board[1][1] == 1 && board[2][2] == 2 && board[3][3] == 1)
			{
				int place = (rand()%4)*2 + 2;
				while (isTaken(place, board))
				{
					place = (rand()%4) *2 + 2;
				}
				setPlace(place,board);
				return;
			}
			
		}
		if (isTaken(3, board) && isTaken(5, board) && isTaken(7, board))
		{
			if (board[1][3] == 1 && board[2][2] == 2 && board[3][1] == 1)
			{
				int place = (rand()%4)*2 + 2;
				while (isTaken(place, board))
				{
					place = (rand()%4) *2 + 2;
				}
				setPlace(place,board);
				return;
			}
		}


		if (isTaken(2,board) && isTaken(4,board))
		{
			if (isTaken(1,board) == false)
			{
				setPlace(1,board);
				return;
			}
			else
			{
				int place = rand()%9+1;
				while (isTaken(place,board))
				{
					place = rand()%9+1;
				}
				setPlace(place,board);
				return;
			}
		}

		if (isTaken(2,board) && isTaken(6,board))
		{
			if(isTaken(3,board) == false)
			{
				setPlace(3,board);
				return;
			}
			else
			{
				int place = rand()%9+1;
				while (isTaken(place,board))
				{
					place = rand()%9+1;
				}
				setPlace(place,board);
				return;

			}
			
		}

		if (isTaken(4,board) && isTaken(8,board))
		{
			if(isTaken(7,board) == false)
			{
				setPlace(7,board);
				return;
			}
			else
			{
				int place = rand()%9+1;
				while (isTaken(place,board))
				{
					place = rand()%9+1;
				}
				setPlace(place,board);
				return;

			}

		}
		if (isTaken(6,board) && isTaken(8,board))
		{
			if(isTaken(9,board) == false)
			{
				setPlace(9,board);
				return;
			}
			else
			{
				int place = rand()%9+1;
				while (isTaken(place,board))
				{
					place = rand()%9+1;
				}
				setPlace(place,board);
				return;

			}

		}


		int coordinate1[2] = {};
		int coordinate2[2] = {};

		for (int row = 1; row <=3; row++)
		{
			for (int column = 1; column <=3; column++)
			{
				if (board[row][column] ==1 && coordinate1[0] == 0)
				{
					coordinate1[0] = row;
					coordinate1[1] = column;
				}
				else if (board[row][column] == 1 && coordinate1[0] !=0)
				{
					coordinate2[0] = row;
					coordinate2[1] = column;
				}
			}
		}

		//if in same row
		if (coordinate1[0] == coordinate2[0])
		{
			int row = coordinate1[0];
			cout << row;
			int column = 1;
			while (column == coordinate1[1] || column == coordinate2[1])
			{
				column = rand()%3 + 1;
			}

			if (board[row][column] == 0)
			{
				board[row][column] = 2;
				return;
			}
			else 
			{
				int place = rand()%9+1;
				while (isTaken(place,board) == true)
				{
					place = rand()%9+1;
				}
				setPlace(place,board);
				return;
			}
		}


		//if in same column
		else if (coordinate1[1] == coordinate2[1])
		{
			int row = 1;
			while (row == coordinate1[0] || row == coordinate2[0])
			{
				row = rand()%3 + 1;
			}

			if (board[row][coordinate1[1]] == 0)
			{
				board[row][coordinate1[1]] = 2;
			}
			else 
			{
				int place = rand()%9+1;
				while (isTaken(place,board) == true)
				{
					place = rand()%9+1;
				}
				setPlace(place,board);
			}
			return;
		}

		//diagonal
		else if ((abs(coordinate1[0]-coordinate2[0]) == 1 && abs(coordinate1[1] - coordinate2[1]) == 1) || (abs(coordinate1[0]-coordinate2[0]) == 2 && abs(coordinate1[1] - coordinate2[1]) == 2) )
		{
			int row = 1;
			while (row == coordinate1[0] || row == coordinate2[0])
			{
				row = rand()%3 + 1;
			}
			int column = 1;
			while (column == coordinate1[1] || column == coordinate2[1])
			{
				column = rand()%3 + 1;
			}
			if (board[row][column] == 0)
			{
				board[row][column] = 2;
				return;
			}
			else
			{	
				int place = rand()%9+1;
				while (isTaken(place,board) == true)
				{
					place = rand()%9+1;
				}
				setPlace(place,board);
				return;

			}
		}

		//otherwise
		else
		{
				int place = rand()%9+1;
				while (isTaken(place,board) == true)
				{
					place = rand()%9+1;
				}
				setPlace(place,board);
				return;
		}

	}

	else
	{
		int coordinates[12] = {};
		int counter = 0;
		int numberofX = 0;
		for (int row = 1; row <=3; row++)
		{
			for (int column = 1; column <=3; column++)
			{
				if (board[row][column] == 1)
				{
					coordinates[counter] = row;
					counter++;
					coordinates[counter] = column;
					counter++;
					numberofX++;
				}
			}
		}

		//comparisons of rows

		int scenario = 0;//0 is no match, 1 is row, 2 is column, 3 is diagonal
		int position1 = 0;
		int position2 = 0;

		for (int first = 1; first < numberofX*2; first=first+2)
		{
			for (int second = first + 2; second <= numberofX*2; second = second +2)
			{
				if (coordinates[first-1] == coordinates[second-1])
				{
					position1 = first-1;
					position2 = second - 1;

					int temprow = coordinates[position1];
					int tempcolumn = 1;
					while (tempcolumn == coordinates[position1+1] || tempcolumn == coordinates[position2+1])
					{
						tempcolumn = rand()%3 + 1;
					}

					if (board[temprow][tempcolumn] == 0)		 
					{
						scenario = 1;
						board[temprow][tempcolumn] = 2;
						return;
					}
				}
			}
	
		}
		
		//compare columns
		for (int first = 1; first < numberofX*2; first=first+2)
		{
			for (int second = first + 2; second <= numberofX*2; second = second +2)
			{
				if (coordinates[first] == coordinates[second])
				{
					 position1 = first-1;
					 position2 = second - 1;

					int tempcolumn = coordinates[position1+1];
					int temprow = 1;
					while (temprow == coordinates[position1] || temprow == coordinates[position2])
					{
						temprow= rand()%3 + 1;
					}

					if (board[temprow][tempcolumn] == 0)		 
					{
						//scenario = 2;
						board[temprow][tempcolumn] = 2;
						return;
						
					}
				}
			}
			
		}
		
		//compare diagonals
		for (int first = 1; first < numberofX*2; first=first+2)
		{
			for (int second = first + 2; second <= numberofX*2; second = second +2)
			{
				if (abs(coordinates[first-1] - coordinates[second-1]) == 1)
				{
					if (abs(coordinates[first] -coordinates[second]) == 1 )
					{	
						 position1 = first-1;
						 position2 = second - 1;

						 int temprow = 1;
						 while (temprow == coordinates[position1] || temprow == coordinates[position2])
						 {
							temprow= rand()%3 + 1;
						 }
						 
						 int tempcolumn = 1;
						 
						 while (tempcolumn == coordinates[position1+1] || tempcolumn == coordinates[position2+1])
						 {
							tempcolumn = rand()%3 + 1;
						 } 
						
						if (board[temprow][tempcolumn] == 0)		 
						{
							scenario = 3;
							board[temprow][tempcolumn] = 2;
							return;
						}
					}
				}
				else if (abs(coordinates[first-1] - coordinates[second-1]) == 2)
				{
					if (abs(coordinates[first] -coordinates[second]) == 2 )
					{	
						 position1 = first-1;
						 position2 = second - 1;
						 
						 int temprow = 1;
						 while (temprow == coordinates[position1] || temprow == coordinates[position2])
						 {
							temprow= rand()%3 + 1;
						 }
						 
						 int tempcolumn = 1;
						 
						 while (tempcolumn == coordinates[position1+1] || tempcolumn == coordinates[position2+1])
						 {
							tempcolumn = rand()%3 + 1;
						 } 
						
						if (board[temprow][tempcolumn] == 0)		 
						{
							scenario = 3;
							board[temprow][tempcolumn] = 2;
							return;
						}
					}
				}

			}
		}
		int place = rand()%9+1;
		while (isTaken(place,board) == true)
		{
			place = rand()%9+1;
		}
		setPlace(place,board);
		return;
	}
}
