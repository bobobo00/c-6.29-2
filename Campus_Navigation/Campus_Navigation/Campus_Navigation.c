#define _CRT_SECURE_NO_WARNINGS 1
#include "Campus_Navigation.h"
void CreateCampus(Mgraph_m  G){
	int i, j;
	printf("       ");
	for (i = 0; i < G->numvex; i++){
		printf("%s", G->vex[i].name);
		printf("    ");
	}
	printf("\n");
	printf("\n");
	for (i = 0; i < G->numvex; i++){
		printf("%s", G->vex[i].name);
		for (j = 0; j < G->numvex; j++){
			printf("  %5d   ", G->edge[i][j]);
		}
		printf("\n");
		printf("\n");
	}
}
Mgraph_m InitInformation(Mgraph_m  G){
	G->numvex = 12;
	G->numedge = 38;
	Spot sp[12] = { { "校门口", '1', "西安科技大学" }, { "图书馆", '2', "借阅、浏览图书" }, { "实验楼", '3', "科研活动中心" }, \
	{"超市  ", '4', "生活用品购买"}, { "榴馨苑", '5', "网红餐厅" }, { "综合楼", '6', "校医院、财务处" }, { "体育馆", '7', "体育活动中心" }, \
	{"美食街", '8', "更多美食选择"}, { "骊绣苑", '9', "大众餐厅" }, { "田径场", '10', "室外体育活动场地" }, { "篮球场", '11', "篮球运动活动中心" }, \
	{"游泳馆", '12', "游泳运动活动中心"} };
	Edge information[38] = { { 1, 2, 50 }, { 1, 3, 30 }, { 2, 1, 50 }, { 2, 5, 8 }, {4,5,8},\
	{ 2, 6, 5 }, { 2 ,7,13} ,{ 3, 1, 30 }, { 3, 7, 20 }, { 4, 8, 12 }, { 5, 2, 8 }, { 5, 4, 8 }, { 5, 8, 10 }, \
	{ 5, 9, 18 }, { 5, 6, 10 }, { 8, 4, 12 }, { 8 ,5, 10 }, {8, 9, 3 }, { 8, 11, 3 }, { 9, 6, 12 },\
	{ 9, 5, 18 }, { 9, 8, 3 }, {9,10,15}, { 6, 2, 5 }, { 6, 5, 10 }, { 6, 9, 12 }, { 6, 7, 6 }, \
	{ 7, 3, 20 }, { 7, 6, 6 }, { 7, 2, 13 }, {7,10,8},{ 10, 9, 15 }, { 10, 12, 40 }, { 10, 7, 8 }, { 12, 10, 40 }, \
	{ 12, 11, 30 }, { 11, 8, 3 }, {11,12,30} };
	Spot s;
	int i = 0;
	int j = 0;
	while (i < G->numvex){
		strcpy(s.name,sp[i].name);
		s.code=sp[i].code;
		strcpy(s.intro,sp[i].intro);
		G->vex[i] =s;
		i++;
	}
	for (i = 0; i < G->numvex; i++){
		for (j = 0; j < G->numvex; j++){
			if (i == j){
				G->edge[i][j] = 0;
			}
			else
			{
				G->edge[i][j] = NO;
			}
		}
	}
	int temp = 1;
	while (temp <= 12){
		for (i = 0; i < G->numedge; i++){
			for (j = 0; j < G->numedge; j++){
				if (information[j].begin == temp){
					G->edge[temp - 1][information[j].end - 1] = information[j].weight;
				}
			}
			temp++;
		}
	}
	return G;
}
void Show(Mgraph_m G){
	int i=0;
	printf("西安科技大学现有%d个景点,景点名称如下：\n", G->numvex);
	for (i = 0; i < G->numvex; i++){
		printf("%s  ", G->vex[i].name);
	}
	printf("\n");
	printf("请浏览详细校园导航图：\n");
	CreateCampus(G);
}
void View(Mgraph_m G){
	printf("请输入景点名称\n");
	char name[NAME_SIZE];
	scanf("%s", name);
	int i = 0;
	int j = 0;
	for (i = 0; i < G->numvex; i++){
		if (!(strcmp(name, G->vex[i].name))){
			printf("景点代号：%c\n", G->vex[i].code);
			printf("景点名称：%s\n", G->vex[i].name);
			printf("景点简介：%s\n", G->vex[i].intro);
			printf("此景点周边有下列景点，可以继续参观：\n");
			for (j = 0; j < G->numvex; j++){
				if(G->edge[i][j] != NO&&G->edge[i][j] != 0 && j < G->numvex){
					printf("%s,", G->vex[j].name);
				}
			}
			printf("\n");
		}
	}
}
void Recommd(Mgraph_m G){
	int code1=0;
	int code2=0;
	printf("请输入你所在景点代号：\n");
	scanf("%d", &code1);
	printf("请输入你的目的景点代号：\n");
	scanf("%d", &code2);
	ShortestPath_Floyd(G, code1, code2);
}
void ShortestPath_Floyd(Mgraph_m G, int num1, int num2){
	int  pathmatirx[MAX][MAX];
	int  shortpathtable[MAX][MAX];
	int v, w, k;
	for (v = 0; v < G->numvex; ++v){
		for (w = 0; w < G->numvex; ++w){
			shortpathtable[v][w] = G->edge[v][w];
			pathmatirx[v][w] = w;
		}
	}
	for (k = 0; k < G->numvex; ++k){
		for (v = 0; v < G->numvex; ++v){
			for (w = 0; w < G->numvex; ++w){
				if (shortpathtable[v][w]>shortpathtable[v][k] + shortpathtable[k][w]){
					shortpathtable[v][w] = shortpathtable[v][k] + shortpathtable[k][w];
					pathmatirx[v][w] = pathmatirx[v][k];
				}
			}
		}
	}
 printf("%d(%s)->%d(%s) 路径总长度为:%dkm\n", num1, G->vex[num1-1].name, num2, G->vex[num2-1].name, shortpathtable[num1 - 1][num2 - 1]);
  k = pathmatirx[num1-1][num2-1];
  printf("路径:%d(%s)", num1,G->vex[num1].name);
  while (k != num2-1){
	  printf("->%d(%s)", k + 1, G->vex[k].name);
	k = pathmatirx[k][num2-1];
	}
  printf("->%d(%s)\n", num2, G->vex[num2 - 1].name);
	printf("\n");	
}
void Alter(Mgraph_m G){
	char name1[NAME_SIZE];
	char name[NAME_SIZE];
	char intro1[INTRO_SIZE];
	int num = 0;
	int code = 0;
	int weight = 0;
	int temp = 0;
	int m = 0;
	printf("请输入要修改的景点名称：\n");
	scanf("%s", name);
	printf("请输入修改后的景点名称：\n");
	scanf(" %s", name1);
	printf("请输入修改后的景点名简介：\n");
	scanf(" %s", intro1);
	int i = 0;
	for (i = 0; i < G->numvex; i++){
		if (!(strcmp(G->vex[i].name,name))){
			temp = i;
			strcpy(G->vex[i].name, name1);
			strcpy(G->vex[i].intro,intro1);
			for (m = 0; m < G->numvex; m++){
				if (m == temp){
					G->edge[temp][m] = 0;
				}
				G->edge[temp][m] = NO;
			}
			for (m = 0; m< G->numvex; m++){
				if (m == temp){
					G->edge[m][temp] = 0;
				}
				G->edge[m][temp] = NO;
			}
		}
	}
	printf("请输入从修改后的景点出发共有多少条路径：\n");
	scanf("%d", &num);
	while (num != 0){
		printf("请输入可到达景点的代码及路径长度：\n");
		scanf("%d,%d", &code, &weight);
		G->edge[temp][code - 1] = weight;
		G->edge[code - 1][temp] = weight;
		num--;
	}
}
void Add(Mgraph_m G){
	char name1[NAME_SIZE];
	char intro1[INTRO_SIZE];
	int num = 0;
	int i = 0;
	int code = 0;
	int wieght = 0;
	int m = 0;
	printf("请输入增加的景点名称：\n");
	scanf("%s", name1);
	printf("请输入增加的景点简介：\n");
	scanf("%s", intro1);
	int temp = G->numvex;
	char code1 = G->numvex + '0';
	G->numvex++;
	strcpy(G->vex[temp].name, name1);
	strcpy(G->vex[temp].intro, intro1);
	G->vex[temp].code = G->numvex + '0';
	for (m = 0; m < G->numvex; m++){
		if (m == G->numvex - 1){
			G->edge[G->numvex - 1][m] = 0;
		}
		G->edge[G->numvex - 1][m] = NO;
	}
	for (m = 0; m< G->numvex; m++){
		if (m == G->numvex - 1){
			G->edge[m][G->numvex - 1] = 0;
		}
		G->edge[m][G->numvex - 1] = NO;
	}

	printf("请输入从增加的景点出发共有多少条路径：\n");
	scanf("%d", &num);
	while (num != 0){
		printf("请输入可到达景点的代码及路径长度：\n");
		scanf("%d,%d", &code, &wieght);
		G->edge[temp][code - 1] = wieght;
		G->edge[code-1][temp] = wieght;
		num--;
	}
}
void Delet(Mgraph_m G){
	unsigned char name1[NAME_SIZE];
	int i = 0;
	int temp = G->numvex - 1;
	int j = 0;
	printf("请输入要删除景点:\n");
	scanf("%s",&name1 );
	for (i = 0; i < G->numvex; i++){
		if (!(strcmp(G->vex[i].name, name1))){
			strcpy(G->vex[i].name, G->vex[temp].name);
			strcpy(G->vex[i].intro, G->vex[temp].intro);
			while (j < G->numvex){
				G->edge[i][j] = G->edge[temp][j];
				G->edge[j][i] = G->edge[j][temp];
				j++;
			}
		}
	}
	G->numvex=G->numvex-1;
}