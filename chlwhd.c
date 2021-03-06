#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#include <windows.h>
#include <wincon.h>
#include <conio.h>
#include<time.h>

/////////////////////////////////////////////////////

#define LEFT 75 //좌로 이동    //키보드값들 
#define RIGHT 77 //우로 이동3
#define UP 72 //위로 이동
#define DOWN 80 //아래로 이동

#define MAX_I 27    //미로의 세로
#define MAX_J 30    //미로의 가로

#define true 1  //참
#define false 0 //거짓

/////////////////////////////////////////////////////


int map[5][MAX_I][MAX_J] =		//미로 맵 (3차원 배열)
{
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//0
		{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1},
		{1,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1},
		{1,1,1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1},
		{1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1},
		{1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1},
		{1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1},
		{1,0,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,0,1,0,1,0,1,0,1,1,1,0,1},
		{1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,1,0,1},
		{1,1,1,0,1,1,1,1,0,1,1,0,1,1,1,0,1,0,1,1,0,1,1,1,1,1,0,1,0,1},
		{1,0,1,0,1,0,0,1,0,0,1,1,1,0,1,0,0,0,0,1,1,1,1,1,0,1,0,1,1,1},
		{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,0,0,1},
		{1,1,1,1,1,0,1,0,1,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,1,1,1},
		{1,0,0,0,0,0,1,0,1,1,1,0,0,0,0,1,1,1,1,0,1,0,0,0,0,0,0,1,0,1},
		{1,0,1,1,0,1,1,0,0,0,1,0,1,1,0,1,0,0,0,0,0,1,0,1,1,1,0,0,0,1},
		{1,0,1,1,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,1,0,1,0,0,0,1,0,1},
		{1,0,1,0,0,0,0,1,1,0,1,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,1,1,0,1},
		{1,0,1,0,1,0,0,0,1,0,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,0,0,1,0,1},
		{1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,0,1},
		{1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,1},
		{1,0,0,0,1,0,1,0,0,0,1,0,1,1,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1},
		{1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,1,0,1,1,1,0,1,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,0,1,0,0,0,1,0,1,1,1,1,0,1},
		{1,0,1,1,1,0,1,1,1,1,1,0,1,0,0,0,0,0,1,0,1,1,1,0,0,0,0,1,1,1},
		{1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,2},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}	//58
	},

	//////////////////////////////////////////////////////////////////////////////////

	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//1
		{1,0,0,1,1,1,1,1,0,0,0,1,0,0,0,0,0,1,1,1,0,1,1,0,1,1,1,1,1,1},
		{1,1,0,1,1,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,1,1,1,1},
		{1,0,0,1,1,0,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,0,0,0,0,1},
		{1,1,0,1,1,0,1,1,1,1,0,0,0,1,0,1,0,0,0,1,0,1,1,1,0,1,1,1,1,1},
		{1,0,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,0,0,0,0,0,0,1,1},
		{1,0,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,0,1,1},
		{1,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,0,1,1,1,0,1,0,0,0,1,1},
		{1,0,1,1,0,1,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,1,1,1,0,1,1},
		{1,1,1,1,0,1,1,1,0,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1},
		{1,1,1,0,0,0,0,1,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,1},
		{1,0,0,0,1,1,0,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,1,0,1,1,1,1,1},
		{1,0,1,1,1,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1,1,1,0,1,1,1,1,1},
		{1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,0,1,1,1,1,0,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,1,1,0,1,1,1,1,1,1,0,1,1,1},
		{1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,0,0,0,0,0,1,1,1},
		{1,0,0,0,1,0,0,0,1,1,0,0,0,0,1,0,0,1,0,0,0,0,0,1,1,1,0,1,1,1},
		{1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1},
		{1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,0,0,0,0,0,1},
		{1,1,1,0,1,1,1,1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1},
		{1,0,1,0,1,1,1,1,0,1,1,1,1,0,1,1,0,1,0,1,1,1,1,1,0,1,1,0,1,1},
		{1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,1,1,1,0,1,0,0,0,0,0,1,1,0,1,1},
		{1,0,1,0,1,1,1,1,0,1,1,1,0,0,1,1,0,1,0,1,1,1,1,1,0,0,1,0,1,1},
		{1,0,1,0,0,0,0,0,0,1,0,1,1,0,1,1,0,1,0,1,1,1,1,1,1,0,0,0,1,1},
		{1,0,1,0,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,1,1,1,1,1,1,1,0,1,1},
		{1,0,0,0,1,1,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,2},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}	//90
	},

	/////////////////////////////////////////////////////////////////////////

	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//2
		{1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1},
		{1,1,0,1,0,1,1,1,0,1,0,0,1,1,1,0,1,1,1,0,0,0,1,0,1,0,1,1,0,1},
		{1,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,1,1,0,1,0,1,1,0,1},
		{1,0,0,1,0,1,0,0,0,1,0,1,0,1,1,1,1,0,1,0,0,0,0,0,1,1,0,0,0,1},
		{1,1,1,1,0,1,1,1,1,1,1,1,0,1,0,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1},
		{1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,1,0,1,1,1,0,0,0,1,1,0,1,0,1},
		{1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,0,0,0,0,1,0,0,0,0,1,1,1},
		{1,0,1,1,0,1,1,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1},
		{1,0,0,0,0,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,0,0,0,1,0,1,1,1,0,1},
		{1,0,1,1,1,1,1,1,1,0,1,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1},
		{1,1,0,0,0,0,0,0,1,1,1,0,1,0,1,0,1,1,0,1,0,1,1,1,1,1,1,0,0,1},
		{1,1,0,1,1,0,1,0,0,0,0,0,1,0,0,0,1,1,0,1,1,0,0,0,0,1,1,1,0,1},
		{1,0,0,1,0,0,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,1},
		{1,0,1,1,1,1,0,0,0,0,0,1,1,0,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,1,1,1,0,0,1,0,1,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1},
		{1,1,1,1,1,1,1,1,0,1,1,0,0,1,1,0,1,0,1,1,0,1,1,1,0,1,0,1,0,1},
		{1,1,0,0,1,0,0,0,0,1,1,1,0,0,1,0,1,0,1,1,0,0,0,0,0,1,0,0,0,1},
		{1,1,0,1,1,0,1,1,0,0,0,1,1,0,0,0,0,0,1,0,0,1,1,1,1,1,1,0,1,1},
		{1,1,0,0,0,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,1,0,1,1},
		{1,1,0,1,1,1,0,0,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,0,1,0,1,1},
		{1,0,0,1,1,1,0,1,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,1},
		{1,1,0,0,0,1,1,0,0,0,0,0,1,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,1},
		{1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,2},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}	//274
	},
	////////////////////////////////////////////////////////////////////////////
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//3
		{1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1,0,0,0,0,1},
		{1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,1,0,1,0,1,0,0,0,0,1,0,1,1},
		{1,0,0,0,1,0,0,0,0,0,1,1,1,0,1,0,0,1,0,1,1,0,0,1,1,1,1,0,0,1},
		{1,0,1,1,1,0,1,1,1,1,0,0,0,0,1,1,0,1,0,1,0,0,1,0,0,0,0,1,0,1},
		{1,0,0,0,0,0,1,0,1,1,0,1,1,1,1,0,0,1,0,0,0,1,0,0,1,1,0,1,0,1},
		{1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,1,1,0,0,0,0,1},
		{1,1,0,0,0,1,0,0,0,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,0,0,1,0,1,1},
		{1,0,0,1,0,0,0,1,1,0,0,0,1,0,1,1,0,0,0,1,1,0,1,0,1,1,1,1,0,1},
		{1,0,1,1,1,1,1,0,0,1,1,0,0,0,0,1,0,1,0,1,1,0,1,1,0,0,0,0,0,1},
		{1,0,0,1,0,0,1,0,1,0,1,1,0,1,0,1,1,1,0,1,1,0,0,0,1,1,1,1,1,1},
		{1,1,0,0,1,0,0,0,1,0,0,1,0,1,0,0,0,0,0,1,0,1,1,0,1,0,0,0,0,1},
		{1,0,1,0,0,1,1,0,1,1,0,0,0,1,1,1,1,1,1,1,0,1,0,1,1,0,1,1,0,1},
		{1,0,0,1,0,0,0,0,1,1,1,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1},
		{1,1,1,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1},
		{1,0,0,1,0,1,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,1,0,0,0,1,0,1},
		{1,1,0,1,1,0,0,0,1,0,0,1,1,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1},
		{1,0,0,0,0,1,1,0,1,1,0,1,0,0,0,1,0,0,0,1,0,0,1,0,1,1,1,1,1,1},
		{1,0,1,1,0,0,0,0,0,0,0,1,0,1,1,0,1,1,1,1,0,1,1,0,0,1,0,0,0,1},
		{1,0,1,1,1,1,1,1,0,1,1,1,0,0,0,1,0,0,0,1,0,0,0,1,1,0,0,1,0,1},
		{1,0,1,0,0,0,0,1,0,0,1,1,1,1,1,0,0,1,0,1,1,1,0,1,0,0,1,1,0,1},
		{1,0,0,0,1,1,0,1,0,1,1,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,1,0,0,1},
		{1,1,0,1,0,0,0,1,0,0,1,0,1,0,1,1,0,1,1,1,1,1,0,1,1,0,0,0,1,1},
		{1,0,1,1,0,1,0,1,0,1,1,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,1,1},
		{1,0,1,0,0,1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1},
		{1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,2},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//108
	},
	////////////////////////////////////////////////////////////////////////
	{	
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },	//4	
		{ 1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,1 },
		{ 1,0,0,0,0,0,1,0,1,1,0,1,0,0,0,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1 },
		{ 1,1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1 },
		{ 1,0,0,0,0,0,1,0,1,1,0,1,0,1,1,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1 },
		{ 1,0,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,1,1,1,1,1,0,0,0,1,0,0,0,1 },
		{ 1,1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1 },
		{ 1,0,0,0,0,0,1,0,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1 },
		{ 1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,0,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,0,1,0,1,1,1 },
		{ 1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,1,1,1,0,1,1,1,1,0,1,1,1 },
		{ 1,1,0,1,1,1,0,1,1,0,1,1,1,1,0,1,1,0,1,0,1,0,0,0,1,0,0,0,0,1 },
		{ 1,1,0,1,1,1,0,1,1,0,0,0,0,1,0,1,1,0,1,0,1,0,1,1,1,1,1,1,0,1 },
		{ 1,0,0,1,1,1,0,0,1,1,1,1,0,1,0,1,1,0,0,0,1,0,1,1,0,0,0,1,0,1 },
		{ 1,0,1,1,1,1,1,0,1,0,0,0,0,1,0,1,1,1,1,1,1,0,1,1,0,1,0,1,0,1 },
		{ 1,0,1,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,1,1,1,0,1,1,0,1,0,1,0,1 },
		{ 1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,1,0,1,0,1 },
		{ 1,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1 },
		{ 1,1,1,1,1,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1 },
		{ 1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,0,1 },
		{ 1,0,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,0,1 },
		{ 1,0,0,0,1,0,0,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,1 },
		{ 1,1,1,0,1,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,1,1,1 },
		{ 1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,2 },	
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },	//194
	}
};

