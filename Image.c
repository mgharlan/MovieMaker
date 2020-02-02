/*********************************************************************/
/* Homework Assignment 5, for EECS 22, Fall 2017                     */
/*                                                                   */
/* Author: Mason Harlan                                              */
/* Date: 11/09/2017                                                  */
/*                                                                   */
/* Image.c: source file for basic image manipulations                */
/*                                                                   */
/*********************************************************************/

#include <stdlib.h>
#include <assert.h>
#include "Image.h"

/* Get the intensity value of the Red channel of pixel (x, y) */
/* in the RGB image */
unsigned char GetPixelR(const IMAGE *image, unsigned int x, unsigned int y)
{
	assert(image);

	assert(x < image->W);
	assert(y < image->H);

	assert(image->R);
	assert(image->G);
	assert(image->B);

	return image->R[x + y * image->W];
}

/* Get the intensity value of the Green channel of pixel (x, y) */
/* in the RGB image */
unsigned char GetPixelG(const IMAGE *image, unsigned int x, unsigned int y)
{
	assert(image);

	assert(x < image->W);
	assert(y < image->H);

	assert(image->R);
	assert(image->G);
	assert(image->B);

	return image->G[x + y * image->W];
}

/* Get the intensity value of the Blue channel of pixel (x, y) */
/* in the RGB image */
unsigned char GetPixelB(const IMAGE *image, unsigned int x, unsigned int y)
{
	assert(image);

	assert(x < image->W);
	assert(y < image->H);

	assert(image->R);
	assert(image->G);
	assert(image->B);

	return image->B[x + y * image->W];
}

/* Set the intensity value of the Red channel of pixel (x, y) */
/* in the RGB image with valueR */
void SetPixelR(IMAGE *image, unsigned int x, unsigned int y,
               unsigned char valueR)
{
	assert(image);

	assert(x < image->W);
	assert(y < image->H);

	assert(image->R);
	assert(image->G);
	assert(image->B);

	image->R[x + y * image->W] = valueR;
}

/* Set the intensity value of the Green channel of pixel (x, y) */
/* in the RGB image with valueG */
void SetPixelG(IMAGE *image, unsigned int x, unsigned int y,
               unsigned char valueG)
{
	assert(image);

	assert(x < image->W);
	assert(y < image->H);

	assert(image->R);
	assert(image->G);
	assert(image->B);

	image->G[x + y * image->W] = valueG;
}

/* Set the intensity value of the Blue channel of pixel (x, y) */
/* in the RGB image with valueB */
void SetPixelB(IMAGE *image, unsigned int x, unsigned int y,
               unsigned char valueB)
{
	assert(image);

	assert(x < image->W);
	assert(y < image->H);

	assert(image->R);
	assert(image->G);
	assert(image->B);

	image->B[x + y * image->W] = valueB;
}

/* Allocate the memory space for the RGB image and the memory spaces */
/* for the RGB intensity values. Return the pointer to the RGB image. */
IMAGE *CreateImage(unsigned int width, unsigned int height)
{
	IMAGE *image = (IMAGE *)malloc(sizeof(IMAGE));
	if (image == NULL) {
		return NULL;
	}

	image->W = width;
	image->H = height;

	image->R = (unsigned char*)malloc(width * height * sizeof(unsigned char));
	if (image->R == NULL) {
		free(image);
		return NULL;
	}

	image->G = (unsigned char*)malloc(width * height * sizeof(unsigned char));
	if (image->G == NULL) {
		free(image->R);
		free(image);
		return NULL;
	}

	image->B = (unsigned char*)malloc(width * height * sizeof(unsigned char));
	if (image->B == NULL) {
		free(image->G);
		free(image->R);
		free(image);
		return NULL;
	}

	return image;
}

/* Release the memory spaces for the RGB intensity values. */
/* Release the memory space for the RGB image. */
void DeleteImage(IMAGE *image)
{
	assert(image);
	assert(image->R);
	assert(image->G);
	assert(image->B);

	free(image->R);
	free(image->G);
	free(image->B);
	image->R = NULL;
	image->G = NULL;
	image->B = NULL;

	free(image);
}

/* Get the intensity value of the Y channel of pixel (x, y) */
/* in the YUV image */
unsigned char GetPixelY(const YUVIMAGE *YUVimage, unsigned int x, unsigned int y)
{
	assert(YUVimage);

	assert(x < YUVimage->W);
	assert(y < YUVimage->H);

	assert(YUVimage->Y);
	assert(YUVimage->U);
	assert(YUVimage->V);

	return YUVimage->Y[x + y * YUVimage->W];
}

