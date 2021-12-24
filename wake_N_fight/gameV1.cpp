#include<iostream>
#include<string>
#include<vector>
#include<conio.h>
#include<windows.h>
#include<cstdlib>
#include<ctime>

using namespace std;

int p1b = 10,p2b = 10,p1p = 0,p2p = 1,p1g = 0,p2g = 0,p1dfnd = 0,p2dfnd = 0;//pos: 0：自己家(sleep)；1：别人家(sleep)；2~3：普通商店；4：大地堡。5~9: 外面；10:自己家，11：别人家。 

void prin3(char a[])
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
void fight(){
	int noGun = 0,flag1 = 0,flag2 = 0,input1,input2;
	while(p1p == p2p){
		cout<<"玩家1：1：逃 ； 2：杀\n";
		cin>>input1;
		if(input1 == 2){
			if(p1g > 0){
				p1g--;
				if(p2dfnd) p2dfnd--;
				else p2b--;
			}
			else if(!flag1){
				noGun++;
				flag1 = 1;
			}
		}
		else break;
		cout<<"玩家2：1：逃 ； 2：杀\n";
		cin>>input2;
		if(input2 == 2){
			if(p2g > 0){
				p2g--;
				if(p1dfnd) p1dfnd--;
				else p1b--;
			}
			else if(!flag2){
				noGun++;
				flag2 = 1;
			}
		}
		else break;
		cout<<"玩家1血量："<<p1b<<"\n玩家2血量："<<p2b<<endl;
		if(p1b <= 0){
			return;
		}
		if(p2b <= 0){
			return;
		}
		if(noGun >= 2) break;
	}
	cout<<"双方离开战场！\n";
	Sleep(1000);
	p1p = 10;
	p2p = 11;
	return;
}

