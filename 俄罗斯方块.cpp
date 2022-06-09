#include<iostream>
#include<string>
#include<cstdlib>
#include<windows.h>
#include<ctime>
#include<conio.h>
#include<cstdio>
#include<chrono>
using namespace std;

class Tetris
{
private:
	int rank;				//游戏难度等级
	int score;				// 得分
	int id;					//图形ID
	int point[2];			//两基点
	int top;				//最高点高度
public:
	Tetris();
	void Welocme();			//首界面
	void DrawMap();			//游戏界面
	void SetColor(int);		//控制颜色
	void Draw(int, int, int);		//画图形
	void Run();				//运行游戏
	void ReDraw(int, int, int);			//清除图形
	bool Judge(int, int, int);
	void Turn(int);				//旋转
	void Updata();				// 更新界面
	void Pause();				//游戏暂停
	void Input_score();
	void AddLine();		//10s随机加一行不满的
};

const int sharp[25][10] =	//组成图形的各个点的各个坐标，x是纵向，y是横向，左上是0,0
{
	//条形
	{0,0,1,0,2,0,3,0},{0,0,0,1,0,2,0,3},
	//方块
	{0,0,1,0,0,1,1,1},
	//L形
	{0,0,1,0,1,1,1,2},{0,1,1,1,2,0,2,1},{0,0,0,1,0,2,1,2},{0,0,0,1,1,0,2,0},
	//J形
	{1,0,1,1,1,2,0,2},{0,0,0,1,1,1,2,1},{0,0,0,1,0,2,1,0},{0,0,1,0,2,0,2,1},
	//T形 尖端朝上，右，下，左
	{0,1,1,0,1,1,1,2},{0,0,1,0,2,0,1,1} , {0,0,0,1,0,2,1,1},{0,1,1,0,1,1,2,1},
	//S形
	{0,0,1,0,1,1,2,1},{0,1,0,2,1,0,1,1},
	//Z形
	{0,1,1,0,1,1,2,0},{0,0,0,1,1,1,1,2},
	//子弹
	{0,0,0,0,0,0,0,0},
	//U形方块id20-23
	{0,0,0,2,1,0,1,1,1,2},{0,0,0,1,1,0,2,0,2,1},{0,0,0,1,0,2,1,0,1,2},{0,0,0,1,1,1,2,0,2,1},
	//十形方块id24
	{0,1,1,0,1,1,1,2,2,1}
};

//每个图形的纵深
const int high[25] = { 4,1,2,2,3,2,3,2,3,2,3,2,3,2,3,3,2,3,2,1,2,3,2,3,3};
int map[28][16];
//条形
#define a1  0			
#define a2  1

// 方块
#define b 2					

//L形
#define c1 3					
#define c2 4
#define c3 5
#define c4 6

//J形
#define d1 7					
#define d2 8 
#define d3 9
#define d4 10

//T形
#define e1 11
#define e2 12
#define e3 13
#define e4 14
//S形
#define f1 15
#define f2 16
//Z形
#define g1 17
#define g2 18
//子弹
#define h 19
//U形
#define i1 20
#define i2 21
#define i3 22
#define i4 23




Tetris::Tetris()				//构造函数， 初始化各个值
{
	point[0] = 0;
	point[1] = 5;
	score = 0;
	top = 25;
}

void Tetris::Turn(int num)				//旋转函数
{
	/*
	通过条形旋转的方式完成其他形状的旋转
	
	有兴趣的同学也可以通过其他方法完成此功能
	*/
	switch (num)
	{
	//条形旋转
	case a1: id = a2; break;					
	case a2: id = a1; break;

	//方块旋转
	case b:break;//不转
	//L形旋转
	case c1:id = c4; break;
	case c2:id = c1; break;
	case c3:id = c2; break;
	case c4:id = c3; break;
	//J型旋转
	case d1:id = d4; break;
	case d2:id = d1; break;
	case d3:id = d2; break;
	case d4:id = d3; break;
	//T形旋转
	case e1:id = e4; break;
	case e2:id = e1; break;
	case e3:id = e2; break;
	case e4:id = e3; break;
	//S形旋转
	case f1:id = f2; break;
	case f2:id = f1; break;
	//Z形旋转
	case g1:id = g2; break;
	case g2:id = g1; break;
	//U形旋转
	case i1:id = i2; break;
	case i2:id = i3; break;
	case i3:id = i4; break;
	case i4:id = i1; break;
	}
}

