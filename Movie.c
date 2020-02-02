/*********************************************************************/
/* Homework Assignment 5, for EECS 22, Fall 2017                     */
/*                                                                   */
/* Author: Mason Harlan                                              */
/* Date: 11/09/2017                                                  */
/*                                                                   */
/* Movie.c: source file for basic movie manipulations                */
/*                                                                   */
/*********************************************************************/

#include <stdlib.h>
#include <assert.h>
#include "Movie.h"

/* Allocate the memory space for the movie and the memory space */
/* for the frame list. Return the pointer to the movie. */
MOVIE *CreateMovie(void)
{
	MOVIE *e;
	e = malloc(sizeof(MOVIE));
	if(!e){
		perror("Out of memory! Aborting...");
		exit(10);
	}
	e->Frames = NULL;
	e->Frames = CreateImageList();
	return e;
}

/* Release the memory space for the frame list. */
/* Release the memory space for the movie. */
void DeleteMovie(MOVIE *movie)
{
	assert(movie);
	DeleteImageList(movie->Frames);
	movie->Frames = NULL;
	free(movie);
}

/* Convert a YUV movie to a RGB movie */
void YUV2RGBMovie(MOVIE *movie)
{
	int Y;
	int U;
	int V;
	int C,D,E;
	int R,G,B;
	int width = MovieWidth(movie);
	int height = MovieHeight(movie);
	IENTRY *entry;
	int len = MovieLength(movie);
	entry = movie->Frames->First;
	for (int i =0; i < len; i++){
		entry->RGBImage = CreateImage(width,height);
		for(int x =0; x<MovieWidth(movie); x++){//converting loop
			for(int y =0; y<MovieHeight(movie); y++){
				Y = GetPixelY(entry->YUVImage,x,y);
				U = GetPixelU(entry->YUVImage,x,y);
				V = GetPixelV(entry->YUVImage, x,y);
				C = Y - 16;
				D = U - 128;
				E = V - 128;
				R = ((298 * C + 409 * E + 128)>>8);
				G = ((298 * C - 100 * D - 208 * E + 128)>>8);
				B = ((298 * C + 516 * D + 128)>>8);
				if (R>255){R = 255;}
				if (R<0){R=0;}
				if (G>255){G = 255;}
				if (G<0){G=0;}
				if (B>255){B = 255;}
				if (B<0){B=0;}
				SetPixelR(entry->RGBImage,x,y,R);
				SetPixelG(entry->RGBImage,x,y,G);
				SetPixelB(entry->RGBImage,x,y,B);
			}
		}
		DeleteYUVImage(entry->YUVImage);
		entry->YUVImage =NULL;
		entry = entry->Next;
	}
}

/* Convert a RGB movie to a YUV movie */
void RGB2YUVMovie(MOVIE *movie)
{
	int Y, U, V;
	int R,G,B;
	int width = MovieWidth(movie);
	int height = MovieHeight(movie);
	IENTRY *entry;
	int len = MovieLength(movie);
	entry = movie->Frames->First;
	for (int i =0; i < len; i++){//converting loop
		entry->YUVImage = CreateYUVImage(width,height);
		for(int x =0; x<MovieWidth(movie); x++){
			for(int y =0; y<MovieHeight(movie); y++){
				R = GetPixelR(entry->RGBImage,x,y);
				G = GetPixelG(entry->RGBImage,x,y);
				B = GetPixelB(entry->RGBImage, x,y);
				Y = (((66*R + 129*G + 25*B + 128)>>8)+16);
				U = (((-38*R - 74*G +112*B + 128)>>8)+128);
				V = (((112*R - 94*G - 18*B + 128)>>8)+128);	
				if (Y>255){Y = 255;}
				if (Y<0){Y=0;}
				if (U>255){U = 255;}
				if (U<0){U=0;}
				if (V>255){V = 255;}
				if (V<0){V=0;}
				SetPixelY(entry->YUVImage,x,y,Y);
				SetPixelU(entry->YUVImage,x,y,U);
				SetPixelV(entry->YUVImage,x,y,V);
			}
		}
		DeleteImage(entry->RGBImage);
		entry->RGBImage = NULL;	
		entry = entry->Next;
	}	
}

int MovieLength(const MOVIE *movie)
{
	return(movie->Frames->length);
}

int MovieHeight(const MOVIE *movie)
{
	if(movie->Frames->First->RGBImage){
		return(movie->Frames->First->RGBImage->H);
	}
	else{
		return(movie->Frames->First->YUVImage->H);
	}
}

int MovieWidth(const MOVIE *movie)
{
	if(movie->Frames->First->RGBImage){
		return(movie->Frames->First->RGBImage->W);
	}
	else{
		return(movie->Frames->First->YUVImage->W);
	}
}

/* EOF */
