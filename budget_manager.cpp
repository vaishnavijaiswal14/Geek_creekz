/*A budget manager to categorise your expenditures in a month and assigning 
limits to them along with some money in security and the rest in savings(that 
can't be easily accessed),as well generating an error message when limit exceeds*/
#include<iostream>
using namespace std;
class account 
{
	long long int acno;
	char fname[30];
	char lname[30];
	public:
		void getdetails()
		{
			cout<<"Enter your 12 digit account no.";
			cin>>acno;
			cout<<"\nEnter your first name";
			cin>>fname;
			cout<<"\nEnter your last name";
			cin>>lname;
		}
		void putdetails()
		{
			cout<<"\n Account no."<<acno;
			cout<<"\n Name:"<<fname<<" "<<lname;
		}
};
class item:public account
{
	char itemnme[30];
	int d;
	int m;
	int y;
	public:
		void getdata()
		{
			cout<<"\nenter item name purchased(use'_'for space)";
			cin>>itemnme;
			cout<<"\nEnter date";
			cin>>d;
			cout<<"\nEnter month( asjanuary=1)";
			cin>>m;
			cout<<"\nEnter year";
			cin>>y;
		}
		void putdata()
		{
			cout<<"\nItem Name\tDate";
			cout<<"\n"<<itemnme;
			cout<<"\t"<<d<<"/"<<m<<"/"<<y;
		}
};
void limitcheck(float f,float s,float r,float t,float g);
int main()
{
	account a;
	a.getdetails();
	a.putdetails();
	item it;
	int ch,c,n;
	float mny,sec,bal;
	float food,stat,tr,rec,gift;
	float f=45,s=20,t=10,r=15,g=5,sav;//food=45,stat=20,tr=10,bill=15,gift=5;
	cout<<"\nEnter your Monthly Budget Rs.";
	cin>>mny;
	bal=mny;
	cout<<"\nEnter your security Money Rs.";
	cin>>sec;
	sec+=.05*mny;
	bal-=sec;
	do
	{
	cout<<"\nEnter your %limits for following categories(*for default choose 6)\n1.Food\t2.Stationary\t3.Recharge&bills\n4.Travel&transport\t5.Gifts\t6.Display limits\n7.NEXT";
	cin>>c;
	switch(c)
	{
		case 1:
			cout<<"\nEnter limit for food:";
			cin>>f;limitcheck(f,s,r,t,g);break;
		case 2:
			cout<<"\nEnter limit for stationary";
			cin>>s;limitcheck(f,s,r,t,g);break;
		case 3:
			cout<<"\nEnter limit for Recharge and bills";
			cin>>r;limitcheck(f,s,r,t,g);break;
		case 4:
			cout<<"\nEnter limit for travel";
			cin>>t;limitcheck(f,s,r,t,g);break;
		case 5:
			cout<<"\nEnter limit for gifts";
			cin>>g;limitcheck(f,s,r,t,g);break;
		case 6:
			cout<<"\nLimit for food:"<<f<<"%\tStationary:"<<s<<"%\tRecharge&bills:"<<r<<"%\tTravel:"<<t<<"%\tGifts:"<<g<<"%";break;
		case 7:
			food=(f*mny)/100;stat=(s*mny)/100;rec=(r*mny)/100;tr=(t*mny)/100;gift=(g*mny)/100;
			cout<<"\nYour limits are assigned.";cout<<"Limit for food:Rs."<<food<<"\tStationary:Rs."<<stat<<"\tRecharge&bills:Rs."<<rec<<"\nTravel:Rs."<<tr<<"\tGifts:Rs."<<gift;break;
		default:
			cout<<"\nInvalid choice";
			break;	
	}
	}while(c!=7);
	sav=mny-(food+stat+rec+tr+gift);
	cout<<"\n We have added 5% of your monthly budget in Security and the rest in savings";
	cout<<"\nSAVINGs:Rs."<<sav<<"\tSECURITY:Rs."<<sec;
	cout<<"\nDid you purchase an item \n1.Yes\n2.No";
    cin>>n;
    while(n==1)
    {	
    	do
    	{
    		int cost;
    		cout<<"\n\nBALANCE:"<<bal;
    	    cout<<"\nEnter your category of expense\n1.Medical(Security)\t2.Recharge and bills\t3.Travelling\t4.Food\t5.Gifts\t6.no further purchase\n Enter your choice";
		    cin>>ch;
			if(ch!=6)
			{
			it.getdata();
		    cout<<"\nEnter its cost";
		    cin>>cost;
			}		    
		    switch(ch)
		    {	
		    case 1:
		    	
				if((cost>sec)||(sec<=0.0))
				{	int chi;
					cout<<"YOUR LIMIT FOR SECURITY MONEY IS EXCEEDED";
					if((sav!=0)&&(cost<=sav))
					{
						cout<<"Do you want to take from savings?\t1.YES\t2.NO";
						cin>>chi;
						if(chi==1)
						{
							sav-=cost;
							bal-=cost;
							it.putdata();
							cout<<"Left SAVINGS:Rs."<<sav;
						}
			            else
			            cout<<"HAPPY SAVINGs!!";
					}
					else
					cout<<"\nPAISA NAHI HAI!!";
				}
				else
				{
					sec-=cost;
					bal-=cost;
					it.putdata();
					cout<<"\nLeft SECURITY Rs."<<sec;	
				}
				break;
		    case 2:if((cost>rec)||(rec<=0.0))
				{	int chi;
					cout<<"YOUR LIMIT IN BILLS AND RECHARGE  IS EXCEEDED";
					if((sav!=0)&&(cost<=sav))
					{
						cout<<"Do you want to take from savings?\t1.YES\t2.NO";
						cin>>chi;
						if(chi==1)
						{
							sav-=cost;
							bal-=cost;
							it.putdata();
							cout<<"Left SAVINGS:Rs."<<sav;
						}
			            else
			            {
			            	int op;
			            	cout<<"Do You want to take from Security\t1.YES\t2.NO";
			            	if((op==1)&&(cost<=sec)&&(sec!=0.0))//password
			            	{
			            		sec-=cost;
			            		bal-=cost;
			            		it.putdata();
			            		cout<<"Left SECURITY:Rs."<<sec;
							}
			            	else
			            	cout<<"NO SECURITY MONEY LEFT!!";
						}
					}
					else
					cout<<"NO SAVINGS LEFT!!";
				}
				else
				{
					rec-=cost;
					bal-=cost;
					it.putdata();
					cout<<"Left BILL AND RECHARGE Rs."<<rec;	
				}
				break;
		    case 3:if((cost>tr)||(tr<=0.0))
				{	int chi;
					cout<<"YOUR LIMIT IN TRAVEL&TRANSPORT  IS EXCEEDED";
					if((sav!=0)&&(cost<=sav))
					{
						cout<<"Do you want to take from savings?\t1.YES\t2.NO";
						cin>>chi;
						if(chi==1)
						{
							sav-=cost;
							bal-=cost;
							it.putdata();
							cout<<"Left SAVINGS:Rs."<<sav;
						}
			            else
			            {
			            	int op;
			            	cout<<"Do You want to take from Security\t1.YES\t2.NO";
			            	if((op==1)&&(cost<=sec)&&(sec>0.0))//password
			            	{
			            		sec-=cost;
			            		bal-=cost;
			            		it.putdata();
			            		cout<<"Left SECURITY:Rs."<<sec;
							}
			            	else
			            	cout<<"NO SECURITY MONEY LEFT!!";
						}
					}
					else
					cout<<"NO SAVINGS LEFT!!";
				}
				else
				{
					tr-=cost;
					bal-=cost;
					it.putdata();
					cout<<"Left TRAVEL & TRANSPORT Rs."<<tr;	
				}
				break;//tr-=cost;break;
		    case 4:if((cost>food)||(food<=0.0))
				{	int chi;
					cout<<"YOUR LIMIT IN FOOD  IS EXCEEDED";
					if((sav!=0)&&(cost<=sav))
					{
						cout<<"Do you want to take from savings?\t1.YES\t2.NO";
						cin>>chi;
						if(chi==1)
						{
							sav-=cost;
							bal-=cost;
							it.putdata();
							cout<<"Left SAVINGS:Rs."<<sav;
						}
			            else
			            {
			            	int op;
			            	cout<<"Do You want to take from Security\t1.YES\t2.NO";
			            	if((op==1)&&(cost<=sec)&&(sec>0.0))//password
			            	{
			            		sec-=cost;
			            		bal-=cost;
			            		it.putdata();
			            		cout<<"Left SECURITY:Rs."<<sec;
							}
			            	else
			            	cout<<"NO SECURITY MONEY LEFT!!";
						}
					}
					else
					cout<<"NO SAVINGS LEFT!!";
				}
				else
				{
					food-=cost;
					bal-=cost;
					it.putdata();
					cout<<"Left FOOD Rs."<<food;	
				}
				break;
		    case 5:if((cost>gift)||(gift<=0.0))
				{	int chi;
					cout<<"YOUR LIMIT IN GIFTS  IS EXCEEDED";
					if((sav!=0)&&(cost<=sav))
					{
						cout<<"Do you want to take from savings?\t1.YES\t2.NO";
						cin>>chi;
						if(chi==1)
						{
							sav-=cost;
							bal-=cost;
							it.putdata();
							cout<<"Left SAVINGS:Rs."<<sav;
						}
			            else
			            {
			            	int op;
			            	cout<<"Do You want to take from Security\t1.YES\t2.NO";
			            	if((op==1)&&(cost<=sec)&&(sec>0.0))
			            	{
			            		sec-=cost;
			            		bal-=cost;
			            		it.putdata();
			            		cout<<"Left SECURITY:Rs."<<sec;
							}
			            	else
			            	cout<<"NO SECURITY MONEY LEFT!!";
						}
					}
					else
					cout<<"NO SAVINGS LEFT!!";
				}
				else
				{
					gift-=cost;
					bal-=cost;
					it.putdata();
					cout<<"Left GIFTS Rs."<<gift;	
				}
				break;//gift-=cost;break;
		    case 6:cout<<"\nexiting";
		    
				exit(0);
		    default:cout<<"Enter valid choice";break;
			}
		}while(ch!=6);
	}
	cout<<"YOUR END OF PURCHASE";
}
//limitcheck funtion to manage the percentage to our limits
void limitcheck(float f,float s,float r,float t,float g)
{
	if((f+s+r+t+g)>100)
	cout<<"PAISA NAHI HAI";
	else if(f+s+r+t+g)
	cout<<"ASSIGN OTHER LIMITS";
}
