#ifndef Campus_Navigation_H_
#define Campus_Navigation_H_

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define NAME_SIZE 16
#define INTRO_SIZE 32
#define CODE_SIZE 8
#define MAX 20
#define NO 11111

typedef struct Spot{
	unsigned char name[NAME_SIZE];
	unsigned char code;
	unsigned char intro[INTRO_SIZE];
}Spot,*Spot_t;

typedef struct{
	unsigned int begin;
	unsigned int end;
	int weight;
}Edge;
typedef struct MGraph{
	int numvex;
	int numedge;
	Spot vex[MAX];
	int edge[MAX][MAX];
}MGraph,*Mgraph_m;


void CreateCampus(Mgraph_m G);
void Show(Mgraph_m G);
void View(Mgraph_m G);
void Recommd(Mgraph_m G);
Mgraph_m InitInformation(Mgraph_m G);
void ShortestPath_Floyd(Mgraph_m G, int num1, int num2);
void Alter(Mgraph_m G);
void Add(Mgraph_m G);
void Delet(Mgraph_m G);


#endif