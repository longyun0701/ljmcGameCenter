#include<iostream>
#include<string.h>
#include<vector>
#include<conio.h>
#include<windows.h>
#include<cstdlib>
#include<ctime>

using namespace std;

void pri(char a[])
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

void printNum2(long long n){
	if(n>1000000){
		cout<<n/1000000<<"."<<(n%1000000+50)/100<<"M";
	}
	else if(n>1000){
		cout<<n/1000<<"."<<(n%1000+5)/10<<"k";
	}
	else cout<<n;
}

void fight3(){
	long long thief[9]={0,1,5,20,100,250,1000,50000,1000000},guard[9]={0,0,0,1,2,5,5,10,50};
	long long life = 1,guard1,thief1,pyr,strength,power,perc = 780;
	long score = 0;
	strength = 5;
	power = 10;
	int tl = 30;
	int lv = 0;
	guard1 = guard[rand()%9];
	thief1 = thief[rand()%9];
	cout<<"�޽�������\n";
	pyr = rand()%6+5;
	char in;
	while(life){
		Sleep(700);
		system("cls");
		if(guard1 < 0) guard1 = 0;
		cout<<"������"<<score<<endl;
		cout<<"��������ȣ�"<<pyr<<endl;
		cout<<"���ɽ��ȣ�"<<perc/10<<"."<<perc%10<<" %�� "<<tl<<" ���������\n";
		cout<<"��������ֵ��"<<strength<<endl;
		cout<<"������"<<power<<endl;
		cout<<"������";printNum2(guard1);cout<<"  ��Ĺ����";printNum2(thief1);cout<<endl;
		if(thief1 <= 0){
			cout<<"��ϲ���ʤ����\n";
			Sleep(500);
			cout<<"��һ��������ʼ��";
			score += 200;
			pyr += 2;
			lv++;
			thief1 = thief[rand()%9];
			Sleep(500);
			system("cls");
			cout<<"������"<<score<<endl;
			cout<<"��������ȣ�"<<pyr<<endl;
			cout<<"���ɽ��ȣ�"<<perc/10<<"."<<perc%10<<" %�� "<<tl<<" ���������\n";
			cout<<"��������ֵ��"<<strength<<endl;
			cout<<"������"<<power<<endl;
			cout<<"������";printNum2(guard1);cout<<"  ��Ĺ����";printNum2(thief1);cout<<endl;
		}
		tl--; 
		if(perc>=800){
			thief1 = 7000000000-guard1*10;
			cout<<"�ռ���ս��70����\n";Sleep(200);
			power = (1000-perc)/pyr;
			cout<<"��������Ϊ"<<power<<"\n";
		}
		if(pyr){
			cout<<"������������һ�㣡\n";
			score += 10;
			if(thief1 >= 100000) score += 190;
			pyr--;
			perc += power;
			cout<<"1���ټ�����	 2������    3��ѵ��	  4��ɱ   5������\n";
			in = getch();
			if(in == '1'){
				guard1 = guard1 + guard1/2*(power/8) + 3;
				cout<<"����һ����\n";
			} 
			else if(in == '2'){
				if(rand()%5 < 2){
					cout<<"������Ч\n";
					thief1/=(power/3);
					score += 10;
				}
				else cout<<"����ʧ�ܣ�\n";
				power-=(power/8);
			}
			else if(in == '4'){
				cout<<"��ɱ����\n";
				while(thief1 > 0 && guard1 > 0){
					guard1--;
					thief1 -= strength;
				}
				pyr++;
				perc -= power;
			}
			else if(in == '5'){
				score = 0;
				Sleep(1000);
				fight3();
				return;
			}
			else if(in == '3'){
				if(rand()%30 == 1) strength*=(power/5); 
				else strength+=(rand()%3+1);
				power = power+rand()%2+1;
				cout<<"ѵ�����\n ";
			} 
			if(thief1 <= 0) continue;
			if(time(0)%60 == 0){
				pri("ʱ����ʱ���̣�����������");
				power*=2;
			}
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
			pri("ľ���������ݣ�");
			cout<<"���շ�����"<<score<<endl;
			Sleep(1500);
			system("cls");
			pri("GAME OVER��"); 
			Sleep(500);
			return;
		}
		if(tl<=0){
			system("cls");
			system("color 0c");
			pri("ľ��������������ʧ�ܣ�");
			cout<<"���շ�����"<<score<<endl;
			Sleep(1500);
			system("cls");
			pri("GAME OVER��"); 
			Sleep(500);
			return;
		}
		if(perc >= 1000){
			system("cls");
			system("color 0a");
			pri("��ϲ�㣡����������������");
			cout<<"���շ�����"<<score<<endl;
			Sleep(1500);
			system("cls");
			pri("YOU LIVED��"); 
			Sleep(500);
			return;
		}
		Sleep(700);
		system("cls");
	}
}
void gam(){
	srand(time(NULL));
	pri("�ڹŰ�������ǧ��ǰ��������֮ǰ����ѡ��һ��ľ������");
	int rmummy = rand()%5 + 1,smummy;
	cout<<"ѡһ��ľ����(1~5)\n";
	cin>>smummy;
	if(((rand()%10 < 6) && smummy < 6 && smummy > 0) || smummy == 1327){
		cout<<"�����ľ������";
		Sleep(600);
		system("cls");
		fight3();
	}
	else{
		Sleep(300);
		system("cls");
		system("color 0c");
		pri("������ľ������");
		pri("�𻯣�");
		pri("GAME OVER��"); 
		return;
	}
}

int mainM(){
	
	system("title ľ�������ɰ�");
	pri("������Ϸ��˾��Ʒ��ľ���������ɰ棩");
	gam();
	return 0;
}
