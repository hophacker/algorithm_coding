/*
 * 2170.cpp
 *
 * 很繁的一个题。。。
 *
 * dfs + hash
 * 这个速度很慢， 不过答案应该都是对的， 先贴上来吧。。 最近没时间做了 。 以后再改。。
 *
 * 可以改进的有 搜索方式 和 hash函数
 *
 *  Created on: 2011-10-17
 */
#include <cstdio>
#include <cstring>
using namespace std;

const int maxp = 5000 + 10;
const int maxn = 25, z = 12;
const int hashNum = 19997;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};

int n, w, h, ans = 0, tmpHashNum, txl, txr, tyu,  tyd, isFH;
//plat[i][j] 表示坐标为 (j, i)
bool plat[maxn][maxn], tmpPlat[maxn][maxn], data[maxp][11][11], oriPlat[maxn][maxn];

struct SNode{
    int key;
    SNode *next;
    SNode() : key(-1), next(NULL) {}
};
SNode hashTable[11][11][hashNum];


void printPlat(bool map[][maxn], int xr, int yu){
    for(int i=maxn-1; i>=0; i--){
        printf("\n");
        for(int j=0; j<maxn; j++){
            if(map[i][j])
                printf("# ");
            else
                printf(". ");
        }
    }
    printf("\n");
}


inline bool isFine(int i, int x, int y, int& xl, int& xr, int& yu, int& yd){
    switch(i){
    case 0:    if(y > yu) yu = y; return (yu - yd + 1) <= h;
    case 1: if(y < yd) yd = y; return (yu - yd + 1) <= h;
    case 2: if(x < xl) xl = x; return (xr - xl + 1) <= w;
    case 3: if(x > xr) xr = x; return (xr - xl + 1) <= w;
    }
}

//使xl = yd = 0
inline void getNorm(bool map[][maxn], int& xl, int& xr, int& yu, int& yd){
    bool tmp[maxn][maxn];
    memcpy(tmp, map, sizeof(plat));
    memset(map, 0, sizeof(plat));

    for(int i=0; i<maxn; i++)
        for(int j=0; j<maxn; j++){
            map[i + z - yd][j + z - xl] = tmp[i][j];
        }

    xr = xr + z - xl; yu = yu + z - yd;
    xl = yd = z;
}

//逆时针转90度
inline void rotate(int& xl, int& xr, int& yu, int& yd){
    memcpy(tmpPlat, plat, sizeof(plat));
    memset(plat, 0, sizeof(plat));

    for(int i=z; i<=yu; i++)
        for(int j=z; j<=xr; j++)
            plat[j][2 * z - i] = tmpPlat[i][j];

    xl = 2 * z - yu; yu = xr; xr = z; yd = z;

}

//左右翻转
inline void overturn(int& xl, int& xr, int& yu, int& yd){

    memset(tmpPlat, 0, sizeof(tmpPlat));

    for(int i=z; i<=yu; i++)
        for(int j=z; j<=xr; j++)
            tmpPlat[i][2 * z - j] = plat[i][j];

    xl = 2 * z - xr;  xr = z;

}

//
int hash(bool map[][maxn], int xr, int yu){
    int hashValue = 0, weight = 1;
    for(int j=z; j<=xr; j++)
        if(map[z][j])
            hashValue++;

    for(int i=z+1; i<=yu; i++){
        weight = weight * 10;
        for(int j=z; j<=xr; j++)
            if(map[i][j])
                hashValue += weight;
    }
    return hashValue % hashNum;
}

//每个bit的比对， 相同返回true
bool checkFull(bool map[][maxn], int t, int xr, int yu){
    for(int i=z; i<=yu; i++)
        for(int j=z; j<=xr; j++)
            if(map[i][j] != data[t][i-z][j-z])
                return false;
    return true;
}

