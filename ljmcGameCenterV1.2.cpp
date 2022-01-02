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
		prinsl("������Ϸ��˾��Ʒ����������Ϸ���ģ��������������㣩��������\n\n1����ս��\n2������ɱ\n3��ľ����ԭ��\n4������\n5��ľ�������ɰ�\n"); 
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
				default:print("�˳���Ϸ��\n����Ϸ�����ǽ���������\n");return 0;
			}
			Sleep(1000);
			system("cls");
			cout<<"�Ƿ����¿�ʼ����0��1�ǣ�\n";
			cin>>kpgng;
			system("cls");
		}while(kpgng);
	}
	return 0;	
}
