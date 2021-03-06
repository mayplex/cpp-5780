/**
 * Exercises in choosing the right container for the task.
 * 
 * Author: Eran Kaufman
 * Since : 2020-06
 */

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <stack>
#include <iostream>
#include <iterator>
#include <fstream>
#include <map>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

// Check if the given string has balanced [] {} parentheses 
bool isBalanced(string word){
	stack<char> st;
	for(auto c : word) {
		if (c == '{' || c == '[' )
			st.push(c);

		if (c == '}' && !st.empty() && st.top() == '{')
			st.pop();

		if (c == ']' && !st.empty() && st.top() == '[')
			st.pop();
	}

	if(!st.empty())
		return false;

	return true;
}


// Find, in the given vector, two values whose sum is "target_sum"
bool FindInSet( vector<int>& data, int target_sum){
	unordered_set<int> comp;

	for (int value: data){
		if(comp.find(target_sum-value) != comp.end())
			return true;

		comp.insert(value);
	}
	return false;
}


int  countZeros(vector<int> & v){
	int count=0;
	unordered_multiset<int> set;
	int sum=0;

	for (int num:v){
		sum += num;
		count += set.count(sum);
		set.insert(sum);
	}

	return count;
}

// Print the frequency of each word in the input file
void printwords(){
	std::ifstream input("input.txt");
	std::vector<std::string> words;

	std::copy(std::istream_iterator<std::string>(input),
		std::istream_iterator<std::string>(),
		std::back_inserter(words)
		);

	std::map<string, size_t> freqs;
	for (auto const& word : words)
	{
		if (freqs.count(word) == 0)
		{
			freqs[word] = 1;
		}
		else
		{
			++freqs[word];
		}
	}
	std::multimap<size_t, std::string,std::greater<size_t>> reverse_freqs;
	for (auto const& pair : freqs)
	{
		reverse_freqs.insert({pair.second, pair.first});
	}
	int i = 0;
	for (auto const& freq_and_word : reverse_freqs)
	{
		if (i++ >= 10) break;
		cout << freq_and_word.second << endl;
	}


}




int main() {
	std::cout << "isBalanced algo: "<< isBalanced("{[]}") << "\n";
	std::cout << "isBalanced algo: "<< isBalanced("{[}") << "\n";
	std::cout << "isBalanced algo: "<< isBalanced("}") << "\n";
	std::cout << "isBalanced algo: "<< isBalanced("}[]{") << "\n";

//	vector<int> vec{1,3,-2,-1,4,0,0,-4};
	vector<int> vec={2,-2};
	std::cout << "FindInSet algo: "<< boolalpha << FindInSet(vec,4) << "\n";

	std::cout << "countZeros algo: "<< countZeros(vec) << "\n";
	
	printwords();
}
