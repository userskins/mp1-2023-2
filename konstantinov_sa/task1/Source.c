#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <locale.h>
//��������� ���������� � ��/�^2
#define P_DVP_5MM (600.0f * 0.005f)
#define P_DSP_15MM (700.0f * 0.015f)
#define P_WOOD_1CM (550.0f * 0.01f)
//������ ����� :
//��������� ������ ������ �� ��� ������� h �� 180 �� 220 ��, ������� w �� 80 �� 120 �� � �������� 5 ��,
//��� �������� �� ��� ������� h, �������� d �� 50 �� 90 �� � �������� 15 ��,
//��������� ������� � ������ ������ �� ��� ������� w, �������� d � �������� 15 ��,
//��� ��������� ����� �� ������ ������� h, ����� ������� w � �������� 1 ��,
//���������� ����� � ����� ����� ������ 40 �� �� ���.
//������, ��� �������� ��������� ���, ��� � ������, ����� ����� ����� � �����������.
//��������� ������������

//���� ������������� ����� � ����������� � �������������, ����� � ������ float
float validatedInput(int l, int r, const char* msg) { 
	int check, v = -1;
	char ch;
	do {
		printf("������� %s � �� � ��������� �� %d �� %d\n", msg, l, r);
		check = scanf("%d", &v);
		if (check != 1) {
			printf("�������� ������ ������!\n");
			while (ch = getchar() != '\n');
		}
		if (!((v >= l) && (v <= r))) {
			check = 0;
			printf("�������� ��� ���������!\n");
		}		
	} while (check != 1);

	return (float)v /100.0f;
}

int main() {
	setlocale(LC_ALL, "");
	float h,w,d;
	h = validatedInput(180, 220, "������");
	w = validatedInput(80, 120, "������");
	d = validatedInput(50, 90, "�������");

	//����� �������� 15�� + ����� 40�� = 415 �� ������ �� ���� �����
	int shelf_count = (int)(h * 1000.0f)/415; //������������� �������
	//����� ����� ���������� ��������� �� �� �������
	float shelf_w = w - 2.0f * 0.015f; 
	//������ ������, �������� � ������, �����, �����
	float mass = P_DVP_5MM * (w * h) + P_DSP_15MM * (h * d * 2.0f + w * d * 2.0f) + P_WOOD_1CM * (w * h) + P_DSP_15MM * (shelf_w * d) * shelf_count;
	printf("��� ����� %.3f��\n", mass); //����� � ����� ������� ����� �������
	system("pause");
}