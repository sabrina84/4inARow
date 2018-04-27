# include "iGraphics.h"
# include <GLAux.h>
# include <time.h>

int gameover=1,ct=0;
int frx,fry,fcx,fcy,p;
int turn=1,k=0,i=0,j=0,rp,cp,rp1,cp1,pl=0,level=0;
int flag=0,play=3,flg=0,flg1;

//int centerx, centery, flg,r,p;
int ar[8][9];

void init(int rw, int cl)
{
	int rw1, cl1;
	for(rw1=0; rw1<rw; rw1++){
		for(cl1=0; cl1<cl; cl1++){
			ar[rw1][cl1]=0;
		}
	}
}
void time()
{
}
void mydelay(int mseconds)
{
	clock_t start, end;
	double elapsed;
	start = clock();
	while(1)
	{
		end = clock();
		elapsed = ((double) (end - start)) / ((double)CLOCKS_PER_SEC/1000.0);
		if(elapsed>mseconds)break;
	}
}

void iMouseMove(int mx, int my)
{
	/*if(play==0){
		if(mx>200 && mx<400 && my>600 && my<700){
			flg1=1;
		}

		else if(mx>200 && mx<400 && my>400 && my<500){
			flg1=3;
		}
		else if(mx>200 && mx<400 && my<400 && my>300){
			flg1 = 4;
		}
		else if(mx>200 && mx<400 && my>500 && my<600){
			flg1 = 2;
		}
	}*/
}

void iAiGame(void){
	int t,r,c,t1,t2,t3,r1,c1,rf,cf,max=-10000,t4;
	//t=total;
		//mydelay(100);
	rp=-1;
	cp=-1;
	rp1=-1;
	cp1=-1;
	if(k==0){
		ar[0][3]=turn;
		k++;
		turn++;
		return;
	}

	if(k==2){
		if(flg1<3)ar[0][4]=turn;
		else ar[0][2]=turn;
		k++;
		turn++;
		return;
	}

	for(r=0; r<7; r++){

		for(c=0; c<7; c++){
			t=0;
			if(ar[r][c]==0){
				ar[r][c]=1;
				t1 = sum3(r,c,1);
				t2 = sum2(r,c,1);
				t4 = sum4(r,c,1);
				if(t4!=0 && level==2){
					rp=r;
					cp=c;
				}
				t = t+t1+t2+t4;
				t3=t;
				for(r1=0; r1<7; r1++){

					for(c1=0; c1<7; c1++){
						t=t3;
						if(ar[r1][c1]==0){
							ar[r1][c1]=2;
							t1 = sum3(r1,c1,2);
							t2 = sum2(r1,c1,2);
							t4 = sum4(r1,c1,2);
							if(t4!=0 && level==2){
								rp1=r1;
								cp1=c1;
							}

							t = t-t1-t2-t4;
							if(t>max){
								max=t;

								rf=r;
								cf=c;
							}
							ar[r1][c1]=0;

						}
					}
				}
				ar[r][c]=0;
				if(rp>=0 || cp>=0 && level==2){
					rf=rp;
					cf=cp;
					break;
				}
				if(rp1>=0 || cp1>=0 && level==2){
					rf=rp1;
					cf=cp1;
					break;
				}

			}
		}
	}

	if(rf>0){
		if(ar[rf-1][cf]>0)ar[rf][cf]=1;
		else {
			while(ar[rf-1][cf]<1){
				rf--;
				if(rf==0)break;
			}
			ar[rf][cf]=1;

		}
	}
	else ar[rf][cf]=1;
			//ar[rf][cf]=1;
	if(flag==1){
		rp=rf;
		cp=cf;

	}
	k++;
	//if(k>2)total=total+t5;
	turn++;
	return;

}

