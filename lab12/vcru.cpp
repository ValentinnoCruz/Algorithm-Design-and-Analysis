#include <iostream>
#include <limits.h>

using namespace std;

int len = 0;

int find_min(int **adj_matrix, bool *check)
{
    int result;
    int min_value = INT_MAX;
    for (int i = 0; i < len; i++)
    {
        if (check[i])
        {
            for (int j = 0; j < len; j++)
            {
                if (adj_matrix[i][j] < min_value && !check[j])
                {
                    result = i * 10 + j;
                    min_value = adj_matrix[i][j];
                }
            }
        }
    }
    return result;
}

int main()
{
    int edges = 0;
    cin >> len;
    cin >> edges;
    int **adj_matrix = new int *[len];
    for (int i = 0; i < len; i++)
    {
        adj_matrix[i] = new int[len];
        for (int j = 0; j < len; j++)
        {
            adj_matrix[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < edges; i++)
    {
        int x, y, weight;
        cin >> x;
        cin >> y;
        cin >> weight;
        adj_matrix[x][y] = weight;
        adj_matrix[y][x] = weight;
    }
    bool check[len];
    for (int i = 0; i < len; i++)
        check[i] = false;
    check[0] = true;
    int output[len - 1];
    int t = len - 1;
    while (t > 0)
    {
        int result = find_min(adj_matrix, check);
        int i = result / 10;
        int j = result % 10;
        check[j] = true;
        t--;
        output[t] = i;
    }
    for (int i = 1; i < len - 1; i++)
    {
        cout << output[i] << "\n";
    }
    cout << output[0] << "\n";
    return 0;
}
