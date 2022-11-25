#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//힘들었던 수행, 그만큼 보람있고 집중도 빡세게 한 수행

int array[25] = {0};
int closeCh = 0, easterEgg = 0;    //0 : 종료 ㄴㄴ, 1 : 종료, 2 : 아님

//테스트용
// int array[25] = {5, 4, 60, 3, 50, 22, 0, 32, 21, 56, 1, 4, 59, 69, 55, 75, 15, 67, 74, 96, 3, 52, 45, 67, 89};
//필수로 들어가야 될것들 ==================================================================
void setRandomArray(){
    srand((unsigned)time(NULL));    //이거 시간에 따라 달라집니다
    for(int i= 0;i<25;i++){
        int random = rand()%100;
        array[i] = random;
    }
    
}

void startline(){
    printf("여러가지 정렬 프로그램 구현\n\n");
    printf(" 1) 선택 정렬\n");
    printf(" 2) 삽입 정렬\n");
    printf(" 3) 버블 정렬\n");
    printf(" 4) 퀵 정렬\n");
    printf(" 5) 합병 정렬\n");
    printf(" 6) 힙 정렬\n");
    printf(" 7) 종료\n\n");
    printf(" 번호 입력 > ");
}

//======================================================================================


// 정렬해주는 함수들
//성공 버블 정렬 
void bubble(){
// 총 n(25번 실행)
    int temp;
    for(int i=0; i<25; i++)
    {
        //만약 j의 앞에있는 값이 클 경우에 값을 바꿈
        for(int j=0;j<25;j++)
        {
            //클 경우(작은 경우로 바꾸면 내림차순으로 바뀜)
            if (array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}


//성공 선택 정렬
void select(){
    int temp, least;    //바꿀값과 제일 작은 값의 index를 저장할 값
    for(int i=0;i<24;i++){
        least = i;      //일단 초기값을 i(제일 처음 값)으로 줘서 0~25까지 한번씩 다 훑음
        for(int j=i+1;j<25;j++){
            if(array[j] < array[least]) least = j;  //만약에 제일 처음값보다 j값이 작다하면 index값을 바꿈
        }
        temp = array[least];    //처음 돌렸을때 for문 안에서 돌렸더니 이상하게 나옴
        array[least] = array[i];//당연히 작은거 찾을때 마다 바꾸니까 애가 정신이 나가버림
        array[i] = temp;        //그냥 1차 for문에 넣으면 됨
    }
}

//성공 삽입 정렬
void insert(){
    int temp, j;
    //얘가 신기한게 굳이 제일 작은걸 차례대로 찾으러 다니고
    //그걸또 맨앞으로 옮겨주는 작업을 해야되기때문에 매우 골치가 아픔(뭔 말인지 모르겠으면 학습지 참고)
    for(int i=0;i<25;i++){
        //일단 초기값이고 뭐고 차례대로 매우 작은걸 앞으로 넘겨줘야되기때문에 i번째를 넘겨줌
        temp = array[i];
        for(j=i-1;j>=0 && array[j] > temp;j--){
            //와 진짜 무슨 원리인지 모르겠다. ( printf 중간중간에 넣어서 결과 보고 해석 했습니다 )
            array[j+1] = array[j];
            // 50 60 70 80 40이 있다 하면 아마 temp는 40을 가리키게 될거임(40저장)
            // 저장한뒤 하나씩 뒤로 넘기기 시작
            // 50 60 70 80 80
            // 50 60 70 70 80
            // 50 60 60 70 80
            // 50 50 60 70 80
            //이렇게 하면 이 for문을 나와서 
        }
        //여기(0번째)에 temp 값을 넣어 40 50 60 70 80 이 되는거임
        array[j+1] = temp;
    }
}

//성공 퀵 정렬 ( 솔직히 대충 이해가 되긴했는데 잘 이해를 못해서 이건 나중에 쌤한테 물어봐야겠다. )
int quick_sort(Left, Right){
    //진심 이해 안된다
    int pivot, temp, i, j;
    if(Left < Right){
        //일단 왼쪽, 오른쪽 기준을 잡는다.
        i = Left;
        j = Right+1;
        pivot = array[Left];    //블로그에선 무슨 이상하게 pivot을 잡던데 학습지에선 그냥 맨 왼쪽을 pivot으로 잡았다.
        do{
            while(array[++i] < pivot);  //여기가 중요한데 이게 원리가 밑에서 말한거처럼 피벗보다 작은애를 못만난다 하면 바꾸는건데
            while(array[--j] > pivot);  //이렇게 while문과 전치연산자를 사용하여 피벗보다 작은 값이 있는지, 큰값이 있는지 찾아준다.
                                        //i가 ++되고 작은 값을 찾는 이유 : i가 첫번째 값인데 첫번째 값보다 큰게 있으면 안되니까 그런는거임
                                        //j는 반대겠죠..???
            if(i < j){                  //이게 증말 신기한게 do while문을 써서 한번 무조건 실행되게 한다.( 처음에 Right에 왜 +1을 하는 이유, 바로 --를 때리면 마지막 값을 무시하게 되버림 )
                temp = array[i];        //그래서 만약 바로 옆은 아니고 1칸 떨어져있는데 옆에 값이 크거나 작으면 바로 + - 때려서 바꿈
                array[i] = array[j];
                array[j] = temp;
            }
        }while(i < j);
        temp = array[Left]; //대충 반복한 다음 맨 왼쪽값이랑 오른쪽값이랑 바꾸고
        array[Left] = array[j];
        array[j] = temp;
        quick_sort(Left, j-1);  //재귀 써서 피벗 바꾸고 하는 그런 정렬
        quick_sort(j+1, Right);
    }
}

void quick(){
    //얘도 정말 골때리는 애가 아닐 수 없다
    //학습지를 봐도 봐도 모르겠어서 블로그 찾아 가면서 이해를 했는데
    //피벗이라는 애를 먼저 선택하고 L(왼쪽 끝 index)은 가만히 있고, R(오른쪽 끝 dinex)이 L쪽으로 오다가
    //피벗 보다 작은애를 못만나면 L이랑 피벗이랑 바꾸는 그런 애다.

    //학습지 코드보니까 재귀 써야되네
    //ㅜㅜ
    int L = 0, R = 25;
    quick_sort(L, R);
    
}

//성공 합병 정렬
//기본적으로 합병 정렬은 두개로 쪼갠 다음에 비교해서 바꾼다음
//다시 붙이는 거기 때문에 함수를 두개 써야된다.

//추가 공간 필요(쪼갠걸 여기다가 합치고 다시 array에 넣어줘야되기 때문)
int sort[25];

//다시 붙이는거
int Merge_sort(left, right, mid){
    int i, j, k, l;
    i = left; j = mid + 1; k = left;    //각각 초기값을 넣어줌

    //쪼개진거 합치기
    while(i<=mid && j<=right){
        if(array[i] <= array[j]) sort[k++] = array[i++];
        else sort[k++] = array[j++];
    }

    //남은 거 넣어주기
    if(i > mid) for(l = j; l <= right; l++) sort[k++] = array[l];
    else for(l = i; l <= mid; l++) sort[k++] = array[l];

    //힘들게 붙인거 array에 넣어주기
    for(l = left; l<= right; l++){
        array[l] = sort[l];
    }

}

//쪼개는거 + 붙이는거( 재귀호출로 쪼개고 붙이고 반복 )
int Merge(left, right){
    int mid;
    if(left < right){   //재귀 호출 됐을 때 계속 쪼개지면 안되니까 조건문
        mid = (left + right) / 2;   //중간을 찾아야 두개로 쪼갤수 있겠죠?
        Merge(left, mid);       //두개로 다시 쪼개기
        Merge(mid+1, right);    //두개로 다시 쪼개기
        Merge_sort(left, right, mid); //합치기
    }
}


//성곤 힙 정렬
//민성이의 힙한 트리 정렬
// 그냥 최대힙 만들고 거기서 하나하나 빼면(최댓값이 빼지겠죠????)
// 자연스럽게 오름차순 이 되는데 그걸 내림차순으로 하면 됨(25 -> 0 이 되게)
int h[26] = {0};    //얘도 따로 저장해둘 공간이 필요함( 힙트리 생성(따로 저장)후 하나하나씩 값을 삭제하면서 return하며 값을 빼 array에 저장 )

int insert_heap_tree(int item, int heap_index){
    int i = heap_index;
    while ((i != 1) && (item > h[i/2])){
        h[i] = h[i/2];  //부모 값을 자식 값으로 바꿈
        i/=2;   //계속 / 2를 하다보면 1이 나와서 1에 item을 넣는다( 왜 i/2를 하는지 모르면 시험지에 힙한 트리 그리면 된다. 학습지에 나온다(부모 선택할려고) )
    }
    h[i] = item;        //item을 넣는 모습
    //자동으로 꽉찬 최대 힙트리가 되겠죠????
}

int delete_heap_tree(int heap_index){
    int parent, child, item, temp;  //부모, 자식, 현재 가장 큰 값, 가장 마지막 주소
    item = h[1]; // 가장 큰 값
    temp = heap_index;  //가장 마지막 값
    parent = 1; child = 2;
    while (child <= heap_index){
        if((child < heap_index) && (h[child] < h[child+1]))
            child++;//자식중에 더 큰값을 선택( 큰값을 올려야 오름차순, 내림차순이 되니 더 큰 값을 선택 )
        if(temp >= h[child]) break;
        h[parent] = h[child];
        parent = child; //아래 단계로 이동
        child *= 2;     //아래 단계로 이동
    }
    h[parent] = temp;
    return item;
}

void heap(){
    int i, heap_index = 0;
    //최대힙 만들기 ( 힙트리 학습지 보면 이해 바로됨 )
    for(i = 0; i < 25; i++){
        heap_index++;
        insert_heap_tree(array[i], heap_index);
    }
    //하나씩 값을 빼서 실제 배열에 넣어주는 함수
    for(i =24; i>=0; i--){
        array[i] = delete_heap_tree(heap_index);
        heap_index--;
    }
}

void sort_before(){
    printf("정렬하기 전 배열 값 : ");
        for(int i=0;i<25;i++){
            printf("%d ",array[i]);
    }printf("\n\n");
}

void numCh(a){
    switch (a)
    {
    case 1:
        printf("  << '선택 정렬'을 선택하셨습니다. >>\n\n");
        sort_before();
        select();
        break;
    case 2:
        printf("  << '삽입 정렬'을 선택하셨습니다. >>\n\n");
        sort_before();
        insert();
        break;
    case 3:
        printf("  << '버블 정렬'을 선택하셨습니다. >>\n\n");
        sort_before();
        bubble();
        break;
    case 4:
        printf("  << '퀵 정렬'을 선택하셨습니다. >>\n\n");
        sort_before();
        quick();
        break;
    case 5:
        printf("  << '합병 정렬'을 선택하셨습니다. >>\n\n");
        sort_before();
        Merge(0, 24);
        break;
    case 6:
        printf("  << '힙 정렬'을 선택하셨습니다. >>\n\n");
        sort_before();
        heap();
        break;
    case 7:
        printf("종료\n\n");
        closeCh = 1;
        break;
    default:
        printf("ㄴㄴ 다시\n\n");
        easterEgg++;
        if(easterEgg == 10)
            printf("우리 애가 아파해요\n\n");
        else if(easterEgg == 20)
            printf("어어 \n\n");
        else if(easterEgg == 25)
            printf("안된다 \n\n");
        else if(easterEgg == 30){
            printf("펑 \n\n");
            closeCh = 1;
        }
        break;
    }
}

int main(){
    int a;
    startline();
    while(1){
        setRandomArray();
        scanf("%d",&a);
        printf("\n\n");
        numCh(a);
        if(closeCh == 1) break;
        printf("정렬한 뒤 배열 값 : ");
        for(int i=0;i<25;i++){
            printf("%d ",array[i]);
        }
        printf("\n\n 더 하실 건가요?? > ");
    }
    /*//테스트 노가다 한 흔적
    bubble();
    for(int i=0;i<25;i++){
        printf("%d ",array[i]);
    }
    select();
    for(int i=0;i<25;i++){
        printf("%d ",array[i]);
    }
    insert();
    for(int i=0;i<25;i++){
        printf("%d ",array[i]);
    }
    quick();
    for(int i=0;i<25;i++){
        printf("%d ",array[i]);
    }
    printf("\n\n===Merge===\n\n");
    Merge(0, 24);
    for(int i=0;i<25;i++){
        printf("%d ",array[i]);
    }
    heap();
    for(int i=0;i<25;i++){
        printf("%d ",array[i]);
    }
    */
    // while(1){
    //     numCh(a);
    // }
    //수행 평가 하면서 이렇게 고생해본적은 처음이였네요
    //그만큼 엄청 집중도 되서 좋았던거같아요
    //새벽 2시까지 달린게 문제지만
    //거의 11시쯤 부터 2시까지 유튜브도 한번 안보고 노래 들으면서 수행 한게 정말 보람차네요
    //전 자러가겠습니다
    //마지막 window 테스트
    return 0;
}
