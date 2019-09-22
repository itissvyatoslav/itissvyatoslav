#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


using namespace std;
ifstream fin;
ofstream fout;

class Auto
{
	char name[20], year[20], prod[20], mod[20], type[20];
public:

	Auto::Auto(){};
	void set(char c[100])
	{
		int i = 0, j = 0;
		for (int j = 0; j < 20; j++)
		{
			if (c[i] == '&')
			{
				for (j; j < 20; j++)
					name[j] = 0;
				break;
			}
			name[j] = c[i];
			i++;
		}
		i++;
		for (j = 0; j < 20; j++)
		{
			if (c[i] == '&')
			{
				for (j; j < 20; j++)
					year[j] = 0;
				break;
			}
			year[j] = c[i];
			i++;
		}
		i++;
		for (j = 0; j < 20; j++)
		{
			if (c[i] == '&')
			{
				for (j; j < 20; j++)
					prod[j] = 0;
				break;
			}
			prod[j] = c[i];
			i++;
		}
		i++;
		for (j = 0; j < 100; j++)
		{
			if (c[i] == '&')
			{
				for (j; j < 20; j++)
					mod[j] = 0;
				break;
			}
			mod[j] = c[i];
			i++;
		}
		i++;
		for (j = 0; j < 100; j++)
		{
			if (c[i] == '=')
			{
				for (j; j < 20; j++)
					type[j] = 0;
				break;
			}
			type[j] = c[i];
			i++;
		}
	}
	void out()
	{
		cout << " Name: " << name << '\n';
		cout << " Year: " << year << '\n';
		cout << " Production: " << prod << '\n';
		cout << " Model: " << mod << '\n';
		cout << " Body: " << type << endl;
	}
	~Auto(){};

	void sname(int i)
	{
		cout << i + 1 << ". " << name << '\n';
	}

	void nameed()
	{
		string s;
		cout << "Write the new name:\n ---------------\n ";
		


	}

};

void rewritetxt(int count, char c[10][100])
{
	int i, j;
	fout.open("autot.txt");
	fout << count << '\n';
	for (i = 0; i < count; i++)
	{
		for (j = 0; j < 100; j++)
		{
			fout << c[i][j];
			if (c[i][j] == '=') break;
		}
		fout << '\n';
	}

	fout.close();
};



