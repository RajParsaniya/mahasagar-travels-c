#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>

struct MYBUS
{
	int no,seat,hh,mm;
	int date1,date2,date3;
	float fare;
	char busd[25],type[25];
}BUS;

struct TICKET
{
	int person,hh,mm;
	int ticketno;
	int date1, date2, date3;
	float fare;
	char busd[25];
	char mobile[25];
	char des[25];
	char name[25];
}TIC;

struct BATTERY
{
	int no;
}CHR;

struct MESSAGE
{
	int no,d1,d2,d3,hh1,mm1,hh,mm;
	char des[25],reason[25];
}MSG;

void welcome();
void end();
void title();
void box();
void box1();

void fun();
void manager();
void manager1();
void customer();

void bus1();
void ticket1();
void ongoing();
void message1();

void addbus();
void searchbus();
void updatebus();
void deletebus();

void filter();
void search();
void update();
void delet();

void msmessage();
void mvmessage();
void mdmessage();

void inquiry();
void reservation();
void payment();
void show();
void cmessage();


void main()
{
	clrscr();
	_setcursortype(_NOCURSOR);
	fflush(stdin);
	welcome();
	fun();
}

void p(int row,int column,int colour,char*message)
{
	textattr(colour);
	gotoxy(column,row);
	cprintf("%s",message);
}

void welcome()
{
	int j;
	clrscr();
	do
	{
		for(j=9;j<=15;j++)
		{
			 p(2,2,j,"$$    $$  $$$$$  $$      $$$$$  $$$$$$  $$$$  $$$$  $$$$$      $$$$$$  $$$$$$");
			 p(3,2,j,"$$    $$  $$     $$      $$     $$  $$  $$  $$  $$  $$           $$    $$  $$");
			 p(4,2,j,"$$    $$  $$$$$  $$      $$     $$  $$  $$  $$  $$  $$$$$        $$    $$  $$");
			 p(5,2,j,"$$ $$ $$  $$     $$      $$     $$  $$  $$      $$  $$           $$    $$  $$");
			 p(6,2,j,"$$$$$$$$  $$$$$  $$$$$   $$$$$  $$$$$$  $$      $$  $$$$$        $$    $$$$$$");

			p(11,3,j,"$$$$  $$$$  $$$$$$  $$  $$  $$$$$$   $$$$$  $$$$$$  $$$$$$$  $$$$$$  $$$$$$");
			p(12,3,j,"$$  $$  $$  $$  $$  $$  $$  $$  $$   $$     $$  $$  $$       $$  $$  $$  $$");
			p(13,3,j,"$$  $$  $$  $$$$$$  $$$$$$  $$$$$$   $$$$$  $$$$$$  $$  $$$  $$$$$$  $$$$$$");
			p(14,3,j,"$$      $$  $$  $$  $$  $$  $$  $$      $$  $$  $$  $$   $$  $$  $$  $$ $$ ");
			p(15,3,j,"$$      $$  $$  $$  $$  $$  $$  $$   $$$$$  $$  $$  $$$$$$$  $$  $$  $$  $$");

			p(20,13,j,"$$$$$$  $$$$$$  $$$$$$  $$    $$  $$$$$  $$     $$$$$");
			p(21,13,j,"  $$    $$  $$  $$  $$  $$    $$  $$     $$     $$   ");
			p(22,13,j,"  $$    $$$$$$  $$$$$$  $$    $$  $$$$$  $$     $$$$$");
			p(23,13,j,"  $$    $$ $$   $$  $$   $$  $$   $$     $$        $$");
			p(24,13,j,"  $$    $$  $$  $$  $$    $$$$    $$$$$  $$$$$  $$$$$");

			fflush(stdin);
			if(kbhit())
			{
				textattr(15);
				fun();
			}
			delay(250);
		}
	}while(!kbhit());
}

void end()
{
	clrscr();
	box(6,18,21,62,10);
	gotoxy(22,8);
	textattr(15);
	cprintf("THANKS FOR VISITING OUR PROGRAM");
	box(10,22,12,58,14);
	p(11,29,15,"DESIGN BY RAJ PARSANIYA");
	p(15,22,15,"IF YOU ARE LIKE THIS PROGRAM");
	p(17,22,15,"PLEASE RATE AS : ");
	p(17,39,8,"* * * * *");
	fflush(stdin);
	switch(getch())
	{
		case'0':
			exit();
		case'1':
			p(17,39,15,"*");
			p(19,22,15,"THANK YOU FOR RATING OUR PROGRAM");
			delay(5000);
			exit();
		case'2':
			p(17,39,15,"* *");
			p(19,22,15,"THANK YOU FOR RATING OUR PROGRAM");
			delay(5000);
			exit();
		case'3':
			p(17,39,15,"* * *");
			p(19,22,15,"THANK YOU FOR RATING OUR PROGRAM");
			delay(5000);
			exit();
		case'4':
			p(17,39,15,"* * * *");
			p(19,22,15,"THANK YOU FOR RATING OUR PROGRAM");
			delay(5000);
			exit();
		case'5':
			p(17,39,15,"* * * * *");
			p(19,22,15,"THANK YOU FOR RATING OUR PROGRAM");
			delay(5000);
			exit();
		default:
			end();
	}
}

void title()
{
	FILE *fp, *fp1, *fp2, *fp3;
	int x,x1=2,x2=2,i;
	for(x1=1;x1<=80;x1++)
	{
		for(x2=2;x2<=4;x2++)
		{
			gotoxy(x1,x2);
			textattr(32+18+6);
			cprintf(" ");
		}
	}
	gotoxy(33,3);
	textattr(56);
	cprintf("MAHASAGAR TRAVELS");
	fp2 = fopen("CHARGE","r");
	if(CHR.no>=31)
	{
		fp = fopen("CHARGE","r");
		fread(&CHR, sizeof(CHR),1,fp);
		while(!feof(fp))
		{
			fread(&CHR, sizeof(CHR),1,fp);
		}
		CHR.no = CHR.no-1;
		gotoxy(74,1);
		textattr(15);
		cprintf("%c",254);
		gotoxy(76,1);
		textattr(15);
		cprintf("%d%",CHR.no);
		fclose(fp);
		fp1 = fopen("CHARGE","a");
		CHR.no = CHR.no;
		fwrite(&CHR, sizeof(CHR), 1, fp1);
		fclose(fp1);
	}
	else
	{
		gotoxy(74,1);
		textattr(15);
		cprintf("%c 100%",254);
		fp3 = fopen("CHARGE","a");
		CHR.no = 100;
		fwrite(&CHR, sizeof(CHR), 1, fp3);
		fclose(fp3);
	}
	fclose(fp2);
}

void box(int r1,int c1,int r2, int c2, int c)
{
	int x;
	textattr(c);
	gotoxy(c1,r1);
	cprintf("%c",201);
	gotoxy(c2,r1);
	cprintf("%c",187);
	gotoxy(c2,r2);
	cprintf("%c",188);
	gotoxy(c1,r2);
	cprintf("%c",200);
	for(x=c1+1;x<=c2-1;x++)
	{
		gotoxy(x,r1);
		cprintf("%c",205);
		gotoxy(x,r2);
		cprintf("%c",205);
	}
	for(x=r1+1;x<=r2-1;x++)
	{
		gotoxy(c1,x);
		cprintf("%c",186);
		gotoxy(c2,x);
		cprintf("%c",186);
	}
}

void box1(int r1,int c1,int r2, int c2, int c)
{
	int x;
	textattr(c);
	gotoxy(c1,r1);
	cprintf("%c",218);
	gotoxy(c2,r1);
	cprintf("%c",191);
	gotoxy(c2,r2);
	cprintf("%c",217);
	gotoxy(c1,r2);
	cprintf("%c",192);
	for(x=c1+1;x<=c2-1;x++)
	{
		gotoxy(x,r1);
		cprintf("%c",196);
		gotoxy(x,r2);
		cprintf("%c",196);
	}
	for(x=r1+1;x<=r2-1;x++)
	{
		gotoxy(c1,x);
		cprintf("%c",179);
		gotoxy(c2,x);
		cprintf("%c",179);
	}
}

void fun()
{
	FILE *fp4, *fp5;
	int x, x1=2, x2=2, i;
	int k=0;
	char pass[25], c;
	clrscr();
	title();
	p(25,5,14,"TC");
	p(25,68,14,"0   EXIT");
	gotoxy(70,25);
	textattr(14);
	cprintf("%c",26);
	p(12,35,10,"M");
	p(12,36,15,"ANAGER");
	p(14,35,10,"C");
	p(14,36,15,"USTOMER");
	switch(getch())
	{
		case'M':
			manager1();
			break;
		case'C':
			customer();
			break;
		case'm':
			p(20,27,140,"PLEASE PRESS CAPITAL ALFABET");
			textattr(15);
			getch();
			fun();
			break;
		case'c':
			p(20,27,140,"PLEASE PRESS CAPITAL ALFABET");
			textattr(15);
			getch();
			fun();
			break;
		case'0':
			end();
			break;
		case'*':
			clrscr();
			p(25,5,14,"TC");
			gotoxy(8,25);
			cprintf("%c",16);
			p(25,10,14,"BATTERY");
			for(x1=1;x1<=80;x1++)
			{
				for(x2=2;x2<=4;x2++)
				{
					gotoxy(x1,x2);
					textattr(32+18+6);
					cprintf(" ");
				}
			}
			gotoxy(33,3);
			textattr(56);
			cprintf("MAHASAGAR TRAVELS");
			fp4 = fopen("CHARGE","r");
			fread(&CHR, sizeof(CHR),1,fp4);
			while(!feof(fp4))
			{
				fread(&CHR, sizeof(CHR),1,fp4);
			}
			CHR.no = CHR.no+0;
			gotoxy(74,1);
			textattr(15);
			cprintf("%c",254);
			gotoxy(76,1);
			cprintf("%d%",CHR.no);
			fclose(fp4);
			p(12,18,15,"PLEASE ENTER PASSWORD THAN BATTERY IS FULL");
			p(14,30,15,"PASSWORD : ");
			while(1)
			{
				c=getch();
				if(c=='\b' && k>0)
				{
					k--;
					printf("\b");
					printf(" ");
					printf("\b");
					continue;
				}
				if(c=='\r')
				break;
				if(c!='\b')
				{
					pass[k]=c;
					printf("*");
					k++;
				}
			}
			pass[k]='\0';
			if(strcmp(pass,"BATTERY")==0)
			{
				fp5 = fopen("CHARGE","a");
				for(i=CHR.no;i<=100;i++)
				{
					gotoxy(38,16);
					textattr(128+15);
					cprintf("%c",254);
					textattr(15);
					cprintf(" %d% ",i);
					gotoxy(74,1);
					textattr(128+15);
					cprintf("%c",254);
					gotoxy(76,1);
					textattr(15);
					cprintf("%d% ",i);
					delay(500);
				}
				CHR.no = 101;
				fwrite(&CHR, sizeof(CHR), 1, fp5);
				fclose(fp5);
				gotoxy(38,16);
				textattr(15);
				cprintf("%c 100%",254);
				gotoxy(74,1);
				cprintf("%c 100%",254);
				p(18,35,15,"BATTERY FULL");
				p(25,68,14,"0   BACK");
				gotoxy(70,25);
				textattr(14);
				cprintf("%c",26);
				textattr(15);
				getch();
				fun();
			}
			else
			{
				p(17,29,140,"PASSWORD IS NOT VALID");
				textattr(15);
				getch();
				fun();
			}
			break;
		default:
			fun();
	}
}

void manager1()
{
	int k=0;
	char pass[25], c;
	clrscr();
	title();
	p(25,5,14,"TC");
	gotoxy(8,25);
	cprintf("%c",16);
	p(25,10,14,"MANAGER");
	p(12,34,15,"USER : MANAGER");
	p(14,30,15,"PASSWORD : ");
	fflush(stdin);
	while(1)
	{
		c=getch();
		if(c=='\b' && k>0)
		{
			k--;
			printf("\b");
			printf(" ");
			printf("\b");
			continue;
		}
		if(c=='\r')
		break;
		if(c!='\b')
		{
		pass[k]=c;
		printf("*");
		k++;
		}
	}
	pass[k]='\0';
	if(strcmp(pass,"MAHASAGAR")==0)
	{
		manager();
	}
	else
	{
		p(17,30,140,"PASSWORD IS NOT VALID");
		textattr(15);
		getch();
		manager1();
	}
}

void manager()
{
	int c, emp;
	clrscr();
	title();
	p(25,5,14,"TC");
	gotoxy(8,25);
	cprintf("%c",16);
	p(25,10,14,"MANAGER");
	p(25,68,14,"0   BACK");
	gotoxy(70,25);
	textattr(14);
	cprintf("%c",26);
	p(12,34,10,"B");
	p(12,35,15,"US RECORD");
	p(14,33,10,"T");
	p(14,34,15,"ICKET RECORD");
	p(16,34,10,"O");
	p(16,35,15,"NGOING BUS");
	p(18,36,10,"M");
	p(18,37,15,"ESSAGE");
	switch(getch())
	{
		case'B':
			bus1();
			break;
		case'T':
			ticket1();
			break;
		case'O':
			ongoing();
			break;
		case'M':
			message1();
			break;
		case'0':
			fun();
			break;
		default:
			manager();
	}
}

