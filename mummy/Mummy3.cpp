#include<iostream>
#include<string.h>
#include<vector>
#include<conio.h>
#include<windows.h>
#include<cstdlib>
#include<ctime>

using namespace std;

void prin2(char a[])
{
    int s=strlen(a);
    for(int i=0;i<s;i++)
    {
        cout<<a[i];
        Sleep(130);
    }
    getch(); 
    system("cls");
}

void printNum(long long n){
	if(n>1000000){
		cout<<(float)n/1000000.0<<"M";
	}
	else if(n>1000){
		cout<<(float)n/1000.0<<"k";
	}
	else cout<<n;
}

void fight1(){
	long long thief[9]={0,1,5,20,100,250,1000,10000000,7000000000},guard[9]={0,0,0,1,2,5,5,10,50};
	long long life = 1,guard1,thief1,pyr,strength;
	long score = 0;
	strength = 5;
	guard1 = guard[rand()%9];
	thief1 = thief[rand()%9];
	cout<<"�޽�������\n";
	pyr = rand()%5;
	char in;
	while(life){
		Sleep(700);
		system("cls");
		if(guard1 < 0) guard1 = 0;
		cout<<"������"<<score<<endl;
		cout<<"��������ȣ�"<<pyr<<endl;
		cout<<"��������ֵ��"<<strength<<endl;
		cout<<"������";printNum(guard1);cout<<"  ��Ĺ����";printNum(thief1);cout<<endl;
		if(thief1 <= 0){
			cout<<"��ϲ���ʤ����\n";
			Sleep(500);
			cout<<"��һ��������ʼ��";
			score += 200;
			pyr += 2;
			thief1 = thief[rand()%9];
			Sleep(500);
			system("cls");
			cout<<"������"<<score<<endl;
			cout<<"��������ȣ�"<<pyr<<endl;
			cout<<"��������ֵ��"<<strength<<endl;
			cout<<"������";printNum(guard1);cout<<"  ��Ĺ����";printNum(thief1);cout<<endl;
		}
		if(pyr){
			cout<<"������������һ�㣡\n";
			score += 10;
			if(thief1 >= 100000) score += 190;
			pyr--;
			cout<<"1���ټ�����	 2������    3��ѵ��	  4��ɱ   5������\n";
			in = getch();
			if(in == '1'){
				guard1 = guard1 + guard1/2 + 3;
				cout<<"����һ����\n";
			} 
			else if(in == '2'){
				if(rand()%5 < 2){
					cout<<"������Ч\n";
					thief1/=5;
					score += 10;
				}
				else cout<<"����ʧ�ܣ�\n";
			}
			else if(in == '4'){
				cout<<"��ɱ����\n";
				while(thief1 > 0 && guard1 > 0){
					guard1--;
					thief1 -= strength;
				}
				pyr++;
			}
			else if(in == '5'){
				score = 0;
				Sleep(1000);
				fight1();
				return;
			}
			else if(in == '3'){
				if(rand()%30 == 1) strength*=3; 
				else strength+=(rand()%3+1);
				cout<<"ѵ�����\n ";
			} 
			if(thief1 <= 0) continue;
		}
		else{
			while(thief1 > 0 && guard1 > 0){
				guard1--;
				thief1 -= strength;
			}
			if(thief1 <= 0) continue;
			Sleep(400);
			system("cls");
			system("color 0c");
			prin2("ľ���������ݣ�");
			cout<<"���շ�����"<<score<<endl;
			Sleep(1500);
			system("cls");
			prin2("GAME OVER��"); 
			Sleep(500);
			return;
		}
		Sleep(700);
		system("cls");
	}
}
void game3(){
	srand(time(NULL));
	prin2("�ڹŰ�������ǧ��ǰ�������ˣ���ѡ��һ��ľ������");
	int rmummy = rand()%5 + 1,smummy;
	cout<<"ѡһ��ľ����(1~5)\n";
	cin>>smummy;
	if(((rand()%10 < 6) && smummy < 6 && smummy > 0) || smummy == 74){
		cout<<"�����ľ������";
		Sleep(600);
		system("cls");
		fight1();
	}
	else{
		Sleep(300);
		system("cls");
		system("color 0c");
		prin2("������ľ������");
		prin2("�𻯣�");
		prin2("GAME OVER��"); 
		return;
	}
}

int mainMum(){
	
	system("title ľ����������");
	prin2("������Ϸ��˾��Ʒ��ľ�����������棩");
	game3();
	return 0;
}
