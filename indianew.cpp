#include <stdio.h>

// we need to print a series of spaces or ! characters to make the india map
// in any row there can be only 80 characters(command line text box)
// as C/C++ compilers let you assign integers to characters and vice versa
// the original program uses this feature to the hilt. 
// also, C/C++ compilers accept any expression in place of a boolean expression
// for eg if ( a ) is acceptable.
// In languages like Java it will not be possible to write such 
// obfuscated code.
//
// The following code, produces the same result, but has demystified code
// some explanation follows. 
//
//
// As you can see from the output, the entire map is drawn only with two
// characters ie ' ' and '!'
// Values of ' ' and '!'are 32 and 33 in decimal! See how the original 
// program uses xor functions etc to just get 32 and 33, depending on 
// whether to print leading spaces or ! characters.
//
// in the india map
// some rows have leading spaces, followed by !!! and again spaces
// for example the first row is such a row
// The first three characters are TFy, which correspond to 84, 70, 121
// If you subract 65 from them, you will get 19, 5 and 56 respectively.
// Notice that the sum of 19, 5 and 56 is 80 => max no of chars in a row
// 
// some other rows have leading spaces, follwed by !!!, spaces, !!! and finally spaces
// for such a row, 5 characters of the array is used to encode the no of 
// spaces and no of ! to be printed
// 
// this way all the rows are printed, until the end of the array is reached
//
// the author must have painstakingly encoded the ! pattern in a india
// map to create this array...
//
// Hope you are able to understand the logic now! A demystified code
// that does the same function follows...
//

char array[] = "TFy!QJu ROo TNn(ROo)SLq SLq ULo+UHs UJq TNn*RPn/QPbEWS_JSWQAIJO^NBELPeHBFHT}TnALVlBLOFAkHFOuFETpHCStHAUFAgcEAelclcn^r^r\\tZvYxXyT|S~Pn SPm SOn TNn ULo0ULo#ULo-WHq!WFs XDt!";

main()
{
	int a,b=0,c=0;

	while ( 1 )
	{
		a = array[b];
		if ( a == 0 )
		{
			// the entire array has been covered
			break;
		}

		// determine whether to print spaces of the ! character
		// depending on whether we are in the even or odd element
		// of the array
		char temp = ( 0 == ( b++ % 2 ) ) ? ' ':'!';

		while ( a-- > 64 )
		{
			if( ++c == 80 )
			{
				c = 0;
				putchar(10);
				continue;
			}
			putchar ( temp );
		}
	}
}

// end of file