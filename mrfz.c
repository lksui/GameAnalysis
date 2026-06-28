#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){


  /* for(i=0;i<50;i++){
        a[i]=rand()%100+1; //1-100随机

           if(a[i]==1 || a[i]==2)//50抽内出货
            sum++;
        printf("%d \n",a[i]);
        printf("%d ",sum);
    }*/

//抽卡，判定抽数从而判定概率，出则重置概率与抽数
//不出则判定抽数并决定是否改变概率
//添加计数器
        int a, p;
        int cards[10000]={0};//抽数计数器cards
        srand(time(NULL));

        for(int i=0;i<10000;i++)   //用i表达第i抽，i∈[0.9999]，存入计数器,与数组长度相同
            for(int j=1;j<100;j++){  //j表达第i抽的第j次抽取，j∈[1.99]
             a=rand()%100+1;//1-100随机数表示概率，配合后面判断本次抽卡概率
            if(0<j<51)            //前50抽
                if(a<3){           //2%概率出货
                     cards[i]=j;
                     break;
                }
            if(50<j<99){           //第51-98抽
                if(a<(2+2*(j-50))){
                    cards[i]=j;
                    break;
            }}
            if(j==99){              //第99抽
                cards[i]=j;
                break;
            }
        }
        for(int i=0;i<10000;i++){          //打印每次出货抽数
            printf("第%d抽出货次数=%d\n",i+1,cards[i]);
        }

        int sum=0;
        double ave=0;
         for(int i=0;i<10000;i++){
            sum+= cards[i];
        }
        ave=sum/10000.0;
        printf("平均期望=%.2f",ave);



    return 0;

}
