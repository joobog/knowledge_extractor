/*
 * =====================================================================================
 *
 *       Filename:  fwrite.c
 *
 *    Description:  :
 *
 *        Version:  1.0
 *        Created:  03/03/2015 11:01:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <stdio.h>

int main( int argc, char ** argv )
{
	using namespace std;

	string filename;
	if (argc == 2) {
		filename = "./" + string(argv[1]);
	}
	else {
		cout << argc << endl;
		filename = "./testfile.bin";	
	}

	cout << "write data to file : " << filename << endl;

	FILE * pFile;
	char buffer[] = {'a', 'b'};
	pFile = fopen( filename.c_str(), "wb" );
	if (pFile != nullptr) {
		fwrite( buffer , sizeof( char ), 2, pFile );
		int c = fgetc( pFile );
		fseeko(pFile, 0, SEEK_SET);
		fputs( "Test", pFile );
		fprintf( pFile, "%s %d\n", "TESTSTR", 47 );
		fprintf( pFile, "%s\n", "aaaaaaaaaaaaaaaaaaaaaaaa" );
		fseeko(pFile, 20, SEEK_SET);
		fprintf( pFile, "%s\n", "bbbbb" );
		fclose( pFile );
	}
	else {
		cout << "couldn't open file: " << filename << endl;
	}
	return 0;
}

