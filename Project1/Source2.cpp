/*
#include <iostream>
#include <map>
#include <set>


struct rectangle {
	int x1, y1, x2, y2;
};
 

int dist(std::map<int, rectangle>::iterator b, std::map<int, rectangle>::iterator c, int quad)
{
	if (quad == 0)
		return (c->second.x1 - b->second.x1);
	else if (quad == 1)
		return (c->second.x1 - b->second.x1 + c->second.y1 - b->second.y1);
	else if (quad == 2)
		return (c->second.y1 - b->second.y1);
	else if (quad == 3)
		return (c->second.y1 - b->second.y1 + b->second.x2 - c->second.x2);
	else if (quad == 4)
		return (b->second.x2 - c->second.x2);
	else if (quad == 5)
		return(b->second.x2 - c->second.x2 + b->second.y2 - c->second.y2);
	else if (quad == 6)
		return (b->second.y2 - c->second.y2);
	else if (quad == 7)
		return (c->second.y2 - b->second.y2 + c->second.x1 - b->second.x1);
}


bool zerocheak(std::map<int, rectangle>::iterator b, std::map<int, rectangle>::iterator c)
{
	if (b->second.x1 > c->second.x1 && b->second.y1 > c->second.y1
		&& c->second.x2 > b->second.x2 && c->second.y2 > b->second.y2)
		return true;
	else
		return false;
}

bool cheak(std::map<int, rectangle>::iterator b, std::map<int, rectangle>::iterator c)
{
	if ((b->second.x2 - b->second.x1) > (c->second.x2 - c->second.x1) 
		&& (b->second.y2 - b->second.y1) > (c->second.y2 - c->second.x1))
		return false;
	else
		return true;
}

int quadrent (std::map<int, rectangle>::iterator a, std::map<int, rectangle>::iterator b)
{
	if ((a->second.y1 >= b->second.y1 && a->second.y2 <= b->second.y2) && a->second.x1 < b->second.x1)
		return 0;
	else if ((a->second.y1 >= b->second.y1 && a->second.y2 <= b->second.y2) && a->second.x2 > b->second.x2)
		return 4;
	else if ((a->second.x1 >= b->second.x1 && a->second.x2 <= b->second.x2) && a->second.y1 < b->second.y1)
		return 2;
	else if ((a->second.x1 >= b->second.x1 && a->second.x2 <= b->second.x2) && a->second.y2 > b->second.y2)
		return 6;
	else if (a->second.x1 < b->second.x1 && a->second.y1 < b->second.y1)
		return 1;
	else if (a->second.x1 > b->second.x1 && a->second.y1 < b->second.y1)
		return 3;
	else if (a->second.x1 > b->second.x1 && a->second.y1 > b->second.y1)
		return 5;
	else if (a->second.x1 < b->second.x1 && a->second.y1 > b->second.y1)
		return 7;
	
}

int calculatouor(std::map<int, rectangle>& a)
{
	std::map<int, rectangle>::iterator c, b;
	std::set<int> s,t;
	int z;
	for (int i = 0; i < a.size(); i++)
	{
		c = a.begin();
		std::advance(c, i);
		for (int j = 0; j < a.size(); j++)
		{
			b = a.begin();
			std::advance(b, j);
			if (zerocheak(c, b))
			{
				return 0;
			}
			if (cheak(c, b))
			{
				z=dist(c,b, quadrent(c, b));
				s.insert(z);
			}
			
		}
		t.insert(*(s.begin()));
		s.clear();
	}
	if (t.empty())
		return -1;
	else
		return *(t.begin());
}

int main()
{
	std::map<int, rectangle> buffer;
	int n,T,l,b,r,u;
	std::cin >> T;
	for (int i =0;i<T;i++)
	{
		std::cin >> n;
		for (int j = 0; j < n; j++)
		{
			std::cin >> l >> b >> r >> u;
			buffer[j] = { l,b,r,u };
		}
	std::cout << calculatouor(buffer);
	buffer.clear();
	}
	
}
*/

