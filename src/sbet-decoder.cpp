/**
 * @author Guillaume Labbe-Morissette
 */

#ifndef MAIN_CPP
#define MAIN_CPP
//For M_PI
#ifdef _WIN32
#define _USE_MATH_DEFINES
#endif

#include <cstdio>
#include <string>
#include "SbetPrinter.hpp"

/**
 * Show the instruction of the main function usage
 */
void printUsage(){
	printf("Usage: sbet-decoder input-file\n");
	exit(0);
}

/**
 * Read a SBET input file with a SbetPrinter
 * 
 * @param argc number of argument
 * @param argv arguments value
 */
int main(int argc,char ** argv){

	if(argc != 2){
		printUsage();
	}

	std::string inputFile = argv[1];

	SbetPrinter sbet;

	sbet.readFile(inputFile);

	return 0;
}

#endif
