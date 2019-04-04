#include<iostream>
#include<vector>
#include<string>
using namespace std;
void func(vector<vector<int>>& vec, int num)
{
	vector<int> res;
	static int base = 0;
	int sum = 0;
	for (int o = 0; o < vec.size(); o++)
	{
		sum += vec[o].size();
	}
	while (sum > 0)
	{
		for (int k = 0; k < vec.size(); k++)
		{
			for (int j = 0; j < num; j++)
			{
				if (base + j < vec[k].size())
				{
					int tmp = vec[k][base + j];
					res.push_back(tmp);
					sum--;
				}
			}
		}
		base = base + num;
	}

	for (int i = 0; i < res.size(); i++)
	{
		if (i == res.size() - 1)
		{
			cout << res[i];
		}
		else
		{
			cout << res[i] << ",";
		}
	}
}
void main()
{
	string num;
	string input;
	vector<vector<int>> vecs;
	getline(cin, num);
	vector<string> inputs;
	while (getline(cin, input))
	{
		if (input == "") break;
		inputs.push_back(input);

	}

	for (int i = 0; i < inputs.size(); i++)
	{
		vector<int> vec;
		string split = ",";
		int pos1 = 0;
		int pos2 = inputs[i].find(split);
		while (string::npos != pos2)
		{
			vec.push_back(stoi(inputs[i].substr(pos1, pos2 - pos1)));
			pos1 = pos2 + split.size();
			pos2 = inputs[i].find(split, pos1);
		}
		if (pos2 != inputs[i].size())
			vec.push_back(stoi(inputs[i].substr(pos1)));
		vecs.push_back(vec);
	}
	func(vecs, stoi(num));

}
