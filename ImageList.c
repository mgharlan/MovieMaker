/*********************************************************************/
/* Homework Assignment 5, for EECS 22, Fall 2017                     */
/*                                                                   */
/* Author: Mason Harlan                                              */
/* Date: 11/09/2017                                                  */
/*                                                                   */
/* ImageList.c: source file for image list manipulations             */
/*                                                                   */
/*********************************************************************/

#include <stdlib.h>
#include <assert.h>
#include "ImageList.h"

/* Create a new image entry */
IENTRY *CreateImageEntry(void)
{
	IENTRY *e;
	e = malloc(sizeof(IENTRY));
	if (! e){
		perror("Out of memory! Aborting...");
		exit(10);
	}
	e ->List = NULL;
	e ->Next = NULL;
	e ->Prev = NULL;
	e ->RGBImage = NULL;
	e ->YUVImage = NULL;
	return e;
}

/* Delete image entry (and image objects)*/
void DeleteImageEntry(IENTRY *entry)
{
	if(entry->RGBImage){
		DeleteImage(entry->RGBImage);				
		entry->RGBImage = NULL;
	}
	else{
		DeleteYUVImage(entry->YUVImage);
		entry->YUVImage = NULL;
	}
	entry->Next = NULL;
	entry->Prev = NULL;
	
	entry->List->length--;
	entry->List = NULL;
	assert(! entry->List);
	assert(! entry->Next);
	assert(! entry->Prev);
	assert(! entry->RGBImage);
	assert(! entry->YUVImage);
	free (entry);
}

/* Create a new image list */
ILIST *CreateImageList(void)
{
	ILIST *l;
	l = malloc(sizeof(ILIST));
	if (! l){
		perror("Out of memory! Aborting...");
		exit(10);
	}
	l->length = 0;
	l->First = NULL;
	l->Last = NULL;
	return l;
}	

/* Delete an image list (and all entries) */
void DeleteImageList(ILIST *list)
{
	IENTRY *e, *n;
	//IMAGE *i;
	assert(list);
	e = list->First;
	while(e){
		n = e-> Next;
		DeleteImageEntry(e);
		assert(e);
		//DeleteImage(i);
		e = n;
	}
	list-> First = NULL;
	list->Last = NULL;
	list->length = 0;
	free(list);
}

/* Insert a RGB image to the image list at the end */
void AppendRGBImage(ILIST *list, IMAGE *RGBimage)
{
	IENTRY *e = NULL;
	assert(list);
	assert(RGBimage);
	e = CreateImageEntry();
	e-> RGBImage = RGBimage;
	e->List = list;
	e-> YUVImage = NULL;
	if (list -> Last){
		e->Next = NULL;
		e->Prev = list->Last;
		list->Last->Next = e;
		list->Last = e;
	}
	else{
		e->Next = NULL;
		e->Prev = NULL;
		list->First = e;
		list->Last = e;
	}
	list->length++;		
}

/* Insert a YUV image to the image list at the end */
void AppendYUVImage(ILIST *list, YUVIMAGE *YUVimage)
{
	IENTRY *e = NULL;
	assert(list);
	assert(YUVimage);
	e = CreateImageEntry();
	e-> YUVImage = YUVimage;
	e->List = list;
	e-> RGBImage = NULL;
	if (list -> Last){
		e->Next = NULL;
		e->Prev = list->Last;
		list->Last->Next = e;
		list->Last = e;
	}
	else{
		e->Next = NULL;
		e->Prev = NULL;
		list->First = e;
		list->Last = e;
	}
	list->length++;		
}

/* Fast forward an image list */
void FastImageList(ILIST *list, unsigned int factor)
{
	unsigned int newFrameNum = 0;
	unsigned int counter = 0;
	IENTRY *curr = NULL; /* current entry in the list */
	IENTRY *prev = NULL; /* previous kept entry in the list */
	IENTRY *next = NULL; /* next entry in the list */

	assert(list);
	assert(factor > 0);

	curr = list->First;

	while (curr != NULL) {
		next = curr->Next;

		if (counter % factor == 0) {
			newFrameNum ++;

			curr->Prev = prev;
			if (prev != NULL) {
				prev->Next = curr;
			}
			prev = curr;
		} else {
			if (curr->RGBImage != NULL) {
				DeleteImage(curr->RGBImage);
			}

			if (curr->YUVImage != NULL) {
				DeleteYUVImage(curr->YUVImage);
			}

			curr->List = NULL;
			curr->Next = NULL;
			curr->Prev = NULL;
			curr->RGBImage = NULL;
			curr->YUVImage = NULL;
			free(curr);
		}

		curr = next;
		counter ++;
	}

	list->Last = prev;
	if (prev != NULL) {
		prev->Next = NULL;
	}
	list->length = newFrameNum;
}

/* Reverse an image list */
void ReverseImageList(ILIST *list)
{
	assert(list);
	if (list->length > 2){
		IENTRY *entry = NULL;
		IENTRY *e = NULL;//starts with first entry
		list->First->Prev = list->First->Next;
		list->First->Next = NULL;
		entry = list->First->Prev;
		//e = list->First;
		for (int i =0; i<list->length-1;i++){//handles rest of entries
			e = entry->Prev;
			entry->Prev = entry->Next;
			entry->Next = e;
			entry = entry->Prev;
		}
		IENTRY *f = list->First;
		list->First = list->Last;
		list->Last = f;
	}
	else{//switches first and last
		IENTRY *entry = NULL;
		entry = list->First;
		list->First = list-> Last;
		list->Last = entry;
		list->First->Next = list->Last;
		list->First->Prev = NULL;
		list->Last->Next = NULL;
		list->Last->Prev = list->First;
		
	}
}























/* EOF */
