#include "Sudoku.h"
int board[9][9];
void Sudoku::giveQuestion(){
	    int give_map[81]={
			        0,2,1,0,6,0,5,9,0,
					        0,0,0,0,0,0,0,0,2,
							        4,0,0,2,0,5,0,6,3,
									        3,0,7,6,0,0,0,0,0,
											        0,9,5,0,0,0,3,2,0,
													        0,0,0,0,0,3,7,0,1,
															        9,3,0,4,0,2,0,0,7,
																	        5,0,0,0,0,0,0,0,0,
																			        0,1,2,0,9,0,6,3,0};
		    for (int i=0; i<81; ++i) {
				        cout<<give_map[i]<<" ";
						        if ((i%9)==8) cout<<'\n';
								    }
}


bool Sudoku::Check(){
	    if (answerNum<=2) {
			        int row, col;
					        if (!GetSpace(row, col)){
								            answerNum++;
											            return 1;
														        }
							        for (int num = 1; num <= 9; num++){
										            if (IsCorrect(row, col, num)){
														                map[row][col] = num;
																		                if (Check()){
																							                    if (answerNum==1) {
																													                        for (int i=0; i<9; i++) {
																																				                            for (int j=0; j<9; j++) {
																																												                                board[i][j]=map[i][j];
																																																				                            }
																																											                        }
																																			                    }
																												                    if (answerNum==2) {
																																		                        return 1;
																																								                    }
																																	                }
																						                map[row][col]=0;
																										            }
													        }
									    }
		    return 0;
}

void Sudoku::solve(){
	    answerNum=0;
		    Check();
			    if (answerNum==1) {
					        cout<<'1'<<endl;
							        for (int i=0; i<9; i++) {
										            for (int j=0; j<9; j++) {
														                map[i][j]=board[i][j];
																		            }
													        }
									        printMap();
											    }
				    if (answerNum==2) {
						        cout<<'2'<<endl;
								    }
					    if (answerNum==0) {cout<<'0'<<endl;}
}

bool Sudoku::GetSpace(int &row, int &col)
{
	    for (row = 0; row < 9; row++)
			        for (col = 0; col < 9; col++)
						            if (map[row][col]==0)
										                return 1;
		    return 0;
}

bool Sudoku::CheckRow(int row, int num)
{
	    for (int col = 0; col < 9; col++){
			        if (map[row][col] == num){return 1;}
					    }
		    return 0;
}

bool Sudoku::CheckCol(int col, int num){
	    for (int row = 0; row < 9; row++){
			        if (map[row][col] == num){return 1;}
					    }
		    return 0;
}

bool Sudoku::CheckBox(int RowS, int ColS, int num){
	    for (int row = 0; row < 3; row++){
			        for (int col = 0; col < 3; col++){
						            if (map[row+RowS][col+ColS] == num){return 1;}
									        }
					    }
		    return 0;
}

