#define _CRT_SECURE_NO_WARNINGS 1
#include "Campus_Navigation.h"
void Menue(){
	printf("__________________________\n");
	printf("��ӭ���������Ƽ���ѧ��\n");
	printf("1:���У԰����\n" );
	printf("2:�鿴ָ��������ϸ��Ϣ\n");
	printf("3:ȥ��Ŀ�ľ������·���Ƽ�\n");
	printf("4:�����¾��㼰·��\n");
	printf("5:ɾ�����㼰·��\n");
	printf("6:�޸ľ��㼰·��\n");
	printf("0:�˳�\n");
	printf("���������ѡ��\n");
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