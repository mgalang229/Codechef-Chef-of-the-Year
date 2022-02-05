#include <bits/stdc++.h>
 
using namespace std;

string GetSmaller(string s1, string s2) {
	int n = (int) s1.size();
	int m = (int) s2.size();
	for (int i = 0; i < min(n, m); i++) {
		if (s1[i] < s2[i]) {
			return s1;
		} else if (s2[i] < s1[i]) {
			return s2;
		}
	}
	return (n < m ? s1 : s2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
 	int n, m;
 	cin >> n >> m;
 	map<string, pair<int, string>> mp;
 	// create an associative array (key:value pair form)
 	// key = chef's name and value will be in pair form (first = frequency, second = country name)
 	for (int i = 0; i < n; i++) {
 		string name, country;
 		cin >> name >> country;
 		mp[name].first = 0;
 		mp[name].second = country;
 	}
 	int mx = INT_MIN;
 	for (int i = 0; i < m; i++) {
 		string name;
 		cin >> name;
 		mp[name].first += 1; // count the occurrences of each chef
 		mx = max(mx, mp[name].first);
 	}
 	string best_chef = "";
 	map<string, int> countries;
 	int new_mx = INT_MIN;
 	for (auto& x : mp) {
 		if (x.second.first == mx) {
 			// find the chef with the maximum votes (in case of multiple chefs, choose the lexicographically smallest string)
 			best_chef = (best_chef == "" ? x.first : GetSmaller(best_chef, x.first));
 		}
 		string country = x.second.second;
		countries[country] += x.second.first; // count the occurrences of each country
		new_mx = max(new_mx, countries[country]);
 	}
 	string best_country = "";
	for (auto& x : countries) {
		if (x.second == new_mx) {
			// find the country with the maximum votes (in case of multiple countries, choose the lexicographically smaller string)
			best_country = (best_country == "" ? x.first : GetSmaller(best_country, x.first));
		}
	}
	cout << best_country << '\n' << best_chef << '\n';
	return 0;
}
