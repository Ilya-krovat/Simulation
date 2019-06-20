#pragma once

int Max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int Min(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}

int haveSdvig0(int a)
{
	if (a  < 0)
		return -1 * a ;
	else
		return 0;
}

int haveSdvig79(int a)
{
	if (a > 79)
		return 79 - a;
	else
		return 0;
}

int haveSdvig39(int a)
{
	if (a > 39)
		return 39 - a;
	else
		return 0;
}