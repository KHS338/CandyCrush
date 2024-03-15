#include<iostream>
#include "helpm2.h"
#include <stdlib.h>
#include <Conio.h>
using namespace std;

int score = 0;//initialisation of score variable to keep track of score

void makeShapes(int value, int x, int y)//function to spawn shapes based on 
//values in jewelsvalue array
{
	int midx, midy;
	if (value == 1)//triangle
	{
		midx = ((2 * x) + 60) / 2;
		myvLine(x, y + 50, midx, y, 255, 200, 255);
		myvLine(midx, y, x + 60, y + 50, 255, 200, 255);
		myvLine(x, y + 50, x + 60, y + 50, 255, 200, 255);
	}
	else if (value == 2)//diamond
	{
		midx = ((2 * x) + 60) / 2;
		midy = ((2 * y) + 60) / 2;
		myvLine(x, midy, midx, y, 255, 255, 200);
		myvLine(midx, y, x + 60, midy, 255, 255, 200);
		myvLine(x, midy, midx, y + 60, 255, 255, 200);
		myvLine(midx, y + 60, x + 60, midy, 255, 255, 200);
	}
	else if (value == 3)//rectangle
	{
		myvRectangle(x + 10, y + 10, x + 50, y + 50, 0, 255, 255, 0, 0, 0);
	}
	else if (value == 4)//ellipse
	{
		myvEllipse(x + 10, y + 10, x + 50, y + 50, 0, 0, 255, 0, 0, 0);
	}
	else if (value == 5)//pentagon - special gem
	{
		midx = ((2 * x) + 60) / 2;
		midy = ((2 * y) + 60) / 2;
		myvLine(x, midy - 10, midx, y, 100, 200, 250);
		myvLine(midx, y, x + 60, midy - 10, 100, 200, 250);
		myvLine(x, midy - 10, x + 20, y + 50, 100, 200, 250);
		myvLine(x + 40, y + 50, x + 60, midy - 10, 100, 200, 250);
		myvLine(x + 20, y + 50, x + 40, y + 50, 100, 200, 250);
	}
	else if (value == 11)//triangle
	{
		midx = ((2 * x) + 60) / 2;
		myvLine(x, y + 50, midx, y, 255, 200, 255);
		myvLine(midx, y, x + 60, y + 50, 255, 200, 255);
		myvLine(x, y + 50, x + 60, y + 50, 255, 200, 255);
		myhRectangle(x, y, x + 60, y + 60, 150, 100, 250, 150, 100, 250);
	}
	else if (value == 12)//diamond
	{
		midx = ((2 * x) + 60) / 2;
		midy = ((2 * y) + 60) / 2;
		myvLine(x, midy, midx, y, 255, 255, 200);
		myvLine(midx, y, x + 60, midy, 255, 255, 200);
		myvLine(x, midy, midx, y + 60, 255, 255, 200);
		myvLine(midx, y + 60, x + 60, midy, 255, 255, 200);
		myhRectangle(x, y, x + 60, y + 60, 150, 100, 250, 150, 100, 250);
	}
	else if (value == 13)//rectangle
	{
		myvRectangle(x + 10, y + 10, x + 50, y + 50, 0, 255, 255, 0, 0, 0);
		myhRectangle(x, y, x + 60, y + 60, 150, 100, 250, 150, 100, 250);
	}
	else if (value == 14)//ellipse
	{
		myhRectangle(x, y, x + 60, y + 60, 150, 100, 250, 150, 100, 250);
		myvEllipse(x + 10, y + 10, x + 50, y + 50, 0, 0, 255, 0, 0, 0);
	}
	else if (value == 15)//pentagon
	{
		midx = ((2 * x) + 60) / 2;
		midy = ((2 * y) + 60) / 2;
		myvLine(x, midy - 10, midx, y, 100, 200, 250);
		myvLine(midx, y, x + 60, midy - 10, 100, 200, 250);
		myvLine(x, midy - 10, x + 20, y + 50, 100, 200, 250);
		myvLine(x + 40, y + 50, x + 60, midy - 10, 100, 200, 250);
		myvLine(x + 20, y + 50, x + 40, y + 50, 100, 200, 250);
		myhRectangle(x, y, x + 60, y + 60, 150, 100, 250, 150, 100, 250);
	}

}

void updateallShapes(int jewelsvalues[][8])//updates jewels in grid
//according to values stored in
//jewelsvalue array
{
	int x = 100;
	int y = 50;
	for (int i = 0; i < 8; i++)
	{
		x = 100;
		for (int j = 0; j < 8; j++)
		{
			myRectangle(x, y, x + 60, y + 60, 0, 0, 0, 0, 0, 0);
			myRectangle(x, y, x + 60, y + 60, 255, 255, 255, 0, 0, 0);
			makeShapes(jewelsvalues[i][j], x, y);
			x = x + 60;
		}
		y = y + 60;
	}
}

