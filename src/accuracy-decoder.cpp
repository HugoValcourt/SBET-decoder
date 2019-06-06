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
#include "AccuracyPrinter.hpp"

/**
 * show the instruction of the of the main function usage
 */
void printUsage(){
	printf("Usage: accuracy-decoder input-file\n");
	exit(0);
}

/**
 * Read a SBET input file with a AccuracyPrinter
 * 
 * @param argc number of argument
 * @param argv arguments value
 */
int main(int argc,char ** argv){

	if(argc != 2){
		printUsage();
	}

	std::string inputFile = argv[1];

	AccuracyPrinter accuracy;

	accuracy.readFile(inputFile);

	return 0;
}

#endif