/* Get the intensity value of the U channel of pixel (x, y) */
/* in the YUV image */
unsigned char GetPixelU(const YUVIMAGE *YUVimage, unsigned int x, unsigned int y)
{
	assert(YUVimage);

	assert(x < YUVimage->W);
	assert(y < YUVimage->H);

	assert(YUVimage->Y);
	assert(YUVimage->U);
	assert(YUVimage->V);

	return YUVimage->U[x + y * YUVimage->W];
}

/* Get the intensity value of the V channel of pixel (x, y) */
/* in the YUV image */
unsigned char GetPixelV(const YUVIMAGE *YUVimage, unsigned int x, unsigned int y)
{
	assert(YUVimage);

	assert(x < YUVimage->W);
	assert(y < YUVimage->H);

	assert(YUVimage->Y);
	assert(YUVimage->U);
	assert(YUVimage->V);

	return YUVimage->V[x + y * YUVimage->W];
}

/* Set the intensity value of the Y channel of pixel (x, y) */
/* in the YUV image with valueY */
void SetPixelY(YUVIMAGE *YUVimage, unsigned int x, unsigned int y,
               unsigned char valueY)
{
	assert(YUVimage);

	assert(x < YUVimage->W);
	assert(y < YUVimage->H);

	assert(YUVimage->Y);
	assert(YUVimage->U);
	assert(YUVimage->V);

	YUVimage->Y[x + y * YUVimage->W] = valueY;
}

/* Set the intensity value of the U channel of pixel (x, y) */
/* in the YUV image with valueU */
void SetPixelU(YUVIMAGE *YUVimage, unsigned int x, unsigned int y,
               unsigned char valueU)
{
	assert(YUVimage);

	assert(x < YUVimage->W);
	assert(y < YUVimage->H);

	assert(YUVimage->Y);
	assert(YUVimage->U);
	assert(YUVimage->V);

	YUVimage->U[x + y * YUVimage->W] = valueU;
}

/* Set the intensity value of the V channel of pixel (x, y) */
/* in the YUV image with valueV */
void SetPixelV(YUVIMAGE *YUVimage, unsigned int x, unsigned int y,
               unsigned char valueV)
{
	assert(YUVimage);

	assert(x < YUVimage->W);
	assert(y < YUVimage->H);

	assert(YUVimage->Y);
	assert(YUVimage->U);
	assert(YUVimage->V);

	YUVimage->V[x + y * YUVimage->W] = valueV;
}

/* Allocate the memory space for the YUV image and the memory spaces */
/* for the YUV intensity values. Return the pointer to the YUV image. */
YUVIMAGE *CreateYUVImage(unsigned int width, unsigned int height)
{
	YUVIMAGE *YUVimage = (YUVIMAGE *)malloc(sizeof(YUVIMAGE));
	if (YUVimage == NULL) {
		return NULL;
	}

	YUVimage->W = width;
	YUVimage->H = height;

	YUVimage->Y = (unsigned char*)malloc(width * height * sizeof(unsigned char));
	if (YUVimage->Y == NULL) {
		free(YUVimage);
		return NULL;
	}

	YUVimage->U = (unsigned char*)malloc(width * height * sizeof(unsigned char));
	if (YUVimage->U == NULL) {
		free(YUVimage->Y);
		free(YUVimage);
		return NULL;
	}

	YUVimage->V = (unsigned char*)malloc(width * height * sizeof(unsigned char));
	if (YUVimage->V == NULL) {
		free(YUVimage->U);
		free(YUVimage->Y);
		free(YUVimage);
		return NULL;
	}

	return YUVimage;
}

/* Release the memory spaces for the YUV intensity values. */
/* Release the memory space for the YUV image. */
void DeleteYUVImage(YUVIMAGE *YUVimage)
{
	assert(YUVimage);
	assert(YUVimage->Y);
	assert(YUVimage->U);
	assert(YUVimage->V);

	free(YUVimage->Y);
	free(YUVimage->U);
	free(YUVimage->V);
	YUVimage->Y = NULL;
	YUVimage->U = NULL;
	YUVimage->V = NULL;

	free(YUVimage);
}

unsigned int ImageWidth(IMAGE *image)
{
	// Assert
	assert(image);

	return image->W;
}

unsigned int ImageHeight(IMAGE *image)
{
	// Assert
	assert(image);

	return image->H;
}

IMAGE *CopyImage(const IMAGE *image)
{
	IMAGE *ret = CreateImage(image->W, image->H);

	for(unsigned int i = 0; i < image->W; i++)
	{
		for(unsigned int j = 0; j < image->H; j++)
		{
			SetPixelR(ret, i, j, GetPixelR(image, i, j));
			SetPixelG(ret, i, j, GetPixelG(image, i, j));
			SetPixelB(ret, i, j, GetPixelB(image, i, j));
		}
	}

	return ret;
}
/* EOF */
