#include <bits/stdc++.h>
using namespace std;

long long n,x,y,z;
const long long MAXN = 150007;

struct druzyna{
    long long x,y,z;
};


bool sort_x(druzyna a, druzyna b){
    if (a.x > b.x) return true;
    if (a.x < b.x) return false;
    
    if (a.y > b.y) return true;
    if (a.y < b.y) return false;
    
    return (a.z > b.z);
    
}

bool sort_y(druzyna a, druzyna b){
    if (a.y > b.y) return true;
    if (a.y < b.y) return false;
    
    if (a.x > b.x) return true;
    if (a.x < b.x) return false;
    
    return (a.z > b.z);
    
}


bool sort_z(druzyna a, druzyna b){
    if (a.z > b.z) return true;
    if (a.z < b.z) return false;
    
    if (a.y > b.y) return true;
    if (a.y < b.y) return false;
    
    return (a.x > b.x);
    
}


druzyna x_[MAXN];
druzyna y_[MAXN];
druzyna z_[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    
    druzyna akt_druzyna;
    
    for (long long i=0; i<n; i++){
        cin >> x >> y >> z;
        akt_druzyna.x = x;
        akt_druzyna.y = y;
        akt_druzyna.z = z;
        
        x_[i] = akt_druzyna;
        y_[i] = akt_druzyna;
        z_[i] = akt_druzyna;
        
    }
    
    
    sort(x_,x_+n,sort_x);
    sort(y_,y_+n,sort_y);
    sort(z_,z_+n,sort_z);
    
    long long wsk_x=0;
    long long wsk_y=0;
    long long wsk_z=0;
    bool git = true;
    while (git){
        git = false;
        if (!(wsk_x>=n) && !(wsk_y>=n) && !(wsk_z>=n)){
            if (x_[wsk_x].y>=y_[wsk_y].y || x_[wsk_x].z>=z_[wsk_z].z){
                wsk_x++;
                git=true;
            }
            if (y_[wsk_y].x>=x_[wsk_x].x || y_[wsk_y].z>=z_[wsk_z].z) {
                wsk_y++;
                git=true;
            }
            if (z_[wsk_z].x>=x_[wsk_x].x || z_[wsk_z].y>=y_[wsk_y].y) {
                wsk_z++;
                git=true;
            }
        }
    }
    if (wsk_x<0 || wsk_y<0 || wsk_z<0 || x_[wsk_x].y>=y_[wsk_y].y || x_[wsk_x].z>=z_[wsk_z].z || y_[wsk_y].x>=x_[wsk_x].x || y_[wsk_y].z>=z_[wsk_z].z || z_[wsk_z].x>=x_[wsk_x].x || z_[wsk_z].y>=y_[wsk_y].y){
        cout << "-1\n";
    }
    else{
        cout << (long long)x_[wsk_x].x+y_[wsk_y].y+z_[wsk_z].z << endl;
    }
    
    
    
   return 0;
}