void mySwap(int& num, int& num2)//function to swap values of jewels
{
	int temp;
	temp = num;
	num = num2;
	num2 = temp;
}

bool checkCut(int jewelsvalue[][8], int row, int col)//checks for groups of 
//3 jewels
{
	bool check = 0;

	if (jewelsvalue[row][col] == jewelsvalue[row][col + 1] && jewelsvalue[row][col + 1] == jewelsvalue[row][col + 2])
	{
		check = 1;
	}
	else if (jewelsvalue[row][col] == jewelsvalue[row][col - 1] && jewelsvalue[row][col - 1] == jewelsvalue[row][col - 2])
	{
		check = 1;
	}
	else if (jewelsvalue[row][col] == jewelsvalue[row - 1][col] && jewelsvalue[row - 1][col] == jewelsvalue[row - 2][col])
	{
		check = 1;
	}
	else if (jewelsvalue[row][col] == jewelsvalue[row + 1][col] && jewelsvalue[row + 1][col] == jewelsvalue[row + 2][col])
	{
		check = 1;
	}
	else if (jewelsvalue[row][col] == jewelsvalue[row + 1][col] && jewelsvalue[row][col] == jewelsvalue[row - 1][col])
	{
		check = 1;
	}
	else if (jewelsvalue[row][col] == jewelsvalue[row][col + 1] && jewelsvalue[row][col] == jewelsvalue[row][col - 1])
	{
		check = 1;
	}
	return check;
}

bool checkspecial(int jewelsvalue[][8], int& row, int& col)//checks for groups
//of 3 or more
//of special gem
{
	int count;
	for (int i = 0; i < 8; i++)//row wise checking
	{
		count = 0;
		for (int j = 0; j < 8; j++)
		{
			if (jewelsvalue[i][j] == 5)
			{
				count++;
				if (count >= 3)
				{
					row = i + 1;
					return true;
				}
			}
			else
			{
				count = 0;
			}
		}
		int k = 0;
		for (int i = 0; i < 8; i++)//column wise checking
		{
			count = 0;
			for (int j = k; j < 8; j++)
			{
				if (jewelsvalue[j][i] == 5)
				{
					count++;
					if (count >= 3)
					{
						col = k;
						return true;
					}
				}
				else
				{
					count = 0;
				}
			}
		}
	}
	return false;
}