void customer()
{
	clrscr();
	title();
	p(25,5,14,"TC");
	gotoxy(8,25);
	cprintf("%c",16);
	p(25,10,14,"CUSTOMER");
	p(25,68,14,"0   BACK");
	gotoxy(70,25);
	textattr(14);
	cprintf("%c",26);
	p(11,37,8+2,"I");
	p(11,38,8+2+5,"NQUIRY");
	p(13,35,8+2,"R");
	p(13,36,8+2+5,"ESERVATION");
	p(15,35,8+2,"S");
	p(15,36,8+2+5,"HOW TICKET");
	p(17,37,8+2,"M");
	p(17,38,8+2+5,"ESSAGE");
	switch(getch())
	{
		case'I':
			inquiry();
			break;
		case'R':
			reservation();
			break;
		case'S':
			show();
			break;
		case'M':
			cmessage();
			break;
		case'0':
			fun();
			break;
		default:
			customer();
	}
}

void bus1()
{
	int c, emp;
	clrscr();
	title();
	p(25,5,14,"TC");
	gotoxy(8,25);
	cprintf("%c",16);
	p(25,10,14,"MANAGER");
	gotoxy(18,25);
	cprintf("%c",16);
	p(25,20,14,"BUS");
	p(25,68,14,"0   BACK");
	gotoxy(70,25);
	textattr(14);
	cprintf("%c",26);
	p(12,36,10,"A");
	p(12,37,15,"DD BUS");
	p(14,35,10,"S");
	p(14,36,15,"EARCH BUS");
	p(16,35,10,"U");
	p(16,36,15,"PDATE BUS");
	p(18,35,10,"D");
	p(18,36,15,"ELETE BUS");
	switch(getch())
	{
		case'A':
			addbus();
			break;
		case'S':
			emp = bempty();
			if (emp == 0)
			{
				p(20,27,12+128,"DATA NOT AVAILABLE IN SYSTEM");
				textattr(15);
				getch();
				bus1();
			}
			else
			searchbus();
			break;
		case'U':
			emp = bempty();
			if (emp == 0)
			{
				p(20,27,12+128,"DATA NOT AVAILABLE IN SYSTEM");
				textattr(15);
				getch();
				bus1();
			}
			else
			updatebus();
			break;
		case'D':
			emp = bempty();
			if (emp == 0)
			{
				p(20,27,12+128,"DATA NOT AVAILABLE IN SYSTEM");
				textattr(15);
				getch();
				bus1();
			}
			else
			deletebus();
			break;
		case'0':
			manager();
			break;
		default:
			bus1();
	}
}

void ticket1()
{
	int c, emp;
	clrscr();
	title();
	p(25,5,14,"TC");
	gotoxy(8,25);
	cprintf("%c",16);
	p(25,10,14,"MANAGER");
	gotoxy(18,25);
	cprintf("%c",16);
	p(25,20,14,"TICKET");
	p(25,68,14,"0   BACK");
	gotoxy(70,25);
	textattr(14);
	cprintf("%c",26);
	p(12,34,10,"F");
	p(12,35,15,"ILTER TICKET");
	p(14,34,10,"S");
	p(14,35,15,"EARCH TICKET");
	p(16,34,10,"U");
	p(16,35,15,"PDATE TICKET");
	p(18,34,10,"D");
	p(18,35,15,"ELETE TICKET");
	switch(getch())
	{
		case'F':
			emp = tempty();
			if (emp == 0)
			{
				p(20,27,12+128,"DATA NOT AVAILABLE IN SYSTEM");
				textattr(15);
				getch();
				ticket1();
			}
			else
			filter();
			break;
		case'S':
			emp = tempty();
			if (emp == 0)
			{
				p(20,27,12+128,"DATA NOT AVAILABLE IN SYSTEM");
				textattr(15);
				getch();
				ticket1();
			}
			else
			search();
			break;
		case'U':
			emp = tempty();
			if (emp == 0)
			{
				p(20,27,12+128,"DATA NOT AVAILABLE IN SYSTEM");
				textattr(15);
				getch();
				ticket1();
			}
			else
			update();
			break;
		case'D':
			emp = tempty();
			if (emp == 0)
			{
				p(20,27,12+128,"DATA NOT AVAILABLE IN SYSTEM");
				textattr(15);
				getch();
				ticket1();
			}
			else
			delet();
		case'0':
			manager();
			break;
		default:
			ticket1();
	}
}

void message1()
{
	int c, emp;
	clrscr();
	title();
	p(25,5,14,"TC");
	gotoxy(8,25);
	cprintf("%c",16);
	p(25,10,14,"MANAGER");
	gotoxy(18,25);
	cprintf("%c",16);
	p(25,20,14,"MESSAGE");
	p(25,68,14,"0   BACK");
	gotoxy(70,25);
	textattr(14);
	cprintf("%c",26);
	p(12,34,10,"S");
	p(12,35,15,"END MESSAGE");
	p(14,33,10,"D");
	p(14,34,15,"ELETE MESSAGE");
	p(16,34,10,"V");
	p(16,35,15,"IEW MESSAGE");
	switch(getch())
	{
		case'V':
			emp = mempty();
			if (emp == 0)
			{
				p(20,27,12+128,"DATA NOT AVAILABLE IN SYSTEM");
				textattr(15);
				getch();
				message1();
			}
			else
			mvmessage();
			break;
		case'S':
			msmessage();
			break;
		case'D':
			emp = mempty();
			if (emp == 0)
			{
				p(20,27,12+128,"DATA NOT AVAILABLE IN SYSTEM");
				textattr(15);
				getch();
				message1();
			}
			else
			mdmessage();
			break;
		case'0':
			manager();
			break;
		default:
			message1();
	}
}

void addbus()
{
	FILE *fp6, *fp7;
	char ch[10];
	clrscr();
	title();
	p(25,5,14,"TC");
	gotoxy(8,25);
	cprintf("%c",16);
	p(25,10,14,"MANAGER");
	gotoxy(18,25);
	cprintf("%c",16);
	p(25,20,14,"BUS");
	gotoxy(24,25);
	cprintf("%c",16);
	p(25,26,14,"ADD BUS");
	p(6,22,15,"DO YOU WANT TO ADD NEW BUS (YES/NO) : ");
	fflush(stdin);
	scanf("%s",&ch);
	if(strcmp(ch,"NO")==0)
	{
		bus1();
	}
	if(strcmp(ch,"YES")==0)
	{
		fp7 = fopen("BUS","r");
		fread(&BUS, sizeof(BUS),1,fp7);
		while(!feof(fp7))
		{
			fread(&BUS, sizeof(BUS),1,fp7);
		}
		BUS.no = BUS.no+1;
		fclose(fp7);
		fp6 = fopen("BUS","a");
		p(6,20,15,"                                            ");
		gotoxy(29,7);
		textattr(11);
		cprintf("BUS NUMBER : %d",BUS.no);
		p(9,27,15,"BUS LOCATION : AHMEDABAD");
		p(11,24,15,"BUS DESTINATION : ");
		scanf("%s",&BUS.busd);
		p(13,22,15,"DATE (DD/MM/YYYY) : ");
		scanf("%d/%d/%d",&BUS.date1,&BUS.date2,&BUS.date3);
		p(15,23,15,"ABD TIME (HH:MM) : ");
		scanf("%d:%d",&BUS.hh,&BUS.mm);
		p(17,25,15,"TYPE (VOL/SLL) : ");
		scanf("%s",&BUS.type);
		p(19,24,15,"FARE (MAX 5000) : ");
		scanf("%f",&BUS.fare);
		p(21,26,15,"SEAT (MAX 80) : ");
		scanf("%d",&BUS.seat);

		fflush(stdin);
		if(strcmp(BUS.busd,"AHMEDABAD")!=0)
		{
		if(BUS.date3>=2018 && BUS.date3<=9999)
		{
		if(BUS.date2>=1 && BUS.date2<=12)
		{
		if(((BUS.date1>=1 && BUS.date1<=31) && (BUS.date2==1 || BUS.date2==3 || BUS.date2==5 || BUS.date2==7 || BUS.date2==8 || BUS.date2==10 || BUS.date2==12)) || ((BUS.date1>=1 && BUS.date1<=30) && (BUS.date2==4 || BUS.date2==6 || BUS.date2==9 || BUS.date2==11)) || ((BUS.date1>=1 && BUS.date1<=28) && (BUS.date2==2)))
		{
		if((BUS.hh<=23 && BUS.hh>=0) && (BUS.mm<=59 && BUS.mm>=0))
		{
		if(strcmp(BUS.type,"VOL")==0 || strcmp(BUS.type,"SLL")==0)
		{
		if(BUS.fare<=5000 && BUS.fare>=1)
		{
		if(BUS.seat<=80 && BUS.seat>=20)
		{
			fflush(stdin);
			fwrite(&BUS, sizeof(BUS), 1, fp6);
			fclose(fp6);
			p(23,30,10,"BUS ADDED SUCCESSFULLY");
			p(25,68,14,"0   BACK");
			gotoxy(70,25);
			textattr(14);
			cprintf("%c",26);
			textattr(15);
			getch();
			bus1();
		}
		else
		{
			if(BUS.seat>=81)
			{
				p(23,28,140,"MORE THAN 80 SEAT NOT VALID");
				textattr(15);
				fclose(fp6);
				getch();
				bus1();
			}
			else
			{
				p(23,28,140,"LESS THAN 20 SEAT NOT VALID");
				textattr(15);
				fclose(fp6);
				getch();
				bus1();
			}
		}
		}
		else
		{
			if(BUS.fare>=5001)
			{
				p(23,29,140,"MORE THAN 5000 FARE NOT VALID");
				textattr(15);
				fclose(fp6);
				getch();
				bus1();
			}
			else
			{
				p(23,29,140,"LESS THAN 1 FARE NOT VALID");
				textattr(15);
				fclose(fp6);
				getch();
				bus1();
			}
		}
		}
		else
		{
			p(23,32,140,"BUS TYPE IS NOT VALID");
			textattr(15);
			fclose(fp6);
			getch();
			bus1();
		}
		}
		else
		{

			p(23,29,140,"TIME FORMET IS NOT VALID");
			textattr(15);
			fclose(fp6);
			getch();
			bus1();
		}
		}
		else
		{
			p(23,29,140,"DATE (DD) IS NOT VALID");
			textattr(15);
			fclose(fp6);
			getch();
			bus1();
		}
		}
		else
		{
			p(23,29,140,"DATE (MM) IS NOT VALID");
			textattr(15);
			fclose(fp6);
			getch();
			bus1();
		}
		}
		else
		{
			p(23,29,140,"DATE (YYYY) IS NOT VALID");
			textattr(15);
			fclose(fp6);
			getch();
			bus1();
		}
		}
		else
		{
			p(23,27,140,"LOCATION & DESTINATION ARE SAME");
			textattr(15);
			fclose(fp6);
			getch();
			bus1();
		}
	}
	else
	{
		p(8,33,140,"PLEASE TRY AGAIN");
		textattr(15);
		getch();
		addbus();
	}
}

void searchbus()
{
	FILE *fp8, *fp9;
	int b, x, avl, d1, d2, d3;
	char des[25];
	clrscr();
	title();
	p(25,5,14,"TC");
	gotoxy(8,25);
	cprintf("%c",16);
	p(25,10,14,"MANAGER");
	gotoxy(18,25);
	cprintf("%c",16);
	p(25,20,14,"BUS");
	gotoxy(24,25);
	cprintf("%c",16);
	p(25,26,14,"SEARCH BUS");
	p(25,68,14,"0   BACK");
	gotoxy(70,25);
	textattr(14);
	cprintf("%c",26);
	p(10,25,15,"SEARCH BY BUS");
	p(10,39,10,"N");
	p(10,40,15,"UMBER");
	p(12,25,15,"SEARCH BY BUS");
	p(12,39,10,"R");
	p(12,40,15,"OUTE");
	switch(getch())
	{
		case'N':
			p(14,20,15,"PLEASE ENTER BUS NO YOU WANT TO SEARCH : ");
			scanf("%d", &b);
			avl = bus(b);
			if (avl == 0)
			{
				gotoxy(22,16);
				textattr(140);
				cprintf("BUS NO %d IS NOT AVAILABLE IN SYSTEM",b);
				textattr(15);
				getch();
				searchbus();
			}
			else
			{
				fp8 = fopen("BUS", "r");
				while (fread(&BUS, sizeof(BUS), 1, fp8))
				{
					x = BUS.no;
					if (x == b)
					{
						clrscr();
						title();
						p(25,5,14,"TC");
						gotoxy(8,25);
						cprintf("%c",16);
						p(25,10,14,"MANAGER");
						gotoxy(18,25);
						cprintf("%c",16);
						p(25,20,14,"BUS");
						gotoxy(24,25);
						cprintf("%c",16);
						p(25,26,14,"SEARCH BUS");
						p(25,68,14,"0   BACK");
						gotoxy(70,25);
						textattr(14);
						cprintf("%c",26);
						box(7,20,23,60,7);
						gotoxy(24,9);
						textattr(15);
						cprintf("BUS NUMBER : %d",BUS.no);
						gotoxy(24,11);
						cprintf("BUS ROUTE : AHMEDABAD TO %s",BUS.busd);
						gotoxy(24,13);
						cprintf("BUS DATE : %d/%d/%d",BUS.date1,BUS.date2,BUS.date3);
						gotoxy(24,15);
						cprintf("ABD TIME : %d:%d",BUS.hh,BUS.mm);
						gotoxy(24,17);
						cprintf("TYPE : %s",BUS.type);
						gotoxy(24,19);
						cprintf("FARE : %0.2f",BUS.fare);
						gotoxy(24,21);
						cprintf("SEAT : %d",BUS.seat);
					}
				}
				fclose(fp8);
				getch();
				searchbus();
			}
			break;
		case'R':
			p(14,20,15,"PLEASE ENTER BUS ROUTE YOU WANT TO SEARCH");
			p(16,31,15,"LOCATION : AHMEDABAD");
			p(18,28,15,"DESTINATION : ");
			fflush(stdin);
			scanf("%s",&des);
			p(20,35,15,"DATE : ");
			scanf("%d/%d/%d",&d1,&d2,&d3);
			fp9 = fopen("BUS", "r");
			while (fread(&BUS, sizeof(BUS), 1, fp9))
			{
				if((strcmp(des,BUS.busd)==0) && (BUS.date1==d1 && BUS.date2==d2 && BUS.date3==d3))
				{
					clrscr();
					title();
					p(25,5,14,"TC");
					gotoxy(8,25);
					cprintf("%c",16);
					p(25,10,14,"MANAGER");
					gotoxy(18,25);
					cprintf("%c",16);
					p(25,20,14,"BUS");
					gotoxy(24,25);
					cprintf("%c",16);
					p(25,26,14,"SEARCH BUS");
					p(25,68,14,"0   BACK");
					gotoxy(70,25);
					textattr(14);
					cprintf("%c",26);
					box(7,20,23,60,7);
					gotoxy(24,9);
					textattr(15);
					cprintf("BUS NUMBER : %d",BUS.no);
					gotoxy(24,11);
					cprintf("BUS ROUTE : AHMEDABAD TO %s",BUS.busd);
					gotoxy(24,13);
					cprintf("BUS DATE : %d/%d/%d",BUS.date1,BUS.date2,BUS.date3);
					gotoxy(24,15);
					cprintf("ABD TIME : %d:%d",BUS.hh,BUS.mm);
					gotoxy(24,17);
					cprintf("TYPE : %s",BUS.type);
					gotoxy(24,19);
					cprintf("FARE : %0.2f",BUS.fare);
					gotoxy(24,21);
					cprintf("SEAT : %d",BUS.seat);
					fclose(fp9);
					getch();
					searchbus();
				}
			}
			fclose(fp9);
			p(22,35,140,"BUS NOT FOUND");
			textattr(15);
			getch();
			searchbus();
			break;
		case'0':
			bus1();
			break;
		default:
			searchbus();
	}
}

