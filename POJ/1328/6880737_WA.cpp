#include<iostream>

#include<fstream>

#include<cmath>

#include<algorithm>

using namespace std;



struct node

{

	double x,y;

};

bool cmp(const node& a, const node& b)

{

	if (a.x == b.x) return a.y < b.y;

	else return a.x < b.x;

}

double dis(node& a, node& b)

{

	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));

}

int main()

{

	freopen("in", "r", stdin);

	int n, r;

	int test = 0;

	node p[1001];

	cin >> n >> r;

	while (n || r)

	{

		

		printf("Case %d: ", ++test);

		for (int i = 1;i <= n; i++)

			cin >> p[i].x >> p[i].y;

		sort(p+1, p+n+1, cmp); 

		bool error = false;

		for (int i = 1; i <= n; i++)

			if (p[i].y > r || p[i].y == 0)

			{

				error = true;

				break;

			}

		if (error) cout << -1 << endl;

		else

		{

			int t = 2;

			node p1;

			p1.x = p[1].x + sqrt(r*r-p[1].y*p[1].y);

			p1.y = 0;

			int num = 1;

			while (t <= n)

			{

				while (dis(p1, p[t]) <= r && t <= n) t++;

				if (t <= n)

					p1.x = p[t].x + sqrt(r*r-p[t].y*p[t].y);

				else break;

				num++;				

			}

			cout << num << endl;

		}

		cin >> n >> r;

	}

}
