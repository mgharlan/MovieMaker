/*********************************************************************/
/* Homework Assignment 5, for EECS 22, Fall 2017                     */
/*                                                                   */
/* Author: Mason Harlan                                              */
/* Date: 11/09/2017                                                  */
/*                                                                   */
/* MovieIO.h: header file for MOVIE input and ouput operations       */
/*                                                                   */
/*********************************************************************/

#include "Movie.h"
#include <stdio.h>
#include <assert.h>
#include "FileIO.h"

/* Load the movie frames from the input file */
MOVIE *LoadMovie(const char *fname, int frameNum,
                 unsigned int width, unsigned height);

/* Load one movie frame from the input file */
YUVIMAGE *LoadOneFrame(const char* fname, int n,
                       unsigned int width, unsigned height);

/* Save the movie frames to the output file */
int SaveMovie(const char *fname, MOVIE *movie);

/* Saves one movie frame to the output file */
void SaveOneFrame(YUVIMAGE *image, const char *fname, FILE *file);
