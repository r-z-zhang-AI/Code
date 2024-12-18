// #include<stdio.h>
// #include<math.h>
// int my_pow(int n, int m){
//     int ans = 1;
//     for(int i = 0; i < m; i++){
//         ans *= n;
//     }
//     return ans;
// }

// int num = 0;
// int main()
// {
//     int i, j;
//     int matrix[10][10] = {};
//     int n;
//     scanf("%d", &n);
//     if(n % 2 == 1){
//         matrix[(n - 1)/2][(n - 1)/2] = my_pow(n, 2);
//         for(i = 0; i < (n - 1)/2; i++){
//             for(j = i; j < i + n - 1 - 2 * i; j++){
//                 matrix[i][j] = ++num;
//             }
//             for(j = i; j < i + n - 1 - 2 * i; j++){
//                 matrix[j][n - 1 - i] = ++num;
//             }
//             for(j = i + n - 1 - 2 * i; j > i; j--){
//                 matrix[n - 1 - 2 * i][j] = ++num;
//             }
//             for(j = n - 1 + i - 2 * i; j > i; j--){
//                 matrix[j][i] = ++num;
//             }
//         }
//     }
//     else{
//         for(i = 0; i < n / 2; i++){
//             for(j = i; j < i + n - 1 - 2 * i; j++){
//                 matrix[i][j] = ++num;
//             }
//             for(j = i; j < i + n - 1 - 2 * i; j++){
//                 matrix[j][n - 1 - i] = ++num;
//             }
//             for(j = n - 1 + i - 2 * i; j > i; j--){
//                 matrix[n - 1 - 2 * i][j] = ++num;
//             }
//             for(j = n - 1 - i - 2 * i; j > i; j--){
//                 matrix[j][i] = ++num;
//             }
//         }
//     }
//     for(i = 0; i < n; i++){
//         for(j = 0; j< n; j++){
//             printf("%3d", matrix[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

#include <stdio.h>
#include <string.h>
#include <math.h>
int di[]={0,1,0,-1};
int dj[]={1,0,-1,0};
int a[100][100];
int main(){

    int i=1,j=1,cnt=2,t=0;
    int n;
    a[i][j]=1;
    scanf("%d",&n);
    while(cnt<=n*n){
        if(i+di[t]>n||i+di[t]<1||j+dj[t]>n||j+dj[t]<1)
            t=(t+1)%4;
        if(a[i+di[t]][j+dj[t]]!=0)
            t=(t+1)%4;
        i+=di[t];
        j+=dj[t];
        a[i][j]=cnt++;
    }
    for (int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/*
讲解：

### **代码结构与功能**

1. **方向数组 `di` 和 `dj`**
   ```c
   int di[]={0,1,0,-1};
   int dj[]={1,0,-1,0};
   ```
   - `di` 和 `dj` 是两个数组，用于控制行和列的移动方向。
   - 移动方向的顺序是：
     - **右**：`di[0]=0, dj[0]=1`
     - **下**：`di[1]=1, dj[1]=0`
     - **左**：`di[2]=0, dj[2]=-1`
     - **上**：`di[3]=-1, dj[3]=0`

   通过 `t` 控制方向，例如 `t=0` 时向右移动，`t=1` 时向下移动，以此类推。

---

2. **矩阵的初始化**
   ```c
   int a[100][100];
   int i=1, j=1, cnt=2, t=0;
   int n;
   a[i][j]=1;
   scanf("%d",&n);
   ```
   - `a[100][100]` 是存储螺旋矩阵的二维数组，初始值为 `0`。
   - `i=1, j=1` 表示从矩阵的左上角（`(1,1)`）开始填充。
   - `cnt=2` 是要填充的下一个数字，初始值为 2（第一个位置已经填充了 `1`）。
   - `t=0` 是方向的初始值，表示从 **右** 开始填充。
   - 使用 `scanf` 读取矩阵的大小 `n`。

---

3. **生成螺旋矩阵的核心逻辑**
   ```c
   while(cnt <= n * n) {
       if(i + di[t] > n || i + di[t] < 1 || j + dj[t] > n || j + dj[t] < 1)
           t = (t + 1) % 4;
       if(a[i + di[t]][j + dj[t]] != 0)
           t = (t + 1) % 4;
       i += di[t];
       j += dj[t];
       a[i][j] = cnt++;
   }
   ```
   - **条件判断（边界检测）**：
     - 如果下一步的 `(i+di[t], j+dj[t])` 超出矩阵范围（`>n` 或 `<1`），改变方向（`t = (t + 1) % 4`）。
   - **检查是否已填充**：
     - 如果下一个位置已经填充了数字（`a[i+di[t]][j+dj[t]] != 0`），也需要改变方向。
   - **移动与填充**：
     - 按当前方向移动到下一个位置：`i += di[t]; j += dj[t]`。
     - 在新位置填充当前的数字 `cnt`，并将 `cnt` 加 1。

---

*/

//二刷

