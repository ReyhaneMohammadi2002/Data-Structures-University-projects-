#include <iostream>
#include <stack>
using namespace std;
void marked(int i, int j, int** maze, stack<int> answer, int** mark, int d, int n) {
    if (maze[i][j + 1] == 0 && mark[i][j] == 1) {
        ++j;
        answer.pop();
        maze[i][j - 1] = 1;
        mark[i][j - 1] = 2;
    }
    else if (maze[i + 1][j] == 0 && mark[i][j] == 1) {
        ++i;
        answer.pop();
        maze[i - 1][j] = 1;
        mark[i - 1][j] = 2;
    }
    else if (maze[i][j - 1] == 0 && mark[i][j] == 1) {
        --j;
        answer.pop();
        maze[i][j + 1] = 1;
        mark[i][j + 1] = 2;
    }
    else if (maze[i - 1][j] == 0 && mark[i][j] == 1) {
        --i;
        answer.pop();
        maze[i + 1][j] = 1;
        mark[i + 1][j] = 2;
    }
    else {
        d = 5;
    }
}
void notMarked(int i, int j, int** maze, stack<int> answer, int** mark, int d, int n) {
    if (maze[i][j + 1] == 0 && mark[i][j + 1] != 1) {
        j++;
        mark[i][j] = 1;
        answer.push((n * (i - 1)) + j);
    }
    else if (maze[i + 1][j] == 0 && mark[i + 1][j] != 1) {
        i++;
        mark[i][j] = 1;
        answer.push((n * (i - 1)) + j);
    }
    else if (maze[i][j - 1] == 0 && mark[i][j - 1] != 1) {
        j--;
        mark[i][j] = 1;
        answer.push((n * (i - 1)) + j);
    }
    else if (maze[i - 1][j] == 0 && mark[i - 1][j] != 1) {
        i--;
        mark[i][j] = 1;
        answer.push((n * (i - 1)) + j);
    }
    else {
        marked(i, j, maze, answer, mark, d, n);
    }
}
void rat(int n, int** maze, stack<int> answer) {
    int i = 1, j = 1, d = 1;
    int** mark;
    mark = new int* [n + 2];
    for (int i = 0; i < n + 2; i++) {
        mark[i] = new int[n + 2];
    }
    mark[1][1] = 1;
    answer.push(1);
    while (d < 5)
    {
        while (d == 1) {
            if (maze[i][j + 1] == 0 && mark[i][j + 1] != 1) {
                ++j;
                mark[i][j] = 1;
                answer.push((n * (i - 1)) + j);
            }
            else if (maze[i + 1][j] == 0 && mark[i + 1][j] != 1) {
                ++i;
                mark[i][j] = 1;
                answer.push((n * (i - 1)) + j);
            }
            else if (maze[i][j - 1] == 0 && mark[i][j - 1] != 1) {
                --j;
                mark[i][j] = 1;
                answer.push((n * (i - 1)) + j);
            }
            else if (maze[i - 1][j] == 0 && mark[i - 1][j] != 1) {
                --i;
                mark[i][j] = 1;
                answer.push((n * (i - 1)) + j);
            }
            else {
                if (maze[i][j + 1] == 0 && mark[i][j] == 1) {
                    ++j;
                    answer.pop();
                    maze[i][j - 1] = 1;
                    mark[i][j - 1] = 2;
                }
                else if (maze[i + 1][j] == 0 && mark[i][j] == 1) {
                    ++i;
                    answer.pop();
                    maze[i - 1][j] = 1;
                    mark[i - 1][j] = 2;
                }
                else if (maze[i][j - 1] == 0 && mark[i][j] == 1) {
                    --j;
                    answer.pop();
                    maze[i][j + 1] = 1;
                    mark[i][j + 1] = 2;
                }
                else if (maze[i - 1][j] == 0 && mark[i][j] == 1) {
                    --i;
                    answer.pop();
                    maze[i + 1][j] = 1;
                    mark[i + 1][j] = 2;
                }
                else {
                    d = 5;
                }
            }
            if ((i == n) && (j == n)) {
                d = 10;
                int size = answer.size();
                int* p = new int[size];
                for (int i = 0; i < size; i++) {
                    p[i] = answer.top();
                    answer.pop();
                }
                for (int i = size - 1; i > -1; i--) {
                    cout << p[i] << " ";
                }
            }
        }
    }
    if (d == 5) {
        cout << "-1";
    }
}
int main()
{
    int n, ** maze;
    cin >> n;
    stack<int> answer;
    maze = new int* [n + 2];
    for (int i = 0; i < n + 2; i++) {
        maze[i] = new int[n + 2];
    }
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            if (i == 0) {
                maze[i][j] = 1;
            }
            else if (j == 0) {
                maze[i][j] = 1;
            }
            else if (i == n + 1) {
                maze[i][j] = 1;
            }
            else if (j == n + 1) {
                maze[i][j] = 1;
            }
            else
                cin >> maze[i][j];
        }
    }
    rat(n, maze, answer);
}