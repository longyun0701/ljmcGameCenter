#include<iostream>
#include<string>
#include<vector>
#include<conio.h>
#include<windows.h>
#include<cstdlib>
#include<ctime>

using namespace std;

int thief[8]={1,5,20,100,250,1000,10000000,7000000000},guard[9]={0,0,0,1,2,5,5,10,50};
int life = 1,guard1,thief1,pyr;
long score = 0;

void print(char a[])
{
    int s=strlen(a);
    for(int i=0;i<s;i++)
    {
        cout<<a[i];
        Sleep(200);
    }
    getch(); 
    system("cls");
}
void fight(){
	guard1 = guard[rand()%9];
	thief1 = thief[rand()%8];
	cout<<"�޽�������\n";
	pyr = rand()%5;
	int in;
	while(life){
		Sleep(700);
		system("cls");
		if(guard1 < 0) guard1 = 0;
		cout<<"������"<<score<<endl;
		cout<<"��������ȣ�"<<pyr<<endl;
		cout<<"������"<<guard1<<"  ��Ĺ����"<<thief1<<endl;
		if(thief1 <= 0){
			cout<<"��ϲ���ʤ����\n";
			Sleep(500);
			cout<<"��һ��������ʼ��";
			score += 200;
			pyr += 2;
			thief1 = thief[rand()%8];
			Sleep(500);
			system("cls");
			cout<<"������"<<score<<endl;
			cout<<"��������ȣ�"<<pyr<<endl;
			cout<<"������"<<guard1<<"  ��Ĺ����"<<thief1<<endl;
		}
		if(pyr){
			cout<<"������������һ�㣡\n";
			score += 20;
			pyr--;
			cout<<"1���ټ�����	2������\n";
			cin>>in;
			if(in == 1) guard1 = guard1 + guard1/2 + 3;
			else if(rand()%5 < 2){
				cout<<"������Ч\n";
				thief1/=3;
			}
			else cout<<"����ʧ�ܣ�\n";
			while(thief1 > 0 && guard1 > 0){
				guard1--;
				thief1 -= 10;
			}
			if(thief1 <= 0) continue;
		}
		else{
			thief1 -= (guard1 * 10);
			guard1 = (0-thief1) / 10;
			if(thief1 <= 0) continue;
			Sleep(400);
			system("cls");
			system("color 0c");
			print("ľ���������ݣ�");
			cout<<"���շ�����"<<score<<endl;
			Sleep(2000);
			system("cls");
			print("GAME OVER��"); 
			Sleep(500);
			return;
		}
		Sleep(700);
		system("cls");
	}
}
void game(){
	srand(time(NULL));
	print("�ڹŰ�������ǧ��ǰ�������ˣ���ѡ��һ��ľ������");
	int rmummy = rand()%5 + 1,smummy;
	cout<<"ѡһ��ľ����(1~5)\n";
	cin>>smummy;
	if(smummy==rmummy || smummy == 37){
		cout<<"�����ľ������";
		Sleep(600);
		system("cls");
		fight();
	}
	else{
		Sleep(300);
		system("cls");
		system("color 0c");
		print("������ľ������");
		print("�𻯣�");
		print("GAME OVER��"); 
		return;
	}
}

int main(){
	
	system("title ľ������һ��");
	print("������Ϸ��˾��Ʒ��ľ��������һ�棩");
	game();
	return 0;
}
