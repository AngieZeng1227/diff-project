//
//  para.h
//  diff
//
//  Created by William McCarthy on 5/9/19.
//  Copyright © 2019 William McCarthy. All rights reserved.
//

#ifndef para_h
#define para_h

#include <stdio.h>

#define ARGC_ERROR 1
#define TOOMANYFILES_ERROR 2
#define CONFLICTING_OUTPUT_OPTIONS 3

#define MAXSTRINGS 1024
#define MAXPARAS 4096

#define HASHLEN 200


typedef struct para para;
struct para {
  char** base;
  int filesize;
  int start;
  int stop;
  char* firstline;   // DEBUG only
  char* secondline;
};

para* para_make(char* base[], int size, int start, int stop);
para* para_first(char* base[], int size);
para* para_next(para* p);
size_t para_filesize(para* p);
size_t para_size(para* p);
char** para_base(para* p);
char* para_info(para* p);
int   para_equal(para* p, para* q);
void para_print(para* p, void (*fp)(const char*));
void para_printfile(char* base[], int count, void (*fp)(const char*));

void para_printboth(para* p, para* q, void (*fp)(const char*, const char*));

#define BUFLEN 256

char* yesorno(int condition);
FILE* openfile(const char* filename, const char* openflags);

void printleft(const char* left);
void printright(const char* right);
void printboth(const char* left, const char* right);

void printline(void);
void search(para* p, para* q);
//
int para_same(void);
void reportiden(para *p, para* q);
void filetime(void);
void briefmode(para* p, para* q) ;

#endif /* para_h */
