#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

void brickColor();
void ChangeBrick(int, int);
void strikePad(int);
void removeStrikePad(int);
void ballPosition(int, int);
int level = 1;


int a[80] = {0};
int bricks[8][10] = { 0 };

int main(){

	int random, ranDir;
	int gd = DETECT, gm;
	int posX = 650;
	int ballX = 650, ballY = 635;
	int count = 0;
	int Xcoll = 0, Ycollup = 0, Ycolldown = 0;
	int brickX, brickY;



	initgraph(&gd, &gm, "C:\\TC\\BGI"); // Initilize graph
	initwindow(1366, 710);

	settextstyle(0, HORIZ_DIR, 1);
	int x = 10, b = 200;
	setcolor(WHITE);
	outtextxy(200, b += x, " ______  # ______  # _____ #  ______ # _    _ #  # ______  # ______  # _______ #        # _    _ # _______ # ______  #");
	outtextxy(200, b += x, "(____  \\ #(_____ \\ #(_____)# / _____)#| |  / )#  #(____  \\ #(_____ \\ #(_______)#   /\\   #| |  / )#(_______)#(_____ \\\ #");
	outtextxy(200, b += x, " ____)  )# _____) )#   _   #| /      #| | / / #  # ____)  )# _____) )# _____   #  /  \\  #| | / / # _____   # _____) )#");
	outtextxy(200, b += x, "|  __  ( #(_____ ( #  | |  #| |      #| |< <  #  #|  __  ( #(_____ ( #|  ___)  # / /\\ \\ #| |< <  #|  ___)  #(_____ ( #");
	outtextxy(200, b += x, "| |__)  )#      | |# _| |_ #| \\_____ #| | \\ \\ #  #| |__)  )#      | |#| |_____ #| |__| |#| | \\ \\ #| |_____ #      | |#");
	outtextxy(200, b += x, "|______/ #      |_|#(_____)# \\______)#|_|  \\_)#  #|______/ #      |_|#|_______)#|______|#|_|  \\_)#|_______)#      |_|#");

	settextstyle(0, HORIZ_DIR, 2);
	outtextxy(500, b += 4 * x, "INSTRUCTIONS");
	outtextxy(500, b += 2 * x, "------------");
	outtextxy(200, b += 2 * x, "1. Click the Left Mouse button to start the game.");
	outtextxy(200, b += 2 * x, "2. Hit the ball with strike Pad to keep it in the sceen.");
	outtextxy(200, b += 2 * x, "3. Hit the bricks following times to destroy them.");

	setfillstyle(SOLID_FILL, YELLOW); //fill styles with fill style color
	rectangle(200, b += 4 * x, 300, b + 2 * x);
	floodfill(250, b + 3, WHITE);

	setfillstyle(SOLID_FILL, GREEN); //fill styles with fill style color
	rectangle(400, b, 500, b + 2 * x);
	floodfill(450, b + 3, WHITE);

	setfillstyle(SOLID_FILL, RED); //fill styles with fill style color
	rectangle(600, b, 700, b + 2 * x);
	floodfill(650, b + 3, WHITE);

	setfillstyle(SOLID_FILL, BLUE); //fill styles with fill style color
	rectangle(800, b, 900, b + 2 * x);
	floodfill(850, b + 3, WHITE);

	outtextxy(200, b += 3 * x, "4 TIMES");
	outtextxy(400, b, "3 TIMES");
	outtextxy(600, b, "2 TIMES");
	outtextxy(800, b, "1 TIME");

	outtextxy(200, b += 4 * x, "4. Destroy all the bricks to complete a level. There are 3 levels");

	getch();
	cleardevice();

	while (level < 4){

		posX = 650;
		ballX = 650, ballY = 635;
		count = 0;
		cleardevice();

		if (level == 1){
			a[1] = 3, a[2] = 2, a[3] = 2, a[4] = 2, a[5] = 2, a[6] = 2, a[7] = 2, a[8] = 2, a[9] = 2, a[10] = 2;
			a[11] = 2, a[12] = 2, a[13] = 2, a[14] = 2, a[15] = 2, a[16] = 2, a[17] = 2, a[18] = 2, a[19] = 2, a[20] = 2;
			a[21] = 3, a[22] = 2, a[23] = 1, a[24] = 1, a[25] = 1, a[26] = 1, a[27] = 1, a[28] = 1, a[29] = 2, a[30] = 3;
			a[31] = 2, a[32] = 2, a[33] = 1, a[34] = 1, a[35] = 1, a[36] = 1, a[37] = 1, a[38] = 1, a[39] = 2, a[40] = 2;
			a[41] = 3, a[42] = 2, a[43] = 1, a[44] = 1, a[45] = 1, a[46] = 1, a[47] = 1, a[48] = 1, a[49] = 2, a[50] = 3;
			a[51] = 2, a[52] = 2, a[53] = 1, a[54] = 1, a[55] = 1, a[56] = 1, a[57] = 1, a[58] = 1, a[59] = 2, a[60] = 2;
			a[61] = 3, a[62] = 2, a[63] = 2, a[64] = 2, a[65] = 2, a[66] = 2, a[67] = 2, a[68] = 2, a[69] = 2, a[70] = 3;
			a[71] = 2, a[72] = 2, a[73] = 2, a[74] = 2, a[75] = 2, a[76] = 2, a[77] = 2, a[78] = 2, a[79] = 2, a[80] = 2;
		}


		else
		if (level == 2){
			a[1] = 1, a[2] = 1, a[3] = 1, a[4] = 1, a[5] = 1, a[6] = 1, a[7] = 1, a[8] = 1, a[9] = 1, a[10] = 1;
			a[11] = 1, a[12] = 2, a[13] = 2, a[14] = 2, a[15] = 2, a[16] = 2, a[17] = 2, a[18] = 2, a[19] = 2, a[20] = 1;
			a[21] = 1, a[22] = 2, a[23] = 3, a[24] = 3, a[25] = 3, a[26] = 3, a[27] = 3, a[28] = 3, a[29] = 2, a[30] = 1;
			a[31] = 1, a[32] = 2, a[33] = 3, a[34] = 1, a[35] = 1, a[36] = 1, a[37] = 1, a[38] = 3, a[39] = 2, a[40] = 1;
			a[41] = 1, a[42] = 2, a[43] = 3, a[44] = 1, a[45] = 1, a[46] = 1, a[47] = 1, a[48] = 3, a[49] = 2, a[50] = 1;
			a[51] = 1, a[52] = 2, a[53] = 3, a[54] = 3, a[55] = 3, a[56] = 3, a[57] = 3, a[58] = 3, a[59] = 2, a[60] = 1;
			a[61] = 1, a[62] = 2, a[63] = 2, a[64] = 2, a[65] = 2, a[66] = 2, a[67] = 2, a[68] = 2, a[69] = 2, a[70] = 1;
			a[71] = 1, a[72] = 1, a[73] = 1, a[74] = 1, a[75] = 1, a[76] = 1, a[77] = 1, a[78] = 1, a[79] = 1, a[80] = 1;
		}
		else
		if (level == 3){
			a[1] = 1, a[2] = 2, a[3] = 2, a[4] = 2, a[5] = 2, a[6] = 2, a[7] = 2, a[8] = 2, a[9] = 2, a[10] = 1;
			a[11] = 1, a[12] = 2, a[13] = 1, a[14] = 1, a[15] = 1, a[16] = 1, a[17] = 1, a[18] = 1, a[19] = 2, a[20] = 1;
			a[21] = 1, a[22] = 3, a[23] = 4, a[24] = 4, a[25] = 4, a[26] = 4, a[27] = 4, a[28] = 3, a[29] = 3, a[30] = 1;
			a[31] = 1, a[32] = 2, a[33] = 4, a[34] = 4, a[35] = 4, a[36] = 4, a[37] = 4, a[38] = 1, a[39] = 2, a[40] = 1;
			a[41] = 1, a[42] = 3, a[43] = 4, a[44] = 4, a[45] = 4, a[46] = 4, a[47] = 4, a[48] = 3, a[49] = 3, a[50] = 1;
			a[51] = 1, a[52] = 2, a[53] = 4, a[54] = 4, a[55] = 4, a[56] = 4, a[57] = 4, a[58] = 1, a[59] = 2, a[60] = 1;
			a[61] = 1, a[62] = 3, a[63] = 1, a[64] = 1, a[65] = 1, a[66] = 1, a[67] = 1, a[68] = 3, a[69] = 3, a[70] = 1;
			a[71] = 1, a[72] = 2, a[73] = 2, a[74] = 2, a[75] = 2, a[76] = 2, a[77] = 2, a[78] = 2, a[79] = 2, a[80] = 1;
		}
		int x = 1;
		for (int i = 0; i < 8; i++){
			for (int z = 0; z < 10; z++){
				bricks[i][z] = a[x];
				x++;
			}
		}

		brickColor();
		strikePad(posX);
		ballPosition(ballX, ballY);

		srand(time(NULL));
		random = 1;
		ranDir = rand() % 2;

		Xcoll = 0, Ycollup = 0, Ycolldown = 0;

		while (ballY < 710){
			count = 0;
			for (int row = 0; row < 8; row++){
				for (int col = 0; col < 10; col++){
					brickY = 50 + (row * 30);
					if (row % 2 == 0){
						brickX = 100 + (col * 110);
					}
					else if (row % 2 == 1){
						brickX = 160 + (col * 110);
					}

					if (((ballY + 13) == brickY) && (ballX) >= brickX && (ballX) <= brickX + 110){
						if (bricks[row][col] != 0){
							bricks[row][col]--;
							cleardevice();
							strikePad(posX);
							brickColor();
							Ycolldown = 1;
							Ycollup = 0;
							break;
						}
					}

					else if (((ballY - 15) == brickY + 30) && (ballX) >= brickX && (ballX) <= brickX + 110){
						if (bricks[row][col] != 0){
							bricks[row][col]--;
							cleardevice();
							strikePad(posX);
							brickColor();
							Ycollup = 1;
							Ycolldown = 0;
							break;
						}
					}

					else if (((ballX - 13) == brickX + 110) && (ballY) >= brickY && (ballY) <= brickY + 30){
						if (bricks[row][col] != 0){
							bricks[row][col]--;
							cleardevice();
							strikePad(posX);
							brickColor();
							Xcoll = 1;
							ranDir = 1;
							break;
						}
					}
					else if (((ballX + 13) == brickX) && (ballY) >= brickY && (ballY) <= brickY + 30){
						if (bricks[row][col] != 0){
							bricks[row][col]--;
							cleardevice();
							strikePad(posX);
							brickColor();
							Xcoll = 1;
							ranDir = 0;
							break;
						}
					}
					if (bricks[row][col] == 0){
						count++;
					}

				}

			}
			if (count >= 80){
				settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
				if (level == 1){
					outtextxy(500, 500, "LEVEL 1 COMPLETE");
					outtextxy(250, 550, "PRESS ENTER TO PROCEED TO THE NEXT LEVEL");
				}
				if (level == 2){
					outtextxy(500, 500, "LEVEL 2 COMPLETE");
					outtextxy(250, 550, "PRESS ENTER TO PROCEED TO THE NEXT LEVEL");
				}
				if (level == 3){
					outtextxy(500, 500, "LEVEL 3 COMPLETE");
					outtextxy(250, 550, "PRESS ENTER TO PROCEED TO THE NEXT LEVEL");
				}
				level++;
				getch();
				break;
			}

			bool click = ismouseclick(WM_LBUTTONDOWN);
			if (click == 1){
				if (ballY <= 12 || Ycollup == 1){
					ballY += 1;
					Ycollup = 1;
					Ycolldown = 0;
					if (ballY >= 634 && ballX > posX - 80 && ballX < posX + 80){
						if (ballX <= posX - 80){
							random = 3;
							ranDir = 1;
						}
						else if (ballX <= posX - 40){
							random = 2;
							ranDir = 1;
						}
						else if (ballX <= posX + 40){
							random = 2;
							ranDir = 0;
						}
						else if (ballX <= posX + 80){
							random = 3;
							ranDir = 0;
						}

						Ycolldown = 1;
						Ycollup = 0;
					}
				}
				if (ballY > 12 && (Ycollup == 0 || Ycolldown == 1)){
					ballY -= 1;
				}


				if (Xcoll == 0){
					if (ranDir == 0){
						if (ballX < 1354){
							ballPosition(ballX += random, ballY);
						}
						if (ballX >= 1354){
							ballPosition(ballX -= random, ballY);
							Xcoll = 1;
						}
					}
					else if (ranDir == 1){
						if (ballX > 12){
							ballPosition(ballX -= random, ballY);
						}
						if (ballX <= 12){
							ballPosition(ballX += random, ballY);
							Xcoll = 1;
						}
					}
				}
				else if (Xcoll == 1){
					if (ranDir == 0){
						if (ballX > 12){
							ballPosition(ballX -= random, ballY);
						}
						if (ballX <= 12){
							ballPosition(ballX += random, ballY);
							Xcoll = 0;
						}
					}
					else if (ranDir == 1){
						if (ballX < 1354){
							ballPosition(ballX += random, ballY);
						}
						if (ballX >= 1354){
							ballPosition(ballX -= random, ballY);
							Xcoll = 0;
						}
					}
				}

			}

			int move = 0;
			if (kbhit()){
				move = getch();
			}
			if (move == KEY_RIGHT){
				if (posX <= 1250){
					removeStrikePad(posX);
					strikePad(posX += 70);
				}
			}
			else if (move == KEY_LEFT){
				if (posX >= 120){
					removeStrikePad(posX);
					strikePad(posX -= 70);
				}
			}
		}
		if (count < 80){
			settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
			outtextxy(500, 500, "GAME OVER");
			break;
			exit(0);
		}
	}
	getch();
	closegraph();
}

