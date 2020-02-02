/*********************************************************************/
/* Homework Assignment 5, for EECS 22, Fall 2018                     */
/*                                                                   */
/* Author: Mason Harlan                                              */
/*                                                                   */
/* IterativeFilter.c: file for iterative filters                     */
/*                                                                   */
/*********************************************************************/

#include "IterativeFilter.h"

MOVIE *doIterativeFilter(IMAGE *image, iterableFilter filter, float start, float end, float change)
{
	MOVIE *m = CreateMovie();
	IMAGE *temp = NULL;
	if (end>start){//step up
		for (float i = start; i<=end; i+= change){
			temp = CopyImage(image);
			temp = filter(temp, i);
			AppendRGBImage(m->Frames,temp);
		}
	}
	else{//step down
		for (float j = start; j>=end; j-= change){
			temp = CopyImage(image);
			temp = filter(temp, j);
			AppendRGBImage(m->Frames,temp);
		}	
	}
	return m;
}