void main()
{
	int i, j, count, leni, lenk=0, k = 0, z, k1 = 0, lenk2 = 0, ks, kf, ff;
	const int len = 100;
	const char ch = '\n';
	char c[10][100] = { 0 }, d[20] = { 0 };
	char n = 'l';


	fin.open("autot.txt");

	fin >> count;

	for (i = 0; i < count; i++)
	{
		for (j = 0; j < len; j++)
		{
			fin >> c[i][j];
			if (c[i][j] == '=') break;
		}
	}

	Auto *cars = new Auto[count];

	for (i = 0; i < count; i++)
	{
		cars[i].set(c[i]);
	}

	/*for (i = 0; i < count; i++)
	{
		cars[i].out();
		cout << '\n';
	}*/

	while (n != 'e')
	{
		if (n == 'l')
		{ 
			system("cls");
			cout << "Cars:\n";
			for (i = 0; i < count; i++)
				cars[i].sname(i);
			cout << "Choose the car by it's number or\n c - to register new\n d - to delete\n e - to exit\n ---------------\n ";
			cin >> n;
		}

		if (n >= '1' && n <= '9')
		{
			j = n - '0';
			system("cls");
			cars[j-1].out();
			cout << " n - to edit the name\n y - to edit the year\n p - to edit the production\n m - to edit the model\n b - to edit the body\n l - to list\n ---------------\n ";
			cin >> n;
			if (n == 'n')
			{
				system("cls");
				cout << "Spell the new name:\n ---------------\n Write '*' when the word finished\n ---------------\n";
				for (i = 0; i < 20; i++)
				{
					cin >> d[i];
					if (d[i] == '*')
					{
						d[i] = d[i + 1];
						leni = i;
						for (i; i < 20; i++)
							d[i] = 0;
						break;
					}
				}
				cout << "Edited to ";
					for (i = 0; i < leni; i++)
					cout << d[i];
					cout << '\n';

					while (c[j-1][k] != '&')
						k++;
					if (k - leni > 0)
					{
						for (i = k; i < 100; i++)
						{
							c[j - 1][i - (k - leni)] = c[j - 1][i];
							if (c[j - 1][i - (k - leni)] == '=')
							{
								for (i; i < 100; i++)
									c[j - 1][i] = 0;
								break;
							}
						}
						cout << "You have to exit to save\n e - to exit\n  ---------------\n ";
						cin >> n;
					}
					else
					{
						while (c[j - 1][lenk] != '=')
							lenk++;
						for (i = lenk; i > 0; i--)
						{
							c[j - 1][i - (k - leni)] = c[j - 1][i];
							if (c[j - 1][i - (k - leni)] == d[0])
							{
								for (i; i > 0; i--)
									c[j - 1][i] = 0;
								break;
							}
						}
						cout << "You have to exit to save\n e - to exit\n  ---------------\n ";
						cin >> n;
					}
					for (i = 0; i < leni; i++)
						c[j-1][i] = d[i];		
			}
			if (n == 'y')
			{
				system("cls");
				cout << "Spell the new year:\n ---------------\n";
				for (i = 0; i < 4; i++)
				{
					cin >> d[i];
				}
				cout << "Edited to ";
				for (i = 0; i < 4; i++)
					cout << d[i];
				cout << '\n';

				while (c[j - 1][k] != '&')
					k++;

					for (i = k+1; i < k+5; i++)
					c[j - 1][i] = d[i - (k+1)];
					cout << "You have to exit to save\n e - to exit\n  ---------------\n ";
					cin >> n;
			}
			if (n == 'p')
			{
				system("cls");
				cout << "Spell the new production's name:\n ---------------\n Write '*' when the word finished\n ---------------\n";
				for (i = 0; i < 20; i++)
				{
					cin >> d[i];
					if (d[i] == '*')
					{
						d[i] = d[i + 1];
						leni = i;
						for (i; i < 20; i++)
							d[i] = 0;
						break;
					}
				}
				cout << "Edited to ";
				for (i = 0; i < leni; i++)
					cout << d[i];
				cout << '\n';

				lenk = 0;
				while (c[j - 1][lenk] != '&')
					lenk++;
				k = lenk+6;
				while (c[j - 1][k] != '&')
					k++;
				k1 = k - lenk - 6;
				if (k1 - leni > 0)
				{
					for (i = k; i < 100; i++)
					{
						c[j - 1][i - (k1 - leni)] = c[j - 1][i];
						if (c[j - 1][i - (k1 - leni)] == '=')
						{
							for (i; i < 100; i++)
								c[j - 1][i] = 0;
							break;
						}
					}
				}
				else
				{
					while (c[j - 1][lenk2] != '=')
						lenk2++;
					for (i = lenk2; i > k - 1; i--)
					{
						c[j - 1][i - (k1 - leni)] = c[j - 1][i];
						
					}

				}
				for (i = lenk+6; i < lenk + 6 +leni; i++)
					c[j - 1][i] = d[i-lenk-6];
				cout << "You have to exit to save\n e - to exit\n  ---------------\n ";
				cin >> n;
			}

			if (n == 'm')
			{
				system("cls");
				cout << "Spell the new model:\n ---------------\n Write '*' when the word finished\n ---------------\n";
				for (i = 0; i < 20; i++)
				{
					cin >> d[i];
					if (d[i] == '*')
					{
						d[i] = d[i + 1];
						leni = i;
						for (i; i < 20; i++)
							d[i] = 0;
						break;
					}
				}
				cout << "Edited to ";
				for (i = 0; i < leni; i++)
					cout << d[i];
				cout << '\n';
				
				k = 0;
				
				while (c[j - 1][k] != '&')
					k++;
				k++;
				while (c[j - 1][k] != '&')
					k++;
				k++;
				while (c[j - 1][k] != '&')
					k++;
				ks = k;
				while (c[j - 1][k] != '&')
					k++;
				kf = k;
				while (c[j - 1][k] != '=')
					k++;
				ff = k;
				lenk = kf - ks - 1;
				if (leni - lenk > 0)
				{
					for (i = ff; i > kf - 1; i--)
					{
						c[j - 1][i + leni - lenk] = c[j - 1][i];
					}
				}
				else
				{
					for (i = kf; i < 100; i++)
					{
						c[j - 1][i - (lenk - leni)] = c[j - 1][i];
						if (c[j - 1][i - (lenk - leni)] == '=')
						{
							for (i; i < 100; i++)
								c[j - 1][i] = 0;
							break;
						}
					}
					
				}
					for (i = ks + 1; i < ks + leni + 1; i++)
					{
						c[j - 1][i] = d[i - ks - 1];
					}
					cout << "You have to exit to save\n e - to exit\n  ---------------\n ";
					cin >> n;
				
			}
			if (n == 'b')
			{
				system("cls");
				cout << "Spell the new body's name:\n ---------------\n Write '*' when the word finished\n ---------------\n";
				for (i = 0; i < 20; i++)
				{
					cin >> d[i];
					if (d[i] == '*')
					{
						d[i] = d[i + 1];
						leni = i;
						for (i; i < 20; i++)
							d[i] = 0;
						break;
					}
				}
				cout << "Edited to ";
				for (i = 0; i < leni; i++)
					cout << d[i];
				cout << '\n';
				
				while (c[j - 1][k] != '=')
					k++;
				ff = k;
				i = ff;
				while (c[j - 1][i] != '&')
					i--;
				kf = i;
				lenk = ff - kf - 1;
				c[j - 1][ff + leni - lenk] = c[j - 1][ff];
				
				for (i = kf + 1; i < kf + leni + 1; i++)
				{
					c[j - 1][i] = d[i - kf - 1];
				}
				cout << "You have to exit to save\n e - to exit\n  ---------------\n ";
				cin >> n;

			}
			
		}
		if (n == 'c')
		{
			system("cls");
			count++;
			cout << "Spell the new name:\n ---------------\n Write '*' when the word finished\n ---------------\n";
			for (i = 0; i < 20; i++)
			{
				cin >> d[i];
				if (d[i] == '*')
				{
					d[i] = d[i + 1];
					leni = i;
					for (i; i < 20; i++)
						d[i] = 0;
					break;
				}
			}
			cout << "Registered ";
			for (i = 0; i < leni; i++)
				cout << d[i];
			cout << '\n';
			for (i = 0; i < leni; i++)
				c[count - 1][i] = d[i];
			c[count - 1][leni] = '&';

			system("cls");
			cout << "Spell the year:\n ---------------\n";
			for (i = 0; i < 4; i++)
			{
				cin >> d[i];
			}
			cout << "Registered ";
			for (i = 0; i < 4; i++)
				cout << d[i];
			cout << '\n';
			for (i = leni + 1; i < leni + 5; i++)
				c[count - 1][i] = d[i - leni - 1];
			c[count - 1][leni + 5] = '&';

			system("cls");
			cout << "Spell the new production's name:\n ---------------\n Write '*' when the word finished\n ---------------\n";
			for (i = 0; i < 20; i++)
			{
				cin >> d[i];
				if (d[i] == '*')
				{
					d[i] = d[i + 1];
					lenk = i;
					for (i; i < 20; i++)
						d[i] = 0;
					break;
				}
			}
			cout << "Registered ";
			for (i = 0; i < lenk; i++)
				cout << d[i];
			cout << '\n';
			for (i = leni + 6; i < leni + 6 + lenk; i++)
				c[count - 1][i] = d[i - leni - 6];
			c[count - 1][leni + lenk + 6] = '&';
			ff = leni + lenk + 7;

			system("cls");
			cout << "Spell the new model:\n ---------------\n Write '*' when the word finished\n ---------------\n";
			for (i = 0; i < 20; i++)
			{
				cin >> d[i];
				if (d[i] == '*')
				{
					d[i] = d[i + 1];
					leni = i;
					for (i; i < 20; i++)
						d[i] = 0;
					break;
				}
			}
			cout << "Created ";
			for (i = 0; i < leni; i++)
				cout << d[i];
			cout << '\n';
			
			for (i = ff; i < ff + leni; i++)
				c[count - 1][i] = d[i - ff];
			c[count - 1][ff + leni] = '&';

			system("cls");
			cout << "Spell the new body's name:\n ---------------\n Write '*' when the word finished\n ---------------\n";
			for (i = 0; i < 20; i++)
			{
				cin >> d[i];
				if (d[i] == '*')
				{
					d[i] = d[i + 1];
					lenk = i;
					for (i; i < 20; i++)
						d[i] = 0;
					break;
				}
			}
			cout << "Created ";
			for (i = 0; i < lenk; i++)
				cout << d[i];
			cout << '\n';

			for (i = ff + leni + 1; i < ff + leni + lenk + 1; i++)
				c[count - 1][i] = d[i - ff - leni - 1];
			c[count - 1][ff + leni + lenk + 1] = '=';
			

			cout << "You have to exit to save\n e - to exit\n  ---------------\n ";
			cin >> n;
		}
		if (n == 'd')
		{
			cout << "\n\nWhich one do you want to delete?\n  ---------------\n  ";
			cin >> n;
			for (i = 0; i < 100; i++)
			{
				c[n - '0' - 1][i] = c[count - 1][i];
				c[count - 1][i] = 0;
			}

			count--;
			
			cout << "\n\nYou have to exit to save\n e - to exit\n  ---------------\n ";
			cin >> n;

		}
	}


	fin.close();

	rewritetxt(count, c);
}