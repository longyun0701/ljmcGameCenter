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
	
	cout<<"你是"<<pls[0].type<<" (0=平民  1=狼人  2=预言家  3=女巫)\n";Sleep(1000); 
	do{
		system("cls");
		
		print("天黑请闭眼！");Sleep(400);cout<<endl;
		print("狼人请睁眼！");Sleep(400);cout<<endl;
		if(pls[0].type==1){
			cout<<"黑名单：";
			for(set<int>::iterator i=alrd.begin();i!=alrd.end();i++){
				cout<<*i+1<<"号 ";
			}
			for(set<int>::iterator i=dead.begin();i!=dead.end();i++){
				cout<<*i+1<<"号 ";
			}
			cout<<endl;Sleep(300);
			cout<<"你要杀死谁？（队友：";
			for(int i=1;i<7;i++) if(pls[i].type==1) cout<<i+1;
			cout<<"）";
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
		print("狼人请闭眼！");Sleep(400);cout<<endl;
		print("预言家请睁眼！");Sleep(400);cout<<endl;
		if(pls[0].type==2){
			cout<<"你要预言谁？";
			int input;
			cin>>input;
			input--;
			cout<<"他是 "<<pls[input].type<<" (0=平民,1=狼人,3=女巫)\n";
			
		}
		else{
			int rnd=rand()%7;
			if(pls[rnd].type==1) pls[rnd].pre=1;
			else pls[rnd].pre=-1;
		}
		Sleep(500);
		print("预言家请闭眼！");Sleep(400);cout<<endl;
		print("女巫请睁眼！");Sleep(400);cout<<endl;
		if(pls[0].type==3){
			cout<<"黑名单：";
			for(set<int>::iterator i=alrd.begin();i!=alrd.end();i++){
				cout<<*i+1<<"号 ";
			}
			for(set<int>::iterator i=dead.begin();i!=dead.end();i++){
				cout<<*i+1<<"号 ";
			}
			cout<<endl;Sleep(300);
			cout<<"你要杀人还是救人？(杀人选0，救人选1)";
			int input;
			cin>>input;
			cout<<"对谁实行？";
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
		print("女巫请闭眼！");Sleep(600);cout<<endl;
		print("天亮了，请睁眼！");Sleep(300);cout<<endl;
		cout<<"昨晚死了 "<<dead.size()<<" 个人。\n";
		for(set<int>::iterator i=dead.begin();i!=dead.end();i++){
			pls[*i].alive=0;
			ctp[pls[*i].type]--;
			cout<<"为 "<<*i+1<<" 号默哀！"<<endl; 
			alrd.insert(*i);
		}
		if(dead.find(0)!=dead.end()){
			print("\n你不幸身亡！\n");
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
				cout<<"我认为 "<<rnd+1<<" 号是狼人。\n";Sleep(300);
				pls[rnd].pre++;
			}
		}
		print("投票 :\n");
		if(pls[0].alive){
			cout<<"你要投死谁：";
			int input;
			cin>>input;
			input--;
			pls[input].pre++;
		}
		cout<<endl;
		Sleep(500);
		print("最终结果：");
		int wwpn,wwp=-1,same=0;;
		for(int i=0;i<7;i++){
			cout<<"\n"<<i+1<<"号："<<pls[i].pre<<"分"; 
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
			print("号已被歼灭！\n");
			pls[wwpn].alive=0;
			ctp[pls[wwpn].type]--;
			alrd.insert(wwpn);
		}
		else if(same==1) print("\n平局！\n");
		print("还剩");cout<<ctp[1];print("个狼人！\n");
		if(wwpn==0){
			print("你被投死了！");
			pls[0].type=0;
		}
		if(ctp[1]<=0){
			print("平民获胜！");
			return ;
		}
		if((ctp[0]+ctp[1]+ctp[2]) <= ctp[1] || ctp[0]<=0){
			print("狼人获胜！");
			return ;
		}
		
		Sleep(1000);
	}while(1);
}

int mainWolf(){
	srand(time(0));
	system("title 狼人杀");
	print("龙家游戏公司出品：狼人杀2018"); 
	getch();
	game(); 
	return 0;
}
