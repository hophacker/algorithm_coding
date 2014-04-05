#include <stdio.h>
#include <algorithm>
#include <functional>
using namespace std;

int all,find1,res,times,used[65],stick[65];
int maxlen,lenth,sum;

void dfs(int no, int curlen, int level);
void fit(int no)
{
    int i;
    if(find1==1 || no>res){//find1==1鍓灊4
    find1 = 1;
    return ;
    }for(i=0; i<all; i++){
        if(!used[i]) break;
    }
    used[i] = 1;
    times++;
    dfs(no, stick[i], i);
    times--;
    used[i] = 0;
}//鍓灊锛氫互褰撳墠鏈€澶у€煎紑濮嬫悳绱竴閬嶏紝鏃犵粨鏋滐紝杩斿洖

void dfs(int no, int curlen, int level)
{
    if(curlen == lenth){
        fit(no+1);
        return ;
    }
    if(find1==1)//鍓灊4
        return ;
    int i,j;
    for(i=level+1; i<all; i++){//鍓灊7锛宭evel+1鎹负0鍒欏鍑?1ms
        if(!used[i] && curlen+stick[i]<=lenth){//鍓灊6
            //灏辨槸蹇樹簡杩欎釜鏈€鍩烘湰鐨?curlen+stick[i]<=lenth鍓灊瀵艰嚧TLE浜嗕竴鏅氫笂
            if(all-times+1<res-no)//鍓灊8锛屽幓鎺夊鍑?5ms
                return ;
            used[i] = 1;
            times++;
            dfs(no, curlen+stick[i], i);
            times--;
            used[i] = 0;
            j=i;
            if(find1==1)//鍓灊4锛屽幓鎺夊鍑?5ms
                return ;
            while(i<all && stick[j]==stick[i])//鍓灊5,鍘绘帀鍒橳LE
                i++;
            if(i==all)return ;
            if(i!=j)i--;
        }
    }
}

void work()
{
    if(sum%res!=0)//鍓灊1
        return ;
    lenth = sum / res;
    if(maxlen > lenth)//鍓灊2
        return ;
    times = 0;
    fit(1);
}

int main()
{
    int i;
    while(1){
        sum = 0;
        maxlen = 0;
        scanf("%d", &all);
        if(all==0)
            break;
        for(i=0; i<all; i++){
            scanf("%d", &stick[i]);
            if(maxlen<stick[i])
                maxlen = stick[i];
            sum += stick[i];
        }
        sort(stick, stick+all, greater<int>());//鍓灊3
        memset(used, 0, sizeof(used));
        times = 0;
        for(res=all; res>0; res--){
            find1 = 0;
            work();
            if(find1==1)
                break;
        }
        printf("%d\n",sum / res);
    }
    return 0;
}
