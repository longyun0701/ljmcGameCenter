#include "wolf/warewolf1.cpp"
#include "wake_N_fight/gameV1.cpp"
#include "mummy/Mummy3.cpp"
#include "energy/energy.cpp"
#include "mummy/MummyFinal.cpp"

using namespace std;

void prinsl(char a[])
{
    int s=strlen(a);
    for(int i=0;i<s;i++)
    {
        switch(i%8){
        	case 0:system("color 01");break;
        	case 1:system("color 0b");break;
        	case 2:system("color 03");break;
        	case 3:system("color 0c");break;
        	case 4:system("color 05");break;
        	case 5:system("color 0e");break;
        	case 6:system("color 08");break;
        	case 7:system("color 0a");break;
		}
		cout<<a[i];
        Sleep(230);
    }
   // getch(); 
    //system("cls");
}

int main(){
	bool kpgng;
	while(1){
		system("color 07");
		system("cls");
		system("title LJMC Game Center v1.2.3");
		prinsl("龙家游戏公司出品：命令行游戏中心ｖ１．２．３（ｃ）２０２１\n\n1：起床战争\n2：狼人杀\n3：木乃伊原版\n4：能量\n5：木乃伊修仙版\n"); 
		char a;
		system("color 07");
		a = getch();
		do{
			system("color 07");
			system("cls");
			switch(a){
				case '1':mainWake();break;
				case '2':mainWolf();break;
				case '3':mainMum();break;
				case '4':mainE();break;
				case '5':mainM();break;
				default:print("退出游戏！\n本游戏由龙星界银行赞助\n");return 0;
			}
			Sleep(1000);
			system("cls");
			cout<<"是否重新开始？（0否，1是）\n";
			cin>>kpgng;
			system("cls");
		}while(kpgng);
	}
	return 0;	
}