void CutGrid(int jewelsvalue[][8])//if checkcut returns true it despawns jewels
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			if (checkCut(jewelsvalue, row, col) == 1)
			{
				if (jewelsvalue[row][col] == jewelsvalue[row][col + 1] && jewelsvalue[row][col + 1] == jewelsvalue[row][col + 2] && jewelsvalue[row][col + 2] == jewelsvalue[row][col + 3] && jewelsvalue[row][col + 3] == jewelsvalue[row][col + 4] && jewelsvalue[row][col + 4] == jewelsvalue[row][col + 5] && jewelsvalue[row][col + 5] == jewelsvalue[row][col + 6] && jewelsvalue[row][col + 6] == jewelsvalue[row][col + 7])
				{
					//next 4 are check 7 in a row
					jewelsvalue[row][col] = 0;
					jewelsvalue[row][col + 1] = 0;
					jewelsvalue[row][col + 2] = 0;
					jewelsvalue[row][col + 3] = 0;
					jewelsvalue[row][col + 4] = 0;
					jewelsvalue[row][col + 5] = 0;
					jewelsvalue[row][col + 6] = 0;
					jewelsvalue[row][col + 7] = 0;
				}
				else if (jewelsvalue[row][col] == jewelsvalue[row][col - 1] && jewelsvalue[row][col - 1] == jewelsvalue[row][col - 2] && jewelsvalue[row][col - 2] == jewelsvalue[row][col - 3] && jewelsvalue[row][col - 3] == jewelsvalue[row][col - 4] && jewelsvalue[row][col - 4] == jewelsvalue[row][col - 5] && jewelsvalue[row][col - 5] == jewelsvalue[row][col - 6] && jewelsvalue[row][col - 6] == jewelsvalue[row][col - 7])
				{
					jewelsvalue[row][col] = 0;
					jewelsvalue[row][col - 1] = 0;
					jewelsvalue[row][col - 2] = 0;
					jewelsvalue[row][col - 3] = 0;
					jewelsvalue[row][col - 4] = 0;
					jewelsvalue[row][col - 5] = 0;
					jewelsvalue[row][col - 6] = 0;
					jewelsvalue[row][col - 7] = 0;
				}
				else if (jewelsvalue[row][col] == jewelsvalue[row - 1][col] && jewelsvalue[row - 1][col] == jewelsvalue[row - 2][col] && jewelsvalue[row - 2][col] == jewelsvalue[row - 3][col] && jewelsvalue[row - 3][col] == jewelsvalue[row - 4][col] && jewelsvalue[row - 4][col] == jewelsvalue[row - 5][col] && jewelsvalue[row - 5][col] == jewelsvalue[row - 6][col] && jewelsvalue[row - 6][col] == jewelsvalue[row - 7][col])
				{
					jewelsvalue[row][col] = 0;
					jewelsvalue[row - 1][col] = 0;
					jewelsvalue[row - 2][col] = 0;
					jewelsvalue[row - 3][col] = 0;
					jewelsvalue[row - 4][col] = 0;
					jewelsvalue[row - 5][col] = 0;
					jewelsvalue[row - 6][col] = 0;
					jewelsvalue[row - 7][col] = 0;
				}
				else if (jewelsvalue[row][col] == jewelsvalue[row + 1][col] && jewelsvalue[row + 1][col] == jewelsvalue[row + 2][col] && jewelsvalue[row + 2][col] == jewelsvalue[row + 3][col] && jewelsvalue[row + 3][col] == jewelsvalue[row + 4][col] && jewelsvalue[row + 4][col] == jewelsvalue[row + 5][col] && jewelsvalue[row + 5][col] == jewelsvalue[row + 6][col] && jewelsvalue[row + 6][col] == jewelsvalue[row + 7][col])
				{
					jewelsvalue[row][col] = 0;
					jewelsvalue[row + 1][col] = 0;
					jewelsvalue[row + 2][col] = 0;
					jewelsvalue[row + 3][col] = 0;
					jewelsvalue[row + 4][col] = 0;
					jewelsvalue[row + 5][col] = 0;
					jewelsvalue[row + 6][col] = 0;
					jewelsvalue[row + 7][col] = 0;
				}
				else if (jewelsvalue[row][col] == jewelsvalue[row][col + 1] && jewelsvalue[row][col + 1] == jewelsvalue[row][col + 2] && jewelsvalue[row][col + 2] == jewelsvalue[row][col + 3] && jewelsvalue[row][col + 3] == jewelsvalue[row][col + 4] && jewelsvalue[row][col + 4] == jewelsvalue[row][col + 5] && jewelsvalue[row][col + 5] == jewelsvalue[row][col + 6])
				{
					//next 4 are check 7 in a row
					jewelsvalue[row][col] = 0;
					jewelsvalue[row][col + 1] = 0;
					jewelsvalue[row][col + 2] = 0;
					jewelsvalue[row][col + 3] = 0;
					jewelsvalue[row][col + 4] = 0;
					jewelsvalue[row][col + 5] = 0;
					jewelsvalue[row][col + 6] = 0;
				}
				else if (jewelsvalue[row][col] == jewelsvalue[row][col - 1] && jewelsvalue[row][col - 1] == jewelsvalue[row][col - 2] && jewelsvalue[row][col - 2] == jewelsvalue[row][col - 3] && jewelsvalue[row][col - 3] == jewelsvalue[row][col - 4] && jewelsvalue[row][col - 4] == jewelsvalue[row][col - 5] && jewelsvalue[row][col - 5] == jewelsvalue[row][col - 6])
				{
					jewelsvalue[row][col] = 0;
					jewelsvalue[row][col - 1] = 0;
					jewelsvalue[row][col - 2] = 0;
					jewelsvalue[row][col - 3] = 0;
					jewelsvalue[row][col - 4] = 0;
					jewelsvalue[row][col - 5] = 0;
					jewelsvalue[row][col - 6] = 0;
				}
				else if (jewelsvalue[row][col] == jewelsvalue[row - 1][col] && jewelsvalue[row - 1][col] == jewelsvalue[row - 2][col] && jewelsvalue[row - 2][col] == jewelsvalue[row - 3][col] && jewelsvalue[row - 3][col] == jewelsvalue[row - 4][col] && jewelsvalue[row - 4][col] == jewelsvalue[row - 5][col] && jewelsvalue[row - 5][col] == jewelsvalue[row - 6][col])
				{
					jewelsvalue[row][col] = 0;
					jewelsvalue[row - 1][col] = 0;
					jewelsvalue[row - 2][col] = 0;
					jewelsvalue[row - 3][col] = 0;
					jewelsvalue[row - 4][col] = 0;
					jewelsvalue[row - 5][col] = 0;
					jewelsvalue[row - 6][col] = 0;
				}
				else if (jewelsvalue[row][col] == jewelsvalue[row + 1][col] && jewelsvalue[row + 1][col] == jewelsvalue[row + 2][col] && jewelsvalue[row + 2][col] == jewelsvalue[row + 3][col] && jewelsvalue[row + 3][col] == jewelsvalue[row + 4][col] && jewelsvalue[row + 4][col] == jewelsvalue[row + 5][col] && jewelsvalue[row + 5][col] == jewelsvalue[row + 6][col])
				{
					jewelsvalue[row][col] = 0;
					jewelsvalue[row + 1][col] = 0;
					jewelsvalue[row + 2][col] = 0;
					jewelsvalue[row + 3][col] = 0;
					jewelsvalue[row + 4][col] = 0;
					jewelsvalue[row + 5][col] = 0;
					jewelsvalue[row + 6][col] = 0;
				}
				else if (jewelsvalue[row][col] == jewelsvalue[row][col + 1] && jewelsvalue[row][col + 1] == jewelsvalue[row][col + 2] && jewelsvalue[row][col + 2] == jewelsvalue[row][col + 3] && jewelsvalue[row][col + 3] == jewelsvalue[row][col + 4] && jewelsvalue[row][col + 4] == jewelsvalue[row][col + 5])
				{
					//next 4 are check 6 in a row
					jewelsvalue[row][col] = 0;
					jewelsvalue[row][col + 1] = 0;
					jewelsvalue[row][col + 2] = 0;
					jewelsvalue[row][col + 3] = 0;
					jewelsvalue[row][col + 4] = 0;
					jewelsvalue[row][col + 5] = 0;
				}
				else if (jewelsvalue[row][col] == jewelsvalue[row][col - 1] && jewelsvalue[row][col - 1] == jewelsvalue[row][col - 2] && jewelsvalue[row][col - 2] == jewelsvalue[row][col - 3] && jewelsvalue[row][col - 3] == jewelsvalue[row][col - 4] && jewelsvalue[row][col - 4] == jewelsvalue[row][col - 5])
				{
					jewelsvalue[row][col] = 0;
					jewelsvalue[row][col - 1] = 0;
					jewelsvalue[row][col - 2] = 0;
					jewelsvalue[row][col - 3] = 0;
					jewelsvalue[row][col - 4] = 0;
					jewelsvalue[row][col - 5] = 0;
				}
				else if (jewelsvalue[row][col] == jewelsvalue[row - 1][col] && jewelsvalue[row - 1][col] == jewelsvalue[row - 2][col] && jewelsvalue[row - 2][col] == jewelsvalue[row - 3][col] && jewelsvalue[row - 3][col] == jewelsvalue[row - 4][col] && jewelsvalue[row - 4][col] == jewelsvalue[row - 5][col])
				{
					jewelsvalue[row][col] = 0;
					jewelsvalue[row - 1][col] = 0;
					jewelsvalue[row - 2][col] = 0;
					jewelsvalue[row - 3][col] = 0;
					jewelsvalue[row - 4][col] = 0;
					jewelsvalue[row - 5][col] = 0;
				}
				else if (jewelsvalue[row][col] == jewelsvalue[row + 1][col] && jewelsvalue[row + 1][col] == jewelsvalue[row + 2][col] && jewelsvalue[row + 2][col] == jewelsvalue[row + 3][col] && jewelsvalue[row + 3][col] == jewelsvalue[row + 4][col] && jewelsvalue[row + 4][col] == jewelsvalue[row + 5][col])
				{
					jewelsvalue[row][col] = 0;
					jewelsvalue[row + 1][col] = 0;
					jewelsvalue[row + 2][col] = 0;
					jewelsvalue[row + 3][col] = 0;
					jewelsvalue[row + 4][col] = 0;
					jewelsvalue[row + 5][col] = 0;
				}
				else if (jewelsvalue[row][col] == jewelsvalue[row][col + 1] && jewelsvalue[row][col + 1] == jewelsvalue[row][col + 2] && jewelsvalue[row][col + 2] == jewelsvalue[row][col + 3] && jewelsvalue[row][col + 3] == jewelsvalue[row][col + 4])
				{
					//next 4 are check 5 in a row
					jewelsvalue[row][col] = 0;
					jewelsvalue[row][col + 1] = 0;
					jewelsvalue[row][col + 2] = 0;
					jewelsvalue[row][col + 3] = 0;
					jewelsvalue[row][col + 4] = 0;
				}
				else if (jewelsvalue[row][col] == jewelsvalue[row][col - 1] && jewelsvalue[row][col - 1] == jewelsvalue[row][col - 2] && jewelsvalue[row][col - 2] == jewelsvalue[row][col - 3] && jewelsvalue[row][col - 3] == jewelsvalue[row][col - 4])
				{
					jewelsvalue[row][col] = 0;
					jewelsvalue[row][col - 1] = 0;
					jewelsvalue[row][col - 2] = 0;
					jewelsvalue[row][col - 3] = 0;
					jewelsvalue[row][col - 4] = 0;
				}
				else if (jewelsvalue[row][col] == jewelsvalue[row - 1][col] && jewelsvalue[row - 1][col] == jewelsvalue[row - 2][col] && jewelsvalue[row - 2][col] == jewelsvalue[row - 3][col] && jewelsvalue[row - 3][col] == jewelsvalue[row - 4][col])
				{
					jewelsvalue[row][col] = 0;
					jewelsvalue[row - 1][col] = 0;
					jewelsvalue[row - 2][col] = 0;
					jewelsvalue[row - 3][col] = 0;
					jewelsvalue[row - 4][col] = 0;
				}
				else if (jewelsvalue[row][col] == jewelsvalue[row + 1][col] && jewelsvalue[row + 1][col] == jewelsvalue[row + 2][col] && jewelsvalue[row + 2][col] == jewelsvalue[row + 3][col] && jewelsvalue[row + 3][col] == jewelsvalue[row + 4][col])
				{
					jewelsvalue[row][col] = 0;
					jewelsvalue[row + 1][col] = 0;
					jewelsvalue[row + 2][col] = 0;
					jewelsvalue[row + 3][col] = 0;
					jewelsvalue[row + 4][col] = 0;
				}
				else if (jewelsvalue[row][col] == jewelsvalue[row][col + 1] && jewelsvalue[row][col + 1] == jewelsvalue[row][col + 2] && jewelsvalue[row][col + 2] == jewelsvalue[row][col + 3])
				{
					//next 4 are check 4 in a row
					jewelsvalue[row][col] = 0;
					jewelsvalue[row][col + 1] = 0;
					jewelsvalue[row][col + 2] = 0;
					jewelsvalue[row][col + 3] = 0;
				}
				else if (jewelsvalue[row][col] == jewelsvalue[row][col - 1] && jewelsvalue[row][col - 1] == jewelsvalue[row][col - 2] && jewelsvalue[row][col - 2] == jewelsvalue[row][col - 3])
				{
					jewelsvalue[row][col] = 0;
					jewelsvalue[row][col - 1] = 0;
					jewelsvalue[row][col - 2] = 0;
					jewelsvalue[row][col - 3] = 0;
				}
				else if (jewelsvalue[row][col] == jewelsvalue[row - 1][col] && jewelsvalue[row - 1][col] == jewelsvalue[row - 2][col] && jewelsvalue[row - 2][col] == jewelsvalue[row - 3][col])
				{
					jewelsvalue[row][col] = 0;
					jewelsvalue[row - 1][col] = 0;
					jewelsvalue[row - 2][col] = 0;
					jewelsvalue[row - 3][col] = 0;
				}
				else if (jewelsvalue[row][col] == jewelsvalue[row + 1][col] && jewelsvalue[row + 1][col] == jewelsvalue[row + 2][col] && jewelsvalue[row + 2][col] == jewelsvalue[row + 3][col])
				{
					jewelsvalue[row][col] = 0;
					jewelsvalue[row + 1][col] = 0;
					jewelsvalue[row + 2][col] = 0;
					jewelsvalue[row + 3][col] = 0;
				}
				else if (jewelsvalue[row][col] == jewelsvalue[row][col + 1] && jewelsvalue[row][col + 1] == jewelsvalue[row][col + 2])
				{
					//next 4 are check 3 in a row
					jewelsvalue[row][col] = 0;
					jewelsvalue[row][col + 1] = 0;
					jewelsvalue[row][col + 2] = 0;
				}
				else if (jewelsvalue[row][col] == jewelsvalue[row][col - 1] && jewelsvalue[row][col - 1] == jewelsvalue[row][col - 2])
				{
					jewelsvalue[row][col] = 0;
					jewelsvalue[row][col - 1] = 0;
					jewelsvalue[row][col - 2] = 0;
				}
				else if (jewelsvalue[row][col] == jewelsvalue[row - 1][col] && jewelsvalue[row - 1][col] == jewelsvalue[row - 2][col])
				{
					jewelsvalue[row][col] = 0;
					jewelsvalue[row - 1][col] = 0;
					jewelsvalue[row - 2][col] = 0;
				}
				else if (jewelsvalue[row][col] == jewelsvalue[row + 1][col] && jewelsvalue[row + 1][col] == jewelsvalue[row + 2][col])
				{
					jewelsvalue[row][col] = 0;
					jewelsvalue[row + 1][col] = 0;
					jewelsvalue[row + 2][col] = 0;
				}
				else if (jewelsvalue[row][col] == jewelsvalue[row + 1][col] && jewelsvalue[row][col] == jewelsvalue[row - 1][col])
				{
					//next 2 are for mid 
					jewelsvalue[row][col] = 0;
					jewelsvalue[row + 1][col] = 0;
					jewelsvalue[row - 1][col] = 0;
				}
				else if (jewelsvalue[row][col] == jewelsvalue[row][col + 1] && jewelsvalue[row][col] == jewelsvalue[row][col - 1])
				{
					jewelsvalue[row][col] = 0;
					jewelsvalue[row][col - 1] = 0;
					jewelsvalue[row][col + 1] = 0;
				}
				//destroyer gem explode radius
				else if (jewelsvalue[row][col] == 6)
				{
					//making all values in row 0
					for (int i = row; i < row + 1; i++)
					{
						for (int j = 0; j < 8; j++)
						{
							jewelsvalue[i][j] = 0;
						}
					}
					//making all values in column 0
					for (int i = col; i < col + 1; i++)
					{
						for (int j = 0; j < 8; j++)
						{
							jewelsvalue[j][i] = 0;
						}
					}
				}
				//explode radius of special gem
				else if (checkspecial(jewelsvalue, row, col) == true)
				{
					jewelsvalue[row - 1][col - 1] = 0;
					jewelsvalue[row - 1][col] = 0;
					jewelsvalue[row - 1][col + 1] = 0;
					jewelsvalue[row][col - 1] = 0;
					jewelsvalue[row][col] = 0;
					jewelsvalue[row][col + 1] = 0;
					jewelsvalue[row + 1][col - 1] = 0;
					jewelsvalue[row + 1][col] = 0;
					jewelsvalue[row + 1][col + 1] = 0;
				}
			}
		}
		//updateallShapes(jewelsvalue);
	}
}

