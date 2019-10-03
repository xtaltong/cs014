#include <iostream>
#include <exception>
#include <string>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

int totalchar = 0;
// A Tree node
struct Node
{
	char ch;
	int freq;
	Node *left, *right;
};

// Function to allocate a new tree node
Node* getNode(char ch, int freq, Node* left, Node* right)
{
	Node* node = new Node();

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

// Comparison object to be used to order the heap
struct comp
{
	bool operator()(Node* l, Node* r)
	{
		// highest priority item has lowest frequency
		return l->freq > r->freq;
	}
};

// traverse the Huffman Tree and store Huffman Codes
// in a map.
void encode(Node* root, string str,
			unordered_map<char, string> &huffmanCode)
{
	if (root == nullptr)
		return;

	// found a leaf node
	if (!root->left && !root->right) {
		huffmanCode[root->ch] = str;
	}

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}

// traverse the Huffman Tree and decode the encoded string
void decode(Node* root, int &index, string str, ofstream& fout)
{
	if (root == nullptr) {
		return;
	}

	// found a leaf node
	if (!root->left && !root->right)
	{
		fout << root->ch;
		return;
	}

	index++;

	if (str[index] =='0')
		decode(root->left, index, str, fout);
	else
		decode(root->right, index,str, fout);
}

// Builds Huffman Tree and decode given input text
void buildHuffmanTree(string inputFile, const string& fileName)
{
    ifstream iFile(inputFile);
    while(!iFile.is_open()){
        cout << "Unable to open file." << endl;
        cout << "Re-enter input filename." << endl;
        cin >> inputFile;
    }
	// count frequency of appearance of each character
	// and store it in a map
	unordered_map<char, int> freq;
	char ch;
	while(iFile.get(ch)){
	    totalchar++;
	    freq[ch]++;
	}
	iFile.close();

	// Create a priority queue to store live nodes of
	// Huffman tree;
	priority_queue<Node*, vector<Node*>, comp> pq;

	// Create a leaf node for each character and add it
	// to the priority queue.
	for (auto pair: freq) {
		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}

	// do till there is more than one node in the queue
	while (pq.size() != 1)
	{
		// Remove the two nodes of highest priority
		// (lowest frequency) from the queue
		Node *left = pq.top(); pq.pop();
		Node *right = pq.top();	pq.pop();

		// Create a new internal node with these two nodes
		// as children and with frequency equal to the sum
		// of the two nodes' frequencies. Add the new node
		// to the priority queue.
		int sum = left->freq + right->freq;
		pq.push(getNode('\0', sum, left, right));
	}

	// root stores pointer to root of Huffman Tree
	Node* root = pq.top();

	// traverse the Huffman Tree and store Huffman Codes
	// in a map. Also prints them
	unordered_map<char, string> huffmanCode;
	encode(root, "", huffmanCode);

	cout << "Huffman Codes are :\n" << '\n';
	for (auto pair: huffmanCode) {
		cout << pair.first << " " << pair.second << '\n';
	}
    
    //encoded stream to a file
    ofstream oFile(fileName);
    iFile.open(inputFile);
    while(iFile.get(ch)){
        oFile << huffmanCode[ch];
    }
    iFile.close();
    
    
	// traverse the Huffman Tree again and this time
	// decode the encoded string

	cout << "Done." << endl;
}

streamsize get_file_size(const string& fileName){
    ifstream file(fileName, ios::binary | ios::ate);
    return file.tellg();
}

// Huffman coding algorithm
int main()
{
//	cout << "Huffman coding is a data compression algorithm." << endl;
	string text = "input.txt";
	string output = "compresstext.txt";
	
	cout << "Compressing file: " << text << endl;
	cout << "Compressed filename: " << output << endl;

	buildHuffmanTree(text, output);
	ifstream file(text);
	stringstream stream;
	stream << file.rdbuf();
	file.close();
	
	const auto file_content = stream.str();
	const auto file_size = totalchar*8;
	const auto after_file_size = get_file_size(output);
	
	cout << "Size before compression: " << file_size << " bits." << endl;
	cout << "Size after compression: " << after_file_size << " bits." << endl;
	cout << "Size change: " << file_size - after_file_size << " bits." << endl;
	cout << "Ratio of compression: " << static_cast<double> (after_file_size) /file_size*100 << "% " << " compressed." << endl;

	return 0;
}