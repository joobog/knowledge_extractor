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
#include <cstdio>
#include <thread>


void random_file_access(const std::string& filename) {
	using namespace std;
	FILE * pFile;
	//	char buffer[] = {'a', 'b'};
	char buffer[] = "long buffe, lalala";
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
}

int main( int argc, char ** argv )
{
	using namespace std;

	const string filename1 = "test1.dat";
	const string filename2 = "test2.dat";

	thread t1(random_file_access, filename1);
	thread t2(random_file_access, filename2);

	t1.join();
	t2.join();

	return 0;
}

