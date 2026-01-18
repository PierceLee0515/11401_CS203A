# Array (陣列) 學習筆記
***
## 陣列基礎 (What & Why)

* ### 陣列是什麼 (What)?
    - 是一種儲存資料的方式，將資料存放在 **連續的記憶體 (Contiguous Memory)** 中。
    - A collection of elements stored in contiguous memory locations, where each element can be accessed directly using an index.
    

* ### 什麼時候會用到 (When)?
    - 當你需要一個空間去存放一連串「相同類型」且「邏輯相關」的資料時。

* ### 為什麼要用陣列 (Why)?
    - **管理方便**：避免宣告大量變數導致代碼混亂（例如不需要宣告 `a1, a2, a3...`）。
    - **分配空間**：只需宣告一次並 **分配大小**，系統就會劃出一塊連續空間供你使用。

## 陣列的使用方式與類型 (How)

* ### 要怎麼用 (How)?
    - 必須先宣告陣列，並決定它是 **靜態 (Static)** 還是 **動態 (Dynamic)** 分配。

    #### C 語言範例：
    ```c
    #include <stdio.h>
    #include <stdlib.h>

    int main(){
        // 1. Static array (靜態)：編譯時決定大小，存在 Stack
        int arr[10] = {0}; 

        // 2. Dynamic array (動態)：執行時決定大小，存在 Heap
        int n = 10;
        int* arr1 = (int*) malloc(sizeof(int) * n);

        // 檢查分配是否成功
        if (arr1 == NULL) return 1;

        // 使用完畢必須釋放
        free(arr1);
        return 0;
    }
    ```

* ### 類型對比：

| 類型 | 定義 | 優點 | 缺點 |
| :--- | :--- | :--- | :--- |
| **Static (靜態)** | 宣告當下即固定大小 | 存取速度極快，自動管理記憶體 | 大小不可變，空間易浪費或不足 |
| **Dynamic (動態)** | 透過 `malloc`/`realloc` 調整 | 彈性高 (Flexible)，可隨時調整大小 | 須手動 `free`，易產生 **Memory Leak** |

---

## 陣列的整體優缺點

* ### 優點 (Strengths)
    - **隨機存取 (Random Access)**：透過 **索引 (Index)** 即可 $O(1)$ 直接存取。
    - **高效能**：對 CPU 快取友善，遍歷速度快。

* ### 缺點 (Weaknesses)
    - **增刪低效**：在中間插入或刪除元素時，需移動大量元素，時間複雜度為 $O(n)$。
    - **連續空間要求**：必須找到一塊足夠大的連續記憶體，否則會分配失敗。

***
### 時間複雜度

| Operation (操作)     | Time Complexity (時間複雜度) | Notes (備註)                                         |
| :------------------- | :--------------------------- | :--------------------------------------------------- |
| **Insertion** (插入) | $O(N)$                       | 在非末尾位置需要移動元素                             |
| **Deletion** (刪除)  | $O(N)$                       | 在非末尾位置需要移動元素                             |
| **Traverse** (遍歷)  | $O(N)$                       | 需檢查所有 $N$ 個元素                                |
| **Access** (存取)    | $O(1)$                       | 透過索引直接定位                                     |
| **Update** (更新)    | $O(1)$                       | 透過索引直接定位並修改                               |
| **Search** (搜尋)    | $O(N)$ 或 $O(\log N)$        | $O(N)$ 為線性搜尋；$O(\log N)$ 為二分搜尋 (要求排序) |
## 陣列正式使用與演算法

### 1. 修改大小 (realloc)
```c
// 擴張動態陣列空間至新大小
int new_size = 20;
int* temp = (int*) realloc(arr1, sizeof(int) * new_size);
if (temp != NULL) {
    arr1 = temp;
}
