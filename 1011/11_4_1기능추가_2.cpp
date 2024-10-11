#include <stdio.h>
#include<iostream>
#include<windows.h>

using namespace std;
 
char *measure_char[10]= {"센티미터", "미터", "킬로미터", "인치", "피트"
		 ,"야드", "마일", "자(척)", "간", "리"};
char *weight_char[7] = {"그램", "킬로그램", "파운드", "온스", "근"
		, "돈", "톤"}; //무게 
char *area_char[6] = {"제곱센티미터", "제곱미터", "제곱킬로미터", "평"
		, "아르", "헥타르"}; //면적 

void print_distance_unit(void); 
void print_weight_unit(void);//무게 
void print_area_unit(void);//면적 
 
void measure_calculate(int basic, int transe, double measure); 
void measure_weight(int basicWeight, int transeWeight, double measureWeight); //무게 
void measure_area(int basicArea, int transeArea, double measureArea);//면적 

double fahrenheitToCelsius(double fahrenheit) 
{
	return (fahrenheit - 32) * 5 / 9;
} 	//화씨를 섭씨로 변환
double celsiusToFahrenheit(double celsius) 
{
    return celsius * 9 / 5 + 32;
}	//섭씨를 화씨로 변환 
int main(void)
{
	int choice;
	double value;
	 
	double measure;
	int basic, transe;
	
	double measureWeight;
	int basicWeight, transeWeight; //무게 
	
	double measureArea;
	int basicArea, transeArea; //면적 
	
	while (true) 
	{
        cout << "변환을 선택하세요." << endl;
        cout << "1. 길이 변환" << endl;
        cout << "2. 온도 변환" << endl;
        cout << "3. 무게 변환" << endl;
        cout << "4. 면적 변환" << endl;
        cout << "0. 프로그램 종료" << endl;
        cin >> choice;

        if (choice == 0) 
		{
            break;
        }
        if(choice == 1)//길이 
		{
			system("cls");
			printf("길이에 대한 도량형 환산 프로그램\n\n");
			print_distance_unit();
			printf("\n\n기본단위와 변환단위\n입력 후 Enter(예:1 5)>");
			if(scanf("%d %d",&basic,&transe) != 2 || 
		   		basic < 0 || basic > 9 || transe < 0 || transe > 9)
			{
				printf("잘못된 입력입니다. 다시 입력해주세요.\n");
				system("pause");
				system("cls");
				continue;
			} 						//입력유효성검사 
			printf("값을 입력하고 Enter>");
			scanf("%lf", &measure);
			printf("\n");
			measure_calculate(basic, transe, measure);
		}
		else if(choice == 2)//온도 
		{
			system("cls");
			printf("온도변환 프로그램\n\n");
			cout << "변환할 온도를 입력하세요 (1: 화씨 -> 섭씨, 2: 섭씨 -> 화씨): ";
            cin >> choice;

            if (choice == 1)
			{
            	cout << "화씨 온도를 입력하세요: ";
                cin >> value;
                cout << value << "°F는 " << fahrenheitToCelsius(value) << "°C입니다.\n\n" << endl;
            } 
			else if (choice == 2) 
			{
                cout << "섭씨 온도를 입력하세요: ";
                cin >> value;
                cout << value << "°C는 " << celsiusToFahrenheit(value) << "°F입니다.\n\n" << endl;
            } 
			else 
			{
                cout << "잘못된 입력입니다.\n" << endl;
            }
            system("pause");
            system("cls");
        }
        else if(choice == 3)//무게 
        {
        	system("cls");
        	printf("무게변환 프로그램\n\n");
			print_weight_unit();
			printf("\n\n기본단위와 변환단위\n입력 후 Enter(예:1 5)>");
			if(scanf("%d %d",&basicWeight,&transeWeight) != 2 || 
		   		basicWeight < 0 || basicWeight > 6 || transeWeight < 0 || transeWeight > 6)
			{
				printf("잘못된 입력입니다. 다시 입력해주세요.\n");
				system("pause");
				system("cls");
				continue;
			} 						//입력유효성검사
			printf("값을 입력하고 Enter>");
			scanf("%lf", &measureWeight);
			printf("\n");
			measure_weight(basicWeight, transeWeight, measureWeight);
		}
		else if(choice == 4)//면적 
		{
			system("cls");
			printf("면적변환 프로그램\n\n");
			print_area_unit();
			printf("\n\n기본단위와 변환단위\n입력 후 Enter(예:1 5)>");
			if(scanf("%d %d",&basicArea,&transeArea) != 2 || 
		   		basicArea < 0 || basicArea > 5 || transeArea < 0 || transeArea > 5)
			{
				printf("잘못된 입력입니다. 다시 입력해주세요.\n");
				system("pause");
				system("cls");
				continue;
			} 						//입력유효성검사
			printf("값을 입력하고 Enter>");
			scanf("%lf", &measureArea);
			printf("\n");
			measure_area(basicArea, transeArea, measureArea);
		}
		else 
		{
            cout << "잘못된 선택입니다.\n" << endl;
            system("pause");
            system("cls");
        }
	}
	return 0;
}