int sum2(int row, int col, int num){
	int t=0;

	if(col<6){
		if(ar[row][col+1]==num)t+=10;
	}
	if(col>0){
		if(ar[row][col-1]==num)t+=10;
	}
	if(row<6){
		if(ar[row+1][col]==num)t+=10;
	}
	if(row>0){
		if(ar[row-1][col]==num)t+=10;
	}
	if(col<6 && row<6){
		if(ar[row+1][col+1]==num)t+=10;
	}
	if(col<6 && row>0){
		if(ar[row-1][col+1]==num)t+=10;
	}
	if(col>0 && row<6){
		if(ar[row+1][col-1]==num)t+=10;
	}
	if(col>0 && row>0){
		if(ar[row-1][col-1]==num)t+=10;
	}
	return t;
}

int sum3(int row, int col, int num){
	int t=0;
	if(col<5){
		if(ar[row][col+1]==num && ar[row][col+2]==num )t+=100;
	}
	if(col>1){
		if(ar[row][col-1]==num && ar[row][col-2]==num )t+=100;
	}
	if(row<5){
		if(ar[row+1][col]==num && ar[row+2][col]==num)t+=100;
	}
	if(row>1){
		if(ar[row-1][col]==num && ar[row-2][col]==num)t+=100;
	}
	if(col<5 && row<5){
		if(ar[row+1][col+1]==num && ar[row+2][col+2]==num)t+=100;
	}
	if(col<5 && row>1){
		if(ar[row-1][col+1]==num && ar[row-2][col+2]==num)t+=100;
	}
	if(col>1 && row<5){
		if(ar[row+1][col-1]==num && ar[row+2][col-2]==num)t+=100;
	}
	if(col>1 && row>1){
		if(ar[row-1][col-1]==num && ar[row-2][col-2]==num)t+=100;
	}
	return t;
}

int sum4(int row, int col, int num){
	int t=0;
	if(col<4){
		if(ar[row][col+1]==num && ar[row][col+2]==num && ar[row][col+3]==num)t+=1000;
	}
	if(col>2){
		if(ar[row][col-1]==num && ar[row][col-2]==num && ar[row][col-3]==num)t+=1000;
	}
	if(row<4){
		if(ar[row+1][col]==num && ar[row+2][col]==num && ar[row+3][col]==num)t+=1000;
	}
	if(row>2){
		if(ar[row-1][col]==num && ar[row-2][col]==num && ar[row-3][col]==num)t+=1000;
	}
	if(col<4 && row<4){
		if(ar[row+1][col+1]==num && ar[row+2][col+2]==num && ar[row+3][col+3]==num)t+=1000;
	}
	if(col<4 && row>2){
		if(ar[row-1][col+1]==num && ar[row-2][col+2]==num  && ar[row-3][col+3]==num)t+=1000;
	}
	if(col>2 && row<4){
		if(ar[row+1][col-1]==num && ar[row+2][col-2]==num && ar[row+3][col-3]==num)t+=1000;
	}
	if(col>2 && row>2){
		if(ar[row-1][col-1]==num && ar[row-2][col-2]==num && ar[row-3][col-3]==num)t+=1000;
	}
	return t;
}


