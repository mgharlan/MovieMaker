/*********************************************************************/
/* Homework Assignment 5, for EECS 22, Fall 2017                     */
/*                                                                   */
/* Author: Mason Harlan                                              */
/* Date: 11/09/2017                                                  */
/*                                                                   */
/* MovieIO.c: source file for MOVIE input and output operations      */
/*                                                                   */
/*********************************************************************/

#include "MovieIO.h"
#include "Constants.h"

/* Load the movie frames from the input file */
MOVIE *LoadMovie(const char *fname, int frameNum,
                 unsigned int width, unsigned height)
{
	unsigned int i;
	MOVIE *movie = NULL;
	YUVIMAGE *YUVimage = NULL;

	movie = CreateMovie();
	if (movie == NULL) {
		return NULL;
	}

	for (i = 0; i < frameNum; i++) {
		YUVimage = LoadOneFrame(fname, i, width, height);
		if (YUVimage == NULL) {
			DeleteMovie(movie);
			return NULL;
		}

		AppendYUVImage(movie->Frames, YUVimage);
	}

	printf("The movie file %s has been read successfully!\n", fname);
	return movie;
}

/* Load one movie frame from the input file */
YUVIMAGE *LoadOneFrame(const char* fname, int n,
                       unsigned int width, unsigned height)
{
	FILE *file;
	unsigned int x, y;
	unsigned char c;
	YUVIMAGE* YUVimage;

	/* Check errors */
	assert(fname);
	assert(n >= 0);

	YUVimage = CreateYUVImage(width, height);
	if (YUVimage == NULL) {
		return NULL;
	}

	/* Open the input file */
	file = fopen(fname, "r");
	if (file == NULL) {
		DeleteYUVImage(YUVimage);
		return NULL;
	}

	/* Find the desired frame */
	fseek(file, 1.5 * n * width * height, SEEK_SET);

	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			c = fgetc(file);
			SetPixelY(YUVimage, x, y, c);
		} /*rof*/
	}

	for (y = 0; y < height; y += 2) {
		for (x = 0; x < width; x += 2) {
			c = fgetc(file);
			SetPixelU(YUVimage, x, y, c);
			SetPixelU(YUVimage, x + 1, y, c);
			SetPixelU(YUVimage, x, y + 1, c);
			SetPixelU(YUVimage, x + 1, y + 1, c);
		}
	}

	for (y = 0; y < height; y += 2) {
		for (x = 0; x < width; x += 2) {
			c = fgetc(file);
			SetPixelV(YUVimage, x, y, c);
			SetPixelV(YUVimage, x + 1, y, c);
			SetPixelV(YUVimage, x, y + 1, c);
			SetPixelV(YUVimage, x + 1, y + 1, c);
		}
	}

	/* Check errors */
	assert(ferror(file) == 0);

	/* Close the input file and return */
	fclose(file);
	file = NULL;
	return YUVimage;
}

/* Save the movie frames to the output file */
int SaveMovie(const char *fname, MOVIE *movie)
{
	unsigned int speedup;
	if(movie)
	{
		if(movie->Frames)
		{
			if(movie->Frames->First)
			{
				if(movie->Frames->First->YUVImage->W * movie->Frames->First->YUVImage->H * movie->Frames->length * 2 > MAXYUVSIZE * 2)
				{
					speedup = movie->Frames->First->YUVImage->W * movie->Frames->First->YUVImage->H * movie->Frames->length * 2 / (MAXYUVSIZE * 2);
					FastImageList(movie->Frames, speedup);
				}
			}
		}
	}

	int count;
	FILE *file;
	IENTRY *curr;

	/* Open the output file */
	file = fopen(fname, "w");
	if (file == NULL) {
		return 1;
	}

	count = 0;
	curr = movie->Frames->First;
	while (curr != NULL && movie->Frames->length > count) {

		SaveOneFrame(curr->YUVImage, fname, file);
		curr = curr->Next;
		count++;
	}

	fclose(file);
	file = NULL;

	printf("The movie file %s has been written successfully!\n", fname);
	printf("%d frames are written to the file %s in total.\n", count, fname);
	return 0;
}


/* Saves one movie frame to the output file */
void SaveOneFrame(YUVIMAGE *image, const char *fname, FILE *file)
{
        int x, y;
        for (y = 0; y < image->H; y++) {
                for (x = 0; x < image->W; x++) {
                        fputc(GetPixelY(image, x, y), file);
                }
        }

        for (y = 0; y < image->H; y += 2) {
                for (x = 0; x < image->W; x += 2) {
                        fputc(GetPixelU(image, x, y), file);
                }
        }

        for (y = 0; y < image->H; y += 2) {
                for (x = 0; x < image->W; x += 2) {
                        fputc(GetPixelV(image, x, y), file);
                }
        }
}
