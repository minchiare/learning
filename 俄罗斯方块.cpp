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
	int rank;				//��Ϸ�Ѷȵȼ�
	int score;				// �÷�
	int id;					//ͼ��ID
	int point[2];			//������
	int top;				//��ߵ�߶�
public:
	Tetris();
	void Welocme();			//�׽���
	void DrawMap();			//��Ϸ����
	void SetColor(int);		//������ɫ
	void Draw(int, int, int);		//��ͼ��
	void Run();				//������Ϸ
	void ReDraw(int, int, int);			//���ͼ��
	bool Judge(int, int, int);
	void Turn(int);				//��ת
	void Updata();				// ���½���
	void Pause();				//��Ϸ��ͣ
	void Input_score();
	void AddLine();		//10s�����һ�в�����
};

const int sharp[25][10] =	//���ͼ�εĸ�����ĸ������꣬x������y�Ǻ���������0,0
{
	//����
	{0,0,1,0,2,0,3,0},{0,0,0,1,0,2,0,3},
	//����
	{0,0,1,0,0,1,1,1},
	//L��
	{0,0,1,0,1,1,1,2},{0,1,1,1,2,0,2,1},{0,0,0,1,0,2,1,2},{0,0,0,1,1,0,2,0},
	//J��
	{1,0,1,1,1,2,0,2},{0,0,0,1,1,1,2,1},{0,0,0,1,0,2,1,0},{0,0,1,0,2,0,2,1},
	//T�� ��˳��ϣ��ң��£���
	{0,1,1,0,1,1,1,2},{0,0,1,0,2,0,1,1} , {0,0,0,1,0,2,1,1},{0,1,1,0,1,1,2,1},
	//S��
	{0,0,1,0,1,1,2,1},{0,1,0,2,1,0,1,1},
	//Z��
	{0,1,1,0,1,1,2,0},{0,0,0,1,1,1,1,2},
	//�ӵ�
	{0,0,0,0,0,0,0,0},
	//U�η���id20-23
	{0,0,0,2,1,0,1,1,1,2},{0,0,0,1,1,0,2,0,2,1},{0,0,0,1,0,2,1,0,1,2},{0,0,0,1,1,1,2,0,2,1},
	//ʮ�η���id24
	{0,1,1,0,1,1,1,2,2,1}
};

//ÿ��ͼ�ε�����
const int high[25] = { 4,1,2,2,3,2,3,2,3,2,3,2,3,2,3,3,2,3,2,1,2,3,2,3,3};
int map[28][16];
//����
#define a1  0			
#define a2  1

// ����
#define b 2					

//L��
#define c1 3					
#define c2 4
#define c3 5
#define c4 6

//J��
#define d1 7					
#define d2 8 
#define d3 9
#define d4 10

//T��
#define e1 11
#define e2 12
#define e3 13
#define e4 14
//S��
#define f1 15
#define f2 16
//Z��
#define g1 17
#define g2 18
//�ӵ�
#define h 19
//U��
#define i1 20
#define i2 21
#define i3 22
#define i4 23




Tetris::Tetris()				//���캯���� ��ʼ������ֵ
{
	point[0] = 0;
	point[1] = 5;
	score = 0;
	top = 25;
}

void Tetris::Turn(int num)				//��ת����
{
	/*
	ͨ��������ת�ķ�ʽ���������״����ת
	
	����Ȥ��ͬѧҲ����ͨ������������ɴ˹���
	*/
	switch (num)
	{
	//������ת
	case a1: id = a2; break;					
	case a2: id = a1; break;

	//������ת
	case b:break;//��ת
	//L����ת
	case c1:id = c4; break;
	case c2:id = c1; break;
	case c3:id = c2; break;
	case c4:id = c3; break;
	//J����ת
	case d1:id = d4; break;
	case d2:id = d1; break;
	case d3:id = d2; break;
	case d4:id = d3; break;
	//T����ת
	case e1:id = e4; break;
	case e2:id = e1; break;
	case e3:id = e2; break;
	case e4:id = e3; break;
	//S����ת
	case f1:id = f2; break;
	case f2:id = f1; break;
	//Z����ת
	case g1:id = g2; break;
	case g2:id = g1; break;
	//U����ת
	case i1:id = i2; break;
	case i2:id = i3; break;
	case i3:id = i4; break;
	case i4:id = i1; break;
	}
}

