#include <stdio.h>
#include<iostream>
#include<windows.h>

using namespace std;
 
char *measure_char[10]= {"��Ƽ����", "����", "ų�ι���", "��ġ", "��Ʈ"
		 ,"�ߵ�", "����", "��(ô)", "��", "��"};
char *weight_char[7] = {"�׷�", "ų�α׷�", "�Ŀ��", "�½�", "��"
		, "��", "��"}; //���� 
char *area_char[6] = {"������Ƽ����", "��������", "����ų�ι���", "��"
		, "�Ƹ�", "��Ÿ��"}; //���� 

void print_distance_unit(void); 
void print_weight_unit(void);//���� 
void print_area_unit(void);//���� 
 
void measure_calculate(int basic, int transe, double measure); 
void measure_weight(int basicWeight, int transeWeight, double measureWeight); //���� 
void measure_area(int basicArea, int transeArea, double measureArea);//���� 

double fahrenheitToCelsius(double fahrenheit) 
{
	return (fahrenheit - 32) * 5 / 9;
} 	//ȭ���� ������ ��ȯ
double celsiusToFahrenheit(double celsius) 
{
    return celsius * 9 / 5 + 32;
}	//������ ȭ���� ��ȯ 
int main(void)
{
	int choice;
	double value;
	 
	double measure;
	int basic, transe;
	
	double measureWeight;
	int basicWeight, transeWeight; //���� 
	
	double measureArea;
	int basicArea, transeArea; //���� 
	
	while (true) 
	{
        cout << "��ȯ�� �����ϼ���." << endl;
        cout << "1. ���� ��ȯ" << endl;
        cout << "2. �µ� ��ȯ" << endl;
        cout << "3. ���� ��ȯ" << endl;
        cout << "4. ���� ��ȯ" << endl;
        cout << "0. ���α׷� ����" << endl;
        cin >> choice;

        if (choice == 0) 
		{
            break;
        }
        if(choice == 1)//���� 
		{
			system("cls");
			printf("���̿� ���� ������ ȯ�� ���α׷�\n\n");
			print_distance_unit();
			printf("\n\n�⺻������ ��ȯ����\n�Է� �� Enter(��:1 5)>");
			if(scanf("%d %d",&basic,&transe) != 2 || 
		   		basic < 0 || basic > 9 || transe < 0 || transe > 9)
			{
				printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
				system("pause");
				system("cls");
				continue;
			} 						//�Է���ȿ���˻� 
			printf("���� �Է��ϰ� Enter>");
			scanf("%lf", &measure);
			printf("\n");
			measure_calculate(basic, transe, measure);
		}
		else if(choice == 2)//�µ� 
		{
			system("cls");
			printf("�µ���ȯ ���α׷�\n\n");
			cout << "��ȯ�� �µ��� �Է��ϼ��� (1: ȭ�� -> ����, 2: ���� -> ȭ��): ";
            cin >> choice;

            if (choice == 1)
			{
            	cout << "ȭ�� �µ��� �Է��ϼ���: ";
                cin >> value;
                cout << value << "��F�� " << fahrenheitToCelsius(value) << "��C�Դϴ�.\n\n" << endl;
            } 
			else if (choice == 2) 
			{
                cout << "���� �µ��� �Է��ϼ���: ";
                cin >> value;
                cout << value << "��C�� " << celsiusToFahrenheit(value) << "��F�Դϴ�.\n\n" << endl;
            } 
			else 
			{
                cout << "�߸��� �Է��Դϴ�.\n" << endl;
            }
            system("pause");
            system("cls");
        }
        else if(choice == 3)//���� 
        {
        	system("cls");
        	printf("���Ժ�ȯ ���α׷�\n\n");
			print_weight_unit();
			printf("\n\n�⺻������ ��ȯ����\n�Է� �� Enter(��:1 5)>");
			if(scanf("%d %d",&basicWeight,&transeWeight) != 2 || 
		   		basicWeight < 0 || basicWeight > 6 || transeWeight < 0 || transeWeight > 6)
			{
				printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
				system("pause");
				system("cls");
				continue;
			} 						//�Է���ȿ���˻�
			printf("���� �Է��ϰ� Enter>");
			scanf("%lf", &measureWeight);
			printf("\n");
			measure_weight(basicWeight, transeWeight, measureWeight);
		}
		else if(choice == 4)//���� 
		{
			system("cls");
			printf("������ȯ ���α׷�\n\n");
			print_area_unit();
			printf("\n\n�⺻������ ��ȯ����\n�Է� �� Enter(��:1 5)>");
			if(scanf("%d %d",&basicArea,&transeArea) != 2 || 
		   		basicArea < 0 || basicArea > 5 || transeArea < 0 || transeArea > 5)
			{
				printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
				system("pause");
				system("cls");
				continue;
			} 						//�Է���ȿ���˻�
			printf("���� �Է��ϰ� Enter>");
			scanf("%lf", &measureArea);
			printf("\n");
			measure_area(basicArea, transeArea, measureArea);
		}
		else 
		{
            cout << "�߸��� �����Դϴ�.\n" << endl;
            system("pause");
            system("cls");
        }
	}
	return 0;
}

