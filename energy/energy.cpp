#include<iostream>
#include<cstdlib>
#include<ctime> 
#include<fstream>
using namespace std;

int saved_ae,saved_be,saved_h1,saved_h2;

int game4(int h1,int h2){
	int a=1,b,ae=0,be=0,n,flag=1;
	
	while(h1>0&&h2>0&&a){
		srand(time(0));
		b=rand()%7+2;
		n=rand()%4+1;
		if(b==2&&n==1)	b=1;
		cout<<"�����루1������  2��С�� 3������� 4��ը�� -1���˳� 9������ 10������ 11�����أ�\n";
		cin>>a;
		
		if(a==9){
			cout<<"��Ϸ����\n	С����1����\n	�������4����\n	ը����7����\n\n";
			cout<<"�����루1������  2��С�� 3������� 4��ը�� -1���˳� 9������ 10������ 11�����أ�\n";
			cin>>a;
		}
		if(a==10){
			cout<<"\n���Ժ󡭡�\n";
			saved_ae=ae;
			saved_be=be;
			saved_h1=h1;
			saved_h2=h2;
			cout<<"�����루1������  2��С�� 3������� 4��ը�� -1���˳� 9������ 10������ 11�����أ�\n";
			cin>>a;
		}
		if(a==11){
			ae=saved_ae;
			be=saved_be;
			h1=saved_h1;
			h2=saved_h2;
			cout<<"���Ѫ����"<<h1<<"    �������Ѫ����"<<h2<<"	����"<<ae<<"����	�������"<<be<<"������"<<endl<<endl<<"-------------------------------"<<endl<<endl; 
			cout<<"�����루1������  2��С�� 3������� 4��ը�� -1���˳� 9������ 10������ 11�����أ�\n";
			cin>>a;
		}
		if(a==-1){
			cout<<"\n������˳�-----";
			return 0;
		}
		
		switch(b){
			case 1:cout<<"���������1\n";be++;break;
			case 2:
			case 3:if(be>=1){
					cout<<"���������2\n";be--;b=2;break;	
				}
				else{
					cout<<"���������1\n";be++;b=1;break;
				};break;
			case 4:
			case 5:
			case 6:	if(be>=4){
					cout<<"���������3\n";be-=4;b=3;break;	
				}
				else{
					cout<<"���������1\n";be++;b=1;break;
				};break;
			case 7:
			case 8:if(be>=7){
					cout<<"���������4\n";be-=7;b=4;break;	
				}
				else{
					cout<<"���������1\n";be++;b=1;break;
				};	break;
		}
		switch(a){
			case 1:
				ae++;
				switch(b){
				case 2:cout<<"��-1��Ѫ!\n";h1-=1;break;
				case 3:cout<<"��-4��Ѫ!!\n";h1-=4;ae/=2;break;
				case 4:cout<<"��-7��Ѫ!!!\n";h1-=7;ae/=2;break;
				default:cout<<"ƽ��\n";break;
			}break; 
			case 2:
				if(ae>=1){
				ae--;
				switch(b){
				case 2:cout<<"ƽ��\n";break;
				case 3:cout<<"��-4��Ѫ!!\n";h1-=4;ae/=2;break;
				case 4:cout<<"��-7��Ѫ!!!\n";h1-=7;ae/=2;break;
				default:cout<<"�����-1��Ѫ\n";h2-=1;break;
				}}
				else{
					cout<<"�㷸��!��ֻ��"<<ae<<"������\n";
					h1--;
				}break; 
			case 3:if(ae>=4){
				ae-=4;
				switch(b){
				//case 2:cout<<"ƽ��\n";h1-=1;break;
				case 3:cout<<"ƽ��\n";break;
				case 4:cout<<"��-7��Ѫ!!!\n";h1-=7;ae/=2;break;
				default:cout<<"�����-4��Ѫ\n";h2-=4;be/=2;break;
				}}
				else{
					cout<<"�㷸��!��ֻ��"<<ae<<"������\n";
					h1--;
				}break; 
			case 4:if(ae>=7){
				ae-=7;
				switch(b){
				//case 2:cout<<"ƽ��\n";h1-=1;break;
				//case 3:cout<<"ƽ��\n";break;
				case 4:cout<<"�䣡\n";h1-=7;h2-=7;ae=be=0;break;
				default:cout<<"�����-7��Ѫ\n";h2-=7;be/=2;break;
				}}
				else{
					cout<<"�㷸��!��ֻ��"<<ae<<"������\n";
					h1--;
				}break; 
			default:cout<<"\n�ƺ��е�BUG����";return 0;
		}
		cout<<"���Ѫ����"<<h1<<"    �������Ѫ����"<<h2<<"	����"<<ae<<"����	�������"<<be<<"������"<<endl<<endl<<"-------------------------------"<<endl<<endl; 
		if(ae>8){
			cout<<"���Ա��ˣ�!";
			ae=0;
			h1=0;
		}
	}
	cout<<"��ʼ�Ծȣ�\n\n";
	h1+=ae;
	h1-=be/2;
	h2+=be;
	h2-=ae/2;
	cout<<"���Ѫ����"<<h1<<"    �������Ѫ����"<<h2<<endl<<endl; 
	
	if(h1>0&&h2>0){
		cout<<"�Ծȳɹ���\n\n---------------------------\n\n";
		flag=game4(h1,h2);
	}
	
	system("pause");
	system("cls");
	if(h2<=0&&h1>0)	{
		system("color 0a");
		cout<<"��ϲ�㣬��Ӯ�ˣ�\n--------------------------------\n";
		flag=0;
		}
	else if(h1<=0&&h2>0)	{
		system("color 0c");
		cout<<"�ܱ�Ǹ�������ˡ���û�ܳɹ��Ծȡ�\n";
		flag=0;}
	
	
	return flag;
	
	//return 0;
}
int mainE(){
	int i;
	system("cls");
	cout<<"��ӭ����������Ϸ\n�鿴��Ϸ����9����";
	cout<<"��Ϸ����\n	С����1����\n	�������4����\n	ը����7����\n\n";
	i=game4(10,10);
	if(i){
		system("color 0f");
		cout<<"��ƽ��";
	}
	return 0;
}