void brickColor(){

	int top = 50;
	int right = 100;
	for (int row = 0; row < 8; row++){
		for (int col = 0; col < 10; col++){

			if (bricks[row][col] == 1){
				setfillstyle(SOLID_FILL, BLUE); //fill styles with fill style color
				rectangle(right, top, right + 110, top + 30);
				floodfill(right + 100, top + 15, WHITE);
			}
			else if (bricks[row][col] == 2){
				setfillstyle(SOLID_FILL, RED); //fill styles with fill style color
				rectangle(right, top, right + 110, top + 30);
				floodfill(right + 100, top + 15, WHITE);
			}
			else if (bricks[row][col] == 3){
				setfillstyle(SOLID_FILL, GREEN); //fill styles with fill style color
				rectangle(right, top, right + 110, top + 30);
				floodfill(right + 100, top + 15, WHITE);
			}
			else if (bricks[row][col] == 4){
				setfillstyle(SOLID_FILL, BROWN); //fill styles with fill style color
				rectangle(right, top, right + 110, top + 30);
				floodfill(right + 100, top + 15, WHITE);
			}
			right += 110;
		}
		top += 30;
		if (row % 2 == 0){
			right = 160;
		}
		else if (row % 2 == 1){
			right = 100;
		}

	}

}

void ChangeBrick(int row, int col){

	int left = 50 + (col * 110);
	int right = left + 110;
	int top = 50 + (row * 30);
	int bottom = top + 30;
	int color;


	if (bricks[row][col] == 0){
		setfillstyle(SOLID_FILL, BLACK); //fill styles with fill style color
		rectangle(right, top, left, bottom);
		floodfill(right + 100, top + 15, WHITE);
	}
	else if (bricks[row][col] == 1){
		setfillstyle(SOLID_FILL, BLUE); //fill styles with fill style color
		rectangle(right, top, left, bottom);
		floodfill(right + 100, top + 15, WHITE);
	}
	else if (bricks[row][col] == 2){
		setfillstyle(SOLID_FILL, RED); //fill styles with fill style color
		rectangle(right, top, left, bottom);
		floodfill(right + 100, top + 15, WHITE);
	}

}

void strikePad(int posX){
	setfillstyle(SOLID_FILL, 4); //fill styles with fill style color
	rectangle(posX - 70, 650, posX + 70, 680);
	floodfill(posX, 665, WHITE);

	setfillstyle(SOLID_FILL, 15); //fill styles with fill style color
	sector(posX - 70, 665, 90, 270, 15, 15);
	floodfill(posX - 75, 665, WHITE);
	setfillstyle(SOLID_FILL, 15); //fill styles with fill style color
	sector(posX + 70, 665, 270, 90, 15, 15);
	floodfill(posX + 75, 665, WHITE);

}

void removeStrikePad(int posX){
	setfillstyle(SOLID_FILL, BLACK); //fill styles with fill style color
	rectangle(posX - 70, 650, posX + 70, 680);
	floodfill(posX, 650, BLACK);
}

void ballPosition(int x, int y){

	setfillstyle(SOLID_FILL, BLACK); //fill styles with fill style color
	circle(x, y, 12);
	floodfill(x, y, BLACK);

	setfillstyle(SOLID_FILL, WHITE); //fill styles with fill style color
	circle(x, y, 12);
	floodfill(x, y, WHITE);
}
