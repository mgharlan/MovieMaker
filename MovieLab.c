/*********************************************************************/
/* Homework Assignment 5, for EECS 22, Fall 2017                     */
/* Modified by Mihnea Chirila for EECS 22 Fall 2018                                                            */
/* Author: Mason Harlan                                               */
/* Date: 11/09/2017                                                  */
/*                                                                   */
/* MovieLab.c: source file for the main function                     */
/*                                                                   */
/* Please use this template for your HW5.                            */
/*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "FileIO.h"
#include "DIPs.h"
#include "Movie.h"
#include "Constants.h"
#include "Image.h"
#include "MovieIO.h"
#include "IterativeFilter.h"

void PrintUsage(char *ProgramName);

int main(int argc, char *argv[])
{
	char *startVal = NULL;
	char *endVal = NULL;
	char *step = NULL;
	char *frameNum = NULL;
	int cutoff = 0;
	int ihue = 0;
	int isat = 0;
	int reverse = 0;
	int iW =0;
	int iH=0;
	char *Size = NULL;
	char *InMovieName = NULL;
	char *InImageName = NULL;
	char *OutFileName = NULL;
	float start = 0, end = 0, change = 0, frames = 0;

	for(int i =1; i<argc; i++){
		if(0 == strcmp(argv[i], "-h")){
			PrintUsage(argv[0]);
			exit(0);
		}
		else if (0 == strcmp(argv[i], "-i")){
			i++;
			if (i<argc){InImageName = argv[i];}
		}
		else if (0 == strcmp(argv[i], "-o")){
			i++;
			if (i<argc){OutFileName = argv[i];}
		}
		else if (0 == strcmp(argv[i], "-start=")){
			i++;
			if (i<argc){
				startVal = argv[i];
				start = atof(startVal);
			}
		}
		else if (0 == strcmp(argv[i], "-m")){
			i++;
			if(i<argc){InMovieName = argv[i];}
		}
		else if(0 == strcmp(argv[i], "-f")){
			i++;
			if(i<argc){
				frameNum = argv[i];
				frames = atof(frameNum);
			}
		}
		else if (0 == strcmp(argv[i], "-end=")){
			i++;
			if(i<argc){
				endVal = argv[i];
				end = atof(endVal);
			}
		}
		else if (0 == strcmp(argv[i], "-step=")){
			i++;
			if(i<argc){
				step = argv[i];
				change = atof(step);
			}
		}
		else if(0 == strcmp(argv[i], "-s")){
			i++;
			if(i<argc){
				Size = argv[i];
				for (int j =0; j < strlen(Size)-1; j++){
					if (Size[j]== 'x'){
						cutoff = j;
						break;
					}
				}
				Size[cutoff] = 0;
				iW = atof(Size);
				Size[cutoff] = 'x';
				for(int q=cutoff+1;q<strlen(Size);q++){
					Size[q-cutoff-1] = Size[q];
				}
				Size[strlen(Size)-cutoff-1]=0;
				iH = atof(Size);
			}
		}
		else if(0 == strcmp(argv[i], "-hue")){
			ihue = 1;
		}
		else if(0 == strcmp(argv[i], "-saturation")){
			isat = 1;
		}
		else if(0 == strcmp(argv[i], "-reverse")){
			reverse = 1;
		}
		else{
			fprintf(stderr, "Unknown option %s!\n", argv[i]);
			PrintUsage(argv[0]);
		}
	}
	
	if(isat == 1){
		if (InImageName == NULL){
			printf("No Input Image File Provided\n");
			exit(0);
		}
		else if (OutFileName == NULL){
			printf("No Output Movie File Provided\n");
			exit(0);
		}
		else if (endVal == NULL){
			printf("End Value not Provided\n");
			exit(0);
		}
		else if (startVal == NULL){
			printf("Start Value not Provided\n");
			exit(0);
		}
		else if(step == NULL){
			printf("Step Value not Provided\n");
			exit(0);
		}
		else{
			MOVIE *M = NULL;
			IMAGE *image = NULL;
			image = LoadImage(InImageName);
			M = doIterativeFilter(image, Saturation, start, end, change);
			RGB2YUVMovie(M);
			SaveMovie(OutFileName,M);
			DeleteImage(image);		
			DeleteMovie(M);
		}
		
	}
	else if (ihue == 1){
		if (InImageName == NULL){
			printf("No Input Image File Provided\n");
			exit(0);
		}
		else if (OutFileName == NULL){
			printf("No Output Movie File Provided\n");
			exit(0);
		}
		else if (endVal == NULL){
			printf("End Value not Provided\n");
			exit(0);
		}
		else if (startVal == NULL){
			printf("Start Value not Provided\n");
			exit(0);
		}
		else if(step == NULL){
			printf("Step Value not Provided\n");
			exit(0);
		}
		else{
			MOVIE *M = NULL;
			IMAGE *image = NULL;
			image = LoadImage(InImageName);
			M = doIterativeFilter(image, HueRotate, start, end, change);
			RGB2YUVMovie(M);
			SaveMovie(OutFileName,M);
			DeleteImage(image);		
			DeleteMovie(M);
		}
	}
	else if (reverse == 1){
		if (InMovieName == NULL){
			printf("No Input Movie File Provided\n");
			exit(0);
		}
		else if (OutFileName == NULL){
			printf("No Output Movie File Provided\n");
			exit(0);
		}
		else if (frameNum == NULL){
			printf("Number of Frames not Provided\n");
			exit(0);
		}
		else if (Size == NULL){
			printf("Size of Movie not Provided\n");
			exit(0);
		}
		else{
			MOVIE *M = NULL;
			M = LoadMovie(InMovieName, frames, iW, iH);
			ReverseImageList(M->Frames);
			SaveMovie(OutFileName,M);
			DeleteMovie(M);
		}
	}
	else{
		printf("No filter selected\n");
	}
	return 0;
}

void PrintUsage(char *ProgramName){
	fprintf(stderr, "Usage: %s [option...]\n"
	"Option:			Function:\n"
	"-h:			print this usage info.\n"
	"-i <file.ppm>:		import image.\n"
	"-o <file.yuv>:		export movie.\n"
	"-start=<startVal>:	set start parameter.\n"
	"-end=<endVal>:		set end parameter.\n"
	"-step=<stepVal>: 	set step parameter.\n"
	"-hue:			use hue filter.\n"
	"-saturation:		use saturation filter.\n"
	"-m <file.yuv>:		import movie.\n"
	"-f <frameNum>:		number of frames in the input movie.\n"
	"-s <WxH>:		size of a movie frame.\n"
	"-reverse:		reverses the inputted movie.\n",
	ProgramName);
}

/* EOF */