void SetPos(int i, int j)			//控制光标位置， 列， 行
{
	COORD pos = { i,j };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Tetris::Pause()				// 暂停函数
{
	SetPos(32, 10);
	cout << "游戏暂停!" << endl;
	SetPos(30, 11);
	cout << "你的分数为 " << score;
	char temp;
	while (1)
	{
		while (1)
		{
			if (_kbhit())
			{
				temp = _getch();
				break;
			}
		}
		if (temp == 32)
			break;
	}
	SetPos(32, 10);					// 清除暂停时显示的信息
	cout << "         ";
	SetPos(30, 11);
	cout << "              ";
}

void Tetris::Updata()					//更新函数
{
	int i, flag;
	int nx, ny;
	//最后一次的绘图
	if(id<20)
	{
		for (i = 0; i < 4; i++)
		{
			nx = point[0] + sharp[id][i * 2];
			ny = point[1] + sharp[id][i * 2 + 1];
			SetPos((ny + 1) * 2, nx + 1);
			SetColor(0);
			cout << "■";
			map[nx][ny] = 1;					//界面各个点是否为空的更新
		}
	}
	else if(id<24)
	{
		for (i = 0; i < 5; i++)
		{
			nx = point[0] + sharp[id][i * 2];
			ny = point[1] + sharp[id][i * 2 + 1];
			SetPos((ny + 1) * 2, nx + 1);
			SetColor(0);
			cout << "■";
			map[nx][ny] = 1;					//界面各个点是否为空的更新
		}
	}
	else
	{
		for (i = 0; i < 5; i++)
		{
			nx = point[0] + sharp[id][i * 2];
			ny = point[1] + sharp[id][i * 2 + 1];
			map[nx][ny] = 2;					//界面各个点是否为空的更新
		}
	}
	
	//这里更新top的意义未知,很好，根本没做过右值,没有意义。
	if (point[0] < top)
		top = point[0];					//最高点的更新

	for (i = point[0]; i < point[0] + high[id]; i++)			//消除行
	{
		//将flag赋值为1，flag为1表示某一行满，0表示未满。
		flag = 1;
		
		// map[i][j] == 0表示在地图的第i行，第j列的地方没有方块，输出的形式为"  "
		// map[i][j] == 1表示在地图的第i行，第j列的地方有方块，输出的形式为"■"
		
		//注：游戏区的列数为13列

		//判断某一行是否为满
		/*
		请在下方补全判断是否为满功能代码
		*/
		for(int j=0;j<13;++j)
		{
			if (map[i][j] != 1)//说明是0（空）或是2（不可消除方块）
			{
				flag = 0;
				break;
			}	
		}


		//当flag为1时，消行
		if (flag == 1)
		{
			/*
			请在下方补全消行功能代码
			*/
			for(int j=0;j<13;++j)
			{
				nx = i;
				ny = j;
				SetPos((ny + 1) * 2, nx + 1);
				SetColor(0);
				cout << "  ";
				map[nx][ny] = 0;					//界面各个点为空的更新
			}
			for(int k=i-1;k>0;--k)//第i行往上开始往下掉
			{
				for(int l=0;l<13;++l)
				{
					if(map[k][l]==1)
					{
						//撤销该位置
						SetPos((l+1)* 2, k + 1);
						cout << "  ";
						map[k][l] = 0;
						//往下掉一格重绘
						SetPos((l + 1) * 2, k+2);
						cout << "■";
						map[k + 1][l] = 1;
					}
				}
			}
			//计算得分
			score += 10;
			Input_score();
		}
	}
}

/// <summary>
/// 设置颜色，设置坐标，输出属性score
/// </summary>
void Tetris::Input_score()
{
	SetColor(3);
	SetPos(30, 19);
	cout << "得分: " << score;
}
void Tetris::AddLine()
{
	for(int i=0;i<2;++i)//先扫一遍第一行和第二行，如果有格子，就直接结束，因为要加一行
	{
		for(int j=0;j<13;++j)
		{
			if(map[i][j]==1||map[i][j]==2)
			{
				system("cls");
				SetPos(20, 10);
				cout << "游戏结束,因为到了加行时间，顶到屏幕边缘了！" << endl;
				SetPos(20, 11);
				cout << "你的分数为 " << score << endl;
				system("pause");
				exit(1);
			}
		}
	}
	for(int i=2;i<25;++i)
	{
		for(int j=0;j<13;++j)
		{
			if(map[i][j]==1)
			{
				//擦除原来的方块
				SetPos((j + 1) * 2, i + 1);
				SetColor(0);
				cout << "  ";
				map[i][j] = 0;					//界面各个点为空的更新
				//在上一行画上新的方块
				SetPos((j + 1) * 2, i);
				cout << "■";
				map[i-1][j] = 1;
			}
			else if(map[i][j]==2)
			{
				SetPos((j + 1) * 2, i + 1);
				SetColor(6);
				cout << "  ";
				map[i][j] = 0;					//界面各个点为空的更新
				//在上一行画上新的方块
				SetPos((j + 1) * 2, i);
				cout << "■";
				map[i - 1][j] = 2;
			}
		}
	}
	SetColor(0);
	for(int i=0;i<13;++i)//在最后一行生成随机序列
	{
		if(rand()%2==0)//是偶数就生成
		{
			SetPos((i + 1) * 2, 25);
			cout << "■";
			map[24][i] = 1;
		}
	}
	Sleep(1);
}
/// <summary>
/// 初始化一个控制难度的属性rank，提示用户怎么操作
/// </summary>
void Tetris::Welocme()			//欢迎界面
{
	SetColor(1);	//欢迎菜单的颜色
	char x;
	while (1)
	{
		system("cls");	//清屏
		cout << "■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "		俄罗斯方块		" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "		操作方式：" << endl;
		cout << "		↑ - 旋转" << endl;
		cout << "		↓ - 加速下移" << endl;
		cout << "		← - 左移" << endl;
		cout << "		→ - 右移" << endl;
		cout << "		空格 - 暂停" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■ 按1—3选择难度■" << endl;
		SetPos(20, 10);//把光标位置从上一句话的行尾放到“度”字后面
		x = getchar();
		if (x <= '9' && x >= '0')//选择难度，0-9，和上面提示不符合
		{
			rank = x - '0';
			break;
		}
	}
}
/// <summary>
/// 6是白色
/// </summary>
/// <param name="color_num"></param>
void Tetris::SetColor(int color_num)			//设置颜色
{
	int n;
	switch (color_num)
	{
	case 0: n = 0x08; break;
	case 1: n = 0x0C; break;
	case 2: n = 0x0D; break;
	case 3: n = 0x0E; break;
	case 4: n = 0x0A; break;
	case 5:n = 0x01; break;
	case 6:n = 0x07; break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
}

void Tetris::DrawMap()				//画游戏时界面
{
	int i;
	SetColor(0);

	for (i = 0; i < 24; i++)		//宽24格
	{
		SetPos(i * 2, 0);//游戏界面顶上的方格
		cout << "■";
		SetPos(i * 2, 26);//游戏界面底下的方格
		cout << "■";
	}

	for (i = 0; i < 26; i++)		//高26格
	{
		SetPos(0, i);
		cout << "■";
		SetPos(28, i);
		cout << "■";
		SetPos(46, i);
		cout << "■";
	}

	for (i = 14; i < 24; i++)//分开“下一个图形”和“得分”的区域
	{
		SetPos(i*2 , 16);
		cout << "■";
	}

	SetColor(3);
	Input_score();
	SetPos(30, 21);
	cout << "难度等级: " << rank;
	SetPos(32, 2);
	cout << "下一图形";
}

/// <summary>
/// 设置坐标为基准X+特定图形点的X坐标和基准Y+特定图形点的Y坐标 输出方块
/// 颜色是循环的
/// </summary>
/// <param name="x">基准点的X坐标</param>
/// <param name="y">基准点的Y坐标</param>
/// <param name="num">图形ID</param>
void Tetris::Draw(int x, int y, int num)				//画图形
{
	int nx, ny;
	if(num<20)
	{
		for (int i = 0; i < 4; i++)
		{
			nx = x + sharp[num][2 * i];
			ny = y + sharp[num][2 * i + 1];
			SetPos((ny + 1) * 2, nx + 1);
			SetColor(i + 1);
			cout << "■";
		}
	}
	else if(num<24)
	{
		for (int i = 0; i < 5; i++)
		{
			nx = x + sharp[num][2 * i];
			ny = y + sharp[num][2 * i + 1];
			SetPos((ny + 1) * 2, nx + 1);
			SetColor(i + 1);
			cout << "■";
		}
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			nx = x + sharp[num][2 * i];
			ny = y + sharp[num][2 * i + 1];
			SetPos((ny + 1) * 2, nx + 1);
			SetColor(6);
			cout << "■";
		}
	}
}

void Tetris::ReDraw(int x, int y, int num)				//为更新图形的位置清除图形
{
	int nx, ny;
	if(num<20)
	{
		for (int i = 0; i < 4; i++)
		{
			nx = x + sharp[num][2 * i];
			ny = y + sharp[num][2 * i + 1];
			if (map[nx][ny] == 0)//如果这里没有东西，重绘空格，不然不动
			{
				SetPos((ny + 1) * 2, nx + 1);
				cout << "  ";
			}
			else
			{
				SetColor(0);
				cout << "■";
			}

		}
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			nx = x + sharp[num][2 * i];
			ny = y + sharp[num][2 * i + 1];
			if (map[nx][ny] == 0)//如果这里没有东西，重绘空格，不然不动
			{
				SetPos((ny + 1) * 2, nx + 1);
				cout << "  ";
			}
			else
			{
				SetColor(0);
				cout << "■";
			}

		}
	}
	
}
/// <summary>
/// 判定在x, y 所指位置是否可画编号为num 的图形， 若不可画则反回true
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="num"></param>
/// <returns>如果不能画true，能画false</returns>
bool Tetris::Judge(int x, int y, int num)				
{													
	int nx, ny;
	if(num<20)
	{
		for (int i = 0; i < 4; i++)
		{
			nx = x + sharp[num][2 * i];
			ny = y + sharp[num][2 * i + 1];
			if (!(nx < 25 && nx >= 0 && ny < 13 && ny >= 0 && !map[nx][ny]))
				return true;
		}
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			nx = x + sharp[num][2 * i];
			ny = y + sharp[num][2 * i + 1];
			if (!(nx < 25 && nx >= 0 && ny < 13 && ny >= 0 && !map[nx][ny]))
				return true;
		}
	}
	
	return false;
}