void SetPos(int i, int j)			//���ƹ��λ�ã� �У� ��
{
	COORD pos = { i,j };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Tetris::Pause()				// ��ͣ����
{
	SetPos(32, 10);
	cout << "��Ϸ��ͣ!" << endl;
	SetPos(30, 11);
	cout << "��ķ���Ϊ " << score;
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
	SetPos(32, 10);					// �����ͣʱ��ʾ����Ϣ
	cout << "         ";
	SetPos(30, 11);
	cout << "              ";
}

void Tetris::Updata()					//���º���
{
	int i, flag;
	int nx, ny;
	//���һ�εĻ�ͼ
	if(id<20)
	{
		for (i = 0; i < 4; i++)
		{
			nx = point[0] + sharp[id][i * 2];
			ny = point[1] + sharp[id][i * 2 + 1];
			SetPos((ny + 1) * 2, nx + 1);
			SetColor(0);
			cout << "��";
			map[nx][ny] = 1;					//����������Ƿ�Ϊ�յĸ���
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
			cout << "��";
			map[nx][ny] = 1;					//����������Ƿ�Ϊ�յĸ���
		}
	}
	else
	{
		for (i = 0; i < 5; i++)
		{
			nx = point[0] + sharp[id][i * 2];
			ny = point[1] + sharp[id][i * 2 + 1];
			map[nx][ny] = 2;					//����������Ƿ�Ϊ�յĸ���
		}
	}
	
	//�������top������δ֪,�ܺã�����û������ֵ,û�����塣
	if (point[0] < top)
		top = point[0];					//��ߵ�ĸ���

	for (i = point[0]; i < point[0] + high[id]; i++)			//������
	{
		//��flag��ֵΪ1��flagΪ1��ʾĳһ������0��ʾδ����
		flag = 1;
		
		// map[i][j] == 0��ʾ�ڵ�ͼ�ĵ�i�У���j�еĵط�û�з��飬�������ʽΪ"  "
		// map[i][j] == 1��ʾ�ڵ�ͼ�ĵ�i�У���j�еĵط��з��飬�������ʽΪ"��"
		
		//ע����Ϸ��������Ϊ13��

		//�ж�ĳһ���Ƿ�Ϊ��
		/*
		�����·���ȫ�ж��Ƿ�Ϊ�����ܴ���
		*/
		for(int j=0;j<13;++j)
		{
			if (map[i][j] != 1)//˵����0���գ�����2�������������飩
			{
				flag = 0;
				break;
			}	
		}


		//��flagΪ1ʱ������
		if (flag == 1)
		{
			/*
			�����·���ȫ���й��ܴ���
			*/
			for(int j=0;j<13;++j)
			{
				nx = i;
				ny = j;
				SetPos((ny + 1) * 2, nx + 1);
				SetColor(0);
				cout << "  ";
				map[nx][ny] = 0;					//���������Ϊ�յĸ���
			}
			for(int k=i-1;k>0;--k)//��i�����Ͽ�ʼ���µ�
			{
				for(int l=0;l<13;++l)
				{
					if(map[k][l]==1)
					{
						//������λ��
						SetPos((l+1)* 2, k + 1);
						cout << "  ";
						map[k][l] = 0;
						//���µ�һ���ػ�
						SetPos((l + 1) * 2, k+2);
						cout << "��";
						map[k + 1][l] = 1;
					}
				}
			}
			//����÷�
			score += 10;
			Input_score();
		}
	}
}

/// <summary>
/// ������ɫ���������꣬�������score
/// </summary>
void Tetris::Input_score()
{
	SetColor(3);
	SetPos(30, 19);
	cout << "�÷�: " << score;
}
void Tetris::AddLine()
{
	for(int i=0;i<2;++i)//��ɨһ���һ�к͵ڶ��У�����и��ӣ���ֱ�ӽ�������ΪҪ��һ��
	{
		for(int j=0;j<13;++j)
		{
			if(map[i][j]==1||map[i][j]==2)
			{
				system("cls");
				SetPos(20, 10);
				cout << "��Ϸ����,��Ϊ���˼���ʱ�䣬������Ļ��Ե�ˣ�" << endl;
				SetPos(20, 11);
				cout << "��ķ���Ϊ " << score << endl;
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
				//����ԭ���ķ���
				SetPos((j + 1) * 2, i + 1);
				SetColor(0);
				cout << "  ";
				map[i][j] = 0;					//���������Ϊ�յĸ���
				//����һ�л����µķ���
				SetPos((j + 1) * 2, i);
				cout << "��";
				map[i-1][j] = 1;
			}
			else if(map[i][j]==2)
			{
				SetPos((j + 1) * 2, i + 1);
				SetColor(6);
				cout << "  ";
				map[i][j] = 0;					//���������Ϊ�յĸ���
				//����һ�л����µķ���
				SetPos((j + 1) * 2, i);
				cout << "��";
				map[i - 1][j] = 2;
			}
		}
	}
	SetColor(0);
	for(int i=0;i<13;++i)//�����һ�������������
	{
		if(rand()%2==0)//��ż��������
		{
			SetPos((i + 1) * 2, 25);
			cout << "��";
			map[24][i] = 1;
		}
	}
	Sleep(1);
}
/// <summary>
/// ��ʼ��һ�������Ѷȵ�����rank����ʾ�û���ô����
/// </summary>
void Tetris::Welocme()			//��ӭ����
{
	SetColor(1);	//��ӭ�˵�����ɫ
	char x;
	while (1)
	{
		system("cls");	//����
		cout << "������������������������������������������" << endl;
		cout << "		����˹����		" << endl;
		cout << "������������������������������������������" << endl;
		cout << "		������ʽ��" << endl;
		cout << "		�� - ��ת" << endl;
		cout << "		�� - ��������" << endl;
		cout << "		�� - ����" << endl;
		cout << "		�� - ����" << endl;
		cout << "		�ո� - ��ͣ" << endl;
		cout << "������������������������������������������" << endl;
		cout << "�� ��1��3ѡ���Ѷȡ�" << endl;
		SetPos(20, 10);//�ѹ��λ�ô���һ�仰����β�ŵ����ȡ��ֺ���
		x = getchar();
		if (x <= '9' && x >= '0')//ѡ���Ѷȣ�0-9����������ʾ������
		{
			rank = x - '0';
			break;
		}
	}
}
/// <summary>
/// 6�ǰ�ɫ
/// </summary>
/// <param name="color_num"></param>
void Tetris::SetColor(int color_num)			//������ɫ
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

void Tetris::DrawMap()				//����Ϸʱ����
{
	int i;
	SetColor(0);

	for (i = 0; i < 24; i++)		//��24��
	{
		SetPos(i * 2, 0);//��Ϸ���涥�ϵķ���
		cout << "��";
		SetPos(i * 2, 26);//��Ϸ������µķ���
		cout << "��";
	}

	for (i = 0; i < 26; i++)		//��26��
	{
		SetPos(0, i);
		cout << "��";
		SetPos(28, i);
		cout << "��";
		SetPos(46, i);
		cout << "��";
	}

	for (i = 14; i < 24; i++)//�ֿ�����һ��ͼ�Ρ��͡��÷֡�������
	{
		SetPos(i*2 , 16);
		cout << "��";
	}

	SetColor(3);
	Input_score();
	SetPos(30, 21);
	cout << "�Ѷȵȼ�: " << rank;
	SetPos(32, 2);
	cout << "��һͼ��";
}

/// <summary>
/// ��������Ϊ��׼X+�ض�ͼ�ε��X����ͻ�׼Y+�ض�ͼ�ε��Y���� �������
/// ��ɫ��ѭ����
/// </summary>
/// <param name="x">��׼���X����</param>
/// <param name="y">��׼���Y����</param>
/// <param name="num">ͼ��ID</param>
void Tetris::Draw(int x, int y, int num)				//��ͼ��
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
			cout << "��";
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
			cout << "��";
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
			cout << "��";
		}
	}
}

