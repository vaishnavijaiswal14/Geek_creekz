/* 
 PASS 1 TO PASS 2 MACROPROCESSOR
WRITTEN IN C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;
void print_program();
void print_line();
void print_deftable();
void print_nametable();
void print_argtable();
void print_finaltable();
void macro_dec();
string macros_found();
string args(std::string &sub2);
ofstream final;
int main()
{
    int m,n,g=1,h=1;
    cout <<endl;
   // open the file if present, in read-text-mode.
   while(g==1)
   {
        cout <<"\t:::::::::::  ENTER YOUR CHOICE   :::::::::::::\n\n\tPress 1 for ) Print the Program Containing Macro's\n\n\tPress 2 for ) Start the Single Pass Macroprocessing\n\n\tEnter Your Choice ===>   ";
        cin>>m;
        switch(m)
        {
            case 1: cout <<endl<<endl<<endl;
            cout <<":::::::::::::::  PRINTING YOUR PROGRAM  ::::::::::::::::"<<endl<<endl;
            print_program();
            cout <<endl<<endl;
            g=1;
            break;
            case 2: cout <<endl<<endl<<endl;
            cout <<":::::::::::::::  PRINTING YOUR PROGRAM  ::::::::::::::::"<<endl<<endl;
            print_program();
            cout <<endl<<endl<<endl;
       	    print_line();
            g=0;
            break;
           	default:
       		cout<<"\n\n\t-----------------   Enter the Given Choice only  -----------------";
          	break;
        }
   }
   while(h==1)
   {
        cout <<"\t:::::::   MACRO'S HAS BEEN IDENTIFIED AND PROCESSED, SELECT THE TABLE YOU WANT TO PRINT  :::::::::::::\n\n\tPress 1 for ) Print the Macro Definition Table (M.D.T)\n\n\tPress 2 for ) Print the Macro Name Table (M.N.T)\n\n\tPress 3 for ) Print the Argument Array Table  \n\n\tPress 4 for ) Declaring the Macro Identify into the following program\n\n\tPress 5 for ) Exiting the Program.\n\n\tEnter Your Choice ===>   ";
        cin>>n;    
        switch(n)
        {
            case 1:cout <<endl<<endl<<endl;
                   print_deftable();
                   cout <<endl<<endl;
                   break;
            case 2:cout <<endl<<endl;
                   print_nametable();
                   cout <<endl<<endl;
                   break;
            case 3:cout <<endl<<endl;
                   print_argtable();
                   cout <<endl<<endl;
                   break;
            case 4:cout <<endl<<endl;
                   print_finaltable();
                   cout <<endl<<endl;
                   break;
            case 5:h=0;
                   break;
            default:cout<<"\n\n\t-----------------   Enter the Given Choice only  -----------------";
                    break;
        }
                              
   }
 
}
 
void print_program()
{
    ifstream filedata("c.txt");
    string singleword;
    while (getline(filedata,singleword))
	{     
        cout <<"\t"<< singleword << endl;
    }        
    filedata.close();          
}         
void print_line()
{
    std::  ifstream filedata("c.txt");
    std::string singleword,doubleword,tab="\t",newline="\n";
    string sub,m,previss;
    int k,macro_call=0,g=0,len,argnum=1,s=0;
    ofstream deftab,nametab,argtab,final;
    deftab.open ("deftab.txt");
    nametab.open("nametab.txt");
    argtab.open("argtab.txt");
    final.open("final.txt");
    final.close();
    int i=1,j,enter=1;    
    while (getline(filedata,singleword))
	{
        istringstream iss(singleword);
        j=1;
        string a,b,c;
        while (iss >> sub)
		{
            if(sub!="END")
			{
                if(j==1)
				{
                   a=sub;
				}
                else if(j==2)
				{
                   b=sub;
				}
                else if(j==3)
				{
                   c=sub;
				}
                if(sub=="MACRO" && enter==1)
				{
                   m=macros_found();
                   enter=0;
                   g=1;
                }
                if(sub=="MEND")
				{
                   g=0;
				}
                if(macro_call==1)
				{
                   len=sub.length();
                   for(k=0;k<len;k++)
				   {
                      if(sub[k]!=',')
					  {
                        argtab <<sub[k];
                      }
                      else
					  {
                        argtab <<"\t"<<"?"<<argnum<<"\n";
                        argnum++;
                      }
                      if(k==(len-1))
					  {
                        argtab <<"\t"<<"?"<<argnum<<"\n";
                        argtab.close();         
                        s=1;
                      }
                    }
                    macro_call=2;    
                    if(s==1)
					{
                        macro_dec();
                    }    
                }
                if(sub==m)
				{
                    macro_call=1;
				}     
                j++;
            }
        }
        if(g==0 && macro_call==0 && b!="MEND")
		{
            final.open("final.txt", std::ios::in | std::ios::out | std::ios::ate);
            final<<singleword<<"\n";
            final.close();
        }
        if(macro_call==2)
        {
		    macro_call=0;
		}
        i++;
    }
    filedata.close();         
}     
void macro_dec()
{
    std::ifstream filedata("deftab.txt");
    std::string singleword,doubleword;
    string sub,m,a,b,c,prevsub,argsub;
    int k,macro_call,len;
    ofstream deftab,nametab,argtab,final;
    final.open("final.txt",  std::ios::in | std::ios::out | std::ios::ate);
    int i=1,j,enter=1; 
    while (getline(filedata,singleword)) 
	{
        istringstream iss(singleword);
        j=1;
        string a,b,c;
        while (iss >> sub)
		{
           if(sub!="MEND")
		   {
              if(i==1 && j==2)
			  {
                final <<".\t"<<prevsub<<"\t"<<sub<<"\n";            
              }
              if(i!=1 && j==2)
			  {
                if(sub[0]=='?')
				{
                   argsub= args(sub);
                   final <<"-\t"<<prevsub<<"\t"<<argsub<<"\n";    
                }
                else
				{
                   final <<"-\t"<<prevsub<<"\t"<<sub<<"\n";
				}
              }
              prevsub=sub;
              j++;
           }
        }
        i++;
    }
   filedata.close();         
   final.close();    
}
 
string args(std::string &sub2)
{
   ifstream filedata("argtab.txt");
   std::string singleword,doubleword,tab="\t",newline="\n";
   string sub,m,a,b,c,prevsub;
   int i=1,j,enter=1;   
   while (getline(filedata,singleword))
   {
      istringstream iss(singleword);
      while (iss >> sub)
	  {
        if(sub2==sub)
		{
          return prevsub;
        }
        prevsub=sub;
      }
   }
   i++;
   filedata.close();                     
}         
string macros_found()
{
    std::  ifstream filedata("c.txt");
    std::string singleword,macroname,doubleword,tab="\t",newline="\n";
    string sub,andd;
    int i=1,j,macrostrt=0,argnum;
    ofstream deftab,nametab,argtab;
    string a,b,c,prevsub;
    char first,arg='&';
    deftab.open ("deftab.txt");
    nametab.open("nametab.txt");
    argtab.open("argtab.txt");
    argnum=1;
    while (getline(filedata,singleword))
	{
        istringstream iss(singleword);
        j=1;
        while (iss >> sub) 
		{
            if(sub=="MACRO")
            {
                macrostrt=1;
                macroname=prevsub;
                //cout << "MACRO NAME ====  "<<macroname<<endl<<endl;                     
            }
            if(sub=="MEND")
			{
                macrostrt=0;
                deftab <<sub<<"\n";//insert sub into the macro definition table
            }
            if(macrostrt==1)
			{
                if(prevsub!="MACRO")
				{
                    first=sub[0];
                    //cout <<first<<endl;
                    if(first==arg)
                    {
                        if(argnum==1)
						{
                            sub="?1";
						}
                        else if(argnum==2)
						{
                            sub="?2";
						}
                        else if(argnum==3)
						{
                            sub="?3";
						}
                        deftab <<prevsub<<"\t"<<sub<<"\n";
                        // deftab.close();//insert prevsub and sub into macro def table;
                        argnum=argnum+1;                                     
					}
                }
                if(prevsub=="MACRO")
				{
                    nametab <<"|\t"<<macroname<<"\t\t\t      |"<<"\n";//insert 'macroname' into the macro name table//and    
                    deftab <<macroname<<"\t"<<sub<<"\n";//insert 'macroname' and 'sub'    into macro definition table                                 
                }
                j++;
            }
            prevsub=sub;
        }
        if(macrostrt==1)
		{
            //cout <<"End of the line :: "<<i<<endl;
            i++;
        }
    }
    filedata.close();
    final.close();
    return macroname;
}
void print_deftable()
{
    ifstream filedata("deftab.txt");
    string singleword;
    cout<<"[ --------Macro Definition Table---------  ]    "<<endl<<endl;
    while (getline(filedata,singleword))
	{    
        cout << singleword << endl;
    }        
    filedata.close();          
}
void print_nametable()
{
   ifstream filedata("nametab.txt");
   string singleword;
   cout <<" _____________________________________ \n";
   cout <<"|                                     |\n";
   cout<<"|         Macro Name Table            |    \n";
   cout <<"|_____________________________________|\n";
   cout <<"|                                     |\n";
   while (getline(filedata,singleword))
   {
       cout << singleword << endl;
   }        
   cout <<"|                                     |\n";
   cout <<"|_____________________________________|\n";
   filedata.close();          
}
void print_argtable()
{
   ifstream filedata("argtab.txt");
   string singleword;
   cout<<"[ --------Argument Array Table--------- ]    "<<endl<<endl;
   while (getline(filedata,singleword))
   {
       cout << singleword << endl;
   }        
   filedata.close();          
}
 
void print_finaltable()
{
   ifstream filedata("final.txt");
   string singleword;
   cout<<"[ --------MACRO HAS BEEN DEFINED--------- ]     "<<endl<<endl;
   while (getline(filedata,singleword))
   {
     cout << singleword << endl;
   }        
   filedata.close();          
}
 

