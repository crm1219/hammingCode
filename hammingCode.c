// header files
# include <stdio.h>
# include <math.h>

// main function
int main()
{
	// declare variables
		// stores user input
	int data;
	int evenParity, oddParity;
	char direction;
		// stores binary number
	int binData[8] = {};
		// stores Hamming code
	int codeArray[12] = {};
	// print title
	printf("This is a program to encode byte values as Hamming Code.\n");
	// prompt for input for number and read input
	printf("Enter a number to encode between 0 and 255: ");
	scanf(" %d", &data);
	// prompt for input for parity and read input
	printf("Enter 0 if you want even parity to be represented by 0 and 1 if you\
 want it to be represented by 1: ");
	scanf(" %d", &evenParity);
	// prompt for input for direction and read input
	printf("Enter which direction you want the Hamming code to run - f for \
forwards and b for backwards: ");
	scanf(" %c", &direction);
	// loop through array to store the binary number
	for (int i = 7; i >= 0; i--)
	{
		double power = i;
		// check if the number is greater than each power of two
		if (data - pow(2, power) >= 0)
		{
			// if so, set bit at the appropriate location equal to 1
			binData[7-i] = 1;
			// subtract power of two from the number
			data -= pow(2, power);
		}
	}
	// set value for odd parity in contrast to value for even parity
	if (evenParity == 0)
	{
		oddParity = 1;
	}
	else if (evenParity == 1)
	{
		oddParity = 0;
	}
	// check if Hamming code should run forward
	if (direction == 'f')
	{
		// place each bit from the data in appropriate locations
		codeArray[0] = binData[0];
		codeArray[1] = binData[1];
		codeArray[2] = binData[2];
		codeArray[3] = binData[3];
		codeArray[5] = binData[4];
		codeArray[6] = binData[5];
		codeArray[7] = binData[6];
		codeArray[9] = binData[7];
		// determine what the first parity bit should be
		if ((codeArray[9] + codeArray[7] + codeArray[5] + codeArray[3] +
		codeArray[1]) % 2 == 0)
		{
			codeArray[11] = evenParity;
		}
		else
		{
			codeArray[11] = oddParity;
		}
		// determine what the second parity bit should be
		if ((codeArray[9] + codeArray[6] + codeArray[5] + codeArray[2] +
		codeArray[1]) % 2 == 0)
		{
			codeArray[10] = evenParity;
		}
		else
		{
			codeArray[10] = oddParity;
		}
		// determine what the third parity bit should be
		if ((codeArray[7] + codeArray[6] + codeArray[5] + codeArray[0]) % 2 == 0)
		{
			codeArray[8] = evenParity;
		}
		else
		{
			codeArray[8] = oddParity;
		}
		// determine what the fourth parity bit should be
		if ((codeArray[3] + codeArray[2] + codeArray[1] + codeArray[0]) % 2 == 0)
		{
			codeArray[4] = evenParity;
		}
		else
		{
			codeArray[4] = oddParity;
		}
	}
	// check if Hamming code should run backward
	else if (direction == 'b')
	{
		// place each bit from the data in appropriate locations
		codeArray[2] = binData[0];
		codeArray[4] = binData[1];
		codeArray[5] = binData[2];
		codeArray[6] = binData[3];
		codeArray[8] = binData[4];
		codeArray[9] = binData[5];
		codeArray[10] = binData[6];
		codeArray[11] = binData[7];
		// determine what the first parity bit should be
		if ((codeArray[2] + codeArray[4] + codeArray[6] + codeArray[8] +
		codeArray[10]) % 2 == 0)
		{
			codeArray[0] = evenParity;
		}
		else
		{
			codeArray[0] = oddParity;
		}
		// determine what the second parity bit should be
		if ((codeArray[2] + codeArray[5] + codeArray[6] + codeArray[9] +
		codeArray[10]) % 2 == 0)
		{
			codeArray[1] = evenParity;
		}
		else
		{
			codeArray[1] = oddParity;
		}
		// determine what the third parity bit should be
		if ((codeArray[4] + codeArray[5] + codeArray[6] + codeArray[11]) % 2 
		== 0)
		{
			codeArray[3] = evenParity;
		}
		else
		{
			codeArray[3] = oddParity;
		}
		// determine what the fourth parity bit should be
		if ((codeArray[8] + codeArray[9] + codeArray[10] + codeArray[11]) % 2 
		== 0)
		{
			codeArray[7] = evenParity;
		}
		else
		{
			codeArray[7] = oddParity;
		}
	}
	// print output
	printf("Your number in binary is: ");
	for (int i = 0; i < 8; i++)
	{
		printf("%d", binData[i]);
	}
	printf("\n");
	printf("The Hamming code for your number is: ");
	for (int i = 0; i < 12; i++)
	{
		printf("%d", codeArray[i]);
	}
	return 0;
}