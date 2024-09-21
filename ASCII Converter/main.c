#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

double f( double x , double b ) {
	double a0 = 186.752;
	double a1 = -148.235;
	double a2 = 34.5049;
	double a3 = -3.5091;
	double a4 = 0.183166;
	double a5 = -0.00513554;
	double a6 = 0.0000735464;
	double a7 = -4.22038e-7;

	return a0 + ( a1 + b ) * x + a2 * pow( x , 2 ) + a3 * pow( x , 3 ) +
		a4 * pow( x , 4 ) + a5 * pow( x , 5 ) + a6 * pow( x , 6 ) +
		a7 * pow( x , 7 );
}




int main( int argc , char * argv[ ] ) {
	int nMessages = 0;

	printf( "Numero de mensagems> " );
	scanf( "%d" , &nMessages );
	printf( "\n" );

	int n = 0;

	while ( n <= nMessages ) {
		int B = 0;
		printf( "B> " );
		scanf( "%d" , &B );
		printf( "\n" );

		char Message[ 100 ];
		printf( "Message> " );
		scanf( "%su" , Message );
		printf( "\n" );

		int j = 1;
		int i = 0;

		for ( i = 0; Message[ i ] != '\0'; i++ ) {
			if ( i % 2 ) {
				if ( !round( f( j , B ) ) ) {
					j++;
					continue;
				}

				char HexString[ 2 ] = { Message[ i - 1 ], Message[ i ] };
				int Ascii = ( int ) strtol( HexString , NULL , 16 );

				if ( !Ascii ) {
					printf( "\nFound break point at index %i!\n" , i );
					break;
				}

				printf( "%c" , ( char ) Ascii);
				j++;
			}
		}
		n++;
	}

	return 0;
}

