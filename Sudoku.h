#include <iostream>
#include <stdlib.h>
using namespace::std;
class Sudoku{
	public:
		    int answerNum;
			    int map[9][9];
				    bool GetSpace(int &row, int &col);
					    bool IsCorrect(int row, int col, int num);
						    bool Check();
							    void solve();
								    bool CheckRow(int row, int num);
									    bool CheckCol(int col, int num);
										    bool CheckBox(int RowS, int ColS, int num);
											    void readIn();
												    void printMap();
													    void giveQuestion();
														    void rot(int &a,int &b,int &c,int &d);
															    void changeNum(int a,int b);
																    void changeCol(int a,int b);
																	    void changeRow(int a,int b);
																		    void rotate(int n);
																			    void flip(int a);
																				    void change();
																					    void transform();
};
