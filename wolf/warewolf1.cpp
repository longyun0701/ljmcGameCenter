#include<iostream>
#include<string>
#include<vector>
#include<conio.h>
#include<windows.h>
#include<cstdlib>
#include<ctime>
#include<set>

using namespace std;

void print(char a[])
{
    int s=strlen(a);
    for(int i=0;i<s;i++)
    {
        cout<<a[i];
        Sleep(80);
    }
    //getch(); 
    
}
class Player{
	public:
		bool alive;
		int type;
		int pre;
		void init1(int typ){
			type=typ;
			alive=1;
			pre=0;
		}
};
Player pls[7];

void game(){
	
	const int tp[4]={3,2,1,1};
	set<int> dead,alrd;
	int startt,endt;
	int ctp[4]={0,0,0,0};
	system("cls");
	for(int i=0;i<7;i++){
		int newt;
		while(1){
			newt=rand()%4;
			if(ctp[newt]<tp[newt]){
				ctp[newt]++;
				break;
			}
			
		}
		pls[i].init1(newt);
		
	}
	
	cout<<"����"<<pls[0].type<<" (0=ƽ��  1=����  2=Ԥ�Լ�  3=Ů��)\n";Sleep(1000); 
	do{
		system("cls");
		
		print("�������ۣ�");Sleep(400);cout<<endl;
		print("���������ۣ�");Sleep(400);cout<<endl;
		if(pls[0].type==1){
			cout<<"��������";
			for(set<int>::iterator i=alrd.begin();i!=alrd.end();i++){
				cout<<*i+1<<"�� ";
			}
			for(set<int>::iterator i=dead.begin();i!=dead.end();i++){
				cout<<*i+1<<"�� ";
			}
			cout<<endl;Sleep(300);
			cout<<"��Ҫɱ��˭�������ѣ�";
			for(int i=1;i<7;i++) if(pls[i].type==1) cout<<i+1;
			cout<<"��";
			int input;
			cin>>input;
			input--;
			dead.insert(input);
			for(int i=1;i<ctp[1];i++){
				int rnd = rand()%7;
				while(pls[rnd].alive == 0 || pls[rnd].type == 1) rnd = rand()%7;
				dead.insert(rnd);
			}
		}
		else{
			for(int i=0;i<ctp[1];i++){
				int rnd = rand()%7;
				while(pls[rnd].alive == 0 || pls[rnd].type == 1) rnd = rand()%7;
				dead.insert(rnd);
			}
		}
		Sleep(500);
		print("��������ۣ�");Sleep(400);cout<<endl;
		print("Ԥ�Լ������ۣ�");Sleep(400);cout<<endl;
		if(pls[0].type==2){
			cout<<"��ҪԤ��˭��";
			int input;
			cin>>input;
			input--;
			cout<<"���� "<<pls[input].type<<" (0=ƽ��,1=����,3=Ů��)\n";
			
		}
		else{
			int rnd=rand()%7;
			if(pls[rnd].type==1) pls[rnd].pre=1;
			else pls[rnd].pre=-1;
		}
		Sleep(500);
		print("Ԥ�Լ�����ۣ�");Sleep(400);cout<<endl;
		print("Ů�������ۣ�");Sleep(400);cout<<endl;
		if(pls[0].type==3){
			cout<<"��������";
			for(set<int>::iterator i=alrd.begin();i!=alrd.end();i++){
				cout<<*i+1<<"�� ";
			}
			for(set<int>::iterator i=dead.begin();i!=dead.end();i++){
				cout<<*i+1<<"�� ";
			}
			cout<<endl;Sleep(300);
			cout<<"��Ҫɱ�˻��Ǿ��ˣ�(ɱ��ѡ0������ѡ1)";
			int input;
			cin>>input;
			cout<<"��˭ʵ�У�";
			int in2;
			cin>>in2;
			in2--;
			if(input==0) dead.insert(in2);
			else dead.erase(in2);
		}
		else{
			for(int i=0;i<ctp[3];i++){
				int onp=rand()%7;
				if(rand()%2){
					while(pls[onp].alive==0) onp=rand()%7;
					dead.insert(onp);
				}
				
				else {
					while(pls[onp].alive==0) onp=rand()%7;
					dead.erase(onp);
				}
				
			}
		}
		Sleep(500);
		print("Ů������ۣ�");Sleep(600);cout<<endl;
		print("�����ˣ������ۣ�");Sleep(300);cout<<endl;
		cout<<"�������� "<<dead.size()<<" ���ˡ�\n";
		for(set<int>::iterator i=dead.begin();i!=dead.end();i++){
			pls[*i].alive=0;
			ctp[pls[*i].type]--;
			cout<<"Ϊ "<<*i+1<<" ��Ĭ����"<<endl; 
			alrd.insert(*i);
		}
		if(dead.find(0)!=dead.end()){
			print("\n�㲻��������\n");
			pls[0].type=0;
			
			//return 0;
		} 
		dead.clear();
		for(int i=1;i<7;i++){
			if(pls[i].alive==1){
				int rnd=rand()%7;
				endt = startt = time(0);
				while(pls[rnd].alive==0 || rnd==i ||(pls[i].type==1 && pls[rnd].type==1)){
					endt = time(0);
					rnd=rand()%7;
					if(endt - startt >= 3){
						cout<<"ERROR 0198:RUNTIME LIMITED\n";
						return;
					}
				}
				cout<<"����Ϊ "<<rnd+1<<" �������ˡ�\n";Sleep(300);
				pls[rnd].pre++;
			}
		}
		print("ͶƱ :\n");
		if(pls[0].alive){
			cout<<"��ҪͶ��˭��";
			int input;
			cin>>input;
			input--;
			pls[input].pre++;
		}
		cout<<endl;
		Sleep(500);
		print("���ս����");
		int wwpn,wwp=-1,same=0;;
		for(int i=0;i<7;i++){
			cout<<"\n"<<i+1<<"�ţ�"<<pls[i].pre<<"��"; 
			Sleep(100);
			if((pls[i].pre>wwp)){
				wwpn=i;wwp=pls[i].pre;
				same=0;
			}
			else if((pls[i].pre==wwp)){
				same=1;
			}
			pls[i].pre=0;
		}
		Sleep(200);
		if(same==0){
			cout<<"\n";
			cout<<wwpn+1;
			print("���ѱ�����\n");
			pls[wwpn].alive=0;
			ctp[pls[wwpn].type]--;
			alrd.insert(wwpn);
		}
		else if(same==1) print("\nƽ�֣�\n");
		print("��ʣ");cout<<ctp[1];print("�����ˣ�\n");
		if(wwpn==0){
			print("�㱻Ͷ���ˣ�");
			pls[0].type=0;
		}
		if(ctp[1]<=0){
			print("ƽ���ʤ��");
			return ;
		}
		if((ctp[0]+ctp[1]+ctp[2]) <= ctp[1] || ctp[0]<=0){
			print("���˻�ʤ��");
			return ;
		}
		
		Sleep(1000);
	}while(1);
}

int mainWolf(){
	srand(time(0));
	system("title ����ɱ");
	print("������Ϸ��˾��Ʒ������ɱ2018"); 
	getch();
	game(); 
	return 0;
}
