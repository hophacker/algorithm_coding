#include<iostream>

#include<fstream>

#include<cmath>

#include<algorithm>

using namespace std;



struct node

{

	double l,r;

};

bool cmp(const node& a, const node& b)

{

	if (a.l == b.l) return a.r < b.r;

	else return a.l < b.l;

}

int main()

{

	freopen("in", "r", stdin);

	int n, r;

	int test = 0;

	node p[1002];

	cin >> n >> r;

	while (n || r)

	{

		printf("Case %d: ", ++test);

		double x, y;

		bool error = false;

		for (int i = 1;i <= n; i++)

		{

			cin >> x >> y;

			if (y > r || y < 0) error = true;

			else

			{

				p[i].l = x - sqrt(r*r - y*y*1.0);

				p[i].r = x + sqrt(r*r - y*y*1.0);

			}

		}

		sort(p+1, p+n+1, cmp);

		if (error) cout << -1 << endl;

		else

		{

			double tempr;

			int total = 0, t = 1, t1;

			while (t <= n)

			{

				tempr = p[t].r;

				total++;

				t1 = t + 1;

				while (t1 <= n && p[t1].l <= tempr) 

				{	

					if (p[t1].r < tempr) tempr = p[t1].r;

					t1++;

				}

				t = t1;

			}

			cout << total << endl;

		}

		cin >> n >> r;

	}

}
