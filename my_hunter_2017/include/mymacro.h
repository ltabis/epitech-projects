/*
** EPITECH PROJECT, 2017
** mylist.h
** File description:
** list for day13
*/
#ifndef MYLIST_H_
#define MYLIST_H_

#define WIDTH  1280
#define HEIGHT 720

typedef struct framebuffer {
        int width;
	int height;
	sfUint8 *pixelArray;
} framebuffer_t;

#endif /* !MYLIST_H_ */
