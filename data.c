// #include <stdio.h>
// // #include <stdilb.h>

// int array[25] = {0};

// void startline(){
//     printf("여러가지 정렬 프로그램 구현\n\n");
//     printf(" 1) 선택 정렬\n");
//     printf(" 2) 삽입 정렬\n");
//     printf(" 3) 버블 정렬\n");
//     printf(" 4) 퀵 정렬\n");
//     printf(" 5) 합병 정렬\n");
//     printf(" 6) 힙 정렬\n");
//     printf(" 7) 종료\n\n");
//     printf(" 번호 입력(번호 입력후 엔터를 눌러주세요!) > ");
// }

void bubble(){
//총 n(25번 실행)
//     int temp;
//     for(i=1; i<n; i++)
//     {
//         //만약 j의 앞에있는 값이 클 경우에 값을 바꿈
//         for(j=1;j<n;j++)
//         {
//             //클 경우(작은 경우로 바꾸면 내림차순으로 바뀜)
//             if (array[j] > array[j+1])
//             {
//                 temp = array[j];
//                 array[j] = array[j+1];
//                 array[j+1] = temp;
//             }
//         }
//     }
}

// void numCh(a){
//     switch (a)
//     {
//     case 1:
//         printf("선택\n\n");
//         break;
//     case 2:
//         printf("삽입\n\n");
//         break;
//     case 3:
//         printf("버블\n\n");
//         break;
//     case 4:
//         printf("퀵\n\n");
//         break;
//     case 5:
//         printf("합병\n\n");
//         break;
//     case 6:
//         printf("힙\n\n");
//         break;
//     case 7:
//         printf("종료\n\n");
//         break;
//     default:
//         printf("ㄴㄴ 다시\n\n");
//         break;
//     }
// }

// int main(){
//     int a;
//     // while(1){
//     //     startline();
//     //     scanf("%d",&a);
//     //     numCh(a);
//     // }
    
//     return 0;
// }

//버블 정렬 codeup
// #include <stdio.h>
// int a[10001];
// int n, i, j, temp;
// int main() {
//     scanf("%d", &n);
//     for (i=1; i<=n; i++)
//         scanf("%d", &a[i]);

//     //총 n(25번 실행)
//     for(i=1; i<n; i++)
//     {
//         //만약 j의 앞에있는 값이 클 경우에 값을 바꿈
//         for(j=1;j<n;j++)
//         {
//             //클 경우(작은 경우로 바꾸면 내림차순으로 바뀜)
//             if (a[j] > a[j+1])
//             {
//                 temp = a[j];
//                 a[j] = a[j+1];
//                 a[j+1] = temp;
//             }
//         }
//     }

//     for (i = 1; i <= n; i++)
//         printf("%d\n", a[i]);
//     return 0;
// }