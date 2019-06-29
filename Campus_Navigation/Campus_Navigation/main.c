#define _CRT_SECURE_NO_WARNINGS 1
#include "Campus_Navigation.h"
void Menue(){
	printf("__________________________\n");
	printf("欢迎来到西安科技大学！\n");
	printf("1:浏览校园景点\n" );
	printf("2:查看指定景点详细信息\n");
	printf("3:去往目的景点最短路径推荐\n");
	printf("4:增加新景点及路线\n");
	printf("5:删除景点及路线\n");
	printf("6:修改景点及路线\n");
	printf("0:退出\n");
	printf("请输入你的选择：\n");
}
int main(){
	MGraph G;
	volatile int quit = 0;
	int select = 0;
	InitInformation(&G);
	while (!quit){
		Menue();
		scanf("%d", &select);
		switch (select){
		case 1:
			Show(&G);
			break;
		case 2:
			View(&G);
			break;
		case 3:
			Recommd(&G);
			break;
		case 4:
			Add(&G);
			break;
		case 5:
			Delet(&G);
			break;
		case 6:
			Alter(&G);
			break;
		case 0:
			quit = 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}