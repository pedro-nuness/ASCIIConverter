#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main( int argc , char * argv[ ] ) {

	/*if ( argc < 2 ) {
		printf( "No input detected!\n" );
		return 0;
	}*/

	//char * Message = argv[ 1 ];
	char * Message = "566F6388732073C66F2076656E6365646F867265732C20766F63C3887320636FBE6E73656775656D2E002DC6C921B7B87FCF";
	printf( "Message: %s\n" , Message );

	/*
	 10566F6388732073C66F2076656E6365646F867265732C20766F63C3887320636FBE6E73656775656D2E002DC6C921B7B87FCF
	*/

	for ( int i = 0; Message[ i ] != '\0'; i++ ) {
		if ( i % 2 ) {
			char HexString[ 2 ] = { Message[ i - 1 ], Message[ i ] };

			int Ascii = ( int ) strtol( HexString , NULL , 16 );

			if ( !Ascii ) {
				printf( "\nFound break point at index %i!\n" , i );
				break;
			}

			printf( "%c - %d\n" , ( char ) Ascii, Ascii );
		}
	}
	
	return 0;
}