//重复则返回true
bool check_1(bool map[][maxn], int& xl, int& xr, int& yu, int& yd){
    //int tmpHash;
    SNode *cur;

    //直接比
    getNorm(map, xl, xr, yu, yd);
    tmpHashNum = hash(map, xr, yu);
    cur = &hashTable[xr-z][yu-z][tmpHashNum];
    if(cur->key != -1){
        while(cur != NULL){
            if(checkFull(map, cur->key, xr, yu))
                return true;
            cur = cur->next;
        }
    }
    return false;
}


//重复则返回true
bool check(int& xl, int& xr, int& yu, int& yd){
    int xll, xrr, yuu, ydd;
    //先直接比
    if(check_1(plat, xl, xr, yu, yd))
        return true;
    //翻转
    xll = xl, xrr = xr, yuu = yu, ydd = yd;
    overturn(xll, xrr, yuu, ydd);
    if(check_1(tmpPlat, xll, xrr, yuu, ydd))
        return true;


    //旋转、翻转后比
    //变换之前确保是Norm， check_1后是Norm
    //旋转直接在plat上进行， 翻转是额外操作， 在tmpPlat上进行
    for(int i=0; i<3; i++){
        //转 i * 90 度 ， 不翻转
        rotate(xl, xr, yu, yd);
        if(check_1(plat, xl, xr, yu, yd)){

            //dfs()中用
            txl = xl; txr = xr; tyu = yu; tyd = yd;
            return true;
        }
        txl = xl; txr = xr; tyu = yu; tyd = yd;

        //翻转
        xll = xl, xrr = xr, yuu = yu, ydd = yd;
        overturn(xll, xrr, yuu, ydd);
        if(check_1(tmpPlat, xll, xrr, yuu, ydd))
            return true;
    }
    return false;
}


//
void addToHash(int xl, int xr, int yu, int yd, int t){
    SNode *tNode = &hashTable[xr-z][yu-z][tmpHashNum];
    if(tNode->key == -1){
        tNode->key = t;
        return;
    }

    SNode* newNode = new SNode;
    newNode->key = t;
    newNode->next = hashTable[xr-z][yu-z][tmpHashNum].next;
    hashTable[xr-z][yu-z][tmpHashNum].next = newNode;
}

//
void dfs(int left, int x, int y, int xl, int xr, int yu, int yd){
    //增加新的方案
    if(left == 0){
        memcpy(oriPlat, plat, sizeof(plat));

        if(!check(xl, xr, yu, yd)){

            for(int i=z; i<=yu; i++)
                for(int j=z; j<=xr; j++)
                    data[ans][i-z][j-z] = plat[i][j];

            addToHash(xl, xr, yu, yd, ans);
            ans++;

        }

        memcpy(plat, oriPlat, sizeof(plat));

        return;
    }

    int curx, cury, xll, xrr, yuu, ydd;
    //从每个已占的点扩展。。 情况很多， 所以巨慢！！！！！！！！！！
    for(int p=yu; p>=yd; p--){
        for(int q=xl; q<=xr; q++){
            if(!plat[p][q]) continue;

            for(int i=0; i<4; i++){
                if(left >= n-3 && i == 1) continue;
                if(left >= n-2 && i == 2) continue;

                xll = xl, xrr = xr, yuu = yu, ydd = yd;
                curx = q + dx[i];
                cury = p + dy[i];
                if(plat[cury][curx])
                    continue;
                if(!isFine(i, curx, cury, xll, xrr, yuu, ydd)) continue;

                plat[cury][curx] = 1;

                dfs(left-1, curx, cury, xll, xrr, yuu, ydd);

                plat[cury][curx] = 0;

            }
        }
    }
}

int main(){
    while(scanf("%d%d%d", &n, &w, &h) != EOF){

    isFH = (h > 5 ? 5 : h);

    plat[z][z] = 1;
    dfs(n-1, z, z, z, z, z, z);

    printf("%d\n", ans);
    }

    return 0;
}