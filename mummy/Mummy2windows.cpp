#include<iostream>
#include<string.h>
#include<vector>
#include<conio.h>
#include<windows.h>
#include<cstdlib>
#include<ctime>

using namespace std;

long long thief[9]={0,1,5,20,100,250,1000,10000000,7000000000},guard[9]={0,0,0,1,2,5,5,10,50};
long long life = 1,guard1,thief1,pyr;
long score = 0;

void print(char a[])
{
    int s=strlen(a);
    for(int i=0;i<s;i++)
    {
        cout<<a[i];
        Sleep(170);
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

void fight(){
	guard1 = guard[rand()%9];
	thief1 = thief[rand()%9];
	cout<<"修建金字塔\n";
	pyr = rand()%5;
	char in;
	while(life){
		Sleep(700);
		system("cls");
		if(guard1 < 0) guard1 = 0;
		cout<<"分数："<<score<<endl;
		cout<<"金字塔厚度："<<pyr<<endl;
		cout<<"侍卫：";printNum(guard1);cout<<"  盗墓贼：";printNum(thief1);cout<<endl;
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
			cout<<"1：召集侍卫	2：诅咒		3：杀	4：重来\n";
			in = getch();
			if(in == '1'){
				guard1 = guard1 + guard1/2 + 3;
				cout<<"多了一点人\n";
			} 
			else if(in == '2'){
				if(rand()%5 < 2){
					cout<<"诅咒生效\n";
					thief1/=5;
				}
				else cout<<"诅咒失败！\n";
			}
			else if(in == '3'){
				cout<<"开杀！！\n";
				while(thief1 > 0 && guard1 > 0){
					guard1--;
					thief1 -= 12;
				}
				pyr++;
			}
			else if(in == '4'){
				Sleep(1000);
				fight();
				return;
			}
			if(thief1 <= 0) continue;
		}
		else{
			while(thief1 > 0 && guard1 > 0){
				guard1--;
				thief1 -= 12;
			}
			if(thief1 <= 0) continue;
			Sleep(400);
			system("cls");
			system("color 0c");
			print("木乃伊已沦陷！");
			cout<<"最终分数："<<score<<endl;
			Sleep(1500);
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
	if((rand()%10 < 6) || smummy == 43){
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
	
	system("title 木乃伊第二版");
	print("龙家游戏公司出品：木乃伊（第二版）");
	game();
	return 0;
}