void updatebus()
{
	FILE *fp10, *fp11, *fp12;
	int x, b, avl;
	clrscr();
	title();
	p(25,5,14,"TC");
	gotoxy(8,25);
	cprintf("%c",16);
	p(25,10,14,"MANAGER");
	gotoxy(18,25);
	cprintf("%c",16);
	p(25,20,14,"BUS");
	gotoxy(24,25);
	cprintf("%c",16);
	p(25,26,14,"UPDATE BUS");
	p(25,68,14,"0   BACK");
	gotoxy(70,25);
	textattr(14);
	cprintf("%c",26);
	p(10,20,15,"PLEASE ENTER BUS NO YOU WANT TO UPDATE : ");
	scanf("%d", &b);
	avl = bus(b);
	if (avl == 0)
	{
		if(b==0)
		{
			bus1();
		}
		else
		{
			gotoxy(22,12);
			textattr(140);
			cprintf("BUS NO %d IS NOT AVAILABLE IN SYSTEM", b);
			textattr(15);
			getch();
			bus1();
		}
	}
	else
	{
		fp12 = fopen("TICKET", "r");
		while (fread(&TIC, sizeof(TIC), 1, fp12))
		{
			if(strcmp(TIC.des,BUS.busd)==0)
			{
				p(12,27,140,"THIS BUS ARE ALREADY RESERVED");
				textattr(15);
				fclose(fp12);
				getch();
				bus1();
			}
		}
		fclose(fp12);
		fp11 = fopen("BUS", "r");
		fp10 = fopen("TEMP", "w");
		while (fread(&BUS, sizeof(BUS), 1, fp11))
		{
			x = BUS.no;
			if(x != b)
			fwrite(&BUS, sizeof(BUS), 1, fp10);
			else
			{
				gotoxy(25,12);
				textattr(15);
				cprintf("BUS ROUTE : AHMEDABAD TO %s",BUS.busd);
				gotoxy(26,14);
				cprintf("OLD TIME : %d:%d",BUS.hh,BUS.mm);
				gotoxy(26,15);
				cprintf("OLD FARE : %0.2f",BUS.fare);

				p(17,26,15,"NEW TIME : ");
				scanf("%d:%d",&BUS.hh,&BUS.mm);
				p(18,26,15,"NEW FARE : ");
				scanf("%f",&BUS.fare);

				if((BUS.hh<=23 && BUS.hh>=0) && (BUS.mm<=59 && BUS.mm>=0))
				{
				if(BUS.fare<=5000 && BUS.fare>=1)
				{
					fwrite(&BUS, sizeof(BUS), 1, fp10);
				}
				else
				{
					if(BUS.fare>=5001)
					{
						p(20,29,140,"MORE THAN 5000 FARE NOT VALID");
						textattr(15);
						getch();
						bus1();
					}
					else
					{
						p(20,29,140,"LESS THAN 1 FARE NOT VALID");
						textattr(15);
						getch();
						bus1();
					}
				}
				}
				else
				{
					p(20,29,140,"TIME FORMAT IS NOT VALID");
					textattr(15);
					getch();
					bus1();
				}
			}
		}
		fclose(fp11);
		fclose(fp10);
		fp11 = fopen("BUS", "w");
		fp10 = fopen("TEMP", "r");
		while (fread(&BUS, sizeof(BUS), 1, fp10))
		{
			fwrite(&BUS, sizeof(BUS), 1, fp11);
		}
		fclose(fp11);
		fclose(fp10);
		p(20,34,10,"BUS UPDATED");
		textattr(15);
		getch();
		bus1();
	}
}

void deletebus()
{
	FILE *fp13, *fp14, *fp15, *fp16;
	int b, x;
	char ch[25];
	clrscr();
	title();
	p(25,5,14,"TC");
	gotoxy(8,25);
	cprintf("%c",16);
	p(25,10,14,"MANAGER");
	gotoxy(18,25);
	cprintf("%c",16);
	p(25,20,14,"BUS");
	gotoxy(24,25);
	cprintf("%c",16);
	p(25,26,14,"DELETE BUS");
	p(25,68,14,"0   BACK");
	gotoxy(70,25);
	textattr(14);
	cprintf("%c",26);
	p(12,20,15,"PLEASE ENTER BUS NO YOU WANT TO DELETE : ");
	scanf("%d", &b);
	if (bus(b) == 0)
	{
		if(b==0)
		{
			bus1();
		}
		else
		{
			gotoxy(22,14);
			textattr(140);
			cprintf("BUS NO %d IS NOT AVAILABLE IN SYSTEM", b);
			textattr(15);
			getch();
			bus1();
		}
	}
	else
	{
		fp15 = fopen("BUS", "r");
		while (fread(&BUS, sizeof(BUS), 1, fp15))
		{
			x = BUS.no;
			if (x == b)
			{
				clrscr();
				title();
				p(25,5,14,"TC");
				gotoxy(8,25);
				cprintf("%c",16);
				p(25,10,14,"MANAGER");
				gotoxy(18,25);
				cprintf("%c",16);
				p(25,20,14,"BUS");
				gotoxy(24,25);
				cprintf("%c",16);
				p(25,26,14,"DELETE BUS");
				box(7,20,21,60,7);
				gotoxy(24,9);
				textattr(15);
				cprintf("BUS NUMBER : %d",BUS.no);
				gotoxy(24,11);
				cprintf("BUS ROUTE : AHMEDABAD TO %s",BUS.busd);
				gotoxy(24,13);
				cprintf("ABD TIME : %d:%d",BUS.hh,BUS.mm);
				gotoxy(24,15);
				cprintf("TYPE : %s",BUS.type);
				gotoxy(24,17);
				cprintf("FARE : %0.2f",BUS.fare);
				gotoxy(24,19);
				cprintf("SEAT : %d",BUS.seat);
				p(23,20,15,"DO YOU WANT TO DELETE THIS BUS (YES/NO) : ");
				fflush(stdin);
				scanf("%s",&ch);
				if(strcmp(ch,"YES")==0)
				{
				fp16 = fopen("TICKET", "r");
				while (fread(&TIC, sizeof(TIC), 1, fp16))
				{
					if(strcmp(TIC.des,BUS.busd)==0)
					{
						p(23,10,15,"                                                                       ");
						p(23,27,140,"THIS BUS ARE ALREADY RESERVED");
						p(25,68,14,"0   BACK");
						gotoxy(70,25);
						textattr(14);
						cprintf("%c",26);
						textattr(15);
						fclose(fp16);
						getch();
						bus1();
					}
				}
				fclose(fp16);
				fp13 = fopen("BUS", "r");
				fp14 = fopen("TEMP", "w");
				while (fread(&BUS, sizeof(BUS), 1, fp13))
				{
					x = BUS.no;
					if (x != b)
					fwrite(&BUS, sizeof(BUS), 1, fp14);
				}
				fclose(fp13);
				fclose(fp14);
				fp13 = fopen("BUS", "w");
				fp14 = fopen("TEMP", "r");
				while (fread(&BUS, sizeof(BUS), 1, fp14))
				fwrite(&BUS, sizeof(BUS), 1, fp13);
				p(23,10,15,"                                                                       ");
				p(23,34,10,"BUS DELETED");
				p(25,68,14,"0   BACK");
				gotoxy(70,25);
				textattr(14);
				cprintf("%c",26);
				textattr(15);
				fclose(fp13);
				fclose(fp14);
				getch();
				bus1();
				}
				else
				{
					bus1();
				}
			}
		}
		fclose(fp15);
	}
}

