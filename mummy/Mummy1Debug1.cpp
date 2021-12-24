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
	cout<<"修建金字塔\n";
	pyr = rand()%5;
	int in;
	while(life){
		Sleep(700);
		system("cls");
		if(guard1 < 0) guard1 = 0;
		cout<<"分数："<<score<<endl;
		cout<<"金字塔厚度："<<pyr<<endl;
		cout<<"侍卫："<<guard1<<"  盗墓贼："<<thief1<<endl;
		if(thief1 <= 0){
			cout<<"恭喜获得胜利！\n";
			Sleep(500);
			cout<<"下一波即将开始！";
			score += 200;
			pyr += 2;
			thief1 = thief[rand()%8];
			Sleep(500);
			system("cls");
			cout<<"分数："<<score<<endl;
			cout<<"金字塔厚度："<<pyr<<endl;
			cout<<"侍卫："<<guard1<<"  盗墓贼："<<thief1<<endl;
		}
		if(pyr){
			cout<<"金字塔被攻破一层！\n";
			score += 20;
			pyr--;
			cout<<"1：召集侍卫	2：诅咒\n";
			cin>>in;
			if(in == 1) guard1 = guard1 + guard1/2 + 3;
			else if(rand()%5 < 2){
				cout<<"诅咒生效\n";
				thief1/=3;
			}
			else cout<<"诅咒失败！\n";
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
			print("木乃伊已沦陷！");
			cout<<"最终分数："<<score<<endl;
			Sleep(2000);
			system("cls");
			print("GAME OVER！"); 
			Sleep(500);
			return;
		}
		Sleep(700);
		system("cls");
	}
}
void game(){
	srand(time(NULL));
	print("在古埃及，三千年前，你死了，并选了一个木乃伊。");
	int rmummy = rand()%5 + 1,smummy;
	cout<<"选一个木乃伊(1~5)\n";
	cin>>smummy;
	if(smummy==rmummy || smummy == 37){
		cout<<"规则的木乃伊！";
		Sleep(600);
		system("cls");
		fight();
	}
	else{
		Sleep(300);
		system("cls");
		system("color 0c");
		print("不规则木乃伊！");
		print("火化！");
		print("GAME OVER！"); 
		return;
	}
}

int main(){
	
	system("title 木乃伊第一版");
	print("龙家游戏公司出品：木乃伊（第一版）");
	game();
	return 0;
}
