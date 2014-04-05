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

	//freopen("in", "r", stdin);

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

			if (y > r) error = true;

			else

			{

				p[i].l = x - sqrt(r*r - y*y);

				p[i].r = x + sqrt(r*r - y*y);

			}

		}

		sort(p+1, p+n+1, cmp);

		if (error) cout << -1 << endl;

		else

		{

			double templ = p[1].l, tempr = p[1].r;

			int total = 0, t = 1, t1;

			while (t <= n)

			{

				total++;

				t1 = t + 1;

				while (t1 <= n && p[t1].l <= tempr) t1++;

				t = t1;

				if (t <= n)tempr = p[t].r;

			}

			cout << total << endl;

		}

		cin >> n >> r;

	}

}
