/*********************************************************************/
/* Homework Assignment 5, for EECS 22, Fall 2017                     */
/*                                                                   */
/* Author: Tim Schmidt                                               */
/* Date: 11/09/2017                                                  */
/*                                                                   */
/* Image.h: header file for basic image manipulations                */
/*                                                                   */
/*********************************************************************/

#ifndef IMAGE_H
#define IMAGE_H

typedef struct {
	unsigned int W;       /* Image width */
	unsigned int H;       /* Image height */
	unsigned char *R;     /* Pointer to the memory storing */
	                      /* all the R intensity values */
	unsigned char *G;     /* Pointer to the memory storing */
	                      /* all the G intensity values */
	unsigned char *B;     /* Pointer to the memory storing */
	                      /* all the B intensity values */
} IMAGE;

/* Get the intensity value of the Red channel of pixel (x, y) */
/* in the RGB image */
unsigned char GetPixelR(const IMAGE *image, unsigned int x, unsigned int y);

/* Get the intensity value of the Green channel of pixel (x, y) */
/* in the RGB image */
unsigned char GetPixelG(const IMAGE *image, unsigned int x, unsigned int y);

/* Get the intensity value of the Blue channel of pixel (x, y) */
/* in the RGB image */
unsigned char GetPixelB(const IMAGE *image, unsigned int x, unsigned int y);

/* Set the intensity value of the Red channel of pixel (x, y) */
/* in the RGB image with valueR */
void SetPixelR(IMAGE *image, unsigned int x, unsigned int y,
               unsigned char valueR);

/* Set the intensity value of the Green channel of pixel (x, y) */
/* in the RGB image with valueG */
void SetPixelG(IMAGE *image, unsigned int x, unsigned int y,
               unsigned char valueG);

/* Set the intensity value of the Blue channel of pixel (x, y) */
/* in the RGB image with valueB */
void SetPixelB(IMAGE *image, unsigned int x, unsigned int y,
               unsigned char valueB);

/* Allocate the memory space for the RGB image and the memory spaces */
/* for the RGB intensity values. Return the pointer to the RGB image. */
IMAGE *CreateImage(unsigned int width, unsigned int height);

/* Release the memory spaces for the RGB intensity values. */
/* Release the memory space for the RGB image. */
void DeleteImage(IMAGE *image);

typedef struct {
	unsigned int W;       /* Image width */
	unsigned int H;       /* Image height */
	unsigned char *Y;     /* Pointer to the memory storing */
	                      /* all the Y intensity values */
	unsigned char *U;     /* Pointer to the memory storing */
	                      /* all the U intensity values */
	unsigned char *V;     /* Pointer to the memory storing */
	                      /* all the V intensity values */
} YUVIMAGE;

/* Get the intensity value of the Y channel of pixel (x, y) */
/* in the YUV image */
unsigned char GetPixelY(const YUVIMAGE *YUVimage, unsigned int x, unsigned int y);

/* Get the intensity value of the U channel of pixel (x, y) */
/* in the YUV image */
unsigned char GetPixelU(const YUVIMAGE *YUVimage, unsigned int x, unsigned int y);

/* Get the intensity value of the V channel of pixel (x, y) */
/* in the YUV image */
unsigned char GetPixelV(const YUVIMAGE *YUVimage, unsigned int x, unsigned int y);

/* Set the intensity value of the Y channel of pixel (x, y) */
/* in the YUV image with valueY */
void SetPixelY(YUVIMAGE *YUVimage, unsigned int x, unsigned int y,
               unsigned char valueY);

/* Set the intensity value of the U channel of pixel (x, y) */
/* in the YUV image with valueU */
void SetPixelU(YUVIMAGE *YUVimage, unsigned int x, unsigned int y,
               unsigned char valueU);

/* Set the intensity value of the V channel of pixel (x, y) */
/* in the YUV image with valueV */
void SetPixelV(YUVIMAGE *YUVimage, unsigned int x, unsigned int y,
               unsigned char valueV);

/* Allocate the memory space for the YUV image and the memory spaces */
/* for the YUV intensity values. Return the pointer to the YUV image. */
YUVIMAGE *CreateYUVImage(unsigned int width, unsigned int height);

/* Release the memory spaces for the YUV intensity values. */
/* Release the memory space for the YUV image. */
void DeleteYUVImage(YUVIMAGE *YUVimage);

unsigned int ImageWidth(IMAGE *image);

unsigned int ImageHeight(IMAGE *image);

IMAGE *CopyImage(const IMAGE *image);

#endif