void print_area_unit(void)//면적 
{
	int k;
	for(k = 0; k <= 5; k++)
	{
		printf("%d : %-8s ", k, area_char[k]);
		if(k % 3 == 2)printf("\n");
	}
}

void print_weight_unit(void)//무게 
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
	//[함수 11.4.1]의 정의 부분 참고
	double msre[10], unit, result;

	msre[0]=392772;		//centimeter
	msre[1]=msre[0]/100.;	//meter
	msre[2]=msre[1]/1000.;	//kilometer
	msre[3]=msre[0]/2.54;	//inch
	msre[4]=msre[3]/12.;	//feet
	msre[5]=msre[4]/3.;	//yard 
	msre[6]=msre[5]/1760.;	//mile
	msre[7]=12960.;      	//자
	msre[8]=msre[7]/6.;   	//간
	msre[9]=msre[8]/(6.*36); //리

	unit=msre[basic];
	result=measure*(msre[transe]/unit);
	printf("%.2f %8s는 ", measure, measure_char[basic]);
	printf("%15.5f %8s\n\n", result, measure_char[transe]);
	system("pause");
	system("cls");
}

void measure_weight(int basicWeight, int transeWeight, double measureWeight)//무게 
{
	double msreWeight[7], unitWeight, resultWeight;
	
	msreWeight[0] = 1;	//그램 
	msreWeight[1] = msreWeight[0] / 1000.;	//킬로그램 
	msreWeight[2] = msreWeight[1] * 2.20462262;	//파운드 
	msreWeight[3] = msreWeight[2] * 16.;	//온스 
	msreWeight[4] = msreWeight[3] * 0.0472492;	//근 
	msreWeight[5] = msreWeight[4] * 160.;	//돈 
	msreWeight[6] = msreWeight[1] / 1000;	//톤 
	
	unitWeight = msreWeight[basicWeight];
	resultWeight = measureWeight * (msreWeight[transeWeight] / unitWeight);
	printf("%.2f %8s는 ", measureWeight, weight_char[basicWeight]);
	printf("%15.8f %8s\n\n", resultWeight, weight_char[transeWeight]);
	system("pause");
	system("cls");
}

void measure_area(int basicArea, int transeArea, double measureArea) //면적
{
	double msreArea[6], unitArea, resultArea;
	
	msreArea[0] = 1;	//제곱센티미터 
	msreArea[1] = msreArea[0] / 10000.;	//제곱미터 
	msreArea[2] = msreArea[1] / 1000000.;	//제곱킬로미터 
	msreArea[3] = msreArea[2] * 302500.;	//평 
	msreArea[4] = msreArea[3] / 30.25;	//아르 
	msreArea[5] = msreArea[4] / 100.;	//헥타르 
	
	unitArea = msreArea[basicArea];
	resultArea = measureArea * (msreArea[transeArea] / unitArea);
	printf("%.2f %8s는 ", measureArea, area_char[basicArea]);
	printf("%15.8f %8s\n\n", resultArea, area_char[transeArea]);
	system("pause");
	system("cls");
}
