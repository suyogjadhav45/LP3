#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char c;
    int freq;
    Node *left, *right;
    Node(char a, int b)
    {
        c = a;
        freq = b;
        left = right = NULL;
    }
};

class Compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

void printhuff(Node *root, string ans)
{
    if (!root)
        return;
    if (root->c != '$')
    {
        cout << root->c << " " << ans << endl;
    }
    printhuff(root->left, ans + '0');
    printhuff(root->right, ans + '1');
}
void huffman(vector<char> chars, vector<int> val, int n)
{
    Node *temp, *left, *right;
    priority_queue<Node *, vector<Node *>, Compare> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(new Node(chars[i], val[i]));
    }

    while (pq.size() != 1)
    {
        left = pq.top();
        pq.pop();
        right = pq.top();
        pq.pop();
        temp = new Node('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;
        pq.push(temp);
    }

    printhuff(pq.top(), "");
}

int main()
{
    vector<char>data= {'A', 'B', 'C', 'D'};
    vector<int>freq = {23, 12, 34, 10};
    huffman(data, freq, 4);
    return 0;
}