void Tetris::ReDraw(int x, int y, int num)				//Ϊ����ͼ�ε�λ�����ͼ��
{
	int nx, ny;
	if(num<20)
	{
		for (int i = 0; i < 4; i++)
		{
			nx = x + sharp[num][2 * i];
			ny = y + sharp[num][2 * i + 1];
			if (map[nx][ny] == 0)//�������û�ж������ػ�ո񣬲�Ȼ����
			{
				SetPos((ny + 1) * 2, nx + 1);
				cout << "  ";
			}
			else
			{
				SetColor(0);
				cout << "��";
			}

		}
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			nx = x + sharp[num][2 * i];
			ny = y + sharp[num][2 * i + 1];
			if (map[nx][ny] == 0)//�������û�ж������ػ�ո񣬲�Ȼ����
			{
				SetPos((ny + 1) * 2, nx + 1);
				cout << "  ";
			}
			else
			{
				SetColor(0);
				cout << "��";
			}

		}
	}
	
}
/// <summary>
/// �ж���x, y ��ָλ���Ƿ�ɻ����Ϊnum ��ͼ�Σ� �����ɻ��򷴻�true
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="num"></param>
/// <returns>������ܻ�true���ܻ�false</returns>
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

void Tetris::Run()					//������Ϸ
{
	int next_id;
	srand((int)time(0));			//��ʱ�������������
	
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
	int i = 0;  //��ͬ�ȼ���Ӧ��ͬcount
	int speed=1;//�ӵ��ƶ��ٶ�
	time_t start, finish;
	time_t bullStart, bullEnd;//�ӵ�time
	finish=start = time(nullptr);
	bullStart = bullEnd = time(nullptr);
	bool reset = true;
	while (1)
	{
		
		if (!(i < count))				//i �� count ���ڿ���ʱ��
		{
			if(id==19)//��Ϊ�ӵ������Ҷ��ģ�Ҫ���⴦��һ��
			{
				if(reset)//���¼�ʱ
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
				if (Judge(point[0] + 1, point[1], id))			//��ĳһλ�ò�������Ļ�
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
						cout << "��Ϸ������" << endl;
						SetPos(20, 11);
						cout << "��ķ���Ϊ " << score << endl;
						system("pause");
						exit(1);
					}
				}
				else					//��������
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

		if (_kbhit())				//��������ֵʱ 
		{
			int key, key2;
			key = _getch();			//������᷵������ֵ����һ���ǹ�����224���ڶ����Ƿֿ��ģ�����Ҫgetch����
			if (key == 224)
			{
				key2 = _getch();

				if (key2 == 72&& id != 19)			//�����Ϸ����ʱ
				{
					int temp = id;
					Turn(id);
					if (Judge(point[0], point[1], id))
						id = temp;
					ReDraw(point[0], point[1], temp);
					Draw(point[0], point[1], id);
				}
				if (key2 == 72 && id == 19)			//�ӵ��������Ϸ����
				{
					for (int i=point[0];i<26;++i)
					{
						if(map[i][point[1]]!=0||i==25)//��һ�еĵ�һ����ײ����(i,point[1])��û����ײ�����
						{
							SetPos((point[1] + sharp[id][1] + 1) * 2, i + sharp[id][0] );
							SetColor(0);
							cout << "��";
							map[i-1][point[1]] = 1;

							//���������
							
							//��flag��ֵΪ1��flagΪ1��ʾĳһ������0��ʾδ����
							bool flag = 1;
							for (int j = 0; j < 13; ++j)
							{
								if (map[i-1][j] == 0)//�пյĵط�˵��û����
								{
									flag = 0;
									break;
								}
							}
							//��flagΪ1ʱ������
							if (flag == 1)
							{
								/*
								�����·���ȫ���й��ܴ���
								*/
								for (int j = 0; j < 13; ++j)
								{
									int nx = i;
									int ny = j;
									SetPos((ny + 1) * 2, nx + 1);
									SetColor(0);
									cout << "  ";
									map[nx][ny] = 0;					//���������Ϊ�յĸ���
								}
								for (int k = i - 1; k > 0; --k)//��i�����Ͽ�ʼ���µ�
								{
									for (int l = 0; l < 13; ++l)
									{
										if (map[k][l] == 1)
										{
											//������λ��
											SetPos((l + 1) * 2, k + 1);
											cout << "  ";
											map[k][l] = 0;
											//���µ�һ���ػ�
											SetPos((l + 1) * 2, k + 2);
											cout << "��";
											map[k + 1][l] = 1;
										}
									}
								}
								//����÷�
								score += 10;
								Input_score();
							}
							break;
						}
					}
					if (Judge(point[0], point[1], id))//�п��ܻ�over�����һ��
					{
						system("cls");
						SetPos(20, 10);
						cout << "��Ϸ������" << endl;
						SetPos(20, 11);
						cout << "��ķ���Ϊ " << score << endl;
						system("pause");
						exit(1);
					}
					
				}
				if (key2 == 80&&id!=19)				//�����·����ʱ
				{
					if (!Judge(point[0] + 2, point[1], id))
					{
						ReDraw(point[0], point[1], id);
						point[0] += 2;
						Draw(point[0], point[1], id);
					}
				}
				else if(key2 == 80 && id == 19)//���µ��ӵ�
				{
					for (int i = point[0]; i < 25; ++i)
					{
						if (map[i][point[1]] != 0 || i == 24)//��һ�еĵ�һ����ײ����(i,point[1])��û����ײ�����
						{
							SetPos((point[1] + sharp[id][1] + 1) * 2, i + sharp[id][0]+1);
							SetColor(0);
							cout << "  ";
							map[i][point[1]] = 0;
							break;
						}
					}
				}
				else if (key2 == 75&&id!=19)				//���������ʱ
				{
					if (!Judge(point[0], point[1] - 1, id))
					{
						ReDraw(point[0], point[1], id);
						point[1]--;
						Draw(point[0], point[1], id);
					}
				}
				else if (key2 == 77&&id!=19)					//�����ҷ����ʱ
				{
					if (!Judge(point[0], point[1] + 1, id))
					{
						ReDraw(point[0], point[1], id);
						point[1]++;
						Draw(point[0], point[1], id);
					}
				}
			}
			else if (key == 32)					// ���¿ո���ͣ���Ѽ�ʱ����һ��
			{
				time_t tempTime = finish;
				time_t tempBulltime = bullEnd;
				Pause();
				finish = tempTime;
				bullEnd = tempBulltime;
			}
				
				
		}

		Sleep(1);		//�ȴ�1����
		i++;				//����������
		finish = time(nullptr);
		
		
	}
}

int main()
{
	Tetris game;
	game.Welocme();
	system("cls");				//�����ӭ����
	game.DrawMap();
	game.Run();
}





