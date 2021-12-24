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
	cout<<"修建金字塔\n";
	pyr = rand()%6+5;
	char in;
	while(life){
		Sleep(700);
		system("cls");
		if(guard1 < 0) guard1 = 0;
		cout<<"分数："<<score<<endl;
		cout<<"金字塔厚度："<<pyr<<endl;
		cout<<"修仙进度："<<perc/10<<"."<<perc%10<<" %。 "<<tl<<" 天后死亡。\n";
		cout<<"侍卫武力值："<<strength<<endl;
		cout<<"功力："<<power<<endl;
		cout<<"侍卫：";printNum2(guard1);cout<<"  盗墓贼：";printNum2(thief1);cout<<endl;
		if(thief1 <= 0){
			cout<<"恭喜获得胜利！\n";
			Sleep(500);
			cout<<"下一波即将开始！";
			score += 200;
			pyr += 2;
			lv++;
			thief1 = thief[rand()%9];
			Sleep(500);
			system("cls");
			cout<<"分数："<<score<<endl;
			cout<<"金字塔厚度："<<pyr<<endl;
			cout<<"修仙进度："<<perc/10<<"."<<perc%10<<" %。 "<<tl<<" 天后死亡。\n";
			cout<<"侍卫武力值："<<strength<<endl;
			cout<<"功力："<<power<<endl;
			cout<<"侍卫：";printNum2(guard1);cout<<"  盗墓贼：";printNum2(thief1);cout<<endl;
		}
		tl--; 
		if(perc>=800){
			thief1 = 7000000000-guard1*10;
			cout<<"终极挑战：70亿人\n";Sleep(200);
			power = (1000-perc)/pyr;
			cout<<"功力晋升为"<<power<<"\n";
		}
		if(pyr){
			cout<<"金字塔被攻破一层！\n";
			score += 10;
			if(thief1 >= 100000) score += 190;
			pyr--;
			perc += power;
			cout<<"1：召集侍卫	 2：诅咒    3：训练	  4：杀   5：重来\n";
			in = getch();
			if(in == '1'){
				guard1 = guard1 + guard1/2*(power/8) + 3;
				cout<<"多了一点人\n";
			} 
			else if(in == '2'){
				if(rand()%5 < 2){
					cout<<"诅咒生效\n";
					thief1/=(power/3);
					score += 10;
				}
				else cout<<"诅咒失败！\n";
				power-=(power/8);
			}
			else if(in == '4'){
				cout<<"开杀！！\n";
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
				cout<<"训练完毕\n ";
			} 
			if(thief1 <= 0) continue;
			if(time(0)%60 == 0){
				pri("时逢午时三刻，功力翻倍！");
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
			pri("木乃伊已沦陷！");
			cout<<"最终分数："<<score<<endl;
			Sleep(1500);
			system("cls");
			pri("GAME OVER！"); 
			Sleep(500);
			return;
		}
		if(tl<=0){
			system("cls");
			system("color 0c");
			pri("木乃伊死亡！修仙失败！");
			cout<<"最终分数："<<score<<endl;
			Sleep(1500);
			system("cls");
			pri("GAME OVER！"); 
			Sleep(500);
			return;
		}
		if(perc >= 1000){
			system("cls");
			system("color 0a");
			pri("恭喜你！你获得了永生！！！");
			cout<<"最终分数："<<score<<endl;
			Sleep(1500);
			system("cls");
			pri("YOU LIVED！"); 
			Sleep(500);
			return;
		}
		Sleep(700);
		system("cls");
	}
}
void gam(){
	srand(time(NULL));
	pri("在古埃及，三千年前，在你死之前，你选了一个木乃伊。");
	int rmummy = rand()%5 + 1,smummy;
	cout<<"选一个木乃伊(1~5)\n";
	cin>>smummy;
	if(((rand()%10 < 6) && smummy < 6 && smummy > 0) || smummy == 1327){
		cout<<"规则的木乃伊！";
		Sleep(600);
		system("cls");
		fight3();
	}
	else{
		Sleep(300);
		system("cls");
		system("color 0c");
		pri("不规则木乃伊！");
		pri("火化！");
		pri("GAME OVER！"); 
		return;
	}
}

int mainM(){
	
	system("title 木乃伊修仙版");
	pri("龙家游戏公司出品：木乃伊（修仙版）");
	gam();
	return 0;
}
