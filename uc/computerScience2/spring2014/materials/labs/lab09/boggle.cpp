#include <string>
#include <vector>
#include <iostream>
using namespace std;

#include <Dictionary.h>

const int SIZE = 4;
const int DIRS = 8;
const int R_D[DIRS] = {-1, -1, 0, 1, 1,  1,  0, -1};
const int C_D[DIRS] = { 0,  1, 1, 1, 0, -1, -1, -1};

vector<vector<char> > getBoard() {
  cout << "enter board: ";
  vector<vector<char> > board;
  string str;
  cin >> str;
  int counter = 0;
  for (int i = 0; i < SIZE; i++) {
    vector<char> v;
    board.push_back(v);
    for (int j = 0; j < SIZE; j++) {
      board[i].push_back(str[counter++]);
    }
  }
  return board;
}

vector<vector<bool> > initVisited() {
  vector<vector<bool> > board;
  for (int i = 0; i < SIZE; i++) {
    vector<bool> v;
    board.push_back(v);
    for (int j = 0; j < SIZE; j++) {
      board[i].push_back(false);
    }
  }
  return board;
}

bool isValid(int r, int c) {
  return r >= 0 && r < SIZE && c >= 0 && c < SIZE;
}

bool containsWord(vector<string>& words, string& word) {
  for (int i = 0; i < words.size(); i++) {
    if (words[i] == word) {
      return true;
    }
  }
  return false;
}

void solve(const vector<vector<char> >& board,
    vector<string>& words,
    int r,
    int c,
    vector<vector<bool> > &visited,
    string candidateWord,
    const Dictionary &dict) {
  for (int dir = 0; dir < DIRS; dir++) {
    int nextR = r + R_D[dir];
    int nextC = c + C_D[dir];
    if (isValid(nextR, nextC) && !visited[nextR][nextC]) {
      string nextWord = candidateWord;
      nextWord += board[nextR][nextC];
      if (dict.isWord(nextWord)) {
        if (!containsWord(words, nextWord)) {
          words.push_back(nextWord);
        }
      }
      visited[nextR][nextC] = true;
      solve(board, words, nextR, nextC, visited, nextWord, dict);
      // backtrack
      visited[nextR][nextC] = false;
    }
  }
}

void solve(const vector<vector<char> >& board, vector<string>& words,
    const Dictionary &dict) {
  // from every starting point
  for (int r = 0; r < board.size(); r++) {
    for (int c = 0; c < board[r].size(); c++) {
      string word;
      word += board[r][c];
      vector<vector<bool> > visited = initVisited();
      visited[r][c] = true;
      solve(board, words, r, c, visited, word, dict);
    }
  }
}

void sort(vector<string> &words) {
  for (unsigned int target = 0; target < words.size() - 1; target++) {
    unsigned int posMin = target;
    for (unsigned int next = target + 1; next < words.size(); next++) {
      if (words[next] < words[posMin]) {
        posMin = next;
      }
    }
    if (posMin != target) {
      string tmp = words[target];
      words[target] = words[posMin];
      words[posMin] = tmp;
    }
  }
}

int main() {
  Dictionary dict;
  vector<vector<char> > board = getBoard();

  cout << "starting solve." << endl;
  vector<string> words;
  solve(board, words, dict);

  cout << "Found: " << words.size() << " words." << endl;
  sort(words);
  for (unsigned int i = 0; i < words.size(); i++) {
    cout << words[i] << endl;
  }

}