void filter()
{
	FILE *fp17, *fp18, *fp19, *fp20, *fp21, *fp22, *fp23, *fp24;
	int d1, d2, d3;
	char name[25], des[25], mobile[25];
	clrscr();
	title();
	p(25,5,14,"TC");
	gotoxy(8,25);
	cprintf("%c",16);
	p(25,10,14,"MANAGER");
	gotoxy(18,25);
	cprintf("%c",16);
	p(25,20,14,"TICKET");
	gotoxy(27,25);
	cprintf("%c",16);
	p(25,29,14,"FILTER TICKET");
	p(25,68,14,"0   BACK");
	gotoxy(70,25);
	textattr(14);
	cprintf("%c",26);
	p(8,25,15,"FILTER BY PASSENGER");
	p(8,45,10,"N");
	p(8,46,15,"AME");
	p(10,25,15,"FILTER BY");
	p(10,35,10,"C");
	p(10,36,15,"ONTACT NUMBER");
	p(12,25,15,"FILTER BY JOURNEY");
	p(12,43,10,"D");
	p(12,44,15,"ATE");
	p(14,25,15,"FILTER BY JOURNEY");
	p(14,43,10,"R");
	p(14,44,15,"OUTE");
	switch(getch())
	{
		case'N':
			p(16,20,15,"PLEASE ENTER PASSENGER NAME YOU WANT TO SEARCH : ");
			fflush(stdin);
			scanf("%s",&name);
			fp17 = fopen("TICKET", "r");
			while (fread(&TIC, sizeof(TIC), 1, fp17))
			{
				if(strcmp(name,TIC.name)==0)
				{
					fp18 = fopen("TICKET", "r");
					while (fread(&TIC, sizeof(TIC), 1, fp18))
					{
						if(strcmp(name,TIC.name)==0)
						{
							clrscr();
							title();
							p(25,5,14,"TC");
							gotoxy(8,25);
							cprintf("%c",16);
							p(25,10,14,"MANAGER");
							gotoxy(18,25);
							cprintf("%c",16);
							p(25,20,14,"TICKET");
							gotoxy(27,25);
							cprintf("%c",16);
							p(25,29,14,"FILTER TICKET");
							p(7,11,15," * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
							p(22,11,15," * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
							p(21,12,15,"*");
							p(8,12,15,"*");
							p(9,12,15,"*");
							p(10,12,15,"*");
							p(11,12,15,"*");
							p(12,12,15,"*");
							p(13,12,15,"*");
							p(14,12,15,"*");
							p(15,12,15,"*");
							p(16,12,15,"*");
							p(17,12,15,"*");
							p(18,12,15,"*");
							p(19,12,15,"*");
							p(20,12,15,"*");
							p(21,70,15,"*");
							p(8,70,15,"*");
							p(9,70,15,"*");
							p(10,70,15,"*");
							p(11,70,15,"*");
							p(12,70,15,"*");
							p(13,70,15,"*");
							p(14,70,15,"*");
							p(15,70,15,"*");
							p(16,70,15,"*");
							p(17,70,15,"*");
							p(18,70,15,"*");
							p(19,70,15,"*");
							p(20,70,15,"*");
							p(8,33,13,"MAHASAGAR TRAVELS");
							gotoxy(16,10);
							textattr(15);
							cprintf("NAME : %s",TIC.name);
							gotoxy(51,10);
							cprintf("DATE : %d/%d/%d",TIC.date1,TIC.date2,TIC.date3);
							gotoxy(16,12);
							cprintf("TICKET NUMBER : %d",TIC.ticketno);
							gotoxy(51,12);
							cprintf("TIME : %d:%d",TIC.hh,TIC.mm);
							gotoxy(16,14);
							cprintf("JOURNEY : AHMEDABAD TO %s",TIC.des);
							gotoxy(16,16);
							cprintf("PERSON : %d",TIC.person);
							gotoxy(51,16);
							cprintf("FARE : %0.2f",TIC.fare);
							gotoxy(16,18);
							cprintf("CONTACT NUMBER : %s",TIC.mobile);
							gotoxy(16,20);
							cprintf("MAHASAGAR OFFICE NUMBER : 022-54321, 079-24245");
							getch();
						}
					}
					fclose(fp18);
					filter();
				}
			}
			fclose(fp17);
			p(18,34,140,"DATA NOT FOUND");
			textattr(15);
			getch();
			filter();
			break;
		case'D':
			p(16,20,15,"PLEASE ENTER JOURNEY DATE YOU WANT TO SEARCH : ");
			fflush(stdin);
			scanf("%d/%d/%d",&d1,&d2,&d3);
			fp19 = fopen("TICKET", "r");
			while (fread(&TIC, sizeof(TIC), 1, fp19))
			{
				if(d1==TIC.date1 && d2==TIC.date2 && d3==TIC.date3)
				{
					fp20 = fopen("TICKET", "r");
					while (fread(&TIC, sizeof(TIC), 1, fp20))
					{
						if(d1==TIC.date1 && d2==TIC.date2 && d3==TIC.date3)
						{
							clrscr();
							title();
							p(25,5,14,"TC");
							gotoxy(8,25);
							cprintf("%c",16);
							p(25,10,14,"MANAGER");
							gotoxy(18,25);
							cprintf("%c",16);
							p(25,20,14,"TICKET");
							gotoxy(27,25);
							cprintf("%c",16);
							p(25,29,14,"FILTER TICKET");
							p(7,11,15," * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
							p(22,11,15," * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
							p(21,12,15,"*");
							p(8,12,15,"*");
							p(9,12,15,"*");
							p(10,12,15,"*");
							p(11,12,15,"*");
							p(12,12,15,"*");
							p(13,12,15,"*");
							p(14,12,15,"*");
							p(15,12,15,"*");
							p(16,12,15,"*");
							p(17,12,15,"*");
							p(18,12,15,"*");
							p(19,12,15,"*");
							p(20,12,15,"*");
							p(21,70,15,"*");
							p(8,70,15,"*");
							p(9,70,15,"*");
							p(10,70,15,"*");
							p(11,70,15,"*");
							p(12,70,15,"*");
							p(13,70,15,"*");
							p(14,70,15,"*");
							p(15,70,15,"*");
							p(16,70,15,"*");
							p(17,70,15,"*");
							p(18,70,15,"*");
							p(19,70,15,"*");
							p(20,70,15,"*");
							p(8,33,13,"MAHASAGAR TRAVELS");
							gotoxy(16,10);
							textattr(15);
							cprintf("NAME : %s",TIC.name);
							gotoxy(51,10);
							cprintf("DATE : %d/%d/%d",TIC.date1,TIC.date2,TIC.date3);
							gotoxy(16,12);
							cprintf("TICKET NUMBER : %d",TIC.ticketno);
							gotoxy(51,12);
							cprintf("TIME : %d:%d",TIC.hh,TIC.mm);
							gotoxy(16,14);
							cprintf("JOURNEY : AHMEDABAD TO %s",TIC.des);
							gotoxy(16,16);
							cprintf("PERSON : %d",TIC.person);
							gotoxy(51,16);
							cprintf("FARE : %0.2f",TIC.fare);
							gotoxy(16,18);
							cprintf("CONTACT NUMBER : %s",TIC.mobile);
							gotoxy(16,20);
							cprintf("MAHASAGAR OFFICE NUMBER : 022-54321, 079-24245");
							getch();
						}
					}
					fclose(fp20);
					filter();
				}
			}
			fclose(fp19);
			p(18,34,140,"DATA NOT FOUND");
			textattr(15);
			getch();
			filter();
			break;
		case'R':
			p(16,20,15,"PLEASE ENTER JOURNEY ROUTE YOU WANT TO SEARCH");
			p(18,31,15,"LOCATION : AHMEDABAD");
			p(20,28,15,"DESTINATION : ");
			fflush(stdin);
			scanf("%s",&des);
			fp21 = fopen("TICKET", "r");
			while (fread(&TIC, sizeof(TIC), 1, fp21))
			{
				if(strcmp(des,TIC.des)==0)
				{
					fp22 = fopen("TICKET", "r");
					while (fread(&TIC, sizeof(TIC), 1, fp22))
					{
						if(strcmp(des,TIC.des)==0)
						{
							clrscr();
							title();
							p(25,5,14,"TC");
							gotoxy(8,25);
							cprintf("%c",16);
							p(25,10,14,"MANAGER");
							gotoxy(18,25);
							cprintf("%c",16);
							p(25,20,14,"TICKET");
							gotoxy(27,25);
							cprintf("%c",16);
							p(25,29,14,"FILTER TICKET");
							p(7,11,15," * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
							p(22,11,15," * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
							p(21,12,15,"*");
							p(8,12,15,"*");
							p(9,12,15,"*");
							p(10,12,15,"*");
							p(11,12,15,"*");
							p(12,12,15,"*");
							p(13,12,15,"*");
							p(14,12,15,"*");
							p(15,12,15,"*");
							p(16,12,15,"*");
							p(17,12,15,"*");
							p(18,12,15,"*");
							p(19,12,15,"*");
							p(20,12,15,"*");
							p(21,70,15,"*");
							p(8,70,15,"*");
							p(9,70,15,"*");
							p(10,70,15,"*");
							p(11,70,15,"*");
							p(12,70,15,"*");
							p(13,70,15,"*");
							p(14,70,15,"*");
							p(15,70,15,"*");
							p(16,70,15,"*");
							p(17,70,15,"*");
							p(18,70,15,"*");
							p(19,70,15,"*");
							p(20,70,15,"*");
							p(8,33,13,"MAHASAGAR TRAVELS");
							gotoxy(16,10);
							textattr(15);
							cprintf("NAME : %s",TIC.name);
							gotoxy(51,10);
							cprintf("DATE : %d/%d/%d",TIC.date1,TIC.date2,TIC.date3);
							gotoxy(16,12);
							cprintf("TICKET NUMBER : %d",TIC.ticketno);
							gotoxy(51,12);
							cprintf("TIME : %d:%d",TIC.hh,TIC.mm);
							gotoxy(16,14);
							cprintf("JOURNEY : AHMEDABAD TO %s",TIC.des);
							gotoxy(16,16);
							cprintf("PERSON : %d",TIC.person);
							gotoxy(51,16);
							cprintf("FARE : %0.2f",TIC.fare);
							gotoxy(16,18);
							cprintf("CONTACT NUMBER : %s",TIC.mobile);
							gotoxy(16,20);
							cprintf("MAHASAGAR OFFICE NUMBER : 022-54321, 079-24245");
							getch();
						}
					}
					fclose(fp22);
					filter();
				}
			}
			fclose(fp21);
			p(22,34,140,"DATA NOT FOUND");
			textattr(15);
			getch();
			filter();
			break;
		case'C':
			p(16,20,15,"PLEASE ENTER CONTACT NUMBER YOU WANT TO SEARCH : ");
			fflush(stdin);
			scanf("%s",&mobile);
			fp23 = fopen("TICKET", "r");
			while (fread(&TIC, sizeof(TIC), 1, fp23))
			{
				if(strcmp(mobile,TIC.mobile)==0)
				{
					fp24 = fopen("TICKET", "r");
					while (fread(&TIC, sizeof(TIC), 1, fp24))
					{
						if(strcmp(mobile,TIC.mobile)==0)
						{
							clrscr();
							title();
							p(25,5,14,"TC");
							gotoxy(8,25);
							cprintf("%c",16);
							p(25,10,14,"MANAGER");
							gotoxy(18,25);
							cprintf("%c",16);
							p(25,20,14,"TICKET");
							gotoxy(27,25);
							cprintf("%c",16);
							p(25,29,14,"FILTER TICKET");
							p(7,11,15," * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
							p(22,11,15," * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
							p(21,12,15,"*");
							p(8,12,15,"*");
							p(9,12,15,"*");
							p(10,12,15,"*");
							p(11,12,15,"*");
							p(12,12,15,"*");
							p(13,12,15,"*");
							p(14,12,15,"*");
							p(15,12,15,"*");
							p(16,12,15,"*");
							p(17,12,15,"*");
							p(18,12,15,"*");
							p(19,12,15,"*");
							p(20,12,15,"*");
							p(21,70,15,"*");
							p(8,70,15,"*");
							p(9,70,15,"*");
							p(10,70,15,"*");
							p(11,70,15,"*");
							p(12,70,15,"*");
							p(13,70,15,"*");
							p(14,70,15,"*");
							p(15,70,15,"*");
							p(16,70,15,"*");
							p(17,70,15,"*");
							p(18,70,15,"*");
							p(19,70,15,"*");
							p(20,70,15,"*");
							p(8,33,13,"MAHASAGAR TRAVELS");
							gotoxy(16,10);
							textattr(15);
							cprintf("NAME : %s",TIC.name);
							gotoxy(51,10);
							cprintf("DATE : %d/%d/%d",TIC.date1,TIC.date2,TIC.date3);
							gotoxy(16,12);
							cprintf("TICKET NUMBER : %d",TIC.ticketno);
							gotoxy(51,12);
							cprintf("TIME : %d:%d",TIC.hh,TIC.mm);
							gotoxy(16,14);
							cprintf("JOURNEY : AHMEDABAD TO %s",TIC.des);
							gotoxy(16,16);
							cprintf("PERSON : %d",TIC.person);
							gotoxy(51,16);
							cprintf("FARE : %0.2f",TIC.fare);
							gotoxy(16,18);
							cprintf("CONTACT NUMBER : %s",TIC.mobile);
							gotoxy(16,20);
							cprintf("MAHASAGAR OFFICE NUMBER : 022-54321, 079-24245");
							getch();
						}
					}
					fclose(fp24);
					filter();
				}
			}
			fclose(fp23);
			p(18,34,140,"DATA NOT FOUND");
			textattr(15);
			getch();
			filter();
			break;
		case'0':
			ticket1();
			break;
		default:
			filter();
	}
}

void search()
{
	FILE *fp25;
	int t, x, avl;
	clrscr();
	title();
	p(25,5,14,"TC");
	gotoxy(8,25);
	cprintf("%c",16);
	p(25,10,14,"MANAGER");
	gotoxy(18,25);
	cprintf("%c",16);
	p(25,20,14,"TICKET");
	gotoxy(27,25);
	cprintf("%c",16);
	p(25,29,14,"SEARCH TICKET");
	p(25,68,14,"0   BACK");
	gotoxy(70,25);
	textattr(14);
	cprintf("%c",26);
	p(12,20,15,"PLEASE ENTER TICKET NO YOU WANT TO SEARCH : ");
	scanf("%d", &t);
	avl = ticket(t);
	if (avl == 0)
	{
		if(t==0)
		{
			ticket1();
		}
		else
		{
			gotoxy(22,14);
			textattr(140);
			cprintf("TICKET NO %d IS NOT AVAILABLE SYSTEM",t);
			textattr(15);
			getch();
			ticket1();
		}
	}
	else
	{
		fp25 = fopen("TICKET", "r");
		while (fread(&TIC, sizeof(TIC), 1, fp25))
		{
			x = TIC.ticketno;
			if (x == t)
			{
				clrscr();
				title();
				p(25,5,14,"TC");
				gotoxy(8,25);
				cprintf("%c",16);
				p(25,10,14,"MANAGER");
				gotoxy(18,25);
				cprintf("%c",16);
				p(25,20,14,"SEARCH TICKET");
				p(25,68,14,"0   BACK");
				gotoxy(70,25);
				textattr(14);
				cprintf("%c",26);
				p(7,11,15," * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
				p(22,11,15," * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
				p(21,12,15,"*");
				p(8,12,15,"*");
				p(9,12,15,"*");
				p(10,12,15,"*");
				p(11,12,15,"*");
				p(12,12,15,"*");
				p(13,12,15,"*");
				p(14,12,15,"*");
				p(15,12,15,"*");
				p(16,12,15,"*");
				p(17,12,15,"*");
				p(18,12,15,"*");
				p(19,12,15,"*");
				p(20,12,15,"*");
				p(21,70,15,"*");
				p(8,70,15,"*");
				p(9,70,15,"*");
				p(10,70,15,"*");
				p(11,70,15,"*");
				p(12,70,15,"*");
				p(13,70,15,"*");
				p(14,70,15,"*");
				p(15,70,15,"*");
				p(16,70,15,"*");
				p(17,70,15,"*");
				p(18,70,15,"*");
				p(19,70,15,"*");
				p(20,70,15,"*");
				p(8,33,13,"MAHASAGAR TRAVELS");
				gotoxy(16,10);
				textattr(15);
				cprintf("NAME : %s",TIC.name);
				gotoxy(51,10);
				cprintf("DATE : %d/%d/%d",TIC.date1,TIC.date2,TIC.date3);
				gotoxy(16,12);
				cprintf("TICKET NUMBER : %d",TIC.ticketno);
				gotoxy(51,12);
				cprintf("TIME : %d:%d",TIC.hh,TIC.mm);
				gotoxy(16,14);
				cprintf("JOURNEY : AHMEDABAD TO %s",TIC.des);
				gotoxy(16,16);
				cprintf("PERSON : %d",TIC.person);
				gotoxy(51,16);
				cprintf("FARE : %0.2f",TIC.fare);
				gotoxy(16,18);
				cprintf("CONTACT NUMBER : %s",TIC.mobile);
				gotoxy(16,20);
				cprintf("MAHASAGAR OFFICE NUMBER : 022-54321, 079-24245");
			}
		}
		fclose(fp25);
		getch();
		ticket1();
	}
}

void update()
{
	FILE  *fp26, *fp27;
	int x, t, avl;
	clrscr();
	title();
	p(25,5,14,"TC");
	gotoxy(8,25);
	cprintf("%c",16);
	p(25,10,14,"MANAGER");
	gotoxy(18,25);
	cprintf("%c",16);
	p(25,20,14,"TICKET");
	gotoxy(27,25);
	cprintf("%c",16);
	p(25,29,14,"UPDATE TICKET");
	p(25,68,14,"0   BACK");
	gotoxy(70,25);
	textattr(14);
	cprintf("%c",26);
	p(10,20,15,"PLEASE ENTER TICKET NO YOU WANT TO UPDATE : ");
	scanf("%d", &t);
	avl = ticket(t);
	if (avl == 0)
	{
		if(t==0)
		{
			ticket1();
		}
		else
		{
			gotoxy(22,12);
			textattr(140);
			cprintf("TICKET NO %d IS NOT AVAILABLE IN SYSTEM", t);
			textattr(15);
			getch();
			ticket1();
		}
	}
	else
	{
		fp27 = fopen("TICKET", "r");
		fp26 = fopen("TEMP1", "w");
		while (fread(&TIC, sizeof(TIC), 1, fp27))
		{
			x = TIC.ticketno;
			if(x != t)
			fwrite(&TIC, sizeof(TIC), 1, fp26);
			else
			{
				gotoxy(25,12);
				textattr(15);
				cprintf("JOURNEY : AHMEDABAD TO %s",TIC.des);
				gotoxy(31,14);
				textattr(15);
				cprintf("OLD NAME : %s",TIC.name);
				gotoxy(21,15);
				cprintf("OLD CONTACT NUMBER : %s",TIC.mobile);
				p(17,31,15,"NEW NAME : ");
				scanf("%s",&TIC.name);
				p(18,21,15,"NEW CONTACT NUMBER : ");
				scanf("%s",&TIC.mobile);

				if(strlen(TIC.mobile)==10)
				{
				if(strcmp(TIC.name,"A")>=0 && strcmp(TIC.name,"Z")<=0)
				{
				if(strcmp(TIC.mobile,"0")>=0 && strcmp(TIC.mobile,"9999999999")<=0)
				{
					fwrite(&TIC, sizeof(TIC), 1, fp26);

				}
				else
				{
					fclose(fp27);
					fclose(fp26);
					p(20,26,140,"CONTACT NUMBER IS NOT VALID");
					textattr(15);
					getch();
					ticket1();
				}
				}
				else
				{
					fclose(fp27);
					fclose(fp26);
					p(20,33,140,"NAME IS NOT VALID");
					textattr(15);
					getch();
					ticket1();
				}
				}
				else
				{
					fclose(fp27);
					fclose(fp26);
					p(20,26,140,"CONTACT NUMBER IS NOT VALID");
					textattr(15);
					getch();
					ticket1();
				}
			}
		}
		fclose(fp27);
		fclose(fp26);
		fp27 = fopen("TICKET", "w");
		fp26 = fopen("TEMP1", "r");
		while (fread(&TIC, sizeof(TIC), 1, fp26))
		{
			fwrite(&TIC, sizeof(TIC), 1, fp27);
		}
		fclose(fp27);
		fclose(fp26);
		p(20,34,10,"TICKET UPDATED");
		textattr(15);
		getch();
		ticket1();
	}
}

void delet()
{
	FILE *fp28, *fp29, *fp30, *fp31, *fp32, *fp33;
	int t, x, z, A;
	char ch[25];
	clrscr();
	title();
	p(25,5,14,"TC");
	gotoxy(8,25);
	cprintf("%c",16);
	p(25,10,14,"MANAGER");
	gotoxy(18,25);
	cprintf("%c",16);
	p(25,20,14,"TICKET");
	gotoxy(27,25);
	cprintf("%c",16);
	p(25,29,14,"DELETE TICKET");
	p(25,68,14,"0   BACK");
	gotoxy(70,25);
	textattr(14);
	cprintf("%c",26);
	p(12,20,15,"PLEASE ENTER TICKET NO YOU WANT TO DELETE : ");
	scanf("%d", &t);
	if (ticket(t) == 0)
	{
		if(t==0)
		{
			ticket1();
		}
		else
		{
			gotoxy(22,14);
			textattr(140);
			cprintf("TICKET NO %d IS NOT AVAILABLE IN SYSTEM", t);
			textattr(15);
			getch();
			ticket1();
		}
	}
	else
	{
		fp30 = fopen("TICKET", "r");
		while (fread(&TIC, sizeof(TIC), 1, fp30))
		{
			x = TIC.ticketno;
			if (x == t)
			{
				clrscr();
				title();
				p(25,5,14,"TC");
				gotoxy(8,25);
				cprintf("%c",16);
				p(25,10,14,"MANAGER");
				gotoxy(18,25);
				cprintf("%c",16);
				p(25,20,14,"TICKET");
				gotoxy(27,25);
				cprintf("%c",16);
				p(25,29,14,"DELETE TICKET");
				p(6,11,15," * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
				p(21,11,15," * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
				p(7,12,15,"*");
				p(8,12,15,"*");
				p(9,12,15,"*");
				p(10,12,15,"*");
				p(11,12,15,"*");
				p(12,12,15,"*");
				p(13,12,15,"*");
				p(14,12,15,"*");
				p(15,12,15,"*");
				p(16,12,15,"*");
				p(17,12,15,"*");
				p(18,12,15,"*");
				p(19,12,15,"*");
				p(20,12,15,"*");
				p(7,70,15,"*");
				p(8,70,15,"*");
				p(9,70,15,"*");
				p(10,70,15,"*");
				p(11,70,15,"*");
				p(12,70,15,"*");
				p(13,70,15,"*");
				p(14,70,15,"*");
				p(15,70,15,"*");
				p(16,70,15,"*");
				p(17,70,15,"*");
				p(18,70,15,"*");
				p(19,70,15,"*");
				p(20,70,15,"*");
				p(7,33,13,"MAHASAGAR TRAVELS");
				gotoxy(16,9);
				textattr(15);
				cprintf("NAME : %s",TIC.name);
				gotoxy(51,9);
				cprintf("DATE : %d/%d/%d",TIC.date1,TIC.date2,TIC.date3);
				gotoxy(16,11);
				cprintf("TICKET NUMBER : %d",TIC.ticketno);
				gotoxy(51,11);
				cprintf("TIME : %d:%d",TIC.hh,TIC.mm);
				gotoxy(16,13);
				cprintf("JOURNEY : AHMEDABAD TO %s",TIC.des);
				gotoxy(16,15);
				cprintf("PERSON : %d",TIC.person);
				gotoxy(51,15);
				cprintf("FARE : %0.2f",TIC.fare);
				gotoxy(16,17);
				cprintf("CONTACT NUMBER : %s",TIC.mobile);
				gotoxy(16,19);
				cprintf("MAHASAGAR OFFICE NUMBER : 022-54321, 079-24245");
				p(23,20,15,"DO YOU WANT TO DELETE THIS TICKET (YES/NO) : ");
				fflush(stdin);
				scanf("%s",&ch);
				if(strcmp(ch,"YES")==0)
				{
			       /* 	fp = fopen("BUS", "r+");
					while (fread(&BUS, sizeof(BUS), 1, fp))
					{
						if((strcmp(BUS.busd,TIC.des)==0) && (TIC.hh==BUS.hh && BUS.mm==TIC.mm) && (BUS.date1==TIC.date1 && BUS.date2==TIC.date2 && BUS.date3==TIC.date3))
						{
							BUS.seat = BUS.seat + TIC.person;
							fseek(fp, (-1L)*sizeof(BUS), 1);
							fwrite(&BUS, sizeof(BUS), 1, fp);
							break;
						}
					}
					fclose(fp);     */
					fp33 = fopen("BUS","r");
					while (fread(&BUS, sizeof(BUS), 1, fp33))
					{
						if((strcmp(BUS.busd,TIC.des)==0) && (TIC.hh==BUS.hh && BUS.mm==TIC.mm) && (BUS.date1==TIC.date1 && BUS.date2==TIC.date2 && BUS.date3==TIC.date3))
						{
							fflush(stdin);
							A=BUS.no;
							fclose(fp33);
						}
					}
					fp32 = fopen("BUS", "r");
					fp31 = fopen("TEMP", "w");
					while (fread(&BUS, sizeof(BUS), 1, fp32))
					{
						z = BUS.no;
						if(z != A)
						fwrite(&BUS, sizeof(BUS), 1, fp31);
						else
						{
							fflush(stdin);
							BUS.seat = BUS.seat + TIC.person;
							fwrite(&BUS, sizeof(BUS), 1, fp31);
						}
					}
					fclose(fp32);
					fclose(fp31);
					fp32 = fopen("BUS", "w");
					fp31 = fopen("TEMP", "r");
					while (fread(&BUS, sizeof(BUS), 1, fp31))
					{
						fwrite(&BUS, sizeof(BUS), 1, fp32);
					}
					fclose(fp32);
					fclose(fp31);

					fp28 = fopen("TICKET", "r");
					fp29 = fopen("TEMP1", "w");
					while (fread(&TIC, sizeof(TIC), 1, fp28))
					{
						x = TIC.ticketno;
						if (x != t)
						fwrite(&TIC, sizeof(TIC), 1, fp29);
					}
					fclose(fp28);
					fclose(fp29);
					fp28 = fopen("TICKET", "w");
					fp29 = fopen("TEMP1", "r");
					while (fread(&TIC, sizeof(TIC), 1, fp29))
					fwrite(&TIC, sizeof(TIC), 1, fp28);
					p(23,10,15,"                                                                              ");
					p(23,34,10,"TICKET DELETED");
					p(25,68,14,"0   BACK");
					gotoxy(70,25);
					textattr(14);
					cprintf("%c",26);
					textattr(15);
					fclose(fp28);
					fclose(fp29);
					textattr(15);
					getch();
					ticket1();
				}
				else
				{
					ticket1();
				}
			}
		}
		fclose(fp30);
	}
}

void ongoing()
{
	FILE *fp34, *fp35, *fp36, *fp37, *fp38, *fp39, *fp40, *fp41;
	int j=10, x, z, w, l=0;
	char a[25],ch[25];
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	clrscr();
	title();
	p(25,5,14,"TC");
	gotoxy(8,25);
	cprintf("%c",16);
	p(25,10,14,"MANAGER");
	gotoxy(18,25);
	cprintf("%c",16);
	p(25,20,14,"ONGOING BUS");
	gotoxy(27,12);
	textattr(15);
	cprintf("CURRENT DATE : %d/%d/%d",tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
	p(14,27,15,"BUS LOCATION : AHMEDABAD");
	p(16,24,15,"BUS DESTINATION : ");
	fflush(stdin);
	scanf("%s",&a);
	fp34 = fopen("TICKET", "r");
	while (fread(&TIC, sizeof(TIC), 1, fp34))
	{
		if((strcmp(a,TIC.des)==0) && (tm.tm_mday==TIC.date1 && tm.tm_mon+1==TIC.date2 && tm.tm_year + 1900))
		{
			fclose(fp34);
			clrscr();
			title();
			p(25,5,14,"TC");
			gotoxy(8,25);
			cprintf("%c",16);
			p(25,10,14,"MANAGER");
			gotoxy(18,25);
			cprintf("%c",16);
			p(25,20,14,"ONGOING BUS");
			p(6,3,13,"BUS ROUTE : ");
			textattr(15);
			cprintf("AHMEDABAD TO %s",TIC.des);
			p(6,47,13,"TIME : ");
			textattr(15);
			cprintf("%d:%d",TIC.hh,TIC.mm);
			p(6,62,13,"DATE : ");
			textattr(15);
			cprintf("%d/%d/%d",TIC.date1,TIC.date2,TIC.date3);
			box1(7,1,9,80,7);
			box1(7,1,22,6,7);
			box1(7,6,22,45,7);
			box1(7,45,22,54,7);
			box1(7,54,22,67,7);
			box1(7,67,22,80,7);
			p(8,3,15,"T");
			p(8,15,15,"PASSENGER NAME");
			p(8,47,15,"PERSON");
			p(8,59,15,"SEAT");
			p(8,69,15,"CONTACT NO");
			fp35 = fopen("TICKET", "r");
			gotoxy(6,7);
			textattr(7);
			cprintf("%c",194);
			gotoxy(45,7);
			cprintf("%c",194);
			gotoxy(54,7);
			cprintf("%c",194);
			gotoxy(67,7);
			cprintf("%c",194);
			gotoxy(6,9);
			cprintf("%c",197);
			gotoxy(45,9);
			cprintf("%c",197);
			gotoxy(54,9);
			cprintf("%c",197);
			gotoxy(67,9);
			cprintf("%c",197);
			gotoxy(6,22);
			cprintf("%c",193);
			gotoxy(45,22);
			cprintf("%c",193);
			gotoxy(54,22);
			cprintf("%c",193);
			gotoxy(67,22);
			cprintf("%c",193);
			gotoxy(1,9);
			cprintf("%c",195);
			gotoxy(80,9);
			cprintf("%c",180);
			textattr(15);
			while (fread(&TIC, sizeof(TIC), 1, fp35))
			{
				if((strcmp(a,TIC.des)==0) && (tm.tm_mday==TIC.date1 && tm.tm_mon+1==TIC.date2 && tm.tm_year + 1900))
				{
					gotoxy(3,j);
					cprintf("%d",TIC.ticketno);
					gotoxy(10,j);
					cprintf("%s",TIC.name);
					gotoxy(49,j);
					cprintf("%d",TIC.person);
					gotoxy(69,j);
					cprintf("%s",TIC.mobile);
					if(TIC.person==1)
					{
						l=l+1;
						gotoxy(56,j);
						cprintf("S%d",l);
					}
					if(TIC.person==2)
					{
						l=l+1;
						gotoxy(56,j);
						cprintf("S%d, ",l);
						l=l+1;
						cprintf("S%d",l);
					}
					if(TIC.person==3)
					{
						l=l+1;
						gotoxy(56,j);
						cprintf("S%d TO ",l);
						l=l+2;
						cprintf("S%d",l);
					}
					if(TIC.person==4)
					{
						l=l+1;
						gotoxy(56,j);
						cprintf("S%d TO ",l);
						l=l+3;
						cprintf("S%d",l);
					}
					if(TIC.person==5)
					{
						l=l+1;
						gotoxy(56,j);
						cprintf("S%d TO ",l);
						l=l+4;
						cprintf("S%d",l);
					}
					if(TIC.person==6)
					{
						l=l+1;
						gotoxy(56,j);
						cprintf("S%d TO ",l);
						l=l+5;
						cprintf("S%d",l);
					}
					if(TIC.person==7)
					{
						l=l+1;
						gotoxy(56,j);
						cprintf("S%d TO ",l);
						l=l+6;
						cprintf("S%d",l);
					}
					if(TIC.person==8)
					{
						l=l+1;
						gotoxy(56,j);
						cprintf("S%d TO ",l);
						l=l+7;
						cprintf("S%d",l);
					}
					if(TIC.person==9)
					{
						l=l+1;
						gotoxy(56,j);
						cprintf("S%d TO ",l);
						l=l+8;
						cprintf("S%d",l);
					}
					if(TIC.person==10)
					{
						l=l+1;
						gotoxy(56,j);
						cprintf("S%d TO ",l);
						l=l+9;
						cprintf("S%d",l);
					}
					j = j + 1;
				}
			}
			fclose(fp35);
			p(23,22,15,"BUS IS READY TO JOURNEY (YES/NO) : ");
			fflush(stdin);
			scanf("%s",&ch);
			if(strcmp(ch,"YES")==0)
			{
				fp36 = fopen("TICKET", "r");
				while (fread(&TIC, sizeof(TIC), 1, fp36))
				{
					if((strcmp(a,TIC.des)==0) && (tm.tm_mday==TIC.date1 && tm.tm_mon+1==TIC.date2 && tm.tm_year+1900==TIC.date3))
					{
						z = TIC.ticketno;
						fp37 = fopen("TICKET", "r");
						fp38 = fopen("TEMP1", "w");
						while (fread(&TIC, sizeof(TIC), 1, fp37))
						{
							x = TIC.ticketno;
							if (x != z)
							fwrite(&TIC, sizeof(TIC), 1, fp38);
						}
						fclose(fp37);
						fclose(fp38);
						fp37 = fopen("TICKET", "w");
						fp38 = fopen("TEMP1", "r");
						while (fread(&TIC, sizeof(TIC), 1, fp38))
						fwrite(&TIC, sizeof(TIC), 1, fp37);
						fclose(fp37);
						fclose(fp38);
						textattr(15);
					}
				}
				fclose(fp36);

				fp39 = fopen("BUS", "r");
				while (fread(&BUS, sizeof(BUS), 1, fp39))
				{
					if((strcmp(a,BUS.busd)==0) && (tm.tm_mday==BUS.date1 && tm.tm_mon+1==BUS.date2 && tm.tm_year+1900==BUS.date3))
					{
						w = BUS.no;
						fp40 = fopen("BUS", "r");
						fp41 = fopen("TEMP", "w");
						while (fread(&BUS, sizeof(BUS), 1, fp40))
						{
							x = BUS.no;
							if (x != w)
							fwrite(&BUS, sizeof(BUS), 1, fp41);
						}
						fclose(fp40);
						fclose(fp41);
						fp40 = fopen("BUS", "w");
						fp41 = fopen("TEMP", "r");
						while (fread(&BUS, sizeof(BUS), 1, fp41))
						fwrite(&BUS, sizeof(BUS), 1, fp40);
						textattr(15);
						fclose(fp40);
						fclose(fp41);
					}
				}
				fclose(fp39);

				p(23,20,15,"                                                                    ");
				p(23,30,10,"BUS GONE SUCCESSFULLY");
				p(25,68,14,"0   BACK");
				gotoxy(70,25);
				textattr(14);
				cprintf("%c",26);
				textattr(15);
				getch();
				manager();
			}
			else
			{
				manager();
			}
		}
	}
	p(18,29,140,"THIS BUS IS NOT RESERVED");
	textattr(15);
	getch();
	fclose(fp34);
	manager();
}

void msmessage()
{
	FILE *fp42, *fp43, *fp44;
	char ch[25];
	clrscr();
	title();
	p(25,5,14,"TC");
	gotoxy(8,25);
	cprintf("%c",16);
	p(25,10,14,"MANAGER");
	gotoxy(18,25);
	cprintf("%c",16);
	p(25,20,14,"MESSAGE");
	gotoxy(28,25);
	cprintf("%c",16);
	p(25,30,14,"SEND MESSAGE");
	p(6,20,15,"DO YOU WANT TO SEND NEW MESSAGE (YES/NO) : ");
	fflush(stdin);
	scanf("%s",&ch);
	if(strcmp(ch,"YES")==0)
	{
		fp43 = fopen("MESSAGE","r");
		fread(&MSG, sizeof(MSG),1,fp43);
		while(!feof(fp43))
		{
			fread(&MSG, sizeof(MSG),1,fp43);
		}
		MSG.no = MSG.no+1;
		fclose(fp43);

		fp42 = fopen("MESSAGE","a");
		gotoxy(25,8);
		textattr(11);
		cprintf("MESSAGE NUMBER : %d",MSG.no);
		p(10,27,15,"BUS LOCATION : AHMEDABAD");
		p(12,24,15,"BUS DESTINATION : ");
		scanf("%s",&MSG.des);
		p(14,22,15,"DATE (DD/MM/YYYY) : ");
		scanf("%d/%d/%d",&MSG.d1,&MSG.d2,&MSG.d3);

		fp44 = fopen("BUS","r");
		while (fread(&BUS, sizeof(BUS), 1, fp44))
		{
			if((strcmp(MSG.des,BUS.busd)==0) && (BUS.date1==MSG.d1 && BUS.date2==MSG.d2 && BUS.date3==MSG.d3))
			{
				gotoxy(31,16);
				textattr(15);
				cprintf("BUS TIME : %d:%d",BUS.hh,BUS.mm);
				p(18,31,15,"NEW TIME : ");
				scanf("%d:%d",&MSG.hh1,&MSG.mm1);
				p(20,33,15,"REASON : ");
				fflush(stdin);
				gets(MSG.reason);
				if((MSG.hh1<=23 && MSG.hh1>=0) && (MSG.mm1<=59 && MSG.mm1>=0))
				{
				if(strlen(MSG.reason)<=13)
				{
					fflush(stdin);
					fwrite(&MSG, sizeof(MSG), 1, fp42);
					fclose(fp42);
					fclose(fp44);
					p(25,68,14,"0   BACK");
					gotoxy(70,25);
					textattr(14);
					cprintf("%c",26);
					p(22,28,10,"MESSAGE SENT SUCCESSFULLY");
					textattr(15);
					getch();
					message1();
					break;
				}
				else
				{
					p(22,31,140,"REASON IS TOO LONG");
					textattr(15);
					fclose(fp42);
					getch();
					message1();
				}
				}
				else
				{
					p(22,30,140,"NEW TIME IS NOT VALID");
					textattr(15);
					fclose(fp42);
					getch();
					message1();
				}
			}
		}
		fclose(fp44);
		p(25,68,14,"0   BACK");
		gotoxy(70,25);
		textattr(14);
		cprintf("%c",26);
		p(14,31,140,"BUS ROUTE IS NOT VALID");
		textattr(15);
		getch();
		message1();
	}
	if(strcmp(ch,"NO")==0)
	{
		message1();
	}
	else
	{
		p(8,33,140,"PLEASE TRY AGAIN");
		textattr(15);
		getch();
		msmessage();
	}
}

void mvmessage()
{
	FILE *fp45;
	int j=10;
	clrscr();
	title();
	p(25,5,14,"TC");
	gotoxy(8,25);
	cprintf("%c",16);
	p(25,10,14,"MANAGER");
	gotoxy(18,25);
	cprintf("%c",16);
	p(25,20,14,"MESSAGE");
	gotoxy(28,25);
	cprintf("%c",16);
	p(25,30,14,"VIEW MESSAGE");
	p(25,68,14,"0   BACK");
	gotoxy(70,25);
	textattr(14);
	cprintf("%c",26);
	fp45 = fopen("MESSAGE", "r");
	while (fread(&MSG, sizeof(MSG), 1, fp45))
	{
		gotoxy(5,j);
		textattr(15);
		cprintf("%d",MSG.no);
		gotoxy(10,j);
		cprintf("AHMEDABAD TO %s",MSG.des);
		gotoxy(40,j);
		cprintf("%d/%d/%d",MSG.d1, MSG.d2, MSG.d3);
		gotoxy(52,j);
		cprintf("%d:%d",MSG.hh1,MSG.mm1);
		gotoxy(59,j);
		cprintf("%s",MSG.reason);
		j = j+1;
	}
	fclose(fp45);
	box1(6,3,8,78,7);
	box1(6,3,23,8,7);
	box1(6,8,23,39,7);
	box1(6,39,23,50,7);
	box1(6,50,23,57,7);
	box1(6,57,23,78,7);
	p(7,5,15,"NO");
	p(7,15,15,"BUS ROUTE");
	p(7,43,15,"DATE");
	p(7,52,15,"TIME");
	p(7,63,15,"REASON");
	gotoxy(3,8);
	textattr(7);
	cprintf("%c",195);
	gotoxy(78,8);
	cprintf("%c",180);
	gotoxy(8,6);
	cprintf("%c",194);
	gotoxy(39,6);
	cprintf("%c",194);
	gotoxy(50,6);
	cprintf("%c",194);
	gotoxy(57,6);
	cprintf("%c",194);
	gotoxy(8,8);
	cprintf("%c",197);
	gotoxy(39,8);
	cprintf("%c",197);
	gotoxy(50,8);
	cprintf("%c",197);
	gotoxy(57,8);
	cprintf("%c",197);
	gotoxy(8,23);
	cprintf("%c",193);
	gotoxy(39,23);
	cprintf("%c",193);
	gotoxy(50,23);
	cprintf("%c",193);
	gotoxy(57,23);
	cprintf("%c",193);
	textattr(15);
	getch();
	message1();
}

void mdmessage()
{
	FILE *fp46, *fp47, *fp48;
	int t, x;
	char ch[25];
	clrscr();
	title();
	p(25,5,14,"TC");
	gotoxy(8,25);
	cprintf("%c",16);
	p(25,10,14,"MANAGER");
	gotoxy(18,25);
	cprintf("%c",16);
	p(25,20,14,"MESSAGE");
	gotoxy(28,25);
	cprintf("%c",16);
	p(25,30,14,"DELETE MESSAGE");
	p(25,68,14,"0   BACK");
	gotoxy(70,25);
	textattr(14);
	cprintf("%c",26);
	p(8,17,15,"PLEASE ENTER MESSAGE NO YOU WANT TO DELETE : ");
	scanf("%d", &t);
	if (message(t) == 0)
	{
		if(t==0)
		{
			message1();
		}
		else
		{
			gotoxy(20,10);
			textattr(140);
			cprintf("MESSAGE NO %d IS NOT AVAILABLE IN SYSTEM",t);
			textattr(15);
			getch();
			message1();
		}
	}
	else
	{
		fp48 = fopen("MESSAGE", "r");
		while (fread(&MSG, sizeof(MSG), 1, fp48))
		{
			x = MSG.no;
			if (x == t)
			{
				box(10,20,17,60,7);
				gotoxy(23,12);
				textattr(15);
				cprintf("BUS ROUTE : AHMEDABAD TO %s",MSG.des);
				gotoxy(23,13);
				cprintf("DATE : %d/%d/%d",MSG.d1, MSG.d2, MSG.d3);
				gotoxy(23,14);
				cprintf("TIME : %d:%d",MSG.hh1,MSG.mm1);
				gotoxy(23,15);
				cprintf("REASON : %s",MSG.reason);
				p(19,17,15,"DO YOU WANT TO DELETE THIS MESSAGE (YES/NO) : ");
				fflush(stdin);
				scanf("%s",&ch);
				if(strcmp(ch,"YES")==0)
				{
					fp46 = fopen("MESSAGE", "r");
					fp47 = fopen("TEMP2", "w");
					while (fread(&MSG, sizeof(MSG), 1, fp46))
					{
						x = MSG.no;
						if (x != t)
						fwrite(&MSG, sizeof(MSG), 1, fp47);
					}
					fclose(fp46);
					fclose(fp47);
					fp46 = fopen("MESSAGE", "w");
					fp47 = fopen("TEMP2", "r");
					while (fread(&MSG, sizeof(MSG), 1, fp47))
					fwrite(&MSG, sizeof(MSG), 1, fp46);
					fclose(fp46);
					fclose(fp47);
					p(21,34,10,"MESSAGE DELETED");
					textattr(15);
					getch();
					message1();
				}
				else
				{
					message1();
				}
			}
		}
		fclose(fp48);
	}
}

void inquiry()
{
	FILE *fp49;
	int d1, d2, d3;
	char inq[25];
	clrscr();
	title();
	p(25,5,14,"TC");
	gotoxy(8,25);
	cprintf("%c",16);
	p(25,10,14,"CUSTOMER");
	gotoxy(19,25);
	cprintf("%c",16);
	p(25,21,14,"INQUIRY");
	p(12,31,15,"LOCATION : AHMEDABAD");
	p(14,28,15,"DESTINATION : ");
	scanf("%s", &inq);
	p(16,14,15,"JOURNEY DATE (DD/MM/YYYY) : ");
	scanf("%d/%d/%d",&d1,&d2,&d3);
	fp49 = fopen("BUS", "r");
	while (fread(&BUS, sizeof(BUS), 1, fp49))
	{
		if((strcmp(inq,BUS.busd)==0) && (BUS.date1==d1 && BUS.date2==d2 && BUS.date3==d3))
		{
			clrscr();
			title();
			p(25,5,14,"TC");
			gotoxy(8,25);
			cprintf("%c",16);
			p(25,10,14,"CUSTOMER");
			gotoxy(19,25);
			cprintf("%c",16);
			p(25,21,14,"INQUIRY");
			p(25,68,14,"0   BACK");
			gotoxy(70,25);
			textattr(14);
			cprintf("%c",26);
			p(7,37,15,"ABD-");
			cprintf("%s",inq);
			gotoxy(44,7);
			cprintf("                 ");
			box(9,20,23,60,7);
			gotoxy(24,11);
			textattr(15);
			cprintf("BUS ROUTE : AHMEDABAD TO %s",BUS.busd);
			gotoxy(24,13);
			cprintf("ABD TIME : %d:%d",BUS.hh,BUS.mm);
			gotoxy(24,15);
			cprintf("DATE : %d/%d/%d",d1,d2,d3);
			gotoxy(24,17);
			cprintf("TYPE : %s",BUS.type);
			gotoxy(24,19);
			cprintf("FARE : %0.2f (PER PERSON)",BUS.fare);
			gotoxy(24,21);
			cprintf("SEAT : %d AVAILABLE NOW",BUS.seat);
			fclose(fp49);
			getch();
			customer();
		}
	}
	p(18,35,140,"BUS NOT FOUND");
	textattr(15);
	fclose(fp49);
	getch();
	customer();
}

void reservation()
{
	FILE *fp50, *fp51, *fp52, *fp53, *fp54;
	char ch[10];
	int s, x, z, A;
	fp52 = fopen("TICKET","r");
	fread(&TIC, sizeof(TIC),1,fp52);
	while(!feof(fp52))
	{
		fread(&TIC, sizeof(TIC),1,fp52);
	}
	TIC.ticketno = TIC.ticketno+1;
	fclose(fp52);
	clrscr();
	title();
	p(25,5,14,"TC");
	gotoxy(8,25);
	cprintf("%c",16);
	p(25,10,14,"CUSTOMER");
	gotoxy(19,25);
	cprintf("%c",16);
	p(25,21,14,"RESERVATION");
	p(6,25,15,"DO YOU HAVE INQUIRY (YES/NO) : ");
	scanf("%s",&ch);
	if(strcmp(ch,"NO")==0)
	{
		customer();
	}
	if(strcmp(ch,"YES")==0)
	{
	fp51 = fopen("TICKET","a");
	textattr(15);
	p(8,35,15,"NAME : ");
	scanf("%s",TIC.name);
	p(10,14,15,"JOURNEY DATE (DD/MM/YYYY) : ");
	scanf("%d/%d/%d",&TIC.date1,&TIC.date2,&TIC.date3);
	p(12,23,15,"JOURNEY LOCATION : AHMEDABAD");
	p(14,20,15,"JOURNEY DESTINATION : ");
	scanf("%s",&TIC.des);
	p(16,27,15,"TIME (HH:MM) : ");
	scanf("%d:%d",&TIC.hh,&TIC.mm);
	p(18,24,15,"PERSON (MAX 10) : ");
	scanf("%d",&TIC.person);
	p(20,25,15,"CONTACT NUMBER : ");
	scanf("%s",&TIC.mobile);
	if(strlen(TIC.name)>=2)
	{
	if(strlen(TIC.mobile)==10)
	{
	if(strcmp(TIC.name,"A")>=0 && strcmp(TIC.name,"Z")<=0)
	{
	if(strcmp(TIC.mobile,"1")>=0 && strcmp(TIC.mobile,"9999999999")<=0)
	{
	if(TIC.person>=1 && TIC.person<=10)
	{
	fp50 = fopen("BUS","r");
	while (fread(&BUS, sizeof(BUS), 1, fp50))
	{
		if((strcmp(BUS.busd,TIC.des)==0) && (TIC.hh==BUS.hh && BUS.mm==TIC.mm) && (BUS.date1==TIC.date1 && BUS.date2==TIC.date2 && BUS.date3==TIC.date3))
		{
			fflush(stdin);
			TIC.fare = (TIC.person * BUS.fare);
			A=BUS.no;
			fclose(fp50);
		fp54 = fopen("BUS", "r");
		fp53 = fopen("TEMP", "w");
		while (fread(&BUS, sizeof(BUS), 1, fp54))
		{
			z = BUS.no;
			if(z != A)
			fwrite(&BUS, sizeof(BUS), 1, fp53);
			else
			{
				if(BUS.seat>=TIC.person)
				{
					fflush(stdin);
					BUS.seat = BUS.seat - TIC.person;
					fwrite(&BUS, sizeof(BUS), 1, fp53);
				}
				else
				{
					p(22,37,140,"BUS FULL");
					textattr(15);
					getch();
					customer();
				}
			}
		}
		fclose(fp54);
		fclose(fp53);
		fp54 = fopen("BUS", "w");
		fp53 = fopen("TEMP", "r");
		while (fread(&BUS, sizeof(BUS), 1, fp53))
		{
			fwrite(&BUS, sizeof(BUS), 1, fp54);
		}
		fclose(fp54);
		fclose(fp53);

		p(22,29,10,"RESERVATION SUCCESSFULLY");
		fflush(stdin);
		fwrite(&TIC, sizeof(TIC), 1, fp51);
		fclose(fp51);
		getch();
		clrscr();
		title();
		p(25,5,14,"TC");
		gotoxy(8,25);
		cprintf("%c",16);
		p(25,10,14,"CUSTOMER");
		gotoxy(19,25);
		cprintf("%c",16);
		p(25,21,14,"RESERVATION");
		gotoxy(33,25);
		cprintf("%c",16);
		p(25,35,14,"TICKET");
		p(6,11,15," * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
		p(21,11,15," * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
		p(7,12,15,"*");
		p(8,12,15,"*");
		p(9,12,15,"*");
		p(10,12,15,"*");
		p(11,12,15,"*");
		p(12,12,15,"*");
		p(13,12,15,"*");
		p(14,12,15,"*");
		p(15,12,15,"*");
		p(16,12,15,"*");
		p(17,12,15,"*");
		p(18,12,15,"*");
		p(19,12,15,"*");
		p(20,12,15,"*");
		p(7,70,15,"*");
		p(8,70,15,"*");
		p(9,70,15,"*");
		p(10,70,15,"*");
		p(11,70,15,"*");
		p(12,70,15,"*");
		p(13,70,15,"*");
		p(14,70,15,"*");
		p(15,70,15,"*");
		p(16,70,15,"*");
		p(17,70,15,"*");
		p(18,70,15,"*");
		p(19,70,15,"*");
		p(20,70,15,"*");
		p(7,33,13,"MAHASAGAR TRAVELS");
		gotoxy(16,9);
		textattr(15);
		cprintf("NAME : %s",TIC.name);
		gotoxy(51,9);
		cprintf("DATE : %d/%d/%d",TIC.date1,TIC.date2,TIC.date3);
		gotoxy(16,11);
		cprintf("TICKET NUMBER : %d",TIC.ticketno);
		gotoxy(51,11);
		cprintf("TIME : %d:%d",TIC.hh,TIC.mm);
		gotoxy(16,13);
		cprintf("JOURNEY : AHMEDABAD TO %s",TIC.des);
		gotoxy(16,15);
		cprintf("PERSON : %d",TIC.person);
		gotoxy(51,15);
		cprintf("FARE : %0.2f",TIC.fare);
		gotoxy(16,17);
		cprintf("CONTACT NUMBER : %s",TIC.mobile);
		gotoxy(16,19);
		cprintf("MAHASAGAR OFFICE NUMBER : 022-54321, 079-24245");
		p(23,20,15,"THANK YOU FOR JOURNEY TO MAHASAGAR TRAVELS");
		getch();
		payment();
		}
	}
	fclose(fp50);
	fclose(fp51);
	p(22,28,140,"JOURNEY ROUTE IS NOT VALID");
	textattr(15);
	getch();
	customer();
	}
	else
	{
		if(TIC.person>=11)
		{
			p(22,25,140,"MORE THAN 10 PERSON IS NOT VALID");
			textattr(15);
			fclose(fp51);
			getch();
			customer();
		}
		else
		{
			p(22,25,140,"LESS THAN 1 PERSON IS NOT VALID");
			textattr(15);
			fclose(fp51);
			getch();
			customer();
		}
	}
	}
	else
	{
		p(22,26,140,"CONTACT NUMBER IS NOT VALID");
		textattr(15);
		fclose(fp51);
		getch();
		customer();
	}
	}
	else
	{
		p(22,33,140,"NAME IS NOT VALID");
		textattr(15);
		fclose(fp51);
		getch();
		customer();
	}
	}
	else
	{
		p(22,26,140,"CONTACT NUMBER IS NOT VALID");
		textattr(15);
		fclose(fp51);
		getch();
		customer();
	}
	}
	else
	{
		p(22,33,140,"NAME IS NOT VALID");
		textattr(15);
		fclose(fp51);
		getch();
		customer();
	}
	}
	else
	{
		p(8,33,140,"PLEASE TRY AGAIN");
		textattr(15);
		getch();
		reservation();
	}
}

void payment()
{
	FILE *fp55;
	int k=0, i;
	char pass[25], c;
	char ch[50],card[50],pin[50];
	clrscr();
	title();
	p(25,5,14,"TC");
	gotoxy(8,25);
	cprintf("%c",16);
	p(25,10,14,"CUSTOMER");
	gotoxy(19,25);
	cprintf("%c",16);
	p(25,21,14,"RESERVATION");
	gotoxy(33,25);
	cprintf("%c",16);
	p(25,35,14,"TICKET");
	gotoxy(42,25);
	cprintf("%c",16);
	p(25,44,14,"PAYMENT");
	fp55 = fopen("TICKET","r");
	fread(&TIC, sizeof(TIC),1,fp55);
	while(!feof(fp55))
	{
		fread(&TIC, sizeof(TIC),1,fp55);
	}
	p(6,13,15,"PAYMENT METHOD (CASH/CARD) : ");
	fflush(stdin);
	scanf("%s",&ch);
	if(strcmp(ch,"CASH")==0)
	{
		p(8,22,11,"THANK YOU FOR USING CASH PAYMENT");
		box(10,20,17,61,7);
		p(11,33,13,"MAHASAGAR OFFICE");
		p(13,23,15,"ADDRESS : 3/MAHASAGAR TRAVELS");
		p(14,33,15,"NEAR NH-8, TB NAGAR ROAD");
		p(15,33,15,"BAPUNAGAR, AHMEDABAD(382350)");
		p(16,23,15,"CONTACT : 022-54321, 079-24245");
		p(19,24,15,"PLEASE PAYMENT TO MAHASAGAR OFFICE");
		p(21,30,15,"PASSWORD : ");
		fflush(stdin);
		while(1)
		{
			c=getch();
			if(c=='\b' && k>0)
			{
				k--;
				printf("\b");
				printf(" ");
				printf("\b");
				continue;
			}
			if(c=='\r')
			break;
			if(c!='\b')
			{
				pass[k]=c;
				printf("*");
				k++;
			}
		}
		pass[k]='\0';
		if(strcmp(pass,"PAYMENT")==0)
		{
			p(25,68,14,"0   BACK");
			gotoxy(70,25);
			textattr(14);
			cprintf("%c",26);
			p(23,31,10,"PAYMENT SUCCESSFULLY");
			textattr(15);
			getch();
			customer();
		}
		else
		{
			p(23,28,140,"PASSWORD IS NOT VALID");
			textattr(15);
			getch();
			payment();
		}
	}
	if(strcmp(ch,"CARD")==0)
	{
		p(8,22,11,"THANK YOU FOR USING CARD PAYMENT");
		p(10,28,15,"CARD NUMBER : ");
		scanf("%s",&card);
		p(12,36,15,"PIN : ");
		while(1)
		{
			c=getch();
			if(c=='\b' && k>0)
			{
				k--;
				printf("\b");
				printf(" ");
				printf("\b");
				continue;
			}
			if(c=='\r')
			break;
			if(c!='\b')
			{
				pin[k]=c;
				printf("*");
				k++;
			}
		}
		pin[k]='\0';

		if(strlen(card)==16)
		{
		if(strlen(pin)==4)
		{
		if(strcmp(card,"1")>=0 && strcmp(card,"9999999999999999")<=0)
		{
		if(strcmp(pin,"1")>=0 && strcmp(pin,"9999")<=0)
		{
			box1(15,3,21,25,13);
			box1(15,55,21,78,13);
			gotoxy(11,16);
			textattr(15);
			cprintf("%s",TIC.name);
			p(18,5,11,"STATE BANK OF INDIA");
			gotoxy(7,20);
			textattr(15);
			cprintf("%s",card);
			p(20,7,15,"XXXXXXXXXXXX");
			p(16,58,15,"MAHASAGAR TRAVELS");
			p(18,62,11,"HDFC BANK");
			p(20,59,15,"XXXXXXXXXXXX9876");
			p(16,33,15,"TRANSFERRING");
			textattr(15+128);
			cprintf("....");
			box1(17,28,19,53,15);
			for(i=29;i<=51;i++)
			{
				gotoxy(i,18);
				textattr(15);
				cprintf("%c",219);
				delay(100);
			}
			p(15,26,15,"                            ");
			p(16,26,15,"                            ");
			p(17,26,15,"                            ");
			p(18,26,15,"                            ");
			p(19,26,15,"                            ");
			p(20,26,15,"                            ");
			p(21,26,15,"                            ");
			p(16,33,15,"TRANSFERRING");
			textattr(15+128);
			cprintf("....");
			box1(17,28,19,53,15);
			for(i=29;i<=51;i++)
			{
				gotoxy(i,18);
				textattr(15);
				cprintf("%c",219);
				delay(100);
			}
			p(15,26,15,"                            ");
			p(16,26,15,"                            ");
			p(17,26,15,"                            ");
			p(18,26,15,"                            ");
			p(19,26,15,"                            ");
			p(20,26,15,"                            ");
			p(21,26,15,"                            ");
			p(16,33,15,"TRANSFERRING");
			textattr(15+128);
			cprintf("....");
			box1(17,28,19,53,15);
			for(i=29;i<=51;i++)
			{
				gotoxy(i,18);
				textattr(15);
				cprintf("%c",219);
				delay(100);
			}
			p(15,26,15,"                            ");
			p(16,26,15,"                            ");
			p(17,26,15,"                            ");
			p(18,26,15,"                            ");
			p(19,26,15,"                            ");
			p(20,26,15,"                            ");
			p(21,26,15,"                            ");
			p(18,34,15,"TRANSFER DONE");
			delay(100);
			p(25,68,14,"0   BACK");
			gotoxy(70,25);
			textattr(14);
			cprintf("%c",26);
			p(23,32,10,"PAYMENT SUCCESSFULLY");
			textattr(15);
			getch();
			customer();
		}
		else
		{
			p(15,33,140,"PIN IS NOT VALID");
			textattr(15);
			getch();
			payment();
		}
		}
		else
		{
			p(15,33,140,"CARD IS NOT VALID");
			textattr(15);
			getch();
			payment();
		}
		}
		else
		{
			p(15,33,140,"PIN IS NOT VALID");
			textattr(15);
			getch();
			payment();
		}
		}
		else
		{
			p(15,33,140,"CARD IS NOT VALID");
			textattr(15);
			getch();
			payment();
		}
	}
	else
	{
		p(8,33,140,"PLEASE TRY AGAIN");
		textattr(15);
		getch();
		payment();
	}
}

void show()
{
	FILE *fp56;
	int t, x, avl;
	char name[25],mobile[25];
	clrscr();
	title();
	p(25,5,14,"TC");
	gotoxy(8,25);
	cprintf("%c",16);
	p(25,10,14,"CUSTOMER");
	gotoxy(19,25);
	cprintf("%c",16);
	p(25,21,14,"SHOW TICKET");
	p(25,68,14,"0   BACK");
	gotoxy(70,25);
	textattr(14);
	cprintf("%c",26);
	p(12,20,15,"PLEASE ENTER TICKET NO YOU WANT TO SHOW : ");
	scanf("%d", &t);
	avl = ticket(t);
	if (avl == 0)
	{
		if(t==0)
		{
			customer();
		}
		else
		{
			gotoxy(22,14);
			textattr(140);
			cprintf("TICKET NO %d IS NOT AVAILABLE IN THE FILE",t);
			textattr(15);
			getch();
			customer();
		}
	}
	else
	{
		fp56 = fopen("TICKET", "r");
		while (fread(&TIC, sizeof(TIC), 1, fp56))
		{
			x = TIC.ticketno;
			if (x == t)
			{
				p(14,20,15,"PLEASE ENTER NAME : ");
				scanf("%s",&name);
				p(16,20,15,"PLEASE ENTER CONTACT NUMBER : ");
				scanf("%s",&mobile);
				if(strcmp(name,TIC.name)==0 && strcmp(mobile,TIC.mobile)==0)
				{
					clrscr();
					title();
					p(25,5,14,"TC");
					gotoxy(8,25);
					cprintf("%c",16);
					p(25,10,14,"CUSTOMER");
					gotoxy(19,25);
					cprintf("%c",16);
					p(25,21,14,"SHOW TICKET");
					p(25,68,14,"0   BACK");
					gotoxy(70,25);
					textattr(14);
					cprintf("%c",26);
					p(6,11,15," * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
					p(21,11,15," * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
					p(7,12,15,"*");
					p(8,12,15,"*");
					p(9,12,15,"*");
					p(10,12,15,"*");
					p(11,12,15,"*");
					p(12,12,15,"*");
					p(13,12,15,"*");
					p(14,12,15,"*");
					p(15,12,15,"*");
					p(16,12,15,"*");
					p(17,12,15,"*");
					p(18,12,15,"*");
					p(19,12,15,"*");
					p(20,12,15,"*");
					p(7,70,15,"*");
					p(8,70,15,"*");
					p(9,70,15,"*");
					p(10,70,15,"*");
					p(11,70,15,"*");
					p(12,70,15,"*");
					p(13,70,15,"*");
					p(14,70,15,"*");
					p(15,70,15,"*");
					p(16,70,15,"*");
					p(17,70,15,"*");
					p(18,70,15,"*");
					p(19,70,15,"*");
					p(20,70,15,"*");
					p(7,33,13,"MAHASAGAR TRAVELS");
					gotoxy(16,9);
					textattr(15);
					cprintf("NAME : %s",TIC.name);
					gotoxy(51,9);
					cprintf("DATE : %d/%d/%d",TIC.date1,TIC.date2,TIC.date3);
					gotoxy(16,11);
					cprintf("TICKET NUMBER : %d",TIC.ticketno);
					gotoxy(51,11);
					cprintf("TIME : %d:%d",TIC.hh,TIC.mm);
					gotoxy(16,13);
					cprintf("JOURNEY : AHMEDABAD TO %s",TIC.des);
					gotoxy(16,15);
					cprintf("PERSON : %d",TIC.person);
					gotoxy(51,15);
					cprintf("FARE : %0.2f",TIC.fare);
					gotoxy(16,17);
					cprintf("CONTACT NUMBER : %s",TIC.mobile);
					gotoxy(16,19);
					cprintf("MAHASAGAR OFFICE NUMBER : 022-54321, 079-24245");
					gotoxy(28,23);
					cprintf("%s, HAVE A NICE JOURNEY",TIC.name);
					fclose(fp56);
					getch();
					customer();
				}
				else
				{
					p(18,34,140,"DATA NOT MATCH");
					textattr(15);
					fclose(fp56);
					getch();
					customer();
				}
			}
		}
	}
}

void cmessage()
{
	FILE *fp57, *fp58;
	int t, x, avl;
	char name[25],mobile[25],ch[25];
	clrscr();
	title();
	p(25,5,14,"TC");
	gotoxy(8,25);
	cprintf("%c",16);
	p(25,10,14,"CUSTOMER");
	gotoxy(19,25);
	cprintf("%c",16);
	p(25,21,14,"MESSAGE");
	p(25,68,14,"0   BACK");
	gotoxy(70,25);
	textattr(14);
	cprintf("%c",26);
	p(12,20,15,"PLEASE ENTER TICKET NO YOU WANT TO SHOW : ");
	scanf("%d", &t);
	avl = ticket(t);
	if (avl == 0)
	{
		if(t==0)
		{
			customer();
		}
		else
		{
			gotoxy(22,14);
			textattr(140);
			cprintf("TICKET NO %d IS NOT AVAILABLE IN SYSTEM",t);
			textattr(15);
			getch();
			customer();
		}
	}
	else
	{
		fp57 = fopen("TICKET", "r");
		while (fread(&TIC, sizeof(TIC), 1, fp57))
		{
			x = TIC.ticketno;
			if (x == t)
			{
				p(14,20,15,"PLEASE ENTER NAME : ");
				scanf("%s",&name);
				p(16,20,15,"PLEASE ENTER CONTACT NUMBER : ");
				scanf("%s",&mobile);
				if(strcmp(name,TIC.name)==0 && strcmp(mobile,TIC.mobile)==0)
				{
					clrscr();
					title();
					p(25,5,14,"TC");
					gotoxy(8,25);
					cprintf("%c",16);
					p(25,10,14,"CUSTOMER");
					gotoxy(19,25);
					cprintf("%c",16);
					p(25,21,14,"MESSAGE");
					p(6,11,15," * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
					p(21,11,15," * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
					p(7,12,15,"*");
					p(8,12,15,"*");
					p(9,12,15,"*");
					p(10,12,15,"*");
					p(11,12,15,"*");
					p(12,12,15,"*");
					p(13,12,15,"*");
					p(14,12,15,"*");
					p(15,12,15,"*");
					p(16,12,15,"*");
					p(17,12,15,"*");
					p(18,12,15,"*");
					p(19,12,15,"*");
					p(20,12,15,"*");
					p(7,70,15,"*");
					p(8,70,15,"*");
					p(9,70,15,"*");
					p(10,70,15,"*");
					p(11,70,15,"*");
					p(12,70,15,"*");
					p(13,70,15,"*");
					p(14,70,15,"*");
					p(15,70,15,"*");
					p(16,70,15,"*");
					p(17,70,15,"*");
					p(18,70,15,"*");
					p(19,70,15,"*");
					p(20,70,15,"*");
					p(7,33,13,"MAHASAGAR TRAVELS");
					gotoxy(16,9);
					textattr(15);
					cprintf("NAME : %s",TIC.name);
					gotoxy(51,9);
					cprintf("DATE : %d/%d/%d",TIC.date1,TIC.date2,TIC.date3);
					gotoxy(16,11);
					cprintf("TICKET NUMBER : %d",TIC.ticketno);
					gotoxy(51,11);
					cprintf("TIME : %d:%d",TIC.hh,TIC.mm);
					gotoxy(16,13);
					cprintf("JOURNEY : AHMEDABAD TO %s",TIC.des);
					gotoxy(16,15);
					cprintf("PERSON : %d",TIC.person);
					gotoxy(51,15);
					cprintf("FARE : %0.2f",TIC.fare);
					gotoxy(16,17);
					cprintf("CONTACT NUMBER : %s",TIC.mobile);
					gotoxy(16,19);
					cprintf("MAHASAGAR OFFICE NUMBER : 022-54321, 079-24245");
					p(23,35,15,"PRESS ANY KEY");
					getch();
					clrscr();
					title();
					p(25,5,14,"TC");
					gotoxy(8,25);
					cprintf("%c",16);
					p(25,10,14,"CUSTOMER");
					gotoxy(19,25);
					cprintf("%c",16);
					p(25,21,14,"MESSAGE");
					fp58 = fopen("MESSAGE","r");
					while (fread(&MSG, sizeof(MSG), 1, fp58))
					{
						if((strcmp(MSG.des,TIC.des)==0) && (TIC.date1==MSG.d1 && TIC.date2==MSG.d2 && TIC.date3==MSG.d3))
						{
							box(10,15,18,65,13);
							p(12,17,15,"DEAR PASSENGER, YOUR BUS ");
							textattr(12);
							cprintf("AHMEDABAD TO %s",TIC.des);
							p(14,17,15,"WILL BE DELAYED DUE TO ");
							textattr(12);
							cprintf("%s",MSG.reason);
							textattr(15);
							cprintf(". PLEASE BE");
							p(16,17,15,"PRESENT AT ");
							textattr(12);
							cprintf("%d:%d ",MSG.hh1,MSG.mm1);
							textattr(15);
							cprintf("ON ");
							textattr(12);
							cprintf("%d/%d/%d ",TIC.date1,TIC.date2,TIC.date3);
							textattr(15);
							cprintf("AT PICKUP POINT.");
							fclose(fp57);
							fclose(fp58);
							p(25,68,14,"0   BACK");
							gotoxy(70,25);
							textattr(14);
							cprintf("%c",26);
							getch();
							customer();
							break;
						}
					}
					box(10,15,18,65,13);
					p(12,17,15,"DEAR PASSENGER, YOUR BUS ");
					textattr(12);
					cprintf("AHMEDABAD TO %s",TIC.des);
					p(14,17,15,"IS ARRIVING AS PER SCHEDULE. PLEASE BE PRESENT");
					p(16,17,15,"AT ");
					textattr(12);
					cprintf("%d:%d ",TIC.hh,TIC.mm);
					textattr(15);
					cprintf("ON ");
					textattr(12);
					cprintf("%d/%d/%d ",TIC.date1,TIC.date2,TIC.date3);
					textattr(15);
					cprintf("AT PICKUP POINT.");
					fclose(fp57);
					fclose(fp58);
					p(25,68,14,"0   BACK");
					gotoxy(70,25);
					textattr(14);
					cprintf("%c",26);
					getch();
					customer();
				}
				else
				{
					p(18,34,140,"DATA NOT MATCH");
					textattr(15);
					fclose(fp57);
					getch();
					customer();
				}
			}
		}
	}
}





int bus(int b)
{
	FILE *fp100;
	fp100 = fopen("BUS", "r");
	while (!feof(fp100))
	{
		fread(&BUS, sizeof(BUS), 1, fp100);
		if (b == BUS.no)
		{
			fclose(fp100);
			return 1;
		}
	}
	fclose(fp100);
	return 0;
}

int ticket(int t)
{
	FILE *fp101;
	fp101 = fopen("TICKET", "r");
	while (!feof(fp101))
	{
		fread(&TIC, sizeof(TIC), 1, fp101);
		if (t == TIC.ticketno)
		{
			fclose(fp101);
			return 1;
		}
	}
	fclose(fp101);
	return 0;
}

int message(int m)
{
	FILE *fp102;
	fp102 = fopen("MESSAGE", "r");
	while (!feof(fp102))
	{
		fread(&MSG, sizeof(MSG), 1, fp102);
		if (m == MSG.no)
		{
			fclose(fp102);
			return 1;
		}
	}
	fclose(fp102);
	return 0;
}

int bempty()
{
	int c = 0;
	FILE *fp103;
	fp103 = fopen("BUS", "r");
	while (fread(&BUS, sizeof(BUS), 1, fp103))
	c = 1;
	fclose(fp103);
	return c;
}

int tempty()
{
	int c = 0;
	FILE *fp104;
	fp104 = fopen("TICKET", "r");
	while (fread(&TIC, sizeof(TIC), 1, fp104))
	c = 1;
	fclose(fp104);
	return c;
}

int mempty()
{
	int c = 0;
	FILE *fp105;
	fp105 = fopen("MESSAGE", "r");
	while (fread(&MSG, sizeof(MSG), 1, fp105))
	c = 1;
	fclose(fp105);
	return c;
}