void fallgrid(int jewelsvalue[8][8]) //falling of jewels into the place
//of jewels despawned
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i != 0)
			{
				if (jewelsvalue[i][j] == 0)
				{
					if (i != 0)
					{
						if (i == 1)
						{
							mySwap(jewelsvalue[i][j], jewelsvalue[i - 1][j]);
						}
						else if (i == 2)
						{
							mySwap(jewelsvalue[i][j], jewelsvalue[i - 1][j]);
							mySwap(jewelsvalue[i - 1][j], jewelsvalue[i - 2][j]);
						}
						else if (i == 3)
						{
							mySwap(jewelsvalue[i][j], jewelsvalue[i - 1][j]);
							mySwap(jewelsvalue[i - 1][j], jewelsvalue[i - 2][j]);
							mySwap(jewelsvalue[i - 2][j], jewelsvalue[i - 3][j]);
						}
						else if (i == 4)
						{
							mySwap(jewelsvalue[i][j], jewelsvalue[i - 1][j]);
							mySwap(jewelsvalue[i - 1][j], jewelsvalue[i - 2][j]);
							mySwap(jewelsvalue[i - 2][j], jewelsvalue[i - 3][j]);
							mySwap(jewelsvalue[i - 3][j], jewelsvalue[i - 4][j]);
						}
						else if (i == 5)
						{
							mySwap(jewelsvalue[i][j], jewelsvalue[i - 1][j]);
							mySwap(jewelsvalue[i - 1][j], jewelsvalue[i - 2][j]);
							mySwap(jewelsvalue[i - 2][j], jewelsvalue[i - 3][j]);
							mySwap(jewelsvalue[i - 3][j], jewelsvalue[i - 4][j]);
							mySwap(jewelsvalue[i - 4][j], jewelsvalue[i - 5][j]);
						}
						else if (i == 6)
						{
							mySwap(jewelsvalue[i][j], jewelsvalue[i - 1][j]);
							mySwap(jewelsvalue[i - 1][j], jewelsvalue[i - 2][j]);
							mySwap(jewelsvalue[i - 2][j], jewelsvalue[i - 3][j]);
							mySwap(jewelsvalue[i - 3][j], jewelsvalue[i - 4][j]);
							mySwap(jewelsvalue[i - 4][j], jewelsvalue[i - 5][j]);
							mySwap(jewelsvalue[i - 5][j], jewelsvalue[i - 6][j]);
						}
						else if (i == 7)
						{
							mySwap(jewelsvalue[i][j], jewelsvalue[i - 1][j]);
							mySwap(jewelsvalue[i - 1][j], jewelsvalue[i - 2][j]);
							mySwap(jewelsvalue[i - 2][j], jewelsvalue[i - 3][j]);
							mySwap(jewelsvalue[i - 3][j], jewelsvalue[i - 4][j]);
							mySwap(jewelsvalue[i - 4][j], jewelsvalue[i - 5][j]);
							mySwap(jewelsvalue[i - 5][j], jewelsvalue[i - 6][j]);
							mySwap(jewelsvalue[i - 6][j], jewelsvalue[i - 7][j]);
						}
					}
				}
			}
		}
	}
	//updateallShapes(jewelsvalue);
}

