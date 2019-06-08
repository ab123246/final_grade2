#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
// =============================================
// �禡�G gotoxy
// �����G ���ʴ�Цܫ��w��m
// ============================================
void gotoxy(int x, int  y){
        COORD point;
        point.X = x, point.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
// =============================================
// �禡�G getxy
// �����G ���o�ثe��Ц�m
// ============================================
void getxy(int *x, int *y){
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        *x = csbi.dwCursorPosition.X;
        *y = csbi.dwCursorPosition.Y;
}
int main(){
	int x,y,index = 0;
	bool num1 = false,num2 = true;
	#pragma omp parallel sections 	
	{
		#pragma omp section
		{
			while(1){
				if(num1){
					num2 = false;
				}
				if(!num1 && num2){
					getxy(&x,&y);
					gotoxy(0,0);
					printf("x = %d, y = %d                                                       ",x,y);
					gotoxy(x,y);
				}
				Sleep(10);
			}
		}
		#pragma omp section
		{
			char c; 
			while ((c=getchar())!='/n'){   /*�C?getchar()�̦�?�J�@?�r��*/
				if(c != '\n'){
					bool first = false;
					if(num2){
						first = true;	
					}
					num1 = true;
					while(num2);
					if(first)
						gotoxy(0,2);	
					printf("%c",c);    /*���ӭ�??�X*/
				}else{
					gotoxy(0,3);
					printf("��Xenter�Findex = %d",index);
					gotoxy(0,1);
					for(int loopnum1 = 0;loopnum1<100;loopnum1++){
						printf(" ");
					}
					num1 = false;
					num2 = true;
					index++;
					gotoxy(0,1);
				} 
			}
			getch();       /*���ݫ����@��*/ 
		}
	}	
	
}
