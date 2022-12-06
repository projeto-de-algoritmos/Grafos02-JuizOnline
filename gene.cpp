#include <iostream>
#include <string>
#include <map>

using namespace std;

int g[305][305] = {0};
int v[305] = {0};

void dfs(int i, int m, int f)
{
    if (v[i])
        return;

    v[i] = f;

    for (int j = 0; j < m; j++)
        if (g[i][j])
            dfs(j, m, f);
}

map<string, int> mapa;
int c = -1;

int find(string p)
{
    int i;
    map<string, int>::iterator it = mapa.find(p);

    if (it != mapa.end())
        i = it->second;
    else
        mapa.insert(make_pair(p, ++c)), i = c;

    return i;
}

int main(void)
{
    int m, n;

    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        string p1, r, p2;
        cin >> p1 >> r >> p2;
        int i1 = find(p1), i2 = find(p2);
        g[i1][i2] = g[i2][i1] = 1;
    }

    int f = 0;

    for (int j = 0; j < m; j++)
        if (!v[j])
            dfs(j, m, ++f);

    cout << f << endl;

    return 0;
}