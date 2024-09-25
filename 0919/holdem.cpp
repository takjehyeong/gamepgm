#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct trump
{
	int order;
	char shape[3];
	int number;
};

void make_card(trump m_card[]);
void display_card(trump m_card[]);
void shuffle_card(trump m_card[]);

int main()
{
 
	trump card[52];
	make_card(card);
	shuffle_card(card);
	display_card(card);
	return 0;
}

void make_card(trump m_card[])
{
	int i, j;
	char shape [4] [3] = {"♠", "◆", "♥", "♣"};
	for(i = 0; i < 4; i++)
	{
		for(j = i * 13; j < i * 13 + 13; j++)
		{
			m_card[j].order = i;
			strcpy(m_card[j].shape, shape[i]);
			m_card[j].number = j % 13 + 1;
			
			switch(m_card[j].number)
			{
				case 1 :
					m_card[j].number ='A';
					break;
				case 11 :
					m_card[j].number ='J';
					break;
				case 12 :
					m_card[j].number ='Q';
					break;
				case 13 :
					m_card[j].number ='K';
					break;
				/*case 14 :
					m_card[j].number = 'A';
					break;*/
				}
			}
		}
	}
	
void display_card(trump m_card[])
{
	printf("엔터를 눌러 핸디를 배정받으세요.\n");
	int i, count = 0;
	char hand, flop, river, turn;

	gets(&hand); //핸디 
	for(i = 0; i < 2; i++)
	{
		printf("%s", m_card[i].shape);
		if(10 < m_card[i].number)
			printf("% - 2c", m_card[i].number);
		else
			printf("% - 2d", m_card[i].number);
			count++;
		if(i % 13 + 1 == 13)
		{
			printf("\n");
			count = 0;
		}
	}
	printf("\n엔터를 눌러 플랍을 배정받으세요.\n", hand);
	
	gets(&flop); //플랍 
	for(i = 2; i < 5; i++)
	{
		printf("\n%s", m_card[i].shape);
		if(10 < m_card[i].number)
			printf("% - 2c", m_card[i].number);
		else
			printf("% - 2d", m_card[i].number);
			count++;
		if(i % 13 + 1 == 13)
		{
			printf("\n");
			count = 0;
		}
	}
	printf("\n엔터를 눌러 턴을 배정받으세요.\n", flop);
	
	gets(&river); //리버	
	for(i = 5; i < 6; i++)
	{

		
		printf("\n%s", m_card[i].shape);
		if(10 < m_card[i].number)
			printf("% - 2c", m_card[i].number);
		else
			printf("% - 2d", m_card[i].number);
			count++;
		if(i % 13 + 1 == 13)
		{
			printf("\n");
			count = 0;
		}
	}
	printf("\n엔터를 눌러 리버를 배정받으세요.\n", river);	
	
	gets(&turn);//턴 
	for(i = 6; i < 7; i++)
	{		
		printf("\n%s", m_card[i].shape);
		if(10 < m_card[i].number)
			printf("% - 2c", m_card[i].number);
		else
			printf("% - 2d", m_card[i].number);
			count++;
		if(i % 13 + 1 == 13)
		{
			printf("\n");
			count = 0;
		}
	}
}

void shuffle_card(trump m_card[])
{
	int i, rnd;
	trump temp;
	srand(time(NULL));
	for(i = 0; i < 52; i++)
	{
		rnd = rand() % 52;
		temp = m_card[rnd];
		m_card[rnd] = m_card[i];
		m_card[i] = temp;
	}
}
