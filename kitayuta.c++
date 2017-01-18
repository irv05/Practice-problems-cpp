/*
http://codeforces.com/problemset/problem/505/A
Kitayuta's Gift

Mr. Kitayuta has kindly given you a string s consisting of lowercase English letters. You are asked to insert exactly one 
lowercase English letter into s to make it a palindrome. A palindrome is a string that reads the same forward and backward. 
For example, "noon", "testset" and "a" are all palindromes, while "test" and "kitayuta" are not.

You can choose any lowercase English letter, and insert it to any position of s, possibly to the beginning or the end of s. 
You have to insert a letter even if the given string is already a palindrome.

If it is possible to insert one lowercase English letter into s so that the resulting string will be a palindrome, print the 
string after the insertion. Otherwise, print "NA" (without quotes, case-sensitive). In case there is more than one palindrome 
that can be obtained, you are allowed to print any of them.

Input
The only line of the input contains a string s (1 ≤ |s| ≤ 10). Each character in s is a lowercase English letter.

Output
If it is possible to turn s into a palindrome by inserting one lowercase English letter, print the resulting string in a single 
line. Otherwise, print "NA" (without quotes, case-sensitive). In case there is more than one solution, any of them will be accepted.

*/

#include <iostream>
#include <string>
bool palcheck(std::string& word){
	int b = 0;
	int e = word.size() - 1;

	while(b < e ) {
		if(word[b] != word[e]) {
			return false;}
		++b;
		--e; }
	return true;
}
int main() {
	using namespace std;
	string word;
	cin >> word;
	if(word.size() == 1) {
		word.insert(word.begin(),word[0]); 
		cout << word;
		return 0; }
	if(palcheck(word) && (word.size()%2 == 0)) {
		word.insert(word.size()/2, "a"); }
	//else if(palcheck(word)) {
		//cout << "NA";
		//return 0; }
	else {
		int pos = 0;
		string word2(word);
		char r = word2[0];
		word2.erase(word2.begin() + pos);
		while(!palcheck(word2)){
			word2.insert(word2.begin() + pos, r);
			++pos;
			if(pos >= word2.size()) {
				cout << "NA";
				return 0;}
			r = word2[pos];
			word2.erase(word2.begin() + pos);
		}
		if(pos > word.size()/2) ++pos;
		word.insert(word.end() - pos, r); 
	}
	cout << word;
	return 0;}