void Tetris::Run()					//运行游戏
{
	int next_id;
	srand((int)time(0));			//以时间设置随机种子
	
	id = 17;
	next_id =  18;

	Draw(point[0], point[1], id);
	Draw(5, 16, next_id);

	int count;
	if (rank == 1)
		count = 150;
	else if (rank == 2)
		count = 100;
	else if (rank == 3)
		count = 50;
	else
		count = 5;
	int i = 0;  //不同等级对应不同count
	int speed=1;//子弹移动速度
	time_t start, finish;
	time_t bullStart, bullEnd;//子弹time
	finish=start = time(nullptr);
	bullStart = bullEnd = time(nullptr);
	bool reset = true;
	while (1)
	{
		
		if (!(i < count))				//i 与 count 用于控制时间
		{
			if(id==19)//因为子弹是左右动的，要额外处理一下
			{
				if(reset)//重新计时
				{
					bullStart = bullEnd = time(nullptr);
					reset = false;
					
				}
				bullEnd = time(nullptr);
				if(difftime(bullEnd, bullStart) >= 5)
				{
					ReDraw(point[0], point[1], id);
					id = next_id;
					ReDraw(5, 16, next_id);
					next_id = rand() % 25;
					point[0] = 0; point[1] = 5;
					Draw(point[0], point[1], id);
					Draw(5, 16, next_id);
					bullStart = bullEnd;
					reset = true;
				}
				else
				{
					if (!Judge(point[0], point[1], id))
					{
						ReDraw(point[0], point[1], id);
						if (point[1] >= 12||point[1]<=0)
							speed = -speed;
						point[1] += speed;
						
						Draw(point[0], point[1], id);
						Sleep(100);
					}
				}
				
			}
			if (id != 19)
			{
				i = 0;
				if (Judge(point[0] + 1, point[1], id))			//在某一位置不能下落的话
				{
					Updata();
					id = next_id;

					ReDraw(5, 16, next_id);
					next_id = rand() % 25;

					point[0] = 0; point[1] = 5;
					Draw(point[0], point[1], id);
					Draw(5, 16, next_id);

					if (Judge(point[0], point[1], id))
					{
						system("cls");
						SetPos(20, 10);
						cout << "游戏结束！" << endl;
						SetPos(20, 11);
						cout << "你的分数为 " << score << endl;
						system("pause");
						exit(1);
					}
				}
				else					//继续下落
				{
					if (difftime(finish, start) < 10)
					{
						ReDraw(point[0], point[1], id);
						point[0]++;
						Draw(point[0], point[1], id);
					}
					
				}
			}
			if (difftime(finish, start) >= 10)
			{
				start = finish;
				AddLine();
			}
		}

		if (_kbhit())				//键盘输入值时 
		{
			int key, key2;
			key = _getch();			//方向键会返回两个值，第一个是公共的224，第二个是分开的，所以要getch两次
			if (key == 224)
			{
				key2 = _getch();

				if (key2 == 72&& id != 19)			//按向上方向键时
				{
					int temp = id;
					Turn(id);
					if (Judge(point[0], point[1], id))
						id = temp;
					ReDraw(point[0], point[1], temp);
					Draw(point[0], point[1], id);
				}
				if (key2 == 72 && id == 19)			//子弹，按向上方向键
				{
					for (int i=point[0];i<26;++i)
					{
						if(map[i][point[1]]!=0||i==25)//这一列的第一个碰撞点是(i,point[1])，没有碰撞点落地
						{
							SetPos((point[1] + sharp[id][1] + 1) * 2, i + sharp[id][0] );
							SetColor(0);
							cout << "■";
							map[i-1][point[1]] = 1;

							//检测消除行
							
							//将flag赋值为1，flag为1表示某一行满，0表示未满。
							bool flag = 1;
							for (int j = 0; j < 13; ++j)
							{
								if (map[i-1][j] == 0)//有空的地方说明没有满
								{
									flag = 0;
									break;
								}
							}
							//当flag为1时，消行
							if (flag == 1)
							{
								/*
								请在下方补全消行功能代码
								*/
								for (int j = 0; j < 13; ++j)
								{
									int nx = i;
									int ny = j;
									SetPos((ny + 1) * 2, nx + 1);
									SetColor(0);
									cout << "  ";
									map[nx][ny] = 0;					//界面各个点为空的更新
								}
								for (int k = i - 1; k > 0; --k)//第i行往上开始往下掉
								{
									for (int l = 0; l < 13; ++l)
									{
										if (map[k][l] == 1)
										{
											//撤销该位置
											SetPos((l + 1) * 2, k + 1);
											cout << "  ";
											map[k][l] = 0;
											//往下掉一格重绘
											SetPos((l + 1) * 2, k + 2);
											cout << "■";
											map[k + 1][l] = 1;
										}
									}
								}
								//计算得分
								score += 10;
								Input_score();
							}
							break;
						}
					}
					if (Judge(point[0], point[1], id))//有可能会over，检测一下
					{
						system("cls");
						SetPos(20, 10);
						cout << "游戏结束！" << endl;
						SetPos(20, 11);
						cout << "你的分数为 " << score << endl;
						system("pause");
						exit(1);
					}
					
				}
				if (key2 == 80&&id!=19)				//按向下方向键时
				{
					if (!Judge(point[0] + 2, point[1], id))
					{
						ReDraw(point[0], point[1], id);
						point[0] += 2;
						Draw(point[0], point[1], id);
					}
				}
				else if(key2 == 80 && id == 19)//向下的子弹
				{
					for (int i = point[0]; i < 25; ++i)
					{
						if (map[i][point[1]] != 0 || i == 24)//这一列的第一个碰撞点是(i,point[1])，没有碰撞点落地
						{
							SetPos((point[1] + sharp[id][1] + 1) * 2, i + sharp[id][0]+1);
							SetColor(0);
							cout << "  ";
							map[i][point[1]] = 0;
							break;
						}
					}
				}
				else if (key2 == 75&&id!=19)				//按向左方向键时
				{
					if (!Judge(point[0], point[1] - 1, id))
					{
						ReDraw(point[0], point[1], id);
						point[1]--;
						Draw(point[0], point[1], id);
					}
				}
				else if (key2 == 77&&id!=19)					//按向右方向键时
				{
					if (!Judge(point[0], point[1] + 1, id))
					{
						ReDraw(point[0], point[1], id);
						point[1]++;
						Draw(point[0], point[1], id);
					}
				}
			}
			else if (key == 32)					// 按下空格暂停，把计时器存一下
			{
				time_t tempTime = finish;
				time_t tempBulltime = bullEnd;
				Pause();
				finish = tempTime;
				bullEnd = tempBulltime;
			}
				
				
		}

		Sleep(1);		//等待1毫秒
		i++;				//控制下落间隔
		finish = time(nullptr);
		
		
	}
}

int main()
{
	Tetris game;
	game.Welocme();
	system("cls");				//清除欢迎界面
	game.DrawMap();
	game.Run();
}





