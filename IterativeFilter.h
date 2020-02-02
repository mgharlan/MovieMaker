/*********************************************************************/
/* Homework Assignment 5, for EECS 22, Fall 2018                     */
/*                                                                   */
/* Author: Jordan Bonecutter                                         */
/*                                                                   */
/* IterativeFilter.h: file for iterative filters                     */
/*                                                                   */
/*********************************************************************/

#ifndef ITERATIVEFILTER_H
#define ITERATIVEFILTER_H

#include "Image.h"
#include "Movie.h"

// Typedef for iterableFilter
/* iterableFilter function pointer */
typedef IMAGE * (*iterableFilter)(IMAGE *image, float parameter);

// Function declaration for doIterativeFilter
/* Generate movie from input image by applying filter with parameter from <start> to <end> using <step> variation */
MOVIE *doIterativeFilter(IMAGE *image, iterableFilter filter, float start, float end, float change);

#endif
