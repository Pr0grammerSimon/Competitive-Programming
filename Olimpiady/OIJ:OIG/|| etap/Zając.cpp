#include <bits/stdc++.h>

using namespace std;

int dx[8] = {1,1,-1,-1,2,2,-2,-2};
int dy[8] = {2,-2,2,-2,1,-1,1,-1};

int main()
{
    int height,width,y,x;
    cin >> height >> width;
    char pola[height][width];
    int wyniki[height][width];
    string ciag;
    queue<pair<int,int>> kolejka;
    pair <int,int> nora,punkt;
    for (int i=0; i<height; i++){
        for (int j=0; j<width; j++){
            wyniki[i][j] = -1;
        }
    }
    for (int i=0; i<height; i++){
        cin >> ciag;
        for (int j=0; j<width; j++){
            pola[i][j] = ciag[j];
            if (ciag[j] == 'n'){
                nora = {i,j};
            }
            else if (ciag[j] == 'z'){
                kolejka.push({i,j});\
                wyniki[i][j] = 0;
            }
        }
    }
    
    while (!kolejka.empty()){
        punkt = kolejka.front();
        kolejka.pop();
        y = punkt.first;
        x = punkt.second;
        if (pola[y][x] == 'n') break;
        for (int i=0; i<8; i++){
            if (y+dy[i] < height && y+dy[i] > -1 && x+dx[i] < width && x+dx[i] > -1){
                if (pola[y+dy[i]][x+dx[i]] != 'x' && (wyniki[y][x]+1<wyniki[y+dy[i]][x+dx[i]] || wyniki[y+dy[i]][x+dx[i]] == -1)){
                    kolejka.push({y+dy[i],x+dx[i]});
                    wyniki[y+dy[i]][x+dx[i]] = wyniki[y][x]+1;
                }
            }
        }
    }

    if (wyniki[nora.first][nora.second] != -1){
        cout << wyniki[nora.first][nora.second];
    }
    else{
        cout << "NIE";
    }

    return 0;
}