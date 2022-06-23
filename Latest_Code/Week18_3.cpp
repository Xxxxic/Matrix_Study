#include<iostream>
#include<queue>
using namespace std;

struct node
{
	//  x位置 y优先级
	int x, y;
};
int largest_value(const queue<node>& q) {
	queue<node> temp = queue<node>(q);
	int largest = temp.front().y;
	while (!temp.empty())
	{
		if (temp.front().y > largest) {
			largest = temp.front().y;
		}
		temp.pop();
	}
	return largest;
}

int main()
{
	int t;
	cin >> t;
	while (t)
	{
		queue<node> q;
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			node temp;
			temp.x = i;
			cin >> temp.y;
			q.push(temp);
		}
		int time = 0;
		while (q.front().x != m || q.front().y != largest_value(q))
		{
			node temp = q.front();
			q.pop();
			if (temp.y < largest_value(q))
				q.push(temp);
			else
				time++;
		}
		cout << ++time << endl;
		t--;
	}
		

    return 0;
}