void print_area_unit(void)//���� 
{
	int k;
	for(k = 0; k <= 5; k++)
	{
		printf("%d : %-8s ", k, area_char[k]);
		if(k % 3 == 2)printf("\n");
	}
}

void print_weight_unit(void)//���� 
{
	int j;
	for(j = 0; j <= 6; j++)
	{
		printf("%d : %-8s ", j, weight_char[j]);
		if(j % 3 == 2)printf("\n");
	}
}

void print_distance_unit(void)
{
	int i;
	for(i=0;i<=9;i++)
	{
		printf("%d:%-8s  ", i, measure_char[i]);
		if (i%3==2)
			printf("\n");
	}
}

void measure_calculate(int basic, int transe, double measure)
{
	//[�Լ� 11.4.1]�� ���� �κ� ����
	double msre[10], unit, result;

	msre[0]=392772;		//centimeter
	msre[1]=msre[0]/100.;	//meter
	msre[2]=msre[1]/1000.;	//kilometer
	msre[3]=msre[0]/2.54;	//inch
	msre[4]=msre[3]/12.;	//feet
	msre[5]=msre[4]/3.;	//yard 
	msre[6]=msre[5]/1760.;	//mile
	msre[7]=12960.;      	//��
	msre[8]=msre[7]/6.;   	//��
	msre[9]=msre[8]/(6.*36); //��

	unit=msre[basic];
	result=measure*(msre[transe]/unit);
	printf("%.2f %8s�� ", measure, measure_char[basic]);
	printf("%15.5f %8s\n\n", result, measure_char[transe]);
	system("pause");
	system("cls");
}

void measure_weight(int basicWeight, int transeWeight, double measureWeight)//���� 
{
	double msreWeight[7], unitWeight, resultWeight;
	
	msreWeight[0] = 1;	//�׷� 
	msreWeight[1] = msreWeight[0] / 1000.;	//ų�α׷� 
	msreWeight[2] = msreWeight[1] * 2.20462262;	//�Ŀ�� 
	msreWeight[3] = msreWeight[2] * 16.;	//�½� 
	msreWeight[4] = msreWeight[3] * 0.0472492;	//�� 
	msreWeight[5] = msreWeight[4] * 160.;	//�� 
	msreWeight[6] = msreWeight[1] / 1000;	//�� 
	
	unitWeight = msreWeight[basicWeight];
	resultWeight = measureWeight * (msreWeight[transeWeight] / unitWeight);
	printf("%.2f %8s�� ", measureWeight, weight_char[basicWeight]);
	printf("%15.8f %8s\n\n", resultWeight, weight_char[transeWeight]);
	system("pause");
	system("cls");
}

void measure_area(int basicArea, int transeArea, double measureArea) //����
{
	double msreArea[6], unitArea, resultArea;
	
	msreArea[0] = 1;	//������Ƽ���� 
	msreArea[1] = msreArea[0] / 10000.;	//�������� 
	msreArea[2] = msreArea[1] / 1000000.;	//����ų�ι��� 
	msreArea[3] = msreArea[2] * 302500.;	//�� 
	msreArea[4] = msreArea[3] / 30.25;	//�Ƹ� 
	msreArea[5] = msreArea[4] / 100.;	//��Ÿ�� 
	
	unitArea = msreArea[basicArea];
	resultArea = measureArea * (msreArea[transeArea] / unitArea);
	printf("%.2f %8s�� ", measureArea, area_char[basicArea]);
	printf("%15.8f %8s\n\n", resultArea, area_char[transeArea]);
	system("pause");
	system("cls");
}