int mc = 0;	 //맵 바꾸기 ㅅㄱ
int ran = 0;    //도착지를 번경시킬 ran 함수
int stage = 0;	//스테이지 출력
int turn = 0;	//플레이어가 움직인 횟수
int star = 0;	//별 개수
int mr;	//맵 종류
int nturn;	//남은 턴수


typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE; //커서숨기는 함수에 사용되는 열거형
void setcursortype(CURSOR_TYPE c) { //커서숨기는 함수 
	CONSOLE_CURSOR_INFO CurInfo;

	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1; //커서의 사이즈
		CurInfo.bVisible = FALSE;   //커서 숨김
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void gotoxy(int x, int y)   //플레이어의 좌표를 움직일 gotoxy

{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int title();
void map_create();  //미로 맵 구현 함수
void rule();
void move_player(); //플레이어를 움직이는 함수
int tx, ty;

int main()
{
	srand(time(NULL));
	char y;
	int title_check;    //check를 검사해 그에 맞는 결과 출력
	setcursortype(NOCURSOR);

	while (true)
	{
		system("cls");
		title_check = title();

		if (title_check == 1)	//START
		{
			mr = rand() % 5;
			system("cls");
			turn = 0;
			map_create(mr);
			move_player();
			gotoxy(100, 21);
			printf("Clear!!!");
			//?
			Sleep(3000);	//3초(1초당 1000)동안 코드 일시정지


		}
		else if (title_check == 2)	//RULE
		{
			system("cls");
			rule();
		}
		else //EXIT
		{
			system("cls");
			return 0;
		}

	}
}

void move_player()  //플레이어 움직이기, goytoxy로 플레이어(3)의 좌표를 바꿈
{

	int key;    //키입력 변수
	int x = 1, y = 3;   //플레이어의 시작 좌표
	tx = x * 2 + 25;     //도형이 2칸이라 생기는 오류를 해결하기 위해 *2를 함 +25는 맵을 중앙으로 옮기기 위함
	ty = y + 2;	//+2는 맵을 중앙으로 옮기긱 위함
	gotoxy(tx, ty); printf("●"); //현재의 x좌표와 y좌표인 [1][3]위치에 플레이어 출력 
	while (tx != 83 || ty != 27)  //도착지점 도달시 종료
	{
		ty = y + 2;
		key = getch();
		if (key == UP && map[mr][y - 1][x] != 1)	//위로 이동
		{

			y--;
			ty = y + 2;
			gotoxy(tx, ty); printf("●");	//플레이어가 움직인 위치에 ●출력
			gotoxy(tx, ty + 1); printf("  ");	//전 자리에 공백 출력
			turn++;
		}
		else if (key == LEFT && map[mr][y][x - 1] != 1 && x != 0)	//왼쪽으로 이동
		{

			x--;
			tx = x * 2 + 25;
			gotoxy(tx, ty); printf("●");
			gotoxy(tx + 2, ty); printf("  ");
			turn++;
		}
		else if (key == DOWN && map[mr][y + 1][x] != 1)	//아래쪽으로 이동
		{

			y++;
			ty = y + 2;
			gotoxy(tx, ty); printf("●");
			gotoxy(tx, ty - 1); printf("  ");
			turn++;
		}
		else if (key == RIGHT && map[mr][y][x + 1] != 1)	//오른쪽으로 이동
		{

			x++;
			tx = x * 2 + 25;
			gotoxy(tx, ty); printf("●");
			gotoxy(tx - 2, ty); printf("  ");
			turn++;
		}
		gotoxy(90, 8);	//turn을 기록할 코드
		printf("◆      TURN : %3d     ", turn);
	}
	star++;	//맵 종료시 별의 개수 증가
}

void rule()	//미로의 룰
{
	system("cls");
	while (1) {
		if (kbhit()) {
			if (getch() == 13) break;
		}
		gotoxy(55, 3);
		printf("R U L E");
		gotoxy(17, 7);
		printf("┌──────────────────────────┐");
		gotoxy(17, 8);
		printf("│        ♧이동 키♧       │");
		gotoxy(17, 9);
		printf("◇                         ◇");
		gotoxy(17, 10);
		printf("│    방향키를 사용하세요   │");
		gotoxy(17, 11);
		printf("◇                         ◇");
		gotoxy(17, 12);
		printf("│   ▲ : 위로 이동         │");
		gotoxy(17, 13);
		printf("◇                         ◇");
		gotoxy(17, 14);
		printf("│                          │");
		gotoxy(17, 15);
		printf("◇  ◀ : 왼쪽으로 이동     ◇");
		gotoxy(17, 16);
		printf("│                          │");
		gotoxy(17, 17);
		printf("◇                         ◇");
		gotoxy(17, 18);
		printf("│   ▼ : 아래쪽으로 이동   │");
		gotoxy(17, 19);
		printf("◇                         ◇");
		gotoxy(17, 20);
		printf("│                          │");
		gotoxy(17, 21);
		printf("◇  ▶ : 오른쪽으로 이동   ◇");
		gotoxy(17, 22);
		printf("│                          │");
		gotoxy(17, 23);
		printf("└──────────────────────────┘");
		gotoxy(72, 7);
		printf("┌──────────────────────────┐");
		gotoxy(72, 8);
		printf("│       ※미로 규칙※      │");
		gotoxy(72, 9);
		printf("◆                         ◆");
		gotoxy(72, 10);
		printf("│       미로 세부 규칙     │");
		gotoxy(72, 11);
		printf("◆                         ◆");
		gotoxy(72, 12);
		printf("│   TURN : 움직인 횟수     │");
		gotoxy(72, 13);
		printf("◆                         ◆");
		gotoxy(72, 14);
		printf("│                          │");
		gotoxy(72, 15);
		printf("◆  STARS : 획득한 별 개수 ◆");
		gotoxy(72, 16);
		printf("│                          │");
		gotoxy(72, 17);
		printf("◆                         ◆");
		gotoxy(72, 18);
		printf("│   STAGE : 스테이지(레벨) │");
		gotoxy(72, 19);
		printf("◆                         ◆");
		gotoxy(72, 20);
		printf("│                          │");
		gotoxy(72, 21);
		printf("◆                         ◆");
		gotoxy(72, 22);
		printf("│                          │");
		gotoxy(72, 23);
		printf("└──────────────────────────┘");
		gotoxy(17, 25);
		printf("◆ 메인으로 돌아가려면 ENTER 키를 누르세용");
	}
}

void map_create(int n)   //미로 맵 제작
{
	//obstacle();
	gotoxy(25, 2);
	for (int i = 0; i < MAX_I; i++) {
		for (int j = 0; j < MAX_J; j++) {
			if (map[n][i][j] == 1)	//map배열에서 모든 1을 □로 출력(벽)
				printf("□");
			else if (map[n][i][j] == 0)
				printf("  ");	//map배열에서 모든 0을 공백으로 출력(길)
			else if (map[n][i][j] == 2)
				printf("★");	//map배열에서 모든 2을 ★로 출력(도착지점)
		}
		gotoxy(25, 2 + i + 1);
	}
	stage++;
	gotoxy(90, 2);
	printf("┌                       ┐");
	gotoxy(90, 3);
	printf("│     ◈ M A Z E ◈     │");
	gotoxy(90, 4);
	printf("◆                      ◆");
	gotoxy(90, 5);
	printf("│       STAGE : %d       │", stage);
	gotoxy(90, 6);
	printf("◆                      ◆");
	gotoxy(90, 7);
	printf("│                       │");
	gotoxy(90, 8);
	printf("◆      TURN :   0      ◆");
	gotoxy(90, 9);
	printf("│                       │");
	gotoxy(90, 10);
	printf("◆                      ◆");
	gotoxy(90, 11);
	printf("│       STARS : %d       │",star);
	gotoxy(90, 12);
	printf("◆                      ◆");
	gotoxy(90, 13);
	printf("│                       │");
	gotoxy(90, 14);
	printf("◆                      ◆");
	gotoxy(90, 15);
	printf("│                       │");
	gotoxy(90, 16);
	printf("◆                      ◆");
	gotoxy(90, 17);
	printf("│                       │");
	gotoxy(90, 18);
	printf("◆                      ◆");
	gotoxy(90, 19);
	printf("│                       │");
	gotoxy(90, 20);
	printf("◆                      ◆");
	gotoxy(90, 21);
	printf("│                       │");
	gotoxy(90, 22);
	printf("◆                      ◆");
	gotoxy(90, 23);
	printf("│                       │");
	gotoxy(90, 24);
	printf("◆                      ◆");
	gotoxy(90, 25);
	printf("│                       │");
	gotoxy(90, 26);
	printf("◆                      ◆");
	gotoxy(90, 27);
	printf("│                       │");
	gotoxy(90, 28);
	printf("└                       ┘");

}

int title()     //메인 화면
{
	int key = 0;
	int x = 48; //타이틀화면이 표시되는 x좌표 
	int y = 4; //타이틀화면이 표시되는 y좌표 
	int check = 1;

	gotoxy(x + 5, y + 2); printf("◈ M A Z E ◈");    //타이틀 화면
	gotoxy(x + 6, 29);
	printf("  ");
	y = 13;
	x = 52;

	gotoxy(x, y - 1); printf("┌──────────┐");   //선택 커서
	gotoxy(x, y + 1); printf("└──────────┘");
	gotoxy(x + 2, y); printf("S T A R T");      //시작 화면
	gotoxy(x + 2, y + 2); printf("R U   L E");  //규칙
	gotoxy(x + 2, y + 4); printf("E X   I T");  //끝
	while (true)
	{


		key = getch();

		if (key == RIGHT)   //키를 입력했을때 실행 창으로 넘어감
		{
			return check;   //상황에 따른check return
		}
		else if (key == DOWN && check < 3)
		{
			check++;
			y += 2;
			gotoxy(x, y - 3); printf("            ");
			gotoxy(x, y - 1); printf("┌──────────┐");   //커서를 아래쭉으로
			gotoxy(x, y + 1); printf("└──────────┘");
		}
		else if (key == DOWN || key == UP && check < 2)
		{
			check += 2;
		}
		else if (key == UP && check > 1)
		{
			check--;
			y -= 2;
			gotoxy(x, y + 3); printf("            ");
			gotoxy(x, y - 1); printf("┌──────────┐");   //커서를 위쪽으로
			gotoxy(x, y + 1); printf("└──────────┘");
		}

	}
}