bool Sudoku::IsCorrect(int row, int col, int num){
	    return !CheckRow(row,num) && !CheckCol(col,num) && !CheckBox(row-row%3,col-col%3,num);
}
void Sudoku::readIn(){
	    for (int i=0; i<9; i++) {
			        for (int j=0; j<9; j++) {
						            cin>>map[i][j];
									        }
					    }
}
void Sudoku::printMap(){
	    for (int i=0; i<9; i++){
			        for (int j=0; j<9; j++)
						            cout<<map[i][j]<<' ';
					        cout<<endl;
							    }
}
void Sudoku::changeNum(int a,int b){
	    int temp[9][9];
		    for (int i=0; i<9; i++)
				        for(int j=0;j<9;j++){temp[i][j]=map[i][j];}
			    for (int i=0; i<9; i++) {
					        for (int j=0; j<9; j++) {
								            if (map[i][j]==a){
												                map[i][j]=b;
																            }
											            if (temp[i][j]==b) {
															                map[i][j]=a;
																			            }
														        }
							    }
}
void Sudoku::changeRow(int a,int b){
	    int c=a*3;
		    int d=b*3;
			    int temp[3][9];
				    for (int i=0; i<3; i++) {
						        for (int j=0; j<9; j++) {
									            temp[i][j]=map[i+c][j];
												        }
								    }
					    for (int i=0; i<3; i++) {
							        for (int j=0; j<9; j++) {
										            map[i+c][j]=map[i+d][j];
													        }
									    }
						    for (int i=0; i<3; i++) {
								        for (int j=0; j<9; j++) {
											            map[i+d][j]=temp[i][j];
														        }
										    }
}
void Sudoku::changeCol(int a,int b){
			    int temp[9][3];
				    for (int i=0; i<9; i++) {
						        for (int j=0; j<3; j++) {
									            temp[i][j]=map[i][a*3+j];
												        }
								    }
					    for (int i=0; i<9; i++) {
							        for (int j=0; j<3; j++) {
										            map[i][a*3+j]=map[i][b*3+j];
													        }
									    }
						    for (int i=0; i<9; i++) {
								        for (int j=0; j<3; j++) {
											            map[i][b*3+j]=temp[i][j];
														        }
										    }
}

void Sudoku::rot(int &a,int &b,int &c,int &d){
	    int temp=a;
		    a=b;
			    b=c;
				    c=d;
					    d=temp;
}
void Sudoku::rotate(int n){
	    int count=n%4;
		    int a=9;
			    if (count==1){
					        for(int i=0; i<a/2; i++)
								            for(int j=0; j<(a+1)/2; j++)
												                rot(map[i][j], map[a-1-j][i], map[a-1-i][a-1-j], map[j][a-1-i]);
							    }
				    if (count==2){
						        for(int i=0; i<a/2; i++)
									            for(int j=0; j<(a+1)/2; j++)
													                rot(map[i][j], map[a-1-j][i], map[a-1-i][a-1-j], map[j][a-1-i]);
								        for(int i=0; i<a/2; i++)
											            for(int j=0; j<(a+1)/2; j++)
															                rot(map[i][j], map[a-1-j][i], map[a-1-i][a-1-j], map[j][a-1-i]);
										    }
					    if (count==3){
							        for(int i=0; i<a/2; i++)
										            for(int j=0; j<(a+1)/2; j++)
														                rot(map[i][j], map[a-1-j][i], map[a-1-i][a-1-j], map[j][a-1-i]);
									        for(int i=0; i<a/2; i++)
												            for(int j=0; j<(a+1)/2; j++)
																                rot(map[i][j], map[a-1-j][i], map[a-1-i][a-1-j], map[j][a-1-i]);
											        for(int i=0; i<a/2; i++)
														            for(int j=0; j<(a+1)/2; j++)
																		                rot(map[i][j], map[a-1-j][i], map[a-1-i][a-1-j], map[j][a-1-i]);
													    }
}

void Sudoku::flip(int a){
	    int tmp;
		    if (a==1) {
				        for (int i=0; i<9;  i++) {
							            for (int j=0; j<9/2 ; j++)  {
											                tmp=map[i][j];
															                map[i][j]=map[i][9-1-j];
																			                map[i][9-1-j]=tmp;
																							            }
										        }
						    }
			    if (a==0) {
					        for (int i=0; i<9/2; i++) {
								            for (int j=0; j<9; j++) {
												                tmp=map[i][j];
																                map[i][j]=map[9-1-i][j];
																				                map[9-1-i][j]=tmp;
																								            }
											        }
							    }
}

void Sudoku::change(){
	    srand(unsigned(time(NULL)));
		    changeNum(rand()%9+1, rand()%9+1) ;
			    changeRow(rand()%3, rand()%3) ;
				    changeCol(rand()%3, rand()%3) ;
					    rotate(rand()%101) ;
						    flip(rand()%2) ;
}

void Sudoku::transform(){
	    change();
}