void game2(){
	int gamemode = 1,input1,input2;
	int whoc;
	srand(time(NULL));
	while(gamemode == 1){
		system("cls");
		whoc = rand()%2;
		if(whoc){
			cout<<"玩家1出：\n";
			switch(p1p){
				case 0:{
					do{
						cout<<"1：起床\n";
						cin>>input1;
					}while(input1 != 1);
					p1p = 10;
					break;
				}
				case 10:{
					do{
						cout<<"1：出门 ； 2：继续睡 ； 3：翻抽屉\n";
						cin>>input1;
					}while(input1 < 1 || input1 > 3);
					switch(input1){
						case 1:{
							p1p = rand() % 5 + 5;
							break;
						}
						case 2:{
							p1p = 0;
							cout<<"ZZZZ!\n";
							break;
						}
						case 3:{
							cout<<"此功能暂未完成:(\n";
							break;
						}
					}
					break;
				}
				case 5:
				case 6:
				case 7:
				case 8:
				case 9:{
					do{
						cout<<"1：回家 ； 2：去商店1 ； 3：去商店2 ； 4：躲地堡 ； 5：去对方家\n";
						cin>>input1;
					}while(input1 < 1 || input1 > 5);
					switch(input1){
						case 1:{
							p1p = 10;
							break;
						}
						case 2:
						case 3:
						case 4:{
							p1p = input1;
							cout<<"进去了\n";
							break;
						}
						case 5:{
							p1p = 11;
							break;
						}
					}
					break;
				}
				case 11:{
					if((p1g )&& p2p == 1){
						cout<<"1：一阵扫射 ； 2：离开\n";
						cin>>input1;
						if(input1 == 1) {
							p2b -= (p1g * 2);
							p1g = 0;
						}
						else p1p = 6;
					}
					else p1p = 5;
					break;
				}
				case 2:
				case 3:{
					do{
						cout<<"1：离开 ； 2：AK47 ； 3：盾牌\n";
						cin>>input1;
					}while(input1 < 1 || input1 > 3);
					switch(input1){
						case 1:{
							p1p = rand() % 5 + 5;
							break;
						}
						case 2:{
							cout<<"购买成功\n"; 
							p1g = (p1g < 5) ? 5 : p1g + 2;
							cout<<"有"<<p1g<<"枚子弹\n";
							break;
						}
						case 3:{
							cout<<"购买成功\n"; 
							p1dfnd += 3;
							break;
						}
					}
					break;
				}
				case 4:{
					do{
						cout<<"1：离开 ； 2：继续躲\n";
						cin>>input1;
					}while(input1 < 1 || input1 > 2);
					if(input1 == 1) p1p = rand() % 5 + 5;
					break;
				}
			}
		}
		else{
			cout<<"玩家2出：\n";
			switch(p2p){
				case 1:{
					do{
						cout<<"1：起床\n";
						cin>>input2;
					}while(input2 != 1);
					p2p = 11;
					break;
				}
				case 11:{
					do{
						cout<<"1：出门 ； 2：继续睡 ； 3：翻抽屉\n";
						cin>>input2;
					}while(input2 < 1 || input2 > 3);
					switch(input2){
						case 1:{
							p2p = rand() % 5 + 5;
							break;
						}
						case 2:{
							p2p = 1;
							cout<<"ZZZZ!\n";
							break;
						}
						case 3:{
							cout<<"此功能暂未完成:(\n";
							break;
						}
					}
					break;
				}
				case 5:
				case 6:
				case 7:
				case 8:
				case 9:{
					do{
						cout<<"1：回家 ； 2：去商店1 ； 3：去商店2 ； 4：躲地堡 ； 5：去对方家\n";
						cin>>input2;
					}while(input2 < 1 || input2 > 5);
					switch(input2){
						case 1:{
							p2p = 11;
							break;
						}
						case 2:
						case 3:
						case 4:{
							p2p = input2;
							cout<<"进去了\n";
							break;
						}
						case 5:{
							p2p = 10;
							break;
						}
					}
					break;
				}
				case 10:{
					if((p2g) && p1p == 0){
						cout<<"1：一阵扫射 ； 2：离开\n";
						cin>>input2;
						if(input2 == 1) {
							p1b -= (p2g * 2);
							p2g = 0;
						}
						else p2p = 7;
					}
					else p2p = 8;
					break;
				}
				case 2:
				case 3:{
					do{
						cout<<"1：离开 ； 2：AK47 ； 3：盾牌\n";
						cin>>input2;
					}while(input2 < 1 || input2 > 3);
					switch(input2){
						case 1:{
							p2p = rand() % 5 + 5;
							break;
						}
						case 2:{
							cout<<"购买成功\n"; 
							p2g = (p2g < 5) ? 5 : p2g + 2;
							cout<<"有"<<p2g<<"枚子弹\n";
							break;
						}
						case 3:{
							cout<<"购买成功\n"; 
							p2dfnd += 3;
							break;
						}
					}
					break;
				}
				case 4:{
					do{
						cout<<"1：离开 ； 2：继续躲\n";
						cin>>input2;
					}while(input2 < 1 || input2 > 2);
					if(input2 == 1) p2p = rand() % 5 + 5;
					break;
				}
			}
			
		}
		if(p2p == p1p){
			cout<<"撞车了\n";
			fight();
		}
		Sleep(600);
		if(p2b <= 0 && p1b > 0) gamemode = 0;
		else if(p2b > 0 && p1b <= 0) gamemode = 2;
		else if(p2b <= 0 && p1b <= 0)gamemode = 3;
	}
	switch(gamemode){
		case 0:prin3("玩家2已阵亡！");prin3("玩家1获胜！");return;
		case 2:prin3("玩家1已阵亡！");prin3("玩家2获胜！");return;
		default:prin3("平局！");return;
	}
}

int mainWake(){
	system("title 起床战争");
	prin3("龙家游戏出品：起床战争第一版（双人）");
	game2();
	
	return 0;
}
