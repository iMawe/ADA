#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

vector<string> segmentar(const string& s, const char& c)
{
	string buff{ "" };
	vector<string> v;

	for (auto n : s)
	{
		if (n != c) buff += n; else
			if (n == c && buff != "") {
				v.push_back(buff);
				buff = "";
			}
	}
	if (buff != "")
			v.push_back(buff);
	return v;
}

vector<string>line1;

void interseccion1(vector<pair<string,vector<string>>> V, vector<pair<string,vector<string>>> V1, int ini){

	vector<string>line;

	int pos=0;
	int cont = 0;

	for (ini; ini<V.size(); ini++)
	{
		for (int j = pos; j < V1.size(); j++)
		{
			if (V[ini].first.size() == V1[j].first.size())
			{
				if (V[ini].second == V1[j].second)
				{
					cont = cont + 1;
					line.push_back(V[ini].first);
					pos = j;
					j = V1.size();
					break;
				}
			}
			
		}
	}
	line.pop_back();
	if (line.size() > line1.size())
	{
		line1 = line;
	}
	while(ini < V.size())
		{
		interseccion1(V, V1, ini + 1);
	}
	cout<< line1.size() << endl;
}


int main(){
	int m, n;

	vector<pair<string,vector<string>>> V;
	vector<pair<string, vector<string>>> V1;

	string line;

	ifstream in("Doc1.txt");
	ifstream in2("Doc2.txt");

	while(getline(in, line)){
	  	std::getline(in, line);
		vector<string> pal = segmentar(line, ' ');
		V.push_back(std::make_pair(line,pal));
	}

	string line1;

	while(getline(in2,line1)){
	  	std::getline(in, line1);
		vector<string> pal = segmentar(line1, ' ');
		V1.push_back(std::make_pair(line1,pal));
	}

	interseccion1(V, V1, 0);

	return 0;
}