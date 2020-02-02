/*********************************************************************/
/* Homework Assignment 5, for EECS 22, Fall 2017                     */
/*                                                                   */
/* Author: Tim Schmidt                                               */
/* Date: 11/09/2017                                                  */
/*                                                                   */
/* Movie.h: header file for basic movie manipulations                */
/*                                                                   */
/*********************************************************************/

#ifndef MOVIE_H
#define MOVIE_H

#include "ImageList.h"

/* the movie structure */
typedef struct {
	ILIST *Frames;
} MOVIE;

/* Allocate the memory space for the movie and the memory space */
/* for the frame list. Return the pointer to the movie. */
MOVIE *CreateMovie(void);

/* Release the memory space for the frame list. */
/* Release the memory space for the movie. */
void DeleteMovie(MOVIE *movie);

/* Convert a YUV movie to a RGB movie */
void YUV2RGBMovie(MOVIE *movie);

/* Convert a RGB movie to a YUV movie */
void RGB2YUVMovie(MOVIE *movie);

/* Get number of frames from a movie */
int MovieLength(const MOVIE *movie);

/* Get height of movie */
int MovieHeight(const MOVIE *movie);

/* Get width of movie */
int MovieWidth(const MOVIE *movie);

#endif