void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		if(mx>70 && mx<560 && my>140 && my<210 && gameover == 0){
			if(flg==1){
				int q,b1;
				p=mx/70;
			//printf("P: %d ",p);
				q=my/70;
				for(b1=0; b1<7; b1++){
					if(ar[b1][p-1]==0){
						ar[b1][p-1]=turn;
						k++;
						turn++;
						if(turn==3)turn=1;
						break;
					}
				}

			}

			else if(flg==2){
				if(turn==2){
					int b1,t,t1,t2,t3;
					p=mx/70;
					//q=my/70;
					for(b1=0; b1<7; b1++){
						if(ar[b1][p-1]==0){
							ar[b1][p-1]=turn;
							turn++;
							if(k==1)flg1=p-1;
							if(turn==3)turn=1;
							k++;

							if(flag==0)iAiGame();
							break;
						}
					}

				}
			}

		}
		//back
		if(mx>750 && mx<850 && my>140 && my<200 && flag==0){

			play=0;
		}
		//main page
		else if(mx>200 && mx<350 && my>200 && my<250 && gameover == 1){
			gameover=0;
			play=0;
		}


		if(flag>0){

			play=0;
		}
		if(gameover==1){
			//2 players
			if(mx>200 && mx<400 && my>600 && my<700){
				play=1;
				turn=1;
				k=0;
				flg=1;
				flag=0;
				gameover=0;
				init(7,7);
			}
			//resume
			else if(mx>200 && mx<400 && my>400 && my<500){
				if(ct>0 && flag==0){
					//turn=1;
					play=1;
					//k=0;
					//init(7,7);
					gameover=0;
					//total=10;
					//if(flg==2)iAiGame();
				}
			}
			else if(mx>200 && mx<400 && my>500 && my<600){
				pl=1;
				//hv=1;
				gameover=0;
				flag=0;
				//play=1;

			}
			if(mx>400 && mx<500 && my>425 && my<500 && pl==1){
				level=2;
				play=1;
				turn=1;
				k=0;
				flg=2;
				gameover=0;
				init(7,7);
				iAiGame();
			}
			if(mx>400 && mx<500 && my>500 && my<575 && pl==1){
				level=1;
				play=1;
				turn=1;
				k=0;
				flg=2;

				gameover=0;
				init(7,7);

				iAiGame();
			}
			else if(mx>200 && mx<400 && my<300 && my>200){
				exit(0);
			}
			//instructions
			else if(mx>200 && mx<400 && my>300 && my<400){
				play=2;
				gameover=0;

			}
		}
	}
}
void iDraw()
{
	if(play==1){
		iClear();
		ct=1;
		pl=0;
		//mydelay(100);
		iShowBMP(0,0,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\4 in a row\\mm2.bmp");
		int i1,j1,k1,i2,i3;
		j1=70;
		k1=70;
		iShowBMP(70,140,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\4 in a row\\gm.bmp");

		if (flag==0){
			iSetcolor(0,20,20);
			iFilledRectangle(750,140,100,60);
			iSetcolor(20,200,30);

			iText(760,160,"Quit",GLUT_BITMAP_TIMES_ROMAN_24);
		}
		iSetcolor(100,10,10);
		iLine(70,700,560,700);
		for(i1=0; i1<8; i1++){
			iLine(j1,140,j1,700);
			iLine(70,j1+70,560,j1+70);
			j1+=70;
		}
		iSetcolor(10,0,40);
		if(flag==0 && flg==1)iText(620,560,"Next move:",GLUT_BITMAP_TIMES_ROMAN_24);
		if(turn>0){
			//if(flag==1)ar[rp][cp]=0;
			for(i2=0; i2<7; i2++){

				for(i3=0; i3<7; i3++){

					if(ar[i2][i3]==1){
						iSetcolor(90,0,0);
						iFilledCircle((i3+1)*70+35,(i2+3)*70+35,21,100);

					}
					else if(ar[i2][i3]==2){
						iSetcolor(0,0,90);
						iFilledCircle((i3+1)*70+35,(i2+3)*70+35,21,100);

					}
				}
			}
		}
		if(flag==0 && flg==1){
			iSetcolor(30,0,235);
			if(turn==1)	iText(760,560,"RED",GLUT_BITMAP_TIMES_ROMAN_24);
			else if(turn==2)iText(760,560,"BLUE",GLUT_BITMAP_TIMES_ROMAN_24);
		}

		flag = iGame(2);
		if(flag==0)flag = iGame(1);
		if(flag==1){
			iSetcolor(70,75,80);
			iLine(fcy, fcx,fry,frx);

		}

	}
	else if(play==3){
		iShowBMP(0,0,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\4 in a row\\ducks2.bmp");
		iSetcolor(0,10,10);
		iFilledRectangle(200,200,150,50);
		iSetcolor(20,0,20);
		iText(220,225,"get started", GLUT_BITMAP_HELVETICA_18);

	}
	else if(play==0){
		mydelay(100);
		iClear();
		iShowBMP(0,0,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\4 in a row\\mm3.bmp");
		gameover=1;
		iSetcolor(100,60,10);
		if(pl==1)iShowBMP(400,425,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\4 in a row\\level.bmp");
		if(flag==1 && ct!=2 && flg==1){
			if(turn==1)iShowBMP(600,400,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\4 in a row\\red.bmp");
			else if(turn==2)iShowBMP(600,400,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\4 in a row\\blue.bmp");
		}
		if(flag==2 && ct!=2){
			iSetcolor(0,75,0);
			iText(200,775,"Match drawn",GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if(flag==1 && ct!=2 && flg==2){

			if(flg1==2){
				//iText(600,525,"YOU WIN!!", GLUT_BITMAP_TIMES_ROMAN_24);
				iShowBMP(600,400,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\4 in a row\\hp.bmp");
			}
			else if(flg1==1){
				//iText(600,525,"YOU LOSE..", GLUT_BITMAP_TIMES_ROMAN_24);
				iShowBMP(600,400,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\4 in a row\\sd.bmp");
			}
		}
		//if(hv==1)iShowBMP(200,500,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\4 in a row\\hp.bmp");

		iShowBMP(200,200,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\4 in a row\\menu.bmp");

	}
	if(play==2){
		mydelay(100);
		iClear();
		//gameover=1;
		iShowBMP(0,0,"C:\\Users\\User\\Documents\\Visual Studio 2010\\Projects\\4 in a row\\INS.bmp");
		iSetcolor(0,200,80);
		iFilledRectangle(750,140,100,60);
		iSetcolor(0,0,0);
		iText(760,160,"Back",GLUT_BITMAP_TIMES_ROMAN_24);
	}
}
int iGame(int num)
{
	int row1,col1;

	for(row1=0; row1<7; row1++){
		for(col1=0; col1<5; col1++){
			if(((ar[row1][col1])== num) && (ar[row1][col1]==ar[row1][col1+1]) && (ar[row1][col1]==ar[row1][col1+2]) && (ar[row1][col1]==ar[row1][col1+3])){
				frx = (row1+3)*70+35;
				fry = (col1+1)*70+35;
				fcx = (row1+3)*70+35;
				fcy = (col1+4)*70+35;
				flg1=ar[row1][col1];
				return 1;
			}
		}
	}
	for(row1=0; row1<5; row1++){
		for(col1=0; col1<7; col1++){
			if(((ar[row1][col1]== num)) && (ar[row1][col1]==ar[row1+1][col1]) && (ar[row1][col1]==ar[row1+2][col1]) &&(ar[row1][col1]==ar[row1+3][col1])){
				frx = (row1+3)*70+35;
				fry = (col1+1)*70+35;
				fcx = (row1+6)*70+35;
				fcy = (col1+1)*70+35;
				flg1=ar[row1][col1];
				return 1;
			}
		}
	}
	for(row1=0; row1<4; row1++){
		for(col1=0; col1<4; col1++){
			if(((ar[row1][col1]) == num) && (ar[row1][col1]==ar[row1+1][col1+1]) &&(ar[row1][col1]==ar[row1+2][col1+2]) && (ar[row1][col1]==ar[row1+3][col1+3])){
				frx = (row1+3)*70+35;
				fry = (col1+1)*70+35;
				fcx = (row1+6)*70+35;
				fcy = (col1+4)*70+35;
				flg1=ar[row1][col1];
				return 1;
			}
		}
	}
	for(row1=0; row1<4; row1++){
		for(col1=3; col1<7; col1++){
			if(((ar[row1][col1])== num) && (ar[row1][col1]==ar[row1+1][col1-1]) && (ar[row1][col1]==ar[row1+2][col1-2]) && (ar[row1][col1]==ar[row1+3][col1-3])){
				frx = (row1+3)*70+35;
				fry = (col1+1)*70+35;
				fcx = (row1+6)*70+35;
				fcy = (col1-2)*70+35;
				flg1=ar[row1][col1];
				return 1;
			}
		}
	}
	if(k==49)return 2;
	return 0;
}

void iSpecialKeyboard(unsigned char key)
{
}
void iKeyboard(unsigned char key)
{
}

int main()
{
	//init(8,9);
	iSettimer(1000, time);
	iInitialize(900, 800, "Final");
	return 0;
}

