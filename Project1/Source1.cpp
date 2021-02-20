#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include<algorithm>


struct date
{
	int d, m, y;

	date()
	{
		d = 0;
		m = 0;
		y = 0;
	}
};

std::istream& operator >>(std::istream& stream, date& d)
{
	stream >> d.d >> d.m >> d.y;
	return stream;
}

std::ostream& operator <<(std::ostream& stream, date& d)
{
	stream << d.d <<' '<< d.m <<' '<< d.y;
	return stream;
}

bool operator> (date& c1, date& c2)
{
	if (c1.y > c2.y)
		return 1;
	else if (c1.y == c2.y && c1.m > c2.m)
		return 1;
	else if (c1.y == c2.y && c1.m == c2.m && c1.d > c2.d)
		return 1;
	else
		return 0;
}

class movie
{
public:
	std::string M_name;
	std::string M_Genre;
	float review;
	date M_rdate;
	std::string A_Name;
	
	movie()
	{
		review = -1;
	}
	void push()
	{
		std::cout << "Name(First letter capital) : ";
		std::cin >> M_name;
		std::cout << "Genre : ";
		std::cin >> M_Genre;
		std::cout << "Review : ";
		std::cin >> review;
		std::cout << "Release date(dd mm yyyy format) : ";
		std::cin >> M_rdate;
		std::cout << "Registry Author Name : ";
		std::cin >> A_Name;
	}
	
	int print()
	{
		if (review == -1 && M_rdate.d == 0 && M_rdate.m == 0 && M_rdate.y == 0)
			return 0;
		else
		{
			std::cout << M_name << '\n' << M_Genre << '\n' << review << '\n' << M_rdate << '\n' << A_Name <<'\n';
			return 1;
		}
	}
};

bool mycomp1(movie a, movie b) 
{
	return a.M_name < b.M_name;
}

bool mycomp2(movie a, movie b) 
{
	return a.review > b.review;
}

bool mycomp3(movie a, movie b) 
{
	return a.M_rdate > b.M_rdate;
}

void print(std::vector<movie> name, std::string str = "NO_FILTER")
{
	int j = 0;
	for (unsigned int i = 0; i < name.size(); i++)
		if (str == "NO_FILTER")
		{
			j+=name[i].print();
		}
		else
		{
			if (str == name[i].M_Genre)
			{
				j+=name[i].print();
			}
		}
	if (j == 0)
	{
		std::cout << "No Movie to Display\n";
	}
		
}
void vecsort(std::vector<movie>& a, bool(*func)(movie, movie)) 
{
	std::sort(a.begin(), a.end(), func);
}


int main()
{
	char z;
	std::vector<movie> vec;
	std::string s, s1;
	movie m;
	int opt;
	bool a = true;
	std::ofstream fout;
	std::ifstream fin;
	while (true)
	{
		std::cout << "MENU\n PLS SELECT OPTIONS ACCORDING TO WHAT OPERATION YOU WANT TO PERFORM\n";
		std::cout << "1)Add new movies to the List\n2)Remove movies from the list\n3)Display Movies from the List\n4)Exit the program\n";
		std::cin >> opt;
		if (opt == 4)
			exit(0);
		else if (opt == 1)
		{
			fout.open("data.txt", std::ios::app);
			if (fout.fail())
			{
				std::cerr << "Error opening file, Closing program";
				exit(1);
			}
			m.push();
			fout<<'\n'<< m.M_name << '\n' << m.M_Genre << '\n' << m.review << '\n' << m.M_rdate << '\n' << m.A_Name;
			fout.close();
			std::cout << "The movie has been added\n";

		}
		else if (opt == 2)
		{
			opt = 1;
			std::cout << "Pls enter the name of the movie u want to remove : ";
			std::cin >> s;
			fout.open("temp.txt", std::ios::out);
			fin.open("data.txt", std::ios::in);
			if (fout.fail())
			{
				std::cerr << "Error opening file, Closing program";
				exit(1);
			}
			if (fin.fail())
			{
				std::cerr << "Error opening file, Closing program";
				exit(1);
			}
			while (!fin.eof())
			{
				fin >> s1;
				if (s1 != s)
				{
					fout << s1;
					if (opt %7 == 4 || opt %7 == 5)
						fout << ' ';
					else
						fout << '\n';
				}

				else
				{
					fin >> s1;
					fin >> s1;
					fin >> s1;
					fin >> s1;
					fin >> s1;
					fin >> s1;
				}
				opt++;
			}
			fin.close();
			fout.close();
			remove("data.txt");
			opt = rename("temp.txt","data.txt");
			if (opt == 0)
				std::cout << "The Movie has been removed\n";
			else
				std::cerr << "Error :  Operation could not compleate\n";
			
		}
		else if (opt == 3)
		{
			std::cout << "PLS SELECT THE OPTIONS DEPENDING ON THE ORDER U WANT THE MOVIES TO BE DISPLAYED ACCORDING TO\n";
			std::cout << "1)According to alphabetical order\n2)According to release date(newer release at top)\n";
			std::cout << "3)According to review(highest review first)\n";
			std::cin >> opt;
			std::cout << "Do you want to to display movies spesific to a genre(Y/N) : ";
			std::cin >> z;
			if (z == 'Y' || z == 'y')
			{
				std::cout << "PLS SELECT THE GENRE ON THE MOVIES TO BE DISPLAYED\n";
				std::cin >> s;
			}
			else
				s = "NO_FILTER";
			fin.open("data.txt",std::ios::in);
			if (fin.fail())
			{
				std::cerr << "Error opening file, Closing program";
				exit(1);
			}
			while (!fin.eof())
			{
				fin >> m.M_name >> m.M_Genre >> m.review >> m.M_rdate >> m.A_Name;
				vec.emplace_back(m);
			}
			fin.close();
			if (opt == 1)
			{
				vecsort(vec,&mycomp1);
				print(vec, s);
			}
			else if (opt == 2)
			{
				vecsort(vec, &mycomp3);
				print(vec, s);
			}
			else if (opt == 3)
			{
				vecsort(vec, &mycomp2);
				print(vec, s);
			}
			else
			{
				std::cout << "Invalid Input (exiting program)";
				exit(1);
			}
			vec.clear();
			
		}
		else
		{
			std::cout << "Invalid Input (exiting program)";
			exit(1);
		}

		

	}
}