void UpdateZero(int jewelsvalue[8][8])//gets rid of groups of 3 jewels at the 
//start of the game
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (jewelsvalue[i][j] == 0)
			{
				jewelsvalue[i][j] = rand() % 5 + 1;

			}
		}
	}
	//updateallShapes(jewelsvalue);
}

void spawndestroyer(int jewelsvalue[][8])//spawns destroyer gem if  
//conditions are met
{
	bool elbow = false;
	//top check
	int count;
	int startindex;
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 7 && elbow == false; j++)
		{
			count = 0;
			for (int k = 0; k < 8; k++)
			{
				if (jewelsvalue[i][j] == jewelsvalue[i][k])
				{
					count++;
				}
				else
				{
					count = 0;
				}
			}
			if (count >= 5)
			{
				jewelsvalue[i][j] = 6;
				startindex = j;
				elbow = true;
			}
		}
		if (elbow == true)
		{
			for (int l = startindex + 1; l < startindex + count; l++)
			{
				jewelsvalue[i][l] = 0;
			}
		}
	}
	//right check
	for (int i = 7; i < 8; i++)
	{
		for (int j = 0; j < 7 && elbow == false; j++)
		{
			count = 0;
			for (int k = 0; k < 8; k++)
			{
				if (jewelsvalue[j][i] == jewelsvalue[k][i])
				{
					count++;
				}
				else
				{
					count = 0;
				}
			}
			if (count >= 5)
			{
				jewelsvalue[i][j] = 6;
				startindex = j;
				elbow = true;
			}
		}
		if (elbow == true)
		{
			for (int l = startindex + 1; l < startindex + count; l++)
			{
				jewelsvalue[i][l] = 0;
			}
		}
	}
	//bottom check
	for (int i = 7; i < 8; i++)
	{
		for (int j = 0; j < 7 && elbow == false; j++)
		{
			count = 0;
			for (int k = 0; k < 8; k++)
			{
				if (jewelsvalue[i][j] == jewelsvalue[i][k])
				{
					count++;
				}
				else
				{
					count = 0;
				}
			}
			if (count >= 5)
			{
				jewelsvalue[i][j] = 6;
				startindex = j;
				elbow = true;
			}
		}
		if (elbow == true)
		{
			for (int l = startindex + 1; l < startindex + count; l++)
			{
				jewelsvalue[i][l] = 0;
			}
		}
	}
	//left check
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 7 && elbow == false; j++)
		{
			count = 0;
			for (int k = 0; k < 8; k++)
			{
				if (jewelsvalue[j][i] == jewelsvalue[k][i])
				{
					count++;
				}
				else
				{
					count = 0;
				}
			}
			if (count >= 5)
			{
				jewelsvalue[i][j] = 6;
				startindex = j;
				elbow = true;
			}
		}
		if (elbow == true)
		{
			for (int l = startindex + 1; l < startindex + count; l++)
			{
				jewelsvalue[i][l] = 0;
			}
		}
	}
	updateallShapes(jewelsvalue);
	fallgrid(jewelsvalue);
}

void scorecounter(int jewelsvalue[8][8], int& score)//counts score by 
//checking if any value is
//0  in array
{
	system("cls"); //to continously update score
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (jewelsvalue[i][j] == 0)
			{
				score = score + 100;
			}
		}
	}
	cout << "Your Score is " << score;
}

void Cycle(int jewelsvalue[][8], int& score)//cycling of functions being used
//continously
{
	CutGrid(jewelsvalue);
	scorecounter(jewelsvalue, score);
	spawndestroyer(jewelsvalue);
	fallgrid(jewelsvalue);
	UpdateZero(jewelsvalue);
	updateallShapes(jewelsvalue);
}

void Checkall(int jewelsvalue[][8], int& score)//checks if there is a group of
//of three and gets rid of it
{
	for (int s = 0; s < 8; s++)
	{
		for (int p = 0; p < 8; p++)
		{
			if (checkCut(jewelsvalue, s, p) == 1)
			{
				Sleep(100);
				Cycle(jewelsvalue, score);
			}
		}
	}
}

int main()
{
	//the rectangle below defines the screen were working with
	//so these are the x and y limits within which we will implement all our objects

	myRectangle(0, 0, 1800, 1800, 0, 0, 0, 0, 0, 0);

	//all variable declarations

	int grid[8][8] = { 0 };
	int jewelsvalue[8][8] = { 0 };
	double x1 = 0;
	double y1 = 50;
	double x2 = 0;
	double y2 = 110;
	double xtime = 600;
	bool check = 0;
	int xuser = 100, yuser = 50, x1user = 160, y1user = 110;
	int indexr = 0, indexc = 0;
	int c1 = 255, c2 = 0, c3 = 0;
	srand(time(0));

	//creation of grid and random placement of jewels

	for (int i = 0; i < 8; i++)
	{
		x1 = 100;
		x2 = 160;
		for (int j = 0; j < 8; j++)
		{
			grid[i][j] = myRectangle(x1, y1, x2, y2, 255, 255, 255, 0, 0, 0);
			jewelsvalue[i][j] = rand() % 5 + 1;
			makeShapes(jewelsvalue[i][j], x1, y1);
			x1 = x1 + 60;
			x2 = x2 + 60;
		}
		y1 = y1 + 60;
		y2 = y2 + 60;
	}

	//time bar and execution of all time controlled functions here
	for (int i = 1; xtime <= 1060; i++)
	{
		Checkall(jewelsvalue, score);
		myhRectangle(xuser, yuser, x1user, y1user, c1, c2, c3, c1, c2, c3);
		if (GetAsyncKeyState(VK_RIGHT))
		{
			if (check == 0)
			{
				if ((xuser + 60 >= 100 && x1user + 60 <= 580))
				{
					myhRectangle(xuser, yuser, x1user, y1user, 255, 255, 255, 255, 255, 255);
					myhRectangle(xuser + 60, yuser, x1user + 60, y1user, c1, c2, c3, c1, c2, c3);
					xuser = xuser + 60;
					x1user = x1user + 60;
					indexc++;
				}
			}
			else if (indexc != 7)
			{
				mySwap(jewelsvalue[indexr][indexc], jewelsvalue[indexr][indexc + 1]);
				updateallShapes(jewelsvalue);
				if (checkCut(jewelsvalue, indexr, indexc + 1) == 0 && checkCut(jewelsvalue, indexr, indexc) == 0)
				{
					Sleep(50);
					mySwap(jewelsvalue[indexr][indexc + 1], jewelsvalue[indexr][indexc]);
					updateallShapes(jewelsvalue);
				}
				else
				{
					Cycle(jewelsvalue, score);
					Checkall(jewelsvalue, score);
				}
			}
		}
		else if (GetAsyncKeyState(VK_LEFT))
		{
			if (check == 0)
			{
				if ((xuser - 60 >= 100 && x1user - 60 <= 580))
				{
					myhRectangle(xuser, yuser, x1user, y1user, 255, 255, 255, 255, 255, 255);
					myhRectangle(xuser - 60, yuser, x1user - 60, y1user, c1, c2, c3, c1, c2, c3);
					xuser = xuser - 60;
					x1user = x1user - 60;
					indexc--;
				}
			}
			else if (indexc != 0)
			{
				mySwap(jewelsvalue[indexr][indexc], jewelsvalue[indexr][indexc - 1]);
				updateallShapes(jewelsvalue);
				if (checkCut(jewelsvalue, indexr, indexc - 1) == 0 && checkCut(jewelsvalue, indexr, indexc) == 0)
				{
					Sleep(50);
					mySwap(jewelsvalue[indexr][indexc - 1], jewelsvalue[indexr][indexc]);
					updateallShapes(jewelsvalue);
				}
				else
				{
					Cycle(jewelsvalue, score);
					Checkall(jewelsvalue, score);
				}
			}
		}
		else if (GetAsyncKeyState(VK_UP))
		{
			if (check == 0)
			{
				if ((yuser - 60 >= 50 && y1user - 60 <= 530))
				{
					myhRectangle(xuser, yuser, x1user, y1user, 255, 255, 255, 255, 255, 255);
					myhRectangle(xuser, yuser - 60, x1user, y1user - 60, c1, c2, c3, c1, c2, c3);
					yuser = yuser - 60;
					y1user = y1user - 60;
					indexr--;
				}
			}
			else
			{
				mySwap(jewelsvalue[indexr][indexc], jewelsvalue[indexr - 1][indexc]);
				updateallShapes(jewelsvalue);
				if (checkCut(jewelsvalue, indexr - 1, indexc) == 0 && checkCut(jewelsvalue, indexr, indexc) == 0)
				{
					Sleep(50);
					mySwap(jewelsvalue[indexr - 1][indexc], jewelsvalue[indexr][indexc]);
					updateallShapes(jewelsvalue);
				}
				else
				{
					Cycle(jewelsvalue, score);
					Checkall(jewelsvalue, score);
				}
			}
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			if (check == 0)
			{
				if ((yuser + 60 >= 50 && y1user + 60 <= 530))
				{
					myhRectangle(xuser, yuser, x1user, y1user, 255, 255, 255, 255, 255, 255);
					myhRectangle(xuser, yuser + 60, x1user, y1user + 60, c1, c2, c3, c1, c2, c3);
					yuser = yuser + 60;
					y1user = y1user + 60;
					indexr++;
				}
			}
			else
			{
				mySwap(jewelsvalue[indexr][indexc], jewelsvalue[indexr + 1][indexc]);
				updateallShapes(jewelsvalue);
				if (checkCut(jewelsvalue, indexr + 1, indexc) == 0 && checkCut(jewelsvalue, indexr, indexc) == 0)
				{
					Sleep(50);
					mySwap(jewelsvalue[indexr + 1][indexc], jewelsvalue[indexr][indexc]);
					updateallShapes(jewelsvalue);
				}
				else
				{
					Cycle(jewelsvalue, score);
					Checkall(jewelsvalue, score);
				}
			}
		}
		else if (GetAsyncKeyState(VK_RETURN))
		{
			check = 1;
			c1 = 255;
			c2 = 165;
			c3 = 0;
		}

		else if (GetAsyncKeyState(VK_SPACE))
		{
			check = 0;
			c1 = 255;
			c2 = 0;
			c3 = 0;
		}
		myRectangle(600, 50, 1060, 100, 255, 255, 255, 0, 0, 0);
		myRectangle(600, 50, xtime, 100, 255, 255, 255, 252, 244, 3);
		Sleep(100);
		xtime = xtime + 0.767;
		if (xtime == 1060)
		{
			CloseWindow;
		}
	}
}
